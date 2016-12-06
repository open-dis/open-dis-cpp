/// Copyright goes here
/// License goes here
/// @author John K. Grant

#include <cppunit/extensions/HelperMacros.h>

#include <DIS/IncomingMessage.h>    // for testing
#include <DIS/DataStream.h>         // for usage
#include <DIS/IPacketProcessor.h>   // for usage
#include <DIS/EntityStatePdu.h>     // for usage
#include <DIS/DetonationPdu.h>     // for usage
#include <DIS/CollisionPdu.h>     // for usage
#include <DIS/PDUType.h>
#include "PduUtils.h"

namespace TestDIS
{
   /// tests the support for listening to packets
   class IMTests : public CPPUNIT_NS::TestFixture
   {
   public:
      void setup();
      void teardown();

      void TestAddRemoveProcessor();
      void TestObserving();

      void TestEntityStateThenDetonation();
      void TestCollisionThenEntityState();

      CPPUNIT_TEST_SUITE( IMTests );
         CPPUNIT_TEST( TestAddRemoveProcessor );
         CPPUNIT_TEST( TestObserving );
         CPPUNIT_TEST( TestEntityStateThenDetonation );
         CPPUNIT_TEST( TestCollisionThenEntityState );
      CPPUNIT_TEST_SUITE_END();

   protected:
      template<typename PduT1, typename PduT2>
      void TestMultiplePackets(const PduT1& src1, const PduT2& src2);
   };

   /// knows if it has been visited
   class HitProcessor : public DIS::IPacketProcessor
   {
   private:
      DIS::PDUType mPduType;

   public:
      unsigned int _hits;

      HitProcessor(DIS::PDUType pdut)
         : DIS::IPacketProcessor()
         , mPduType(pdut)
         , _hits(0)
      {
      }

      DIS::PDUType GetRegisteredType() const { return mPduType; }

      /// test casting to a concrete type
      void Process(const DIS::Pdu& packet)
      {
         //const DIS::EntityStatePdu& espdu = static_cast<const DIS::EntityStatePdu&>( packet );
         //espdu.getEntityAppearance();
         _hits++;
      }

   private:
      HitProcessor(); ///< not implemented by design
   };
}

using namespace TestDIS;
using namespace DIS;
CPPUNIT_TEST_SUITE_REGISTRATION( IMTests );


void IMTests::TestAddRemoveProcessor()
{
   EntityStatePdu espdu;
   HitProcessor hp0((DIS::PDUType)espdu.getPduType());

   IncomingMessage im;
   CPPUNIT_ASSERT( im.GetProcessors().empty() );

   // test a single mapping
   im.AddProcessor( hp0.GetRegisteredType() , &hp0 );
   CPPUNIT_ASSERT_EQUAL( im.GetProcessors().size(), size_t(1) );

   im.RemoveProcessor( hp0.GetRegisteredType() , &hp0 );
   CPPUNIT_ASSERT_EQUAL( im.GetProcessors().size(), size_t(0) );
   CPPUNIT_ASSERT( im.GetProcessors().empty() );

   // test the multimap
   DIS::CollisionPdu cpdu;
   HitProcessor hp1((DIS::PDUType)cpdu.getPduType());

   im.AddProcessor( hp0.GetRegisteredType() , &hp0 );
   CPPUNIT_ASSERT_EQUAL( im.GetProcessors().size(), size_t(1) );

   im.AddProcessor( hp0.GetRegisteredType() , &hp1 );
   CPPUNIT_ASSERT_EQUAL( im.GetProcessors().size(), size_t(2) );

   // This should not allow multiples of the exact same pair
   im.AddProcessor( hp0.GetRegisteredType() , &hp0 );
   CPPUNIT_ASSERT_EQUAL( im.GetProcessors().size(), size_t(2) );

   // this should not remove the pair that does not exist
   im.RemoveProcessor( hp1.GetRegisteredType() , &hp0 );
   CPPUNIT_ASSERT_EQUAL( im.GetProcessors().size(), size_t(2) );

   im.RemoveProcessor( hp0.GetRegisteredType() , &hp1 );
   CPPUNIT_ASSERT_EQUAL( im.GetProcessors().size(), size_t(1) );

   im.RemoveProcessor( hp0.GetRegisteredType() , &hp0 );
   CPPUNIT_ASSERT_EQUAL( im.GetProcessors().size(), size_t(0) );
   CPPUNIT_ASSERT( im.GetProcessors().empty() );
}

