#!/bin/bash

# the directories to copy the dist to
DEST_DIR=/mnt/hgfs/share
C_LOGFILE=/tmp/configure-log.txt
M_LOGFILE=/tmp/make-log.txt
P_LOGFILE=/tmp/pack-log.txt
S_LOGFILE=/tmp/svn-log.txt
C2_LOGFILE=/tmp/check-log.txt
SKIP_BUILD="false"
if [ "$1" = "--skip-build" ]
then
  SKIP_BUILD="true"
fi

#Build script for RPM and DEB files
SVN_REPO=https://svn.code.sf.net/p/sbml/code/trunk/libsbml
INSTALL_PREFIX=/usr
VERSION=libSBML-5.17.0
SUFFIX=
SVN_DIR=/mnt/hgfs/share/libsbml
BUILD_DIR=Development/build5
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
WITH_MONO=OFF
if which gmcs >/dev/null; then
  WITH_MONO=ON
fi

echo ...
echo ...Dist build script for $VERSION \($DIR bit\)
echo ...

echo $SVN_DIR
if [ ! -d "../$BUILD_DIR" ]; then
  mkdir ../$BUILD_DIR
fi
cd ../$BUILD_DIR

if [ -d "src/bindings" ]; then
rm -rf src/bindings
fi

if [ -d "CMakeFiles" ]; then
rm -rf CMakeFiles
fi

test -f CMakeCache.txt && rm CMakeCache.txt

echo ...Configure $VERSION
cmake -DWITH_CHECK=ON -DWITH_JAVA=ON -DWITH_CPP_NAMESPACE=OFF -DWITH_PYTHON=OFF -DENABLE_RENDER=ON -DENABLE_LAYOUT=ON -DENABLE_MULTI=ON -DENABLE_GROUPS=ON -DENABLE_FBC=ON -DENABLE_COMP=ON  -DENABLE_QUAL=ON -DWITH_RUBY=ON -DWITH_PERL=ON -DWITH_CSHARP=$WITH_MONO -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX -DCMAKE_INSTALL_LIBDIR=$INSTALL_PREFIX/$LIB_SUFFIX $SVN_DIR  
cmake -DWITH_CHECK=ON -DWITH_JAVA=ON -DWITH_CPP_NAMESPACE=OFF -DWITH_PYTHON=OFF -DENABLE_RENDER=ON -DENABLE_LAYOUT=ON -DENABLE_MULTI=ON -DENABLE_GROUPS=ON -DENABLE_FBC=ON -DENABLE_COMP=ON  -DENABLE_QUAL=ON -DWITH_RUBY=ON -DWITH_PERL=ON -DWITH_CSHARP=$WITH_MONO -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX -DCMAKE_INSTALL_LIBDIR=$INSTALL_PREFIX/$LIB_SUFFIX $SVN_DIR > $C_LOGFILE 2>&1

if [ "$SKIP_BUILD" = "false" ]; then
  echo ...build $VERSION
  make > $M_LOGFILE 2>&1
else
  echo ... skipping build
fi

#cpack
cpack -G TGZ > $P_LOGFILE 2>&1
if grep -q Ubuntu /proc/version; then
 echo ... create DEB
 cpack -G DEB $EXTRA_ARG >> $P_LOGFILE 2>&1
else
 echo ... create RPM  
 cpack -G RPM >> $P_LOGFILE 2>&1
fi

#ctest
ctest -V > $C2_LOGFILE 2>&1

echo ...copy dist libsbml-5 to $DEST_DIR
cp $VERSION-Linux.* $DEST_DIR/$DIR/

if grep -q Ubuntu /proc/version; then
  echo ...copy deb
  cp $S_LOGFILE $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-ubuntu-svn.txt
  cp $C_LOGFILE $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-ubuntu-configure.txt
  cp $M_LOGFILE $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-ubuntu-make.txt
  cp $P_LOGFILE $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-ubuntu-package.txt
  cp $C2_LOGFILE $DEST_DIR/$DIR/${VERSION-Linux-$FILE-ubuntu-check.txt
  cp $VERSION-Linux.deb $DEST_DIR/$DIR/${VERSION}$-Linux-$FILE.deb
  cp $VERSION-Linux.tar.gz $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-binaries-ubuntu.tar.gz
else
  echo ...copy rpm
  cp $S_LOGFILE $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-centos-svn.txt
  cp $C_LOGFILE $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-centos-configure.txt
  cp $M_LOGFILE $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-centos-make.txt
  cp $P_LOGFILE $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-centos-package.txt
  cp $C2_LOGFILE $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-centos-check.txt
  cp $VERSION-Linux.rpm $DEST_DIR/$DIR/${VERSION}-Linux-$FILE.rpm
  cp $VERSION-Linux.tar.gz $DEST_DIR/$DIR/${VERSION}-Linux-$FILE-binaries-centos.tar.gz
fi



cd ..
echo Done
echo 
