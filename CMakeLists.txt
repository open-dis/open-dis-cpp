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
