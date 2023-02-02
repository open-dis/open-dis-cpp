# open-dis-cpp
A C++ implementation of the Distributed Interactive Simulation (DIS) application protocol IEEE-1278.

Note: This code base was originally auto generated with [xmlpg](https://github.com/open-dis/xmlpg).

[![Travis (Linux) Build Status](https://app.travis-ci.com/open-dis/open-dis-cpp.svg?branch=master)](https://app.travis-ci.com/open-dis/open-dis-cpp)
[![Build status](https://ci.appveyor.com/api/projects/status/nt6t12a654j91osg?svg=true)](https://ci.appveyor.com/project/leif81/open-dis-cpp)
[![CodeDocs status](https://codedocs.xyz/open-dis/open-dis-cpp.svg)](https://codedocs.xyz/open-dis/open-dis-cpp/)

## Building Open DIS

* [CMake](http://cmake.org/) is required to build the platform specific projects.
  It can be downloaded and installed from http://cmake.org/

* SDL2 and SDL2_net are required libraries to compile the examples.
  These can usually be install via Linux package managers.
  More details, and instructions for Windows are included [below](#SDL2-and-SDL2_net-Install-Instructions).

  **NOTE:** Windows users will need to either add the DLL folders to their path, or copy the DLLs to the output directory (`Debug`).

### OpenDIS Build Options

The OpenDIS build system accepts several build options to control compilation. The following options are available:

* **BUILD_SHARED_LIBS** - Boolean value to specify whether to build OpenDIS libraries as shared (ON/TRUE) or static (OFF/FALSE). Default is ON.
* **BUILD_EXAMPLES** - Boolean value to specify whether to build example sender/receiver applications. Default is OFF.
* **BUILD_TESTS** - Boolean value to specify whether to build unit tests. Default is OFF.

Example application build options. Only valid if **BUILD_EXAMPLES** is enabled.

* **SDL2_PATH** - Installation path of SDL2
* **SDL2_NET_PATH** - Installation path of SDL2_net

These options are passed to cmake as arguments. Example: `cmake -DBUILD_SHARED_LIBS=ON -DBUILD_EXAMPLES=ON ..`

### Linux / GNU Makefiles

1. Run `mkdir build`
1. Run `cd build`
1. Run `cmake ..`
  1. Optionally, `-DCMAKE_INSTALL_PREFIX=<custom-path-to-install>` to set a custom directory to install the bin, include, and lib output directories.
1. Run `make` - this will output the libOpenDIS6.so, and libOpenDIS7.so libraries in the build directory along with the Example Applications.
1. The below steps are optional
  1. Run `make package` to build Linux package files. Currently this will produce a Red Hat RPM package, Debian DEB package, and 2 compressed tarball (XZ, GZ).
  1. Run `make install` to install bin, lib, and dir, into `CMAKE_INSTALL_PREFIX`
     WARNING: `CMAKE_INSTALL_PREFIX` default can to somewhere `/usr/local/`, if not specified with the `-D` flag as shown in Step 3.1.
     If you're unsure where to install, and want to keep your `/usr/local/` directory clean, run `cmake .. -DCMAKE_INSTALL_PREFIX=./install`.
     This will cause `make install` to create a local install directory, from which you can move files elsewhere at a later date.

#### Windows with Visual Studio
1. Open `CMake (cmake-gui)` via the the start menu.
2. Enter the open-dis-cpp directory path into the Source and Build fields.
3. Click the `+ Add Entry` button and enter the following details:
  Name: `SDL2_PATH`
  Type: `PATH`
  Value: `<SDL2-install-folder>`
  (if you follow the below [SDL2 Windows Install Instruction](#Windows-Install-Instructions) this will be `C:/SDL2`)
3. Click the `+ Add Entry` button and enter the following details:
  Name: `SDL2_NET_PATH`
  Type: `PATH`
  Value: `<SDL2-install-folder>`
  (if you follow the below [SDL2 Windows Install Instruction](#Windows-Install-Instructions) this will be `C:/SDL2`)
3. Click the `+ Add Entry` button and enter the following details:
  Name: `CMAKE_LIBRARY_ARCHITECTURE`
  Type: `STRING`
  Value: `x64` (64 bit) or `x86` (32 bit)
4. Click Configure and follow the prompts, selecting the correct generator (i.e. Visual Studio version).
5. Click Generate
6. Click Open Project - This should open the generates solution file in Visual Studio
7. Build the Solution (`Ctrl + Shift + B`)

These steps were tested with Visual Studio 16 2019 (Community Edition).
Currently, only OpenDIS 6 and the Example Applications compile.
The library and executable files are output to a `Debug` directory.

To run the executables, either the value of the `SDL2_PATH/lib/CMAKE_LIBRARY_ARCHITECUTRE` should be added to your path,
or `SDL2.dll` and `SDL2_net.dll` need to be copied to the `Debug` directory.

### Cleaning CMake files

To quickly clean up CMake output files, use `git clean -xdf`.
**Note:** Use with care if you are actually developing open-dis-cpp, as `git clean` removes untracked files.

### Old Pre-make build instructions

* [premake5](http://premake.github.io/) is required to build the platform specific projects. Download it and make sure it's available on your path, or specify the path to it.

#### Linux / GNU Makefiles
1. Run `premake5 gmake`
1. Run `make config=release`


#### Windows with Visual Studio 2015
1. Run `premake5 vs2015`
1. Open the solution and build.

## Developer Docs

The latest doxygen docs for the Open DIS master branch can be found [here](https://codedocs.xyz/open-dis/open-dis-cpp/).

## SDL2 and SDL2_net Install Instructions

### Linux Package Managers

Arch: ```sudo pacman -S sdl2 sdl2_net```

Fedora: ```sudo dnf install SDL2-devel SDL2_net-devel```

Ubuntu: ```sudo apt-get install libsdl2-dev libsdl2-net-dev```

If you're unable to install the correct packages, try [installing from source](#POSIX-Source-Installation)

### Windows Install Instructions

These are the installation steps that have been tested with open-dis-cpp, however there are other methods for installation.
Experienced users should feel free to customise their install.

#### (Core) SDL2 Instructions

1. Navigate to the SDL2 [Download](https://www.libsdl.org/download-2.0.php) page, and download the latest Development Libraries.

   Alternatively, the version tested with open-dis-cpp, 2.0.12-VC, can be downloaded from this [direct link](https://www.libsdl.org/release/SDL2-devel-2.0.12-VC.zip).

2. Extract the SDL2-devel-2.0.12-VC.zip file directly to your `C:\`.
3. Rename the resulting `SDL2-2.0.12` folder to `SDL2`.
4. Add `C:\SDL2\lib\x64` to your System Path for 64-bit systems,
   or add `C:\SDL2\lib\x86` for 32-bit systems.

#### SDL2_net Instructions

1. Navigate to the SDL2_net [project](https://www.libsdl.org/projects/SDL_net/) page, and download the latest Development Libraries.

   Alternatively, the version tested with open-dis-cpp, 2.0.1-VC, can be downloaded from this [direct link](https://www.libsdl.org/projects/SDL_net/release/SDL2_net-devel-2.0.1-VC.zip).

2. Extract the SDL2-devel-2.0.12-VC.zip
3. Copy the `include` and `lib` directories from the resulting folder into you `C:\SDL2\` folder

### POSIX Source Installation

#### (Core) SDL2
Run the following commands:
1. `wget http://libsdl.org/release/SDL2-2.0.12.tar.gz`

   Or, Download via your favourite web browser.

   **NOTE:** check the [download](https://www.libsdl.org/download-2.0.php) page for new releases

2. `tar -xvf SDL2-2.0.9.tar.gz`
3. `pushd SDL2-2.0.9/`
4. `./configure --prefix=/usr && make && sudo make install`
5. `popd`

#### SDL2_net
1. `wget https://www.libsdl.org/projects/SDL_net/release/SDL2_net-2.0.1.tar.gz`

   Or, Download via your favourite web browser.

   **NOTE:** check [https://www.libsdl.org/projects/SDL_net](project) page for new releases

2. `tar -xvf SDL2_net-2.0.1.tar.gz`
3. `pushd SDL2_net-2.0.1/`
4. `./configure --prefix=/usr && make && sudo make install`
5. `popd`
