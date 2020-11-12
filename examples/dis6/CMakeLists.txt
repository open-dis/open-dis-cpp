cmake_minimum_required(VERSION 3.14)
project(OpenDIS-Example-dis6)

## Libraries

# find_package(OpenDIS6)

## Example Programs
# include_directories(.)

# if Windows add M_PI definition
# - issues occurred during testing in Visual Studio
if (WIN32)
  add_definitions(/DM_PI=3.14159265358979323846)
endif (WIN32)

# create list of ExampleSender source files
set(EX_SENDER_SOURCES
  "main.cpp"
  "Connection.cpp"
  "Utils.cpp"
  "Timer.cpp"
)

if(WIN32)
       set(SDL_LIBS SDL2main SDL2 SDL2_net)
else(WIN32)
       set(SDL_LIBS SDL2 SDL2_net)
endif(WIN32)

# Define ExampleSender Executable
add_executable(ExampleSender ${EX_SENDER_SOURCES})
# Link OpenDIS into ExampleSender
target_link_libraries(ExampleSender PRIVATE opendis::dis6 ${SDL_LIBS})
target_include_directories(ExampleSender PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
# add src to ExampleSender include directories
target_include_directories(ExampleSender PRIVATE src)

# create list of ExampleReceiver source files
file(GLOB EX_RECEIVER_SOURCES
  "main_receive.cpp"
  "Connection.cpp"
  "Utils.cpp"
  "Timer.cpp"
  "EntityStatePduProcessor.cpp"
)

# Define ExampleReceiver Executable
add_executable(ExampleReceiver ${EX_RECEIVER_SOURCES})
# Link OpenDIS into ExampleReceiver
target_link_libraries(ExampleReceiver PRIVATE opendis::dis6 ${SDL_LIBS})
# add src to ExampleSender include directories
target_include_directories(ExampleReceiver PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Configuring SDL2
#--------------------------------------------------------------------------------------

# If SDL_INC_DIR declared (by user via -D flag)
if(SDL_INC_DIR)
  # Inform the user we will use the their specified SDL_INC_DIR
  message("Using SDL2 include directory defined with -DSDL_INC_DIR")
  message("\tvalue: ${SDL_INC_DIR}")
  # Add SDL_INC_DIR to the include directories for both exampe apps
  target_include_directories(ExampleSender PUBLIC ${SDL_INC_DIR})
  target_include_directories(ExampleReceiver PUBLIC ${SDL_INC_DIR})
else(SDL_INC_DIR)
  # Otherwise, try get SDL2 Compiler Flags from sdl2-config
  execute_process(
    COMMAND sdl2-config --cflags
    RESULT_VARIABLE SDL_CERR
    OUTPUT_VARIABLE SDL_CFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  # if sdl2-config errors
  if(SDL_CERR)
    # warn user that they may have to define the SDL2 include
    #  directory with the -DSDL_INC_DIR flag
    # Most linux systems will probably be fine
    message(WARNING "Unable to detect SDL2 include flags")
    message("You may need to specify the SDL include manually")
    message(" with -DSDL_INC_DIR=<SDL2 include path>")
  else(SDL_CERR)
    # otherwise split the output of sdl2-config and add to compiler flags to examples
    if(WIN32)
      separate_arguments(SDL_CFLAGS UNIX_COMMAND "${SDL_CFLAGS}")
    else(WIN32)
      separate_arguments(SDL_CFLAGS WINDOWS_COMMAND "${SDL_CFLAGS}")
    endif(WIN32)
    target_compile_options(ExampleSender PRIVATE "${SDL_CFLAGS}")
    target_compile_options(ExampleReceiver PRIVATE "${SDL_CFLAGS}")
  endif(SDL_CERR)
endif(SDL_INC_DIR)

# If SDL_LIB_DIR declared (by user via -D flag)
if(SDL_LIB_DIR)
  message("Using SDL2 include directory defined with -DSDL_LIB_DIR")
  message("\tvalue: ${SDL_LIB_DIR}")
  target_link_directories(ExampleSender PUBLIC ${SDL_LIB_DIR})
  target_link_directories(ExampleReceiver PUBLIC ${SDL_LIB_DIR})
else(SDL_LIB_DIR)
  # Otherwise, try get SDL2 Library Flags from sdl2-config
  execute_process(
    COMMAND sdl2-config --libs
    RESULT_VARIABLE SDL_LERR
    OUTPUT_VARIABLE SDL_LFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  # if sdl2-config errors
  if(SDL_LERR)
    # warn user that they may have to define the SDL2 include
    #  directory with the -DSDL_LIB_DIR flag
    # Most linux systems will probably be fine
    message(WARNING "Unable to detect SDL2 library flags using defaults")
    message("You may need to specify the SDL library manually with")
    message(" -DSDL_LIB_DIR=<SDL2 include path>, especially for Windows users")
  else(SDL_LERR)
    # otherwise split the output of sdl2-config and add to library flags to examples
    if(WIN32)
      separate_arguments(SDL_LFLAGS UNIX_COMMAND "${SDL_LFLAGS}")
    else(WIN32)
      separate_arguments(SDL_LFLAGS WINDOWS_COMMAND "${SDL_LFLAGS}")
    endif(WIN32)
    target_link_libraries(ExampleSender PRIVATE "${SDL_LFLAGS}")
    target_link_libraries(ExampleReceiver PRIVATE "${SDL_LFLAGS}")
  endif(SDL_LERR)
endif(SDL_LIB_DIR)

