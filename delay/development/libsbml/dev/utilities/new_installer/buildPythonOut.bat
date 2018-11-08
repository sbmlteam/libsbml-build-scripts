@echo off 

REM This file will build the python source dist and the 
REM python installers for (32 and 64 bit)
REM
REM 2011/02/26 Frank Bergmann
REM
REM 2018/10/20 Updated for vs14 Brett G. Olivier
REM

REM ensure visual studio is in the path
if "%INCLUDE%"=="" call c:\Development\vs14.bat

REM set up directory variables
SET WIN_INST_DIR=%~dp0
SET LIBSBML_PACKAGE_ROOT=c:\Development\libsbml-with-packages

REM this assumes that libsbml was previously build
REM SET PYTHON_25_32=c:\python32\Python25\python.exe
REM SET PYTHON_25_64=$$PYTHON25_64$$\python.exe
SET PYTHON_26_32=c:\python32\Python26\python.exe
SET PYTHON_26_64=c:\Python64\Python26\python.exe
SET PYTHON_27_32=c:\python32\Python27\python.exe
SET PYTHON_27_64=c:\Python64\Python27\python.exe
REM SET PYTHON_32_32=c:\Python32\Python32\python.exe
REM SET PYTHON_32_64=c:\Python64\Python32\python.exe
SET PYTHON_33_32=C:\Python32\Python33\python.exe
SET PYTHON_33_64=C:\Python64\Python33\python.exe
SET PYTHON_34_32=C:\Python32\Python34\python.exe
SET PYTHON_34_64=C:\Python64\Python34\python.exe
SET PYTHON_35_32=C:\Python32\Python35\python.exe
SET PYTHON_35_64=C:\Python64\Python35\python.exe
SET PYTHON_36_32=C:\Python32\Python36\python.exe
SET PYTHON_36_64=C:\Python64\Python36\python.exe
SET PYTHON_37_32=C:\Python32\Python37\python.exe
SET PYTHON_37_64=C:\Python64\Python37\python.exe


cd  /d %WIN_INST_DIR%

cmake .

SET BUILD_DIR_32_BIT=c:\Development\libsbml-32-packages

SET INSTALL_DIR_32=c:\Development\libsbml-32-inst-package
SET INSTALL_DIR_64=c:\Development\libsbml-64-inst-package

SET DEP_DIR_32=c:\Development\dependencies\x86\release-static
SET DEP_DIR_64=c:\Development\dependencies\x64\release-static

set SOURCE_32=%INSTALL_DIR_32%\bindings\python\src

SET INIT2_FILE=%BUILD_DIR_32_BIT%\src\bindings\python\libsbml.py
SET INIT3_FILE=%BUILD_DIR_32_BIT%\src\bindings\python\libsbml3.py
cmake -DSOURCE="%INIT2_FILE%" -DTARGET="%INIT3_FILE%" -P .\transform_init.cmake


IF NOT EXIST "%BUILD_DIR_32_BIT%" goto MISSING_DEPENDENCIES
IF NOT EXIST "%INSTALL_DIR_32%" goto MISSING_DEPENDENCIES
IF NOT EXIST "%INSTALL_DIR_64%" goto MISSING_DEPENDENCIES

REM Allow to bypass things
if "%1" == "--skip-copy" goto COMPILE_BINDINGS
if "%1" == "--test-only" goto DONE_BUILDING

REM prepare install dir 

mkdir "%INSTALL_DIR_32%\win32"
mkdir "%INSTALL_DIR_32%\win32\bin"
mkdir "%INSTALL_DIR_32%\win32\include"
mkdir "%INSTALL_DIR_32%\win32\lib"

xcopy /E /Y "%INSTALL_DIR_32%\bin" "%INSTALL_DIR_32%\win32\bin"
xcopy /E /Y "%INSTALL_DIR_32%\include" "%INSTALL_DIR_32%\win32\include"
xcopy /E /Y "%INSTALL_DIR_32%\lib" "%INSTALL_DIR_32%\win32\lib"
xcopy /E /Y "%DEP_DIR_32%\lib\*.lib" "%INSTALL_DIR_32%\win32\lib"

