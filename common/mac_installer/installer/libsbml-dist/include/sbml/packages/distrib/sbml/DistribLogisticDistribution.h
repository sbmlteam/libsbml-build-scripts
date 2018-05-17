/**
 * @file DistribLogisticDistribution.h
 * @brief Definition of the DistribLogisticDistribution class.
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
 * @class DistribLogisticDistribution
 * @sbmlbrief{distrib} TODO:Definition of the DistribLogisticDistribution
 * class.
 */


#ifndef DistribLogisticDistribution_H__
#define DistribLogisticDistribution_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/distrib/sbml/DistribContinuousUnivariateDistribution.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/DistribUncertValue.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN DistribLogisticDistribution : public
  DistribContinuousUnivariateDistribution
{
protected:

  /** @cond doxygenLibsbmlInternal */

  DistribUncertValue* mLocation;
  DistribUncertValue* mScale;

  /** @endcond */

public:

  /**
   * Creates a new DistribLogisticDistribution using the given SBML Level,
   * Version and &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * DistribLogisticDistribution.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * DistribLogisticDistribution.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this DistribLogisticDistribution.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DistribLogisticDistribution(
                              unsigned int level =
                                DistribExtension::getDefaultLevel(),
                              unsigned int version =
                                DistribExtension::getDefaultVersion(),
                              unsigned int pkgVersion =
                                DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new DistribLogisticDistribution using the given
   * DistribPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DistribLogisticDistribution(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for DistribLogisticDistribution.
   *
   * @param orig the DistribLogisticDistribution instance to copy.
   */
  DistribLogisticDistribution(const DistribLogisticDistribution& orig);


  /**
   * Assignment operator for DistribLogisticDistribution.
   *
   * @param rhs the DistribLogisticDistribution object whose values are to be
   * used as the basis of the assignment.
   */
  DistribLogisticDistribution& operator=(const DistribLogisticDistribution&
    rhs);


  /**
   * Creates and returns a deep copy of this DistribLogisticDistribution
   * object.
   *
   * @return a (deep) copy of this DistribLogisticDistribution object.
   */
  virtual DistribLogisticDistribution* clone() const;


  /**
   * Destructor for DistribLogisticDistribution.
   */
  virtual ~DistribLogisticDistribution();


  /**
   * Returns the value of the "id" attribute of this
   * DistribLogisticDistribution.
   *
   * @return the value of the "id" attribute of this
   * DistribLogisticDistribution as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this
   * DistribLogisticDistribution.
   *
   * @return the value of the "name" attribute of this
   * DistribLogisticDistribution as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Predicate returning @c true if this DistribLogisticDistribution's "id"
   * attribute is set.
   *
   * @return @c true if this DistribLogisticDistribution's "id" attribute has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this DistribLogisticDistribution's "name"
   * attribute is set.
   *
   * @return @c true if this DistribLogisticDistribution's "name" attribute has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Sets the value of the "id" attribute of this DistribLogisticDistribution.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * Calling this function with @p id = @c NULL or an empty string is
   * equivalent to calling unsetId().
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "name" attribute of this
   * DistribLogisticDistribution.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p name = @c NULL or an empty string is
   * equivalent to calling unsetName().
   */
  virtual int setName(const std::string& name);


  /**
   * Unsets the value of the "id" attribute of this
   * DistribLogisticDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "name" attribute of this
   * DistribLogisticDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetName();


  /**
   * Returns the value of the "location" element of this
   * DistribLogisticDistribution.
   *
   * @return the value of the "location" element of this
   * DistribLogisticDistribution as a DistribUncertValue*.
   */
  const DistribUncertValue* getLocation() const;


  /**
   * Returns the value of the "location" element of this
   * DistribLogisticDistribution.
   *
   * @return the value of the "location" element of this
   * DistribLogisticDistribution as a DistribUncertValue*.
   */
  DistribUncertValue* getLocation();


  /**
   * Returns the value of the "scale" element of this
   * DistribLogisticDistribution.
   *
   * @return the value of the "scale" element of this
   * DistribLogisticDistribution as a DistribUncertValue*.
   */
  const DistribUncertValue* getScale() const;


  /**
   * Returns the value of the "scale" element of this
   * DistribLogisticDistribution.
   *
   * @return the value of the "scale" element of this
   * DistribLogisticDistribution as a DistribUncertValue*.
   */
  DistribUncertValue* getScale();


  /**
   * Predicate returning @c true if this DistribLogisticDistribution's
   * "location" element is set.
   *
   * @return @c true if this DistribLogisticDistribution's "location" element
   * has been set, otherwise @c false is returned.
   */
  bool isSetLocation() const;


  /**
   * Predicate returning @c true if this DistribLogisticDistribution's "scale"
   * element is set.
   *
   * @return @c true if this DistribLogisticDistribution's "scale" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetScale() const;


  /**
   * Sets the value of the "location" element of this
   * DistribLogisticDistribution.
   *
   * @param location DistribUncertValue* value of the "location" element to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLocation(const DistribUncertValue* location);


  /**
   * Sets the value of the "scale" element of this DistribLogisticDistribution.
   *
   * @param scale DistribUncertValue* value of the "scale" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setScale(const DistribUncertValue* scale);


  /**
   * Creates a new DistribUncertValue object, adds it to this
   * DistribLogisticDistribution object and returns the DistribUncertValue
   * object created.
   *
   * @return a new DistribUncertValue object instance.
   */
  DistribUncertValue* createLocation();


  /**
   * Creates a new DistribUncertValue object, adds it to this
   * DistribLogisticDistribution object and returns the DistribUncertValue
   * object created.
   *
   * @return a new DistribUncertValue object instance.
   */
  DistribUncertValue* createScale();


  /**
   * Unsets the value of the "location" element of this
   * DistribLogisticDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLocation();


  /**
   * Unsets the value of the "scale" element of this
   * DistribLogisticDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetScale();


  /**
   * Returns the XML element name of this DistribLogisticDistribution object.
   *
   * For DistribLogisticDistribution, the XML element name is always
   * @c "logisticDistribution".
   *
   * @return the name of this element, i.e. @c "logisticDistribution".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this DistribLogisticDistribution object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_DISTRIB_LOGISTICDISTRIBUTION, SBMLDistribTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * DistribLogisticDistribution object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * DistribLogisticDistribution have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * DistribLogisticDistribution object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * DistribLogisticDistribution have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the DistribLogisticDistribution object
   * are:
   * @li "location"
   * @li "scale"
   */
  virtual bool hasRequiredElements() const;



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
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Updates the namespaces when setLevelVersion is used
   */
  virtual void updateSBMLNamespace(const std::string& package,
                                   unsigned int level,
                                   unsigned int version);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * Gets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * Gets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * Gets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * Gets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * Predicate returning @c true if this DistribLogisticDistribution's
   * attribute "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this DistribLogisticDistribution's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * Sets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * Sets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * Sets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * Sets the value of the "attributeName" attribute of this
   * DistribLogisticDistribution.
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
   * DistribLogisticDistribution.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates and returns an new "elementName" object in this
   * DistribLogisticDistribution.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this DistribLogisticDistribution.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SBase* element);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * DistribLogisticDistribution.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SBase* removeChildObject(const std::string& elementName,
                                   const std::string& id);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the number of "elementName" in this DistribLogisticDistribution.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this
   * DistribLogisticDistribution.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SBase* getObject(const std::string& elementName, unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid. If no
   * such object is found this method returns @c NULL.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List* pointer of pointers to all SBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(ElementFilter * filter = NULL);


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



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
   * Reads the expected attributes into the member data variables
   */
  virtual void readL3V1V1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readL3V2V1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeL3V1V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeL3V2V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new DistribLogisticDistribution_t using the given SBML Level,
 * Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * DistribLogisticDistribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * DistribLogisticDistribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this DistribLogisticDistribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
DistribLogisticDistribution_t *
DistribLogisticDistribution_create(unsigned int level,
                                   unsigned int version,
                                   unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this DistribLogisticDistribution_t
 * object.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @return a (deep) copy of this DistribLogisticDistribution_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
DistribLogisticDistribution_t*
DistribLogisticDistribution_clone(const DistribLogisticDistribution_t* dld);


/**
 * Frees this DistribLogisticDistribution_t object.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
void
DistribLogisticDistribution_free(DistribLogisticDistribution_t* dld);


/**
 * Returns the value of the "id" attribute of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this
 * DistribLogisticDistribution_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
char *
DistribLogisticDistribution_getId(const DistribLogisticDistribution_t * dld);


/**
 * Returns the value of the "name" attribute of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this
 * DistribLogisticDistribution_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
char *
DistribLogisticDistribution_getName(const DistribLogisticDistribution_t * dld);


/**
 * Predicate returning @c 1 (true) if this DistribLogisticDistribution_t's "id"
 * attribute is set.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribLogisticDistribution_t's "id" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_isSetId(const DistribLogisticDistribution_t * dld);


/**
 * Predicate returning @c 1 (true) if this DistribLogisticDistribution_t's
 * "name" attribute is set.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribLogisticDistribution_t's "name" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_isSetName(const DistribLogisticDistribution_t *
  dld);


/**
 * Sets the value of the "id" attribute of this DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling DistribLogisticDistribution_unsetId().
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_setId(DistribLogisticDistribution_t * dld,
                                  const char * id);


/**
 * Sets the value of the "name" attribute of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling DistribLogisticDistribution_unsetName().
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_setName(DistribLogisticDistribution_t * dld,
                                    const char * name);


/**
 * Unsets the value of the "id" attribute of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_unsetId(DistribLogisticDistribution_t * dld);


/**
 * Unsets the value of the "name" attribute of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_unsetName(DistribLogisticDistribution_t * dld);


/**
 * Returns the value of the "location" element of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure whose location is
 * sought.
 *
 * @return the value of the "location" element of this
 * DistribLogisticDistribution_t as a DistribUncertValue*.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
const DistribUncertValue_t*
DistribLogisticDistribution_getLocation(const DistribLogisticDistribution_t *
  dld);


/**
 * Returns the value of the "scale" element of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure whose scale is
 * sought.
 *
 * @return the value of the "scale" element of this
 * DistribLogisticDistribution_t as a DistribUncertValue*.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
const DistribUncertValue_t*
DistribLogisticDistribution_getScale(const DistribLogisticDistribution_t *
  dld);


/**
 * Predicate returning @c 1 (true) if this DistribLogisticDistribution_t's
 * "location" element is set.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribLogisticDistribution_t's "location"
 * element has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_isSetLocation(const DistribLogisticDistribution_t *
  dld);


/**
 * Predicate returning @c 1 (true) if this DistribLogisticDistribution_t's
 * "scale" element is set.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribLogisticDistribution_t's "scale" element
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_isSetScale(const DistribLogisticDistribution_t *
  dld);


/**
 * Sets the value of the "location" element of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @param location DistribUncertValue_t* value of the "location" element to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_setLocation(DistribLogisticDistribution_t * dld,
                                        const DistribUncertValue_t* location);


/**
 * Sets the value of the "scale" element of this DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @param scale DistribUncertValue_t* value of the "scale" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_setScale(DistribLogisticDistribution_t * dld,
                                     const DistribUncertValue_t* scale);


/**
 * Creates a new DistribUncertValue_t object, adds it to this
 * DistribLogisticDistribution_t object and returns the DistribUncertValue_t
 * object created.
 *
 * @param dld the DistribLogisticDistribution_t structure to which the
 * DistribUncertValue_t should be added.
 *
 * @return a new DistribUncertValue_t object instance.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
DistribUncertValue_t*
DistribLogisticDistribution_createLocation(DistribLogisticDistribution_t* dld);


/**
 * Creates a new DistribUncertValue_t object, adds it to this
 * DistribLogisticDistribution_t object and returns the DistribUncertValue_t
 * object created.
 *
 * @param dld the DistribLogisticDistribution_t structure to which the
 * DistribUncertValue_t should be added.
 *
 * @return a new DistribUncertValue_t object instance.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
DistribUncertValue_t*
DistribLogisticDistribution_createScale(DistribLogisticDistribution_t* dld);


/**
 * Unsets the value of the "location" element of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_unsetLocation(DistribLogisticDistribution_t * dld);


/**
 * Unsets the value of the "scale" element of this
 * DistribLogisticDistribution_t.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_unsetScale(DistribLogisticDistribution_t * dld);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * DistribLogisticDistribution_t object have been set.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * DistribLogisticDistribution_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_hasRequiredAttributes(const
  DistribLogisticDistribution_t * dld);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * DistribLogisticDistribution_t object have been set.
 *
 * @param dld the DistribLogisticDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * DistribLogisticDistribution_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 *
 * @note The required elements for the DistribLogisticDistribution_t object
 * are:
 * @li "location"
 * @li "scale"
 *
 * @memberof DistribLogisticDistribution_t
 */
LIBSBML_EXTERN
int
DistribLogisticDistribution_hasRequiredElements(const
  DistribLogisticDistribution_t * dld);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !DistribLogisticDistribution_H__ */


