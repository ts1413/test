// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

/**
 * @file
 * @brief Generated from xmi-id.xsd.
 */

#ifndef XMI_ID_HXX
#define XMI_ID_HXX

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/types.hxx>

#include <xsd/cxx/xml/error-handler.hxx>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

#include <xsd/cxx/tree/parsing.hxx>
#include <xsd/cxx/tree/parsing/byte.hxx>
#include <xsd/cxx/tree/parsing/unsigned-byte.hxx>
#include <xsd/cxx/tree/parsing/short.hxx>
#include <xsd/cxx/tree/parsing/unsigned-short.hxx>
#include <xsd/cxx/tree/parsing/int.hxx>
#include <xsd/cxx/tree/parsing/unsigned-int.hxx>
#include <xsd/cxx/tree/parsing/long.hxx>
#include <xsd/cxx/tree/parsing/unsigned-long.hxx>
#include <xsd/cxx/tree/parsing/boolean.hxx>
#include <xsd/cxx/tree/parsing/float.hxx>
#include <xsd/cxx/tree/parsing/double.hxx>
#include <xsd/cxx/tree/parsing/decimal.hxx>

#include <xsd/cxx/xml/dom/serialization-header.hxx>
#include <xsd/cxx/tree/serialization.hxx>
#include <xsd/cxx/tree/serialization/byte.hxx>
#include <xsd/cxx/tree/serialization/unsigned-byte.hxx>
#include <xsd/cxx/tree/serialization/short.hxx>
#include <xsd/cxx/tree/serialization/unsigned-short.hxx>
#include <xsd/cxx/tree/serialization/int.hxx>
#include <xsd/cxx/tree/serialization/unsigned-int.hxx>
#include <xsd/cxx/tree/serialization/long.hxx>
#include <xsd/cxx/tree/serialization/unsigned-long.hxx>
#include <xsd/cxx/tree/serialization/boolean.hxx>
#include <xsd/cxx/tree/serialization/float.hxx>
#include <xsd/cxx/tree/serialization/double.hxx>
#include <xsd/cxx/tree/serialization/decimal.hxx>

/**
 * @brief C++ namespace for the %http://www.w3.org/2001/XMLSchema
 * schema namespace.
 */
namespace xml_schema
{
  // anyType and anySimpleType.
  //

  /**
   * @brief C++ type corresponding to the anyType XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::type type;

  /**
   * @brief C++ type corresponding to the anySimpleType XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::simple_type< char, type > simple_type;

  /**
   * @brief Alias for the anyType type.
   */
  typedef ::xsd::cxx::tree::type container;


  // 8-bit
  //

  /**
   * @brief C++ type corresponding to the byte XML Schema
   * built-in type.
   */
  typedef signed char byte;

  /**
   * @brief C++ type corresponding to the unsignedByte XML Schema
   * built-in type.
   */
  typedef unsigned char unsigned_byte;


  // 16-bit
  //

  /**
   * @brief C++ type corresponding to the short XML Schema
   * built-in type.
   */
  typedef short short_;

  /**
   * @brief C++ type corresponding to the unsignedShort XML Schema
   * built-in type.
   */
  typedef unsigned short unsigned_short;


  // 32-bit
  //

  /**
   * @brief C++ type corresponding to the int XML Schema
   * built-in type.
   */
  typedef int int_;

  /**
   * @brief C++ type corresponding to the unsignedInt XML Schema
   * built-in type.
   */
  typedef unsigned int unsigned_int;


  // 64-bit
  //

  /**
   * @brief C++ type corresponding to the long XML Schema
   * built-in type.
   */
  typedef long long long_;

  /**
   * @brief C++ type corresponding to the unsignedLong XML Schema
   * built-in type.
   */
  typedef unsigned long long unsigned_long;


  // Supposed to be arbitrary-length integral types.
  //

  /**
   * @brief C++ type corresponding to the integer XML Schema
   * built-in type.
   */
  typedef long long integer;

  /**
   * @brief C++ type corresponding to the nonPositiveInteger XML Schema
   * built-in type.
   */
  typedef long long non_positive_integer;

  /**
   * @brief C++ type corresponding to the nonNegativeInteger XML Schema
   * built-in type.
   */
  typedef unsigned long long non_negative_integer;

  /**
   * @brief C++ type corresponding to the positiveInteger XML Schema
   * built-in type.
   */
  typedef unsigned long long positive_integer;

  /**
   * @brief C++ type corresponding to the negativeInteger XML Schema
   * built-in type.
   */
  typedef long long negative_integer;


  // Boolean.
  //

  /**
   * @brief C++ type corresponding to the boolean XML Schema
   * built-in type.
   */
  typedef bool boolean;


  // Floating-point types.
  //

  /**
   * @brief C++ type corresponding to the float XML Schema
   * built-in type.
   */
  typedef float float_;

  /**
   * @brief C++ type corresponding to the double XML Schema
   * built-in type.
   */
  typedef double double_;

