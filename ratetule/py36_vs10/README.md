# Compiling Python 3.6 bindings with Visual Studio 2010

It turns out Python 3.6 targets C99 and requires a header file not available by default in VS versions pre-2013 (it is considered a no-fix issue for Python 3.6+ see https://bugs.python.org/issue29244). The consensus here (https://www.pivotaltracker.com/story/show/152235559) is that we will add the missing header file (`inttypes.h`):

* Download header from https://code.google.com/archive/p/msinttypes/
* https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/msinttypes/msinttypes-r26.zip
* copy `inttypes.h` from zip archive to `c:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\include\`

Enable Python 3.6 support in the following files found in c:\buildtool

```
buildPython.in 
createXMLRel_x86.in 
reateXMLRel_x64.in 
```


