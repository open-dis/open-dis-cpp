#include "catch.hpp"
#include "PduSampleData.h"
#include <dis7/utils/DataStream.h>
#include <iostream>
#include <iomanip>

using namespace DIS;
using namespace DIS::Test;

// Helper function to print hex dump of buffer
static void printHexDump(const char* data, size_t length, const std::string& label) {
    std::cout << "\n" << label << " (" << length << " bytes):\n";
    for (size_t i = 0; i < length; ++i) {
        if (i % 16 == 0) {
            std::cout << std::setw(4) << std::setfill('0') << std::hex << i << ": ";
        }
        std::cout << std::setw(2) << std::setfill('0') << std::hex
                  << (static_cast<unsigned int>(static_cast<unsigned char>(data[i])) & 0xFF) << " ";
        if ((i + 1) % 16 == 0 || i == length - 1) {
            std::cout << "\n";
        }
    }
    std::cout << std::dec;
}

// Verify PDU header structure (first 12 bytes)
static bool verifyPduHeader(const DataStream& stream, unsigned char expectedPduType,
                           unsigned char expectedFamily, unsigned char expectedVersion = 7) {
    if (stream.size() < 12) return false;

    const char* data = stream.data();
    unsigned char protocolVersion = static_cast<unsigned char>(data[0]);
    unsigned char exerciseID = static_cast<unsigned char>(data[1]);
    unsigned char pduType = static_cast<unsigned char>(data[2]);
    unsigned char family = static_cast<unsigned char>(data[3]);

    return (protocolVersion == expectedVersion) &&
           (pduType == expectedPduType) &&
           (family == expectedFamily);
}

TEST_CASE("EntityStatePdu Wire Format", "[pdu][wire][entity]") {
    EntityStatePdu pdu = createSampleEntityStatePdu();
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    printHexDump(stream.data(), stream.size(), "EntityStatePdu Wire Format");

    REQUIRE(stream.size() == 144);
    REQUIRE(verifyPduHeader(stream, 1, 1));  // PDU Type 1, Family 1
}

TEST_CASE("FirePdu Wire Format", "[pdu][wire][warfare]") {
    FirePdu pdu = createSampleFirePdu();
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    printHexDump(stream.data(), stream.size(), "FirePdu Wire Format");

    REQUIRE(stream.size() == 128);
    REQUIRE(verifyPduHeader(stream, 2, 2));  // PDU Type 2, Family 2
}

TEST_CASE("DetonationPdu Wire Format", "[pdu][wire][warfare]") {
    DetonationPdu pdu = createSampleDetonationPdu();
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    printHexDump(stream.data(), stream.size(), "DetonationPdu Wire Format");

    REQUIRE(stream.size() == 128);
    REQUIRE(verifyPduHeader(stream, 3, 2));  // PDU Type 3, Family 2
}

TEST_CASE("TransmitterPdu Wire Format", "[pdu][wire][radio]") {
    TransmitterPdu pdu = createSampleTransmitterPdu();
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    printHexDump(stream.data(), stream.size(), "TransmitterPdu Wire Format");

    REQUIRE(stream.size() == 104);
    REQUIRE(verifyPduHeader(stream, 25, 4));  // PDU Type 25, Family 4

    // Verify RadioType structure (64 bits starting at offset 32)
    const char* data = stream.data();
    unsigned char entityKind = static_cast<unsigned char>(data[32]);
    unsigned char domain = static_cast<unsigned char>(data[33]);

    REQUIRE(entityKind == 7);  // Radio
    REQUIRE(domain == 1);      // Air
}

TEST_CASE("SignalPdu Wire Format", "[pdu][wire][radio]") {
    SignalPdu pdu = createSampleSignalPdu();
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    printHexDump(stream.data(), stream.size(), "SignalPdu Wire Format");

    REQUIRE(stream.size() == 196);
    REQUIRE(verifyPduHeader(stream, 26, 4));  // PDU Type 26, Family 4

    // Verify encoding scheme (16 bits at offset 32)
    const char* data = stream.data();
    unsigned short encodingScheme = (static_cast<unsigned char>(data[32]) << 8) |
                                   static_cast<unsigned char>(data[33]);
    REQUIRE(encodingScheme == 0x0001);  // 8-bit mu-law
}

