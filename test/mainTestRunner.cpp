
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestRunner.h>

#include <cppunit/TestListener.h>
#include <cppunit/Test.h>
#include <cppunit/TestFailure.h>

int main (int argc, char* argv[])
{
   CPPUNIT_NS::TestResult testResult;

   CPPUNIT_NS::TestResultCollector collectedResults;
   testResult.addListener(&collectedResults);

   CPPUNIT_NS::TestRunner testRunner;
   testRunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
   testRunner.run(testResult);

   CPPUNIT_NS::CompilerOutputter compilerOutputter(&collectedResults,std::cerr);
   compilerOutputter.write();

   return collectedResults.wasSuccessful () ? 0 : 1;
}

