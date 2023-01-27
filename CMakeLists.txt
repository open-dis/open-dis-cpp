cmake_minimum_required(VERSION 3.2)
project(OpenDIS VERSION 1.0.0)

# Build options
option(BUILD_SHARED_LIBS "build shared libraries" ON)
option(BUILD_EXAMPLES "build example sender/receiver applications" OFF)
option(BUILD_TESTS "build unit tests" OFF)

# include GNUInstallDirs Module to get more generic directory handling
include(GNUInstallDirs)

# Define OpenDIS6 Library
add_library(OpenDIS6 "")

# Add src/ to the include directories to OpenDIS6
target_include_directories(OpenDIS6
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Define OpenDIS7 Library
add_library(OpenDIS7 "")

# Add src/ to the include directories to OpenDIS6
target_include_directories(OpenDIS7
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Add compile definition EXPORT_LIBRARY for shared libs
if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(OpenDIS6 PRIVATE OpenDIS6_STATIC_DEFINE)
  target_compile_definitions(OpenDIS7 PRIVATE OpenDIS7_STATIC_DEFINE)
endif()

# Add source directories
add_subdirectory(src)

# Build example applications
if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

# Build tests
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()

# Configure install target (i.e. what files to install)
install(TARGETS OpenDIS6 EXPORT OpenDIS6Config DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(EXPORT OpenDIS6Config DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/OpenDIS6")
install(TARGETS OpenDIS7 EXPORT OpenDIS7Config DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(EXPORT OpenDIS7Config DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/OpenDIS7")

# configure package target (i.e. Package Types, and meta data)
set(CPACK_GENERATOR "DEB" "RPM" "TXZ" "TGZ")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_NAME "OpenDis")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The open DIS cpp library")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}.${CMAKE_SYSTEM_PROCESSOR}")
set(CPACK_PACKAGE_RPM_DIR "${CMAKE_CURRENT_BINARY_DIR}/_CPack_Packages/Linux/RPM")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Leif Gruenwoldt <leifer@gmail.com>")
set(CPACK_PACKAGE_PACKAGER $ENV{USER})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The open DIS cpp library")
include(CPack)
