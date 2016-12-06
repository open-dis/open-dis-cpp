pushd Projects
rem set DIS_LIB_INSTALL="where you want the build system to send the binary library files to"
rem set DIS_BIN_INSTALL="where you want the build system to send the other binary files to"
rem set HAWKNL_INC_DIR="where the headers for HawkNL exist."
rem set HAWKNL_LIB_DIR="where the library for HawkNL exists."
premake --file DIS.lua --target vs2003 
popd
pause