#include "catch.hpp"

#include "PduUtils.h"
#include "dis6/CollisionPdu.h"
#include "dis6/DetonationPdu.h"
#include "dis6/EntityStatePdu.h"
#include "dis6/utils/DataStream.h"
#include "dis6/utils/IPacketProcessor.h"
#include "dis6/utils/IncomingMessage.h"
#include "dis6/utils/PDUType.h"

using namespace DIS;

/// knows if it has been visited
class HitProcessor : public IPacketProcessor {
 private:
  PDUType mPduType;

 public:
  unsigned int _hits;

  HitProcessor(PDUType pdut) : IPacketProcessor(), mPduType(pdut), _hits(0) {}

  PDUType GetRegisteredType() const { return mPduType; }

  /// test casting to a concrete type
  void Process(const Pdu& packet) {
    // const EntityStatePdu& espdu = static_cast<const
    // EntityStatePdu&>( packet ); espdu.getEntityAppearance();
    _hits++;
  }

 private:
  HitProcessor();  ///< not implemented by design
};

template <typename PduT1, typename PduT2>
void TestMultiplePackets(const PduT1& src1, const PduT2& src2) {
  // populate the factory
  IncomingMessage im;

  // sample PDUs for testing
  const unsigned int NUM_ES = 3;
  PduT1 pdu1_array[NUM_ES];
  for (unsigned int pdu1clone = 0; pdu1clone < NUM_ES; ++pdu1clone) {
    pdu1_array[pdu1clone] = src1;
  }
  PduT2 pdu2 = src2;

  // will tell us if the packet processor framework within IncomingMessage is
  // working.
  HitProcessor hp_es((PDUType)pdu1_array[0].getPduType());
  HitProcessor hp_dt((PDUType)pdu2.getPduType());
  REQUIRE(hp_es._hits == (unsigned int)0);  // better not be hit yet
  REQUIRE(hp_dt._hits == (unsigned int)0);  // better not be hit yet

  // map the HitProcessor to the type of pdu
  im.AddProcessor(hp_es.GetRegisteredType(), &hp_es);
  im.AddProcessor(hp_dt.GetRegisteredType(), &hp_dt);

  // fake a network buffer to read
  DataStream ds(BIG);
  for (unsigned int pdu1clone = 0; pdu1clone < NUM_ES; ++pdu1clone) {
    pdu1_array[pdu1clone].marshal(ds);
  }
  pdu2.marshal(ds);

  // test the packet processor framework
  im.Process(&(ds[0]), ds.size(), ds.GetStreamEndian());
  REQUIRE(hp_es._hits == NUM_ES);  // better be hit for all the ESPdu only
  REQUIRE(hp_dt._hits ==
          (unsigned int)1);  // better be hit for all the ESPdu only

  // clean up things
  im.RemoveProcessor(hp_es.GetRegisteredType(), &hp_es);
  im.RemoveProcessor(hp_dt.GetRegisteredType(), &hp_dt);
}

TEST_CASE("Add/remove processor", "[IncomingMessage]") {
  EntityStatePdu espdu;
  HitProcessor hp0((PDUType)espdu.getPduType());

  IncomingMessage im;
  REQUIRE(im.GetProcessors().empty());

  // test a single mapping
  im.AddProcessor(hp0.GetRegisteredType(), &hp0);
  REQUIRE(im.GetProcessors().size() == size_t(1));

  im.RemoveProcessor(hp0.GetRegisteredType(), &hp0);
  REQUIRE(im.GetProcessors().size() == size_t(0));
  REQUIRE(im.GetProcessors().empty());

  // test the multimap
  CollisionPdu cpdu;
  HitProcessor hp1((PDUType)cpdu.getPduType());

  im.AddProcessor(hp0.GetRegisteredType(), &hp0);
  REQUIRE(im.GetProcessors().size() == size_t(1));

  im.AddProcessor(hp0.GetRegisteredType(), &hp1);
  REQUIRE(im.GetProcessors().size() == size_t(2));

  // This should not allow multiples of the exact same pair
  im.AddProcessor(hp0.GetRegisteredType(), &hp0);
  REQUIRE(im.GetProcessors().size() == size_t(2));

  // this should not remove the pair that does not exist
  im.RemoveProcessor(hp1.GetRegisteredType(), &hp0);
  REQUIRE(im.GetProcessors().size() == size_t(2));

  im.RemoveProcessor(hp0.GetRegisteredType(), &hp1);
  REQUIRE(im.GetProcessors().size() == size_t(1));

  im.RemoveProcessor(hp0.GetRegisteredType(), &hp0);
  REQUIRE(im.GetProcessors().size() == size_t(0));
  REQUIRE(im.GetProcessors().empty());
}

TEST_CASE("Observing", "[IncomingMessage]") {
  // sample pdu for testing
  EntityStatePdu espdu;

  // will tell us if the packet processor framework within IncomingMessage is
  // working.
  HitProcessor hp((PDUType)espdu.getPduType());
  REQUIRE(hp._hits == (unsigned int)0);  // better not be hit

  // map the HitProcessor to the type of pdu
  IncomingMessage im;
  im.AddProcessor(espdu.getPduType(), &hp);

  // fake a network buffer to read
  DataStream ds(BIG);
  espdu.marshal(ds);

  // test the packet processor framework
  im.Process(&(ds[0]), ds.size(), ds.GetStreamEndian());
  REQUIRE(hp._hits == (unsigned int)1);  // better be hit now

  // clean up things
  im.RemoveProcessor(espdu.getPduType(), &hp);
}

TEST_CASE("EntityState then Detonation", "[IncomingMessage]") {
  EntityStatePdu espdu;
  TestDIS::InitPDU(espdu);

  DetonationPdu detpdu;
  TestDIS::InitPDU(detpdu);

  TestMultiplePackets(espdu, detpdu);
}

TEST_CASE("Collision then EntityState", "[IncomingMessage]") {
  CollisionPdu colpdu;
  TestDIS::InitPDU(colpdu);

  EntityStatePdu espdu;
  TestDIS::InitPDU(espdu);

  TestMultiplePackets(colpdu, espdu);
}
