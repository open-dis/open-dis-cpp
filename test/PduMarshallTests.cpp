#include "catch.hpp"

#include "PduUtils.h"
#include "dis6/DetonationPdu.h"
#include "dis6/EntityStatePdu.h"
#include "dis6/utils/DataStream.h"
#include "dis6/utils/StreamUtils.h"

template <typename PduT, unsigned int clones, typename PduT2>
void CheckSerialization(const PduT& src1, const PduT2& src2) {
  DIS::DataStream ds(DIS::BIG);
  PduT pdu_array[clones];

  // initialize the array
  // also add data to the stream
  for (unsigned int c_index = 0; c_index < clones; ++c_index) {
    pdu_array[c_index] = src1;
    pdu_array[c_index].marshal(ds);
  }
  src2.marshal(ds);

  // now pull data from the stream and check the values
  for (unsigned int c_index = 0; c_index < clones; ++c_index) {
    PduT copy;
    // copy the data
    copy.unmarshal(ds);

    // check to see if the copy has the same data as the pdu
    REQUIRE(pdu_array[c_index] == copy);
  }

  PduT2 copy2;
  copy2.unmarshal(ds);
  REQUIRE(src2 == copy2);
}

TEST_CASE("EntityStatePdu serialization", "[PduMarshall]") {
  DIS::EntityStatePdu p1;
  TestDIS::InitPDU(p1);

  DIS::DetonationPdu p2;
  TestDIS::InitPDU(p2);

  CheckSerialization<DIS::EntityStatePdu, 3, DIS::DetonationPdu>(p1, p2);
}

TEST_CASE("DetonationPdu serialization", "[PduMarshall]") {
  DIS::DetonationPdu p1;
  TestDIS::InitPDU(p1);

  DIS::EntityStatePdu p2;
  TestDIS::InitPDU(p2);

  CheckSerialization<DIS::DetonationPdu, 3, DIS::EntityStatePdu>(p1, p2);
}
