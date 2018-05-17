# Delay Windows/Python build

Create the complete set of all 32/64 bit standalone installers, PyPI wheels and Anaconda packages from local libSBML source repositories for various Python distributions. Requires various Python versions each with setuptools, pip and wheel packages and swig in the system path. 

The `build-python` directory occurs in two places but only needs to be run from the one. The current setup is such that `experimental` is built in the 64 bit branch:

 c:\Development\libsbml-experimental-src-64\dev\utilities\build-python\
 
while `stable` is built in the 32bit branch:

 c:\Development\libsbml-src-32\dev\utilities\build-python\

## Folder locations
`c:\Development\libsbml-src-32\dev\utilities\build-python\`
`c:\Development\libsbml-experimental-src-64\dev\utilities\build-python\`

*TODO* for both stable and experimental the 32 and 64 bit branches need to be sychronised!!!
