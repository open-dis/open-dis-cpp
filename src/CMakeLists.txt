# LICENSE
# 
# See main CMakeLists.txt file in main project directory
#

set(LIBRARY_NAME OpenDIS)
set(LIB_MAJOR 0)
set(LIB_MINOR 0)
set(LIB_RELEASE 1)
include_directories(./)

# Only go into specific sub directories
add_subdirectory(dis6)
#add_subdirectory(dis7) # premake script does not build this, and anyway it has build errors
add_subdirectory(utils)

# Do not include DIS 7 for now since it doesn't build
add_library(${LIBRARY_NAME} SHARED
  $<TARGET_OBJECTS:OpenDIS6>
  # $<TARGET_OBJECTS:OpenDIS7>
  $<TARGET_OBJECTS:OpenDIS-utils>
)

# -Wall flag turned off due to numerous warnings
target_compile_options(${LIBRARY_NAME}
  PRIVATE
#    -Wall
    -std=c++14
    $<$<CXX_COMPILER_ID:Clang>:"-Wno-return-type-c-linkage">
)

set(_soversion ${LIB_MAJOR}.${LIB_MINOR}.${LIB_RELEASE})

set_target_properties(${LIBRARY_NAME} PROPERTIES
  SOVERSION ${LIB_MAJOR}
  VERSION ${_soversion}
  LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR}
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${PROJECT_INC_DIR}>
)

install(TARGETS ${LIBRARY_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/${PROJECT_NAME}
)

# Push up the PROJECT_PLUGINS variable
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIBRARY_NAME} PARENT_SCOPE)


set(PROJECT_LIBS ${PROJECT_LIBS} PARENT_SCOPE)

set(OPENDIS_LIBRARY ${LIBRARY_NAME} PARENT_SCOPE)

