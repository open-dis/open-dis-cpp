set(OPENDIS_PACKAGE_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/OpenDIS")

include(CMakePackageConfigHelpers)

configure_package_config_file(
  OpenDISConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/OpenDISConfig.cmake
  INSTALL_DESTINATION ${OPENDIS_PACKAGE_DIR}
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/OpenDISConfigVersion.cmake"
  VERSION "${PROJECT_VERSION_FULL}"
  COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/OpenDISConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/OpenDISConfigVersion.cmake
        DESTINATION ${OPENDIS_PACKAGE_DIR})
