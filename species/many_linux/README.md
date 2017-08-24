# Creating Linux Python wheels

These scripts generate a variety of libSBML Linux wheels for PyPI using ManyLinux containers, this can takes some time. The ManyLinux build depends on the source package being available on PyPI, so that `pip install` will work. Depending on the release being built, one of: 

* `run_libsbml.sh` or
* `run_libsbml_experimental.sh`

should be executed in the build directory that contains the following scripts. Each one in turn is run on the 32 and 64 bit containers. 

* build_libsbml.sh
* build_libsbml_experimental.sh

NOTE! Root (sudo) level access is required to run docker containers.

TODO: Python 2.6 support is being deprecated in many_linux so should be removed from the build.
