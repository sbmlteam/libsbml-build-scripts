#!/bin/bash
DIRECTORY=$(cd `dirname $0` && pwd)
DEV_DIR=$HOME/Development
DEP_DIR=$DEV_DIR/install_dependencies
DEP_ARCHIVE=$DIRECTORY/libsbml_dependencies.zip
SVN_REPO=https://svn.code.sf.net/p/sbml/code/trunk/libsbml
TODAY=`date +%Y-%m-%d`
VERSION=5.18.0

ARCH=`uname -m`
FILE=x86
if [ $ARCH = "x86_64" ]; then
FILE=x64
fi

DIST=Centos
if grep -q Ubuntu /proc/version; then
DIST=Ubuntu
fi
SYSTEM="$DIST ($FILE)"

MATLAB_ROOT=$HOME/Desktop/unix

cd $DEV_DIR

# checkout 
if [ ! -d "$DEV_DIR/libsbml" ]; then
svn co $SVN_REPO --non-interactive
fi

# update 
cd $DEV_DIR/libsbml
svn cleanup
svn update --non-interactive

cd ..

# check dependencies

if [ ! -d "$DEV_DIR/install_dependencies" ]; then

unzip -o $DEP_ARCHIVE
cd $DEV_DIR/libsbml_dependencies
find . | xargs touch 
mkdir $DEV_DIR/build_dependencies
cd $DEV_DIR/build_dependencies
cmake -DCMAKE_INSTALL_PREFIX=$DEV_DIR/install_dependencies $DEV_DIR/libsbml_dependencies
make 
make install 

fi

if [ ! -d "$DEV_DIR/build_libsbml_matlab" ]; then
mkdir $DEV_DIR/build_libsbml_matlab
fi

if [ -d "$DEV_DIR/install_matlab" ]; then
rm -rf $DEV_DIR/install_matlab
fi



cd $DEV_DIR/build_libsbml_matlab

# configure 
cmake -DCMAKE_INSTALL_PREFIX=$DEV_DIR/install_matlab -DWITH_LIBXML=OFF -DWITH_EXPAT=ON  -DLIBEXPAT_INCLUDE_DIR=$DEP_DIR/include -DLIBEXPAT_LIBRARY=$DEP_DIR/lib/libexpat.a -DCMAKE_BUILD_TYPE=Release -DLIBBZ_INCLUDE_DIR=$DEP_DIR/include -DLIBBZ_LIBRARY=$DEP_DIR/lib/libbz2.a -DLIBZ_INCLUDE_DIR=$DEP_DIR/include -DLIBZ_LIBRARY=$DEP_DIR/lib/libzlib.a -DENABLE_FBC=ON -DENABLE_COMP=OFF -DENABLE_LAYOUT=OFF -DENABLE_MULTI=OFF -DENABLE_QUAL=ON -DENABLE_GROUPS=ON -DENABLE_L3V2EXTENDEDMATH=ON -DLIBSBML_SKIP_SHARED_LIBRARY=ON -DLIBSBML_USE_LEGACY_MATH=ON -DWITH_CHECK=ON -DWITH_MATLAB=ON -DMATLAB_ROOT_PATH=$MATLAB_ROOT $DEV_DIR/libsbml

# build & test
#make
ctest --overwrite Site="$SYSTEM" -D Experimental
# install 
cd $DEV_DIR/build_libsbml_matlab/src/bindings/matlab
make install 

# create archive
NAME=libSBML-${VERSION}-linux-matlab-${FILE}
cd $DEV_DIR/install_matlab

if [ -d "lib/pkgconfig" ]; then
rm -rf lib/pkgconfig
fi 

if [ -f "lib/libsbml-static.a" ]; then 
rm lib/libsbml-static.a
fi 

if [ -d "$NAME" ]; then
rm -rf $NAME
fi 

if [ -f "$NAME.tar.gz" ]; then
rm $NAME.tar.gz
fi 


cp $DIRECTORY/MatlabBinding-README.md lib/README.md

mv lib $NAME
tar -cf "$NAME.tar" * 
gzip "$NAME.tar"
cp "$NAME.tar.gz" /mnt/hgfs/share/$NAME.tar.gz

SUFFIX=mexa64
if [ $ARCH = "x86_64" ]; then
  SUFFIX = mexglx
fi

cp "$NAME/TranslateSBML.$SUFFIX" /mnt/hgfs/share/TranslateSBML.$SUFFIX
cp "$NAME/OutputSBML.$SUFFIX" /mnt/hgfs/share/OutputSBML.$SUFFIX

