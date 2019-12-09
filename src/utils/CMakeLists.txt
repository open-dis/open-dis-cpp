SET(LIBRARY_NAME OpenDIS-utils)
#########################################
# COPY INC FILES TO BUILD DIR
#########################################
set(BUILD_INC_DIR ${PROJECT_INC_DIR}/utils)

file(GLOB INCS *.h)
file(MAKE_DIRECTORY ${BUILD_INC_DIR})
foreach(inc_file ${INCS})
  configure_file(${inc_file} ${BUILD_INC_DIR})
endforeach()

file(GLOB SRCS *.cpp)

add_library(${LIBRARY_NAME} OBJECT
  ${SRCS})

set_property(TARGET ${LIBRARY_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

target_compile_options(${LIBRARY_NAME}
  PRIVATE
#    -Wall
    -std=c++14
    $<$<CXX_COMPILER_ID:Clang>:"-Wno-return-type-c-linkage">
)
RETURN()
