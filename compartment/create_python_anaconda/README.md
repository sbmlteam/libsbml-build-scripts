# Creating an Anaconda Python binary from the Python source and uploading to conda cloud

* Unpack a copy of the "full" Python source archive `tar xf python-libsbml-experimental-<ver>.tar.gz`
* cd into your newly unpacked archive

Fire up your editor `nano setup.py` and look for this section of the code:

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
  print('No bdist_conda')

```

Now use Anaconda, the default Python, to build the binaries:

* run `python setup.py bdist_conda` to compile the Ananconda package
* Once you have a Conda package we need to upload it to the Anaconda cloud. 
* Log in to the Anaconda cloud first with `anaconda login`
* Upload with `anaconda upload --user SBMLTeam `/home/fbergman/anaconda2/conda-bld/linux-32/python-libsbml-experimental-5.15.2-py27h115b96f_0.tar.bz2`

The hashy thing after py27 is a Conda thing and can be ignored

UPDATE:

There are semi-automated scripts for generating conda packages for multiple Python versions.


