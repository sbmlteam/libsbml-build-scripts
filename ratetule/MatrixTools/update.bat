@echo off 
SET THIS_DIR=%~dp0
pushd %THIS_DIR%
pushd bin
DownloadFormSubmissions -o ..\out
popd
bin\CreateMatrix.exe out\matrix.csv out\softwarematrix.xml

echo copy files to the server
copy /y out\*.* C:\inetpub\wwwroot\Facilities\RecoverSurveyURL\data\

popd