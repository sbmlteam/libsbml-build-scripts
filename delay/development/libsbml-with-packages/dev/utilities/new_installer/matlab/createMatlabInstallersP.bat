@echo off
REM 
REM  Simple build script to create the matlab installers it just 
REM  calls createInstallFiles with the defaults used by the one
REM  click installer. 
REM 

SET MATLAB_INST_DIR=%~dp0

SET LIBSBML_ROOT=c:\Development\libsbml-with-packages
SET DEPENDENCIES_32_BIT=c:\Development\dependencies\x86\release-static
SET MATLAB_INSTALLER_DIR=%MATLAB_INST_DIR%\Output
cd /d %MATLAB_INST_DIR%

SET COMPILER=c:\Program Files (x86)\Inno Setup 5\ISCC.exe

call createInstallFilesP.bat 32 c:\Development\libsbml-32-inst-package -silent
"%COMPILER%" install_matlab_libsbml_script_xml_win32.iss

call createInstallFilesP.bat 64 c:\Development\libsbml-64-inst-package -silent
"%COMPILER%" install_matlab_libsbml_script_xml_win64.iss


cd /d %MATLAB_INST_DIR%

