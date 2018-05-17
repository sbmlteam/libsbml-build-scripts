/**
 * @file ParametricObject.h
 * @brief Definition of the ParametricObject class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class ParametricObject
 * @sbmlbrief{spatial} TODO:Definition of the ParametricObject class.
 */


#ifndef ParametricObject_H__
#define ParametricObject_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/spatial/common/spatialfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/spatial/extension/SpatialExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ParametricObject : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  PolygonKind_t mPolygonType;
  std::string mDomainType;
  int* mPointIndex;
  int mPointIndexLength;
  bool mIsSetPointIndexLength;
  CompressionKind_t mCompression;
  DataKind_t mDataType;

  /** @endcond */

public:

  /**
   * Creates a new ParametricObject using the given SBML Level, Version and
   * &ldquo;spatial&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ParametricObject.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ParametricObject.
   *
   * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
   * this ParametricObject.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ParametricObject(unsigned int level = SpatialExtension::getDefaultLevel(),
                   unsigned int version =
                     SpatialExtension::getDefaultVersion(),
                   unsigned int pkgVersion =
                     SpatialExtension::getDefaultPackageVersion());


  /**
   * Creates a new ParametricObject using the given SpatialPkgNamespaces
   * object.
   *
   * @param spatialns the SpatialPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ParametricObject(SpatialPkgNamespaces *spatialns);


  /**
   * Copy constructor for ParametricObject.
   *
   * @param orig the ParametricObject instance to copy.
   */
  ParametricObject(const ParametricObject& orig);


  /**
   * Assignment operator for ParametricObject.
   *
   * @param rhs the ParametricObject object whose values are to be used as the
   * basis of the assignment.
   */
  ParametricObject& operator=(const ParametricObject& rhs);


  /**
   * Creates and returns a deep copy of this ParametricObject object.
   *
   * @return a (deep) copy of this ParametricObject object.
   */
  virtual ParametricObject* clone() const;


  /**
   * Destructor for ParametricObject.
   */
  virtual ~ParametricObject();


  /**
   * Returns the value of the "id" attribute of this ParametricObject.
   *
   * @return the value of the "id" attribute of this ParametricObject as a
   * string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "polygonType" attribute of this ParametricObject.
   *
   * @return the value of the "polygonType" attribute of this ParametricObject
   * as a PolygonKind_t.
   */
  PolygonKind_t getPolygonType() const;


  /**
   * Returns the value of the "polygonType" attribute of this ParametricObject.
   *
   * @return the value of the "polygonType" attribute of this ParametricObject
   * as a string.
   */
  std::string getPolygonTypeAsString() const;
  //bgoli22


  /**
   * Returns the value of the "domainType" attribute of this ParametricObject.
   *
   * @return the value of the "domainType" attribute of this ParametricObject
   * as a string.
   */
  const std::string& getDomainType() const;


  /**
   * Returns the value of the "pointIndex" attribute of this ParametricObject.
   *
   * @param outArray int* array that will be used to return the value of the
   * "pointIndex" attribute of this ParametricObject.
   *
   * @note the value of the "pointIndex" attribute of this ParametricObject is
   * returned in the argument array.
   */
  void getPointIndex(int* outArray) const;


  /**
   * Returns the value of the "pointIndexLength" attribute of this
   * ParametricObject.
   *
   * @return the value of the "pointIndexLength" attribute of this
   * ParametricObject as a integer.
   */
  int getPointIndexLength() const;


  /**
   * Returns the value of the "compression" attribute of this ParametricObject.
   *
   * @return the value of the "compression" attribute of this ParametricObject
   * as a CompressionKind_t.
   */
  CompressionKind_t getCompression() const;


  /**
   * Returns the value of the "compression" attribute of this ParametricObject.
   *
   * @return the value of the "compression" attribute of this ParametricObject
   * as a string.
   */
  const std::string& getCompressionAsString() const;


  /**
   * Returns the value of the "dataType" attribute of this ParametricObject.
   *
   * @return the value of the "dataType" attribute of this ParametricObject as
   * a DataKind_t.
   */
  DataKind_t getDataType() const;


  /**
   * Returns the value of the "dataType" attribute of this ParametricObject.
   *
   * @return the value of the "dataType" attribute of this ParametricObject as
   * a string.
   */
  std::string getDataTypeAsString() const;
  //bgoli22


  /**
   * Predicate returning @c true if this ParametricObject's "id" attribute is
   * set.
   *
   * @return @c true if this ParametricObject's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true if this ParametricObject's "polygonType"
   * attribute is set.
   *
   * @return @c true if this ParametricObject's "polygonType" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetPolygonType() const;


  /**
   * Predicate returning @c true if this ParametricObject's "domainType"
   * attribute is set.
   *
   * @return @c true if this ParametricObject's "domainType" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetDomainType() const;


  /**
   * Predicate returning @c true if this ParametricObject's "pointIndex"
   * attribute is set.
   *
   * @return @c true if this ParametricObject's "pointIndex" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetPointIndex() const;


  /**
   * Predicate returning @c true if this ParametricObject's "pointIndexLength"
   * attribute is set.
   *
   * @return @c true if this ParametricObject's "pointIndexLength" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetPointIndexLength() const;


  /**
   * Predicate returning @c true if this ParametricObject's "compression"
   * attribute is set.
   *
   * @return @c true if this ParametricObject's "compression" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetCompression() const;


  /**
   * Predicate returning @c true if this ParametricObject's "dataType"
   * attribute is set.
   *
   * @return @c true if this ParametricObject's "dataType" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetDataType() const;


  /**
   * Sets the value of the "id" attribute of this ParametricObject.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Sets the value of the "polygonType" attribute of this ParametricObject.
   *
   * @param polygonType PolygonKind_t value of the "polygonType" attribute to
   * be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPolygonType(const PolygonKind_t polygonType);


  /**
   * Sets the value of the "polygonType" attribute of this ParametricObject.
   *
   * @param polygonType std::string& of the "polygonType" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPolygonType(const std::string& polygonType);


  /**
   * Sets the value of the "domainType" attribute of this ParametricObject.
   *
   * @param domainType std::string& value of the "domainType" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDomainType(const std::string& domainType);


  /**
   * Sets the value of the "pointIndex" attribute of this ParametricObject.
   *
   * @param inArray int* array value of the "pointIndex" attribute to be set.
   *
   * @param arrayLength int value for the length of the "pointIndex" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPointIndex(int* inArray, int arrayLength);


  /**
   * Sets the value of the "pointIndexLength" attribute of this
   * ParametricObject.
   *
   * @param pointIndexLength int value of the "pointIndexLength" attribute to
   * be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPointIndexLength(int pointIndexLength);


  /**
   * Sets the value of the "compression" attribute of this ParametricObject.
   *
   * @param compression CompressionKind_t value of the "compression" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCompression(const CompressionKind_t compression);


  /**
   * Sets the value of the "compression" attribute of this ParametricObject.
   *
   * @param compression std::string& of the "compression" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCompression(const std::string& compression);


  /**
   * Sets the value of the "dataType" attribute of this ParametricObject.
   *
   * @param dataType DataKind_t value of the "dataType" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDataType(const DataKind_t dataType);


  /**
   * Sets the value of the "dataType" attribute of this ParametricObject.
   *
   * @param dataType std::string& of the "dataType" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDataType(const std::string& dataType);


  /**
   * Unsets the value of the "id" attribute of this ParametricObject.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "polygonType" attribute of this ParametricObject.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPolygonType();


  /**
   * Unsets the value of the "domainType" attribute of this ParametricObject.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDomainType();


  /**
   * Unsets the value of the "pointIndex" attribute of this ParametricObject.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPointIndex();


  /**
   * Unsets the value of the "pointIndexLength" attribute of this
   * ParametricObject.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPointIndexLength();


  /**
   * Unsets the value of the "compression" attribute of this ParametricObject.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCompression();


  /**
   * Unsets the value of the "dataType" attribute of this ParametricObject.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDataType();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this ParametricObject object.
   *
   * For ParametricObject, the XML element name is always @c
   * "parametricObject".
   *
   * @return the name of this element, i.e. @c "parametricObject".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ParametricObject object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_SPATIAL_PARAMETRICOBJECT, SBMLSpatialTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * ParametricObject object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * ParametricObject have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the ParametricObject object are:
   * @li "id"
   * @li "polygonType"
   * @li "domainType"
   * @li "pointIndex"
   * @li "pointIndexLength"
   * @li "compression"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument
   */
  virtual void setSBMLDocument(SBMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * used to write arrays
   */
  virtual void write(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this ParametricObject's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this ParametricObject's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ParametricObject.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this
   * ParametricObject.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the array data as a text element
   */
  virtual void setElementText(const std::string& text);

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new ParametricObject_t using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * ParametricObject_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ParametricObject_t.
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this ParametricObject_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
ParametricObject_t *
ParametricObject_create(unsigned int level,
                        unsigned int version,
                        unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this ParametricObject_t object.
 *
 * @param po the ParametricObject_t structure.
 *
 * @return a (deep) copy of this ParametricObject_t object.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
ParametricObject_t*
ParametricObject_clone(const ParametricObject_t* po);


/**
 * Frees this ParametricObject_t object.
 *
 * @param po the ParametricObject_t structure.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
void
ParametricObject_free(ParametricObject_t* po);


/**
 * Returns the value of the "id" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this ParametricObject_t as a
 * pointer to a string.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
const char *
ParametricObject_getId(const ParametricObject_t * po);


/**
 * Returns the value of the "polygonType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure whose polygonType is sought.
 *
 * @return the value of the "polygonType" attribute of this ParametricObject_t
 * as a PolygonKind_t.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
PolygonKind_t
ParametricObject_getPolygonType(const ParametricObject_t * po);


/**
 * Returns the value of the "polygonType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure whose polygonType is sought.
 *
 * @return the value of the "polygonType" attribute of this ParametricObject_t
 * as a const char *.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
const char *
ParametricObject_getPolygonTypeAsString(const ParametricObject_t * po);


/**
 * Returns the value of the "domainType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure whose domainType is sought.
 *
 * @return the value of the "domainType" attribute of this ParametricObject_t
 * as a pointer to a string.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
const char *
ParametricObject_getDomainType(const ParametricObject_t * po);


/**
 * Returns the value of the "pointIndexLength" attribute of this
 * ParametricObject_t.
 *
 * @param po the ParametricObject_t structure whose pointIndexLength is sought.
 *
 * @return the value of the "pointIndexLength" attribute of this
 * ParametricObject_t as a integer.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_getPointIndexLength(const ParametricObject_t * po);


/**
 * Returns the value of the "compression" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure whose compression is sought.
 *
 * @return the value of the "compression" attribute of this ParametricObject_t
 * as a CompressionKind_t.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
CompressionKind_t
ParametricObject_getCompression(const ParametricObject_t * po);


/**
 * Returns the value of the "compression" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure whose compression is sought.
 *
 * @return the value of the "compression" attribute of this ParametricObject_t
 * as a const char *.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
const char *
ParametricObject_getCompressionAsString(const ParametricObject_t * po);


/**
 * Returns the value of the "dataType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure whose dataType is sought.
 *
 * @return the value of the "dataType" attribute of this ParametricObject_t as
 * a DataKind_t.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
DataKind_t
ParametricObject_getDataType(const ParametricObject_t * po);


/**
 * Returns the value of the "dataType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure whose dataType is sought.
 *
 * @return the value of the "dataType" attribute of this ParametricObject_t as
 * a const char *.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
const char *
ParametricObject_getDataTypeAsString(const ParametricObject_t * po);


/**
 * Predicate returning @c 1 if this ParametricObject_t's "id" attribute is set.
 *
 * @param po the ParametricObject_t structure.
 *
 * @return @c 1 if this ParametricObject_t's "id" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_isSetId(const ParametricObject_t * po);


/**
 * Predicate returning @c 1 if this ParametricObject_t's "polygonType"
 * attribute is set.
 *
 * @param po the ParametricObject_t structure.
 *
 * @return @c 1 if this ParametricObject_t's "polygonType" attribute has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_isSetPolygonType(const ParametricObject_t * po);


/**
 * Predicate returning @c 1 if this ParametricObject_t's "domainType" attribute
 * is set.
 *
 * @param po the ParametricObject_t structure.
 *
 * @return @c 1 if this ParametricObject_t's "domainType" attribute has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_isSetDomainType(const ParametricObject_t * po);


/**
 * Predicate returning @c 1 if this ParametricObject_t's "pointIndex" attribute
 * is set.
 *
 * @param po the ParametricObject_t structure.
 *
 * @return @c 1 if this ParametricObject_t's "pointIndex" attribute has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_isSetPointIndex(const ParametricObject_t * po);


/**
 * Predicate returning @c 1 if this ParametricObject_t's "pointIndexLength"
 * attribute is set.
 *
 * @param po the ParametricObject_t structure.
 *
 * @return @c 1 if this ParametricObject_t's "pointIndexLength" attribute has
 * been set, otherwise @c 0 is returned.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_isSetPointIndexLength(const ParametricObject_t * po);


/**
 * Predicate returning @c 1 if this ParametricObject_t's "compression"
 * attribute is set.
 *
 * @param po the ParametricObject_t structure.
 *
 * @return @c 1 if this ParametricObject_t's "compression" attribute has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_isSetCompression(const ParametricObject_t * po);


/**
 * Predicate returning @c 1 if this ParametricObject_t's "dataType" attribute
 * is set.
 *
 * @param po the ParametricObject_t structure.
 *
 * @return @c 1 if this ParametricObject_t's "dataType" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_isSetDataType(const ParametricObject_t * po);


/**
 * Sets the value of the "id" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setId(ParametricObject_t * po, const char * id);


/**
 * Sets the value of the "polygonType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param polygonType PolygonKind_t value of the "polygonType" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setPolygonType(ParametricObject_t * po,
                                PolygonKind_t polygonType);


/**
 * Sets the value of the "polygonType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param polygonType const char * of the "polygonType" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setPolygonTypeAsString(ParametricObject_t * po,
                                        const char * polygonType);


/**
 * Sets the value of the "domainType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param domainType const char * value of the "domainType" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setDomainType(ParametricObject_t * po,
                               const char * domainType);


/**
 * Sets the value of the "pointIndex" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param pointIndex pointer value of the "pointIndex" attribute to be set.
 *
 * @param arrayLength int value for the length of the "pointIndex" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setPointIndex(ParametricObject_t* po,
                               int* pointIndex,
                               int arrayLength);


/**
 * Sets the value of the "pointIndexLength" attribute of this
 * ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param pointIndexLength int value of the "pointIndexLength" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setPointIndexLength(ParametricObject_t * po,
                                     int pointIndexLength);


/**
 * Sets the value of the "compression" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param compression CompressionKind_t value of the "compression" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setCompression(ParametricObject_t * po,
                                CompressionKind_t compression);


/**
 * Sets the value of the "compression" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param compression const char * of the "compression" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setCompressionAsString(ParametricObject_t * po,
                                        const char * compression);


/**
 * Sets the value of the "dataType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param dataType DataKind_t value of the "dataType" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setDataType(ParametricObject_t * po, DataKind_t dataType);


/**
 * Sets the value of the "dataType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @param dataType const char * of the "dataType" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_setDataTypeAsString(ParametricObject_t * po,
                                     const char * dataType);


/**
 * Unsets the value of the "id" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_unsetId(ParametricObject_t * po);


/**
 * Unsets the value of the "polygonType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_unsetPolygonType(ParametricObject_t * po);


/**
 * Unsets the value of the "domainType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_unsetDomainType(ParametricObject_t * po);


/**
 * Unsets the value of the "pointIndex" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_unsetPointIndex(ParametricObject_t * po);


/**
 * Unsets the value of the "pointIndexLength" attribute of this
 * ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_unsetPointIndexLength(ParametricObject_t * po);


/**
 * Unsets the value of the "compression" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_unsetCompression(ParametricObject_t * po);


/**
 * Unsets the value of the "dataType" attribute of this ParametricObject_t.
 *
 * @param po the ParametricObject_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_unsetDataType(ParametricObject_t * po);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * ParametricObject_t object have been set.
 *
 * @param po the ParametricObject_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * ParametricObject_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the ParametricObject_t object are:
 * @li "id"
 * @li "polygonType"
 * @li "domainType"
 * @li "pointIndex"
 * @li "pointIndexLength"
 * @li "compression"
 *
 * @memberof ParametricObject_t
 */
LIBSBML_EXTERN
int
ParametricObject_hasRequiredAttributes(const ParametricObject_t * po);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ParametricObject_H__ */


