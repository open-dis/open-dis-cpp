/// Copyright goes here
/// License goes here
/// @author John K. Grant

#include <cppunit/extensions/HelperMacros.h>

#include <DIS/DataStream.h>       // for testing
#include <DIS/EntityStatePdu.h>   // for usage

#include <cstdlib>   // for NULL definition
#include <cstring>   // for strlen

namespace TestDIS
{
   /// tests the support for serializing basic types.
   class DataStreamTests : public CPPUNIT_NS::TestFixture
   {
   public:
      void setup();
      void teardown(); 

      void TestChar();
      void TestShort();
      void TestDouble();
      void TestFloat();
      void TestStream();
      void TestChaining();

      CPPUNIT_TEST_SUITE( DataStreamTests );
         CPPUNIT_TEST( TestChar );
         CPPUNIT_TEST( TestShort );
         CPPUNIT_TEST( TestDouble );
         CPPUNIT_TEST( TestFloat );
         CPPUNIT_TEST( TestChaining );
      CPPUNIT_TEST_SUITE_END();

   protected:
      /// tests to know if the same data comes out of the DataStream's char buffer that was put into it.
      /// also tests to know if the DataStream's read and write positions were updated.
      template<typename T>
      void TestData(DIS::Endian e, T t0, T t1, T t2);
   };
}

using namespace TestDIS;
using namespace DIS;
CPPUNIT_TEST_SUITE_REGISTRATION( DataStreamTests );

template<typename T>
void DataStreamTests::TestData(DIS::Endian e, T t0, T t1, T t2)
{
   DataStream ds( e );
   CPPUNIT_ASSERT( ds.empty() );

   size_t read_pos( 0 );
   size_t write_pos( 0 );

   // check the read and write positions
   CPPUNIT_ASSERT_EQUAL( ds.GetReadPos() , read_pos );
   CPPUNIT_ASSERT_EQUAL( ds.GetWritePos() , write_pos );

   // check the size of the buffer
   CPPUNIT_ASSERT_EQUAL( ds.size() , write_pos );

   // fill the stream
   T ch = t0;
   ds << ch;
   CPPUNIT_ASSERT( !ds.empty() );
   write_pos += sizeof(T);
   CPPUNIT_ASSERT_EQUAL( ds.size(), write_pos );             // size check
   CPPUNIT_ASSERT_EQUAL( ds.GetReadPos() , read_pos );       // read check
   CPPUNIT_ASSERT_EQUAL( ds.GetWritePos() , write_pos );     // write check

   ch = t1;
   ds << ch;
   write_pos += sizeof(T);
   CPPUNIT_ASSERT( !ds.empty() );                            // empty check
   CPPUNIT_ASSERT_EQUAL( ds.size(), write_pos );             // size check
   CPPUNIT_ASSERT_EQUAL( ds.GetReadPos() , read_pos );       // read check
   CPPUNIT_ASSERT_EQUAL( ds.GetWritePos() , write_pos );     // write check

   ch = t2;
   ds << ch;
   write_pos += sizeof(T);
   CPPUNIT_ASSERT( !ds.empty() );                            // empty check
   CPPUNIT_ASSERT_EQUAL( ds.size(), write_pos );             // size check
   CPPUNIT_ASSERT_EQUAL( ds.GetReadPos() , read_pos );       // read check
   CPPUNIT_ASSERT_EQUAL( ds.GetWritePos() , write_pos );     // write check

   // read from the stream
   ds >> ch;
   read_pos += sizeof(T);
   CPPUNIT_ASSERT_EQUAL( ch , t0 );                          // value check
   CPPUNIT_ASSERT( !ds.empty() );                            // empty check
   CPPUNIT_ASSERT_EQUAL( ds.size(), write_pos );             // size check
   CPPUNIT_ASSERT_EQUAL( ds.GetReadPos() , read_pos );       // read check
   CPPUNIT_ASSERT_EQUAL( ds.GetWritePos() , write_pos );     // write check

   ds >> ch;
   read_pos += sizeof(T);
   CPPUNIT_ASSERT_EQUAL( ch , t1 );                          // value check
   CPPUNIT_ASSERT( !ds.empty() );                            // empty check
   CPPUNIT_ASSERT_EQUAL( ds.size(), write_pos );             // size check
   CPPUNIT_ASSERT_EQUAL( ds.GetReadPos() , read_pos );       // read check
   CPPUNIT_ASSERT_EQUAL( ds.GetWritePos() , write_pos );     // write check

   ds >> ch;
   read_pos += sizeof(T);
   CPPUNIT_ASSERT_EQUAL( ch , t2 );                          // value check
   CPPUNIT_ASSERT( !ds.empty() );                            // empty check
   CPPUNIT_ASSERT_EQUAL( ds.size(), write_pos );             // size check
   CPPUNIT_ASSERT_EQUAL( ds.GetReadPos() , read_pos );       // read check
   CPPUNIT_ASSERT_EQUAL( ds.GetWritePos() , write_pos );     // write check
}

void DataStreamTests::TestChar()
{
   TestData<char>( DIS::BIG , 'a' , 'b' , 'c' );
}

void DataStreamTests::TestShort()
{
   short a(1), b(2), c(3);
   TestData<short>( DIS::BIG , a , b , c );
}

void DataStreamTests::TestDouble()
{
   TestData<double>( DIS::BIG , 9. , 10. , 11. );
}

void DataStreamTests::TestFloat()
{
   TestData<float>( DIS::BIG , 9.f , 10.f , 11.f );
}

void DataStreamTests::TestChaining()
{
   // define a psuedo packet
   char id=3;
   float x=9.f;
   float y=11.f;
   char length=sizeof(char)+sizeof(char)+sizeof(float)+sizeof(float);  // 10

   DIS::DataStream output(DIS::BIG);
   output << id << length << x << y;

   // catch the psuedo packet
   char inid=0;
   char inlength=0;
   float inx=0;
   float iny=0;

   DIS::DataStream input( &(output[0]) , output.size() , output.GetStreamEndian() );
   input >> inid >> inlength >> inx >> iny;

   CPPUNIT_ASSERT_EQUAL( id , inid );
   CPPUNIT_ASSERT_EQUAL( length , inlength );
   CPPUNIT_ASSERT_EQUAL( x , inx );
   CPPUNIT_ASSERT_EQUAL( y , iny );
}
