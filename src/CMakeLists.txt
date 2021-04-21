
# Define the common interface library
add_library(common_OpenDIS INTERFACE)

# Add src/ to the include directories to OpenDIS6
target_include_directories(common_OpenDIS INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/common>
)

add_library(opendis::common ALIAS common_OpenDIS)

# Define OpenDIS6 library
add_library(OpenDIS6 SHARED 
)

target_link_libraries(OpenDIS6 opendis::common)

# Add src/ to the include directories to OpenDIS6
target_include_directories(OpenDIS6 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/dis6>
)
# Add compile definition EXPORT_LIBRARY for DIS6 msLibMacro.h
target_compile_definitions(OpenDIS6 PRIVATE EXPORT_LIBRARY)

add_library(opendis::dis6 ALIAS OpenDIS6)

# Define OpenDIS7 library
add_library(OpenDIS7 SHARED)

target_link_libraries(OpenDIS7 opendis::common)
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