#include "catch.hpp"

#include "dis6/EntityStatePdu.h"
#include "dis6/utils/DataStream.h"

template <typename T>
void TestData(DIS::Endian e, T t0, T t1, T t2) {
  DIS::DataStream ds(e);
  REQUIRE(ds.empty());

  size_t read_pos(0);
  size_t write_pos(0);

  // check the read and write positions
  REQUIRE(ds.GetReadPos() == read_pos);
  REQUIRE(ds.GetWritePos() == write_pos);

  // check the size of the buffer
  REQUIRE(ds.size() == write_pos);

  // fill the stream
  T ch = t0;
  ds << ch;
  REQUIRE(!ds.empty());
  write_pos += sizeof(T);
  REQUIRE(ds.size() == write_pos);         // size check
  REQUIRE(ds.GetReadPos() == read_pos);    // read check
  REQUIRE(ds.GetWritePos() == write_pos);  // write check

  ch = t1;
  ds << ch;
  write_pos += sizeof(T);
  REQUIRE(!ds.empty());                    // empty check
  REQUIRE(ds.size() == write_pos);         // size check
  REQUIRE(ds.GetReadPos() == read_pos);    // read check
  REQUIRE(ds.GetWritePos() == write_pos);  // write check

  ch = t2;
  ds << ch;
  write_pos += sizeof(T);
  REQUIRE(!ds.empty());                    // empty check
  REQUIRE(ds.size() == write_pos);         // size check
  REQUIRE(ds.GetReadPos() == read_pos);    // read check
  REQUIRE(ds.GetWritePos() == write_pos);  // write check

  // read from the stream
  ds >> ch;
  read_pos += sizeof(T);
  REQUIRE(ch == t0);                       // value check
  REQUIRE(!ds.empty());                    // empty check
  REQUIRE(ds.size() == write_pos);         // size check
  REQUIRE(ds.GetReadPos() == read_pos);    // read check
  REQUIRE(ds.GetWritePos() == write_pos);  // write check

  ds >> ch;
  read_pos += sizeof(T);
  REQUIRE(ch == t1);                       // value check
  REQUIRE(!ds.empty());                    // empty check
  REQUIRE(ds.size() == write_pos);         // size check
  REQUIRE(ds.GetReadPos() == read_pos);    // read check
  REQUIRE(ds.GetWritePos() == write_pos);  // write check

  ds >> ch;
  read_pos += sizeof(T);
  REQUIRE(ch == t2);                       // value check
  REQUIRE(!ds.empty());                    // empty check
  REQUIRE(ds.size() == write_pos);         // size check
  REQUIRE(ds.GetReadPos() == read_pos);    // read check
  REQUIRE(ds.GetWritePos() == write_pos);  // write check
}

TEST_CASE("DataStream encoding and decoding ", "[DataStream]") {
  TestData<char>(DIS::BIG, 'a', 'b', 'c');
  short a(1), b(2), c(3);
  TestData<short>(DIS::BIG, a, b, c);
  TestData<double>(DIS::BIG, 9., 10., 11.);
  TestData<float>(DIS::BIG, 9.f, 10.f, 11.f);
}

TEST_CASE("DataStream chaining datatypes", "[DataStream]") {
  // define a psuedo packet
  char id = 3;
  float x = 9.f;
  float y = 11.f;
  char length =
      sizeof(char) + sizeof(char) + sizeof(float) + sizeof(float);  // 10

  DIS::DataStream output(DIS::BIG);
  output << id << length << x << y;

  // catch the psuedo packet
  char inid = 0;
  char inlength = 0;
  float inx = 0;
  float iny = 0;

  DIS::DataStream input(&(output[0]), output.size(), output.GetStreamEndian());
  input >> inid >> inlength >> inx >> iny;

  REQUIRE(id == inid);
  REQUIRE(length == inlength);
  REQUIRE(x == inx);
  REQUIRE(y == iny);
}
