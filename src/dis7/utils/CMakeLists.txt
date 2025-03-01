# Create list of all headers
set(utils_hdr
  DataStream.h
  Endian.h
  ConversionUtils.h
  PDUType.h
)

# Create list of all source files
set(utils_src
  DataStream.cpp
  ConversionUtils.cpp
)

# CMake < 3.16 requires target_sources to be specified as
# absolute paths if not in the same directory as the target
# definition. If cmake_minimum_required is ever changed to
# be >= 16, these 2 lines can be removed.
list(TRANSFORM utils_src PREPEND "${CMAKE_CURRENT_LIST_DIR}/")

target_sources(OpenDIS7 PRIVATE ${utils_src})

install(FILES ${utils_hdr}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dis7/utils)
