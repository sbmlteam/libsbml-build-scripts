# Create source archives

## PREREQUISITES

1. The package archives should be created using Delay: create package archives.

## RUN

From the frank home directory run

1. ~/gitrepo/libsbml-build-scripts/rule/buildGnuSource.sh This creates a source archive and puts it into the ~/out_dir directory.
2. Test the created archive.
3. Run ~/gitrepo/libsbml-build-scripts/rule/buildLibsbmlPackages.sh VERSION_NO

## RESULT

The first script builds a src archive which should be tested. The second script does all teh copying/creating necessary. The final 6 src archives are placed in the appropriate dropbox directory. 
