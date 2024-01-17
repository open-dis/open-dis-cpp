set(radio_communications_src
  AntennaLocation.cpp
  IntercomCommunicationsParameters.cpp
  IntercomControlPdu.cpp
  IntercomSignalPdu.cpp
  ModulationType.cpp
  RadioCommunicationsFamilyPdu.cpp
  RadioEntityType.cpp
  ReceiverPdu.cpp
  SignalPdu.cpp
  TransmitterPdu.cpp
)

set(radio_communications_hdr
  AntennaLocation.h
  IntercomCommunicationsParameters.h
  IntercomControlPdu.h
  IntercomSignalPdu.h
  ModulationType.h
  RadioCommunicationsFamilyPdu.h
  RadioEntityType.h
  ReceiverPdu.h
  SignalPdu.h
  TransmitterPdu.h
)

list(TRANSFORM radio_communications_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND radio_communications_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${radio_communications_src})

install(FILES ${radio_communications_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/radio_communications
)
