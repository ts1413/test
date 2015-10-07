qgen-xmi_parser: qgen-xmi_parser.o qgen-xmi.a
				g++ -g -L/usr/local/lib  qgen-xmi_parser.o qgen-xmi.a -lxerces-c  -lboost_regex -o qgen-xmi_parser

qgen-xmi_parser.o: qgen-xmi_parser.cxx qgen-xmi.hxx xmi-id.hxx SimulinkModel.hxx
				g++ -Wall -g -ffunction-sections -fdata-sections -I/usr/local/include -DSHIM_XSD_VERSION=20150212  -c -o qgen-xmi_parser.o qgen-xmi_parser.cxx
				

qgen-xmi.a: qgen-xmi.o xmi-id.o SimulinkModel.o
				ar rv qgen-xmi.a qgen-xmi.o xmi-id.o SimulinkModel.o


qgen-xmi.o: qgen-xmi.cxx qgen-xmi.hxx xmi-id.cxx xmi-id.hxx
				g++ -Wall -g -ffunction-sections -fdata-sections -fPIC -O2 -I/usr/local/include -DSHIM_XSD_VERSION=20150212  -c -o qgen-xmi.o qgen-xmi.cxx

qgen-xmi.cxx qgen-xmi.hxx: qgen-xmi_c&h

qgen-xmi_c&h: qgen-xmi.xsd
				xsd cxx-tree --generate-serialization --generate-doxygen --char-encoding utf8 --root-element GASystemModel --namespace-map http:///geneauto/emf/models/gasystemmodel.ecore=QGenXMI --namespace-map http://schema.omg.org/spec/XMI/2.1=XMI qgen-xmi.xsd


xmi-id.o: xmi-id.cxx xmi-id.hxx
				g++ -Wall -g -ffunction-sections -fdata-sections -fPIC -O2 -I/usr/local/include -DSHIM_XSD_VERSION=20150212  -c -o xmi-id.o xmi-id.cxx

xmi-id.cxx xmi-id.hxx: xmi-id_c&h

xmi-id_c&h: xmi-id.xsd
				xsd cxx-tree --generate-serialization --generate-doxygen --char-encoding utf8 --namespace-map http://schema.omg.org/spec/XMI/2.1=XMI xmi-id.xsd


SimulinkModel.o: SimulinkModel.cxx SimulinkModel.hxx
				g++ -Wall -g -ffunction-sections -fdata-sections -fPIC -O2 -I/usr/local/include -DSHIM_XSD_VERSION=20150212  -c -o SimulinkModel.o SimulinkModel.cxx

SimulinkModel.cxx SimulinkModel.hxx: SimulinkModel_c&h

SimulinkModel_c&h: SimulinkModel.xsd
				xsd cxx-tree --generate-serialization --generate-doxygen --char-encoding utf8 --root-element blocks --namespace-map http://example.com/SimulinkModel=SimulinkModel::XSD SimulinkModel.xsd
