import re

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
    template_libsbml_source_path = '/home/sbml/development/sf_libsbml'
    libsbml_src_path = '/home/sbml/development/sf_libsbml'
    libsbml_exp_src_path = '/home/sbml/development/sf_libsbml_experimental'

    cmake_generator_opts = {'Unix Makefiles' : {'cmake_generator_make' : '/usr/bin/make'}}
    cmake_src_config = ['LIBSBML_ROOT_SOURCE_DIR:PATH=', 'libsbml_SOURCE_DIR:STATIC=',\
        'CMAKE_HOME_DIRECTORY:INTERNAL=']
    
    libsbml_packages_enabled = None
    libsbml_packages_disabled = None
    libsbml_packages_exp_enabled = None
    libsbml_packages_exp_disabled = None
    cmake_template_src_paths = None
    cmake_install_path = None


    def __init__(self):
        self.cmake_template_src_paths = {p : self.template_libsbml_source_path for p in self.cmake_src_config}
        self.libsbml_packages_enabled =  {p : 'ENABLE_{}:BOOL=ON'.format(p) for p in self.package_names}
        self.libsbml_packages_disabled =  {p : 'ENABLE_{}:BOOL=OFF'.format(p) for p in self.package_names if p != 'L3V2EXTENDEDMATH'}
        self.libsbml_packages_exp_enabled =  {p : 'ENABLE_{}:BOOL=ON'.format(p) for p in self.package_names_exp}
        self.libsbml_packages_exp_disabled =  {p : 'ENABLE_{}:BOOL=OFF'.format(p) for p in self.package_names_exp if p != 'L3V2EXTENDEDMATH'}


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
    



