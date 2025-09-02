cmake_minimum_required(VERSION 3.2)
project(OpenDIS VERSION 1.1.0)

# Build options
option(BUILD_SHARED_LIBS "build shared libraries" OFF)
option(BUILD_EXAMPLES "build example sender/receiver applications" OFF)
option(BUILD_TESTS "build unit tests" OFF)

option(BUILD_OPENDIS6 "build OpenDIS6" ON)
option(BUILD_OPENDIS7 "build OpenDIS7" ON)

# Enforce a C++11 compliant compiler
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# include GNUInstallDirs Module to get more generic directory handling
include(GNUInstallDirs)

# Define OpenDIS6 Library
if(BUILD_OPENDIS6)
  add_library(OpenDIS6 "")

  target_compile_options(OpenDIS6 PRIVATE
      $<$<CXX_COMPILER_ID:GNU>:-Wno-attributes>
      $<$<CXX_COMPILER_ID:Clang>:-Wno-attributes>
  )

  # Add src/ to the include directories to OpenDIS6
  target_include_directories(OpenDIS6
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
          $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

  if(WIN32)
    target_link_libraries(OpenDIS6 PRIVATE ws2_32)
  endif()
endif()

if(BUILD_OPENDIS7)
  # Define OpenDIS7 Library
  add_library(OpenDIS7 "")

  target_compile_options(OpenDIS7 PRIVATE
      $<$<CXX_COMPILER_ID:GNU>:-Wno-attributes>
      $<$<CXX_COMPILER_ID:Clang>:-Wno-attributes>
  )

  # Add src/ to the include directories to DIS7
  target_include_directories(OpenDIS7
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
          $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

  if(WIN32)
  target_link_libraries(OpenDIS7 PRIVATE ws2_32)
  endif()
endif()

# Add source directories
add_subdirectory(src)
add_subdirectory(cmake)

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
if(BUILD_OPENDIS6)
  install(TARGETS OpenDIS6
          EXPORT OpenDISTargets
          RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
          LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
          ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

if(BUILD_OPENDIS7)
  install(TARGETS OpenDIS7
        EXPORT OpenDISTargets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

install(EXPORT OpenDISTargets
        NAMESPACE OpenDIS::
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/OpenDIS")

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
