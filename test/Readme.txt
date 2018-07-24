The source code within this folder requires
a dependency project to compile and link against.
The package known as CppUnit must be installed.
To help users, the choice of installation location
can vary, and 2 environment variables will be used
to locate the CppUnit SDK.
CPPUNIT_INC
CPPUNIT_LIB

For example, if the package was located at the following:
C:\cppunit-1.12.0
Then the environment variables could be defined as such:
CPPUNIT_INC=C:\cppunit-1.12.0\include
CPPUNIT_LIB=C:\cppunit-1.12.0\lib

CppUnit can be obtained via the instructions at:
http://cppunit.sourceforge.net/

