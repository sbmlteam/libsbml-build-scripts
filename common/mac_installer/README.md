# Mac Installer

## PREREQUISITES

1. The mac build has been done and installed into the installer/libsbml-dist folder.
2. The create.sh file has been updated for any recent Mac OS updates.
3. The uninstall-libsbml-pkg.sh file has been updated to ensure all files are listed; particularly any version specific files.

## RUN

1. From mac\_installer/installer directory run ./create.sh version_no
2. Copy to dropbox

## RESULT

The relevant dmg file is created

## Suggested improvements

1. Automate creation/update of the uninstall-libsbml-pkg file
2. Add copying files into a script