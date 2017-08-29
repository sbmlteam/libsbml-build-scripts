@echo off

del c:\Development\libsbml\dev\utilities\new_installer\Output\*.exe
del c:\Development\libsbml\dev\utilities\new_installer\matlab\Output\*.exe
del c:\Development\libsbml-with-packages\dev\utilities\new_installer\matlab\Output\*.exe

SET DIR=C:\Development\libsbml-32
pushd %DIR%
rd /s /q %DIR%\src\bindings\csharp\csharp-files
rd /s /q %DIR%\src\bindings\java\java-files
del /s /q libsbml_wrap.cpp
del /s /q *.jar 
popd 

SET DIR=C:\Development\libsbml-32-packages
pushd %DIR%
rd /s /q %DIR%\src\bindings\csharp\csharp-files
rd /s /q %DIR%\src\bindings\java\java-files
del /s /q libsbml_wrap.cpp
del /s /q *.jar 
popd 


SET DIR=C:\Development\libsbml-64
pushd %DIR%
rd /s /q %DIR%\src\bindings\csharp\csharp-files
rd /s /q %DIR%\src\bindings\java\java-files
del /s /q libsbml_wrap.cpp
del /s /q *.jar 
popd 

SET DIR=C:\Development\libsbml-64-packages
pushd %DIR%
rd /s /q %DIR%\src\bindings\csharp\csharp-files
rd /s /q %DIR%\src\bindings\java\java-files
del /s /q libsbml_wrap.cpp
del /s /q *.jar 
popd 