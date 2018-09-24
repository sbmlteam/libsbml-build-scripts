/**
 * @file    XMLLogOverride.h
 * @brief   Utility class implementing a temporary override the severity on error logs. 
 * @author  Frank T. Bergmann
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->
 *
 * @class XMLLogOverride
 * @sbmlbrief{core} Facility for temporarily overriding error severities.
 *
 * @ifnot clike @internal @endif@~
 */

 
#ifndef XMLLogOverride_h
#define XMLLogOverride_h

#ifdef __cplusplus

#include <sbml/xml/XMLExtern.h>
#include <sbml/xml/XMLError.h>

LIBSBML_CPP_NAMESPACE_BEGIN

class LIBSBML_EXTERN XMLLogOverride
{
public: 
	XMLLogOverride(XMLErrorLog* log, XMLErrorSeverityOverride_t new_override);
	virtual ~XMLLogOverride();
	
protected: 
  /** @cond doxygenLibsbmlInternal */
	XMLErrorLog* mLog;
	XMLErrorSeverityOverride_t mOldStatus;
  /** @endcond */
};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */

#endif  /* XMLTokenizer_h */
