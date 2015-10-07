

/*
 * parser for qgen-xmi
 *
 */
#include <string.h>
#include <ctype.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include <assert.h>

#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>

#include <vector>
#include <map>
#include <list>

#include <xercesc/dom/DOM.hpp>
#include <xsd/cxx/xml/string.hxx>

#include "qgen-xmi.hxx"
#include "xmi-id.hxx"
#include "SimulinkModel.hxx"


static void name_model(::std::auto_ptr < QGenXMI::model >&);
static void name_elements(QGenXMI::elements&);
static void name_blocks(QGenXMI::blocks&,std::string);
static void name_Chart_blocks(QGenXMI::blocks&,std::string);
static void name_inDataPorts(QGenXMI::inDataPorts&,std::string);
static void name_insubsystem_inDataPorts(int ,QGenXMI::inDataPorts&,std::string);
static void name_subsystem_inDataPorts(QGenXMI::inDataPorts&,std::string);
static void name_outDataPorts(QGenXMI::outDataPorts&,std::string);
static void name_insubsystem_outDataPorts(int ,QGenXMI::outDataPorts&,std::string);
static void name_subsystem_outDataPorts(QGenXMI::outDataPorts&,std::string);
static void name_signals(QGenXMI::signals&,std::string);
static void name_Goto(QGenXMI::blocks&,std::string);
static void name_From(QGenXMI::blocks&,std::string);

static void usename_model(::std::auto_ptr < QGenXMI::model >&);
static void usename_elements(QGenXMI::elements&);
static void usename_blocks(QGenXMI::blocks&);
static void set_usename(QGenXMI::blocks&);

static void parse_model(::std::auto_ptr < QGenXMI::model >&, SimulinkModel::XSD::blocks_T&);
static void parse_elements(QGenXMI::elements&, SimulinkModel::XSD::blocks_T&);
static void parse_blocks(QGenXMI::blocks&, SimulinkModel::XSD::block_T&);
static void parse_inDataPorts(QGenXMI::inDataPorts&, SimulinkModel::XSD::ioport_T&);
static void parse_outDataPorts(QGenXMI::outDataPorts&, SimulinkModel::XSD::ioport_T&);
static bool parse_parameters(QGenXMI::parameters&, SimulinkModel::XSD::param_T&);
static bool parse_value(QGenXMI::value&, SimulinkModel::XSD::param_T&);
static bool parse_valueDataType(QGenXMI::valueDataType&, SimulinkModel::XSD::param_T&);

static void parse_Goto(QGenXMI::blocks, SimulinkModel::XSD::ioport_T&);
static void parse_From(QGenXMI::blocks, SimulinkModel::XSD::ioport_T&);

static std::string get_DataStoreName(QGenXMI::blocks);
static std::string get_Atomic(QGenXMI::blocks);

static void printconnect();
static void printsubconnect();

struct connect{
  	std::string dst_block;
  	std::string dst_port;
  	std::string line;
  	std::string src_port;
  	std::string src_block;
  	bool user_named_line;
  	int usename;
};

static std::map <int, connect> connection;     //信号線のつながり

struct sub_connect{
	std::vector<int> in_line;
	std::vector<int> out_line;
};

static std::map <int, sub_connect> sub_connection;      //subsystem

/*Gotoの範囲未考慮につき要修正*/
struct gotofrom_connect{
  std::string goto_block;
  std::string goto_port;
  std::string line;
  std::vector<std::string> from_port;
  std::vector<std::string> from_block;
};

static std::map <std::string, gotofrom_connect> gotofrom_connection;      //GotoとFromの仮想信号線


static void name_model(::std::auto_ptr < QGenXMI::model >& qgen_sysmodel){
  QGenXMI::elements qgen_ele = qgen_sysmodel->elements();
  name_elements(qgen_ele);
  qgen_sysmodel->elements(qgen_ele);
}

static void name_elements(QGenXMI::elements& qgen_ele){
  std::string fullname = qgen_ele.name();

  QGenXMI::elements::signals_sequence qgen_sig_seq = qgen_ele.signals();
  QGenXMI::elements::signals_iterator qgen_sig_i = qgen_sig_seq.begin();
  for(qgen_sig_i = qgen_sig_seq.begin(); qgen_sig_i != qgen_sig_seq.end(); qgen_sig_i++){
    name_signals(*qgen_sig_i, fullname);
  }
  qgen_ele.signals( qgen_sig_seq );

  QGenXMI::elements::inDataPorts_sequence qgen_idp_seq = qgen_ele.inDataPorts();
  QGenXMI::elements::inDataPorts_iterator qgen_idp_i = qgen_idp_seq.begin();
  for(qgen_idp_i = qgen_idp_seq.begin(); qgen_idp_i != qgen_idp_seq.end(); qgen_idp_i++){
    name_inDataPorts(*qgen_idp_i, fullname);
  }
  qgen_ele.inDataPorts( qgen_idp_seq );

  QGenXMI::elements::outDataPorts_sequence qgen_odp_seq = qgen_ele.outDataPorts();
  QGenXMI::elements::outDataPorts_iterator qgen_odp_i = qgen_odp_seq.begin();
  for(qgen_odp_i = qgen_odp_seq.begin(); qgen_odp_i != qgen_odp_seq.end(); qgen_odp_i++){
    name_outDataPorts(*qgen_odp_i, fullname);
  }
  qgen_ele.outDataPorts( qgen_odp_seq );

  QGenXMI::elements::blocks_sequence qgen_blks_seq = qgen_ele.blocks();
  QGenXMI::elements::blocks_iterator qgen_blks_i = qgen_blks_seq.begin();
  for(qgen_blks_i = qgen_blks_seq.begin(); qgen_blks_i != qgen_blks_seq.end(); qgen_blks_i++){
    name_blocks(*qgen_blks_i, fullname);
  }
  qgen_ele.blocks( qgen_blks_seq );
}

