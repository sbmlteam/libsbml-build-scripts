#!/usr/bin/env python
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

import os, pprint

cdir = os.path.dirname(os.path.abspath(os.sys.argv[0]))
resdir = os.path.join(cdir, 'reports_test', '2019-03-07-19-26')
res_idx_file = os.path.join(resdir, 'result_log.md')

Fidx =  open(res_idx_file, 'r')

check_results = {}
CHECK_GO = False
for l in Fidx:
    if l.startswith('# CHECK REPORT:'):
        CHECK_GO = True
    elif l.startswith('  /'):
        ls = l.strip().split(' ')
        check_results[os.path.split(ls[0])[1].split('-base-')[1]] = int(ls[1])

options_bad = []
options_good = []
for r in check_results:
    opts = r.split('-')
    #opts.sort()
    if check_results[r] == 0:
        options_good.append(opts)
    else:
        options_bad.append(opts)
options_bad.sort()
options_good.sort()
Fidx.close()
pprint.pprint(check_results)
print('\nOptions good')
pprint.pprint(options_good)
print('\nOptions bad')
pprint.pprint(options_bad)