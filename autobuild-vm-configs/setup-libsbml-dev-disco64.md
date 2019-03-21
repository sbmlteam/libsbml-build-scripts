# Setting up an Ubuntu 19.04 64 bit build environment for libSBML

## Setup build environment

Start with a default install of Ubuntu 19.04 and grab some build tools 

 sudo apt-get -y install git subversion build-essential g++ gfortran
 
If running on a VirtualBox VM this is a good time to install the guest extensions.
Continue with more build tools and libSBML dependencies.

# Setting up an Ubuntu 16.04 64 bit build environment for libSBML

 sudo apt-get -y install python python-all-dev python3-all-dev 
 
 sudo apt-get -y install cmake cmake-gui p7zip swig check mc scite
 
 sudo apt-get -y install libxml2 libxml2-dev libxslt-dev zlib1g zlib1g-dev bzip2 libbz2-dev
 
 sudo apt-get -y install libexpat-dev libxerces-c-dev libcurl4-openssl-dev
 
 sudo apt-get -y install bzr p7zip mercurial ninja-build curl
 
These following adds support for compiling libSBML bindings (Python, R, Java, Ruby, Perl)
 
 sudo apt-get -y install r-base default-jdk mono-complete ruby ruby-dev perl libperl-dev 

These extra Python packages are rquired for fancy report generation and gneral python haappiness

  sudo apt-get -y install ipython ipython3 python-pip python3-pip python-xlsxwriter python3-xlsxwriter
  
## Getting the libSBML source code and configuration files

All building is assumed to take place in ~/development

 cd ~
 mkdir development
 cd development

Checkout the libSBML build-scripts

 svn checkout https://svn.code.sf.net/p/sbml/code/trunk/libsbml sf_libsbml
 
 svn checkout https://svn.code.sf.net/p/sbml/code/branches/libsbml-experimental sf_libsbml_experimental
 
Clone the libSBML build-scripts repository and checkout the automatic build configuration tools.

 git clone https://github.com/sbmlteam/libsbml-build-scripts.git
 
 cd libsbml-build-scripts
 
 git checkout auto-build-options
 
 cd autobuild-option-tests

Brett G. Olivier, Amsterdam, The Netherlands 2019. This work is licensed under a Creative Commons Attribution 4.0 International License.



















