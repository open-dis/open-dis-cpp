#--------------------------------------------------------
# Library Creation
#--------------------------------------------------------
set(LIBRARY_NAME OpenDIS6)
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

add_library(${LIBRARY_NAME} OBJECT
  ${SRCS})

set_property(TARGET ${LIBRARY_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

target_compile_options(${LIBRARY_NAME}
  PRIVATE
#    -Wall
    -std=c++14
    $<$<CXX_COMPILER_ID:Clang>:"-Wno-return-type-c-linkage">
)

