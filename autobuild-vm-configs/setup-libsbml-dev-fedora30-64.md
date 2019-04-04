# Setting up an Fedora 30 64 bit build environment for libSBML

## Setup build environment

Start with a default install of Fedora 30 or newer and grab some build tools 

  sudo yum install -y kernel-headers kernel-devel 
  
  sudo yum install -y gcc make autoconf cmake cmake-gui gcc-c++ swig
  
  sudo yum install -y mc subversion git

 
If running on a VirtualBox VM this is a good time to install the guest extensions.
Continue with more build tools and libSBML dependencies.
 
 
 sudo yum install -y libcurl libcurl-devel libxml2 libxml2-devel check check-devel bzip2 bzip2-devel
 
 sudo yum install -y expat expat-devel xerces-c xerces-c-devel curl curl-devel
 
 sudo yum install -y bzr p7zip ninja-build
 


  
These following adds support for compiling libSBML bindings (Python, Perl, Java, Ruby, R, Mono)
 
 sudo yum install -y python-devel python3-devel perl perl-devel java-openjdk
 
 sudo yum install -y ruby ruby-devel R R-devel mono-core

 
These extra Python packages are rquired for fancy report generation and gneral python haappiness

  sudo yum install -y ipython3 python-pip python3-pip python3-xlsxwriter
  
Install Visual Studio Code (optional)

 https://code.visualstudio.com/docs/setup/linux

 
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


 sudo apt-get -y install libapache2-mod-php php php-dev
 sudo apt-get -y install octave octave-pkg-dev


Package dependency issues, so unable to install completely::

 sudo apt-get -y install slurm slurm-wlm

### This should be done automagically by cmake configure

If you use the distro check library as installed above then you also need to add the
following to the cmake EXTRA_LIBS configuration::

(GCC)   EXTRA_LIBS: -lrt -lpthread -lsubunit
(CLANG) EXTRA_LIBS: -lpthread -lsubunit -lrt 

Brett G. Olivier, Amsterdam, The Netherlands 2019. This work is licensed under a Creative Commons Attribution 4.0 International License.
