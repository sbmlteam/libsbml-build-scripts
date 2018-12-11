@echo off
SET THIS_DIR=%~dp0
pushd %THIS_DIR%

robocopy /e /purge c:\inetpub\wwwroot\Files c:\Users\brett\Dropbox\sbml\sbmlteam-libsbml-dist\delay_build\Files

:copy /y C:\inetpub\wwwroot\Files\test_log32.txt C:\Users\brett\Dropbox\sbml\sbmlteam-libsbml-dist\delay_build_logs
:copy /y C:\inetpub\wwwroot\Files\test_log32p.txt C:\Users\brett\Dropbox\sbml\sbmlteam-libsbml-dist\delay_build_logs
:copy /y C:\inetpub\wwwroot\Files\test_log64.txt C:\Users\brett\Dropbox\sbml\sbmlteam-libsbml-dist\delay_build_logs
:copy /y C:\inetpub\wwwroot\Files\test_log64p.txt C:\Users\brett\Dropbox\sbml\sbmlteam-libsbml-dist\delay_build_logs
:copy /y C:\inetpub\wwwroot\Files\build_log.txt C:\Users\brett\Dropbox\sbml\sbmlteam-libsbml-dist\delay_build_logs
:copy /y C:\inetpub\wwwroot\Files\overview.txt C:\Users\brett\Dropbox\sbml\sbmlteam-libsbml-dist\delay_build_logs

