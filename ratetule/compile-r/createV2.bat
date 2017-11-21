@echo off
SET CURRENT_DIR=%~dp0

SET R_VERSION=2.15.2
SET R_DIR=C:/Program Files/R/R-%R_VERSION%
SET PACKAGE_VERSION=5.15.0

SET R_INCLUDE_DIRS=%R_DIR%/include
SET R_INTERPRETER=%R_DIR%/bin/R.exe
SET R_LIB_32=%R_DIR%/bin/i386/Rlib.lib
SET R_LIB_64=%R_DIR%/bin/x64/Rlib.lib

SET LIBSBML_SRC=C:/Development/libsbml
SET LIBSBML_32=C:/Development/libsbml-32-inst/lib/libsbml-static.lib
SET LIBSBML_64=C:/Development/libsbml-64-inst/lib/libsbml-static.lib

SET DEP_32=C:/Development/dependencies/32bit/lib
SET DEP_64=C:/Development/dependencies/64bit/lib

SET OPTS=-G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release -DLIBSBML_ROOT_SOURCE_DIR="%LIBSBML_SRC%"

SET VC_VARS=C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat

pushd %CURRENT_DIR%

:: copy new files
copy /y C:\Development\libsbml-32\src\bindings\r\*.cpp . 
copy /y C:\Development\libsbml-32\src\bindings\swig\*.h swig
rd /s /q sbml
mkdir sbml
xcopy /y /s C:\Development\libsbml-32-inst\include\sbml sbml


:: COMPILE 32bit
mkdir build32
pushd build32
call "%VC_VARS%" x86
cmake %OPTS% -DR_INCLUDE_DIRS="%R_INCLUDE_DIRS%" -DR_INTERPRETER="%R_INTERPRETER%" -DR_LIB="%R_LIB_32%" -DPACKAGE_VERSION=%PACKAGE_VERSION% ..
cmake -DLIBSBML_LIB="%LIBSBML_32%" -DDEP_DIR="%DEP_32%" ..
cmake -DEXTRA_DEFS="USE_COMP;USE_LAYOUT;USE_FBC;USE_QUAL;USE_GROUPS;USE_MULTI;LIBSBML_COMPILED_IN_SRC;LIBSBML_USE_LEGACY_MATH" ..
nmake

popd

:: COMPILE 64bit
mkdir build64
pushd build64
call "%VC_VARS%" x64
cmake %OPTS% -DR_INCLUDE_DIRS="%R_INCLUDE_DIRS%" -DR_INTERPRETER="%R_INTERPRETER%" -DR_LIB="%R_LIB_64%" -DPACKAGE_VERSION=%PACKAGE_VERSION% ..
cmake -DLIBSBML_LIB="%LIBSBML_64%"  -DDEP_DIR="%DEP_64%" ..
cmake -DEXTRA_DEFS="USE_COMP;USE_LAYOUT;USE_FBC;USE_QUAL;USE_GROUPS;USE_MULTI;LIBSBML_COMPILED_IN_SRC;LIBSBML_USE_LEGACY_MATH" ..
nmake

popd

:: CREATE PACKAGE
mkdir %CURRENT_DIR%\libSBML\inst\libs\i386
mkdir %CURRENT_DIR%\libSBML\inst\libs\x64
mkdir %CURRENT_DIR%\libSBML\R
copy /y  build32\libSBML.dll %CURRENT_DIR%\libSBML\inst\libs\i386
copy /y  build64\libSBML.dll %CURRENT_DIR%\libSBML\inst\libs\x64
copy /Y  libSBML.R %CURRENT_DIR%\libSBML\R


"%R_INTERPRETER%" CMD INSTALL --build  --no-libs  --no-test-load --no-clean-on-error  --no-multiarch libSBML  -l temp
mkdir  %R_VERSION%
move *.zip %R_VERSION%
popd