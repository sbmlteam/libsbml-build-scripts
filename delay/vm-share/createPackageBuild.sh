#!/bin/bash

# the directories to copy the dist to
DEST_DIR=/mnt/hgfs/share
C_LOGFILE=/tmp/package-configure-log.txt
M_LOGFILE=/tmp/package-make-log.txt
P_LOGFILE=/tmp/package-pack-log.txt
S_LOGFILE=/tmp/package-svn-log.txt
C2_LOGFILE=/tmp/check-log.txt

#Build script for RPM and DEB files
VERSION=libSBML-5.16.0
PACKAGE_FILE=$DEST_DIR/$VERSION-Source.tar.gz
ENABLED_PACKAGES="-DENABLE_LAYOUT=ON -DENABLE_ARRAYS=ON  -DENABLE_MULTI=ON -DENABLE_RENDER=ON -DENABLE_COMP=ON -DENABLE_FBC=ON -DENABLE_GROUPS=ON -DENABLE_REQUIREDELEMENTS=ON -DENABLE_SPATIAL=ON -DENABLE_DYN=ON -DENABLE_QUAL=ON -DENABLE_DISTRIB=ON "
INSTALL_PREFIX=/usr
SUFFIX=-packages
SVN_DIR=$VERSION-Source
BUILD_DIR=buildPackage
ARCH=`uname -m`
DIR=32
LIB_SUFFIX=lib
FILE=x86
JAVA_TAR=$DEST_DIR/jdk1.5.0_22.tar
EXTRA_ARG=-DDEBIAN_PACKAGE_ARCHITECTURE="i386"
if [ $ARCH = "x86_64" ]; then
JAVA_TAR=$DEST_DIR/jdk1.5.0_22-amd64.tar
DIR=64
LIB_SUFFIX=lib64
FILE=x64
EXTRA_ARG=
fi
WITH_MONO=OFF
if which gmcs >/dev/null; then
WITH_MONO=ON
fi

CMAKE_JAVA_OPTS="-DWITH_JAVA=ON -DJava_JAVA_EXECUTABLE=~/jdk1.5.0_22/bin/java -DJava_JAVAC_EXECUTABLE=~/jdk1.5.0_22/bin/javac -DJava_JAR_EXECUTABLE=~/jdk1.5.0_22/bin/jar "
if [ ! -d "$HOME/jdk1.5.0_22" ]; then
cd $HOME
tar xf $JAVA_TAR
fi

export JAVA_HOME=$HOME/jdk1.5.0_22
export PATH=/usr/local/bin:$JAVA_HOME/bin:$PATH

cd $HOME/Development

# create build lock
touch /tmp/build_running


# remove existing files
test -f $C_LOGFILE && rm $C_LOGFILE
test -f $M_LOGFILE && rm $M_LOGFILE
test -f $P_LOGFILE && rm $P_LOGFILE
test -f $S_LOGFILE && rm $S_LOGFILE
test -f $C2_LOGFILE && rm $C2_LOGFILE

if [ ! -d "$DEST_DIR/32" ]; then
mkdir "$DEST_DIR/32"
fi
if [ ! -d "$DEST_DIR/64" ]; then
mkdir "$DEST_DIR/64"
fi


SKIP_BUILD="false"
if [ "$1" = "--skip-build" ]
then
  SKIP_BUILD="true"
fi


echo ...
echo ...Dist build script for $VERSION \($DIR bit\)
echo ...
if [ "$SKIP_BUILD" = "false" ]; then
  echo ...extract $VERSION
  rm -rf $SVN_DIR
  tar zxf $PACKAGE_FILE
fi

if [ ! -d "$BUILD_DIR" ]; then
  mkdir $BUILD_DIR
fi

cd $BUILD_DIR

if [ -d "src/bindings" ]; then
rm -rf src/bindings
fi

if [ -d "CMakeFiles" ]; then
rm -rf CMakeFiles
fi

test -f CMakeCache.txt && rm CMakeCache.txt

echo ...Configure $VERSION
cmake -DWITH_CHECK=ON $ENABLED_PACKAGES $CMAKE_JAVA_OPTS -DWITH_CPP_NAMESPACE=OFF -DWITH_PYTHON=OFF -DWITH_RUBY=ON -DWITH_PERL=ON -DWITH_CSHARP=$WITH_MONO -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX -DCMAKE_INSTALL_LIBDIR=$INSTALL_PREFIX/$LIB_SUFFIX ../$SVN_DIR  > $C_LOGFILE 2>&1
cmake -DWITH_CHECK=ON $ENABLED_PACKAGES $CMAKE_JAVA_OPTS -DWITH_CPP_NAMESPACE=OFF -DWITH_PYTHON=OFF -DWITH_RUBY=ON -DWITH_PERL=ON -DWITH_CSHARP=$WITH_MONO -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX -DCMAKE_INSTALL_LIBDIR=$INSTALL_PREFIX/$LIB_SUFFIX ../$SVN_DIR  >> $C_LOGFILE 2>&1

if [ "$SKIP_BUILD" = "false" ]; then
  echo ...build $VERSION
  make  > $M_LOGFILE 2>&1
else
  echo ... skipping build
fi

#cpack
cpack -G TGZ  > $P_LOGFILE 2>&1
if grep -q Ubuntu /proc/version; then
  echo ... create DEB
  echo ... running cpack -G DEB $EXTRA_ARG
  cpack -G DEB $EXTRA_ARG  >> $P_LOGFILE 2>&1
else
  echo ... create RPM
  cpack -G RPM  >> $P_LOGFILE 2>&1
fi

#ctest
ctest -V > $C2_LOGFILE 2>&1


echo ...copy dist libsbml-5 to $DEST_DIR

if grep -q Ubuntu /proc/version; then
  echo ...copy deb
  cp $C_LOGFILE $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-ubuntu-configure-package.txt
  cp $M_LOGFILE $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-ubuntu-make-package.txt
  cp $P_LOGFILE $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-ubuntu-package-package.txt
  cp $C2_LOGFILE $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-ubuntu-check-package.txt
  cp $VERSION-Linux.deb $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE.deb
  cp $VERSION-Linux.tar.gz $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-ubuntu-binaries.tar.gz
else
  echo ...copy rpm
  cp $C_LOGFILE $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-centos-configure-package.txt
  cp $M_LOGFILE $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-centos-make-package.txt
  cp $P_LOGFILE $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-centos-package-package.txt
  cp $C2_LOGFILE $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-centos-check-package.txt
  cp $VERSION-Linux.rpm $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE.rpm
  cp $VERSION-Linux.tar.gz $DEST_DIR/$DIR/${VERSION}${SUFFIX}-Linux-$FILE-centos-binaries.tar.gz
fi

cd ..
echo Done
echo 

# remove include block
test -f /tmp/build_running && rm /tmp/build_running

