set(TARGET_NAME OpenDis6)
set(INSTALL_INCLUDE_DIR ${INSTALL_INCLUDE_DIR_BASE}/PDUs/dis6)
set(INSTALL_LIB_DIR ${INSTALL_LIB_DIR_BASE})

file(GLOB_RECURSE source_files
  *.cpp
)

file(GLOB_RECURSE header_files
  *.h
)

add_library(${TARGET_NAME} $<TARGET_OBJECTS:OpenDis-CppUtils> ${source_files})

target_include_directories(${TARGET_NAME}
                           PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
                           $<INSTALL_INTERFACE:${INSTALL_INCLUDE_DIR}>/..
                           $<INSTALL_INTERFACE:${INSTALL_INCLUDE_DIR_BASE}>
                           PRIVATE
                           ${CMAKE_SOURCE_DIR}/src/utils
)

install(TARGETS ${TARGET_NAME} EXPORT ${TARGET_NAME}Targets ARCHIVE DESTINATION ${INSTALL_LIB_DIR})
install(EXPORT ${TARGET_NAME}Targets DESTINATION ${INSTALL_LIB_DIR})
install(FILES ${header_files} DESTINATION ${INSTALL_INCLUDE_DIR})
