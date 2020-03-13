@echo off
Setlocal EnableDelayedExpansion
SET BASE_DIR=%~dp0

SET VS_VERSION=14
SET VS_PREFIX=vs%VS_VERSION%
SET VS=%ProgramFiles(x86)%\Microsoft Visual Studio %VS_VERSION%.0\VC
SET VSDIR=%VS%\bin
SET NINJA_OPTS=-DCMAKE_CXX_COMPILER:FILEPATH="%VSDIR%\cl.exe" -DCMAKE_C_COMPILER:FILEPATH="%VSDIR%\cl.exe" -DCMAKE_LINKER:FILEPATH="%VSDIR%\link.exe" 

cd %BASE_DIR%
:: create dirs 
if not exist ninja_libsbml_32 mkdir ninja_libsbml_32
if not exist ninja_libsbml_64 mkdir ninja_libsbml_64
if not exist ninja_libsbml-experimental_32 mkdir ninja_libsbml-experimental_32
if not exist ninja_libsbml-experimental_64 mkdir ninja_libsbml-experimental_64

:: update sources
cd %BASE_DIR%\libsbml-src-32
svn cleanup 
svn update 
cd %BASE_DIR%\libsbml-src-64
svn cleanup 
svn update 
cd %BASE_DIR%\libsbml-experimental-src-32
svn cleanup 
svn update 
cd %BASE_DIR%\libsbml-experimental-src-64
svn cleanup 
svn update 

call "%VS%\vcvarsall.bat" x86
:: build 32 bit 
cd %BASE_DIR%\ninja_libsbml_32
SET WITH_STATIC_RUNTIME=ON
SET CMAKE_BUILD_TYPE=Release
SET VARIANT=%VS_PREFIX%_release_x86_static
SET CMAKE_OPTS=-DCMAKE_BUILD_TYPE:STRING=%CMAKE_BUILD_TYPE% -DBUILD_SHARED_LIBS:BOOL=OFF -DWITH_STATIC_RUNTIME:BOOL=%WITH_STATIC_RUNTIME% -DLIBSBML_DEPENDENCY_DIR=%BASE_DIR%\libsbml-dependencies\install_%VARIANT%

if not exist CMakeCache.txt cmake -G "Ninja" %NINJA_OPTS% %CMAKE_OPTS% %* %BASE_DIR%\libsbml-src-32 
ctest -D Experimental --overwrite Site=delay_ninja_32


:: build 32 bit exp 
cd %BASE_DIR%\ninja_libsbml-experimental_32
SET WITH_STATIC_RUNTIME=ON
SET CMAKE_BUILD_TYPE=Release
SET VARIANT=%VS_PREFIX%_release_x86_static
SET CMAKE_OPTS=-DCMAKE_BUILD_TYPE:STRING=%CMAKE_BUILD_TYPE% -DBUILD_SHARED_LIBS:BOOL=OFF -DWITH_STATIC_RUNTIME:BOOL=%WITH_STATIC_RUNTIME% -DLIBSBML_DEPENDENCY_DIR=%BASE_DIR%\libsbml-dependencies\install_%VARIANT%

if not exist CMakeCache.txt cmake -G "Ninja" %NINJA_OPTS% %CMAKE_OPTS% %* %BASE_DIR%\libsbml-experimental-src-32
ctest -D Experimental --overwrite Site=delay_ninja_32

call "%VS%\vcvarsall.bat" amd64
:: build 32 bit 
cd %BASE_DIR%\ninja_libsbml_64
SET WITH_STATIC_RUNTIME=ON
SET CMAKE_BUILD_TYPE=Release
SET VARIANT=%VS_PREFIX%_release_x64_static
SET CMAKE_OPTS=-DCMAKE_BUILD_TYPE:STRING=%CMAKE_BUILD_TYPE% -DBUILD_SHARED_LIBS:BOOL=OFF -DWITH_STATIC_RUNTIME:BOOL=%WITH_STATIC_RUNTIME% -DLIBSBML_DEPENDENCY_DIR=%BASE_DIR%\libsbml-dependencies\install_%VARIANT%

if not exist CMakeCache.txt cmake -G "Ninja" %NINJA_OPTS% %CMAKE_OPTS% %* %BASE_DIR%\libsbml-src-64
ctest -D Experimental --overwrite Site=delay_ninja_64
ctest -D Experimental --overwrite Site=delay_ninja_64


:: build 32 bit exp 
cd %BASE_DIR%\ninja_libsbml-experimental_64
SET WITH_STATIC_RUNTIME=ON
SET CMAKE_BUILD_TYPE=Release
SET VARIANT=%VS_PREFIX%_release_x86_static
SET CMAKE_OPTS=-DCMAKE_BUILD_TYPE:STRING=%CMAKE_BUILD_TYPE% -DBUILD_SHARED_LIBS:BOOL=OFF -DWITH_STATIC_RUNTIME:BOOL=%WITH_STATIC_RUNTIME% -DLIBSBML_DEPENDENCY_DIR=%BASE_DIR%\libsbml-dependencies\install_%VARIANT%

if not exist CMakeCache.txt cmake -G "Ninja" %NINJA_OPTS% %CMAKE_OPTS% %* %BASE_DIR%\libsbml-experimental-src-64
ctest -D Experimental --overwrite Site=delay_ninja_64