static void name_blocks(QGenXMI::blocks& qgen_blks, std::string fullname){
  static int in_subsystem = 0;  //何段目のsubsystem内のブロックなのか

  fullname = fullname + "_" + qgen_blks.name();
  qgen_blks.name( fullname );

  QGenXMI::blocks::signals_sequence qgen_sig_seq = qgen_blks.signals();
  QGenXMI::blocks::signals_iterator qgen_sig_i = qgen_sig_seq.begin();
  for(qgen_sig_i = qgen_sig_seq.begin(); qgen_sig_i != qgen_sig_seq.end(); qgen_sig_i++){
    name_signals(*qgen_sig_i, fullname);
  }
  qgen_blks.signals( qgen_sig_seq );

  if( qgen_blks.type1() == "SubSystem" ){
    in_subsystem++;

    if( qgen_blks.inEnablePort() ){
      name_subsystem_inDataPorts(*qgen_blks.inEnablePort(), fullname);
    }
    if( qgen_blks.inEdgeEnablePort() ){
      name_subsystem_inDataPorts(*qgen_blks.inEdgeEnablePort(), fullname);
    }
    else if( qgen_blks.inControlPort() ){
      name_subsystem_inDataPorts(*qgen_blks.inControlPort(), fullname);
    }
    QGenXMI::blocks::inDataPorts_sequence qgen_idp_seq = qgen_blks.inDataPorts();
    QGenXMI::blocks::inDataPorts_iterator qgen_idp_i = qgen_idp_seq.begin();
    for(qgen_idp_i = qgen_idp_seq.begin(); qgen_idp_i != qgen_idp_seq.end(); qgen_idp_i++){
      name_subsystem_inDataPorts(*qgen_idp_i, fullname);
    }
    qgen_blks.inDataPorts( qgen_idp_seq );

    QGenXMI::blocks::outDataPorts_sequence qgen_odp_seq = qgen_blks.outDataPorts();
    QGenXMI::blocks::outDataPorts_iterator qgen_odp_i = qgen_odp_seq.begin();
    for(qgen_odp_i = qgen_odp_seq.begin(); qgen_odp_i != qgen_odp_seq.end(); qgen_odp_i++){
      name_subsystem_outDataPorts(*qgen_odp_i, fullname);
    }
    qgen_blks.outDataPorts( qgen_odp_seq );

    QGenXMI::blocks::blocks1_sequence qgen_blk_seq = qgen_blks.blocks1();
    QGenXMI::blocks::blocks1_iterator qgen_blk_i = qgen_blk_seq.begin();
    for(qgen_blk_i = qgen_blk_seq.begin(); qgen_blk_i != qgen_blk_seq.end(); qgen_blk_i++){
      name_blocks(*qgen_blk_i, fullname);
    }
    qgen_blks.blocks1( qgen_blk_seq );
    
    in_subsystem--;
  }

  else if( qgen_blks.type1() == "SFChart" ){
    name_Chart_blocks(qgen_blks, fullname);

    QGenXMI::blocks::inDataPorts_sequence qgen_idp_seq = qgen_blks.inDataPorts();
    QGenXMI::blocks::inDataPorts_iterator qgen_idp_i = qgen_idp_seq.begin();
    for(qgen_idp_i = qgen_idp_seq.begin(); qgen_idp_i != qgen_idp_seq.end(); qgen_idp_i++){
      name_subsystem_inDataPorts(*qgen_idp_i, fullname);
    }
    qgen_blks.inDataPorts( qgen_idp_seq );

    QGenXMI::blocks::outDataPorts_sequence qgen_odp_seq = qgen_blks.outDataPorts();
    QGenXMI::blocks::outDataPorts_iterator qgen_odp_i = qgen_odp_seq.begin();
    for(qgen_odp_i = qgen_odp_seq.begin(); qgen_odp_i != qgen_odp_seq.end(); qgen_odp_i++){
      name_subsystem_outDataPorts(*qgen_odp_i, fullname);
    }
    qgen_blks.outDataPorts( qgen_odp_seq );

    QGenXMI::blocks::blocks1_sequence qgen_blk_seq = qgen_blks.blocks1();
    QGenXMI::blocks::blocks1_iterator qgen_blk_i = qgen_blk_seq.begin();
    for(qgen_blk_i = qgen_blk_seq.begin(); qgen_blk_i != qgen_blk_seq.end(); qgen_blk_i++){
      name_blocks(*qgen_blk_i, fullname);
    }
    qgen_blks.blocks1( qgen_blk_seq );
  }

  else{
    if(in_subsystem > 0 && qgen_blks.type1() == "Inport"){
      QGenXMI::blocks::outDataPorts_sequence qgen_odp_seq = qgen_blks.outDataPorts();
      QGenXMI::blocks::outDataPorts_iterator qgen_odp_i = qgen_odp_seq.begin();
      for(qgen_odp_i = qgen_odp_seq.begin(); qgen_odp_i != qgen_odp_seq.end(); qgen_odp_i++){
        name_insubsystem_outDataPorts(qgen_blks.id(), *qgen_odp_i, fullname);
      }
      qgen_blks.outDataPorts( qgen_odp_seq );
    }

    else if(in_subsystem > 0 && qgen_blks.type1() == "Outport"){
      QGenXMI::blocks::inDataPorts_sequence qgen_idp_seq = qgen_blks.inDataPorts();
      QGenXMI::blocks::inDataPorts_iterator qgen_idp_i = qgen_idp_seq.begin();
      for(qgen_idp_i = qgen_idp_seq.begin(); qgen_idp_i != qgen_idp_seq.end(); qgen_idp_i++){
        name_insubsystem_inDataPorts(qgen_blks.id(), *qgen_idp_i, fullname);
      }
      qgen_blks.inDataPorts( qgen_idp_seq );
    }

    else{
      if(qgen_blks.type1() == "Goto"){
        name_Goto(qgen_blks, fullname);
      }
      else if(qgen_blks.type1() == "From"){
        name_From(qgen_blks, fullname);
      }

      QGenXMI::blocks::inDataPorts_sequence qgen_idp_seq = qgen_blks.inDataPorts();
      QGenXMI::blocks::inDataPorts_iterator qgen_idp_i = qgen_idp_seq.begin();
      for(qgen_idp_i = qgen_idp_seq.begin(); qgen_idp_i != qgen_idp_seq.end(); qgen_idp_i++){
        name_inDataPorts(*qgen_idp_i, fullname);
      }
      qgen_blks.inDataPorts( qgen_idp_seq );

      QGenXMI::blocks::outDataPorts_sequence qgen_odp_seq = qgen_blks.outDataPorts();
      QGenXMI::blocks::outDataPorts_iterator qgen_odp_i = qgen_odp_seq.begin();
      for(qgen_odp_i = qgen_odp_seq.begin(); qgen_odp_i != qgen_odp_seq.end(); qgen_odp_i++){
        name_outDataPorts(*qgen_odp_i, fullname);
      }
      qgen_blks.outDataPorts( qgen_odp_seq );

      QGenXMI::blocks::outControlPorts_sequence qgen_ocp_seq = qgen_blks.outControlPorts();
      QGenXMI::blocks::outControlPorts_iterator qgen_ocp_i = qgen_ocp_seq.begin();
      for(qgen_ocp_i = qgen_ocp_seq.begin(); qgen_ocp_i != qgen_ocp_seq.end(); qgen_ocp_i++){
        name_outDataPorts(*qgen_ocp_i, fullname);
      }
      qgen_blks.outControlPorts( qgen_ocp_seq );
    }
  }
}

