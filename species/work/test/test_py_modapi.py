## @file    test_0_basic.py
## @brief   Test code for enhanced Python API
## @author  Brett G. Olivier (b.g.olivier@vu.nl)
##
##<!---------------------------------------------------------------------------
## This file is part of libSBML.  Please visit http://sbml.org for more
## information about SBML, and the latest version of libSBML.
##
## Copyright (C) 2013-2018 jointly by the following organizations:
##     1. California Institute of Technology, Pasadena, CA, USA
##     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
##     3. University of Heidelberg, Heidelberg, Germany
##
## Copyright 2005-2010 California Institute of Technology.
## Copyright 2002-2005 California Institute of Technology and
##                     Japan Science and Technology Corporation.
##
## This library is free software; you can redistribute it and/or modify it
## under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation.  A copy of the license agreement is provided
## in the file named "LICENSE.txt" included with this software distribution
## and also available online as http://sbml.org/software/libsbml/license.html
##----------------------------------------------------------------------- -->*/

import os
cDir = os.path.dirname(os.path.abspath(__file__))

import libsbml

print('\nlibSBML version: {}\n({})\n'.format(libsbml.getLibSBMLVersionString(),  os.sys.version))

D = libsbml.readSBMLFromFile('enzymekinetics.xml')
M = D.getModel()
S = M.getSpecies('S')
R = M.getReaction('veq')

#m_rid = M.getReaction(0).getId()
#m_spid = M.getSpecies(0).getId()
#m_ns = M.getNamespaces()
#m_cvterm = M.getCVTerm(0)

print('M.__parent_ref__: {}\n'.format(M.__parent_ref__))
print('M.reactions: {}'.format(M.reactions))
print('M.species: {}\n'.format(M.species))
print('NoCVTerms: {}'.format(S.getCVTerms()))
print('HasCVTerms: {}\n'.format(R.getCVTerms()))
print('setId: {}\n'.format(M.setId('bad id')))
print('R+S hasattr read: {}\n'.format(hasattr(S, 'read') and hasattr(R, 'read')))



