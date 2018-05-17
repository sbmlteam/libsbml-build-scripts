@echo off

SET BASE_DIR=%~dp0
echo %BASE_DIR%

if "%~1"=="" GOTO NO_VERSION_NO

SET THIS_VERSION=%1

SET VM_SHARE_DIR=C:\vm-share
SET SRC_ARCHIVE=C:\Dropbox\sbmlteam-libsbml-dist\%THIS_VERSION%\libSBML-%THIS_VERSION%-Source.tat.gz
 
cd VM_SHARE_DIR

rem delete previous files
del Translate*
del Output*
del libSBML-5*.tar.gz
deltree 32 /y
deltree 64 /y

rem update svn
cd libsbml
svn up
cd ..
cd libsbml-experimental
svn up
cd ..

rem copy source archive
copy /y %SRC_ARCHIVE% .

GOTO DONE

:NO_VERSION_NO
echo Need a version number

:DONE

SET SRC_ARCHIVE=
SET VERSION=

echo vm-share dir complete