static void name_Chart_blocks(QGenXMI::blocks& qgen_blks,std::string fullname){
  static int line_ID = -1;  //信号線ID
  int first_line_ID = line_ID;
  int in_num = 0;   //Chartへの入力数
  int out_num = 0;  //Chartからの出力数

  /*信号線追加用ダミーデータ*/
  struct connect data = {"","","","","",false,0};

  /*追加ブロック用変数*/
  QGenXMI::blocks push_blk(0,"name","type");
  push_blk.assignedPriority(0);
  push_blk.samplePeriod(-1);

  /*追加ポートタグ用変数*/
  QGenXMI::inDataPorts push_idp(0,"in1",1);
  QGenXMI::outDataPorts push_odp(0,"out1",1);


  QGenXMI::blocks::blocks1_sequence& qgen_blk_seq = qgen_blks.blocks1();
  QGenXMI::blocks::blocks1_iterator qgen_blk_i = qgen_blk_seq.begin();
  for(qgen_blk_i = qgen_blk_seq.begin(); qgen_blk_i != qgen_blk_seq.end(); qgen_blk_i++){
    (*qgen_blk_i).inDataPorts().clear();
    (*qgen_blk_i).outDataPorts().clear();
    if((*qgen_blk_i).type1()=="Inport"){
      push_odp.outgoingSignals( QGenXMI::id_list(1,line_ID) );
      (*qgen_blk_i).outDataPorts().push_back(push_odp);
      push_odp.outgoingSignals( QGenXMI::id_list() );  //push_odpのoutgoingSignas初期化
      data.line = "";
      connection[line_ID] = data;  //信号線追加
      line_ID--;  //信号線IDカウント
      in_num++;  //入力数カウント
    }
    else if((*qgen_blk_i).type1()=="Outport"){
      push_idp.incomingSignal( QGenXMI::id_list(1,line_ID) );
      (*qgen_blk_i).inDataPorts().push_back(push_idp);
      push_idp.incomingSignal( QGenXMI::id_list() );  //push_idpのincomingSignal初期化
      data.line = fullname + "_SFunction_" + (*qgen_blk_i).name();
      connection[line_ID] = data;  //信号線追加
      line_ID--;  //信号線IDカウント
      out_num++;  //出力数カウント
    }
  }

  int i;

  /*portname変更用stringstream*/
  std::stringstream portname;

  /*S-Function追加*/
  push_blk.name("SFunction");
  push_blk.type1("S-Function");
  line_ID = first_line_ID;
        /*入力の数だけinDataPortsを生成*/
  for(i=1; i<=in_num; i++){
    portname << "in" << i;
    push_idp.name(portname.str());
    portname.str("");
    portname.clear(std::stringstream::goodbit);
    push_idp.portNumber(i);
    push_idp.incomingSignal( QGenXMI::id_list(1,line_ID) );
    push_blk.inDataPorts().push_back(push_idp);
    push_idp.incomingSignal( QGenXMI::id_list() );  //push_idpのincomingSignal初期化
    line_ID--;
  }
        /*出力の数だけoutDataPortsを生成*/
  for(i=1; i<=out_num; i++){
    portname << "out" << i;
    push_odp.name(portname.str());
    portname.str("");
    portname.clear(std::stringstream::goodbit);
    push_odp.portNumber(i);
    push_odp.outgoingSignals( QGenXMI::id_list(1,line_ID) );
    push_blk.outDataPorts().push_back(push_odp);
    push_odp.outgoingSignals( QGenXMI::id_list() );  //push_odpのoutgoingSignas初期化
    line_ID--;
  }
        /*Demuxの分のoutDataPortsを生成*/
    portname << "out" << (out_num+1);
    push_odp.name(portname.str());
    push_odp.portNumber(i);
    push_odp.outgoingSignals( QGenXMI::id_list(1,line_ID) );
    push_blk.outDataPorts().push_back(push_odp);
    push_odp.outgoingSignals( QGenXMI::id_list() );  //push_odpのoutgoingSignas初期化
  data.line = "";
  connection[line_ID] = data;  //S-functionとDemux間の信号線追加
  qgen_blk_seq.push_back(push_blk);
  push_blk.inDataPorts().clear();
  push_blk.outDataPorts().clear();

  /*Demuxの追加*/
  push_blk.name("Demux");
  push_blk.type1("Demux");
    push_idp.name("in1");
    push_idp.portNumber(1);
    push_idp.incomingSignal( QGenXMI::id_list(1,line_ID) );
    push_blk.inDataPorts().push_back(push_idp);
    push_idp.incomingSignal( QGenXMI::id_list() );  //push_idpのincomingSignal初期化
  line_ID--;
  data.line = "";
  connection[line_ID] = data;  //DemuxとTerminator間の信号線追加
    push_idp.name("out1");
    push_idp.portNumber(1);
    push_odp.outgoingSignals( QGenXMI::id_list(1,line_ID) );
    push_blk.outDataPorts().push_back(push_odp);
    push_odp.outgoingSignals( QGenXMI::id_list() );  //push_odpのoutgoingSignas初期化
  qgen_blk_seq.push_back(push_blk);
  push_blk.inDataPorts().clear();
  push_blk.outDataPorts().clear();

  /*Terminatorの追加*/
  push_blk.name("Terminator");
  push_blk.type1("Terminator");
    push_idp.name("in1");
    push_idp.portNumber(1);
    push_idp.incomingSignal( QGenXMI::id_list(1,line_ID) );
    push_blk.inDataPorts().push_back(push_idp);
    push_idp.incomingSignal( QGenXMI::id_list() );  //push_idpのincomingSignal初期化
  qgen_blk_seq.push_back(push_blk);

  line_ID--;
}

