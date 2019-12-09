####################################################################
# Standard Build Directives
####################################################################
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


# Extra Build Directives
set(PROJECT_BUILD_DATE string(TIMESTAMP TODAY "%Y-%m-%d"))


# macOS requires additional compiler flags
if(APPLE)
  set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif()

# see : https://crascit.com/2016/04/09/using-ccache-with-cmake/
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
else()
  message("ccache not found, repeated builds will be faster if this program is installed")
endif()

###########################################################
# Project Info
###########################################################
project (open-dis)
set(PROJECT_DESCRIPTION "OpenDIS DIS Libraries")

set(PROJECT_VERSION_MAJOR "1")
set(PROJECT_VERSION_MINOR "0")
set(PROJECT_VERSION_PATCH "0")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(PROJECT_VERSION_DATE "${PROJECT_BUILD_DATE}")

# specify an install location if one hasn't already been specified
if(NOT CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX /usr/local)
endif()

# fetch all the local directories for generated code
get_filename_component(PROJECT_LIB_DIR ${PROJECT_BINARY_DIR}/lib ABSOLUTE)
get_filename_component(PROJECT_BIN_DIR ${PROJECT_BINARY_DIR}/bin ABSOLUTE)
get_filename_component(PROJECT_INC_DIR ${PROJECT_BINARY_DIR}/include ABSOLUTE)
get_filename_component(PROJECT_SRC_DIR ./src ABSOLUTE)
get_filename_component(PROJECT_EXAMPLES_DIR ./examples ABSOLUTE)
get_filename_component(PROJECT_EXAMPLES_INC_DIR ./examples ABSOLUTE)
get_filename_component(PROJECT_PATCHES_DIR ./patches ABSOLUTE)
get_filename_component(PROJECT_TEST_DIR ./test ABSOLUTE)
get_filename_component(PROJECT_MODULES_DIR ./cmake/Modules ABSOLUTE)


# append this project's path to the cmake modules path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_MODULES_DIR})

# Include some cmake modules to call
# This module gets the name of all subdirs of a dir
include(MacroSubDirList)
include(MacroAddExternalTarget)


# Release or Debug, if build type isn't specified, set it to Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
    "Choose the type of build, options are: Debug Release
      RelWithDebInfo MinSizeRel." FORCE)
endif()


# set the cmake path defaults for libraries and binaries
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR} CACHE PATH
  "Output directory for the dynamic libraries" )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR} CACHE PATH
  "Output directory for the binaries" )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR} CACHE PATH
  "Output directory for the static libraries (archives)" )


########################################################
# Consolidate Include Files
########################################################
file(MAKE_DIRECTORY ${PROJECT_INC_DIR})


########################################################
# Find Packages
########################################################
# Required packages:  links { "OpenDIS", "SDL2", "SDL2_net" }
find_package(SDL2 REQUIRED)
find_package(SDL2_net REQUIRED)

# This may or may not be required?
# find_package(OpenDIS REQUIRED)
include_directories(${OPENDIS_INCLUDE_DIR})


########################################################
# Recurse into src, examples, and tests
########################################################
add_subdirectory(src)
add_subdirectory(examples)


# Build Documentation
option(BUILD_DOCS "Build documentation" OFF)
if(BUILD_DOCS)
  add_subdirectory(docs)
endif()


########################################################
# Tests 
########################################################
# Skip building tests
option(BUILD_TESTS "BUILD_TESTS" OFF)


###############################################################################
# Cleaning 
###############################################################################

# Add a distclean target to the Makefile
set(DIST_CLEAN_DIRS "${PROJECT_LIB_DIR};${PROJECT_BIN_DIR};${CMAKE_BINARY_DIR}")
add_custom_target(distclean
  COMMAND ${CMAKE_COMMAND} -DDIRS_TO_REMOVE="${DIST_CLEAN_DIRS}" -P ${PROJECT_SOURCE_DIR}/cmake/Modules/distclean.cmake
)


###############################################################################
# Installation
###############################################################################
include(CMakePackageConfigHelpers)

# Setup install directories for 
set(INCLUDE_INSTALL_DIR include/ CACHE PATH "Include install dir")
set(LIB_INSTALL_DIR lib/ CACHE PATH "Library install dir")
set(CMAKE_CONFIG_DEST "${LIB_INSTALL_DIR}/${PROJECT_NAME}/cmake")

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/project-config.cmake.in
  ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  INSTALL_DESTINATION ${PROJECT_BINARY_DIR}
  PATH_VARS INCLUDE_INSTALL_DIR
)

write_basic_package_version_file(
  ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

# Add all library targets to the build-tree export set
export(TARGETS ${PROJECT_LIBS} ${PROJECT_EXAMPLES}
  FILE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-targets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry ~/.cmake)
export(PACKAGE ${PROJECT_NAME})


#############################################################################
# Generate the cmake configuration files for the install tree
#############################################################################
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/project-config.cmake.in
  ${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}-config.cmake
  INSTALL_DESTINATION ${CMAKE_CONFIG_DEST}
  PATH_VARS INCLUDE_INSTALL_DIR
)

write_basic_package_version_file(
  ${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}-config-version.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

# Install cmake config files
install(FILES ${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}-config.cmake
  ${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}-config-version.cmake
  DESTINATION ${CMAKE_CONFIG_DEST})

# install export targets
# install(
#   EXPORT ${PROJECT_NAME}-targets
#   DESTINATION ${CMAKE_CONFIG_DEST}
# )


#############################################################################
# Install Targets
#############################################################################

# Install all header files under include/PROJECT_NAME
install(
  DIRECTORY ${PROJECT_BINARY_DIR}/include/
  DESTINATION include/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.h"
)

# Create the ld.so.conf.d/project.conf file
if(NOT APPLE)
  file(WRITE
    ${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}.conf
    "${CMAKE_INSTALL_PREFIX}/lib\n"
    )
  option(ENABLE_LD_SO_CONF_INSTALL "Install ${PROJECT_NAME}.conf to /etc/ld.so.conf.d" OFF)
  if(ENABLE_LD_SO_CONF_INSTALL)
    install(
      FILES ${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}.conf
      DESTINATION /etc/ld.so.conf.d
      )
  endif()
endif()




###############################################################################
# Binary installation generation
###############################################################################
set(CPACK_INSTALL_CMAKE_PROJECTS "${PROJECT_BINARY_DIR};${PROJECT_NAME};ALL;/")
set(CPACK_OUTPUT_CONFIG_FILE "${PROJECT_BINARY_DIR}/CPackConfig.cmake")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_DESCRIPTION}")
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "Tara Madden")
set(CPACK_PACKAGE_VENDOR "GTRI")
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
include(CPack)