TEST_CASE("StartResumePdu Wire Format", "[pdu][wire][simman]") {
    StartResumePdu pdu = createSampleStartResumePdu();
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    printHexDump(stream.data(), stream.size(), "StartResumePdu Wire Format");

    REQUIRE(stream.size() == 56);
    REQUIRE(verifyPduHeader(stream, 13, 5));  // PDU Type 13, Family 5
}

TEST_CASE("StopFreezePdu Wire Format", "[pdu][wire][simman]") {
    StopFreezePdu pdu = createSampleStopFreezePdu();
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    printHexDump(stream.data(), stream.size(), "StopFreezePdu Wire Format");

    REQUIRE(stream.size() == 56);
    REQUIRE(verifyPduHeader(stream, 14, 5));  // PDU Type 14, Family 5
}

TEST_CASE("DesignatorPdu Wire Format", "[pdu][wire][der]") {
    DesignatorPdu pdu = createSampleDesignatorPdu();
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    printHexDump(stream.data(), stream.size(), "DesignatorPdu Wire Format");

    REQUIRE(stream.size() == 116);
    REQUIRE(verifyPduHeader(stream, 24, 6));  // PDU Type 24, Family 6
}

TEST_CASE("Byte Order Verification", "[pdu][wire][byteorder]") {
    // Create EntityID with known values
    EntityID entityId;
    entityId.setSite(0x0102);
    entityId.setApplication(0x0304);
    entityId.setEntity(0x0506);

    // Marshal just the EntityID (6 bytes)
    DataStream stream(DIS::BIG);
    stream << entityId.getSite();
    stream << entityId.getApplication();
    stream << entityId.getEntity();

    printHexDump(stream.data(), stream.size(), "EntityID Byte Order Test");

    // Verify big-endian byte order
    const char* data = stream.data();
    REQUIRE(static_cast<unsigned char>(data[0]) == 0x01);  // Site MSB
    REQUIRE(static_cast<unsigned char>(data[1]) == 0x02);  // Site LSB
    REQUIRE(static_cast<unsigned char>(data[2]) == 0x03);  // App MSB
    REQUIRE(static_cast<unsigned char>(data[3]) == 0x04);  // App LSB
    REQUIRE(static_cast<unsigned char>(data[4]) == 0x05);  // Entity MSB
    REQUIRE(static_cast<unsigned char>(data[5]) == 0x06);  // Entity LSB
}

TEST_CASE("Padding Verification EntityStatePdu", "[pdu][wire][padding]") {
    EntityStatePdu pdu = createSampleEntityStatePdu();
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    // EntityStatePdu should have specific padding bytes
    // This test verifies that padding is correctly placed and zeroed
    // According to IEEE 1278.1-2012, padding should be zero-filled

    REQUIRE(stream.size() == 144);

    // Padding bytes should be present but verification of zero-filling
    // requires knowing exact field offsets from the spec
    // This is a placeholder for detailed padding verification
    std::cout << "\nNote: Detailed padding verification requires IEEE spec field offsets\n";
}

TEST_CASE("Variable Length Field Handling", "[pdu][wire][variable]") {
    SignalPdu pdu = createSampleSignalPdu();

    // Test with different data lengths
    std::vector<uint8_t> shortData(80, 0x55);  // 80 bytes
    pdu.setData(shortData);
    pdu.setDataLength(shortData.size() * 8);  // Length in bits
    pdu.setSamples(80);

    DataStream stream1(DIS::BIG);
    pdu.marshal(stream1);

    REQUIRE(stream1.size() == (36 + 80));  // Header + data

    // Test with longer data
    std::vector<uint8_t> longData(320, 0xAA);  // 320 bytes
    pdu.setData(longData);
    pdu.setDataLength(longData.size() * 8);
    pdu.setSamples(320);

    DataStream stream2(DIS::BIG);
    pdu.marshal(stream2);

    REQUIRE(stream2.size() == (36 + 320));  // Header + data

    std::cout << "\nVariable length field handling: 80 bytes -> " << stream1.size()
              << ", 320 bytes -> " << stream2.size() << "\n";
}