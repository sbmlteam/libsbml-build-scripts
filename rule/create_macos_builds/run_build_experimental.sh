#!/bin/bash


DIRECTORY=$(cd `dirname $0` && pwd)

SOURCE_DIR=$DIRECTORY/../../../../Development/libsbml-experimental

BUILD_DIR=$DIRECTORY/../../../../Development/build_experimental


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
