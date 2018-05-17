# Delay Windows/Python build

Create the complete set of all 32/64 bit standalone installers, PyPI wheels and Anaconda packages from local libSBML source repositories for various Python distributions. Requires various Python versions each with setuptools, pip and wheel packages and swig in the system path. The `build-python` directory occurs in two places but only needs to be run from on located in the 64 bit source tree.

Actually both directories have been used, the current (15.7.0) build has been done in the src-64 directory as these (newer) files include support for Py36. 

## Folder location
`c:\Development\libsbml-experimental-src-64\dev\utilities`
