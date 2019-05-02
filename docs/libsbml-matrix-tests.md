# libSBML option matrix configuration test documentation

## Overview and VM configuration
The matrix configuration test tool's function is to enable the efficient testing and reporting of multiple configuration/build options. It is currently set up to run on Python 3 and Linux is located in two directories in the `auto-build-options` branch of the `libsbml-build-scripts` repository.

- The `autobuild-vm-configs` folder contains documents describing how to setup libSBML build environments for various flavours of linux. These files can be used to set up native build environments using the default packageing system (apt, dnf, etc) and include the dependencies for all three possible XML parsers, as well as Python 2/3, Java, C#, Perl, R and Ruby bindings and PyPI packages needed for the matrix test generator. Each file represents a specific OS flavour/version, for example:
  - setup-libsbml-dev-fedora30-64.md 
  - setup-libsbml-dev-disco64.md
- The `autobuild-option-tests` folder contains the actual tool, configuration files and generated reports.

As part of the VM configuration the you would have cloned this repository and switched to the `auto-build-options` branch ... you are now ready to run the matrix configuration tool.

## Running the matrix configuration tool

Open and terminal in your new VM and change to the `autobuild-option-tests` directory. To run the matrix configuration test tool:

```
$ python3 run_matrix_tests.py <configfile>.json
```

In this folder you you will find CMakeCache template files (note the one that matches your current OS version):

- fedora-30-ninja-base-CMakeCache.txt 
- ubuntu-1904-ninja-base-CMakeCache.txt 
- ubuntu-1604-ninja-base-CMakeCache.txt 

The Python source code:
- `run_matrix_tests.py` the main script, call with a configuration file as an argument.
- `testlib.py` a predefined library of test configurations, feel free to add your own.
- `generate_matrix_report.py` the report generator, by default called automatically
- `templatetools.py` a converter class for manipulating CMakeCache file based on options contained in the configuration files.

Configuration files are stored in JSON format and can be customised to run any flavour of tests. Two predifined files are provided to get started:

- `config.json` a template configuration for testing the stable trunk
- `config-exp.json`  a template for testing the experimental branch

### Sample trunk test configuration

```json
{
 "options": {
  "build_test_configurations": true,
  "check_test_configurations": true,
  "disk_space_saver": true,
  "cmake_generator": "Ninja",
  "configure_with_cmake": true,
  "configure_experimental": false,
  "test_all_combinations": false,
  "config_combination" : "all_xml2"
 },
 "paths": {
  "libsbml_exp_src_path": "/home/libsbml/development/sf_libsbml_experimental",
  "libsbml_src_path": "/home/libsbml/development/sf_libsbml",
  "template_libsbml_source_path": "/home/sbml/development/sf_libsbml",
  "base_file": "ubuntu-1904-ninja-base-CMakeCache.txt"
 },
 "tests": {
  "default": [["check"]]
 }
}

```
The configuration file is divided into three sections two of which are currently used `options` and `paths`:
- `libsbml_exp_src_path` the path to the libSBML **experimental** source code
- `libsbml_src_path` the path to the libSBML **trunk** source code
- `template_libsbml_source_path` this is an internal option that refers the path to the libSBML source code **as defined in the CMakeCache template**. For the supplied templates this can be left at its default value.
- `base_file` this is the name of the the CMakeCache template of configured for the current OS version.

The `options` section contains various configuration options:
- `config_combination` this option selects a configuration option set as defined in `testlib.py`.
- `build_test_configurations` try to build the generated configurations, this should generally be left at its default value, *true*.
- `check_test_configurations` try to run ctest on the the built configurations, this should generally be left at its default value, *true*.
- `disk_space_saver` this option greatly affects the amount of disk space used by the matrix configuration tool. When enabled all intermediate build/test files are deleted when the build is successful (even if the unittest check fails). When disables all intermedieate build files are retained. As an indication if fourty build/test confiurations are retuned this can require 60+ GB of disk space.
- `cmake_generator` this sets the cmake genrator to use to build, by default the faster *ninja* is used, alternatively this can be set to *Unix Makefiles*.
- `configure_with_cmake` generate CMake configurations for the selected configuration options, this should generally be left at its default value, *true*.
- `configure_experimental` should the matrix test use trunk (`false`) or experimental (`true`).
- `test_all_combinations` this option causes the matrix test generator to create configurations for all option combinations (of all lengths). Note, use with caution, this can generate a large number of configurations and overides any selected option set.

## Report generation and analysis of the results of a configuration tests.

By default the `run_matrix_tests.py` script automatically calls the report generator. As part of the configuration/build/test cycle the results of the individual ctests are stored in the `<cdir>/reports/<date-time>` folder. As the testing proceeds that results are stored in *csv* format files in the aforementioned directory. Once all all tests are complete, information is collated and stored in an Excel spreadsheet.

### Format of the generated Excel spreadsheet report.

The result generator creates an *.xlsx* spreadsheet in `<cdir>/reports/<date-time>`. This spreadsheet has four worksheets:
- `Configure` results of the Cmake configuration step
- `Build` results of the ninja *build* step
- `Check` results of the Ctest unit tests
- `Info` general metadata about the test set

For each sheet the the first n-1 columns are the configuration options, each row being a single test. The final column is the result of the operation with **1** being successful and **0** failure. Failured rows are also presented in red.

(C) Brett G. Olivier for the SBML Team distributed under a CC-BY-4.0 licence, Amsterdam, 2019.