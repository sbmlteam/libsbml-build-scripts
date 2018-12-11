@echo off
Setlocal EnableDelayedExpansion
SET BASE_DIR=%~dp0

SET VS_VERSION=14
SET VS_PREFIX=vs%VS_VERSION%
SET VS=%ProgramFiles(x86)%\Microsoft Visual Studio %VS_VERSION%.0\VC
SET VSDIR=%VS%\bin
echo "%VS%\vcvarsall.bat" %*
"%VS%\vcvarsall.bat" %*
