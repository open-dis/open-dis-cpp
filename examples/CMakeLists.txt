cmake_minimum_required(VERSION 3.2)
project(OpenDIS-Examples VERSION 1.0.0)

# include GNUInstallDirs Module to get more generic directory handling
include(GNUInstallDirs)

# set cmake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Require the OpenDIS6 target
if(NOT TARGET OpenDIS6)
  find_package(OpenDIS REQUIRED)
endif()

# SDL2 is required to build the examples
find_package(SDL2 REQUIRED)
find_package(SDL2_net REQUIRED)

# create list of ExampleSender source files
set(examplesender_src
  main.cpp
  Connection.cpp
  Utils.cpp
  Timer.cpp
)

# Define ExampleSender Executable
add_executable(ExampleSender ${examplesender_src})

# Link OpenDIS into ExampleSender
target_link_libraries(ExampleSender PRIVATE OpenDIS6 SDL2::Main SDL2::Net)

# create list of ExampleReceiver source files
set(examplereceiver_src
  main_receive.cpp
  Connection.cpp
  Utils.cpp
  Timer.cpp
  EntityStatePduProcessor.cpp
)

# Define ExampleReceiver Executable
add_executable(ExampleReceiver ${examplereceiver_src})

# Link OpenDIS into ExampleReceiver
target_link_libraries(ExampleReceiver PRIVATE OpenDIS6 SDL2::Main SDL2::Net)

# if Windows add M_PI definition
# - issues occurred during testing in Visual Studio
if (WIN32)
  target_compile_definitions(ExampleSender PRIVATE M_PI=3.14159265358979323846)
  target_compile_definitions(ExampleReceiver PRIVATE M_PI=3.14159265358979323846)
endif (WIN32)

install(TARGETS ExampleSender ExampleReceiver DESTINATION ${CMAKE_INSTALL_BINDIR})
