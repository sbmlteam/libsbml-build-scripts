#!/bin/bash
DIRECTORY=$(cd `dirname $0` && pwd)
export PATH=$HOME/bin:$PATH:$DIRECTORY/ninja:/usr/local/bin:/usr/bin
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
export CK_FORK=no

cd $DIRECTORY

if [ -e $LOCK ]; then 
  echo Build running ... skipping; 
  exit;
fi; 

touch $LOCK 

cd $DIRECTORY/libsbml-stable-check
svn cleanup --non-interactive
svn update --non-interactive

cd $DIRECTORY/

if [ ! -d ninja_libsbml-check ]; then
mkdir ninja_libsbml-check
fi 

cd ninja_libsbml-check

cmake -DNODEJS_EXECUTABLE=/usr/local/bin/node -DWITH_LIBXML=OFF -DWITH_EXPAT=ON -DCMAKE_BUILD_TYPE=Debug -DWITH_CHECK=ON -DENABLE_ARRAYS=ON -DENABLE_DISTRIB=ON -DENABLE_REQUIREDELEMENTS=ON -DENABLE_DYN=ON -DENABLE_MULTI=ON -DENABLE_RENDER=ON -DENABLE_GROUPS=ON -DENABLE_SPATIAL=ON -DENABLE_COMP=ON -DENABLE_FBC=ON -DENABLE_QUAL=ON -DENABLE_LAYOUT=ON -DLIBSBML_USE_LEGACY_MATH=ON -DWITH_CSHARP=ON -DWITH_JAVASCRIPT=ON -DWITH_JAVA=ON -DWITH_PERL=ON -DWITH_PYTHON=ON -DWITH_RUBY=ON -DWITH_OCTAVE=ON -DWITH_R=ON -DWITH_CREATE_PYTHON_SOURCE=ON -DWITH_WALL=ON $DIRECTORY/libsbml-stable-check

ctest -D Experimental

cd $DIRECTORY

cd $DIRECTORY/libsbml-experimental-check
svn cleanup --non-interactive
svn update --non-interactive

cd $DIRECTORY

if [ ! -d ninja_libsbml-experimental-check ]; then
mkdir ninja_libsbml-experimental-check
fi 

cd ninja_libsbml-experimental-check


cmake -DNODEJS_EXECUTABLE=/usr/local/bin/node -DWITH_LIBXML=OFF -DWITH_EXPAT=ON -DCMAKE_BUILD_TYPE=Debug -DWITH_CHECK=ON -DENABLE_ARRAYS=ON -DENABLE_DISTRIB=ON -DENABLE_REQUIREDELEMENTS=ON -DENABLE_DYN=ON -DENABLE_MULTI=ON -DENABLE_RENDER=ON -DENABLE_GROUPS=ON -DENABLE_SPATIAL=ON -DENABLE_COMP=ON -DENABLE_FBC=ON -DENABLE_QUAL=ON -DENABLE_LAYOUT=ON -DLIBSBML_USE_LEGACY_MATH=OFF -DWITH_CSHARP=ON -DWITH_JAVASCRIPT=ON -DWITH_JAVA=ON -DWITH_PERL=ON -DWITH_PYTHON=ON -DWITH_RUBY=ON -DWITH_OCTAVE=ON -DWITH_R=ON -DWITH_CREATE_PYTHON_SOURCE=ON -DWITH_WALL=ON  $DIRECTORY/libsbml-experimental-check

ctest -D Experimental

cd $DIRECTORY

rm $LOCK 

