# Setting up an Ubuntu 16.04 64 bit build environment for libSBML

## Setup build environment

Start with a default install of Ubuntu 16.04.6 or newer and grab some build tools 

 sudo apt-get -y install git subversion build-essential g++ gfortran
 
If running on a VirtualBox VM this is a good time to install the guest extensions.
Continue with more build tools and libSBML dependencies.
 
 sudo apt-get -y install python python-all-dev python3-all-dev python-xlsxwrite python3-xlsxwrite
 
 sudo apt-get -y install cmake cmake-gui p7zip swig check mc scite
 
 sudo apt-get -y install libxml2 libxml2-dev libxslt-dev zlib1g zlib1g-dev bzip2 libbz2-dev
 
 sudo apt-get -y install libexpat-dev libxerces-c-dev libcurl4-openssl-dev
 
 sudo apt-get -y install bzr p7zip mercurial ninja-build curl
 
These following adds support for compiling libSBML bindings (Python, R, Java, Ruby, Perl)
 
 sudo apt-get -y install r-base default-jdk mono-complete ruby ruby-dev perl libperl-dev 
 
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


# Unresolved issues and bindings that need to be resolved

Build and install node-v0.12.0.tar.gz with
 ./configure
 make
 make test
 sudo make install
  
# sudo apt-get -y install libapache2-mod-php php php-dev
# sudo apt-get -y install octave octave-pkg-dev


Package dependency issues, so unable to install completely::

 sudo apt-get -y install slurm slurm-wlm

### This should be done automagically by cmake configure

If you use the distro check library as installed above then you also need to add the
following to the cmake EXTRA_LIBS configuration::

(GCC)   EXTRA_LIBS: -lrt -lpthread -lsubunit
(CLANG) EXTRA_LIBS: -lpthread -lsubunit -lrt 

Brett G. Olivier, Amsterdam, The Netherlands 2019. This work is licensed under a Creative Commons Attribution 4.0 International License.