mkdir "%INSTALL_DIR_32%\win64"
mkdir "%INSTALL_DIR_32%\win64\bin"
mkdir "%INSTALL_DIR_32%\win64\include"
mkdir "%INSTALL_DIR_32%\win64\lib"

xcopy /E /Y "%INSTALL_DIR_64%\bin" "%INSTALL_DIR_32%\win64\bin"
xcopy /E /Y "%INSTALL_DIR_64%\include" "%INSTALL_DIR_32%\win64\include"
xcopy /E /Y "%INSTALL_DIR_64%\lib" "%INSTALL_DIR_32%\win64\lib"
xcopy /E /Y "%DEP_DIR_64%\lib\*.lib" "%INSTALL_DIR_32%\win64\lib"


REM create source dir
:CREATE_SOURCE_32
mkdir "%SOURCE_32%"
mkdir "%SOURCE_32%\..\swig"
mkdir "%SOURCE_32%\libsbml"
cd /d "%SOURCE_32%"
copy /Y "%WIN_INST_DIR%\graphics\libsbml-python-installer-graphic.bmp" %SOURCE_32%\

copy /Y "%WIN_INST_DIR%\python\libsbml.pth" %SOURCE_32%\
:copy /Y "%SOURCE_32%\..\libsbml.pth" %SOURCE_32%\
copy /Y "%LIBSBML_PACKAGE_ROOT%\src\bindings\swig\*.h" "%SOURCE_32%\..\swig"
copy /Y "%LIBSBML_PACKAGE_ROOT%\src\bindings\swig\libsbml.h" %SOURCE_32%\
copy /Y "%LIBSBML_PACKAGE_ROOT%\src\bindings\swig\ListWrapper.h" %SOURCE_32%\
copy /Y "%LIBSBML_PACKAGE_ROOT%\src\bindings\swig\OStream.h" %SOURCE_32%\
copy /Y "%LIBSBML_PACKAGE_ROOT%\src\bindings\swig\OStream.cpp" %SOURCE_32%\

copy /Y "%LIBSBML_PACKAGE_ROOT%\src\bindings\python\*.cpp" %SOURCE_32%\
copy /Y "%BUILD_DIR_32_BIT%\src\bindings\python\*.cpp" %SOURCE_32%\
copy /Y "%BUILD_DIR_32_BIT%\src\bindings\python\*.h" %SOURCE_32%\
copy /Y "%BUILD_DIR_32_BIT%\src\bindings\swig\*.h" %SOURCE_32%\..\swig
copy /Y "%INIT2_FILE%" libsbml\__init__.py

copy /Y "%WIN_INST_DIR%\python\CMakeLists.txt" %SOURCE_32%

copy /Y "%WIN_INST_DIR%\vs14.bat" %SOURCE_32%
copy /Y "%WIN_INST_DIR%\buildPython32.bat" %SOURCE_32%
copy /Y "%WIN_INST_DIR%\buildPython64.bat" %SOURCE_32%

copy /Y "%WIN_INST_DIR%\python\setup32.py" %SOURCE_32%
copy /Y "%WIN_INST_DIR%\python\setup64.py" %SOURCE_32%


:COMPILE_BINDINGS

REM remove old results
rd /s /q "%SOURCE_32%\build"
rd /s /q "%SOURCE_32%\dist"
mkdir "%SOURCE_32%\build"
mkdir "%SOURCE_32%\dist"

REM build python 2.5
REM rd /s /q "%SOURCE_32%\b32_
REM call  "%SOURCE_32%\buildPython32.bat" "%PYTHON_25_32%" "%DEP_DIR_32%"
REM mkdir "%SOURCE_32%\build\lib.win32-2.5"
REM mkdir "%SOURCE_32%\build\lib.win32-2.5\libsbml"
REM copy  "%INIT2_FILE%" "%SOURCE_32%\build\lib.win32-2.5\libsbml\__init__.py"
REM move  "%SOURCE_32%\b32_\_libsbml.pyd" "%SOURCE_32%\build\lib.win32-2.5\libsbml"

