@echo off
SET BUILDTOOL_DIR=%~dp0
SETLOCAL ENABLEDELAYEDEXPANSION 
SET CL=/MP

cd /d %BUILDTOOL_DIR%

echo Starting new Build (Installer): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -i >> build_log.txt

echo Starting new Matlab Packaging: %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -pm  >> build_log.txt

cd /d %BUILDTOOL_DIR%
echo Update R: %date% %time% >> build_log.txt
call updateR.bat  >> build_log.txt

cd /d %BUILDTOOL_DIR%

call updatelist.bat

