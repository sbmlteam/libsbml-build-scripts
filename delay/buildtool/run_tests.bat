@echo off 
SET ORIGPATH=%PATH%
SET BUILDTOOL_DIR=%~dp0

SETLOCAL ENABLEDELAYEDEXPANSION 

SET PATH=c:\Development\libsbml-32-inst\win32\bin;%ORIGPATH%
cd /d C:\Development\libsbml-32
echo Starting Tests: %date% %time% > %BUILDTOOL_DIR%\test_log32.txt
ctest -V -C Release >> %BUILDTOOL_DIR%\test_log32.txt
echo Finished Tests: %date% %time% >> %BUILDTOOL_DIR%\test_log32.txt
copy /y %BUILDTOOL_DIR%\test_log32.txt  C:\inetpub\wwwroot\Files
del /Q "%TEMP%\check*"

SET PATH=c:\Development\libsbml-32-inst-package\win32\bin;%ORIGPATH%
cd /d C:\Development\libsbml-32-packages
echo Starting Tests: %date% %time% > %BUILDTOOL_DIR%\test_log32p.txt
ctest -V -C Release >> %BUILDTOOL_DIR%\test_log32p.txt
echo Finished Tests: %date% %time% >> %BUILDTOOL_DIR%\test_log32p.txt
copy /y %BUILDTOOL_DIR%\test_log32p.txt  C:\inetpub\wwwroot\Files
del /Q "%TEMP%\check*"


SET PATH=C:\Development\libsbml-64-inst\bin;%ORIGPATH%
cd /d C:\Development\libsbml-64
echo Starting Tests: %date% %time% > %BUILDTOOL_DIR%\test_log64.txt
ctest -V -C Release >> %BUILDTOOL_DIR%\test_log64.txt
echo Finished Tests: %date% %time% >> %BUILDTOOL_DIR%\test_log64.txt
copy /y %BUILDTOOL_DIR%\test_log64.txt  C:\inetpub\wwwroot\Files
del /Q "%TEMP%\check*"

SET PATH=C:\Development\libsbml-64-inst-package\bin;%ORIGPATH%
cd /d C:\Development\libsbml-64-packages
echo Starting Tests: %date% %time% > %BUILDTOOL_DIR%\test_log64p.txt
ctest -V -C Release >> %BUILDTOOL_DIR%\test_log64p.txt
echo Finished Tests: %date% %time% >> %BUILDTOOL_DIR%\test_log64p.txt
copy /y %BUILDTOOL_DIR%\test_log64p.txt  C:\inetpub\wwwroot\Files
del /Q "%TEMP%\check*"

