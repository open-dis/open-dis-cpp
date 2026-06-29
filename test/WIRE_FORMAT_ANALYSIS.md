# Wire Format Size Analysis

**Analysis Date**: 2025-09-30
**Analyst**: Claude (AI Assistant)
**Branch**: Roundtable-v1.1.0.0
**Reference**: IEEE Std 1278.1-2012

## Executive Summary

All wire format size "discrepancies" identified in testing were **test errors**, not implementation bugs. The open-dis-cpp library correctly implements IEEE 1278.1-2012 wire format specifications for both SignalPdu and StartResumePdu.

### Findings
| PDU | Test Expected | Actual Marshaled | IEEE Spec | Status |
|-----|--------------|------------------|-----------|--------|
| **SignalPdu** | 196 bytes | 192 bytes | 192 bytes | ✅ **CORRECT** |
| **StartResumePdu** | 56 bytes | 44 bytes | 44 bytes | ✅ **CORRECT** |

## Issue 1: SignalPdu Size (192 vs 196 bytes)

### Test Observation
```
C:\Dev\roundtable\open-dis-cpp\test\PduBasicTests.cpp(101): FAILED:
  REQUIRE( stream.size() == 196 )
with expansion:
  192 == 196
```

### Root Cause: **TEST ERROR**

The test incorrectly expected 196 bytes. The open-dis-cpp implementation marshals **192 bytes**, which is **CORRECT** per IEEE specification.

### IEEE Specification (Table 178)

**Reference**: IEEE Std 1278.1-2012, Section 7.7.3, Table 178 (Page 416)

```
Total Signal PDU size = 256 + K + P bits

where:
  K = data length in bits
  P = padding bits to 32-bit boundary
```

**For test case with 160-byte voice data**:
- K = 1280 bits (160 bytes × 8)
- P = 0 bits (already 32-bit aligned)
- Total = 256 + 1280 + 0 = **1536 bits = 192 bytes**

### Field-by-Field Breakdown

| Field | Size (bits) | Size (bytes) | IEEE Reference |
|-------|-------------|--------------|----------------|
| **PDU Header** | | | |
| Protocol Version | 8 | 1 | 6.2.66 |
| Exercise ID | 8 | 1 | 6.2.66 |
| PDU Type (26) | 8 | 1 | 6.2.66 |
| Protocol Family (4) | 8 | 1 | 6.2.66 |
| Timestamp | 32 | 4 | 6.2.66 |
| Length | 16 | 2 | 6.2.66 |
| PDU Status | 8 | 1 | 6.2.66 |
| Padding | 8 | 1 | 6.2.66 |
| **Subtotal** | **96** | **12** | |
| **Radio Identifier** | | | |
| Site Number | 16 | 2 | 6.2.70 |
| Application Number | 16 | 2 | 6.2.70 |
| Reference Number | 16 | 2 | 6.2.70 |
| Radio Number | 16 | 2 | 7.7.3 |
| **Subtotal** | **64** | **8** | |
| **Signal Parameters** | | | |
| Encoding Scheme | 16 | 2 | Table 177 |
| TDL Type | 16 | 2 | [UID 178] |
| Sample Rate | 32 | 4 | 7.7.3 |
| Data Length (K) | 16 | 2 | 7.7.3 |
| Samples | 16 | 2 | 7.7.3 |
| **Subtotal** | **96** | **12** | |
| **Data** | 1280 | 160 | 7.7.3 |
| **Padding** | 0 | 0 | (aligned) |
| **TOTAL** | **1536** | **192** | ✅ |

### Implementation Verification

**File**: `open-dis-cpp/src/dis7/SignalPdu.cpp`

```cpp
int SignalPdu::getMarshalledSize() const
{
  auto marshalSize = 0;

  marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize(); // 20 bytes
  marshalSize += 2; // _encodingScheme
  marshalSize += 2; // _tdlType
  marshalSize += 4; // _sampleRate
  marshalSize += 2; // _dataLength
  marshalSize += 2; // _samples
  marshalSize += _data.size(); // 160 bytes

  return marshalSize; // 192 bytes total ✅
}
```

**RadioCommunicationsFamilyPdu base**: 20 bytes
- Pdu (12) + EntityID (6) + RadioId (2) = 20 bytes

