## create-standalone
This folder contains everything needed, to transform the default python archive (as created by CMake from the libSBML sources) into a standalone archive containing all dependencies. 

### Dependencies
This folder contains all the necessary sources: expat, zlib and bzip2. As well as a copy of the libSBML expat API. These files will be copied by the script as needed. 

This can only work, if `cmake` as well as `tar` are in the PATH variable. 

### How to use
In order to create a new set of archives create first the stable and experimental source archives using the normal cmake process. Then copy them into the 'in' folder. After that execute: 

	createStandalone.bat <VERSION>

where `VERSION` is the full dotted version string of the release. So for example to create the `5.12.1` version one would run: 

	createStandalone.bat 5.12.1


----------
2/8/2016 2:46:00 PM Frank Bergmann