# open-dis-cpp
A C++ implementation of the Distributed Interactive Simulation (DIS) protocol


[![Travis (Linux) Build Status](https://travis-ci.org/open-dis/open-dis-cpp.svg?branch=master)](https://travis-ci.org/open-dis/open-dis-cpp)

## Git submodule
This repository includes a git submodule for the XML descripton files. These
files contain a machine-readable description of the DIS messages that are 
translated into a language implementation. Since the XML file is shared across
multiple languages, I'm trying to prevent between-language drift of the description
file.

You should only need this if you're regenerated the source code, which is unlikely.
but if you are, bring in the submodule with

~~~~
git submodule init
git submodule update
~~~~
