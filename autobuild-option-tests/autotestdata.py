#!/usr/bin/env python
#
# @file    autobuild.py
# @brief   automatic, configuration and testing of liSBML build options
# @author  Brett G. Olivier
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2018 by the California Institute of Technology
# (California, USA), the European Bioinformatics Institute (EMBL-EBI, UK)
# and the University of Heidelberg (Germany), with support from the National
# Institutes of Health (USA) under grant R01GM070923.  All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
# Neither the name of the California Institute of Technology (Caltech), nor
# of the European Bioinformatics Institute (EMBL-EBI), nor of the University
# of Heidelberg, nor the names of any contributors, may be used to endorse
# or promote products derived from this software without specific prior
# written permission.
# ------------------------------------------------------------------------ -->
#

import os, re, json

# package switches

class CMakeRegEx(object):
    """
    Generates and stores regular expressions usefuls for manipulating cmake files

    """

    package_names = ['COMP', 'FBC', 'GROUPS', 'L3V2EXTENDEDMATH', 'LAYOUT', 'MULTI', 'QUAL', 'RENDER']
    packages = {}

    def __init__(self):
        for n_ in self.package_names:
            self.packages['ENABLE_{}'.format(n_)] = re.compile('ENABLE_{}:BOOL=(ON|OFF)'.format(n_))



