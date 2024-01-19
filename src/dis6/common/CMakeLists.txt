set(common_src
  ArticulationParameter.cpp
  ClockTime.cpp
  EightByteChunk.cpp
  EntityID.cpp
  EntityType.cpp
  EventID.cpp
  FixedDatum.cpp
  FourByteChunk.cpp
  Orientation.cpp
  Pdu.cpp
  RecordSet.cpp
  SimulationAddress.cpp
  SixByteChunk.cpp
  TwoByteChunk.cpp
  VariableDatum.cpp
  Vector3Double.cpp
  Vector3Float.cpp
)

set(common_hdr
  ArticulationParameter.h
  ClockTime.h
  EightByteChunk.h
  EntityID.h
  EntityType.h
  EventID.h
  FixedDatum.h
  FourByteChunk.h
  Orientation.h
  Pdu.h
  RecordSet.h
  SimulationAddress.h
  SixByteChunk.h
  TwoByteChunk.h
  VariableDatum.h
  Vector3Double.h
  Vector3Float.h
)

target_sources(OpenDIS6 PRIVATE ${common_src})

install(FILES ${common_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/common
)
