# LICENSE
# 
# See main CMakeLists.txt file in main project directory
#

#--------------------------------------------------------
# Library Creation
#--------------------------------------------------------
set(LIBRARY_NAME OpenDIS7)
set(BUILD_INC_DIR ${PROJECT_INC_DIR}/dis7)


#########################################
# COPY INC FILES TO BUILD DIR
#########################################
file(GLOB INCS *.h)
file(MAKE_DIRECTORY ${BUILD_INC_DIR})
foreach(inc_file ${INCS})
  configure_file(${inc_file} ${BUILD_INC_DIR})
endforeach()


file(GLOB SRCS *.cpp)

add_library(${LIBRARY_NAME} OBJECT
  ${SRCS})

set_property(TARGET ${LIBRARY_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

# -Wall flag turned off due to numerous warnings
target_compile_options(${LIBRARY_NAME}
  PRIVATE
#    -Wall
    -std=c++14
    $<$<CXX_COMPILER_ID:Clang>:"-Wno-return-type-c-linkage">
)

