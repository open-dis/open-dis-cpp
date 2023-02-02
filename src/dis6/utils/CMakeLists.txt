# Create list of all headers
set(utils_hdr
  Conversion.h
  DataStream.h
  Endian.h
  IBufferProcessor.h
  IncomingMessage.h
  IPacketProcessor.h
  IPduBank.h
  Masks.h
  PacketFactory.h
  PDUBank.h
  PduFactory.h
  PDUType.h
  StreamUtils.h
)

# Create list of all source files
set(utils_src
  Conversion.cpp
  DataStream.cpp
  IncomingMessage.cpp
  PacketFactory.cpp
  PDUBank.cpp
  PduFactory.cpp
  StreamUtils.cpp
)

# CMake < 3.16 requires target_sources to be specified as
# absolute paths if not in the same directory as the target
# definition. If cmake_minimum_required is ever changed to
# be >= 16, these 2 lines can be removed.
list(TRANSFORM utils_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

target_sources(OpenDIS6 PRIVATE ${utils_src})

install(FILES ${utils_hdr}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis6/utils)
