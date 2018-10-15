@echo off
SET BUILDTOOL_DIR=%~dp0
SETLOCAL ENABLEDELAYEDEXPANSION 

cd /d %BUILDTOOL_DIR%

echo Starting new Build: %date% %time% > build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -u -py -ppy -i >> build_log.txt

echo Running tests: %date% %time% >> build_log.txt
call run_tests.bat

echo Completed build and tests: %date% %time% >> build_log.txt

copy /y build_log.txt C:\inetpub\wwwroot\Files

cd /d %BUILDTOOL_DIR%

call updatelist.bat

