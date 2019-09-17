# open-dis-cpp
A C++ implementation of the Distributed Interactive Simulation (DIS) protocol.
Initially generated with [xmlpg](https://github.com/open-dis/xmlpg).

[![Travis (Linux) Build Status](https://travis-ci.org/open-dis/open-dis-cpp.svg?branch=master)](https://travis-ci.org/open-dis/open-dis-cpp)
[![CodeDocs status](https://codedocs.xyz/open-dis/open-dis-cpp.svg)](https://codedocs.xyz/open-dis/open-dis-cpp/)

## Building Open DIS

* [premake5](http://premake.github.io/) is required to build the platform specific projects. Download it and make sure it's available on your path, or specify the path to it. 

* SDL2 and SDL2_net are required libraries to compile the examples. See the [.travis.yml](.travis.yml) for more details on setting up a build environment.

### Linux

1. Run `premake5 gmake`
1. Run `make config=release`

### Windows

1. Run `premake5 vs2015`
1. Open the solution and build.

## Developer Docs

The latest doxygen docs for the Open DIS master branch can be found [here](https://codedocs.xyz/open-dis/open-dis-cpp/).
