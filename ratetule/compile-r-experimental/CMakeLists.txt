###############################################################################
#
# Description       : CMake build script for libSBML R bindings
# Original author(s): Frank Bergmann <fbergman@caltech.edu>
# Organization      : California Institute of Technology
#
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright (C) 2013-2014 jointly by the following organizations:
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

cmake_minimum_required(VERSION 2.6)
project(libsbml)

SET(R_INCLUDE_DIRS)
SET(R_LIB)
SET(R_INTERPRETER)
SET(R_ADDITIONAL_PATH_ENTRIES "" CACHE STRING "Additional paths to the RTOOLS / GCC binary directories to build package")

# message(
# "
#              R_INCLUDE_DIRS = ${R_INCLUDE_DIRS}
#                       R_LIB = ${R_LIB}
#               R_INTERPRETER = ${R_INTERPRETER}
#   R_ADDITIONAL_PATH_ENTRIES = ${R_ADDITIONAL_PATH_ENTRIES}
# 
# ")

# if we have not found something, stop here to ask for it
if (NOT R_INTERPRETER)
	message(FATAL_ERROR "Need the R interpreter in order to create an R package") 
endif()
if (NOT R_LIB)
	message(FATAL_ERROR "Need the R library, please specify R_LIB")
endif()
if (NOT R_INCLUDE_DIRS)
	message(FATAL_ERROR "Need the R include directory, please specify R_INCLUDE_DIRS")
endif()



####################################################################
#
# Build native library
#

if(MSVC OR USING_INTEL)
        add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_CRT_NONSTDC_NO_DEPRECATE)
        set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -D_CRT_SECURE_NO_WARNINGS")
        option(WITH_STATIC_RUNTIME "Compile using the static MSVC Runtime." ON)
        if(WITH_STATIC_RUNTIME)
            foreach(flag_var
                CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
                CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
                CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)

                if(${flag_var} MATCHES "/MD")
                    string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
                endif(${flag_var} MATCHES "/MD")
								
            endforeach(flag_var)
        add_definitions( -D_MT)
        endif(WITH_STATIC_RUNTIME)
endif()

if(WIN32)
	add_definitions(-DNT=1 -DIMPORT -DLIBSBML_STATIC=1 -DLIBLAX_STATIC=1)
endif()

if (EXTRA_DEFS)
 foreach (item ${EXTRA_DEFS})
   add_definitions(-D${item}=1)
 endforeach()
endif()
include_directories(${LIBSBML_ROOT_SOURCE_DIR}/src/bindings/r)
include_directories(${LIBSBML_ROOT_SOURCE_DIR}/src/bindings/swig)
include_directories(${LIBSBML_ROOT_SOURCE_DIR}/src)
include_directories(${R_INCLUDE_DIRS})
include_directories(BEFORE ${LIBSBML_ROOT_BINARY_DIR}/src)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/..)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})

if (EXTRA_INCLUDE_DIRS) 
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

if (MSVC)
  # the build fails when compiled with packages as the object file is too 
  # big adding the big flag makes it work!
  add_definitions(/bigobj)
endif(MSVC)

add_library(binding_r_lib SHARED ${CMAKE_CURRENT_BINARY_DIR}/../libsbml_wrap.cpp)



set_target_properties (binding_r_lib PROPERTIES OUTPUT_NAME "libSBML")
if (UNIX)
	set_target_properties (binding_r_lib PROPERTIES PREFIX "")
	if (APPLE)
		set_target_properties (binding_r_lib PROPERTIES SUFFIX ".so")
    if( "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" AND CLANG_USE_STDLIB )
      set_target_properties (binding_r_lib PROPERTIES COMPILE_FLAGS " -std=c++0x -stdlib=libstdc++")
    endif()
	endif()
endif()


SET(EXTRA_LIBS "WS2_32.lib")
if (DEP_DIR)

SET (EXTRA_LIBS ${EXTRA_LIBS} ${DEP_DIR}/libbz2.lib)
SET (EXTRA_LIBS ${EXTRA_LIBS} ${DEP_DIR}/expat.lib)
SET (EXTRA_LIBS ${EXTRA_LIBS} ${DEP_DIR}/libiconv.lib)
SET (EXTRA_LIBS ${EXTRA_LIBS} ${DEP_DIR}/libxml2.lib)
SET (EXTRA_LIBS ${EXTRA_LIBS} ${DEP_DIR}/zdll.lib)

endif()

target_link_libraries(binding_r_lib ${LIBSBML_LIB} ${R_LIB} ${EXTRA_LIBS})

####################################################################
#
# create the r package
#

MACRO (TODAY RESULT) 
    IF (WIN32) 
        EXECUTE_PROCESS(COMMAND "cmd" " /C date /T" OUTPUT_VARIABLE ${RESULT} OUTPUT_STRIP_TRAILING_WHITESPACE) 
        string(REGEX REPLACE "(..)/(..)/..(..).*" "\\1/\\2/\\3" ${RESULT} ${${RESULT}}) 
    ELSEIF(UNIX) 
        EXECUTE_PROCESS(COMMAND "date" "+%Y-%m-%d" OUTPUT_VARIABLE ${RESULT} OUTPUT_STRIP_TRAILING_WHITESPACE) 
        string(REGEX REPLACE "(..)/(..)/..(..).*" "\\1/\\2/\\3" ${RESULT} ${${RESULT}}) 
    ELSE (WIN32) 
        MESSAGE(SEND_ERROR "date not implemented") 
        SET(${RESULT} 000000) 
    ENDIF (WIN32) 
ENDMACRO (TODAY) 

TODAY(CURRENT_DATE) 

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/../libSBML")

set(R_LIBRARY_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/../libSBML/inst/libs")

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../libSBML/R)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../temp)
configure_file (
  "${LIBSBML_ROOT_SOURCE_DIR}/src/bindings/r/DESCRIPTION.in"
  "${CMAKE_CURRENT_BINARY_DIR}/../libSBML/DESCRIPTION"
  )
configure_file (
  "${LIBSBML_ROOT_SOURCE_DIR}/src/bindings/r/NAMESPACE"
  "${CMAKE_CURRENT_BINARY_DIR}/../libSBML/NAMESPACE"
)


