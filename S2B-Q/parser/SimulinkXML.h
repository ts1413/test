// -*- mode: c++ -*-
#ifndef SIMULINKXML_H
#define SIMULINKXML_H

typedef struct s_simulink c_simulink_T;
typedef struct s_blocks c_blocks_T;
typedef struct s_block c_block_T;
typedef struct s_ioport c_ioport_T;
typedef struct s_connection c_connection_T;
typedef struct s_var c_var_T;
typedef struct s_param c_param_T;
typedef struct s_code c_code_T;
typedef struct s_link c_link_T;

#ifdef __cplusplus

#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>

#include <xercesc/dom/DOM.hpp>
#include <xsd/cxx/xml/string.hxx>

#include "SimulinkModel.hxx"

namespace Simulink
{
  namespace XML
  {
    class BlockInfo;

    BlockInfo* find_multirate_subsystem (const BlockInfo* binfo);

    typedef ::std::vector < BlockInfo* > block_list_T;
    typedef block_list_T::iterator block_list_iterator;
    typedef block_list_T::const_iterator block_list_const_iterator;

    class const_block_list_T : public ::std::vector < const BlockInfo* >
    {
    public:
      const_block_list_T () : l_any (0) {}
      const_block_list_T (size_t size, const BlockInfo* b)
	: ::std::vector < const BlockInfo* > (size, b), l_any (0)
      {
      }

      const BlockInfo*
      operator+= (const BlockInfo* b) { addinfo (b); return b; }

      bool
      checkinfo (const BlockInfo* b) const
      {
	const_iterator i = find (begin (), end (), b);
	return i != end ();
      }

      void
      addinfo (const BlockInfo* b)
      {
	if (find (begin (), end (), b) == end ())
	  push_back (b);
      }

      // flag for any
      unsigned long any (void) const { return l_any; }
      unsigned long& any (void) { return l_any; }
    private:
      unsigned long l_any;
    };

    typedef const_block_list_T::iterator const_block_list_iterator;
    typedef const_block_list_T::const_iterator const_block_list_const_iterator;

    typedef ::std::vector < const ::SimulinkModel::XSD::var_T* > var_list_T;

    class BlockConnect
    {
    public:
      BlockConnect () {}
      BlockConnect (BlockInfo* tail, BlockInfo* head)
	: bc_tail (tail), bc_head (head)
      {
      }

      const var_list_T& var_list (void) const { return bc_var_list; }
      var_list_T& var_list (void) { return bc_var_list; }

      BlockInfo* head (void) const { return bc_head; }
      BlockInfo*& head (void) { return bc_head; }
      BlockInfo* tail (void) const { return bc_tail; }
      BlockInfo*& tail (void) { return bc_tail; }

      bool operator== (const BlockConnect& bc) const
      {
	return tail () == bc.tail () && head () == bc.head ();
      }

    private:

      var_list_T bc_var_list;

      BlockInfo* bc_tail;
      BlockInfo* bc_head;
    };

    typedef ::std::vector < BlockConnect > block_connect_list_T;

    class Reader;

    class BlockInfo
    {
    public:
      typedef enum { ATOMIC,
		     ENABLED,
		     TRIGGERED,
		     ENABLED_TRIGGERED,
		     ACTION,
		     ITERATOR } subsystem_type_T;

      BlockInfo(::SimulinkModel::XSD::block_T* block,
		::SimulinkModel::XSD::block_T* upper = NULL);

      unsigned int
      id (void) const
      {
	return b_id;
      }

      ::SimulinkModel::XSD::block_T*
      block (void) const
      {
	return b_block;
      }

      ::SimulinkModel::XSD::block_T*&
      block (void)
      {
	return b_block;
      }

      ::SimulinkModel::XSD::block_T*
      upper (void) const
      {
	return b_upper;
      }

      ::SimulinkModel::XSD::block_T*&
      upper (void)
      {
	return b_upper;
      }

      bool is_subsystem (void) const { return b_is_subsystem; }
      bool& is_subsystem (void) { return b_is_subsystem; }

      bool has_update (void) const { return b_has_update; }
      bool& has_update (void) { return b_has_update; }

      bool is_sfunction (void) const { return b_is_sfunction; }
      bool& is_sfunction (void) { return b_is_sfunction; }

      subsystem_type_T
      subsystem_type (void) const
      {
	return b_subsystem_type;
      }

