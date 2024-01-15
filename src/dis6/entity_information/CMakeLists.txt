set(entity_information_hdr
  CollisionElasticPdu.h
  CollisionPdu.h
  DeadReckoningParameter.h
  EntityInformationFamilyPdu.h
  EntityStatePdu.h
  EntityStateUpdatePdu.h
)

set(entity_information_src
  CollisionElasticPdu.cpp
  CollisionPdu.cpp
  DeadReckoningParameter.cpp
  EntityInformationFamilyPdu.cpp
  EntityStatePdu.cpp
  EntityStateUpdatePdu.cpp
)

list(TRANSFORM entity_information_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND entity_information_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${entity_information_src})

install(FILES ${entity_information_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/entity_information
)
