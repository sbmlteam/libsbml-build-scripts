# Automated Windows build system
Development dir contains various source directories including:

```
libsbml libsbml-src32 libsbml-src-32 libsbml-src-64 libsbml-with-packages 
```

Nightly builds are triggered by the windows task scheduler every day at 2PM (pacific), so that the builds are ready in time for the next day. The main files are kept in `c:\buildtool` which has the following scripts:

* Run_build.bat: runs the whole build and test (will take many hours) in the process the build_log.txt file in the local directory contains the results of the build and can be monitored
* Run_package_build.bat: only runs the experimental package builds, no testing here. 
* Make_pkg.bat: run package matlab and r builds only
* Run_tests.bat: runs all the tests
* Runpython.bat: runs all python builds
* updateR.bat moves the created R packages into the web directory
* Updatelist.bat: updates the build and test text files for the website (copies them to the IIS directory, and forces the site to refresh the file list upon the next request.)
*deleteBindings.bat: deletes all language bindings previously created. 

`cmake --build dir --config_Realease` will run whatever build has been configured

To update the build configuration of nightly builds on raterule:

In buildtool directory the CMakeCache_32.in etc are the configuration files, CMakeLists.txt for python:

```
CMakeCache_32.in CMakeCache_32p.in 
CMakeCache_64.in CMakeCache_64p.in 
CMakeListsPy.txt.in CMakeListsPythonPackage.in 
createInst.in createInstallFilesP.in 
createMatlabInstallers.in createMatlabInstallersP.in 
createXMLRel_x64.in createXMLRel_x86.in
```

The buildPython.bat lists the versions of python that will be used in build.

* Python 32: 2.5, 2.6, 2.7, 3.2, 3.3, 3.4, 3.5
* Python 64: 2.6, 2.7, 3.2, 3.3, 3.4, 3.5

### still to be worked through

* The conda bat files need to be updated (need to look into this -bgoli)
* R build now in Development/compile-r:
* createV3 or createV2 lists the cmake configurations

Libsbml src tree `dev/utilities/expdef`	has code that runs a program that creates the lib files for R (if we have R4)
