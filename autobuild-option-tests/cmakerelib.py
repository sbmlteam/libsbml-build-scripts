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
    template_libsbml_source_path = '/home/sbml/development/sf_libsbml'

    cmake_generator_opts = {'Unix Makefiles' : {'cmake_generator_make' : '/usr/bin/make'}}
    cmake_src_config = ['LIBSBML_ROOT_SOURCE_DIR:PATH=', 'libsbml_SOURCE_DIR:STATIC=',\
        'CMAKE_HOME_DIRECTORY:INTERNAL=']
    
    cmake_template_src_paths = None
    libsbml_packages_enabled = None
    libsbml_packages_disabled = None

    def __init__(self):
        self.cmake_template_src_paths = {p : self.template_libsbml_source_path for p in self.cmake_src_config}
        self.libsbml_packages_enabled =  {p : 'ENABLE_{}:BOOL=ON'.format(p) for p in self.package_names}
        self.libsbml_packages_disabled =  {p : 'ENABLE_{}:BOOL=OFF'.format(p) for p in self.package_names if p != 'L3V2EXTENDEDMATH'}
    
    ubuntu_check_config = {'disabled' : 'WITH_CHECK:BOOL=OFF',
                           'enabled' : 'WITH_CHECK:BOOL=ON'
                           }


    

