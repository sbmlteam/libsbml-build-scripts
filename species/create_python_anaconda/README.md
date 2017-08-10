# Creating an Anaconda Python binary from the Python source and uploading to conda cloud

* Unpack a copy of the "full" Python source archive `tar xf python-libsbml-experimental-<ver>.tar.gz`
* cd into your newly unpacked archive

Fire up your editor `nano setup.py` and look for this section of code

```
try:
  from setuptools import setup, Extension, Command
except ImportError:
  from distutils.core import setup, Extension
```
or 

```
from distutils.core import setup, Extension

```

and simply add the following lines.

```
try:
    import distutils.command.bdist_conda
except:
    pass  

```

Now use Anaconda to build the Anaconda binaries. Anaconda Python lives in `` so we need to call its Python binary, assuming we are in ~/work/<archive>

* run `../../anaconda2/bin/python setup.py bdist_conda` this will compile the Ananconda package
* Once you have a Conda package we need to upload it to the Anaconda cloud. 
* Log in to the Anaconda cloud first id you need to `../anaconda2/bin/anaconda login`
* upload with `../anaconda2/bin/anaconda upload --user SBMLTeam /Users/frank/anaconda2/conda-bld/osx-64/python-libsbml-experimental-<ver>-py27_0.tar.bz2`





