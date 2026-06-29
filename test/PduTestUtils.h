#pragma once

#include <dis7/Pdu.h>
#include <dis7/utils/DataStream.h>
#include <string>
#include <vector>
#include <chrono>

namespace DIS {
namespace Test {

// Test category classification
enum class PduTestCategory {
    COMPLIANT,        // Fully compliant, wire format verified
    USABLE_WARNING,   // Functional but with known issues
    DO_NOT_USE        // Critical issues, should not be tested
};

// Individual test result for a PDU type
struct PduTestResult {
    std::string pduName;
    PduTestCategory category;
    bool marshalUnmarshalPassed;
    bool wireFormatSizePassed;
    bool fieldEqualityPassed;
    int expectedSize;
    int actualSize;
    std::string errorMessage;
    long long marshalTimeUs;
    long long unmarshalTimeUs;

    PduTestResult()
        : category(PduTestCategory::COMPLIANT),
          marshalUnmarshalPassed(false),
          wireFormatSizePassed(false),
          fieldEqualityPassed(false),
          expectedSize(0),
          actualSize(0),
          marshalTimeUs(0),
          unmarshalTimeUs(0) {}

    bool allTestsPassed() const {
        return marshalUnmarshalPassed && wireFormatSizePassed && fieldEqualityPassed;
    }
};

// Test reporter for aggregating and outputting results
class PduTestReporter {
private:
    std::vector<PduTestResult> results_;

public:
    void addResult(const PduTestResult& result);

    // Report generation
    std::string generateMarkdownReport() const;
    std::string generateXmlReport() const;
    std::string generateJsonReport() const;

    // Statistics
    int getTotalTests() const { return results_.size(); }
    int getPassedTests() const;
    int getFailedTests() const;
    int getCompliantCount() const;
    int getUsableWarningCount() const;

    const std::vector<PduTestResult>& getResults() const { return results_; }
    void clear() { results_.clear(); }
};

// Template function to test marshal/unmarshal round-trip
template<typename T>
PduTestResult testMarshalUnmarshal(const T& originalPdu, const std::string& pduName,
                                   PduTestCategory category, int expectedWireSize) {
    PduTestResult result;
    result.pduName = pduName;
    result.category = category;
    result.expectedSize = expectedWireSize;

    try {
        // Marshal original PDU
        DIS::DataStream marshalStream(DIS::BIG);
        auto marshalStart = std::chrono::high_resolution_clock::now();
        originalPdu.marshal(marshalStream);
        auto marshalEnd = std::chrono::high_resolution_clock::now();
        result.marshalTimeUs = std::chrono::duration_cast<std::chrono::microseconds>(
            marshalEnd - marshalStart).count();

        // Check wire format size
        result.actualSize = marshalStream.size();
        result.wireFormatSizePassed = (result.actualSize == expectedWireSize);

        // Unmarshal into new PDU
        T unmarshaledPdu;
        DIS::DataStream unmarshalStream(marshalStream.data(), marshalStream.size(), DIS::BIG);
        auto unmarshalStart = std::chrono::high_resolution_clock::now();
        unmarshaledPdu.unmarshal(unmarshalStream);
        auto unmarshalEnd = std::chrono::high_resolution_clock::now();
        result.unmarshalTimeUs = std::chrono::duration_cast<std::chrono::microseconds>(
            unmarshalEnd - unmarshalStart).count();

        result.marshalUnmarshalPassed = true;

        // Test equality
        result.fieldEqualityPassed = (originalPdu == unmarshaledPdu);

        if (!result.fieldEqualityPassed) {
            result.errorMessage = "Field equality check failed after round-trip";
        }

    } catch (const std::exception& e) {
        result.marshalUnmarshalPassed = false;
        result.wireFormatSizePassed = false;
        result.fieldEqualityPassed = false;
        result.errorMessage = std::string("Exception: ") + e.what();
    }

    return result;
}

// Template function to test wire format size only
template<typename T>
bool testWireFormatSize(const T& pdu, int expectedSize) {
    try {
        DIS::DataStream stream(DIS::BIG);
        pdu.marshal(stream);
        return stream.size() == expectedSize;
    } catch (...) {
        return false;
    }
}

// Template function to test field equality
template<typename T>
bool testFieldEquality(const T& pdu1, const T& pdu2) {
    try {
        return pdu1 == pdu2;
    } catch (...) {
        return false;
    }
}

// Helper to get category name as string
inline std::string categoryToString(PduTestCategory category) {
    switch (category) {
        case PduTestCategory::COMPLIANT: return "Compliant";
        case PduTestCategory::USABLE_WARNING: return "Usable with Warnings";
        case PduTestCategory::DO_NOT_USE: return "Do Not Use";
        default: return "Unknown";
    }
}

} // namespace Test
} // namespace DIS