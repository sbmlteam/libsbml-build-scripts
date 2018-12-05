::
:: This script extracts the created python installers from the in dir,
:: adds the files from the extra dir, reconfigures the setup.py files
:: and repackages the files.
::
:: author: fbergman@caltech.edu
::
:: Required software: cmake, tar
::
:: Usage: simply copy generated files into the 'in' directory, modify the
::        DEFAULT_VERSION variable below (or pass in the version via the
::        first argument to the batch script.
::
::
@echo off
SET CURRENT_DIR=%~dp0
SET DEFAULT_VERSION=5.17.0
SET CMAKE=cmake


:: allow version to be overridden via command line argument

SET VERSION=%1
if [%1] == [] SET VERSION=%DEFAULT_VERSION%

pushd %CURRENT_DIR%

echo Version is: %VERSION%

:: check for input archives:
:: IF NOT EXIST in\python-libsbml-%VERSION%.tar.gz goto MISSING
IF NOT EXIST in\python-libsbml-experimental-%VERSION%.tar.gz goto MISSING


:: extract input archives
echo extract archives
::tar zxf in\python-libsbml-%VERSION%.tar.gz
tar zxf in\python-libsbml-experimental-%VERSION%.tar.gz

:: add additional files
:: and modify setup.py script
echo modify files
%CMAKE% -DSRC_DIR="." -DLIBSBML_VERSION=%VERSION% -P create_package_exp.cmake



:: finally create new archives
echo create new archives
:: tar -czf python-libsbml-%VERSION%.tar.gz python-libsbml-%VERSION%
tar -czf python-libsbml-experimental-%VERSION%.tar.gz python-libsbml-experimental-%VERSION%

:: move files away
echo move archives
move /Y *.tar.gz out > NUL

:: clean up
echo remove extracted files
:: rd /s /q python-libsbml-%VERSION%
rd /s /q python-libsbml-experimental-%VERSION%

goto DONE

:MISSING
echo.
echo the required files:
echo.
echo    in\python-libsbml-%VERSION%.tar.gz and/or
echo    in\python-libsbml-experimental-%VERSION%.tar.gz
echo.
echo are not present, please copy them in to the in dir first.
echo.
:DONE
echo DONE
popd