  /**
   * @brief C++ type corresponding to the decimal XML Schema
   * built-in type.
   */
  typedef double decimal;


  // String types.
  //

  /**
   * @brief C++ type corresponding to the string XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::string< char, simple_type > string;

  /**
   * @brief C++ type corresponding to the normalizedString XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::normalized_string< char, string > normalized_string;

  /**
   * @brief C++ type corresponding to the token XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::token< char, normalized_string > token;

  /**
   * @brief C++ type corresponding to the Name XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::name< char, token > name;

  /**
   * @brief C++ type corresponding to the NMTOKEN XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::nmtoken< char, token > nmtoken;

  /**
   * @brief C++ type corresponding to the NMTOKENS XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::nmtokens< char, simple_type, nmtoken > nmtokens;

  /**
   * @brief C++ type corresponding to the NCName XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::ncname< char, name > ncname;

  /**
   * @brief C++ type corresponding to the language XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::language< char, token > language;


  // ID/IDREF.
  //

  /**
   * @brief C++ type corresponding to the ID XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::id< char, ncname > id;

  /**
   * @brief C++ type corresponding to the IDREF XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::idref< char, ncname, type > idref;

  /**
   * @brief C++ type corresponding to the IDREFS XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::idrefs< char, simple_type, idref > idrefs;


  // URI.
  //

  /**
   * @brief C++ type corresponding to the anyURI XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::uri< char, simple_type > uri;


  // Qualified name.
  //

  /**
   * @brief C++ type corresponding to the QName XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::qname< char, simple_type, uri, ncname > qname;


  // Binary.
  //

  /**
   * @brief Binary buffer type.
   */
  typedef ::xsd::cxx::tree::buffer< char > buffer;

  /**
   * @brief C++ type corresponding to the base64Binary XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::base64_binary< char, simple_type > base64_binary;

  /**
   * @brief C++ type corresponding to the hexBinary XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::hex_binary< char, simple_type > hex_binary;


  // Date/time.
  //

  /**
   * @brief Time zone type.
   */
  typedef ::xsd::cxx::tree::time_zone time_zone;

  /**
   * @brief C++ type corresponding to the date XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::date< char, simple_type > date;

  /**
   * @brief C++ type corresponding to the dateTime XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::date_time< char, simple_type > date_time;

  /**
   * @brief C++ type corresponding to the duration XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::duration< char, simple_type > duration;

  /**
   * @brief C++ type corresponding to the gDay XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gday< char, simple_type > gday;

  /**
   * @brief C++ type corresponding to the gMonth XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gmonth< char, simple_type > gmonth;

  /**
   * @brief C++ type corresponding to the gMonthDay XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gmonth_day< char, simple_type > gmonth_day;

  /**
   * @brief C++ type corresponding to the gYear XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gyear< char, simple_type > gyear;

  /**
   * @brief C++ type corresponding to the gYearMonth XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gyear_month< char, simple_type > gyear_month;

  /**
   * @brief C++ type corresponding to the time XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::time< char, simple_type > time;


  // Entity.
  //

  /**
   * @brief C++ type corresponding to the ENTITY XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::entity< char, ncname > entity;

  /**
   * @brief C++ type corresponding to the ENTITIES XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::entities< char, simple_type, entity > entities;



  /**
   * @brief Content order sequence entry.
   */
  typedef ::xsd::cxx::tree::content_order content_order;
  // Namespace information and list stream. Used in
  // serialization functions.
  //
  /**
   * @brief Namespace serialization information.
   */
  typedef ::xsd::cxx::xml::dom::namespace_info< char > namespace_info;

  /**
   * @brief Namespace serialization information map.
   */
  typedef ::xsd::cxx::xml::dom::namespace_infomap< char > namespace_infomap;

  /**
   * @brief List serialization stream.
   */
  typedef ::xsd::cxx::tree::list_stream< char > list_stream;

  /**
   * @brief Serialization wrapper for the %double type.
   */
  typedef ::xsd::cxx::tree::as_double< double_ > as_double;

  /**
   * @brief Serialization wrapper for the %decimal type.
   */
  typedef ::xsd::cxx::tree::as_decimal< decimal > as_decimal;

  /**
   * @brief Simple type facet.
   */
  typedef ::xsd::cxx::tree::facet facet;

  // Flags and properties.
  //

  /**
   * @brief Parsing and serialization flags.
   */
  typedef ::xsd::cxx::tree::flags flags;

  /**
   * @brief Parsing properties.
   */
  typedef ::xsd::cxx::tree::properties< char > properties;

  // Parsing/serialization diagnostics.
  //

  /**
   * @brief Error severity.
   */
  typedef ::xsd::cxx::tree::severity severity;

  /**
   * @brief Error condition.
   */
  typedef ::xsd::cxx::tree::error< char > error;

  /**
   * @brief List of %error conditions.
   */
  typedef ::xsd::cxx::tree::diagnostics< char > diagnostics;

  // Exceptions.
  //