static void name_inDataPorts(QGenXMI::inDataPorts& qgen_idp, std::string block_fullname){
  std::stringstream port_fullname;
  if(qgen_idp.name().length() < 3){
  	  port_fullname << block_fullname << "_" << qgen_idp.name();
  }
  else{
  	  std::string in = qgen_idp.name().substr(0,2);
  	  std::string num = qgen_idp.name().substr(2);
  	  if(in == "in" && num.find_first_not_of("0123456789") == std::string::npos)
  	    port_fullname << block_fullname << "_" << qgen_idp.portNumber();
  	  else
  		  port_fullname << block_fullname << "_" << qgen_idp.name();
  }
  qgen_idp.name( port_fullname.str() );

  if(qgen_idp.incomingSignal()){
  	  QGenXMI::id_list::iterator qgen_idl_i = (*qgen_idp.incomingSignal()).begin();
  	  for(qgen_idl_i = (*qgen_idp.incomingSignal()).begin(); qgen_idl_i != (*qgen_idp.incomingSignal()).end(); qgen_idl_i++){
  	    connection[ *qgen_idl_i ].src_block = block_fullname;
  	    connection[ *qgen_idl_i ].src_port = port_fullname.str();
  	  }
  }

}
static void name_insubsystem_inDataPorts(int id,QGenXMI::inDataPorts& qgen_idp, std::string block_fullname){
  std::stringstream port_fullname;
  if(qgen_idp.name().length() < 3){
    port_fullname << block_fullname << "_" << qgen_idp.name();
  }
  else{
      std::string in = qgen_idp.name().substr(0,2);
      std::string num = qgen_idp.name().substr(2);
      if(in == "in" && num.find_first_not_of("0123456789") == std::string::npos)
      port_fullname << block_fullname << "_" << qgen_idp.portNumber();
      else
      port_fullname << block_fullname << "_" << qgen_idp.name();
  }
  qgen_idp.name( port_fullname.str() );

    std::vector<int> v;
    if(qgen_idp.incomingSignal()){
      QGenXMI::id_list::iterator qgen_idl_i = (*qgen_idp.incomingSignal()).begin();
      for(qgen_idl_i = (*qgen_idp.incomingSignal()).begin(); qgen_idl_i != (*qgen_idp.incomingSignal()).end(); qgen_idl_i++){
        connection[ *qgen_idl_i ].src_block = block_fullname;
        connection[ *qgen_idl_i ].src_port = port_fullname.str();
        v.push_back(*qgen_idl_i);
      }
    sub_connection[id].in_line = v;
  }

}

static void name_subsystem_inDataPorts(QGenXMI::inDataPorts& qgen_idp, std::string block_fullname){
  std::stringstream port_fullname;
  if(qgen_idp.name().length() < 3){
    port_fullname << block_fullname << "_" << qgen_idp.name();
  }
  else{
  	  std::string in = qgen_idp.name().substr(0,2);
  	  std::string num = qgen_idp.name().substr(2);
  	  if(in == "in" && num.find_first_not_of("0123456789") == std::string::npos)
      port_fullname << block_fullname << "_" << qgen_idp.portNumber();
    	else
      port_fullname << block_fullname << "_" << qgen_idp.name();
  }
  qgen_idp.name( port_fullname.str() );

  	std::vector<int> v;
  	if(qgen_idp.incomingSignal()){
  	  QGenXMI::id_list::iterator qgen_idl_i = (*qgen_idp.incomingSignal()).begin();
  	  for(qgen_idl_i = (*qgen_idp.incomingSignal()).begin(); qgen_idl_i != (*qgen_idp.incomingSignal()).end(); qgen_idl_i++){
  	    connection[ *qgen_idl_i ].src_block = block_fullname;
  	    connection[ *qgen_idl_i ].src_port = port_fullname.str();
  	    v.push_back(*qgen_idl_i);
  	  }
	  sub_connection[*qgen_idp.sourceBlock()].in_line = v;
  }

}

static void name_outDataPorts(QGenXMI::outDataPorts& qgen_odp, std::string block_fullname){
  std::stringstream port_fullname;
  if(qgen_odp.name().length() < 4){
    port_fullname << block_fullname << "_" << qgen_odp.name();
  }
  else{
  	  std::string out = qgen_odp.name().substr(0,3);
  	  std::string num = qgen_odp.name().substr(3);
  	  if(out == "out" && num.find_first_not_of("0123456789") == std::string::npos)
      port_fullname << block_fullname << "_" << qgen_odp.portNumber();
  	  else
      port_fullname << block_fullname << "_" << qgen_odp.name();
  }
  qgen_odp.name( port_fullname.str() );

  if(qgen_odp.outgoingSignals()){
  	  QGenXMI::id_list::iterator qgen_idl_i = (*qgen_odp.outgoingSignals()).begin();
  	  for(qgen_idl_i = (*qgen_odp.outgoingSignals()).begin(); qgen_idl_i != (*qgen_odp.outgoingSignals()).end(); qgen_idl_i++){
      std::stringstream line_fullname;
  	    if(connection[ *qgen_idl_i ].line == ""){
  	  	    line_fullname << 	block_fullname << "_" << qgen_odp.portNumber();      }
  	    else{
  		    line_fullname << connection[ *qgen_idl_i ].line;
        }
 	    connection[ *qgen_idl_i ].dst_block = block_fullname;
  	    connection[ *qgen_idl_i ].dst_port = port_fullname.str();
  	    connection[ *qgen_idl_i ].line = line_fullname.str();
  	  }
  }

}

static void name_insubsystem_outDataPorts(int id, QGenXMI::outDataPorts& qgen_odp, std::string block_fullname){
  std::stringstream port_fullname;
  if(qgen_odp.name().length() < 4){
    port_fullname << block_fullname << "_" << qgen_odp.name();
  }
  else{
      std::string out = qgen_odp.name().substr(0,3);
      std::string num = qgen_odp.name().substr(3);
      if(out == "out" && num.find_first_not_of("0123456789") == std::string::npos)
      port_fullname << block_fullname << "_" << qgen_odp.portNumber();
      else
      port_fullname << block_fullname << "_" << qgen_odp.name();
  }
  qgen_odp.name( port_fullname.str() );

    std::vector<int> v;
  if(qgen_odp.outgoingSignals()){
      QGenXMI::id_list::iterator qgen_idl_i = (*qgen_odp.outgoingSignals()).begin();
      for(qgen_idl_i = (*qgen_odp.outgoingSignals()).begin(); qgen_idl_i != (*qgen_odp.outgoingSignals()).end(); qgen_idl_i++){
      std::stringstream line_fullname;
        if(connection[ *qgen_idl_i ].line == "")
        line_fullname << block_fullname << "_" << qgen_odp.portNumber();
        else
        line_fullname << connection[ *qgen_idl_i ].line;
      connection[ *qgen_idl_i ].dst_block = block_fullname;
        connection[ *qgen_idl_i ].dst_port = port_fullname.str();
        connection[ *qgen_idl_i ].line = line_fullname.str();
        v.push_back(*qgen_idl_i);
      }
      sub_connection[id].out_line = v;
  }
}

