cmake_minimum_required(VERSION 3.2)
project(OpenDIS)

## Libraries
include_directories(src)

file(GLOB DIS6_SOURCES
  "src/dis6/*.cpp"
  "src/utils/*.cpp"
)
add_library(OpenDIS6 SHARED ${DIS6_SOURCES})

file(GLOB DIS7_SOURCES
  "src/dis7/*.cpp"
  "src/utils/*.cpp"
)
add_library(OpenDIS7 SHARED ${DIS7_SOURCES})


## Example Programs
include_directories(.)
set(LIB_FLAGS "-lSDL2 -lSDL2_net")

file(GLOB EX_SENDER_SOURCES
  "examples/main.cpp"
  "examples/Connection.cpp"
  "examples/Utils.cpp"
  "examples/Timer.cpp"
)

add_executable(ExampleSender ${EX_SENDER_SOURCES})
target_link_libraries(ExampleSender ${LIB_FLAGS})
target_link_libraries(ExampleSender OpenDIS6)

file(GLOB EX_RECEIVER_SOURCES
  "examples/main_receive.cpp"
  "examples/Connection.cpp"
  "examples/Utils.cpp"
  "examples/Timer.cpp"
  "examples/EntityStatePduProcessor.cpp"
)

add_executable(ExampleReceiver ${EX_RECEIVER_SOURCES})
target_link_libraries(ExampleReceiver ${LIB_FLAGS})
target_link_libraries(ExampleReceiver OpenDIS6)

install(TARGETS OpenDIS6 OpenDIS7 DESTINATION "lib")
install(TARGETS ExampleReceiver ExampleSender DESTINATION "bin")
install(DIRECTORY src/ DESTINATION "include"
        FILES_MATCHING PATTERN "*.h"
)

set(CPACK_GENERATOR "DEB" "RPM" "TXZ" "TGZ")
set(CPACK_PACKAGE_VERSION 1.0.0)
set(CPACK_PACKAGE_NAME "OpenDis")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The open DIS cpp library")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}.${CMAKE_SYSTEM_PROCESSOR}")
set(CPACK_PACKAGE_RPM_DIR "${CMAKE_CURRENT_BINARY_DIR}/_CPack_Packages/Linux/RPM")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Leif Gruenwoldt <leifer@gmail.com>")
set(CPACK_PACKAGE_PACKAGER $ENV{USER})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The open DIS cpp library")

include(CPack)