REM rd /s /q "%SOURCE_32%\b64_
REM call  "%SOURCE_32%\buildPython64.bat" "%PYTHON_25_64%" "%DEP_DIR_64%"
REM mkdir "%SOURCE_32%\build\lib.win-amd64-2.5"
REM mkdir "%SOURCE_32%\build\lib.win-amd64-2.5\libsbml"
REM copy "%INIT2_FILE%" "%SOURCE_32%\build\lib.win-amd64-2.5\libsbml\__init__.py"
REM move  "%SOURCE_32%\b64_\_libsbml.pyd" "%SOURCE_32%\build\lib.win-amd64-2.5\libsbml"

REM build python 2.6
echo == Build Python 2.6
rd /s /q "%SOURCE_32%\b32_
call  "%SOURCE_32%\buildPython32.bat" "%PYTHON_26_32%" "%DEP_DIR_32%"
mkdir "%SOURCE_32%\build\lib.win32-2.6"
mkdir "%SOURCE_32%\build\lib.win32-2.6\libsbml"
copy  "%INIT2_FILE%" "%SOURCE_32%\build\lib.win32-2.6\libsbml\__init__.py"
move  "%SOURCE_32%\b32_\_libsbml.pyd" "%SOURCE_32%\build\lib.win32-2.6\libsbml"

rd /s /q "%SOURCE_32%\b64_
call  "%SOURCE_32%\buildPython64.bat" "%PYTHON_26_64%" "%DEP_DIR_64%"
mkdir "%SOURCE_32%\build\lib.win-amd64-2.6"
mkdir "%SOURCE_32%\build\lib.win-amd64-2.6\libsbml"
copy "%INIT2_FILE%" "%SOURCE_32%\build\lib.win-amd64-2.6\libsbml\__init__.py"
move  "%SOURCE_32%\b64_\_libsbml.pyd" "%SOURCE_32%\build\lib.win-amd64-2.6\libsbml"

REM build python 2.7
rd /s /q "%SOURCE_32%\b32_
call "%SOURCE_32%\buildPython32.bat" "%PYTHON_27_32%" "%DEP_DIR_32%"
mkdir "%SOURCE_32%\build\lib.win32-2.7"
mkdir "%SOURCE_32%\build\lib.win32-2.7\libsbml"
copy  "%INIT2_FILE%" "%SOURCE_32%\build\lib.win32-2.7\libsbml\__init__.py"
move  "%SOURCE_32%\b32_\_libsbml.pyd" "%SOURCE_32%\build\lib.win32-2.7\libsbml"

rd /s /q "%SOURCE_32%\b64_
call "%SOURCE_32%\buildPython64.bat" "%PYTHON_27_64%" "%DEP_DIR_64%"
mkdir "%SOURCE_32%\build\lib.win-amd64-2.7"
mkdir "%SOURCE_32%\build\lib.win-amd64-2.7\libsbml"
copy "%INIT2_FILE%" "%SOURCE_32%\build\lib.win-amd64-2.7\libsbml\__init__.py"
move  "%SOURCE_32%\b64_\_libsbml.pyd" "%SOURCE_32%\build\lib.win-amd64-2.7\libsbml"


REM build python 3.2
REM rd /s /q "%SOURCE_32%\b32_
REM call "%SOURCE_32%\buildPython32.bat" "%PYTHON_32_32%" "%DEP_DIR_32%"
REM mkdir "%SOURCE_32%\build\lib.win32-3.2"
REM mkdir "%SOURCE_32%\build\lib.win32-3.2\libsbml"
REM copy  "%INIT3_FILE%" "%SOURCE_32%\build\lib.win32-3.2\libsbml\__init__.py"
REM move  "%SOURCE_32%\b32_\_libsbml.pyd" "%SOURCE_32%\build\lib.win32-3.2\libsbml"

