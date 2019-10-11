set(TARGET_NAME OpenDis-CppUtils)
set(INSTALL_INCLUDE_DIR ${INSTALL_INCLUDE_DIR_BASE}/utils)
set(INSTALL_LIB_DIR ${INSTALL_LIB_DIR_BASE})

file(GLOB_RECURSE source_files
     *.cpp
     )

file(GLOB_RECURSE header_files
     *.h
     )

add_library(${TARGET_NAME} OBJECT ${source_files})

target_include_directories(${TARGET_NAME}
                           PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/utils>
                           $<INSTALL_INTERFACE:${INSTALL_INCLUDE_DIR}/..>
                           PRIVATE
                           ${CMAKE_SOURCE_DIR}/src
                           )

install(FILES ${header_files} DESTINATION ${INSTALL_INCLUDE_DIR})

