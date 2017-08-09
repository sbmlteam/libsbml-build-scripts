# rule src archive build

Log in to rule via ssh as: frank@rule.caltech.edu 
Rule uses franks dropbox account and synchronizes the sbmlteam-libsbml-dist directory. 
First create the libsbml gnumake source, by running ~/Dropbox/sbmlteam-libsbml-dist/buildGnuSource.sh (as always it has a VERSION variable that would be good to update, otherwise some files might be left behind)
Once that script is done, the latest gnumake source (and mac*txt log files) are placed in ~/out_dir
The next step is to test the gnu source archive. Does it contain all needed files? Especially is it able to create another source archive (that is the test that shows that all new files have been properly registered in the Makefile.in files). 
If all that is OK, copy the libsbml-VERSION-src* file into ~/Dropbox/sbmlteam-libsbml-dist/VERSION. 
At that point create the accepted and experimental folder in ~/Dropbox/sbmlteam-libsbml-dist/VERSION. And upload all the package zip files into the proper folders. 
Now back on the mac update the VERSION attribute in ~/Dropbox/sbmlteam-libsbml-dist/buildLibSBMLPackages.sh and run it. This will create the individual source packages (also in the ~/frank/out_dir directory). If you are happy with them, then copy them also into sbmlteam-libsbml-dist/VERSION

