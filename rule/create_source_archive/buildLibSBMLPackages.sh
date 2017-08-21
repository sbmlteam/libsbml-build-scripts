#!/bin/bash

DIRECTORY=$(cd `dirname $0` && pwd)
VERSION=$1
DB_DIR=$HOME/Dropbox/sbmlteam-libsbml-dist/$VERSION
OUT_DIR=$HOME/out_dir
BUILD_DIR=$HOME/build_dir

if [ ! -d "$OUT_DIR" ]; then
	mkdir "$OUT_DIR"
fi

if [ -d "$BUILD_DIR" ]; then
	rm -rf "$BUILD_DIR"
fi

cp $OUT_DIR/libsbml-$VERSION-src.tar.gz $DB_DIR/libSBML-$VERSION-src.tar.gz
cp $OUT_DIR/libsbml-$VERSION-src.zip $DB_DIR/libSBML-$VERSION-src.zip


cd $HOME

mkdir $BUILD_DIR
cd $BUILD_DIR

tar zxf $DB_DIR/libsbml-$VERSION-src.tar.gz
cp $DB_DIR/libsbml-$VERSION-src.tar.gz $OUT_DIR/libSBML-$VERSION-core-src.tar.gz
cp $DB_DIR/libsbml-$VERSION-src.zip $OUT_DIR/libSBML-$VERSION-core-src.zip

cd libsbml-$VERSION
for f in $DB_DIR/accepted/*.zip; do unzip -o $f; done
dot_clean -m . 
find . -name ".DS_Store" -depth -exec rm {} \;
cd $BUILD_DIR

mkdir build_core
cd build_core
cmake ../libsbml-$VERSION
cpack -G TGZ --config ./CPackSourceConfig.cmake 
cpack -G ZIP --config ./CPackSourceConfig.cmake 

cp libSBML-$VERSION-Source.tar.gz $OUT_DIR/libSBML-$VERSION-core-plus-packages-src.tar.gz
cp libSBML-$VERSION-Source.zip $OUT_DIR/libSBML-$VERSION-core-plus-packages-src.zip

cd $BUILD_DIR

cd libsbml-$VERSION
for f in $DB_DIR/experimental/*.zip; do unzip -o $f; done
cd $BUILD_DIR

mkdir build_experimental
cd build_experimental
cmake ../libsbml-$VERSION
cpack -G TGZ --config ./CPackSourceConfig.cmake
cpack -G ZIP --config ./CPackSourceConfig.cmake
cp libSBML-$VERSION-Source.tar.gz $OUT_DIR/
cp libSBML-$VERSION-Source.zip $OUT_DIR/

cd $DB_DIR
rm libsbml-$VERSION-src.tar.gz
rm libsbml-$VERSION-src.zip

cd $OUT_DIR
cp libSBML-$VERSION-*.* $DB_DIR/*.*

