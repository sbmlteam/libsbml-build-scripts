/**
 * @file DistribParetoDistribution.h
 * @brief Definition of the DistribParetoDistribution class.
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
 * @class DistribParetoDistribution
 * @sbmlbrief{distrib} TODO:Definition of the DistribParetoDistribution class.
 */


#ifndef DistribParetoDistribution_H__
#define DistribParetoDistribution_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/distrib/sbml/DistribContinuousUnivariateDistribution.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/DistribUncertValue.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN DistribParetoDistribution : public
  DistribContinuousUnivariateDistribution
{
protected:

  /** @cond doxygenLibsbmlInternal */

  DistribUncertValue* mScale;
  DistribUncertValue* mShape;

  /** @endcond */

public:

  /**
   * Creates a new DistribParetoDistribution using the given SBML Level,
   * Version and &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * DistribParetoDistribution.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * DistribParetoDistribution.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this DistribParetoDistribution.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DistribParetoDistribution(
                            unsigned int level =
                              DistribExtension::getDefaultLevel(),
                            unsigned int version =
                              DistribExtension::getDefaultVersion(),
                            unsigned int pkgVersion =
                              DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new DistribParetoDistribution using the given
   * DistribPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DistribParetoDistribution(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for DistribParetoDistribution.
   *
   * @param orig the DistribParetoDistribution instance to copy.
   */
  DistribParetoDistribution(const DistribParetoDistribution& orig);


  /**
   * Assignment operator for DistribParetoDistribution.
   *
   * @param rhs the DistribParetoDistribution object whose values are to be
   * used as the basis of the assignment.
   */
  DistribParetoDistribution& operator=(const DistribParetoDistribution& rhs);


  /**
   * Creates and returns a deep copy of this DistribParetoDistribution object.
   *
   * @return a (deep) copy of this DistribParetoDistribution object.
   */
  virtual DistribParetoDistribution* clone() const;


  /**
   * Destructor for DistribParetoDistribution.
   */
  virtual ~DistribParetoDistribution();


  /**
   * Returns the value of the "id" attribute of this DistribParetoDistribution.
   *
   * @return the value of the "id" attribute of this DistribParetoDistribution
   * as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this
   * DistribParetoDistribution.
   *
   * @return the value of the "name" attribute of this
   * DistribParetoDistribution as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Predicate returning @c true if this DistribParetoDistribution's "id"
   * attribute is set.
   *
   * @return @c true if this DistribParetoDistribution's "id" attribute has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this DistribParetoDistribution's "name"
   * attribute is set.
   *
   * @return @c true if this DistribParetoDistribution's "name" attribute has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Sets the value of the "id" attribute of this DistribParetoDistribution.
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
   * Sets the value of the "name" attribute of this DistribParetoDistribution.
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
   * Unsets the value of the "id" attribute of this DistribParetoDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "name" attribute of this
   * DistribParetoDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetName();


  /**
   * Returns the value of the "scale" element of this
   * DistribParetoDistribution.
   *
   * @return the value of the "scale" element of this DistribParetoDistribution
   * as a DistribUncertValue*.
   */
  const DistribUncertValue* getScale() const;


  /**
   * Returns the value of the "scale" element of this
   * DistribParetoDistribution.
   *
   * @return the value of the "scale" element of this DistribParetoDistribution
   * as a DistribUncertValue*.
   */
  DistribUncertValue* getScale();


  /**
   * Returns the value of the "shape" element of this
   * DistribParetoDistribution.
   *
   * @return the value of the "shape" element of this DistribParetoDistribution
   * as a DistribUncertValue*.
   */
  const DistribUncertValue* getShape() const;


  /**
   * Returns the value of the "shape" element of this
   * DistribParetoDistribution.
   *
   * @return the value of the "shape" element of this DistribParetoDistribution
   * as a DistribUncertValue*.
   */
  DistribUncertValue* getShape();


  /**
   * Predicate returning @c true if this DistribParetoDistribution's "scale"
   * element is set.
   *
   * @return @c true if this DistribParetoDistribution's "scale" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetScale() const;


  /**
   * Predicate returning @c true if this DistribParetoDistribution's "shape"
   * element is set.
   *
   * @return @c true if this DistribParetoDistribution's "shape" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetShape() const;


  /**
   * Sets the value of the "scale" element of this DistribParetoDistribution.
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
   * Sets the value of the "shape" element of this DistribParetoDistribution.
   *
   * @param shape DistribUncertValue* value of the "shape" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setShape(const DistribUncertValue* shape);


  /**
   * Creates a new DistribUncertValue object, adds it to this
   * DistribParetoDistribution object and returns the DistribUncertValue object
   * created.
   *
   * @return a new DistribUncertValue object instance.
   */
  DistribUncertValue* createScale();


  /**
   * Creates a new DistribUncertValue object, adds it to this
   * DistribParetoDistribution object and returns the DistribUncertValue object
   * created.
   *
   * @return a new DistribUncertValue object instance.
   */
  DistribUncertValue* createShape();


  /**
   * Unsets the value of the "scale" element of this DistribParetoDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetScale();


  /**
   * Unsets the value of the "shape" element of this DistribParetoDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetShape();


  /**
   * Returns the XML element name of this DistribParetoDistribution object.
   *
   * For DistribParetoDistribution, the XML element name is always
   * @c "logisticDistribution".
   *
   * @return the name of this element, i.e. @c "logisticDistribution".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this DistribParetoDistribution object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_DISTRIB_PARETODISTRIBUTION, SBMLDistribTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * DistribParetoDistribution object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * DistribParetoDistribution have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * DistribParetoDistribution object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * DistribParetoDistribution have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the DistribParetoDistribution object are:
   * @li "scale"
   * @li "shape"
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
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * Predicate returning @c true if this DistribParetoDistribution's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this DistribParetoDistribution's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * DistribParetoDistribution.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this DistribParetoDistribution.
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
   * DistribParetoDistribution.
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
   * Returns the number of "elementName" in this DistribParetoDistribution.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this DistribParetoDistribution.
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
 * Creates a new DistribParetoDistribution_t using the given SBML Level,
 * Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * DistribParetoDistribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * DistribParetoDistribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this DistribParetoDistribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
DistribParetoDistribution_t *
DistribParetoDistribution_create(unsigned int level,
                                 unsigned int version,
                                 unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this DistribParetoDistribution_t object.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @return a (deep) copy of this DistribParetoDistribution_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
DistribParetoDistribution_t*
DistribParetoDistribution_clone(const DistribParetoDistribution_t* dpd);


/**
 * Frees this DistribParetoDistribution_t object.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
void
DistribParetoDistribution_free(DistribParetoDistribution_t* dpd);


/**
 * Returns the value of the "id" attribute of this DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this DistribParetoDistribution_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
char *
DistribParetoDistribution_getId(const DistribParetoDistribution_t * dpd);


/**
 * Returns the value of the "name" attribute of this
 * DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this
 * DistribParetoDistribution_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
char *
DistribParetoDistribution_getName(const DistribParetoDistribution_t * dpd);


/**
 * Predicate returning @c 1 (true) if this DistribParetoDistribution_t's "id"
 * attribute is set.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribParetoDistribution_t's "id" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_isSetId(const DistribParetoDistribution_t * dpd);


/**
 * Predicate returning @c 1 (true) if this DistribParetoDistribution_t's "name"
 * attribute is set.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribParetoDistribution_t's "name" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_isSetName(const DistribParetoDistribution_t * dpd);


/**
 * Sets the value of the "id" attribute of this DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling DistribParetoDistribution_unsetId().
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_setId(DistribParetoDistribution_t * dpd,
                                const char * id);


/**
 * Sets the value of the "name" attribute of this DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling DistribParetoDistribution_unsetName().
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_setName(DistribParetoDistribution_t * dpd,
                                  const char * name);


/**
 * Unsets the value of the "id" attribute of this DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_unsetId(DistribParetoDistribution_t * dpd);


/**
 * Unsets the value of the "name" attribute of this
 * DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_unsetName(DistribParetoDistribution_t * dpd);


/**
 * Returns the value of the "scale" element of this
 * DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure whose scale is sought.
 *
 * @return the value of the "scale" element of this DistribParetoDistribution_t
 * as a DistribUncertValue*.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
const DistribUncertValue_t*
DistribParetoDistribution_getScale(const DistribParetoDistribution_t * dpd);


/**
 * Returns the value of the "shape" element of this
 * DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure whose shape is sought.
 *
 * @return the value of the "shape" element of this DistribParetoDistribution_t
 * as a DistribUncertValue*.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
const DistribUncertValue_t*
DistribParetoDistribution_getShape(const DistribParetoDistribution_t * dpd);


/**
 * Predicate returning @c 1 (true) if this DistribParetoDistribution_t's
 * "scale" element is set.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribParetoDistribution_t's "scale" element
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_isSetScale(const DistribParetoDistribution_t * dpd);


/**
 * Predicate returning @c 1 (true) if this DistribParetoDistribution_t's
 * "shape" element is set.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @return @c 1 (true) if this DistribParetoDistribution_t's "shape" element
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_isSetShape(const DistribParetoDistribution_t * dpd);


/**
 * Sets the value of the "scale" element of this DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @param scale DistribUncertValue_t* value of the "scale" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_setScale(DistribParetoDistribution_t * dpd,
                                   const DistribUncertValue_t* scale);


/**
 * Sets the value of the "shape" element of this DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @param shape DistribUncertValue_t* value of the "shape" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_setShape(DistribParetoDistribution_t * dpd,
                                   const DistribUncertValue_t* shape);


/**
 * Creates a new DistribUncertValue_t object, adds it to this
 * DistribParetoDistribution_t object and returns the DistribUncertValue_t
 * object created.
 *
 * @param dpd the DistribParetoDistribution_t structure to which the
 * DistribUncertValue_t should be added.
 *
 * @return a new DistribUncertValue_t object instance.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
DistribUncertValue_t*
DistribParetoDistribution_createScale(DistribParetoDistribution_t* dpd);


/**
 * Creates a new DistribUncertValue_t object, adds it to this
 * DistribParetoDistribution_t object and returns the DistribUncertValue_t
 * object created.
 *
 * @param dpd the DistribParetoDistribution_t structure to which the
 * DistribUncertValue_t should be added.
 *
 * @return a new DistribUncertValue_t object instance.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
DistribUncertValue_t*
DistribParetoDistribution_createShape(DistribParetoDistribution_t* dpd);


/**
 * Unsets the value of the "scale" element of this DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_unsetScale(DistribParetoDistribution_t * dpd);


/**
 * Unsets the value of the "shape" element of this DistribParetoDistribution_t.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_unsetShape(DistribParetoDistribution_t * dpd);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * DistribParetoDistribution_t object have been set.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * DistribParetoDistribution_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_hasRequiredAttributes(const
  DistribParetoDistribution_t * dpd);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * DistribParetoDistribution_t object have been set.
 *
 * @param dpd the DistribParetoDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * DistribParetoDistribution_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 *
 * @note The required elements for the DistribParetoDistribution_t object are:
 * @li "scale"
 * @li "shape"
 *
 * @memberof DistribParetoDistribution_t
 */
LIBSBML_EXTERN
int
DistribParetoDistribution_hasRequiredElements(const DistribParetoDistribution_t
  * dpd);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !DistribParetoDistribution_H__ */


