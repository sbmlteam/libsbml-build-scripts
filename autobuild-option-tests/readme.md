
## Creating a new OS template file
Using CMake-gui or command line tools create 

### Add the experimental packages to  CMakeCache.txt file
I usually do it after the existing  ```ENABLE_RENDER:BOOL=OFF``` entry

```
//Enable libSBML support for the SBML Level 3 Arrays ('arrays')
// package.
ENABLE_ARRAYS:BOOL=OFF

//Enable libSBML support for the SBML Level 3 Distrib ('distrib')
// package.
ENABLE_DISTRIB:BOOL=OFF

//Enable libSBML support for the SBML Level 3 Dynamic Structures
// ('dyn') package
ENABLE_DYN:BOOL=OFF

//Enable libSBML support for the SBML Level 3 Required Elements
// ('req') package.
ENABLE_REQUIREDELEMENTS:BOOL=OFF

//Enable libSBML support for the SBML Level 3 Spatial Processes
// ('spatial') package.
ENABLE_SPATIAL:BOOL=OFF
```
