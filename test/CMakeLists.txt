set(unit_test_suite_src
  UnitTestSuite.cpp
  DataStreamTests.cpp
  IncomingMessageTests.cpp
  PduMarshallTests.cpp
  PduUtils.cpp
)

add_executable(
  UnitTestSuite
  ${unit_test_suite_src}
)

target_link_libraries(UnitTestSuite OpenDIS6)
target_include_directories(UnitTestSuite PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME UnitTestSuite
         COMMAND UnitTestSuite -r junit -o UnitTestSuite-results.xml)

# DIS7 PDU Basic Test Suite (minimal working tests)
set(pdu_basic_test_src
  PduBasicTests.cpp
  PduTestUtils.cpp
)

add_executable(
  PduBasicTests
  ${pdu_basic_test_src}
)

target_link_libraries(PduBasicTests OpenDIS7)
target_include_directories(PduBasicTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME PduBasicTests
         COMMAND PduBasicTests -r junit -o PduBasicTests-results.xml)

# DIS7 PDU Full Test Suite (requires API mapping fixes)
# Commented out until API mapping is completed
# set(pdu_test_suite_src
#   PduTestSuite.cpp
#   PduWireFormatTests.cpp
#   PduTestUtils.cpp
#   PduSampleData.cpp
# )
#
# add_executable(
#   PduTestSuite
#   ${pdu_test_suite_src}
# )
#
# target_link_libraries(PduTestSuite OpenDIS7)
# target_include_directories(PduTestSuite PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
#
# add_test(NAME PduTestSuite
#          COMMAND PduTestSuite -r junit -o PduTestSuite-results.xml)