static void name_subsystem_outDataPorts(QGenXMI::outDataPorts& qgen_odp, std::string block_fullname){
  std::stringstream port_fullname;
  if(qgen_odp.name().length() < 4){
    port_fullname << block_fullname << "_" << qgen_odp.name();
  }
  else{
  	  std::string out = qgen_odp.name().substr(0,3);
  	  std::string num = qgen_odp.name().substr(3);
  	  if(out == "out" && num.find_first_not_of("0123456789") == std::string::npos)
      port_fullname << block_fullname << "_" << qgen_odp.portNumber();
  	  else
      port_fullname << block_fullname << "_" << qgen_odp.name();
  }
  qgen_odp.name( port_fullname.str() );

  	std::vector<int> v;
	if(qgen_odp.outgoingSignals()){
  	  QGenXMI::id_list::iterator qgen_idl_i = (*qgen_odp.outgoingSignals()).begin();
  	  for(qgen_idl_i = (*qgen_odp.outgoingSignals()).begin(); qgen_idl_i != (*qgen_odp.outgoingSignals()).end(); qgen_idl_i++){
      std::stringstream line_fullname;
  	    if(connection[ *qgen_idl_i ].line == "")
        line_fullname << block_fullname << "_" << qgen_odp.portNumber();
  	    else
        line_fullname << connection[ *qgen_idl_i ].line;
 	    connection[ *qgen_idl_i ].dst_block = block_fullname;
  	    connection[ *qgen_idl_i ].dst_port = port_fullname.str();
  	    connection[ *qgen_idl_i ].line = line_fullname.str();
  	    v.push_back(*qgen_idl_i);
  	  }
  	  sub_connection[*qgen_odp.sourceBlock()].out_line = v;
  }
}

static void name_signals(QGenXMI::signals& qgen_sig, std::string fullname){
  struct connect data = {"","","","","",false,0};

  if(qgen_sig.name() != ""){
    data.user_named_line = true;
    data.line = qgen_sig.name();
  }
  connection[qgen_sig.id()] = data;
}

static void name_Goto(QGenXMI::blocks& qgen_blks, std::string fullname){
  std::string Tag;

  QGenXMI::blocks::parameters_sequence qgen_par_seq = qgen_blks.parameters();
  QGenXMI::blocks::parameters_iterator qgen_par_i = qgen_par_seq.begin();
  for(qgen_par_i = qgen_par_seq.begin(); qgen_par_i != qgen_par_seq.end(); qgen_par_i++){
    if((*qgen_par_i).name() == "GotoTag"){
      QGenXMI::parameters::value_sequence qgen_val_seq = (*qgen_par_i).value();
      Tag = *(*qgen_val_seq.begin()).litValue();
      break;    
    }
  }  
  gotofrom_connection[Tag].goto_block = fullname;
  gotofrom_connection[Tag].goto_port = fullname + "_1";
  gotofrom_connection[Tag].line = fullname + "_1";
}

static void name_From(QGenXMI::blocks& qgen_blks, std::string fullname){
  std::string Tag;

  QGenXMI::blocks::parameters_sequence qgen_par_seq = qgen_blks.parameters();
  QGenXMI::blocks::parameters_iterator qgen_par_i = qgen_par_seq.begin();
  for(qgen_par_i = qgen_par_seq.begin(); qgen_par_i != qgen_par_seq.end(); qgen_par_i++){
    if((*qgen_par_i).name() == "GotoTag"){
      QGenXMI::parameters::value_sequence qgen_val_seq = (*qgen_par_i).value();
      Tag = *(*qgen_val_seq.begin()).litValue();
      break;    
    }
  }  
  gotofrom_connection[Tag].from_block.push_back(fullname);
  gotofrom_connection[Tag].from_port.push_back(fullname + "_1");
}



static void usename_model(::std::auto_ptr < QGenXMI::model >& qgen_sysmodel){
  QGenXMI::elements qgen_ele = qgen_sysmodel->elements();
  usename_elements(qgen_ele);
}

static void usename_elements(QGenXMI::elements& qgen_ele){
  QGenXMI::elements::blocks_sequence qgen_blks_seq = qgen_ele.blocks();
  QGenXMI::elements::blocks_iterator qgen_blks_i = qgen_blks_seq.begin();
  for(qgen_blks_i = qgen_blks_seq.begin(); qgen_blks_i != qgen_blks_seq.end(); qgen_blks_i++){
    usename_blocks(*qgen_blks_i);
  }
}

static void usename_blocks(QGenXMI::blocks& qgen_blks){
  if( qgen_blks.type1() == "SubSystem" ){
    QGenXMI::blocks::blocks1_sequence qgen_blk_seq = qgen_blks.blocks1();
    QGenXMI::blocks::blocks1_iterator qgen_blk_i = qgen_blk_seq.begin();
    for(qgen_blk_i = qgen_blk_seq.begin(); qgen_blk_i != qgen_blk_seq.end(); qgen_blk_i++){
      usename_blocks(*qgen_blk_i);
    }
  }
  else
    set_usename(qgen_blks);
}

static void set_usename(QGenXMI::blocks& qgen_blks){
  if(sub_connection.find(qgen_blks.id()) == sub_connection.end()){
    QGenXMI::blocks::outDataPorts_sequence qgen_odp_seq = qgen_blks.outDataPorts();
    QGenXMI::blocks::outDataPorts_iterator qgen_odp_i = qgen_odp_seq.begin();
    for(qgen_odp_i = qgen_odp_seq.begin(); qgen_odp_i != qgen_odp_seq.end(); qgen_odp_i++){
      if((*qgen_odp_i).outgoingSignals()){
        QGenXMI::id_list::iterator qgen_idl_i = (*(*qgen_odp_i).outgoingSignals()).begin();
        for(qgen_idl_i = (*(*qgen_odp_i).outgoingSignals()).begin(); qgen_idl_i != (*(*qgen_odp_i).outgoingSignals()).end(); qgen_idl_i++){
          connection[ *qgen_idl_i ].usename = 1;
        }
      }
    }
    return;
  }

	struct sub_connect data = sub_connection[qgen_blks.id()];
	std::vector<int>::iterator in_i = data.in_line.begin();
	std::vector<int>::iterator out_i = data.out_line.begin();

	for(in_i = data.in_line.begin(); in_i != data.in_line.end(); in_i++){
	  if(connection[*in_i].user_named_line == true){
	  	connection[*in_i].usename = 1;
	  	return;
	  }
	}

	for(out_i = data.out_line.begin(); out_i != data.out_line.end(); out_i++){
	  if(connection[*out_i].user_named_line == true){
	  	connection[*out_i].usename = 1;
	  	return;
	  }
	}

	for(out_i = data.out_line.begin(); out_i != data.out_line.end(); out_i++){
	  if(connection[*out_i].usename == 2){
	  	connection[*data.in_line.begin()].usename = 2;
	  	return;
	  }
	}

}



static void parse_model(::std::auto_ptr < QGenXMI::model >& qgen_sysmodel, SimulinkModel::XSD::blocks_T& sim_blks){
  QGenXMI::elements qgen_ele = qgen_sysmodel->elements();
  parse_elements(qgen_ele, sim_blks);
}

