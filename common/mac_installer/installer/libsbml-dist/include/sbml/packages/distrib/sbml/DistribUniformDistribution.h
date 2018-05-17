/**
 * @file DistribUniformDistribution.h
 * @brief Definition of the DistribUniformDistribution class.
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
 * @class DistribUniformDistribution
 * @sbmlbrief{distrib} TODO:Definition of the DistribUniformDistribution class.
 */


#ifndef DistribUniformDistribution_H__
#define DistribUniformDistribution_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/distrib/sbml/DistribContinuousUnivariateDistribution.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/DistribUncertValue.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN DistribUniformDistribution : public
  DistribContinuousUnivariateDistribution
{
protected:

  /** @cond doxygenLibsbmlInternal */

  DistribUncertValue* mMinimum;
  DistribUncertValue* mMaximum;
  DistribUncertValue* mNumberOfClasses;

  /** @endcond */

public:

  /**
   * Creates a new DistribUniformDistribution using the given SBML Level,
   * Version and &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * DistribUniformDistribution.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * DistribUniformDistribution.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this DistribUniformDistribution.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DistribUniformDistribution(
                             unsigned int level =
                               DistribExtension::getDefaultLevel(),
                             unsigned int version =
                               DistribExtension::getDefaultVersion(),
                             unsigned int pkgVersion =
                               DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new DistribUniformDistribution using the given
   * DistribPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DistribUniformDistribution(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for DistribUniformDistribution.
   *
   * @param orig the DistribUniformDistribution instance to copy.
   */
  DistribUniformDistribution(const DistribUniformDistribution& orig);


  /**
   * Assignment operator for DistribUniformDistribution.
   *
   * @param rhs the DistribUniformDistribution object whose values are to be
   * used as the basis of the assignment.
   */
  DistribUniformDistribution& operator=(const DistribUniformDistribution& rhs);


  /**
   * Creates and returns a deep copy of this DistribUniformDistribution object.
   *
   * @return a (deep) copy of this DistribUniformDistribution object.
   */
  virtual DistribUniformDistribution* clone() const;


  /**
   * Destructor for DistribUniformDistribution.
   */
  virtual ~DistribUniformDistribution();


  /**
   * Returns the value of the "id" attribute of this
   * DistribUniformDistribution.
   *
   * @return the value of the "id" attribute of this DistribUniformDistribution
   * as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this
   * DistribUniformDistribution.
   *
   * @return the value of the "name" attribute of this
   * DistribUniformDistribution as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Predicate returning @c true if this DistribUniformDistribution's "id"
   * attribute is set.
   *
   * @return @c true if this DistribUniformDistribution's "id" attribute has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this DistribUniformDistribution's "name"
   * attribute is set.
   *
   * @return @c true if this DistribUniformDistribution's "name" attribute has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Sets the value of the "id" attribute of this DistribUniformDistribution.
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
   * Sets the value of the "name" attribute of this DistribUniformDistribution.
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
   * Unsets the value of the "id" attribute of this DistribUniformDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "name" attribute of this
   * DistribUniformDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetName();


  /**
   * Returns the value of the "minimum" element of this
   * DistribUniformDistribution.
   *
   * @return the value of the "minimum" element of this
   * DistribUniformDistribution as a DistribUncertValue*.
   */
  const DistribUncertValue* getMinimum() const;


  /**
   * Returns the value of the "minimum" element of this
   * DistribUniformDistribution.
   *
   * @return the value of the "minimum" element of this
   * DistribUniformDistribution as a DistribUncertValue*.
   */
  DistribUncertValue* getMinimum();


  /**
   * Returns the value of the "maximum" element of this
   * DistribUniformDistribution.
   *
   * @return the value of the "maximum" element of this
   * DistribUniformDistribution as a DistribUncertValue*.
   */
  const DistribUncertValue* getMaximum() const;


  /**
   * Returns the value of the "maximum" element of this
   * DistribUniformDistribution.
   *
   * @return the value of the "maximum" element of this
   * DistribUniformDistribution as a DistribUncertValue*.
   */
  DistribUncertValue* getMaximum();


  /**
   * Returns the value of the "numberOfClasses" element of this
   * DistribUniformDistribution.
   *
   * @return the value of the "numberOfClasses" element of this
   * DistribUniformDistribution as a DistribUncertValue*.
   */
  const DistribUncertValue* getNumberOfClasses() const;


  /**
   * Returns the value of the "numberOfClasses" element of this
   * DistribUniformDistribution.
   *
   * @return the value of the "numberOfClasses" element of this
   * DistribUniformDistribution as a DistribUncertValue*.
   */
  DistribUncertValue* getNumberOfClasses();


  /**
   * Predicate returning @c true if this DistribUniformDistribution's "minimum"
   * element is set.
   *
   * @return @c true if this DistribUniformDistribution's "minimum" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetMinimum() const;


  /**
   * Predicate returning @c true if this DistribUniformDistribution's "maximum"
   * element is set.
   *
   * @return @c true if this DistribUniformDistribution's "maximum" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetMaximum() const;


  /**
   * Predicate returning @c true if this DistribUniformDistribution's
   * "numberOfClasses" element is set.
   *
   * @return @c true if this DistribUniformDistribution's "numberOfClasses"
   * element has been set, otherwise @c false is returned.
   */
  bool isSetNumberOfClasses() const;


  /**
   * Sets the value of the "minimum" element of this
   * DistribUniformDistribution.
   *
   * @param minimum DistribUncertValue* value of the "minimum" element to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMinimum(const DistribUncertValue* minimum);


  /**
   * Sets the value of the "maximum" element of this
   * DistribUniformDistribution.
   *
   * @param maximum DistribUncertValue* value of the "maximum" element to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMaximum(const DistribUncertValue* maximum);


  /**
   * Sets the value of the "numberOfClasses" element of this
   * DistribUniformDistribution.
   *
   * @param numberOfClasses DistribUncertValue* value of the "numberOfClasses"
   * element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNumberOfClasses(const DistribUncertValue* numberOfClasses);


  /**
   * Creates a new DistribUncertValue object, adds it to this
   * DistribUniformDistribution object and returns the DistribUncertValue
   * object created.
   *
   * @return a new DistribUncertValue object instance.
   */
  DistribUncertValue* createMinimum();


  /**
   * Creates a new DistribUncertValue object, adds it to this
   * DistribUniformDistribution object and returns the DistribUncertValue
   * object created.
   *
   * @return a new DistribUncertValue object instance.
   */
  DistribUncertValue* createMaximum();


  /**
   * Creates a new DistribUncertValue object, adds it to this
   * DistribUniformDistribution object and returns the DistribUncertValue
   * object created.
   *
   * @return a new DistribUncertValue object instance.
   */
  DistribUncertValue* createNumberOfClasses();


  /**
   * Unsets the value of the "minimum" element of this
   * DistribUniformDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMinimum();


  /**
   * Unsets the value of the "maximum" element of this
   * DistribUniformDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMaximum();


  /**
   * Unsets the value of the "numberOfClasses" element of this
   * DistribUniformDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumberOfClasses();


  /**
   * Returns the XML element name of this DistribUniformDistribution object.
   *
   * For DistribUniformDistribution, the XML element name is always
   * @c "uniformDistribution".
   *
   * @return the name of this element, i.e. @c "uniformDistribution".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this DistribUniformDistribution object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_DISTRIB_UNIFORMDISTRIBUTION, SBMLDistribTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * DistribUniformDistribution object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * DistribUniformDistribution have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * DistribUniformDistribution object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * DistribUniformDistribution have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the DistribUniformDistribution object are:
   * @li "minimum"
   * @li "maximum"
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
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * Predicate returning @c true if this DistribUniformDistribution's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this DistribUniformDistribution's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * DistribUniformDistribution.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this DistribUniformDistribution.
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
   * DistribUniformDistribution.
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
   * Returns the number of "elementName" in this DistribUniformDistribution.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this DistribUniformDistribution.
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
 * Creates a new DistribUniformDistribution_t using the given SBML Level,
 * Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * DistribUniformDistribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * DistribUniformDistribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this DistribUniformDistribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
DistribUniformDistribution_t *
DistribUniformDistribution_create(unsigned int level,
                                  unsigned int version,
                                  unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this DistribUniformDistribution_t object.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @return a (deep) copy of this DistribUniformDistribution_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
DistribUniformDistribution_t*
DistribUniformDistribution_clone(const DistribUniformDistribution_t* dud);


/**
 * Frees this DistribUniformDistribution_t object.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
void
DistribUniformDistribution_free(DistribUniformDistribution_t* dud);


/**
 * Returns the value of the "id" attribute of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this DistribUniformDistribution_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
char *
DistribUniformDistribution_getId(const DistribUniformDistribution_t * dud);


/**
 * Returns the value of the "name" attribute of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this
 * DistribUniformDistribution_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
char *
DistribUniformDistribution_getName(const DistribUniformDistribution_t * dud);


/**
 * Predicate returning @c 1 (true) if this DistribUniformDistribution_t's "id"
 * attribute is set.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribUniformDistribution_t's "id" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_isSetId(const DistribUniformDistribution_t * dud);


/**
 * Predicate returning @c 1 (true) if this DistribUniformDistribution_t's
 * "name" attribute is set.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribUniformDistribution_t's "name" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_isSetName(const DistribUniformDistribution_t * dud);


/**
 * Sets the value of the "id" attribute of this DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling DistribUniformDistribution_unsetId().
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_setId(DistribUniformDistribution_t * dud,
                                 const char * id);


/**
 * Sets the value of the "name" attribute of this DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling DistribUniformDistribution_unsetName().
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_setName(DistribUniformDistribution_t * dud,
                                   const char * name);


/**
 * Unsets the value of the "id" attribute of this DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_unsetId(DistribUniformDistribution_t * dud);


/**
 * Unsets the value of the "name" attribute of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_unsetName(DistribUniformDistribution_t * dud);


/**
 * Returns the value of the "minimum" element of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure whose minimum is
 * sought.
 *
 * @return the value of the "minimum" element of this
 * DistribUniformDistribution_t as a DistribUncertValue*.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
const DistribUncertValue_t*
DistribUniformDistribution_getMinimum(const DistribUniformDistribution_t *
  dud);


/**
 * Returns the value of the "maximum" element of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure whose maximum is
 * sought.
 *
 * @return the value of the "maximum" element of this
 * DistribUniformDistribution_t as a DistribUncertValue*.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
const DistribUncertValue_t*
DistribUniformDistribution_getMaximum(const DistribUniformDistribution_t *
  dud);


/**
 * Returns the value of the "numberOfClasses" element of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure whose numberOfClasses
 * is sought.
 *
 * @return the value of the "numberOfClasses" element of this
 * DistribUniformDistribution_t as a DistribUncertValue*.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
const DistribUncertValue_t*
DistribUniformDistribution_getNumberOfClasses(const
  DistribUniformDistribution_t * dud);


/**
 * Predicate returning @c 1 (true) if this DistribUniformDistribution_t's
 * "minimum" element is set.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribUniformDistribution_t's "minimum" element
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_isSetMinimum(const DistribUniformDistribution_t *
  dud);


/**
 * Predicate returning @c 1 (true) if this DistribUniformDistribution_t's
 * "maximum" element is set.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribUniformDistribution_t's "maximum" element
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_isSetMaximum(const DistribUniformDistribution_t *
  dud);


/**
 * Predicate returning @c 1 (true) if this DistribUniformDistribution_t's
 * "numberOfClasses" element is set.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribUniformDistribution_t's "numberOfClasses"
 * element has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_isSetNumberOfClasses(const
  DistribUniformDistribution_t * dud);


/**
 * Sets the value of the "minimum" element of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @param minimum DistribUncertValue_t* value of the "minimum" element to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_setMinimum(DistribUniformDistribution_t * dud,
                                      const DistribUncertValue_t* minimum);


/**
 * Sets the value of the "maximum" element of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @param maximum DistribUncertValue_t* value of the "maximum" element to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_setMaximum(DistribUniformDistribution_t * dud,
                                      const DistribUncertValue_t* maximum);


/**
 * Sets the value of the "numberOfClasses" element of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @param numberOfClasses DistribUncertValue_t* value of the "numberOfClasses"
 * element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_setNumberOfClasses(
                                              DistribUniformDistribution_t *
                                                dud,
                                              const DistribUncertValue_t*
                                                numberOfClasses);


/**
 * Creates a new DistribUncertValue_t object, adds it to this
 * DistribUniformDistribution_t object and returns the DistribUncertValue_t
 * object created.
 *
 * @param dud the DistribUniformDistribution_t structure to which the
 * DistribUncertValue_t should be added.
 *
 * @return a new DistribUncertValue_t object instance.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
DistribUncertValue_t*
DistribUniformDistribution_createMinimum(DistribUniformDistribution_t* dud);


/**
 * Creates a new DistribUncertValue_t object, adds it to this
 * DistribUniformDistribution_t object and returns the DistribUncertValue_t
 * object created.
 *
 * @param dud the DistribUniformDistribution_t structure to which the
 * DistribUncertValue_t should be added.
 *
 * @return a new DistribUncertValue_t object instance.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
DistribUncertValue_t*
DistribUniformDistribution_createMaximum(DistribUniformDistribution_t* dud);


/**
 * Creates a new DistribUncertValue_t object, adds it to this
 * DistribUniformDistribution_t object and returns the DistribUncertValue_t
 * object created.
 *
 * @param dud the DistribUniformDistribution_t structure to which the
 * DistribUncertValue_t should be added.
 *
 * @return a new DistribUncertValue_t object instance.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
DistribUncertValue_t*
DistribUniformDistribution_createNumberOfClasses(DistribUniformDistribution_t*
  dud);


/**
 * Unsets the value of the "minimum" element of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_unsetMinimum(DistribUniformDistribution_t * dud);


/**
 * Unsets the value of the "maximum" element of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_unsetMaximum(DistribUniformDistribution_t * dud);


/**
 * Unsets the value of the "numberOfClasses" element of this
 * DistribUniformDistribution_t.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_unsetNumberOfClasses(DistribUniformDistribution_t *
  dud);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * DistribUniformDistribution_t object have been set.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * DistribUniformDistribution_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_hasRequiredAttributes(const
  DistribUniformDistribution_t * dud);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * DistribUniformDistribution_t object have been set.
 *
 * @param dud the DistribUniformDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * DistribUniformDistribution_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 *
 * @note The required elements for the DistribUniformDistribution_t object are:
 * @li "minimum"
 * @li "maximum"
 *
 * @memberof DistribUniformDistribution_t
 */
LIBSBML_EXTERN
int
DistribUniformDistribution_hasRequiredElements(const
  DistribUniformDistribution_t * dud);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !DistribUniformDistribution_H__ */