      subsystem_type_T& subsystem_type (void) { return b_subsystem_type; }

      BlockInfo* upper_subsystem (void) const { return b_upper_subsystem; }
      BlockInfo*& upper_subsystem (void) { return b_upper_subsystem; }

      const block_list_T& lower_block (void) const { return b_lower_block; }
      block_list_T& lower_block (void) { return b_lower_block; }

      const block_connect_list_T& forward (void) const { return b_forward; }
      block_connect_list_T& forward (void) { return b_forward; }

      const block_connect_list_T& backword (void) const { return b_backword; }
      block_connect_list_T& backword (void) { return b_backword; }

      BlockInfo* top_subsystem (void) const { return b_top_subsystem; }
      BlockInfo*& top_subsystem (void) { return b_top_subsystem; }

      ::SimulinkModel::XSD::block_T* top (void) const { return b_top; }
      ::SimulinkModel::XSD::block_T*& top (void) { return b_top; }

      const block_list_T&
      contain_block (void) const
      {
	return b_contain_block;
      }
      block_list_T& contain_block (void) { return b_contain_block; }

      bool is_contained (const BlockInfo* b) const;
      bool is_contained (const ::SimulinkModel::XSD::block_T* b) const;

      const block_list_T& merged_to (void) const { return b_merged_to; }
      block_list_T& merged_to (void) { return b_merged_to; }

      const block_list_T& merge_blocks (void) const { return b_merge_blocks; }
      block_list_T& merge_blocks (void) { return b_merge_blocks; }

      const block_list_T& bound_to (void) const { return b_bound_to; }
      block_list_T& bound_to (void) { return b_bound_to; }
      
      const block_list_T& bind_blocks (void) const { return b_bind_blocks; }
      block_list_T& bind_blocks (void) { return b_bind_blocks; }

      void dump (void) const;

      bool operator== (const ::std::string& name) const
      {
	return block ()->name () == name;
      }

      friend class Reader;

      static unsigned int max_id (void) { return seq; }

    protected:
      void set_newid (void) { b_id = ++seq; }

    private:
      static unsigned int seq;

      unsigned int b_id;

      SimulinkModel::XSD::block_T* b_block;
      SimulinkModel::XSD::block_T* b_upper;

      bool b_is_subsystem;
      bool b_has_update;
      bool b_is_sfunction;

      subsystem_type_T b_subsystem_type;

      BlockInfo* b_upper_subsystem;	/* SubSystem */
      block_list_T b_lower_block;	/* lower block in SubSystem */

      block_connect_list_T b_forward;
      block_connect_list_T b_backword;

      // Toplevel Subsystem (e.g. ForIterator)
      SimulinkModel::XSD::block_T* b_top;
      BlockInfo* b_top_subsystem;

      block_list_T b_contain_block;

      // merge
      block_list_T b_merged_to;
      block_list_T b_merge_blocks;

      // bind
      block_list_T b_bound_to;
      block_list_T b_bind_blocks;
    };

    typedef ::std::map< ::std::string, BlockInfo > block_map_T;
    typedef block_map_T::iterator block_map_iterator;
    typedef block_map_T::const_iterator block_map_const_iterator;

    class IOPort
    {
    public:
      IOPort ();
      IOPort (::SimulinkModel::XSD::block_T* block,
	      ::SimulinkModel::XSD::ioport_T* ioport);

      ::SimulinkModel::XSD::block_T*
      block_tag (void) const
      {
	return iop_block_tag;
      }

      ::SimulinkModel::XSD::block_T*&
      block_tag (void)
      {
	return iop_block_tag;
      }

      ::SimulinkModel::XSD::ioport_T*
      ioport_tag (void) const
      {
	return iop_ioport_tag;
      }

      ::SimulinkModel::XSD::ioport_T*&
      ioport_tag (void)
      {
	return iop_ioport_tag;
      }

      const ::std::string&
      blockname (void) const
      {
	return iop_block_tag->name();
      }

      ::std::string&
      blockname (void)
      {
	return iop_block_tag->name();
      }

      const ::std::string&
      port (void) const
      {
	return iop_ioport_tag->port();
      }

      ::std::string&
      port (void)
      {
	return iop_ioport_tag->port();
      }

      const ::std::string&
      line (void) const
      {
	return iop_ioport_tag->line();
      }

      ::std::string&
      line (void)
      {
	return iop_ioport_tag->line();
      }

