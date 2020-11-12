
set(common_src
  DataStream.cpp 
)

target_sources(OpenDIS6
  PRIVATE
    Conversion.cpp
    IncomingMessage.cpp
    PacketFactory.cpp
    PDUBank.cpp
    PduFactory.cpp
    StreamUtils.cpp
    ${common_src}
)

target_sources(OpenDIS7
  PRIVATE
    ${common_src}
)