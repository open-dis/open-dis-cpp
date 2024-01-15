set(logistics_hdr
  LogisticsFamilyPdu.h
  RepairCompletePdu.h
  RepairResponsePdu.h
  ResupplyCancelPdu.h
  ResupplyOfferPdu.h
  ResupplyReceivedPdu.h
  ServiceRequestPdu.h
  SupplyQuantity.h
)

set(logistics_src
  LogisticsFamilyPdu.cpp
  RepairCompletePdu.cpp
  RepairResponsePdu.cpp
  ResupplyCancelPdu.cpp
  ResupplyOfferPdu.cpp
  ResupplyReceivedPdu.cpp
  ServiceRequestPdu.cpp
  SupplyQuantity.cpp
)

list(TRANSFORM logistics_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

include(GenerateExportHeader)
generate_export_header(OpenDIS6)
list(APPEND logistics_hdr "${CMAKE_CURRENT_BINARY_DIR}/opendis6_export.h")

target_sources(OpenDIS6 PRIVATE ${logistics_src})

install(FILES ${logistics_hdr}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/logistics
)
