#!/bin/bash
ROOT_DIR=/opt/online-validator
WEB_ROOT=$ROOT_DIR/apache-tomcat-7.0.12
WEB_APPS=$WEB_ROOT/webapps/
WEB_LIB=$WEB_ROOT/lib/
UPLOAD_DIR=$ROOT_DIR/upload

cp $UPLOAD_DIR/validator.jar $ROOT_DIR/lib
cp $UPLOAD_DIR/validator.jar  $WEB_LIB
cp $UPLOAD_DIR/validator.jar ~/lib

cp $UPLOAD_DIR/validator_servlet.war $WEB_APPS
cp $UPLOAD_DIR/validator_ws.war $WEB_APPS