**SignalPdu fields**: 12 bytes (2+2+4+2+2)

**Data**: 160 bytes

**Total**: 20 + 12 + 160 = **192 bytes** ✅

### Conclusion: Issue 1

**Status**: ✅ **NO ISSUE - Implementation is CORRECT**
**Source of Error**: Test assumption (196 bytes) was incorrect
**Action Taken**: Test corrected to expect 192 bytes (commit: test fixes)
**IEEE Compliance**: **FULL COMPLIANCE** ✅

---

## Issue 2: StartResumePdu Size (44 vs 56 bytes)

### Test Observation
```
C:\Dev\roundtable\open-dis-cpp\test\PduBasicTests.cpp(131): FAILED:
  REQUIRE( stream.size() == 56 )
with expansion:
  44 == 56
```

### Root Cause: **TEST ERROR**

The test incorrectly expected 56 bytes. The open-dis-cpp implementation marshals **44 bytes**, which is **CORRECT** per IEEE specification.

### IEEE Specification (Table 151)

**Reference**: IEEE Std 1278.1-2012, Section 7.5.5, Table 151 (Page 367)

```
Total Start/Resume PDU size = 352 bits
```

**Calculation**: 352 bits ÷ 8 = **44 bytes** ✅

### Field-by-Field Breakdown

| Field | Size (bits) | Size (bytes) | IEEE Reference |
|-------|-------------|--------------|----------------|
| **PDU Header** | | | |
| Protocol Version | 8 | 1 | 6.2.66 |
| Exercise ID | 8 | 1 | 6.2.66 |
| PDU Type (13) | 8 | 1 | 6.2.66 |
| Protocol Family (5) | 8 | 1 | 6.2.66 |
| Timestamp | 32 | 4 | 6.2.66 |
| Length | 16 | 2 | 6.2.66 |
| PDU Status | 8 | 1 | 6.2.66 |
| Padding | 8 | 1 | 6.2.66 |
| **Subtotal** | **96** | **12** | |
| **Originating ID** | | | |
| Site Number | 16 | 2 | 6.2.28 |
| Application Number | 16 | 2 | 6.2.28 |
| Reference Number | 16 | 2 | 6.2.28 |
| **Subtotal** | **48** | **6** | |
| **Receiving ID** | | | |
| Site Number | 16 | 2 | 6.2.28 |
| Application Number | 16 | 2 | 6.2.28 |
| Reference Number | 16 | 2 | 6.2.28 |
| **Subtotal** | **48** | **6** | |
| **Real-World Time** | | | |
| Hour | 32 | 4 | 6.2.14 |
| Time Past Hour | 32 | 4 | 6.2.14 |
| **Subtotal** | **64** | **8** | |
| **Simulation Time** | | | |
| Hour | 32 | 4 | 6.2.14 |
| Time Past Hour | 32 | 4 | 6.2.14 |
| **Subtotal** | **64** | **8** | |
| **Request ID** | 32 | 4 | 7.5.5 |
| **TOTAL** | **352** | **44** | ✅ |

### Implementation Verification

**File**: `open-dis-cpp/src/dis7/StartResumePdu.cpp`

```cpp
int StartResumePdu::getMarshalledSize() const
{
  int marshalSize = 0;

  marshalSize = SimulationManagementFamilyPdu::getMarshalledSize(); // 24 bytes
  marshalSize = marshalSize + _realWorldTime.getMarshalledSize();  // 8 bytes
  marshalSize = marshalSize + _simulationTime.getMarshalledSize(); // 8 bytes
  marshalSize = marshalSize + 4;  // _requestID

  return marshalSize; // 44 bytes total ✅
}
```

**Component Sizes**:
- SimulationManagementFamilyPdu: 24 bytes
  - Pdu (12) + OriginatingEntityID (6) + ReceivingEntityID (6) = 24
- RealWorldTime (ClockTime): 8 bytes (4 + 4)
- SimulationTime (ClockTime): 8 bytes (4 + 4)
- RequestID: 4 bytes

**Total**: 24 + 8 + 8 + 4 = **44 bytes** ✅

### Possible Source of 56-Byte Expectation

The 56-byte expectation may have originated from:

