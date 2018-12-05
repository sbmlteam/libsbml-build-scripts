###############################################################################
#
# Description       : CMake script for constructing a libSBML python source package
# Original author(s): Frank Bergmann <fbergman@caltech.edu>
# Organization      : California Institute of Technology
#
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright (C) 2013-2015 jointly by the following organizations:
#     1. California Institute of Technology, Pasadena, CA, USA
#     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
#     3. University of Heidelberg, Heidelberg, Germany
#
# Copyright (C) 2009-2013 jointly by the following organizations:
#     1. California Institute of Technology, Pasadena, CA, USA
#     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
#
# Copyright (C) 2006-2008 by the California Institute of Technology,
#     Pasadena, CA, USA
#
# Copyright (C) 2002-2005 jointly by the following organizations:
#     1. California Institute of Technology, Pasadena, CA, USA
#     2. Japan Science and Technology Agency, Japan
#
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
#
###############################################################################

# checking arguments


# collect extra files
file (GLOB DEPENDENCY_FILES
  ${SRC_DIR}/extra/*.c
  ${SRC_DIR}/extra/*.h
  )

# copy files
file(
    COPY ${DEPENDENCY_FILES}
    DESTINATION ${SRC_DIR}/python-libsbml-${LIBSBML_VERSION}/base/
)
# copy files
#file(
    #COPY ${DEPENDENCY_FILES}
    #DESTINATION ${SRC_DIR}/python-libsbml-experimental-${LIBSBML_VERSION}/base/
#)

# collect expat files
file (GLOB EXPAT_FILES
  ${SRC_DIR}/extra/xml/*.cpp
  ${SRC_DIR}/extra/xml/*.h
  )

# copy files
file(
    COPY ${EXPAT_FILES}
    DESTINATION ${SRC_DIR}/python-libsbml-${LIBSBML_VERSION}/base/sbml/xml/
)
# copy files
#file(
    #COPY ${EXPAT_FILES}
    #DESTINATION ${SRC_DIR}/python-libsbml-experimental-${LIBSBML_VERSION}/base/sbml/xml/
#)

# collext libxml files
file (GLOB LIBXML_FILES
  ${SRC_DIR}/python-libsbml-${LIBSBML_VERSION}/base/sbml/xml/LibXML*
#  ${SRC_DIR}/python-libsbml-experimental-${LIBSBML_VERSION}/base/sbml/xml/LibXML*
)

# remove libxml files
list(LENGTH LIBXML_FILES NUM_FILES)
if (${NUM_FILES} GREATER  0)
file(REMOVE ${LIBXML_FILES})
endif()


#configure version in setup.py
configure_file(${SRC_DIR}/extra/stable/setup.py.in
               ${SRC_DIR}/python-libsbml-${LIBSBML_VERSION}/setup.py)
#configure_file(${SRC_DIR}/extra/experimental/setup.py.in
               #${SRC_DIR}/python-libsbml-experimental-${LIBSBML_VERSION}/setup.py)
