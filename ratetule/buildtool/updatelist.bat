@echo off
SET THIS_DIR=%~dp0
pushd %THIS_DIR%
grep "tests failed" test_log32.txt > overview.txt
grep "tests failed" test_log32p.txt >> overview.txt
grep "tests failed" test_log64.txt >> overview.txt
grep "tests failed" test_log64p.txt >> overview.txt

copy /y %THIS_DIR%\build_log.txt C:\inetpub\wwwroot\Files
copy /y %THIS_DIR%\overview.txt C:\inetpub\wwwroot\Files

echo "Update" > C:\inetpub\wwwroot\Files\UpdateNow