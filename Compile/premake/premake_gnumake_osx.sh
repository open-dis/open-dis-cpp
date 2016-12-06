pushd Projects
#export DIS_LIB_INSTALL="where you want the build system to send the binary library files to"
#export DIS_BIN_INSTALL="where you want the build system to send the other binary files to"
#export HAWKNL_INC_DIR="where the headers for HawkNL exist."
#export HAWKNL_LIB_DIR="where the library for HawkNL exists."
../premake.osx --file DIS.lua --target gnu
../premake.osx --file DIS.lua --target vs2003
../premake.osx --file DIS.lua --target vs2005
popd
