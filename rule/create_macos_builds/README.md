# Create macos builds

## PREREQUISITES

None

## RUN

1. Create the stable build using ./run_build.sh - **WARNING this scripts deletes any code previously installed in the installer directory**
2. Go to common/mac_installer/installer and create the dmg before doing the next bit
3. Create the experimental build using ./run_build_experimental.sh - **WARNING this scripts deletes any code previously installed in the installer directory**


## RESULT

The build is created and installed into the common/mac_installer/installer/libsbml-dist directory.

## Suggested improvements

Add running the installer script and moving the dmg into the above.