static void parse_elements(QGenXMI::elements& qgen_ele, SimulinkModel::XSD::blocks_T& sim_blks){
  sim_blks.name( qgen_ele.name() );

  SimulinkModel::XSD::blocks_T::block_sequence sim_blk_seq = sim_blks.block();
  QGenXMI::elements::blocks_sequence qgen_blks_seq = qgen_ele.blocks();
  QGenXMI::elements::blocks_iterator qgen_blks_i = qgen_blks_seq.begin();
  for(qgen_blks_i = qgen_blks_seq.begin(); qgen_blks_i != qgen_blks_seq.end(); qgen_blks_i++){
    SimulinkModel::XSD::block_T sim_blk("","");
    parse_blocks(*qgen_blks_i, sim_blk);
    sim_blk_seq.insert( sim_blk_seq.end(), sim_blk );
  }
  sim_blks.block( sim_blk_seq );
}

static void parse_blocks(QGenXMI::blocks& qgen_blks, SimulinkModel::XSD::block_T& sim_blk){
  sim_blk.blocktype( qgen_blks.type1() );
  sim_blk.name( qgen_blks.name() );
  sim_blk.priority( *qgen_blks.assignedPriority() );

  std::stringstream rate;
  if(*qgen_blks.samplePeriod() == -1){
    rate << -1;
  }
  else{
    rate << *qgen_blks.samplePeriod();
  }
  sim_blk.rate( rate.str() );

  if( qgen_blks.type1() == "DataStoreMemory" ){
    sim_blk.DataStoreName( get_DataStoreName( qgen_blks ) );
  } 
  else if( qgen_blks.type1() == "DataStoreRead" ){
    sim_blk.DataStoreName( get_DataStoreName( qgen_blks ) );
  }
  else if( qgen_blks.type1() == "DataStoreWrite" ){
    sim_blk.DataStoreName( get_DataStoreName( qgen_blks ) );
  }
  else if( qgen_blks.type1() == "SubSystem" ){
    SimulinkModel::XSD::block_T::blocks_sequence sim_blks_seq = sim_blk.blocks();
    SimulinkModel::XSD::blocks_T sim_blks;
    SimulinkModel::XSD::blocks_T::block_sequence sim_blk1_seq = sim_blks.block();
    QGenXMI::blocks::blocks1_sequence qgen_blk_seq = qgen_blks.blocks1();
    QGenXMI::blocks::blocks1_iterator qgen_blk_i = qgen_blk_seq.begin();
    for(qgen_blk_i = qgen_blk_seq.begin(); qgen_blk_i != qgen_blk_seq.end(); qgen_blk_i++){
      SimulinkModel::XSD::block_T sim_blk1("","");
      parse_blocks(*qgen_blk_i, sim_blk1);
      sim_blk1_seq.insert( sim_blk1_seq.end(), sim_blk1);
    }
    sim_blks.block( sim_blk1_seq );
    sim_blks_seq.insert( sim_blks_seq.begin(), sim_blks );
    sim_blk.blocks( sim_blks_seq );

    sim_blk.TreatAsAtomicUnit( get_Atomic( qgen_blks ) );
  }
  else if(qgen_blks.type1() == "SFChart" ){
    sim_blk.blocktype("SubSystem");
    sim_blk.stateflow("Chart");

    SimulinkModel::XSD::block_T::blocks_sequence sim_blks_seq = sim_blk.blocks();
    SimulinkModel::XSD::blocks_T sim_blks;
    SimulinkModel::XSD::blocks_T::block_sequence sim_blk1_seq = sim_blks.block();
    QGenXMI::blocks::blocks1_sequence qgen_blk_seq = qgen_blks.blocks1();
    QGenXMI::blocks::blocks1_iterator qgen_blk_i = qgen_blk_seq.begin();
    for(qgen_blk_i = qgen_blk_seq.begin(); qgen_blk_i != qgen_blk_seq.end(); qgen_blk_i++){
      SimulinkModel::XSD::block_T sim_blk1("","");
      parse_blocks(*qgen_blk_i, sim_blk1);
      sim_blk1_seq.insert( sim_blk1_seq.end(), sim_blk1);
    }
    sim_blks.block( sim_blk1_seq );
    sim_blks_seq.insert( sim_blks_seq.begin(), sim_blks );
    sim_blk.blocks( sim_blks_seq );

    sim_blk.TreatAsAtomicUnit( get_Atomic( qgen_blks ) );    
  }

  SimulinkModel::XSD::block_T::input_sequence sim_in_seq = sim_blk.input();
  QGenXMI::blocks::inDataPorts_sequence qgen_idp_seq = qgen_blks.inDataPorts();
  QGenXMI::blocks::inDataPorts_iterator qgen_idp_i = qgen_idp_seq.begin();
  for(qgen_idp_i = qgen_idp_seq.begin(); qgen_idp_i != qgen_idp_seq.end(); qgen_idp_i++){
    SimulinkModel::XSD::ioport_T sim_io("","");
    parse_inDataPorts(*qgen_idp_i, sim_io);
    sim_in_seq.push_back( sim_io );
  }
  if(qgen_blks.inEnablePort()){
    SimulinkModel::XSD::ioport_T sim_io("","");
    parse_inDataPorts(*qgen_blks.inEnablePort(), sim_io);
    sim_in_seq.push_back( sim_io );
  }
  else if(qgen_blks.inEdgeEnablePort()){
    SimulinkModel::XSD::ioport_T sim_io("","");
    parse_inDataPorts(*qgen_blks.inEdgeEnablePort(), sim_io);
    sim_in_seq.push_back( sim_io );
  }
  else if(qgen_blks.inControlPort()){
    SimulinkModel::XSD::ioport_T sim_io("","");
    parse_inDataPorts(*qgen_blks.inControlPort(), sim_io);
    sim_in_seq.push_back( sim_io );
  }
  else if(qgen_blks.type1() == "From"){
    SimulinkModel::XSD::ioport_T sim_io("","");
    parse_From(qgen_blks, sim_io);
    sim_in_seq.push_back( sim_io );
  }
  sim_blk.input( sim_in_seq );

  SimulinkModel::XSD::block_T::output_sequence sim_out_seq = sim_blk.output();
  QGenXMI::blocks::outDataPorts_sequence qgen_odp_seq = qgen_blks.outDataPorts();
  QGenXMI::blocks::outDataPorts_iterator qgen_odp_i = qgen_odp_seq.begin();
  for(qgen_odp_i = qgen_odp_seq.begin(); qgen_odp_i != qgen_odp_seq.end(); qgen_odp_i++){
    SimulinkModel::XSD::ioport_T sim_io("","");
    parse_outDataPorts(*qgen_odp_i, sim_io);
    sim_out_seq.push_back( sim_io );
  }
  QGenXMI::blocks::outControlPorts_sequence qgen_ocp_seq = qgen_blks.outControlPorts();
  QGenXMI::blocks::outControlPorts_iterator qgen_ocp_i = qgen_ocp_seq.begin();
  for(qgen_ocp_i = qgen_ocp_seq.begin(); qgen_ocp_i != qgen_ocp_seq.end(); qgen_ocp_i++){
    SimulinkModel::XSD::ioport_T sim_io("","");
    parse_outDataPorts(*qgen_ocp_i, sim_io);
    sim_out_seq.push_back( sim_io );
  }
  if(qgen_blks.type1() == "Goto"){
    SimulinkModel::XSD::ioport_T sim_io("","");
    parse_Goto( qgen_blks, sim_io );
    sim_out_seq.push_back( sim_io );
  }
  sim_blk.output( sim_out_seq );



  SimulinkModel::XSD::block_T::param_sequence sim_par_seq = sim_blk.param();
  QGenXMI::blocks::parameters_sequence qgen_par_seq = qgen_blks.parameters();
  QGenXMI::blocks::parameters_iterator qgen_par_i = qgen_par_seq.begin();
  for(qgen_par_i = qgen_par_seq.begin(); qgen_par_i != qgen_par_seq.end(); qgen_par_i++){
    SimulinkModel::XSD::param_T sim_par("","","");
    if( parse_parameters(*qgen_par_i, sim_par) ){
      sim_par_seq.push_back(sim_par);
    }
  }
  sim_blk.param( sim_par_seq );
}

