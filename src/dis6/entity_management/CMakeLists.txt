set(entity_management_hdr
  AggregateID.cpp
  AggregateMarking.cpp
  AggregateStatePdu.cpp
  AggregateType.cpp
  EntityManagementFamilyPdu.cpp
  IsGroupOfPdu.cpp
  IsPartOfPdu.cpp
  Marking.cpp
  NamedLocation.cpp
  Relationship.cpp
  TransferControlRequestPdu.cpp
)

set(entity_management_src
  AggregateID.h
  AggregateMarking.h
  AggregateStatePdu.h
  AggregateType.h
  EntityManagementFamilyPdu.h
  IsGroupOfPdu.h
  IsPartOfPdu.h
  Marking.h
  NamedLocation.h
  Relationship.h
  TransferControlRequestPdu.h
)

list(TRANSFORM entity_management_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND entity_management_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${entity_management_src})

install(FILES ${entity_management_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/entity_management
)