1. **DIS 6 Difference**: DIS 6 may have used different ClockTime structure
2. **Padding Assumption**: Incorrect assumption of 8-byte alignment padding
3. **Field Miscount**: Assuming 12-byte ClockTime instead of 8-byte

**Analysis**: IEEE 1278.1-2012 (DIS 7) explicitly specifies 352 bits total with no additional padding fields beyond those shown in Table 151.

### Conclusion: Issue 2

**Status**: ✅ **NO ISSUE - Implementation is CORRECT**
**Source of Error**: Test assumption (56 bytes) was incorrect
**Action Taken**: Test corrected to expect 44 bytes (commit: test fixes)
**IEEE Compliance**: **FULL COMPLIANCE** ✅

---

## Summary of Related Files Changed

### During Porting (TransmitterPdu & SignalPdu)
1. `open-dis-cpp/src/dis7/TransmitterPdu.h` - NEW (ported from DIS 6)
2. `open-dis-cpp/src/dis7/TransmitterPdu.cpp` - NEW (ported from DIS 6)
3. `open-dis-cpp/src/dis7/SignalPdu.h` - NEW (ported from DIS 6, unchanged)
4. `open-dis-cpp/src/dis7/SignalPdu.cpp` - NEW (ported from DIS 6, unchanged)
5. `open-dis-cpp/src/dis7/CMakeLists.txt` - MODIFIED (added new PDU files)

**Porting Impact on Wire Format**: NONE - Both PDUs correctly implement IEEE spec

### During Testing
6. `open-dis-cpp/test/PduBasicTests.cpp` - NEW (test suite)
7. `open-dis-cpp/test/PduTestUtils.h` - NEW (test utilities)
8. `open-dis-cpp/test/PduTestUtils.cpp` - NEW (test utilities)
9. `open-dis-cpp/test/CMakeLists.txt` - MODIFIED (added test target)

**Testing Impact on Wire Format**: Test errors discovered and corrected

---

## Recommendations

### For Future Test Development

1. **Always Cross-Reference IEEE Spec**: Calculate expected sizes from IEEE tables before writing assertions
2. **Use getMarshalledSize()**: Trust the library's size calculation methods
3. **Document Size Calculations**: Include field-by-field breakdown in test comments
4. **Verify with Hex Dumps**: For critical PDUs, verify byte-level wire format

### Example Test Pattern

```cpp
TEST_CASE("SignalPdu Wire Format", "[pdu][wire][radio]") {
    // IEEE 1278.1-2012 Table 178:
    // Base: 256 bits (32 bytes)
    // Data: 1280 bits (160 bytes)
    // Padding: 0 bits (aligned)
    // Expected Total: 1536 bits (192 bytes)

    SignalPdu pdu = createSampleSignalPdu(160); // 160-byte data
    DataStream stream(DIS::BIG);
    pdu.marshal(stream);

    REQUIRE(stream.size() == 192); // From IEEE calculation
    REQUIRE(stream.size() == pdu.getMarshalledSize()); // Verify consistency
}
```

### For Documentation

1. Update `test/PDU_TEST_RESULTS.md` to reflect correct analysis
2. Add this wire format analysis to project documentation
3. Include IEEE table references in all PDU documentation

---

## Verification Checklist

- [x] IEEE Std 1278.1-2012 specification consulted
- [x] SignalPdu Table 178 (Section 7.7.3) verified
- [x] StartResumePdu Table 151 (Section 7.5.5) verified
- [x] open-dis-cpp implementation code reviewed
- [x] getMarshalledSize() calculations traced
- [x] Field-by-field byte counts calculated
- [x] Test assumptions identified and corrected
- [x] All tests passing with corrected expectations

---

## Conclusion

**NO BUGS FOUND** in open-dis-cpp implementation. Both SignalPdu and StartResumePdu:
- ✅ Correctly implement IEEE 1278.1-2012 wire format specifications
- ✅ Marshal to exact byte sizes specified in IEEE tables
- ✅ Successfully round-trip through marshal/unmarshal
- ✅ Maintain field equality after round-trip

The "discrepancies" were test errors caused by incorrect size assumptions. The open-dis-cpp library is fully compliant with the DIS 7 standard for these PDUs.

---

*Analysis completed 2025-09-30 by Claude AI Assistant*
*IEEE Std 1278.1-2012 references verified from ../ref/split/*
*All calculations independently verified against specification*