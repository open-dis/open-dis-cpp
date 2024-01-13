set(distributed_emissions_hdr
  DesignatorPdu.h
  DistributedEmissionsFamilyPdu.h
  ElectromagneticEmissionBeamData.h
  ElectromagneticEmissionsPdu.h
  ElectromagneticEmissionSystemData.h
  EmitterSystem.h
  FundamentalParameterData.h
  FundamentalParameterDataIff.h
  IffAtcNavAidsLayer1Pdu.h
  IffAtcNavAidsLayer2Pdu.h
  IffFundamentalData.h
  SeesPdu.h
  TrackJamTarget.h
  UnderwaterAcousticsPdu.h
)

set(distributed_emissions_src
  DesignatorPdu.cpp
  DistributedEmissionsFamilyPdu.cpp
  ElectromagneticEmissionBeamData.cpp
  ElectromagneticEmissionsPdu.cpp
  ElectromagneticEmissionSystemData.cpp
  EmitterSystem.cpp
  FundamentalParameterData.cpp
  FundamentalParameterDataIff.cpp
  IffAtcNavAidsLayer1Pdu.cpp
  IffAtcNavAidsLayer2Pdu.cpp
  IffFundamentalData.cpp
  SeesPdu.cpp
  TrackJamTarget.cpp
  UnderwaterAcousticsPdu.cpp
)

list(TRANSFORM distributed_emissions_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND distributed_emissions_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${distributed_emissions_src})

install(FILES ${distributed_emissions_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/distributed_emissions
)
