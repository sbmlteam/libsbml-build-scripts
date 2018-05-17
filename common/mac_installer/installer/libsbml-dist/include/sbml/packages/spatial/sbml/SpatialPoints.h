/**
 * @file SpatialPoints.h
 * @brief Definition of the SpatialPoints class.
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
 * @class SpatialPoints
 * @sbmlbrief{spatial} TODO:Definition of the SpatialPoints class.
 */


#ifndef SpatialPoints_H__
#define SpatialPoints_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/spatial/common/spatialfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/spatial/extension/SpatialExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN SpatialPoints : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  CompressionKind_t mCompression;
  double* mArrayData;
  int mArrayDataLength;
  bool mIsSetArrayDataLength;
  DataKind_t mDataType;

  /** @endcond */

public:

  /**
   * Creates a new SpatialPoints using the given SBML Level, Version and
   * &ldquo;spatial&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * SpatialPoints.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * SpatialPoints.
   *
   * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
   * this SpatialPoints.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  SpatialPoints(unsigned int level = SpatialExtension::getDefaultLevel(),
                unsigned int version = SpatialExtension::getDefaultVersion(),
                unsigned int pkgVersion =
                  SpatialExtension::getDefaultPackageVersion());


  /**
   * Creates a new SpatialPoints using the given SpatialPkgNamespaces object.
   *
   * @param spatialns the SpatialPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  SpatialPoints(SpatialPkgNamespaces *spatialns);


  /**
   * Copy constructor for SpatialPoints.
   *
   * @param orig the SpatialPoints instance to copy.
   */
  SpatialPoints(const SpatialPoints& orig);


  /**
   * Assignment operator for SpatialPoints.
   *
   * @param rhs the SpatialPoints object whose values are to be used as the
   * basis of the assignment.
   */
  SpatialPoints& operator=(const SpatialPoints& rhs);


  /**
   * Creates and returns a deep copy of this SpatialPoints object.
   *
   * @return a (deep) copy of this SpatialPoints object.
   */
  virtual SpatialPoints* clone() const;


  /**
   * Destructor for SpatialPoints.
   */
  virtual ~SpatialPoints();


  /**
   * Returns the value of the "id" attribute of this SpatialPoints.
   *
   * @return the value of the "id" attribute of this SpatialPoints as a string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "compression" attribute of this SpatialPoints.
   *
   * @return the value of the "compression" attribute of this SpatialPoints as
   * a CompressionKind_t.
   */
  CompressionKind_t getCompression() const;


  /**
   * Returns the value of the "compression" attribute of this SpatialPoints.
   *
   * @return the value of the "compression" attribute of this SpatialPoints as
   * a string.
   */
  const std::string& getCompressionAsString() const;


  /**
   * Returns the value of the "arrayData" attribute of this SpatialPoints.
   *
   * @param outArray double* array that will be used to return the value of the
   * "arrayData" attribute of this SpatialPoints.
   *
   * @note the value of the "arrayData" attribute of this SpatialPoints is
   * returned in the argument array.
   */
  void getArrayData(double* outArray) const;


  /**
   * Returns the value of the "arrayDataLength" attribute of this
   * SpatialPoints.
   *
   * @return the value of the "arrayDataLength" attribute of this SpatialPoints
   * as a integer.
   */
  int getArrayDataLength() const;


  /**
   * Returns the value of the "dataType" attribute of this SpatialPoints.
   *
   * @return the value of the "dataType" attribute of this SpatialPoints as a
   * DataKind_t.
   */
  DataKind_t getDataType() const;


  /**
   * Returns the value of the "dataType" attribute of this SpatialPoints.
   *
   * @return the value of the "dataType" attribute of this SpatialPoints as a
   * string.
   */
  std::string getDataTypeAsString() const;
  //bgoli22

  /**
   * Predicate returning @c true if this SpatialPoints's "id" attribute is set.
   *
   * @return @c true if this SpatialPoints's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true if this SpatialPoints's "compression"
   * attribute is set.
   *
   * @return @c true if this SpatialPoints's "compression" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetCompression() const;


  /**
   * Predicate returning @c true if this SpatialPoints's "arrayData" attribute
   * is set.
   *
   * @return @c true if this SpatialPoints's "arrayData" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetArrayData() const;


  /**
   * Predicate returning @c true if this SpatialPoints's "arrayDataLength"
   * attribute is set.
   *
   * @return @c true if this SpatialPoints's "arrayDataLength" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetArrayDataLength() const;


  /**
   * Predicate returning @c true if this SpatialPoints's "dataType" attribute
   * is set.
   *
   * @return @c true if this SpatialPoints's "dataType" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetDataType() const;


  /**
   * Sets the value of the "id" attribute of this SpatialPoints.
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
   * Sets the value of the "compression" attribute of this SpatialPoints.
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
   * Sets the value of the "compression" attribute of this SpatialPoints.
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
   * Sets the value of the "arrayData" attribute of this SpatialPoints.
   *
   * @param inArray double* array value of the "arrayData" attribute to be set.
   *
   * @param arrayLength int value for the length of the "arrayData" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setArrayData(double* inArray, int arrayLength);


  /**
   * Sets the value of the "arrayDataLength" attribute of this SpatialPoints.
   *
   * @param arrayDataLength int value of the "arrayDataLength" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setArrayDataLength(int arrayDataLength);


  /**
   * Sets the value of the "dataType" attribute of this SpatialPoints.
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
   * Sets the value of the "dataType" attribute of this SpatialPoints.
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
   * Unsets the value of the "id" attribute of this SpatialPoints.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "compression" attribute of this SpatialPoints.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCompression();


  /**
   * Unsets the value of the "arrayData" attribute of this SpatialPoints.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetArrayData();


  /**
   * Unsets the value of the "arrayDataLength" attribute of this SpatialPoints.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetArrayDataLength();


  /**
   * Unsets the value of the "dataType" attribute of this SpatialPoints.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDataType();


  /**
   * Returns the XML element name of this SpatialPoints object.
   *
   * For SpatialPoints, the XML element name is always @c "spatialPoints".
   *
   * @return the name of this element, i.e. @c "spatialPoints".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this SpatialPoints object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_SPATIAL_SPATIALPOINTS, SBMLSpatialTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SpatialPoints object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SpatialPoints have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SpatialPoints object are:
   * @li "id"
   * @li "compression"
   * @li "arrayData"
   * @li "arrayDataLength"
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
   * Gets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Gets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Gets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Gets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Gets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Predicate returning @c true if this SpatialPoints's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SpatialPoints's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Sets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Sets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Sets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Sets the value of the "attributeName" attribute of this SpatialPoints.
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
   * Unsets the value of the "attributeName" attribute of this SpatialPoints.
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
 * Creates a new SpatialPoints_t using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * SpatialPoints_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * SpatialPoints_t.
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this SpatialPoints_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
SpatialPoints_t *
SpatialPoints_create(unsigned int level,
                     unsigned int version,
                     unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this SpatialPoints_t object.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @return a (deep) copy of this SpatialPoints_t object.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
SpatialPoints_t*
SpatialPoints_clone(const SpatialPoints_t* sp);


/**
 * Frees this SpatialPoints_t object.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
void
SpatialPoints_free(SpatialPoints_t* sp);


/**
 * Returns the value of the "id" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SpatialPoints_t as a pointer
 * to a string.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
const char *
SpatialPoints_getId(const SpatialPoints_t * sp);


/**
 * Returns the value of the "compression" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure whose compression is sought.
 *
 * @return the value of the "compression" attribute of this SpatialPoints_t as
 * a CompressionKind_t.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
CompressionKind_t
SpatialPoints_getCompression(const SpatialPoints_t * sp);


/**
 * Returns the value of the "compression" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure whose compression is sought.
 *
 * @return the value of the "compression" attribute of this SpatialPoints_t as
 * a const char *.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
const char *
SpatialPoints_getCompressionAsString(const SpatialPoints_t * sp);


/**
 * Returns the value of the "arrayDataLength" attribute of this
 * SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure whose arrayDataLength is sought.
 *
 * @return the value of the "arrayDataLength" attribute of this SpatialPoints_t
 * as a integer.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_getArrayDataLength(const SpatialPoints_t * sp);


/**
 * Returns the value of the "dataType" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure whose dataType is sought.
 *
 * @return the value of the "dataType" attribute of this SpatialPoints_t as a
 * DataKind_t.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
DataKind_t
SpatialPoints_getDataType(const SpatialPoints_t * sp);


/**
 * Returns the value of the "dataType" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure whose dataType is sought.
 *
 * @return the value of the "dataType" attribute of this SpatialPoints_t as a
 * const char *.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
const char *
SpatialPoints_getDataTypeAsString(const SpatialPoints_t * sp);


/**
 * Predicate returning @c 1 if this SpatialPoints_t's "id" attribute is set.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @return @c 1 if this SpatialPoints_t's "id" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_isSetId(const SpatialPoints_t * sp);


/**
 * Predicate returning @c 1 if this SpatialPoints_t's "compression" attribute
 * is set.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @return @c 1 if this SpatialPoints_t's "compression" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_isSetCompression(const SpatialPoints_t * sp);


/**
 * Predicate returning @c 1 if this SpatialPoints_t's "arrayData" attribute is
 * set.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @return @c 1 if this SpatialPoints_t's "arrayData" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_isSetArrayData(const SpatialPoints_t * sp);


/**
 * Predicate returning @c 1 if this SpatialPoints_t's "arrayDataLength"
 * attribute is set.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @return @c 1 if this SpatialPoints_t's "arrayDataLength" attribute has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_isSetArrayDataLength(const SpatialPoints_t * sp);


/**
 * Predicate returning @c 1 if this SpatialPoints_t's "dataType" attribute is
 * set.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @return @c 1 if this SpatialPoints_t's "dataType" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_isSetDataType(const SpatialPoints_t * sp);


/**
 * Sets the value of the "id" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_setId(SpatialPoints_t * sp, const char * id);


/**
 * Sets the value of the "compression" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @param compression CompressionKind_t value of the "compression" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_setCompression(SpatialPoints_t * sp,
                             CompressionKind_t compression);


/**
 * Sets the value of the "compression" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @param compression const char * of the "compression" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_setCompressionAsString(SpatialPoints_t * sp,
                                     const char * compression);


/**
 * Sets the value of the "arrayData" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @param arrayData pointer value of the "arrayData" attribute to be set.
 *
 * @param arrayLength int value for the length of the "arrayData" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_setArrayData(SpatialPoints_t* sp,
                           double* arrayData,
                           int arrayLength);


/**
 * Sets the value of the "arrayDataLength" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @param arrayDataLength int value of the "arrayDataLength" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_setArrayDataLength(SpatialPoints_t * sp, int arrayDataLength);


/**
 * Sets the value of the "dataType" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @param dataType DataKind_t value of the "dataType" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_setDataType(SpatialPoints_t * sp, DataKind_t dataType);


/**
 * Sets the value of the "dataType" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @param dataType const char * of the "dataType" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_setDataTypeAsString(SpatialPoints_t * sp,
                                  const char * dataType);


/**
 * Unsets the value of the "id" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_unsetId(SpatialPoints_t * sp);


/**
 * Unsets the value of the "compression" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_unsetCompression(SpatialPoints_t * sp);


/**
 * Unsets the value of the "arrayData" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_unsetArrayData(SpatialPoints_t * sp);


/**
 * Unsets the value of the "arrayDataLength" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_unsetArrayDataLength(SpatialPoints_t * sp);


/**
 * Unsets the value of the "dataType" attribute of this SpatialPoints_t.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_unsetDataType(SpatialPoints_t * sp);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * SpatialPoints_t object have been set.
 *
 * @param sp the SpatialPoints_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * SpatialPoints_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the SpatialPoints_t object are:
 * @li "id"
 * @li "compression"
 * @li "arrayData"
 * @li "arrayDataLength"
 *
 * @memberof SpatialPoints_t
 */
LIBSBML_EXTERN
int
SpatialPoints_hasRequiredAttributes(const SpatialPoints_t * sp);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SpatialPoints_H__ */


