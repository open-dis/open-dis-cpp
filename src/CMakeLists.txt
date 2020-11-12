# create list of DIS6 source files



# set(DIS_UTIL_COMMON
#     utils/DataStream.cpp
# )
# Define ExampleSender Executable
add_library(OpenDIS6 SHARED
    # ${DIS6_UTIL_SRC}
    # ${DIS_UTIL_COMMON}
)

# Add src/ to the include directories to OpenDIS6
target_include_directories(OpenDIS6 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/dis6>
)
# Add compile definition EXPORT_LIBRARY for DIS6 msLibMacro.h
target_compile_definitions(OpenDIS6 PRIVATE EXPORT_LIBRARY)

add_library(opendis::dis6 ALIAS OpenDIS6)


# Define ExampleSender Executable
add_library(OpenDIS7 SHARED ${DIS7_SOURCES} ${DIS_UTIL_COMMON})

# Add src/ to the include directories to OpenDIS6
target_include_directories(OpenDIS7 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
# Add compile definition EXPORT_LIBRARY for DIS7 msLibMacro.h
target_compile_definitions(OpenDIS7 PRIVATE EXPORT_LIBRARY)

add_library(opendis::dis7 ALIAS OpenDIS7)

# put these at the otherwise utils barfs because it has two targets
add_subdirectory(utils)
add_subdirectory(dis6)
add_subdirectory(dis7)