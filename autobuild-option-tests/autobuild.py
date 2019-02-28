import os, sys, shutil, re, itertools, copy
cdir = os.path.dirname(os.path.abspath(os.sys.argv[0]))

# import and instantiate custom cmake replacements
from cmakerelib import CMakeReplacements
rbase = CMakeReplacements()

## configure test environment

base_file = 'ubuntu-1604-ninja-base-CMakeCache.txt' # default for Ubuntu

## configure for experimental
configure_experimental = False

## Setup cmake generator
cmake_generator = 'Ninja' # default for Ubuntu
# cmake_generator = 'Unix Makefiles'

# setup option templates
test_options = [[]] # base only
xml_options = ['xml2', 'expat', 'xerces']
config_options = ['packages', 'check', 'examples', 'strict', 'cpp_ns']

## test configurations
test_all_combinations = True # overrides all, use with care
# test_options = [a for a in xml_options if a is not None] + config_options # all individual options

if test_all_combinations:
    test_options = []
    for it in range(len(config_options)):
        combis = [list(c) for c in itertools.combinations(config_options, it+1 )]
        [c.sort() for c in combis]
        test_options.extend(combis)

    out = []

    for xml in xml_options:
        out1 = copy.deepcopy(test_options)
        if xml in ['expat', 'xerces']:
            [x.insert(0, xml) for x in out1]
        out += out1
    test_options = out

    for i in test_options:
        print(i)
    a = raw_input('Proceed and generate all combindations (y/n)?\n')
    if a.lower() != 'y':
        os.sys.exit()

# we insert the base option
tmp = [opt.insert(0, 'base') for opt in test_options]

print(test_options)

libsbml_src_path = rbase.libsbml_src_path
if configure_experimental:
    libsbml_src_path = rbase.libsbml_exp_src_path

if cmake_generator == 'Unix Makefiles':
    cmake_generator_make = rbase.cmake_generator_opts['Unix Makefiles']['cmake_generator_make']
else:
    cmake_generator_make = None

cmake_builds = []
for conopts in test_options:
    # configures the base paths and files in the new cmake build directory
    base_split = base_file.split('-')
    new_opts = '-'.join(conopts)
    base_dir = os.path.join(cdir, '-'.join(base_split[:-2]) + '-{}'.format(new_opts), )
    if configure_experimental:
        base_dir = base_dir.replace('-ninja-', '-exp-{}-'.format(cmake_generator.replace(' ', '-').lower()))
    else:
        base_dir = base_dir.replace('-ninja-', '-{}-'.format(cmake_generator.replace(' ', '-').lower()))
    rbase.cmake_install_path = base_dir + '-install'
    cmake_builds.append(base_dir)

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
        # set the cmake build folders
        if cmake_generator == 'Ninja':
            if configure_experimental:
                outlin = l.replace('-ninja-', '-exp-ninja-')
            else:
                outlin = l
        else:
            if configure_experimental:
                outlin = l.replace('-ninja-', '-exp-{}-'.format(cmake_generator.replace(' ', '-').lower()))
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
        # sets the install path
        if rbase.cmake_install_prefix in l:
            outlin = outlin.replace('/usr/local', rbase.cmake_install_path)
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
        # enable xerces, the default is lxml2
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
            if configure_experimental:
                pkgs = rbase.libsbml_packages_exp_disabled
            else:
                pkgs = rbase.libsbml_packages_disabled
            for p in pkgs:
                pval = pkgs[p]
                if pval in outlin:
                    outlin = outlin.replace(pval, pval.replace('BOOL=OFF', 'BOOL=ON'))
        # enable examples
        if 'examples' in conopts:
            if rbase.libsbml_examples['disabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_examples['disabled'], rbase.libsbml_examples['enabled'])
        # strict includes
        if 'strict' in conopts:
            if rbase.libsbml_use_strict_includes['disabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_use_strict_includes['disabled'], rbase.libsbml_use_strict_includes['enabled'])
        # cpp namespace
        if 'cpp_ns' in conopts:
            if rbase.libsbml_cpp_namespace['disabled'] in outlin:
                outlin = outlin.replace(rbase.libsbml_cpp_namespace['disabled'], rbase.libsbml_cpp_namespace['enabled'])

        Fout.write(outlin)
    Fin.close()
    Fout.close()
    os.remove(new_cache_template)

Fout = open(os.path.join(cdir, 'cmake_configure.sh'), 'w')
for build in cmake_builds:
    Fout.write('cmake {}\n'.format(build))
Fout.write('\n')
Fout.close()
os.chmod(os.path.join(cdir, 'cmake_configure.sh'), 0o744)


    
    