REM rd /s /q "%SOURCE_32%\b64_
REM call "%SOURCE_32%\buildPython64.bat" "%PYTHON_32_64%" "%DEP_DIR_64%"
REM mkdir "%SOURCE_32%\build\lib.win-amd64-3.2"
REM mkdir "%SOURCE_32%\build\lib.win-amd64-3.2\libsbml"
REM copy "%INIT3_FILE%" "%SOURCE_32%\build\lib.win-amd64-3.2\libsbml\__init__.py"
REM move  "%SOURCE_32%\b64_\_libsbml.pyd" "%SOURCE_32%\build\lib.win-amd64-3.2\libsbml"

REM build python 3.3
rd /s /q "%SOURCE_32%\b32_
call "%SOURCE_32%\buildPython32.bat" "%PYTHON_33_32%" "%DEP_DIR_32%"
mkdir "%SOURCE_32%\build\lib.win32-3.3"
mkdir "%SOURCE_32%\build\lib.win32-3.3\libsbml"
copy  "%INIT3_FILE%" "%SOURCE_32%\build\lib.win32-3.3\libsbml\__init__.py"
move  "%SOURCE_32%\b32_\_libsbml.pyd" "%SOURCE_32%\build\lib.win32-3.3\libsbml"

rd /s /q "%SOURCE_32%\b64_
call "%SOURCE_32%\buildPython64.bat" "%PYTHON_33_64%" "%DEP_DIR_64%"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.3"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.3\libsbml"
copy "%INIT3_FILE%" "%SOURCE_32%\build\lib.win-amd64-3.3\libsbml\__init__.py"
move  "%SOURCE_32%\b64_\_libsbml.pyd" "%SOURCE_32%\build\lib.win-amd64-3.3\libsbml"

REM build python 3.4
rd /s /q "%SOURCE_32%\b32_
call "%SOURCE_32%\buildPython32.bat" "%PYTHON_34_32%" "%DEP_DIR_32%"
mkdir "%SOURCE_32%\build\lib.win32-3.4"
mkdir "%SOURCE_32%\build\lib.win32-3.4\libsbml"
copy  "%INIT3_FILE%" "%SOURCE_32%\build\lib.win32-3.4\libsbml\__init__.py"
move  "%SOURCE_32%\b32_\_libsbml.pyd" "%SOURCE_32%\build\lib.win32-3.4\libsbml"

rd /s /q "%SOURCE_32%\b64_
call "%SOURCE_32%\buildPython64.bat" "%PYTHON_34_64%" "%DEP_DIR_64%"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.4"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.4\libsbml"
copy "%INIT3_FILE%" "%SOURCE_32%\build\lib.win-amd64-3.4\libsbml\__init__.py"
move  "%SOURCE_32%\b64_\_libsbml.pyd" "%SOURCE_32%\build\lib.win-amd64-3.4\libsbml"

REM build python 3.5
rd /s /q "%SOURCE_32%\b32_
call "%SOURCE_32%\buildPython32.bat" "%PYTHON_35_32%" "%DEP_DIR_32%"
mkdir "%SOURCE_32%\build\lib.win32-3.5"
mkdir "%SOURCE_32%\build\lib.win32-3.5\libsbml"
copy  "%INIT3_FILE%" "%SOURCE_32%\build\lib.win32-3.5\libsbml\__init__.py"
move  "%SOURCE_32%\b32_\_libsbml.pyd" "%SOURCE_32%\build\lib.win32-3.5\libsbml"

rd /s /q "%SOURCE_32%\b64_
call "%SOURCE_32%\buildPython64.bat" "%PYTHON_35_64%" "%DEP_DIR_64%"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.5"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.5\libsbml"
copy "%INIT3_FILE%" "%SOURCE_32%\build\lib.win-amd64-3.5\libsbml\__init__.py"
move  "%SOURCE_32%\b64_\_libsbml.pyd" "%SOURCE_32%\build\lib.win-amd64-3.5\libsbml"