static void parse_inDataPorts(QGenXMI::inDataPorts& qgen_idp, SimulinkModel::XSD::ioport_T& sim_in){
  SimulinkModel::XSD::ioport_T::connect_sequence sim_con_seq = sim_in.connect();
  QGenXMI::id_list::iterator qgen_idl_i = (*qgen_idp.incomingSignal()).begin();
  for(qgen_idl_i = (*qgen_idp.incomingSignal()).begin(); qgen_idl_i != (*qgen_idp.incomingSignal()).end(); qgen_idl_i++){
	sim_in.line( connection[*qgen_idl_i].line );
  	sim_in.port( connection[*qgen_idl_i].src_port );

  	SimulinkModel::XSD::connection_T sim_con("","");
  	sim_con.block( connection[*qgen_idl_i].dst_block );
  	sim_con.port( connection[*qgen_idl_i].dst_port );
  	sim_con_seq.insert(sim_con_seq.end(), sim_con);
  }
  sim_in.connect(sim_con_seq);
}

static void parse_outDataPorts(QGenXMI::outDataPorts& qgen_odp, SimulinkModel::XSD::ioport_T& sim_out){
  SimulinkModel::XSD::ioport_T::connect_sequence sim_con_seq = sim_out.connect();
  QGenXMI::id_list::iterator qgen_idl_i = (*qgen_odp.outgoingSignals()).begin();
  for(qgen_idl_i = (*qgen_odp.outgoingSignals()).begin(); qgen_idl_i != (*qgen_odp.outgoingSignals()).end(); qgen_idl_i++){
	sim_out.line( connection[*qgen_idl_i].line );
  	sim_out.port( connection[*qgen_idl_i].dst_port );
  	if(connection[*qgen_idl_i].usename == 1)
  	  sim_out.usename( true );
  	else
  	  sim_out.usename( false );

  	SimulinkModel::XSD::connection_T sim_con("","");
  	sim_con.block( connection[*qgen_idl_i].src_block );
  	sim_con.port( connection[*qgen_idl_i].src_port );
  	sim_con_seq.insert(sim_con_seq.end(), sim_con);
  }
  sim_out.connect(sim_con_seq);
}

static bool parse_parameters(QGenXMI::parameters& qgen_par, SimulinkModel::XSD::param_T& sim_par){
  QGenXMI::parameters::value_sequence qgen_val_seq = qgen_par.value();
  QGenXMI::parameters::value_iterator qgen_val_i = qgen_val_seq.begin();
  for(qgen_val_i = qgen_val_seq.begin(); qgen_val_i != qgen_val_seq.end(); qgen_val_i++){
    if( parse_value(*qgen_val_i, sim_par) ){
      sim_par.storage(*qgen_par.storageClass());
      sim_par.name(qgen_par.name());
      return(true);
    }
  }
  return(false);
}

static bool parse_value(QGenXMI::value& qgen_val, SimulinkModel::XSD::param_T& sim_par){
  QGenXMI::value::valueDataType_sequence qgen_vdt_seq = qgen_val.valueDataType();
  QGenXMI::value::valueDataType_iterator qgen_vdt_i = qgen_vdt_seq.begin();
  for(qgen_vdt_i = qgen_vdt_seq.begin(); qgen_vdt_i != qgen_vdt_seq.end(); qgen_vdt_i++){
    if( parse_valueDataType(*qgen_vdt_i, sim_par) ){
      sim_par.value(*qgen_val.litValue());
      return(true);
    }
  }
  return(false);
}

/*要改良*/
static bool parse_valueDataType(QGenXMI::valueDataType& qgen_vdt, SimulinkModel::XSD::param_T& sim_par){
  sim_par.type("double");
  return(true);
}


static void parse_Goto(QGenXMI::blocks qgen_blks, SimulinkModel::XSD::ioport_T& sim_io){
  std::string Tag;

  QGenXMI::blocks::parameters_sequence qgen_par_seq = qgen_blks.parameters();
  QGenXMI::blocks::parameters_iterator qgen_par_i = qgen_par_seq.begin();
  for(qgen_par_i = qgen_par_seq.begin(); qgen_par_i != qgen_par_seq.end(); qgen_par_i++){
    if((*qgen_par_i).name() == "GotoTag"){
      QGenXMI::parameters::value_sequence qgen_val_seq = (*qgen_par_i).value();
      Tag = *(*qgen_val_seq.begin()).litValue();
      break;    
    }
  }

  sim_io.line(gotofrom_connection[Tag].line);
  sim_io.port(gotofrom_connection[Tag].goto_port);
  sim_io.usename( false );

  int i;
  SimulinkModel::XSD::ioport_T::connect_sequence& sim_con_seq = sim_io.connect();
  for(i = 0; i != (int)gotofrom_connection[Tag].from_block.size(); i++){
    SimulinkModel::XSD::connection_T sim_con("","");
    sim_con.block(gotofrom_connection[Tag].from_block.at(i));
    sim_con.port(gotofrom_connection[Tag].from_port.at(i));
    sim_con_seq.push_back(sim_con);
  }
}

