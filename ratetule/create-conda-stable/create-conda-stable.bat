@echo off 
Setlocal EnableDelayedExpansion
SET THIS_DIR=%~dp0
pushd %THIS_DIR%

del /q %THIS_DIR%\out\64\*
del /q %THIS_DIR%\out\32\*

SET NAME=python-libsbml
if not "%1" == "" SET NAME=%1

cmake -DSRC_DIR=c:\Development\libsbml -DBUILD_DIR=%THIS_DIR%\build\lib.win-amd64-3.6 -DOUT_DIR=%THIS_DIR%\out\64 -DNAME=%NAME% -P create-conda-archives.cmake
cmake -DSRC_DIR=c:\Development\libsbml -DBUILD_DIR=%THIS_DIR%\build\lib.win32-3.6 -DOUT_DIR=%THIS_DIR%\out\32 -DNAME=%NAME% -P create-conda-archives.cmake
cmake -DSRC_DIR=c:\Development\libsbml -DBUILD_DIR=%THIS_DIR%\build\lib.win-amd64-3.5 -DOUT_DIR=%THIS_DIR%\out\64 -DNAME=%NAME% -P create-conda-archives.cmake
cmake -DSRC_DIR=c:\Development\libsbml -DBUILD_DIR=%THIS_DIR%\build\lib.win32-3.5 -DOUT_DIR=%THIS_DIR%\out\32 -DNAME=%NAME% -P create-conda-archives.cmake
cmake -DSRC_DIR=c:\Development\libsbml -DBUILD_DIR=%THIS_DIR%\build\lib.win-amd64-3.3 -DOUT_DIR=%THIS_DIR%\out\64 -DNAME=%NAME% -P create-conda-archives.cmake
cmake -DSRC_DIR=c:\Development\libsbml -DBUILD_DIR=%THIS_DIR%\build\lib.win32-3.3 -DOUT_DIR=%THIS_DIR%\out\32 -DNAME=%NAME% -P create-conda-archives.cmake
cmake -DSRC_DIR=c:\Development\libsbml -DBUILD_DIR=%THIS_DIR%\build\lib.win-amd64-2.7 -DOUT_DIR=%THIS_DIR%\out\64 -DNAME=%NAME% -P create-conda-archives.cmake
cmake -DSRC_DIR=c:\Development\libsbml -DBUILD_DIR=%THIS_DIR%\build\lib.win32-2.7 -DOUT_DIR=%THIS_DIR%\out\32 -DNAME=%NAME% -P create-conda-archives.cmake
popd