class CMakeReplacements(object):
    """
    Generates and stores string replacements usefuls for manipulating cmake files

    """
    package_names = ['COMP', 'FBC', 'GROUPS', 'L3V2EXTENDEDMATH', 'LAYOUT', 'MULTI', 'QUAL', 'RENDER']
    package_names_exp = package_names + ['ARRAYS', 'DISTRIB','DYN','REQUIREDELEMENTS', 'SPATIAL']
    template_libsbml_source_path = None
    libsbml_src_path = None
    libsbml_exp_src_path = None

    cmake_generator_opts = {'Unix Makefiles' : {'cmake_generator_make' : '/usr/bin/make'}}
    cmake_src_config = ['LIBSBML_ROOT_SOURCE_DIR:PATH=', 'libsbml_SOURCE_DIR:STATIC=',\
        'CMAKE_HOME_DIRECTORY:INTERNAL=']

    libsbml_packages_enabled = None
    libsbml_packages_disabled = None
    libsbml_packages_exp_enabled = None
    libsbml_packages_exp_disabled = None

    cmake_template_src_paths = None
    cmake_install_path = None

    configure_experimental = None
    configure_with_cmake = None
    build_test_configurations = None
    check_test_configurations = None
    test_all_combinations = None
    config_combination = None
    cmake_generator = None
    default_test_options = None
    base_file = None
    config = None

    def __init__(self, filepath):
        """
        Create a test data object initialised with a configuration dictionary
        loaded from a json formatted configuration file.

        - *filepath* a string that refers to a file containing a python dictionary of configuration options

        """
        self.load_json_to_config(filepath)
        self.load_options_from_config()

    ubuntu_check_config = {'disabled' : 'WITH_CHECK:BOOL=OFF',
                           'enabled' : 'WITH_CHECK:BOOL=ON'}

    libsbml_xml_parsers = {'expat' : {'enabled' : 'WITH_EXPAT:BOOL=ON',
                                      'disabled' : 'WITH_EXPAT:BOOL=OFF'
                                      },
                           'xml2' :  {'enabled' :  'WITH_LIBXML:BOOL=ON',
                                      'disabled' : 'WITH_LIBXML:BOOL=OFF'
                                      },
                           'xerces' : {'enabled' :  'WITH_XERCES:BOOL=ON',
                                       'disabled' : 'WITH_XERCES:BOOL=OFF'
                                      }}

    libsbml_examples = {'enabled' : 'WITH_EXAMPLES:BOOL=ON',
                         'disabled' : 'WITH_EXAMPLES:BOOL=OFF'}

    cmake_install_prefix = 'CMAKE_INSTALL_PREFIX:PATH=/usr/local'

    libsbml_use_strict_includes = {'enabled' : 'LIBSBML_USE_STRICT_INCLUDES:BOOL=ON',
                                   'disabled' : 'LIBSBML_USE_STRICT_INCLUDES:BOOL=OFF'}

    libsbml_cpp_namespace = {'enabled' : 'WITH_CPP_NAMESPACE:BOOL=ON',
                             'disabled' : 'WITH_CPP_NAMESPACE:BOOL=OFF'}

    libsbml_bindings = {'csharp' :  {'enabled' : 'WITH_CSHARP:BOOL=ON',
                                    'disabled' : 'WITH_CSHARP:BOOL=OFF'
                                    },
                        'java' :    {'enabled' : 'WITH_JAVA:BOOL=ON',
                                    'disabled' : 'WITH_JAVA:BOOL=OFF'
                                    },
                        'perl' :    {'enabled' : 'WITH_PERL:BOOL=ON',
                                    'disabled' : 'WITH_PERL:BOOL=OFF'
                                    },
                        'python' :  {'enabled' : 'WITH_PYTHON:BOOL=ON',
                                    'disabled' : 'WITH_PYTHON:BOOL=OFF'
                                    },
                        'r' :       {'enabled' : 'WITH_R:BOOL=ON',
                                    'disabled' : 'WITH_R:BOOL=OFF'
                                    }
                        }

    create_python_source = {'enabled' : 'WITH_CREATE_PYTHON_SOURCE:BOOL=ON',
                           'disabled' : 'WITH_CREATE_PYTHON_SOURCE:BOOL=OFF'
                           }

    def load_json_to_config(self, filepath):
        """
        Load a configuration file and decode

        - *filepath* a file path

        """
        assert os.path.exists(filepath), '\n{} is not a file'.format(filepath)
        with open(filepath, 'r') as Fcfg:
            self.config = json.load(Fcfg)
        Fcfg.close()

    def load_options_from_config(self):
        """
        Configures options attributes from a loaded config file.

        """
        self.libsbml_exp_src_path = self.config['paths']['libsbml_exp_src_path']
        self.libsbml_src_path = self.config['paths']['libsbml_src_path']
        self.template_libsbml_source_path = self.config['paths']['template_libsbml_source_path']
        self.base_file = self.config['paths']['base_file']

        self.configure_experimental = self.config['options']['configure_experimental']
        self.configure_with_cmake = self.config['options']['configure_with_cmake']
        self.build_test_configurations = self.config['options']['build_test_configurations']
        self.check_test_configurations = self.config['options']['check_test_configurations']

        self.test_all_combinations = self.config['options']['test_all_combinations']
        self.config_combination = self.config['options']['config_combination']
        self.cmake_generator = self.config['options']['cmake_generator']
        self.default_test_options = self.config['tests']['default']

        self.cmake_template_src_paths = {p : self.template_libsbml_source_path for p in self.cmake_src_config}
        self.libsbml_packages_enabled =  {p : 'ENABLE_{}:BOOL=ON'.format(p) for p in self.package_names}
        self.libsbml_packages_disabled =  {p : 'ENABLE_{}:BOOL=OFF'.format(p) for p in self.package_names if p != 'L3V2EXTENDEDMATH'}
        self.libsbml_packages_exp_enabled =  {p : 'ENABLE_{}:BOOL=ON'.format(p) for p in self.package_names_exp}
        self.libsbml_packages_exp_disabled =  {p : 'ENABLE_{}:BOOL=OFF'.format(p) for p in self.package_names_exp if p != 'L3V2EXTENDEDMATH'}







def format_output_csv(config, head, status):
    """
    Format results for CSV output. Returns a linked list of data.

     *config* the list of processed configuration options and results
     *head* the header row
     *status* the integer indicating the combination of options was successful

    """
    form = []
    for opts in config:
        row = []
        for h in head:
            if h == 'status':
                row.append(status)
            elif h in opts:
                row.append('X')
            else:
                row.append('')
        form.append(row)
    return form
