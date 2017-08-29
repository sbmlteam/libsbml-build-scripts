#!/bin/bash

DIRECTORY=$(cd `dirname $0` && pwd)

INSTALL_DIR=$DIRECTORY/../../common/mac_installer/installer/libsbml-dist

SOURCE_DIR=$DIRECTORY/../../../../libsbml-experimental

BUILD_DIR=$DIRECTORY/../../../../working/buildExpSVN


cd $INSTALL_DIR
rm -r $INSTALL_DIR/*
cd $SOURCE_DIR

cd $SOURCE_DIR
# update SVN
svn cleanup
svn update

if [ ! -d $BUILD_DIR ] 
then
  mkdir $BUILD_DIR
else 
  # remove old files from it
  rm -r $BUILD_DIR/*
fi

cd $BUILD_DIR
# copy files needed
cp ${DIRECTORY}/experimental/CMakeCache.txt ${BUILD_DIR}/CMakeCache.txt
cp ${DIRECTORY}/experimental/Makefile ${BUILD_DIR}/Makefile

make rebuild_cache
make
make check
make install

cd $DIRECTORY
