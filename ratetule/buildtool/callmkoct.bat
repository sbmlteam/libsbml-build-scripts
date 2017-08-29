@echo off
echo call is: 
echo \cygwin\bin\bash \cygwin\bin\mkoctfile %*

SET PATH=C:\Octave\3.2.4_gcc-4.4.0\bin;C:\Octave\3.2.4_gcc-4.4.0\mingw32\bin;%PATH%
mkoctfile %*
