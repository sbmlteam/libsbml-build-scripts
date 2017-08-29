@echo off
cd /d C:\Development\libsbml-64\src\bindings\r\
del /s /q *.zip
cd /d C:\Development\libsbml-32-packages\src\bindings\r\
del /s /q *.zip
cd /d C:\Development\libsbml-64-packages\src\bindings\r\
del /s /q *.zip
cd /d C:\Development\libsbml-32\src\bindings\r\
del /s /q *.zip

del /s /q C:\Development\compile-r\3.1.1\*.zip
pushd C:\Development\compile-r
call "createV3.bat"
move 3.1.1\*.zip C:\inetpub\wwwroot\Files\R
popd 

del /s /q C:\Development\compile-r-experimental\3.1.1\*.zip
pushd C:\Development\compile-r-experimental
call "createV3.bat"
move 3.1.1\*.zip C:\inetpub\wwwroot\Files\R_package
popd 

