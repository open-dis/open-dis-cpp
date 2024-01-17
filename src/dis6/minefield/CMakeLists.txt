set(minefield_src
  MinefieldDataPdu.cpp
  MinefieldFamilyPdu.cpp
  MinefieldQueryPdu.cpp
  MinefieldResponseNackPdu.cpp
  MinefieldStatePdu.cpp
  Point.cpp
)

set(minefield_hdr
  MinefieldDataPdu.h
  MinefieldFamilyPdu.h
  MinefieldQueryPdu.h
  MinefieldResponseNackPdu.h
  MinefieldStatePdu.h
  Point.h
)

list(TRANSFORM minefield_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND minefield_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${minefield_src})

install(FILES ${minefield_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/minefield
)
