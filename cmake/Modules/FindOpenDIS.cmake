get_filename_component(PARENT_DIR ${CMAKE_SOURCE_DIR}/.. ABSOLUTE)

SET(DIS_SEARCH_PATHS
  /usr/local
  /usr
  ${PARENT_DIR}/open-dis
  )
  

FIND_PATH(OPENDIS_INCLUDE_DIR dis6/AcknowledgePdu.h
  PATH_SUFFIXES src include/
  PATHS ${DIS_SEARCH_PATHS})

FIND_LIBRARY(OPENDIS_LIBRARY
  NAMES OpenDIS
  PATH_SUFFIXES Build/lib/Release Build/lib/Debug lib lib64
  PATHS ${DIS_SEARCH_PATHS}
  )
