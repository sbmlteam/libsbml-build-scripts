#!/bin/bash
# This build script build the anaconda packages from 
# the latest pypi package. It takes two optional arguments
#   
#  PACKAGE_NAME = the name of the package (defaults to python-libsbml)
#  ANACONDA_DIR = the full path to the anaconda directory (defauls to ~/anaconda2/)
#


PACKAGE_NAME=$1
if [ "$PACKAGE_NAME" == "" ]
then
  PACKAGE_NAME=python-libsbml
fi

ANACONDA_DIR=$2
BUILD_DIR=~/Development/conda
if [ "$ANACONDA_DIR" == "" ]
then
  ANACONDA_DIR=~/anaconda2/
fi

# determine directory
UNAME=`uname`
DIR=conda-bld/osx-64/
if [ "$UNAME" == "Linux" ]; then
  DIR=conda-bld/linux-32/
  ARCH=`uname -m`
  if [ $ARCH = "x86_64" ]; then
    DIR=conda-bld/linux-64/
  fi
fi

export PATH=$ANACONDA_DIR/bin:$PATH
export PYTHONPATH=$ANACONDA_DIR/lib/python2.7/site-packages:$ANACONDA_DIR/lib/python2.7

if [ ! -d $BUILD_DIR ]
then
  mkdir $BUILD_DIR
fi

cd $BUILD_DIR

if [ -d ${PACKAGE_NAME} ]
then
 rm -rf ${PACKAGE_NAME}
fi

# upgrade anaconda 
#conda update -y --prefix $ANACONDA_DIR anaconda
conda install -y conda-build 

# grab the latest package from PyPi 
conda skeleton pypi ${PACKAGE_NAME}

# read -n1 -r -p "Press any key to continue..." key

# build the different versions
conda build --python 2.7 ${PACKAGE_NAME}
conda build --python 3.3 ${PACKAGE_NAME}
conda build --python 3.5 ${PACKAGE_NAME}
conda build --python 3.6 ${PACKAGE_NAME}

FILES=`ls -l $ANACONDA_DIR/$DIR`
echo "The build is done, you can now upload the files"
echo ""
echo $FILES
echo ""
echo "to anaconda using anaconda upload --user SBMLTeam $ANACONDA_DIR/$DIR/*"
echo ""

