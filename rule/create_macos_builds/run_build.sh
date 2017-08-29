#!/bin/bash


DIRECTORY=$(cd `dirname $0` && pwd)

SOURCE_DIR=$DIRECTORY/../Development/libsbml

BUILD_DIR=$DIRECTORY/../Development/build_stable


cd $SOURCE_DIR
# update SVN
svn cleanup > $S_LOGFILE 2>&1
svn update  >> $S_LOGFILE 2>&1

if [ ! -d $BUILD_DIR ] 
then
  mkdir $BUILD_DIR
else 
  # remove old files from it
  rm -r $BUILD_DIR/*
fi

cd $BUILD_DIR
# copy files needed
cp ${DIRECTORY}/stable/CMakeCache.txt ${BUILD_DIR}/CMakeCache.txt
cp ${DIRECTORY}/stable/Makefile ${BUILD_DIR}/Makefile

make rebuild_cache
make
make check
make install