REM build python 3.6
rd /s /q "%SOURCE_32%\b32_
call "%SOURCE_32%\buildPython32.bat" "%PYTHON_36_32%" "%DEP_DIR_32%"
mkdir "%SOURCE_32%\build\lib.win32-3.6"
mkdir "%SOURCE_32%\build\lib.win32-3.6\libsbml"
copy  "%INIT3_FILE%" "%SOURCE_32%\build\lib.win32-3.6\libsbml\__init__.py"
move  "%SOURCE_32%\b32_\_libsbml.pyd" "%SOURCE_32%\build\lib.win32-3.6\libsbml"

rd /s /q "%SOURCE_32%\b64_
call "%SOURCE_32%\buildPython64.bat" "%PYTHON_36_64%" "%DEP_DIR_64%"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.6"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.6\libsbml"
copy "%INIT3_FILE%" "%SOURCE_32%\build\lib.win-amd64-3.6\libsbml\__init__.py"
move  "%SOURCE_32%\b64_\_libsbml.pyd" "%SOURCE_32%\build\lib.win-amd64-3.6\libsbml"

REM build python 3.7
rd /s /q "%SOURCE_32%\b32_
call "%SOURCE_32%\buildPython32.bat" "%PYTHON_37_32%" "%DEP_DIR_32%"
mkdir "%SOURCE_32%\build\lib.win32-3.7"
mkdir "%SOURCE_32%\build\lib.win32-3.7\libsbml"
copy  "%INIT3_FILE%" "%SOURCE_32%\build\lib.win32-3.7\libsbml\__init__.py"
move  "%SOURCE_32%\b32_\_libsbml.pyd" "%SOURCE_32%\build\lib.win32-3.7\libsbml"

rd /s /q "%SOURCE_32%\b64_
call "%SOURCE_32%\buildPython64.bat" "%PYTHON_37_64%" "%DEP_DIR_64%"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.7"
mkdir "%SOURCE_32%\build\lib.win-amd64-3.7\libsbml"
copy "%INIT3_FILE%" "%SOURCE_32%\build\lib.win-amd64-3.7\libsbml\__init__.py"
move  "%SOURCE_32%\b64_\_libsbml.pyd" "%SOURCE_32%\build\lib.win-amd64-3.7\libsbml"


:: 
:: copy files for anaconda
:: 
rd /s /q \Development\create-conda-stable\build
xcopy /y /S \Development\libsbml-32-inst-package\bindings\python\src\build \Development\create-conda-stable\build\
call \Development\create-conda-stable\create-conda-stable.bat python-libsbml-experimental
mkdir "c:\inetpub\wwwroot\Files\anaconda-32"
mkdir "c:\inetpub\wwwroot\Files\anaconda-64"
copy /y \Development\create-conda-stable\out\32\* "c:\inetpub\wwwroot\Files\anaconda-32"
copy /y \Development\create-conda-stable\out\64\* "c:\inetpub\wwwroot\Files\anaconda-64"

:: 
:: Create installers 
::
REM "%PYTHON_25_32%" setup32.py bdist_wininst --skip-build  --target-version="2.5" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_26_32%" setup32.py bdist_wininst --skip-build  --target-version="2.6" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_26_32%" setup32.py bdist_wheel --skip-build
"%PYTHON_27_32%" setup32.py bdist_wininst --skip-build  --target-version="2.7" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_27_32%" setup32.py bdist_wheel --skip-build
REM "%PYTHON_32_32%" setup32.py bdist_wininst --skip-build  --target-version="3.2" --bitmap libsbml-python-installer-graphic.bmp
REM "%PYTHON_32_32%" setup32.py bdist_wheel --skip-build
"%PYTHON_33_32%" setup32.py bdist_wininst --skip-build  --target-version="3.3" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_33_32%" setup32.py bdist_wheel --skip-build
"%PYTHON_34_32%" setup32.py bdist_wininst --skip-build  --target-version="3.4" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_34_32%" setup32.py bdist_wheel --skip-build
"%PYTHON_35_32%" setup32.py bdist_wininst --skip-build  --target-version="3.5" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_35_32%" setup32.py bdist_wheel --skip-build
"%PYTHON_36_32%" setup32.py bdist_wininst --skip-build  --target-version="3.6" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_36_32%" setup32.py bdist_wheel --skip-build
"%PYTHON_37_32%" setup32.py bdist_wininst --skip-build  --target-version="3.7" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_37_32%" setup32.py bdist_wheel --skip-build


