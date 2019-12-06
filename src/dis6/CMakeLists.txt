#--------------------------------------------------------
# Library Creation
#--------------------------------------------------------
set(LIBRARY_NAME OpenDIS6)
set(LIB_MAJOR 0)
set(LIB_MINOR 0)
set(LIB_RELEASE 1)
set(BUILD_INC_DIR ${PROJECT_INC_DIR}/dis6)


#########################################
# COPY INC FILES TO BUILD DIR
#########################################
file(GLOB INCS *.h)
file(MAKE_DIRECTORY ${BUILD_INC_DIR})
foreach(inc_file ${INCS})
  configure_file(${inc_file} ${BUILD_INC_DIR})
endforeach()


file(GLOB SRCS *.cpp)

#include_directories(${SDL2_NET_INCLUDE_DIRS})
#include_directories(${SDL2_INCLUDE_DIRS})

add_library(${LIBRARY_NAME} SHARED
  ${SRCS}
)

target_compile_options(${LIBRARY_NAME}
  PRIVATE
#    -Wall
    -std=c++14
    $<$<CXX_COMPILER_ID:Clang>:"-Wno-return-type-c-linkage">
)

#target_link_libraries(${LIBRARY_NAME}
#  SDL2::Main
#  SDL2::Net
#)

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
  # IMPORTANT: Add the library to the "export-set"
  EXPORT ${PROJECT_NAME}-targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/${PROJECT_NAME}
)

# Push up the PROJECT_PLUGINS variable
set(PROJECT_LIBS ${PROJECT_LIBS} ${LIBRARY_NAME} PARENT_SCOPE)

