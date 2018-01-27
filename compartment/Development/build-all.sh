#!/bin/bash
DIRECTORY=$(cd `dirname $0` && pwd)
export PATH=$DIRECTORY/ninja:$HOME/bin:$PATH:/usr/local/bin:/usr/bin
INSTALL_PREFIX=/usr
ARCH=`uname -m`
DIR=32
LIB_SUFFIX=lib
FILE=x86
EXTRA_ARG=-DDEBIAN_PACKAGE_ARCHITECTURE="i386"
if [ $ARCH = "x86_64" ]; then
DIR=64
LIB_SUFFIX=lib64
FILE=x64
EXTRA_ARG=
fi
LOCK=$DIRECTORY/.build-running

cd $DIRECTORY

if [ -e $LOCK ]; then 

 echo build in process ... skipping ;
 exit 1;
fi; 

touch $LOCK

if [ ! -d "ninja_libsbml" ]; then
mkdir "ninja_libsbml"
fi
if [ ! -d "ninja_libsbml-experimental" ]; then
mkdir "ninja_libsbml-experimental"
fi

echo ... Checkout 
# checkout
cd libsbml-stable
svn cleanup
svn update
cd $DIRECTORY

# checkout
cd libsbml-experimental
svn cleanup
svn update

cd $DIRECTORY

echo ... build trunk 

# compile stable
cd ninja_libsbml
rm *.tar.gz
rm *.deb
if [ -d "src" ]; then
rm -rf src 
fi

echo ..... configure
# brett debug disabled octave
cmake $EXTRA_ARG -DNODEJS_EXECUTABLE=/usr/local/bin/node -DWITH_EXPAT=OFF -DWITH_LIBXML=ON -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX -DWITH_CHECK=ON -DENABLE_RENDER=ON -DENABLE_GROUPS=ON -DENABLE_COMP=ON -DENABLE_FBC=ON -DENABLE_QUAL=ON -DENABLE_LAYOUT=ON -DLIBSBML_USE_LEGACY_MATH=ON -DWITH_CSHARP=ON -DWITH_JAVASCRIPT=ON -DWITH_JAVA=ON -DWITH_PERL=ON -DWITH_PYTHON=ON -DWITH_RUBY=ON -DWITH_OCTAVE=OFF -DWITH_R=ON -DWITH_CREATE_PYTHON_SOURCE=ON -DWITH_WALL=ON $DIRECTORY/libsbml-stable > $DIRECTORY/core-conf.log 2>&1

echo ..... compile
make > $DIRECTORY/core-build.log 2>&1

echo ..... test
ctest -V  > $DIRECTORY/core-test.log 2>&1

echo ..... package
# cpack -G ZIP
cpack -G TGZ
cpack -G DEB
# cpack -G RPM
cd $DIRECTORY

echo ... copy files
# copy files
$DIRECTORY/Dropbox-Uploader/dropbox_uploader.sh upload $DIRECTORY/ninja_libsbml/*.deb libsbml_linux/$DIR/
$DIRECTORY/Dropbox-Uploader/dropbox_uploader.sh upload $DIRECTORY/ninja_libsbml/*.tar.gz libsbml_linux/$DIR/
$DIRECTORY/Dropbox-Uploader/dropbox_uploader.sh upload $DIRECTORY/ninja_libsbml/src/bindings/r/*.tar.gz libsbml_linux/$DIR/
$DIRECTORY/Dropbox-Uploader/dropbox_uploader.sh upload $DIRECTORY/core-*.log libsbml_linux/$DIR/


echo ... build packages
# compile packages
cd ninja_libsbml-experimental
rm *.deb
rm *.tar.gz

if [ -d "src" ]; then
rm -rf src 
fi

echo ..... configure
# brett debug disabled octave
cmake $EXTRA_ARG  -DNODEJS_EXECUTABLE=/usr/local/bin/node -DWITH_EXPAT=OFF -DWITH_LIBXML=ON -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX -DWITH_CHECK=ON -DENABLE_ARRAYS=ON -DENABLE_DISTRIB=ON -DENABLE_REQUIREDELEMENTS=ON -DENABLE_DYN=ON -DENABLE_MULTI=ON -DENABLE_RENDER=ON -DENABLE_GROUPS=ON -DENABLE_SPATIAL=ON -DENABLE_COMP=ON -DENABLE_FBC=ON -DENABLE_QUAL=ON -DENABLE_LAYOUT=ON -DLIBSBML_USE_LEGACY_MATH=OFF -DWITH_CSHARP=ON -DWITH_JAVASCRIPT=ON -DWITH_JAVA=ON -DWITH_PERL=ON -DWITH_PYTHON=ON -DWITH_RUBY=ON -DWITH_OCTAVE=OFF -DWITH_R=ON -DWITH_CREATE_PYTHON_SOURCE=ON -DWITH_WALL=ON $DIRECTORY/libsbml-experimental > $DIRECTORY/exp-conf.log 2>&1

echo ..... compile
make > $DIRECTORY/exp-build.log 2>&1

echo ..... test
ctest -V > $DIRECTORY/exp-test.log 2>&1

echo ... build packages
# cpack -G ZIP
cpack -G TGZ
cpack -G DEB
# cpack -G RPM
cd $DIRECTORY

echo ... copy files
# copy files
$DIRECTORY/Dropbox-Uploader/dropbox_uploader.sh upload $DIRECTORY/ninja_libsbml-experimental/*.deb libsbml_linux/$DIR-package/
$DIRECTORY/Dropbox-Uploader/dropbox_uploader.sh upload $DIRECTORY/ninja_libsbml-experimental/*.tar.gz libsbml_linux/$DIR-package/
$DIRECTORY/Dropbox-Uploader/dropbox_uploader.sh upload $DIRECTORY/ninja_libsbml-experimental/src/bindings/r/*.tar.gz libsbml_linux/$DIR-package/
$DIRECTORY/Dropbox-Uploader/dropbox_uploader.sh upload $DIRECTORY/exp-*.log libsbml_linux/$DIR-package/

rm $LOCK
