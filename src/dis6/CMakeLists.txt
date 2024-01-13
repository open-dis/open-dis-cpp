add_subdirectory(utils)

add_subdirectory(distributed_emissions)
add_subdirectory(entity_information)
add_subdirectory(entity_management)
add_subdirectory(logistics)
add_subdirectory(minefield)
add_subdirectory(radio_communications)
add_subdirectory(simulation_management)
add_subdirectory(simulation_management_with_reliability)
add_subdirectory(synthetic_environment)
add_subdirectory(warfare)

# Create list of all headers
set(dis6_hdr
  AcousticBeamData.h
  AcousticBeamFundamentalParameter.h
  AcousticEmitter.h
  AcousticEmitterSystem.h
  AcousticEmitterSystemData.h
  AggregateID.h
  AggregateMarking.h
  AggregateType.h
  AngularVelocityVector.h
  AntennaLocation.h
  ApaData.h
  ArticulationParameter.h
  BeamAntennaPattern.h
  BeamData.h
  BurstDescriptor.h
  EightByteChunk.h
  Environment.h
  EventID.h
  FixedDatum.h
  FourByteChunk.h
  GridAxisRecord.h
  GridAxisRecordRepresentation0.h
  GridAxisRecordRepresentation1.h
  GridAxisRecordRepresentation2.h
  LayerHeader.h
  LinearSegmentParameter.h
  Marking.h
  ModulationType.h
  NamedLocation.h
  ObjectType.h
  Orientation.h
  PduContainer.h
  Point.h
  PropulsionSystemData.h
  RecordSet.h
  Relationship.h
  ShaftRPMs.h
  SixByteChunk.h
  SphericalHarmonicAntennaPattern.h
  SupplyQuantity.h
  SystemID.h
  TwoByteChunk.h
  VariableDatum.h
  VectoringNozzleSystemData.h
)

# Create list of all source files
set(dis6_src
  AcousticBeamData.cpp
  AcousticBeamFundamentalParameter.cpp
  AcousticEmitter.cpp
  AcousticEmitterSystem.cpp
  AcousticEmitterSystemData.cpp
  AggregateID.cpp
  AggregateMarking.cpp
  AggregateType.cpp
  AngularVelocityVector.cpp
  AntennaLocation.cpp
  ApaData.cpp
  ArticulationParameter.cpp
  BeamAntennaPattern.cpp
  BeamData.cpp
  BurstDescriptor.cpp
  EightByteChunk.cpp
  Environment.cpp
  EventID.cpp
  FixedDatum.cpp
  FourByteChunk.cpp
  GridAxisRecord.cpp
  GridAxisRecordRepresentation0.cpp
  GridAxisRecordRepresentation1.cpp
  GridAxisRecordRepresentation2.cpp
  LayerHeader.cpp
  LinearSegmentParameter.cpp
  Marking.cpp
  ModulationType.cpp
  NamedLocation.cpp
  ObjectType.cpp
  Orientation.cpp
  PduContainer.cpp
  Point.cpp
  PropulsionSystemData.cpp
  RecordSet.cpp
  Relationship.cpp
  ShaftRPMs.cpp
  SixByteChunk.cpp
  SphericalHarmonicAntennaPattern.cpp
  SupplyQuantity.cpp
  SystemID.cpp
  TwoByteChunk.cpp
  VariableDatum.cpp
  VectoringNozzleSystemData.cpp
)

# CMake < 3.16 requires target_sources to be specified as
# absolute paths if not in the same directory as the target
# definition. If cmake_minimum_required is ever changed to
# be >= 16, this line can be removed.
list(TRANSFORM dis6_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND dis6_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${dis6_src})

install(FILES ${dis6_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6)
