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
  AggregateStatePdu.h
  AggregateType.h
  AngularVelocityVector.h
  AntennaLocation.h
  ApaData.h
  ArealObjectStatePdu.h
  ArticulationParameter.h
  BeamAntennaPattern.h
  BeamData.h
  BurstDescriptor.h
  CollisionElasticPdu.h
  CollisionPdu.h
  EightByteChunk.h
  EntityStateUpdatePdu.h
  Environment.h
  EnvironmentalProcessPdu.h
  EventID.h
  FastEntityStatePdu.h
  FixedDatum.h
  FourByteChunk.h
  GridAxisRecord.h
  GridAxisRecordRepresentation0.h
  GridAxisRecordRepresentation1.h
  GridAxisRecordRepresentation2.h
  GriddedDataPdu.h
  IsGroupOfPdu.h
  IsPartOfPdu.h
  LayerHeader.h
  LinearObjectStatePdu.h
  LinearSegmentParameter.h
  LogisticsPdu.h
  Marking.h
  ModulationType.h
  NamedLocation.h
  ObjectType.h
  Orientation.h
  PduContainer.h
  Point.h
  PointObjectStatePdu.h
  PropulsionSystemData.h
  RecordSet.h
  Relationship.h
  ServiceRequestPdu.h
  ShaftRPMs.h
  SixByteChunk.h
  SphericalHarmonicAntennaPattern.h
  SupplyQuantity.h
  symbolic_names.h
  SystemID.h
  TransferControlRequestPdu.h
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
  AggregateStatePdu.cpp
  AggregateType.cpp
  AngularVelocityVector.cpp
  AntennaLocation.cpp
  ApaData.cpp
  ArealObjectStatePdu.cpp
  ArticulationParameter.cpp
  BeamAntennaPattern.cpp
  BeamData.cpp
  BurstDescriptor.cpp
  CollisionElasticPdu.cpp
  CollisionPdu.cpp
  EightByteChunk.cpp
  EntityStateUpdatePdu.cpp
  Environment.cpp
  EnvironmentalProcessPdu.cpp
  EventID.cpp
  FastEntityStatePdu.cpp
  FixedDatum.cpp
  FourByteChunk.cpp
  GridAxisRecord.cpp
  GridAxisRecordRepresentation0.cpp
  GridAxisRecordRepresentation1.cpp
  GridAxisRecordRepresentation2.cpp
  GriddedDataPdu.cpp
  IsGroupOfPdu.cpp
  IsPartOfPdu.cpp
  LayerHeader.cpp
  LinearObjectStatePdu.cpp
  LinearSegmentParameter.cpp
  LogisticsPdu.cpp
  Marking.cpp
  ModulationType.cpp
  NamedLocation.cpp
  ObjectType.cpp
  Orientation.cpp
  PduContainer.cpp
  Point.cpp
  PointObjectStatePdu.cpp
  PropulsionSystemData.cpp
  RecordSet.cpp
  Relationship.cpp
  ServiceRequestPdu.cpp
  ShaftRPMs.cpp
  SixByteChunk.cpp
  SphericalHarmonicAntennaPattern.cpp
  SupplyQuantity.cpp
  SystemID.cpp
  TransferControlRequestPdu.cpp
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
