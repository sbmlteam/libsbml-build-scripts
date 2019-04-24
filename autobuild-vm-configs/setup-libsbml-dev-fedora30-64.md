# Setting up an Fedora 30 64 bit build environment for libSBML

## Setup build environment

Start with a default install of Fedora 30 or newer and grab some build tools 

```
sudo dnf install -y kernel-headers kernel-devel 
sudo dnf install -y gcc make autoconf cmake cmake-gui gcc-c++ swig
sudo dnf install -y mc subversion git
```

If running on a VirtualBox VM this is a good time to install the guest extensions. See [https://www.if-not-true-then-false.com/2010/install-virtualbox-guest-additions-on-fedora-centos-red-hat-rhel/] for details:

```
sudo dnf update kernel*
sudo mkdir /media/VirtualBoxGuestAdditions
sudo mount -r /dev/cdrom /media/VirtualBoxGuestAdditions
sudo dnf install gcc kernel-devel kernel-headers dkms make bzip2 perl
KERN_DIR=/usr/src/kernels/`uname -r`/build
export KERN_DIR
cd /media/VirtualBoxGuestAdditions
sudo ./VBoxLinuxAdditions.run
```

Continue with more build tools and libSBML dependencies. 

```
sudo dnf install -y libcurl libcurl-devel libxml2 libxml2-devel check check-devel bzip2 bzip2-devel
sudo dnf install -y libcurl-devel.x86_64 
sudo dnf install -y expat expat-devel xerces-c xerces-c-devel curl curl-devel
sudo dnf install -y bzr p7zip ninja-build
``` 
 
These following adds support for compiling libSBML bindings (Python, Perl, Java, Ruby, R, Mono)

```
sudo dnf install -y python-devel python3-devel perl perl-devel java-openjdk
sudo dnf install -y ruby ruby-devel R R-devel mono-core
```
 
These extra Python packages are required for fancy report generation and general python happiness

```
sudo dnf install -y ipython3 python-pip python3-pip python3-xlsxwriter
```
Install Visual Studio Code (optional)

```
https://code.visualstudio.com/docs/setup/linux
```

 
## Getting the libSBML source code and configuration files

All building is assumed to take place in ~/development

```
cd ~
mkdir development
cd development
```

Checkout the libSBML build-scripts

```
svn checkout https://svn.code.sf.net/p/sbml/code/trunk/libsbml sf_libsbml
svn checkout https://svn.code.sf.net/p/sbml/code/branches/libsbml-experimental sf_libsbml_experimental
```

Clone the libSBML build-scripts repository and checkout the automatic build configuration tools.

```
git clone https://github.com/sbmlteam/libsbml-build-scripts.git
cd libsbml-build-scripts
git checkout auto-build-options
cd autobuild-option-tests
```

Brett G. Olivier, Amsterdam, The Netherlands 2019. This work is licensed under a Creative Commons Attribution 4.0 International License.
