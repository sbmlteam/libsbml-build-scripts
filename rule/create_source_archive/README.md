# Create source archives

## PREREQUISITES

1. These scripts assume that the libSBML svn branch is checked out in home/Development/libsbml_gnumake.
2. The package archives should be created using Delay: create package archives.

## RUN

From the frank home directory run

1. ~/gitrepo/libsbml-build-scripts/rule/create\_source\_archive/buildGnuSource.sh This creates a source archive and puts it into the ~/out_dir directory.
2. Test the created archive.
3. Run ~/gitrepo/libsbml-build-scripts/rule/create\_source\_archive/buildLibsbmlPackages.sh VERSION_NO

## RESULT

The first script builds a src archive which should be tested. The second script does all the copying/creating necessary. The final 6 src archives are placed in the appropriate dropbox directory. 
