#!/usr/bin/env python3
#
# @file    parse_test_results.py
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

# test argument: python parse_test_results.py test_reports\\2019-03-12-23-11\\result_log.md

import os, pprint, csv
cdir = os.path.dirname(os.path.abspath(os.sys.argv[0]))

assert len(os.sys.argv) == 2, '\n\nparse_test_results.py requires a path relative to the current directory to a report file as an argument.'
report_path = os.path.join(os.path.join(cdir, os.sys.argv[1]))
assert os.path.exists(report_path), '\n\nInvalid path argument: \"{}\" does not exist'.format(os.sys.argv[1])
report_dir, report_name = os.path.split(report_path)
print('\nUsing valid input report:\n{}\n{}\n{}'.format(report_path, report_dir, report_name))

HAVE_XLS = True
try:
    import xlsxwriter
    print('Generating Excel format report.')
except ImportError:
    HAVE_XLS = False
    xlsw = None

import templatetools as atd


# MATRIX TEST
if HAVE_XLS:
    workbook = xlsxwriter.Workbook(report_path.replace('.md', '.xlsx'))
    config_sheet = workbook.add_worksheet('Configure')
    build_sheet = workbook.add_worksheet('Build')
    check_sheet = workbook.add_worksheet('Check')
    info_sheet = workbook.add_worksheet('Info')
    cf_header = workbook.add_format({'bold': True, 'align': 'center'})
    cf_normal = workbook.add_format({'bold': False, 'align': 'center'})
    cf_error = workbook.add_format({'bold': False, 'align': 'center', 'color': 'red'})

if HAVE_XLS:
    info_sheet.write_string(3, 0, 'Experimental')
    if '-exp-' in report_name:
        info_sheet.write_string(3, 1, 'true')
    else:
        info_sheet.write_string(3, 1, 'false')
    info_sheet.write_string(4, 0, 'Report')
    info_sheet.write_string(4, 1, report_name)

# INFO parse
if HAVE_XLS:
    Fidx =  open(report_path, 'r')
    for l in Fidx:
        if l.startswith('Test run:'):
            k, v = l.split(':')
            info_sheet.write_string(0, 0, k.strip())
            info_sheet.write_string(0, 1, v.strip())
        elif l.startswith('Generator:'):
            k, v = l.split(':')
            info_sheet.write_string(1, 0, k.strip())
            info_sheet.write_string(1, 1, v.strip())
        elif l.startswith('Config time:'):
            k, v = l.split(':')
            info_sheet.write_string(6, 0, k.strip())
            info_sheet.write_string(6, 1, v.strip())
        elif l.startswith('CMake time:'):
            k, v = l.split(':')
            info_sheet.write_string(7, 0, k.strip())
            info_sheet.write_string(7, 1, v.strip())
        elif l.startswith('Build time:'):
            k, v = l.split(':')
            info_sheet.write_string(8, 0, k.strip())
            info_sheet.write_string(8, 1, v.strip())
        elif l.startswith('Test time:'):
            k, v = l.split(':')
            info_sheet.write_string(9, 0, k.strip())
            info_sheet.write_string(9, 1, v.strip())
        elif l.startswith('Total time:'):
            k, v = l.split(':')
            info_sheet.write_string(10, 0, k.strip())
            info_sheet.write_string(10, 1, v.strip())
        elif l.startswith('Source:'):
            k, v = l.split(':')
            info_sheet.write_string(2, 0, k.strip())
            info_sheet.write_string(2, 1, v.strip())
    Fidx.close()

# CMAKE parse
Fidx =  open(report_path, 'r')
configure_results = {}
CONFIG_GO = False
for l in Fidx:
    if l.startswith('# CMAKE CONFIGURATION REPORT GOOD:'):
        CONFIG_GO = True
    elif l.startswith('# BUILD REPORT:'):
        CONFIG_GO = False
        break
    elif l.startswith('  /') and CONFIG_GO:
        ls = l.strip().split(' ')
        configure_results[os.path.split(ls[0])[1].split('-base-')[1]] = int(ls[1])
Fidx.close()

# BUILD parse
Fidx =  open(report_path, 'r')
build_results = {}
BUILD_GO = False
for l in Fidx:
    if l.startswith('# BUILD REPORT:'):
        BUILD_GO = True
    elif l.startswith('# CHECK REPORT:'):
        BUILD_GO = False
        break
    elif l.startswith('  /') and BUILD_GO:
        ls = l.strip().split(' ')
        build_results[os.path.split(ls[0])[1].split('-base-')[1]] = int(ls[1])
Fidx.close()

# CTEST parse
Fidx =  open(report_path, 'r')
ctest_results = {}
CHECK_GO = False
for l in Fidx:
    if l.startswith('# CHECK REPORT:'):
        CHECK_GO = True
    elif l.startswith('  /') and CHECK_GO:
        ls = l.strip().split(' ')
        ctest_results[os.path.split(ls[0])[1].split('-base-')[1]] = int(ls[1])
Fidx.close()

#pprint.pprint(configure_results)
#pprint.pprint(build_results)
#pprint.pprint(ctest_results)
#input('sds')