      bool
      match (const ::std::string& b, const ::std::string& p) const
      {
	return blockname() == b && port () == p;
      }

      void dump (void) const;

    private:
      ::SimulinkModel::XSD::block_T* iop_block_tag;
      ::SimulinkModel::XSD::ioport_T* iop_ioport_tag;
    };

    typedef ::std::multimap< ::std::string, IOPort > ioport_map_T;
    typedef ioport_map_T::iterator ioport_map_iterator;
    typedef ioport_map_T::const_iterator ioport_map_const_iterator;
    typedef ::std::pair< ioport_map_iterator,
			 ioport_map_iterator > ioport_map_iterator_pair;
    typedef ::std::pair< ioport_map_const_iterator,
			 ioport_map_const_iterator >
    ioport_map_const_iterator_pair;

    class Reader
    {
    public:
      Reader();
      Reader (const char* xml, bool validation = true);

      const ::SimulinkModel::XSD::blocks_T&
      xml_blocks (void) const
      {
	return *r_blocks;
      }

      ::SimulinkModel::XSD::blocks_T&
      xml_blocks (void)
      {
	return *r_blocks;
      }

      const block_map_T&
      block_map (void) const
      {
	return r_block_map;
      }

      block_map_T&
      block_map (void)
      {
	return r_block_map;
      }

      const ioport_map_T&
      input_map (void) const
      {
	return r_input_map;
      }

      ioport_map_T&
      input_map (void)
      {
	return r_input_map;
      }

      const ioport_map_T&
      output_map (void) const
      {
	return r_output_map;
      }

      ioport_map_T&
      output_map (void)
      {
	return r_output_map;
      }

      const block_list_T&
      block_list (void) const
      {
	return r_block_list;
      }

      block_list_T&
      block_list (void)
      {
	return r_block_list;
      }

      const IOPort* find_input_port (const ::std::string& block,
				     const ::std::string& port) const;
      IOPort* find_input_port (const ::std::string& block,
			       const ::std::string& port);
      const IOPort* find_output_port (const ::std::string& block,
				      const ::std::string& port) const;
      IOPort* find_output_port (const ::std::string& block,
				const ::std::string& port);

      const BlockInfo* find_block (const ::std::string& block) const;
      BlockInfo* find_block (const ::std::string& block);

      int load_xml (const char* xml, bool validation = true);

      void dump (void) const;

      operator bool () const
      {
	return r_blocks.get() != NULL;
      }

      enum search_dir { SEARCH_FORWARD, SEARCH_BACKWORD };

      int find_loop (int index, int *route,
		     search_dir dir = SEARCH_FORWARD,
		     bool break_multirate = false) const;

      int find_loop (int index, search_dir dir = SEARCH_FORWARD,
		     bool break_multirate = false) const;

    protected:

      int depth_search_for_loop (int s_index, int c_index,
				 int* color, int* route,
				 search_dir dir,
				 bool break_multirate) const;

      BlockInfo& add_block_map (SimulinkModel::XSD::block_T* upper,
				SimulinkModel::XSD::block_T& block);

      IOPort& add_input_map (SimulinkModel::XSD::block_T* block,
			     SimulinkModel::XSD::ioport_T* ioport);

      IOPort& add_output_map (SimulinkModel::XSD::block_T* block,
			      SimulinkModel::XSD::ioport_T* ioport);

      void process_blocks (BlockInfo* top,
			   SimulinkModel::XSD::block_T* upper,
			   BlockInfo* subsystem,
			   SimulinkModel::XSD::blocks_T& blocks);
      void process_blocks_complete ();
      void process_port (SimulinkModel::XSD::blocks_T& blocks);
      void process_graph (void);
      void process_all (void);

    private:

      ::std::auto_ptr< SimulinkModel::XSD::blocks_T > r_blocks;

      block_map_T r_block_map;
      ioport_map_T r_input_map;
      ioport_map_T r_output_map;

      block_list_T r_block_list;
    };

    class c_mark
    {
    public:
      c_mark (const char* b, const char* e,
	      const char* tb, const char* te,
	      char t, unsigned int i, const ::std::string& n)
	: x_beg (b), x_end (e), x_text_beg (tb), x_text_end (te),
	  x_type (t), x_num (i), x_name (n)
      {}

