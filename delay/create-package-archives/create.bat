@echo off

SET BASE_DIR=%~dp0
echo %BASE_DIR%

if "%~1"=="" GOTO NO_VERSION_NO

SET THIS_VERSION=%1


SET LIBSBML_SRC_DIR=C:\Development\libsbml-src-32\dev\packages\create_archives
SET LIBSBML_EXPER_SRC_DIR=C:\Development\libsbml-experimental-src-32\dev\packages\create_archives
SET DROPBOX_DIR=C:\Dropbox\sbmlteam-libsbml-dist\%THIS_VERSION%

cd %LIBSBML_SRC_DIR%
del *.zip

SET VERSION=%THIS_VERSION%
CALL create-zip-comp.bat %VERSION%
SET VERSION=%THIS_VERSION%
CALL create-zip-fbc.bat %VERSION%
SET VERSION=%THIS_VERSION%
CALL create-zip-groups.bat %VERSION%
SET VERSION=%THIS_VERSION%
CALL create-zip-multi.bat %VERSION%
SET VERSION=%THIS_VERSION%
CALL create-zip-qual.bat %VERSION%

cd %LIBSBML_EXPER_SRC_DIR%
del *.zip

SET VERSION=%THIS_VERSION%
CALL create-zip-arrays.bat %VERSION%
SET VERSION=%THIS_VERSION%
CALL create-zip-distrib.bat %VERSION%
SET VERSION=%THIS_VERSION%
CALL create-zip-dyn.bat %VERSION%
SET VERSION=%THIS_VERSION%
CALL create-zip-render.bat %VERSION%
SET VERSION=%THIS_VERSION%
CALL create-zip-req.bat %VERSION%
SET VERSION=%THIS_VERSION%
CALL create-zip-spatial.bat %VERSION%


cd %DROPBOX_DIR%
mkdir accepted
mkdir experimental

copy /y %LIBSBML_SRC_DIR%\*.zip accepted\*.zip
copy /y %LIBSBML_EXPER_SRC_DIR%\*.zip experimental\*.zip


GOTO DONE

:NO_VERSION_NO
echo Need a version number

:DONE
cd %BASE_DIR%

SET BASE_DIR=
SET VERSION=
SET LIBSBML_SRC_DIR=
SET LIBSBML_EXPER_SRC_DIR=