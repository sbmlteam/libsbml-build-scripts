#!/bin/bash
#
#
ROOT_DIR=/opt/online-validator
LIBSBML_DIR=$ROOT_DIR/libsbml-5 
BUILD_DIR=$ROOT_DIR/build
WEB_ROOT=$ROOT_DIR/apache-tomcat-7.0.12

echo Update LibSBML
cd $LIBSBML_DIR
svn update
echo Build LibSBML
cd $BUILD_DIR
echo deleting old java bindings
rm -rf $BUILD_DIR/src/bindings/java
echo rebuilding cache
make rebuild_cache
make
echo Install LibSBML
make install

echo Copy LibSBML
cp $ROOT_DIR/share/java/libsbmlj.jar $ROOT_DIR/lib
cp $ROOT_DIR/lib/* $WEB_ROOT/lib/
cp $ROOT_DIR/lib/* $HOME/lib/
