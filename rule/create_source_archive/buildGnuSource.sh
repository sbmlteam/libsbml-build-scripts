#!/bin/bash

DIRECTORY=$(cd `dirname $0` && pwd)
OUT_DIR=$HOME/out_dir
SOURCE_DIR=$HOME/Development/libsbml_gnumake
C_LOGFILE=$OUT_DIR/mac-gnumake-configure-log.txt
M_LOGFILE=$OUT_DIR/mac-gnumake-make-log.txt
P_LOGFILE=$OUT_DIR/mac-gnumake-pack-log.txt
S_LOGFILE=$OUT_DIR/mac-gnumake-svn-log.txt

if [ ! -d $SOURCE_DIR ] 
then
  echo "this system is not setup for the gnu source build"
  exit 1
fi

if [ ! -d $OUT_DIR ] 
then
  mkdir $OUT_DIR
else 
  # remove old files from it
  rm $OUT_DIR/*-src.*
  rm $OUT_DIR/*.txt
fi


cd $SOURCE_DIR
# remove old files 
rm libsbml-*-src.*

# update SVN
svn cleanup > $S_LOGFILE 2>&1
svn update  >> $S_LOGFILE 2>&1

# configure build 
./configure --with-libxml=/usr --with-swig=/usr/local --with-csharp --with-ruby=/usr --with-perl=/usr --with-python --with-java=/Library/Java/JavaVirtualMachines/1.6.0.jdk/Contents/Home/ --with-check --enable-layout=no  --enable-l3v2extendedmath=yes > $C_LOGFILE  2>&1 

make dist-zip > $P_LOGFILE 2>&1

# remove directory
rm -rf libsbml-$VERSION

# copy files
cp libsbml-*-src.* $OUT_DIR