# CMAKE results
config_good = []
config_bad = []
for r in configure_results:
    opts = r.split('-')
    if configure_results[r] == 0:
        config_good.append(opts)
    else:
        config_bad.append(opts)

# BUILD results
build_good = []
build_bad = []
for r in build_results:
    opts = r.split('-')
    if build_results[r] == 0:
        build_good.append(opts)
    else:
        build_bad.append(opts)

# CTEST results
ctest_bad = []
ctest_good = []
for r in ctest_results:
    opts = r.split('-')
    if ctest_results[r] == 0:
        ctest_good.append(opts)
    else:
        ctest_bad.append(opts)

# create a sorted header row
hraw = []
for c in config_good:
    hraw.extend(c)
header0 = list(set(hraw))
header = []
for item in ['check', 'examples', 'r', 'perl', 'java', 'csharp', 'python', 'packages', 'xerces','expat', 'xml2']:
    if item in header0:
        header.insert(0, header0.pop(header0.index(item)))
if 'check' in header0:
    header0.remove('check')
header0.sort()
header.extend(header0)
header.append('status')
del header0

#print('\nConfigure good')
#pprint.pprint(config_good)
#print('Config bad')
#pprint.pprint(config_bad)
#print('\nBuild good')
#pprint.pprint(build_good)
#print('Build bad')
#pprint.pprint(build_bad)
#print('\nCTest good')
#pprint.pprint(ctest_good)
#print('CTest bad')
#pprint.pprint(ctest_bad)
#print('Header: {}'.format(header))

with open(os.path.join(report_dir, 'report_configure.csv'), mode='w') as csv_file:
    csv_out = [header]
    [csv_out.append(h) for h in atd.format_output_csv(config_bad, header, 0)]
    [csv_out.append(h) for h in atd.format_output_csv(config_good, header, 1)]
    csvwriter = csv.writer(csv_file, dialect='excel', quoting=csv.QUOTE_NONNUMERIC)
    csvwriter.writerows(csv_out)
    if HAVE_XLS:
        for r in range(len(csv_out)):
            # formatting options
            if r == 0:
                fmt = cf_header
            elif csv_out[r][-1] == 0:
                fmt = cf_error                
            else:
                fmt = cf_normal
            for c in range(0, len(csv_out[0])):
                if csv_out[r][c] == 0 or csv_out[r][c] == 1:
                    config_sheet.write_number(r, c, csv_out[r][c], fmt)
                elif csv_out[r][c] == '':
                    config_sheet.write_blank(r, c, None, fmt)
                else:
                    config_sheet.write_string(r, c, csv_out[r][c], fmt)

with open(os.path.join(report_dir, 'report_build.csv'), mode='w') as csv_file:
    csv_out = [header]
    [csv_out.append(h) for h in atd.format_output_csv(build_bad, header, 0)]
    [csv_out.append(h) for h in atd.format_output_csv(build_good, header, 1)]
    csvwriter = csv.writer(csv_file, dialect='excel', quoting=csv.QUOTE_NONNUMERIC)
    csvwriter.writerows(csv_out)
    if HAVE_XLS:
        for r in range(len(csv_out)):
            # formatting options
            if r == 0:
                fmt = cf_header
            elif csv_out[r][-1] == 0:
                fmt = cf_error                
            else:
                fmt = cf_normal
            for c in range(0, len(csv_out[0])):
                if csv_out[r][c] == 0 or csv_out[r][c] == 1:
                    build_sheet.write_number(r, c, csv_out[r][c], fmt)
                elif csv_out[r][c] == '':
                    build_sheet.write_blank(r, c, None, fmt)
                else:
                    build_sheet.write_string(r, c, csv_out[r][c], fmt)


# debug
#ctest_bad_f = atd.format_output_csv(ctest_bad, header, 0)
#ctest_good_f = atd.format_output_csv(ctest_good, header, 1)
#print('bad')
#pprint.pprint(ctest_bad_f)
#print('good')
#pprint.pprint(ctest_good_f)

with open(os.path.join(report_dir, 'report_check.csv'), mode='w') as csv_file:
    csv_out = [header]
    [csv_out.append(h) for h in atd.format_output_csv(ctest_bad, header, 0)]
    [csv_out.append(h) for h in atd.format_output_csv(ctest_good, header, 1)]
    csvwriter = csv.writer(csv_file, dialect='excel', quoting=csv.QUOTE_NONNUMERIC)
    csvwriter.writerows(csv_out)
    if HAVE_XLS:
        for r in range(len(csv_out)):
            # formatting options
            if r == 0:
                fmt = cf_header
            elif csv_out[r][-1] == 0:
                fmt = cf_error                
            else:
                fmt = cf_normal
            for c in range(0, len(csv_out[0])):
                if csv_out[r][c] == 0 or csv_out[r][c] == 1:
                    check_sheet.write_number(r, c, csv_out[r][c], fmt)
                elif csv_out[r][c] == '':
                    check_sheet.write_blank(r, c, None, fmt)
                else:
                    check_sheet.write_string(r, c, csv_out[r][c], fmt)


if HAVE_XLS:
    workbook.close()