  /**
   * @brief Root of the C++/Tree %exception hierarchy.
   */
  typedef ::xsd::cxx::tree::exception< char > exception;

  /**
   * @brief Exception indicating that the size argument exceeds
   * the capacity argument.
   */
  typedef ::xsd::cxx::tree::bounds< char > bounds;

  /**
   * @brief Exception indicating that a duplicate ID value
   * was encountered in the object model.
   */
  typedef ::xsd::cxx::tree::duplicate_id< char > duplicate_id;

  /**
   * @brief Exception indicating a parsing failure.
   */
  typedef ::xsd::cxx::tree::parsing< char > parsing;

  /**
   * @brief Exception indicating that an expected element
   * was not encountered.
   */
  typedef ::xsd::cxx::tree::expected_element< char > expected_element;

  /**
   * @brief Exception indicating that an unexpected element
   * was encountered.
   */
  typedef ::xsd::cxx::tree::unexpected_element< char > unexpected_element;

  /**
   * @brief Exception indicating that an expected attribute
   * was not encountered.
   */
  typedef ::xsd::cxx::tree::expected_attribute< char > expected_attribute;

  /**
   * @brief Exception indicating that an unexpected enumerator
   * was encountered.
   */
  typedef ::xsd::cxx::tree::unexpected_enumerator< char > unexpected_enumerator;

  /**
   * @brief Exception indicating that the text content was
   * expected for an element.
   */
  typedef ::xsd::cxx::tree::expected_text_content< char > expected_text_content;

  /**
   * @brief Exception indicating that a prefix-namespace
   * mapping was not provided.
   */
  typedef ::xsd::cxx::tree::no_prefix_mapping< char > no_prefix_mapping;

  /**
   * @brief Exception indicating a serialization failure.
   */
  typedef ::xsd::cxx::tree::serialization< char > serialization;

  /**
   * @brief Error handler callback interface.
   */
  typedef ::xsd::cxx::xml::error_handler< char > error_handler;

  /**
   * @brief DOM interaction.
   */
  namespace dom
  {
    /**
     * @brief Automatic pointer for DOMDocument.
     */
    using ::xsd::cxx::xml::dom::auto_ptr;

#ifndef XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
#define XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
    /**
     * @brief DOM user data key for back pointers to tree nodes.
     */
    const XMLCh* const tree_node_key = ::xsd::cxx::tree::user_data_keys::node;
#endif
  }
}

// Forward declarations.
//
namespace XMI
{
  class type;
  class id;
}


#include <memory>    // ::std::auto_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

/**
 * @brief C++ namespace for the %http://schema.omg.org/spec/XMI/2.1
 * schema namespace.
 */
namespace XMI
{
  /**
   * @brief Class corresponding to the %type schema type.
   *
   * @nosubgrouping
   */
  class type: public ::xml_schema::string
  {
    public:
    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from initializers for required 
     * elements and attributes.
     */
    type ();

    /**
     * @brief Create an instance from a C string and initializers
     * for required elements and attributes.
     */
    type (const char*);

    /**
     * @brief Create an instance from a string andinitializers
     * for required elements and attributes.
     */
    type (const ::std::string&);

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    type (const ::xml_schema::string&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    type (const ::xercesc::DOMElement& e,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

    /**
     * @brief Create an instance from a DOM attribute.
     *
     * @param a A DOM attribute to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    type (const ::xercesc::DOMAttr& a,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

    /**
     * @brief Create an instance from a string fragment.
     *
     * @param s A string fragment to extract the data from.
     * @param e A pointer to DOM element containing the string fragment.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    type (const ::std::string& s,
          const ::xercesc::DOMElement* e,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    type (const type& x,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual type*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~type ();
  };

  /**
   * @brief Class corresponding to the %id schema type.
   *
   * @nosubgrouping
   */
  class id: public ::xsd::cxx::tree::fundamental_base< ::xml_schema::int_, char, ::xml_schema::simple_type >
  {
    public:
    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    id (const ::xml_schema::int_&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    id (const ::xercesc::DOMElement& e,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

    /**
     * @brief Create an instance from a DOM attribute.
     *
     * @param a A DOM attribute to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    id (const ::xercesc::DOMAttr& a,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

    /**
     * @brief Create an instance from a string fragment.
     *
     * @param s A string fragment to extract the data from.
     * @param e A pointer to DOM element containing the string fragment.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    id (const ::std::string& s,
        const ::xercesc::DOMElement* e,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    id (const id& x,
        ::xml_schema::flags f = 0,
        ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual id*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~id ();
  };
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace XMI
{
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace XMI
{
  void
  operator<< (::xercesc::DOMElement&, const type&);

  void
  operator<< (::xercesc::DOMAttr&, const type&);

  void
  operator<< (::xml_schema::list_stream&,
              const type&);

  void
  operator<< (::xercesc::DOMElement&, const id&);

  void
  operator<< (::xercesc::DOMAttr&, const id&);

  void
  operator<< (::xml_schema::list_stream&,
              const id&);
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // XMI_ID_HXX