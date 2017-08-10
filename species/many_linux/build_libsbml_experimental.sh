#!/bin/bash

for PYBIN in /opt/python/*/bin; do
    ${PYBIN}/pip wheel --no-binary :all: python-libsbml-experimental
done

# Bundle external shared libraries into the wheels
for whl in *.whl; do
    auditwheel repair $whl -w /io/wheelhouse/
done