REM dist utils fails to create the python 25 64bit installer
REM "%PYTHON_25_64%" setup64.py bdist_wininst --skip-build --target-version="2.5"
"%PYTHON_26_64%" setup64.py bdist_wininst --skip-build --target-version="2.6" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_26_64%" setup64.py bdist_wheel --skip-build
"%PYTHON_27_64%" setup64.py bdist_wininst --skip-build --target-version="2.7" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_27_64%" setup64.py bdist_wheel --skip-build
REM "%PYTHON_32_64%" setup64.py bdist_wininst --skip-build --target-version="3.2" --bitmap libsbml-python-installer-graphic.bmp
REM "%PYTHON_32_64%" setup64.py bdist_wheel --skip-build
"%PYTHON_33_64%" setup64.py bdist_wininst --skip-build --target-version="3.3" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_33_64%" setup64.py bdist_wheel --skip-build
"%PYTHON_34_64%" setup64.py bdist_wininst --skip-build --target-version="3.4" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_34_64%" setup64.py bdist_wheel --skip-build
"%PYTHON_35_64%" setup64.py bdist_wininst --skip-build --target-version="3.5" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_35_64%" setup64.py bdist_wheel --skip-build
"%PYTHON_36_64%" setup64.py bdist_wininst --skip-build --target-version="3.6" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_36_64%" setup64.py bdist_wheel --skip-build
"%PYTHON_37_64%" setup64.py bdist_wininst --skip-build --target-version="3.7" --bitmap libsbml-python-installer-graphic.bmp
"%PYTHON_37_64%" setup64.py bdist_wheel --skip-build


REM here we can test the new bindindgs
cd  /d %WIN_INST_DIR%
REM call "%WIN_INST_DIR%\testPython.bat" %PYTHON_25_32% %SOURCE_32%\build\lib.win32-2.5\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_26_32% %SOURCE_32%\build\lib.win32-2.6\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_27_32% %SOURCE_32%\build\lib.win32-2.7\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
REM call "%WIN_INST_DIR%\testPython.bat" %PYTHON_32_32% %SOURCE_32%\build\lib.win32-3.2\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_33_32% %SOURCE_32%\build\lib.win32-3.3\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_34_32% %SOURCE_32%\build\lib.win32-3.4\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_35_32% %SOURCE_32%\build\lib.win32-3.5\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_36_32% %SOURCE_32%\build\lib.win32-3.6\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_37_32% %SOURCE_32%\build\lib.win32-3.7\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python

REM call "%WIN_INST_DIR%\testPython.bat" %PYTHON_25_64% %SOURCE_32%\build\lib.win-amd64-2.5\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_26_64% %SOURCE_32%\build\lib.win-amd64-2.6\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_27_64% %SOURCE_32%\build\lib.win-amd64-2.7\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
REM call "%WIN_INST_DIR%\testPython.bat" %PYTHON_32_64% %SOURCE_32%\build\lib.win-amd64-3.2\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_33_64% %SOURCE_32%\build\lib.win-amd64-3.3\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_34_64% %SOURCE_32%\build\lib.win-amd64-3.4\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_35_64% %SOURCE_32%\build\lib.win-amd64-3.5\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_36_64% %SOURCE_32%\build\lib.win-amd64-3.6\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python
call "%WIN_INST_DIR%\testPython.bat" %PYTHON_37_64% %SOURCE_32%\build\lib.win-amd64-3.7\ %LIBSBML_PACKAGE_ROOT%\src\bindings\python


