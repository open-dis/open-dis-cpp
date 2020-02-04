# open-dis-cpp
A C++ implementation of the Distributed Interactive Simulation (DIS) protocol.
Initially generated with [xmlpg](https://github.com/open-dis/xmlpg).

[![Travis (Linux) Build Status](https://travis-ci.org/open-dis/open-dis-cpp.svg?branch=master)](https://travis-ci.org/open-dis/open-dis-cpp)
[![CodeDocs status](https://codedocs.xyz/open-dis/open-dis-cpp.svg)](https://codedocs.xyz/open-dis/open-dis-cpp/)

## Building Open DIS

* [premake5](http://premake.github.io/) is required to build the platform specific projects. Download it and make sure it's available on your path, or specify the path to it. 

* SDL2 and SDL2_net are required libraries to compile the examples. See the [.travis.yml](.travis.yml) for more details on setting up a build environment.

### Linux / GNU Makefiles

1. Run `mkdir build`
1. Run `cd build`
1. Run `cmake ..`
  1. Optionally, `-DCMAKE_INSTALL_PREFIX=<custom-path-to-install>` to set a custom directory to install the bin, include, and lib output directories.
1. Run `make` - this will output the libOpenDIS6.so, and libOpenDIS7.so libraries in the build directory along with the Example Applications.
1. The below steps are optional
  1. Run `make package` to build linux package files. Currently this will produce a RedHat RPM package, Debian DEB package, and 2 compressed tarball (XZ, GZ).
  1. Run `make install` to install bin, lib, and dir, into `CMAKE_INSTALL_PREFIX`
     WARNING: `CMAKE_INSTALL_PREFIX` default can to somewhere `/usr/local/`, if not specified with the `-D` flag as shown in Step 3.1.
     If you're unsure where to install, and want to keep your `/usr/local/` directory clean, run `cmake .. -DCMAKE_INSTALL_PREFIX=./install`.
     This will cause `make install` to create a local install directory, from which you can move files elsewhere at a later date.



### Old Pre-make build instructions
#### Linux / GNU Makefiles
1. Run `premake5 gmake`
1. Run `make config=release`


#### Windows with Visual Studio 2015
1. Run `premake5 vs2015`
1. Open the solution and build.

## Developer Docs

The latest doxygen docs for the Open DIS master branch can be found [here](https://codedocs.xyz/open-dis/open-dis-cpp/).
