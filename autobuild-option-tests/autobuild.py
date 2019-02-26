import os, sys, shutil, re
cdir = os.path.dirname(os.path.abspath(os.sys.argv[0]))

# import and instantiate custom cmake replacements
from cmakerelib import CMakeReplacements
rbase = CMakeReplacements()

## configure test environment
libsbml_src_path = '/home/sbml/development/sf_libsbml'
base_file = 'ubuntu-1604-ninja-base-CMakeCache.txt' # default for Ubuntu

## Setup cmake generator
cmake_generator = 'Ninja' # default for Ubuntu
# cmake_generator = 'Unix Makefiles'

# setup option templates
test_options = [[]] # base only

## test configurations
# test_options = [[], ['packages'], ['check'], ['examples'], ['expat'], ['xerces']] # individual options
# test_options = test_options + [['packages', 'check', 'examples', 'expat']] # all options combined

# we insert the base option
tmp = [opt.insert(0, 'base') for opt in test_options]

print(test_options)

if cmake_generator == 'Unix Makefiles':
    cmake_generator_make = rbase.cmake_generator_opts['Unix Makefiles']['cmake_generator_make']
else:
    cmake_generator_make = None

for conopts in test_options:
    # configures the base paths and files in the new cmake build directory
    base_split = base_file.split('-')
    new_opts = '-'.join(conopts)
    base_dir = os.path.join(cdir, '-'.join(base_split[:-2]) + '-{}'.format(new_opts), )
    base_dir = base_dir.replace('-ninja-', '-{}-'.format(cmake_generator.replace(' ', '-').lower()))
    if os.path.exists(base_dir):
        shutil.rmtree(base_dir)
    os.mkdir(base_dir)
    new_cache_file = os.path.join(base_dir, 'CMakeCache.txt')
    new_cache_template = new_cache_file + '.template'
    shutil.copyfile(os.path.join(cdir, base_file), new_cache_template)
    
    output = []
    Fin = open(new_cache_template, 'r')
    Fout = open(new_cache_file, 'w')
    for l in Fin:
        # set the cmake build folder
        if cmake_generator == 'Ninja':
            outlin = l
        else:
            outlin = l.replace('-ninja-', '-{}-'.format(cmake_generator.replace(' ', '-').lower()))
        # configure cmake generator specific options
        if cmake_generator == "Unix Makefiles":
            if 'CMAKE_GENERATOR:INTERNAL' in outlin:
                outlin = outlin.replace('Ninja', cmake_generator)
            elif 'CMAKE_MAKE_PROGRAM:FILEPATH' in outlin:
                outlin = outlin.replace('=/usr/bin/ninja', '={}'.format(cmake_generator_make))
        # configure cmake build paths
        if '# For build in directory' in l:
            outlin = outlin.replace('/home/sbml/development/autobuild-option-tests', cdir)
            outlin = '{}'.format(outlin.replace('-base', '-{}'.format(new_opts)))
        elif '-base' in l:
            outlin = outlin.replace('/home/sbml/development/autobuild-option-tests', cdir)
            outlin = '{}'.format(outlin.replace('-base', '-{}'.format(new_opts)))
        # sets the libsbml src path options
        for o_ in rbase.cmake_template_src_paths:
            if o_ in l:
                outlin = outlin.replace(rbase.cmake_template_src_paths[o_], libsbml_src_path)
        
        # enable libCheck based unit testing
        if 'check' in conopts:
            if rbase.ubuntu_check_config['disabled'] in outlin:
                outlin = outlin.replace(rbase.ubuntu_check_config['disabled'], rbase.ubuntu_check_config['enabled'])

        # enable expat, the default is lxml2
        if 'expat' in conopts:
            if rbase.libsbml_xml_parsers['xml2']['enabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_xml_parsers['xml2']['enabled'], rbase.libsbml_xml_parsers['xml2']['disabled'])
            if rbase.libsbml_xml_parsers['xerces']['enabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_xml_parsers['xerces']['enabled'], rbase.libsbml_xml_parsers['xerces']['disabled'])
            if rbase.libsbml_xml_parsers['expat']['disabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_xml_parsers['expat']['disabled'], rbase.libsbml_xml_parsers['expat']['enabled'])

        # enable xerced, the default is lxml2
        if 'xerces' in conopts:
            if rbase.libsbml_xml_parsers['xml2']['enabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_xml_parsers['xml2']['enabled'], rbase.libsbml_xml_parsers['xml2']['disabled'])
            if rbase.libsbml_xml_parsers['expat']['enabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_xml_parsers['expat']['enabled'], rbase.libsbml_xml_parsers['expat']['disabled'])
            if rbase.libsbml_xml_parsers['xerces']['disabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_xml_parsers['xerces']['disabled'], rbase.libsbml_xml_parsers['xerces']['enabled'])

        # additional build options
        # enable packages
        if 'packages' in conopts:
            for p in rbase.libsbml_packages_disabled:
                pval = rbase.libsbml_packages_disabled[p]
                if pval in outlin:
                    outlin = outlin.replace(pval, pval.replace('BOOL=OFF', 'BOOL=ON'))
        # enable examples
        if 'examples' in conopts:
            if rbase.libsbml_examples['disabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_examples['disabled'], rbase.libsbml_examples['enabled'])


        Fout.write(outlin)
    Fin.close()
    Fout.close()
    