/*usename要修正*/
static void parse_From(QGenXMI::blocks qgen_blks, SimulinkModel::XSD::ioport_T& sim_io){
  std::string Tag;

  QGenXMI::blocks::parameters_sequence qgen_par_seq = qgen_blks.parameters();
  QGenXMI::blocks::parameters_iterator qgen_par_i = qgen_par_seq.begin();
  for(qgen_par_i = qgen_par_seq.begin(); qgen_par_i != qgen_par_seq.end(); qgen_par_i++){
    if((*qgen_par_i).name() == "GotoTag"){
      QGenXMI::parameters::value_sequence qgen_val_seq = (*qgen_par_i).value();
      Tag = *(*qgen_val_seq.begin()).litValue();
      break;    
    }
  }

  int i;
  SimulinkModel::XSD::ioport_T::connect_sequence& sim_con_seq = sim_io.connect();
  for(i = 0; i != (int)gotofrom_connection[Tag].from_block.size(); i++){
    if(gotofrom_connection[Tag].from_block.at(i) == qgen_blks.name()){
      break;
    }
  }
  sim_io.line(gotofrom_connection[Tag].line);
  sim_io.port(gotofrom_connection[Tag].from_port.at(i));
  SimulinkModel::XSD::connection_T sim_con("","");
  sim_con.block(gotofrom_connection[Tag].goto_block);
  sim_con.port(gotofrom_connection[Tag].goto_port);
  sim_con_seq.push_back(sim_con);
}


static std::string get_DataStoreName(QGenXMI::blocks qgen_blks){
  QGenXMI::blocks::parameters_sequence qgen_par_seq = qgen_blks.parameters();
  QGenXMI::blocks::parameters_iterator qgen_par_i = qgen_par_seq.begin();
  for(qgen_par_i = qgen_par_seq.begin(); qgen_par_i != qgen_par_seq.end(); qgen_par_i++){
    if( (*qgen_par_i).name() == "DataStoreName"){
      QGenXMI::parameters::value_sequence qgen_val_seq = (*qgen_par_i).value();
      return ( *(*qgen_val_seq.begin()).litValue() );
    }
  }
  return("nothing");
}

static std::string get_Atomic(QGenXMI::blocks qgen_blks){
  QGenXMI::blocks::parameters_sequence qgen_par_seq = qgen_blks.parameters();
  QGenXMI::blocks::parameters_iterator qgen_par_i = qgen_par_seq.begin();
  for(qgen_par_i = qgen_par_seq.begin(); qgen_par_i != qgen_par_seq.end(); qgen_par_i++){
    if( (*qgen_par_i).name() == "AtomicSubSystem"){
      QGenXMI::parameters::value_sequence qgen_val_seq = (*qgen_par_i).value();
      return ( *(*qgen_val_seq.begin()).litValue() );
    }
  }
  return("off");
}



static void printconnect(){
	std::map <int,connect> ::iterator con_i = connection.begin();
	std::cout << "map" << std::endl;
	for(con_i = connection.begin(); con_i != connection.end(); con_i++){
		std::cout << con_i->first << std::endl;
		std::cout << "     " << con_i->second.dst_block << std::endl;
		std::cout << "     " << con_i->second.dst_port << std::endl;
		std::cout << "     " << con_i->second.line << std::endl;
		std::cout << "     " << con_i->second.src_port << std::endl;
		std::cout << "     " << con_i->second.src_block << std::endl;
		std::cout << "     " << con_i->second.usename << std::endl;
	}

}

static void printsubconnect(){
  std::map <int,sub_connect> ::iterator subcon_i = sub_connection.begin();
  std::cout << "map--sub" << std::endl;
  for(subcon_i = sub_connection.begin(); subcon_i != sub_connection.end(); subcon_i++){
    std::cout << subcon_i->first << std::endl;
    std::cout << "  in" << std::endl;
    std::vector<int>::iterator v_i = subcon_i->second.in_line.begin();
    for(v_i = subcon_i->second.in_line.begin(); v_i != subcon_i->second.in_line.end(); v_i++){
      std::cout << "     " << *v_i << std::endl;
    }
    std::cout << "  out" << std::endl;
    for(v_i = subcon_i->second.out_line.begin(); v_i != subcon_i->second.out_line.end(); v_i++){
      std::cout << "     " << *v_i << std::endl;
    }
  }
}


int
main (int argc,  char* const* argv)
{
  int c;
  const char* inxml = NULL;
  const char* outcsv = NULL;

  while ((c = ::getopt (argc,  argv,  "o:")) != -1)
    {
      switch (c)
	{
	case 'o':
	  outcsv = optarg;
	  break;

	default:
	  ::std::cerr << "usage: " << argv[0]
		      << " [-o csv-file] [input-xml]"
		      << ::std::endl;
	  return 1;
	}
    }

  argv += optind - 1;
  argc -= optind - 1;

  if (argc > 1)
    inxml = argv[1];

  try
    {
      ::std::ofstream ofs;
      ::std::ostream *os;

      if (outcsv)
	{
	  ofs.open (outcsv);
	  os = &ofs;
	}
      else{
        ::std::cerr << "please enter outputfile_name" << ::std::endl;
        return 1;
      }
      os->exceptions (::std::ostream::badbit | ::std::ostream::failbit);

      ::std::auto_ptr < QGenXMI::model > sysmodel;

      if (inxml)
	sysmodel = QGenXMI::GASystemModel (inxml,  xml_schema::flags::dont_validate);
      else{
        ::std::cerr << "please enter inputfile_name" << ::std::endl;
        return 1;
      }


  	SimulinkModel::XSD::blocks_T sim_blks;
  	name_model(sysmodel);
   // printsubconnect();
  usename_model(sysmodel);
   // printconnect();
	parse_model(sysmodel, sim_blks);

    /* BLXML出力 */
    xml_schema::namespace_infomap map;
    map["sm"].name = "http://example.com/SimulinkModel";
    map["sm"].schema = "SimulinkModel.xsd";
    SimulinkModel::XSD::blocks(ofs , sim_blks, map);

    /* QGenXMI出力 */
    /*xml_schema::namespace_infomap map;
    map["sm"].name = "http:///geneauto/emf/models/gasystemmodel.ecore";
    map["sm"].schema = "qgen-xmi.xsd";
    QGenXMI::GASystemModel(ofs , *sysmodel, map);*/

    std::cout << "qgen-xmi to blxml successed!!" << std::endl;
    }

  catch (const xml_schema::exception& e)
    {
      ::std::cerr << e << ::std::endl;
      return 1;
    }

  catch (const ::std::ostream::failure e)
    {
      ::std::cerr << e.what () << ::std::endl;
      return 1;
    }

  catch (...)
    {
      ::std::cerr << "ERROR" << ::std::endl;
      return 1;
    }

  return 0;
}