      void
      set (const char* b, const char* e,
	   const char* tb, const char* te,
	   char t, unsigned int i, const ::std::string& n)
      {
	x_beg = b;
	x_end = e;
	x_text_beg = tb;
	x_text_end = te;
	x_type = t;
	x_num = i;
	x_name = n;
      }

      const char* beg (void) const { return x_beg; }
      const char*& beg (void) { return x_beg; }
      const char* end (void) const { return x_end; }
      const char*& end (void) { return x_end; }
      const char* text_beg (void) const { return x_text_beg; }
      const char*& text_beg (void) { return x_text_beg; }
      const char* text_end (void) const { return x_text_end; }
      const char*& text_end (void) { return x_text_end; }
      char type (void) const { return x_type; }
      char& type (void) { return x_type; }
      unsigned int num (void) const { return x_num; }
      unsigned int& num (void) { return x_num; }
      const ::std::string& name (void) const { return x_name; }
      ::std::string& name (void) { return x_name; }

      operator ::std::string () const
      {
	return ::std::string (x_text_beg, x_text_end - x_text_beg);
      }

    private:
      const char* x_beg;
      const char* x_end;
      const char* x_text_beg;
      const char* x_text_end;
      char x_type;
      unsigned int x_num;
      ::std::string x_name;
    };

    typedef ::std::vector < c_mark > marklist_T;

    class codelist
    {
    public:

      codelist() {}
      ~codelist() {}

      void process (const char* beg, const char* end);

      codelist (const char* beg, const char* end) { process (beg, end); }
      codelist (const ::std::string& str)
      {
	const char* beg = str.c_str();
	const char* end = beg + str.length ();
	process (beg, end);
      }

      const marklist_T& mark_list (void) const { return list; }
      marklist_T& mark_list (void) { return list; }

    private:
      marklist_T list;
    };
  }
}

extern "C" {
#endif
  c_simulink_T* load_all_file (const char* xml,
			       const char* header,
			       const char* source,
			       const char* data);

  c_blocks_T* get_top_blocks (c_simulink_T* s);

  const char* get_blocks_name (c_blocks_T* bs);

  c_block_T* get_first_block (c_blocks_T* bs);
  c_block_T* get_next_block (c_block_T* i);

  const char* get_block_name (c_block_T* b);
  const char* get_block_blocktype (c_block_T* b);
  const char* get_block_rate (c_block_T* b);

  c_blocks_T* get_first_blocks (c_block_T* b);
  c_blocks_T* get_next_blocks (c_blocks_T* i);

  c_ioport_T* get_first_input (c_block_T* b);
  c_ioport_T* get_next_input (c_ioport_T* i);

  c_ioport_T* get_first_output (c_block_T* b);
  c_ioport_T* get_next_output (c_ioport_T* i);

  const char* get_ioport_line (c_ioport_T* p);
  const char* get_ioport_port (c_ioport_T* p);

  c_connection_T* get_first_connection (c_ioport_T* b);
  c_connection_T* get_next_connection (c_connection_T* i);

  const char* get_connection_block (c_connection_T* c);
  const char* get_connection_port (c_connection_T* c);

  c_var_T* get_first_variable (c_block_T* b);
  c_var_T* get_next_variable (c_var_T* i);

  const char* get_variable_name (c_var_T* v);
  const char* get_variable_type (c_var_T* v);
  const char* get_varibale_mode (c_var_T* v);

  c_param_T* get_first_param (c_block_T* b);
  c_param_T* get_next_param (c_param_T* i);

  c_param_T* get_first_state (c_block_T* b);
  c_param_T* get_next_state (c_param_T* i);

  c_param_T* get_first_const_param (c_block_T* b);
  c_param_T* get_next_const_param (c_block_T* i);

  const char* get_param_storage (c_param_T* p);
  const char* get_param_name (c_param_T* p);
  const char* get_param_type (c_param_T* p);

  c_code_T* get_first_code (c_block_T* b);
  c_code_T* get_next_code (c_code_T* i);

  const char* get_code_type (c_code_T* c);
  const char* get_code_text (c_code_T* c);

  c_link_T* get_first_forward (c_block_T* b);
  c_link_T* get_next_forward (c_link_T* i);

  c_link_T* get_first_backword (c_block_T* b);
  c_link_T* get_next_backword (c_link_T* i);

  const char* get_link_block (c_link_T* l);
  const char* get_link_type (c_link_T* l);

#ifdef __cplusplus
}
#endif

#endif	/* SIMULINKXML_H */
