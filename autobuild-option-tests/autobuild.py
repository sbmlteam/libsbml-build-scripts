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

import os, sys, shutil, re, time, itertools, copy, subprocess, threading, pprint
cdir = os.path.dirname(os.path.abspath(os.sys.argv[0]))

if os.sys.version_info[0] > 2:
    def raw_input(txt):
        return input(txt)

# import and instantiate custom cmake replacements
from cmakerelib import CMakeReplacements
rbase = CMakeReplacements()

## configure test environment

base_file = 'ubuntu-1604-ninja-base-CMakeCache.txt' # default for Ubuntu

## configure for experimental
configure_experimental = False

## call cmake configure
configure_with_cmake = True
## try to build the successfully configured builds
build_test_configurations = True
## test configurations
test_all_combinations = False # overrides all, use with care

## Setup cmake generator
cmake_generator = 'Ninja' # default for Ubuntu
# cmake_generator = 'Unix Makefiles'

# setup option templates
xml_options = ['xml2', 'expat', 'xerces']
fixed_options = ['check']
combi_options = ['packages', 'examples', 'strict', 'cpp_ns']

test_options = [[]] # base only
test_options =  [['check'], ['check', 'packages'], ['check', 'examples'], ['check', 'strict'], ['check', 'cpp_ns']]

# create output logger
Rlog = open('result_log.md', 'w')

if test_all_combinations:
    test_options = []
    for it in range(len(combi_options)):
        combis = [list(c) for c in itertools.combinations(combi_options, it+1 )]
        [c.sort() for c in combis]
        for opt in fixed_options:
            combis = [[opt] + c for c in combis]
        test_options.extend(combis)

    out = []

    for xml in xml_options:
        out1 = copy.deepcopy(test_options)
        if xml in ['expat', 'xerces']:
            [x.insert(0, xml) for x in out1]
        out += out1
    test_options = out

    print('\nAutogenerate created {} unique test combinations\n'.format(len(test_options)))
    a = raw_input('Proceed and generate all combinations (y/n)?\n')
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

# log selected options
Rlog.write('# MATRIX TEST\nTest run: {}\n'.format(time.strftime('%Y-%m-%d %H:%M:%S')))
Rlog.write('\n# CONFIGURATION COMBINATIONS\n')
for i in test_options:
    Rlog.write('  {}\n'.format(i))

START_TIME = time.time()

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

CONFIG_TIME = time.time()

# generate cmake configuration shell script
Fout = open(os.path.join(cdir, 'configure_with_cmake.sh'), 'w')
for build in cmake_builds:
    Fout.write('cmake {}\n'.format(build))
Fout.write('\n')
Fout.close()
os.chmod(os.path.join(cdir, 'configure_with_cmake.sh'), 0o744)

# parallel cmake congfiguration
report_cmake_configure = {}
report_cmake_configure_bad = {}
if configure_with_cmake:
    prprinter = pprint.PrettyPrinter()
    def cmake_configure(build, rpt):
        try:
            rpt[build] = subprocess.check_call(['cmake', build])
        except subprocess.CalledProcessError as err:
            rpt[build] = err.returncode
    process_pool = []
    for build in cmake_builds:
        process_pool.append(threading.Thread(target=cmake_configure, args=[build, report_cmake_configure]))
    for p in process_pool:
        p.start()
    for p in process_pool:
        p.join()

    for a in list(report_cmake_configure.keys()):
        if report_cmake_configure[a] != 0:
            report_cmake_configure_bad[a] = report_cmake_configure.pop(a)

    print('\n\nCMAKE CONFIGURARATION REPORT GOOD: {}\n'.format(len(report_cmake_configure)) + 37*'-')
    prprinter.pprint(report_cmake_configure)
    print('\nCMAKE CONFIGURARATION REPORT BAD: {}\n'.format(len(report_cmake_configure_bad)) + 36*'-')
    prprinter.pprint(report_cmake_configure_bad)

    # log build configurations
    Rlog.write('\n# CMAKE CONFIGURARATION REPORT GOOD: {}\n'.format(len(report_cmake_configure)))
    for i in report_cmake_configure:
        Rlog.write('  {} {}\n'.format(i, report_cmake_configure[i]))
    Rlog.write('\n# CMAKE CONFIGURARATION REPORT BAD: {}\n'.format(len(report_cmake_configure_bad)))
    for i in report_cmake_configure_bad:
        Rlog.write('  {} {}\n'.format(i, report_cmake_configure_bad[i]))

CMAKE_TIME = time.time()

if len(report_cmake_configure) == 0:
    print('\n\nNO GOOD CONFIGURATIONS, NOTHING TO DO!')
    Rlog.write('\nConfigure time: {}\n'.format(CONFIG_TIME - START_TIME))
    Rlog.write('CMake time: {}\n\n'.format(CMAKE_TIME - CONFIG_TIME))
    Rlog.close()
    os.sys.exit(1)
    
if build_test_configurations:
    print('\nCMAKE could configure {} out of {} unique test combinations\n'.format(len(report_cmake_configure), len(test_options)))
    a = raw_input('Proceed to build all combinations - this may take some time (y/n)?\n')
    if a.lower() != 'y':
        os.sys.exit()

    report_build = {}
    for cf in report_cmake_configure:
        try:
            os.chdir(cf)
            if cmake_generator == 'Ninja':
                report_build[cf] = subprocess.check_call(['ninja'])
            elif cmake_generator == 'Unix Makefiles':
                report_build[cf] = subprocess.check_call(['make'])
        except subprocess.CalledProcessError as err:
            report_build[cf] = err.returncode
    os.chdir(cdir)

    print('\nBUILD REPORT: {}\n'.format(len(report_build)) + 14*'-')
    prprinter.pprint(report_build)

    # log build report
    Rlog.write('\n# BUILD REPORT: {}\n'.format(len(report_cmake_configure)))
    for i in report_build:
        Rlog.write('  {} {}\n'.format(i, report_build[i]))
    
END_TIME = time.time()

# close log
Rlog.write('\nConfigure time: {}\n'.format(CONFIG_TIME - START_TIME))
Rlog.write('CMake time: {}\n'.format(CMAKE_TIME - CONFIG_TIME))
Rlog.write('Build time: {}\n'.format(END_TIME - CMAKE_TIME))
Rlog.write('Total time: {}\n\n'.format(END_TIME - START_TIME))
Rlog.close()


    


