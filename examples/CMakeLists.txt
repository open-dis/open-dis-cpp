# LICENSE
# 
# See main CMakeLists.txt file in main project directory
#

#--------------------------------------------------------
# Library Creation
#--------------------------------------------------------
set(LIBRARY_NAME ExampleSender)
set(LIBRARY_NAME_2 ExampleReceiver)
set(LIB_MAJOR 0)
set(LIB_MINOR 0)
set(LIB_RELEASE 1)
set(BUILD_INC_DIR ${PROJECT_INC_DIR}/examples)


#########################################
# COPY INC FILES TO BUILD DIR
#########################################
file(GLOB INCS *.h)
file(MAKE_DIRECTORY ${BUILD_INC_DIR})
foreach(inc_file ${INCS})
  configure_file(${inc_file} ${BUILD_INC_DIR})
endforeach()


include_directories(${OPENDIS_INCLUDE_DIR})
include_directories(${SDL2_NET_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(${LIBRARY_NAME}
  Connection.cpp 
  Utils.cpp 
  Timer.cpp
  main.cpp
)
add_executable(${LIBRARY_NAME_2} 
  Connection.cpp 
  Utils.cpp 
  Timer.cpp 
  EntityStatePduProcessor.cpp
  main_receive.cpp
)


# -Wall flag turned off due to numerous warnings
target_compile_options(${LIBRARY_NAME}
  PRIVATE
#    -Wall
    -std=c++14
    $<$<CXX_COMPILER_ID:Clang>:"-Wno-return-type-c-linkage">
)
target_compile_options(${LIBRARY_NAME_2}
  PRIVATE
#    -Wall
    -std=c++14
    $<$<CXX_COMPILER_ID:Clang>:"-Wno-return-type-c-linkage">
)


target_link_libraries(${LIBRARY_NAME}
  ${OPENDIS_LIBRARY}
  SDL2::Main
  SDL2::Net
)
target_link_libraries(${LIBRARY_NAME_2}
  ${OPENDIS_LIBRARY}
  SDL2::Main
  SDL2::Net
)


set(_soversion ${LIB_MAJOR}.${LIB_MINOR}.${LIB_RELEASE})
set_target_properties(${LIBRARY_NAME} PROPERTIES
  SOVERSION ${LIB_MAJOR}
  VERSION ${_soversion}
  LIBRARY_OUTPUT_DIRECTORY ${PROJECT_EXAMPLES_DIR}
)
set_target_properties(${LIBRARY_NAME_2} PROPERTIES
  SOVERSION ${LIB_MAJOR}
  VERSION ${_soversion}
  LIBRARY_OUTPUT_DIRECTORY ${PROJECT_EXAMPLES_DIR}
)


target_include_directories(${LIBRARY_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${PROJECT_INC_DIR}>
)
target_include_directories(${LIBRARY_NAME_2}
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
install(TARGETS ${LIBRARY_NAME_2}
  # IMPORTANT: Add the library to the "export-set"
  EXPORT ${PROJECT_NAME}-targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/${PROJECT_NAME}
)


# Push up the PROJECT_EXAMPLES variable
set(PROJECT_EXAMPLES ${PROJECT_EXAMPLES} ${LIBRARY_NAME} PARENT_SCOPE)
set(PROJECT_EXAMPLES ${PROJECT_EXAMPLES} ${LIBRARY_NAME_2} PARENT_SCOPE)



