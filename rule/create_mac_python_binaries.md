# Create the Python OSX binaries

Once you have a tested/working Python source archive, go to ~/work and create a build_whl directory. Unpack the trunk and experimental
source arhives into this directory and run:

```
python setup.py build
python setup.py bdist_wheel
```

For both Python source archives, this generates the OSX Wheels. Copy the generated wheels, together with the source archives to an
upload folder.