void IMTests::TestObserving()
{
   // sample pdu for testing
   EntityStatePdu espdu;

   // will tell us if the packet processor framework within IncomingMessage is working.
   HitProcessor hp((DIS::PDUType)espdu.getPduType());
   CPPUNIT_ASSERT_EQUAL( hp._hits, (unsigned int)0 );  // better not be hit

   // map the HitProcessor to the type of pdu
   IncomingMessage im;
   im.AddProcessor( espdu.getPduType() , &hp );

   // fake a network buffer to read
   DIS::DataStream ds(DIS::BIG);
   espdu.marshal( ds );

   // test the packet processor framework
   im.Process( &(ds[0]), ds.size(), ds.GetStreamEndian() );
   CPPUNIT_ASSERT_EQUAL( hp._hits, (unsigned int)1 );  // better be hit now

   // clean up things
   im.RemoveProcessor( espdu.getPduType() , &hp );
}

void IMTests::TestEntityStateThenDetonation()
{
   DIS::EntityStatePdu espdu;
   TestDIS::InitPDU( espdu );

   DIS::DetonationPdu detpdu;
   TestDIS::InitPDU( detpdu );

   TestMultiplePackets( espdu , detpdu );
}

void IMTests::TestCollisionThenEntityState()
{
   DIS::CollisionPdu colpdu;
   TestDIS::InitPDU( colpdu );

   DIS::EntityStatePdu espdu;
   TestDIS::InitPDU( espdu );

   TestMultiplePackets( colpdu , espdu );
}

template<typename PduT1, typename PduT2>
void IMTests::TestMultiplePackets(const PduT1& src1, const PduT2& src2)
{
   // populate the factory
   IncomingMessage im;

   // sample PDUs for testing
   const unsigned int NUM_ES = 3;
   PduT1 pdu1_array[NUM_ES];
   for(unsigned int pdu1clone=0; pdu1clone<NUM_ES; ++pdu1clone)
   {
      pdu1_array[pdu1clone] = src1;
   }
   PduT2 pdu2 = src2;

   // will tell us if the packet processor framework within IncomingMessage is working.
   HitProcessor hp_es((DIS::PDUType)pdu1_array[0].getPduType());
   HitProcessor hp_dt((DIS::PDUType)pdu2.getPduType());
   CPPUNIT_ASSERT_EQUAL( hp_es._hits, (unsigned int)0 );  // better not be hit yet
   CPPUNIT_ASSERT_EQUAL( hp_dt._hits, (unsigned int)0 );  // better not be hit yet

   // map the HitProcessor to the type of pdu
   im.AddProcessor( hp_es.GetRegisteredType() , &hp_es );
   im.AddProcessor( hp_dt.GetRegisteredType() , &hp_dt );

   // fake a network buffer to read
   DIS::DataStream ds(DIS::BIG);
   for(unsigned int pdu1clone=0; pdu1clone<NUM_ES; ++pdu1clone)
   {
      pdu1_array[pdu1clone].marshal( ds );
   }
   pdu2.marshal( ds );

   // test the packet processor framework
   im.Process( &(ds[0]), ds.size(), ds.GetStreamEndian() );
   CPPUNIT_ASSERT_EQUAL( hp_es._hits, NUM_ES );  // better be hit for all the ESPdu only
   CPPUNIT_ASSERT_EQUAL( hp_dt._hits, (unsigned int)1 );  // better be hit for all the ESPdu only

   // clean up things
   im.RemoveProcessor( hp_es.GetRegisteredType() , &hp_es );
   im.RemoveProcessor( hp_dt.GetRegisteredType() , &hp_dt );
}

