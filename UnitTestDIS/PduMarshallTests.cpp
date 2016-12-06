/// Copyright goes here
/// License goes here
/// @author John K. Grant

#include <cppunit/extensions/HelperMacros.h>
#include "PduUtils.h"            // for init functions

#include <DIS/StreamUtils.h>         // for stream operators so unit test macros compile
#include <DIS/DataStream.h>       // for use
#include <DIS/EntityStatePdu.h>   // for testing
#include <DIS/DetonationPdu.h>    // for testing

namespace TestDIS
{
   /// tests serializing the data for various Pdu types.
   ///\todo figure out why CppUnit won't compile the commented code in 'CheckSerialization'
   class PduMarshallTests : public CPPUNIT_NS::TestFixture
   {
   public:
      static const unsigned int NUMBER_OF_CLONES = 3;

      void setup();
      void teardown(); 

      CPPUNIT_TEST_SUITE( PduMarshallTests );
         CPPUNIT_TEST( TestESPdu );
         CPPUNIT_TEST( TestDetonationPdu );
      CPPUNIT_TEST_SUITE_END();

      /// test the EntityStatePdu packet.
      void TestESPdu();
      void TestDetonationPdu();

   protected:
      /// tests the results of serialization of back-2-back serializations of the same PDU type.
      /// @param src1 data to be serialized
      template<typename PduT, unsigned int clones, typename PduT2>
      void CheckSerialization(const PduT& src1, const PduT2& src2);

      /// copies data of 1 & 2 via serialization
      /// @param read1 data will be copied from this to the write1 parameter.
      /// @param write1 data will be copied to this to the read1 parameter.
      template<typename PduT>
      void MarshallLaw(const PduT& read1, DIS::DataStream& ds, PduT& write1) const;
   };
}

using namespace TestDIS;
CPPUNIT_TEST_SUITE_REGISTRATION( PduMarshallTests );

template<typename PduT>
void PduMarshallTests::MarshallLaw(const PduT& read1, DIS::DataStream& ds, PduT& write1) const
{
}

template<typename PduT, unsigned int clones, typename PduT2>
void PduMarshallTests::CheckSerialization(const PduT& src1, const PduT2& src2)
{
   DIS::DataStream ds( DIS::BIG );
   PduT pdu_array[clones];

   // initialize the array
   // also add data to the stream
   for(unsigned int c_index=0; c_index<clones; ++c_index)
   {
      pdu_array[c_index] = src1;
      pdu_array[c_index].marshal( ds );
   }
   src2.marshal( ds );

   // now pull data from the stream and check the values
   for(unsigned int c_index=0; c_index<clones; ++c_index)
   {
      PduT copy;
      // copy the data
      copy.unmarshal( ds );

      // check to see if the copy has the same data as the pdu
      CPPUNIT_ASSERT_EQUAL( pdu_array[c_index] , copy );
   }

   PduT2 copy2;
   copy2.unmarshal( ds );
   CPPUNIT_ASSERT_EQUAL( src2 , copy2 );
}

void PduMarshallTests::TestESPdu()
{
   DIS::EntityStatePdu p1;
   TestDIS::InitPDU( p1 );

   DIS::DetonationPdu p2;
   TestDIS::InitPDU( p2 );

   CheckSerialization<DIS::EntityStatePdu,NUMBER_OF_CLONES,DIS::DetonationPdu>( p1, p2 );
}

void PduMarshallTests::TestDetonationPdu()
{
   DIS::DetonationPdu p1;
   TestDIS::InitPDU( p1 );

   DIS::EntityStatePdu p2;
   TestDIS::InitPDU( p2 );

   CheckSerialization<DIS::DetonationPdu,NUMBER_OF_CLONES,DIS::EntityStatePdu>( p1, p2 );
}

