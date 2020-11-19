cmake_minimum_required(VERSION 3.14)

project(OpenDIS
        VERSION 0.1.0
        LANGUAGES CXX
      )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


option(WERROR "Add -Werror flag to build (turns warnings into errors)" ON)
# Default options
option(OpenDIS_ENABLE_EXAMPLES "Enable the examples for OpenDIS" ON)

# Set CMake Install directories for OpenDIS
set(OpenDIS_INSTALL_LIB_DIR lib CACHE PATH "Installation path for OpenDIS library files")
set(OpenDIS_INSTALL_BIN_DIR bin CACHE PATH "Installation path for OpenDIS binary files")
set(OpenDIS_INSTALL_INCLUDE_DIR include/ CACHE PATH "Installation path for header files")
if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/OpenDIS)
endif()
set(OpenDIS_INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation path for OpenDIS CMake files")

if ( NOT MSVC)
  # configure optimization
  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
      set(OPTIMIZATION_FLAGS "-O0 -DDEBUG")
      message("-- Configuring debug build")
  else()
      set(OPTIMIZATION_FLAGS "-O3 -DNDEBUG")
      message("-- Configuring release build")
  endif()

  set(DESIRED_WARNINGS "-Wall -Wextra -Wconversion -Wunreachable-code -Wuninitialized -pedantic-errors -Wold-style-cast -Wno-error=unused-variable -Wshadow -Wfloat-equal -Weffc++")
  if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(DESIRED_WARNINGS "${DESIRED_WARNINGS} -Wmost")
  endif()

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OPTIMIZATION_FLAGS}")

  if (WERROR)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
  endif()
endif( NOT MSVC)

# Add libraries
add_subdirectory(src)


if (OpenDIS_ENABLE_EXAMPLES)
  add_subdirectory("examples")
endif (OpenDIS_ENABLE_EXAMPLES)


## Example Programs
# include_directories(.)

# if Windows add M_PI dfinition
# - issues occurred during testing in Visual Studio
# if (WIN32)
#   add_definitions(/DM_PI=3.14159265358979323846)
# endif (WIN32)

# # create list of ExampleSender source files
# file(GLOB EX_SENDER_SOURCES
#   "examples/main.cpp"
#   "examples/Connection.cpp"
#   "examples/Utils.cpp"
#   "examples/Timer.cpp"
# )



# #--------------------------------------------------------------------------------------

# # include GNUInstallDirs Module to get more generic directory handling
# include(GNUInstallDirs)
# IF(NOT DEFINED LIBDIR)
#   set(LIBDIR "lib")   # Was not defined on Travis CI
# ENDIF(NOT DEFINED LIBDIR)
# # Configure install target (i.e. what files to install)
# install(TARGETS OpenDIS6 EXPORT OpenDIS6Config DESTINATION "${LIBDIR}")
# install(EXPORT OpenDIS6Config DESTINATION "lib/cmake/OpenDIS6")
# install(TARGETS OpenDIS7 EXPORT OpenDIS7Config DESTINATION "${LIBDIR}")
# install(EXPORT OpenDIS7Config DESTINATION "lib/cmake/OpenDIS7")
# install(TARGETS ExampleReceiver ExampleSender DESTINATION "bin")
# install(DIRECTORY src/ DESTINATION "include"
#         FILES_MATCHING PATTERN "*.h"
# )

# # configure package target (i.e. Package Types, and meta data)
# set(CPACK_GENERATOR "DEB" "RPM" "TXZ" "TGZ")
# set(CPACK_PACKAGE_VERSION 1.0.0)
# set(CPACK_PACKAGE_NAME "OpenDis")
# set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The open DIS cpp library")
# set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}.${CMAKE_SYSTEM_PROCESSOR}")
# set(CPACK_PACKAGE_RPM_DIR "${CMAKE_CURRENT_BINARY_DIR}/_CPack_Packages/Linux/RPM")
# set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Leif Gruenwoldt <leifer@gmail.com>")
# set(CPACK_PACKAGE_PACKAGER $ENV{USER})
# set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The open DIS cpp library")
# include(CPack)
