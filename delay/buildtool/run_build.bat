
@echo off
SET BUILDTOOL_DIR=%~dp0
SETLOCAL ENABLEDELAYEDEXPANSION 
SET CL=/MP

cd /d %BUILDTOOL_DIR%

call deleteBindings.bat

echo Starting new build: %date% %time%

echo Starting new Build (update): %date% %time% > build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -u >> build_log.txt

echo Starting new Build (32 bit build): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -32 >> build_log.txt

echo Starting new Build (64 bit build): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -64 >> build_log.txt

echo Starting new Build (32 bit package build): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -p32 >> build_log.txt

echo Starting new Build (64 bit package build): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -p64 >> build_log.txt

echo Starting new Python Package build: %date% %time%

echo Starting new Build (Python builds): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -py >> build_log.txt

echo Starting new Build (Python package builds): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -ppy >> build_log.txt

echo Starting new installer build: %date% %time%

echo Starting new Build (Installer): %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -i >> build_log.txt

echo Starting new MATLAB installer build: %date% %time%

echo Starting new Matlab Packaging: %date% %time% >> build_log.txt
%BUILDTOOL_DIR%\LibSBMLBuild.exe -f %BUILDTOOL_DIR%\libsbml.setting -pm  >> build_log.txt

echo Starting new R installer build: %date% %time%

cd /d %BUILDTOOL_DIR%
echo Update R: %date% %time% >> build_log.txt
call updateR.bat  >> build_log.txt

echo Running tests: %date% %time%

cd /d %BUILDTOOL_DIR%
echo Running tests: %date% %time% >> build_log.txt
call run_tests.bat

echo Completed build and tests: %date% %time% >> build_log.txt

copy /y build_log.txt C:\inetpub\wwwroot\Files

cd /d %BUILDTOOL_DIR%

call updatelist.bat

echo Completed build and tests: %date% %time%
call copy_to_surfdrive.bat
