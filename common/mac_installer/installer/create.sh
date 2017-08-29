#!/bin/bash


DIRECTORY=$(cd `dirname $0` && pwd)

PACKAGE_MAKER=$DIRECTORY/../../../../../Development/PackageMaker.app/Contents/MacOS/PackageMaker
SOURCE_DIR=$DIRECTORY/../../../../../Development/libsbml


OSX_MAJOR_VER=`uname -r | cut -d'.' -f1`
if expr ${OSX_MAJOR_VER} \>= 16 | grep -q 1; then
MACOS="sierra"
elif expr ${OSX_MAJOR_VER} \>= 15 | grep -q 1; then
MACOS="elcapitan"
elif expr ${OSX_MAJOR_VER} \>= 14 | grep -q 1; then
MACOS="yosemite"
elif expr ${OSX_MAJOR_VER} \>= 13 | grep -q 1; then
MACOS="mavericks"
elif expr ${OSX_MAJOR_VER} \>= 12 | grep -q 1; then
  MACOS="mountainlion"
elif expr ${OSX_MAJOR_VER} \>= 11 | grep -q 1; then
  MACOS="lion"
elif expr ${OSX_MAJOR_VER} \>= 10 | grep -q 1; then
  MACOS="snowleopard"
  PACKAGE_MAKER=/Developer/Applications/Utilities/PackageMaker.app/Contents/MacOS/PackageMaker
  SOURCE_DIR=$DIRECTORY/../../../../../libsbml
else
  MACOS="leopard"
fi


PACKAGE_VERSION=$1
XML_PARSER=libxml2
DISKDIR=disk-image
PKGNAME=libSBML-${PACKAGE_VERSION}-${XML_PARSER}-${MACOS}.pkg
DMGBASE=libsbml-${PACKAGE_VERSION}-${XML_PARSER}
DMGNAME=${DMGBASE}-macosx-${MACOS}.dmg
DMGFINAL=./${DMGNAME}

PACKAGE_LOCATION=${DIRECTORY}

cd ${DIRECTORY}

if ! test -e ${DIRECTORY}/libsbml-dist/bin; then
mkdir ${DIRECTORY}/libsbml-dist/bin
else
rm -r ${DIRECTORY}/libsbml-dist/bin
mkdir ${DIRECTORY}/libsbml-dist/bin
fi

cp uninstall-libsbml-pkg.sh ${DIRECTORY}/libsbml-dist/bin

sed -e s:@PACKAGE_LOCATION@:$DIRECTORY/libsbml-dist/:g -e s:@PACKAGE_VERSION@:$PACKAGE_VERSION:g -e s:@XML_PARSER@:$XML_PARSER:g $DIRECTORY/libsbml-package.pmdoc/01local-contents.xml.in > $DIRECTORY/libsbml-package.pmdoc/01local-contents.xml

sed -e s:@PACKAGE_LOCATION@:$DIRECTORY/libsbml-dist/:g -e s:@PACKAGE_VERSION@:$PACKAGE_VERSION:g -e s:@XML_PARSER@:$XML_PARSER:g $DIRECTORY/libsbml-package.pmdoc/01local.xml.in > $DIRECTORY/libsbml-package.pmdoc/01local.xml

sed -e s:@PACKAGE_LOCATION@:$DIRECTORY/libsbml-dist/:g -e s:@PACKAGE_VERSION@:$PACKAGE_VERSION:g -e s:@XML_PARSER@:$XML_PARSER:g $DIRECTORY/libsbml-package.pmdoc/index.xml.in > $DIRECTORY/libsbml-package.pmdoc/index.xml

sed -e s:@PACKAGE_LOCATION@:$DIRECTORY/libsbml-dist/:g -e s:@PACKAGE_VERSION@:$PACKAGE_VERSION:g -e s:@XML_PARSER@:$XML_PARSER:g $DIRECTORY/resources/package-readme.txt.in > $DIRECTORY/resources/package-readme.txt


sed -e s:@PACKAGE_LOCATION@:$DIRECTORY/libsbml-dist/:g -e s:@PACKAGE_VERSION@:$PACKAGE_VERSION:g -e s:@XML_PARSER@:$XML_PARSER:g $DIRECTORY/resources/package-intro.txt.in > $DIRECTORY/resources/package-intro.txt

find . -name ".DS_Store" -depth -exec rm {} \;

${PACKAGE_MAKER} -v --id org.sbml.libsbml --doc libsbml-package.pmdoc --out  ${PKGNAME}

if ! test -e ${PKGNAME}; then
  echo "**** ERROR: ${PKGNAME} does not exist -- nothing to do."
  exit 1
fi

if test -d ${DISKDIR}; then
  if test -d ${DISKDIR}-previous; then
    echo "Directory '${DISKDIR}-previous' exists; deleting it.  Hope that's okay."
    /bin/rm -rf ${DISKDIR}-previous
  fi
  echo "Moving previous copy of '${DISKDIR}' to '${DISKDIR}-previous'."
  mv -f ${DISKDIR} ${DISKDIR}-previous
fi

mkdir ${DISKDIR}
cp ${PKGNAME}           ${DISKDIR}
cp resources/README.txt ${DISKDIR}

mkdir ${DISKDIR}/docs
cp ${SOURCE_DIR}/AUTHORS.txt  ${DISKDIR}/docs
cp ${SOURCE_DIR}/COPYING.html ${DISKDIR}/docs
cp ${SOURCE_DIR}/COPYING.txt  ${DISKDIR}/docs
cp ${SOURCE_DIR}/FUNDING.txt  ${DISKDIR}/docs
cp ${SOURCE_DIR}/LICENSE.html ${DISKDIR}/docs
cp ${SOURCE_DIR}/LICENSE.txt  ${DISKDIR}/docs
cp ${SOURCE_DIR}/NEWS.txt     ${DISKDIR}/docs
cp ${SOURCE_DIR}/OLD_NEWS.txt ${DISKDIR}/docs
cp ${SOURCE_DIR}/README.txt   ${DISKDIR}/docs
cp ${SOURCE_DIR}/VERSION.txt  ${DISKDIR}/docs

echo /usr/bin/hdiutil create -ov -fs HFSX -layout SPUD -format UDZO \
-volname ${DMGBASE} -srcfolder ${DISKDIR} \
-imagekey zlib-level=9 -scrub ${DMGFINAL}

/usr/bin/hdiutil create -ov -fs HFSX -layout SPUD -format UDZO \
		 -volname ${DMGBASE} -srcfolder ${DISKDIR} \
		 -imagekey zlib-level=9 -scrub ${DMGFINAL}

echo ""
echo "Done creating ${DMGFINAL}."
echo ""
