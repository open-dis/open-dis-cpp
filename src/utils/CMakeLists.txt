#########################################
# COPY INC FILES TO BUILD DIR
#########################################
set(BUILD_INC_DIR ${PROJECT_INC_DIR}/utils)

file(GLOB INCS *.h)
file(MAKE_DIRECTORY ${BUILD_INC_DIR})
foreach(inc_file ${INCS})
  configure_file(${inc_file} ${BUILD_INC_DIR})
endforeach()

RETURN()
