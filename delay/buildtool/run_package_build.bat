@echo off
SET BUILDTOOL_DIR=%~dp0
SETLOCAL ENABLEDELAYEDEXPANSION 
SET CL=/MP

cd /d %BUILDTOOL_DIR%

::call deleteBindings.bat

echo Starting new Build (update): %date% %time% > build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -u >> build_log.txt

echo Starting new Build (32 bit package build): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -p32 >> build_log.txt

echo Starting new Build (64 bit package build): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -p64 >> build_log.txt

echo Starting new Build (Python package builds): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -ppy >> build_log.txt

copy /y build_log.txt C:\inetpub\wwwroot\Files

cd /d %BUILDTOOL_DIR%

call updatelist.bat

