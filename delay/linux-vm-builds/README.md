# Linux VM


##Important Note

**Do not shut the machines down, suspend always (pause button)**

**Do not update vmware tools (these old operating systems are no longer supported)**
##What OSes are used ? 

Ubuntu 8.08 32 / 64 bit
This OS is no longer supported, no more updates to be expected
Centos 5.11 32/64 bit 
This OS is still supported, updates can be installed via sudo yum -y update. 


These machines have since been copied onto delay.caltech.edu into: 

c:\Virtual Machines. 

Those machines can be run using the installed vmware player. (Note that these machines are quite old, and not really supported well by the newer VMware Player, so sometimes network issues and or shared folder issues occur). 

##Shared folder
Generally these VM’s have shared folders setup so that when they have been launched, one can simply run a script from that directory, which will create the binaries and copy them over. The shared folder is located in: 

C:\vm-share and contains the build scripts: 




- createBuild5.sh: this will create the build directly from the libSBML SVN located. The only thing in this script that should need updating is the VERSION variable that should have the latest VERSION information. (and of course when new packages are accepted these need to be enabled as well). After the script is run, the linux binary archive + deb (ubuntu) / rpm (centos) along with the build logs are in vm-share/32 or vm-share/64 as appropriate. 


- createPackageBuild.sh: this script will create a new build from a libSBML cd Depackage source archive placed into the vm-share folder. For that you first edit the dlsfile and update the VERSION variable and then copy the libSBML-VERSION-Source.tar.gz next to it. Next you check, that the correct cd packages are enabled. Otherwise this script is again run from the Development directory.  After the script is run, the linux binary archive + deb (ubuntu) / rpm (centos) along with the build logs are in vm-share/32 or vm-share/64 as appropriate. 


- createMatlab.sh: this script creates the matlab bindings. It is supposed to be run from the ubuntu vms only, as they are setup with matlab already. This script updates the libsbml directory (from SVN) and then builds only the matlab bindings, tests them and copies logs and binaries into vm-share/32 or vm-share/64 as appropriateLaunch VMware player and launch the machine you would like to run

##Creating builds


- To create a new libsbml build from svn trunk, open a new Terminal and run: 
cd ~/Development
/mnt/hgfs/share/createBuild5.shf


- To create a package build, ensure the source archive has been placed into c:\vm-share and that the VERSION variable in createPackageBuild.sh has been updated then run
cd ~/Development
/mnt/hgfs/share/createPackageBuild.sh

