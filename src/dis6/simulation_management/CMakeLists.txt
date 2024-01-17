set(simulation_management_hdr
  AcknowledgePdu.h
  ActionRequestPdu.h
  ActionResponsePdu.h
  CommentPdu.h
  CreateEntityPdu.h
  DataPdu.h
  DataQueryPdu.h
  EventReportPdu.h
  RemoveEntityPdu.h
  SetDataPdu.h
  SimulationManagementFamilyPdu.h
  StartResumePdu.h
  StopFreezePdu.h
)

set(simulation_management_src
  AcknowledgePdu.cpp
  ActionRequestPdu.cpp
  ActionResponsePdu.cpp
  CommentPdu.cpp
  CreateEntityPdu.cpp
  DataPdu.cpp
  DataQueryPdu.cpp
  EventReportPdu.cpp
  RemoveEntityPdu.cpp
  SetDataPdu.cpp
  SimulationManagementFamilyPdu.cpp
  StartResumePdu.cpp
  StopFreezePdu.cpp
)

list(TRANSFORM simulation_management_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND simulation_management_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${simulation_management_src})

install(FILES ${simulation_management_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/simulation_management
)