REM Copy binaries 


REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1.win32-py2.5.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py2.5-packages-x86.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win32-py2.6.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py2.6-packages-x86.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win32-py2.7.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py2.7-packages-x86.exe"
REM copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win32-py3.2.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.2-packages-x86.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win32-py3.3.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.3-packages-x86.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win32-py3.4.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.4-packages-x86.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win32-py3.5.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.5-packages-x86.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win32-py3.6.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.6-packages-x86.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win32-py3.7.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.7-packages-x86.exe"

copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win-amd64-py2.6.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py2.6-packages-amd64.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win-amd64-py2.7.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py2.7-packages-amd64.exe"
REM copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win-amd64-py3.2.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.2-packages-amd64.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win-amd64-py3.3.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.3-packages-amd64.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win-amd64-py3.4.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.4-packages-amd64.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win-amd64-py3.5.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.5-packages-amd64.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win-amd64-py3.6.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.6-packages-amd64.exe"
copy /y "%SOURCE_32%\dist\python-libsbml-experimental-5.17.1.win-amd64-py3.7.exe" "c:\inetpub\wwwroot\Files\libSBML-5.17.1-win-py3.7-packages-amd64.exe"

REM Copy wheels to outdir\wheels-experimental
mkdir "c:\inetpub\wwwroot\Files\wheels-experimental"
copy /y "%SOURCE_32%\dist\*.whl" "c:\inetpub\wwwroot\Files\wheels-experimental"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp27-cp27m-win_amd64.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp27-cp27m-win_amd64.whl"  
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp27-cp27m-win32.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp27-cp27m-win32.whl" 
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp33-cp33m-win_amd64.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp33-cp33m-win_amd64.whl"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp33-cp33m-win32.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp33-cp33m-win32.whl"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp34-cp34m-win_amd64.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp34-cp34m-win_amd64.whl"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp34-cp34m-win32.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp34-cp34m-win32.whl"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp35-cp35m-win_amd64.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp35-cp35m-win_amd64.whl"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp35-cp35m-win32.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp35-cp35m-win32.whl"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp36-cp36m-win_amd64.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp36-cp36m-win_amd64.whl"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp36-cp36m-win32.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp36-cp36m-win32.whl"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp37-cp37m-win_amd64.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp37-cp37m-win_amd64.whl"
REM copy /y "%SOURCE_32%\dist\libsbml-5.17.1-cp37-cp37m-win32.whl" "c:\inetpub\wwwroot\Files\wheels-experimental\python-libsbml-experimental-5.17.1-cp37-cp37m-win32.whl" 


:echo BRETT DEBUG
:echo "%WIN_INST_DIR%"
:echo "%WIN_INST_DIR%\buildPython32.bat" %SOURCE_32%
:echo "%WIN_INST_DIR%\buildPython64.bat" %SOURCE_32%
:echo "%WIN_INST_DIR%\python\setup32.py" %SOURCE_32%
:echo "%WIN_INST_DIR%\python\setup64.py" %SOURCE_32%
:echo "%SOURCE_32%\buildPython32.bat" "%PYTHON_27_32%" "%DEP_DIR_32%"
:echo "%SOURCE_32%\buildPython64.bat" "%PYTHON_27_64%" "%DEP_DIR_64%"
:echo BRETT DEBUG
:goto ALL_DONE



goto ALL_DONE

:MISSING_DEPENDENCIES
echo.
echo Please ensure, that libsbml, has been build prior to running
echo this script it is assumed that the following conditions are
echo met: 
echo   build dir exists: %BUILD_DIR_32_BIT%
echo   32bit install dir exists: %INSTALL_DIR_32%
echo   64bit install dir exists: %INSTALL_DIR_64%
echo. 
echo Please run the buildAll.bat file again. 
echo. 
goto ALL_DONE

:ALL_DONE
cd  /d %WIN_INST_DIR%
