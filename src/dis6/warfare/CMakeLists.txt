set(warfare_hdr
  BurstDescriptor.h
  DetonationPdu.h
  FirePdu.h
  WarfareFamilyPdu.h
)

set(warfare_src
  BurstDescriptor.cpp
  DetonationPdu.cpp
  FirePdu.cpp
  WarfareFamilyPdu.cpp
)

list(TRANSFORM warfare_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND warfare_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${warfare_src})

install(FILES ${warfare_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/warfare
)
