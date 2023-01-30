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
