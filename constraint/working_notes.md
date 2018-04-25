# Updating the online validator

* Follow the instructions found here: [http://sbml.org/SBML_Projects/Online_Validator_Release_procedure]
* Test the web api with the procedure found here: [http://sbml.org/validator/api/]

## In a nutshell

* run `update-libsbml.sh`
* restart service with monit

# Transplanting the SBML Online Validator to Ubuntu

## Validator setup

 * Rsync online-validator to local machine
 * Upgrade SVN repository
 * clean build directory
 * reconfigure with CMAKE, 
 * enable: packages, JAVA bindings, check
 * (ubuntu) include extra libraries: -lrt -lpthread -lsubunit
 * set install prefix to /opt/online-validator
 * set install lib to /opt/online-validator/lib
 
# Validator from scratch (Ubuntu 16.04)

Experiment with installation of validator from scratch using Ubuntu
native libraries/toolchains.

* install libSBML dependencies (see Ubuntu installation instructions)
* the web-app only works with Tomcat 7.0 and not 8!!!

Installing TomCat, instruction taken from [https://www.digitalocean.com/community/tutorials/how-to-install-apache-tomcat-8-on-ubuntu-16-04]

```
sudo apt-get update
sudo apt-get install default-jdk

sudo groupadd tomcat
sudo useradd -s /bin/false -g tomcat -d /opt/tomcat tomcat

```

Download latest Tomcat from [http://tomcat.apache.org/download-80.cgi]

Install into opt:

```
sudo mkdir /opt/tomcat
sudo tar xzvf apache-tomcat-8*tar.gz -C /opt/tomcat --strip-components=1

cd /opt/tomcat
sudo chgrp -R tomcat /opt/tomcat

sudo chmod -R g+r conf
sudo chmod g+x conf
sudo chown -R tomcat webapps/ work/ temp/ logs/


```

Setting up systemd init service

```
sudo nano /etc/systemd/system/tomcat.service
JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk-amd64

sudo systemctl daemon-reload
sudo systemctl start tomcat
sudo systemctl status tomcat

```
Update firewall

```
udo ufw allow 8080
```

Test by opening http://localhost:8080 in a browser.

Add users to management console:

```
sudo nano /opt/tomcat/conf/tomcat-users.xml

<user username="admin" password="thepassword" roles="manager-gui,admin-gui"/>
```

For remote access to the management panel:

```
sudo nano /opt/tomcat/webapps/manager/META-INF/context.xml
sudo nano /opt/tomcat/webapps/host-manager/META-INF/context.xml
```

Remove IP restriction:

```
<Context antiResourceLocking="false" privileged="true" >
  
</Context>
```

Restart Tomcat

```
sudo systemctl restart tomcat
```
	
Managemenat apps can be accessed:

* [http://localhost:8080/manager/html]
* [http://localhost:8080/host-manager/html/]

# Installing servlets

copy `validator_servlet` and `validator_ws` and wars to the webapps folder

## Servlet modifications

In the web configuration file `opt/tomcat/webapps/validator_servlet/WEB-INF/web.xml`

```
<!-- Comment the lines below out in case you don't run the validator on sbml.org   
        <session-config> 
           <cookie-config> <domain>.sbml.org</domain> <path>/Facilities/Validator</path> 
                </cookie-config> </session-config> -->
```

copy libsbml, libsbmlj and validator jars into lib

TODO: set java.library.path so that it contains libSBMLj




Brett
