set(synthetic_environment_hdr
  ArealObjectStatePdu.h
  EnvironmentalProcessPdu.h
  GriddedDataPdu.h
  LinearObjectStatePdu.h
  PointObjectStatePdu.h
  SyntheticEnvironmentFamilyPdu.h
)

set(synthetic_environment_src
  ArealObjectStatePdu.cpp
  EnvironmentalProcessPdu.cpp
  GriddedDataPdu.cpp
  LinearObjectStatePdu.cpp
  PointObjectStatePdu.cpp
  SyntheticEnvironmentFamilyPdu.cpp
)

list(TRANSFORM synthetic_environment_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND synthetic_environment_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${synthetic_environment_src})

install(FILES ${synthetic_environment_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/synthetic_environment
)
