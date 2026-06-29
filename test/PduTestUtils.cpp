#include "PduTestUtils.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace DIS {
namespace Test {

void PduTestReporter::addResult(const PduTestResult& result) {
    results_.push_back(result);
}

int PduTestReporter::getPassedTests() const {
    return std::count_if(results_.begin(), results_.end(),
        [](const PduTestResult& r) { return r.allTestsPassed(); });
}

int PduTestReporter::getFailedTests() const {
    return getTotalTests() - getPassedTests();
}

int PduTestReporter::getCompliantCount() const {
    return std::count_if(results_.begin(), results_.end(),
        [](const PduTestResult& r) { return r.category == PduTestCategory::COMPLIANT; });
}

int PduTestReporter::getUsableWarningCount() const {
    return std::count_if(results_.begin(), results_.end(),
        [](const PduTestResult& r) { return r.category == PduTestCategory::USABLE_WARNING; });
}

std::string PduTestReporter::generateMarkdownReport() const {
    std::ostringstream report;

    report << "# PDU Test Suite Results\n\n";
    report << "Generated: " << __DATE__ << " " << __TIME__ << "\n\n";

    // Summary statistics
    report << "## Summary\n\n";
    report << "- Total Tests: " << getTotalTests() << "\n";
    report << "- Passed: " << getPassedTests() << "\n";
    report << "- Failed: " << getFailedTests() << "\n";
    report << "- Success Rate: " << std::fixed << std::setprecision(1)
           << (getTotalTests() > 0 ? (100.0 * getPassedTests() / getTotalTests()) : 0.0) << "%\n";
    report << "- Compliant PDUs: " << getCompliantCount() << "\n";
    report << "- Usable with Warnings: " << getUsableWarningCount() << "\n\n";

    // Detailed results table
    report << "## Detailed Results\n\n";
    report << "| PDU Name | Category | Marshal/Unmarshal | Wire Size | Field Equality | Expected Size | Actual Size | Time (us) |\n";
    report << "|----------|----------|-------------------|-----------|----------------|---------------|-------------|----------|\n";

    for (const auto& result : results_) {
        report << "| " << result.pduName << " ";
        report << "| " << categoryToString(result.category) << " ";
        report << "| " << (result.marshalUnmarshalPassed ? "PASS" : "FAIL") << " ";
        report << "| " << (result.wireFormatSizePassed ? "PASS" : "FAIL") << " ";
        report << "| " << (result.fieldEqualityPassed ? "PASS" : "FAIL") << " ";
        report << "| " << result.expectedSize << " ";
        report << "| " << result.actualSize << " ";
        report << "| " << (result.marshalTimeUs + result.unmarshalTimeUs) << " |\n";
    }

    // Failed tests details
    int failedCount = 0;
    for (const auto& result : results_) {
        if (!result.allTestsPassed() && !result.errorMessage.empty()) {
            if (failedCount == 0) {
                report << "\n## Failed Test Details\n\n";
            }
            failedCount++;
            report << "### " << result.pduName << "\n\n";
            report << "- Category: " << categoryToString(result.category) << "\n";
            report << "- Error: " << result.errorMessage << "\n";
            if (!result.wireFormatSizePassed) {
                report << "- Expected Size: " << result.expectedSize << " bytes\n";
                report << "- Actual Size: " << result.actualSize << " bytes\n";
                report << "- Size Difference: " << (result.actualSize - result.expectedSize) << " bytes\n";
            }
            report << "\n";
        }
    }

    return report.str();
}

std::string PduTestReporter::generateXmlReport() const {
    std::ostringstream report;

    report << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    report << "<testsuites name=\"PDU Test Suite\" tests=\"" << getTotalTests()
           << "\" failures=\"" << getFailedTests() << "\">\n";
    report << "  <testsuite name=\"PDU Tests\" tests=\"" << getTotalTests()
           << "\" failures=\"" << getFailedTests() << "\">\n";

    for (const auto& result : results_) {
        report << "    <testcase name=\"" << result.pduName << "\" ";
        report << "classname=\"" << categoryToString(result.category) << "\" ";
        report << "time=\"" << std::fixed << std::setprecision(6)
               << ((result.marshalTimeUs + result.unmarshalTimeUs) / 1000000.0) << "\"";

        if (!result.allTestsPassed()) {
            report << ">\n";
            report << "      <failure message=\"" << result.errorMessage << "\">\n";
            if (!result.marshalUnmarshalPassed) {
                report << "Marshal/Unmarshal: FAILED\n";
            }
            if (!result.wireFormatSizePassed) {
                report << "Wire Format Size: FAILED (expected " << result.expectedSize
                       << ", got " << result.actualSize << ")\n";
            }
            if (!result.fieldEqualityPassed) {
                report << "Field Equality: FAILED\n";
            }
            report << "      </failure>\n";
            report << "    </testcase>\n";
        } else {
            report << " />\n";
        }
    }

    report << "  </testsuite>\n";
    report << "</testsuites>\n";

    return report.str();
}

std::string PduTestReporter::generateJsonReport() const {
    std::ostringstream report;

    report << "{\n";
    report << "  \"summary\": {\n";
    report << "    \"total_tests\": " << getTotalTests() << ",\n";
    report << "    \"passed\": " << getPassedTests() << ",\n";
    report << "    \"failed\": " << getFailedTests() << ",\n";
    report << "    \"success_rate\": " << std::fixed << std::setprecision(2)
           << (getTotalTests() > 0 ? (100.0 * getPassedTests() / getTotalTests()) : 0.0) << ",\n";
    report << "    \"compliant_count\": " << getCompliantCount() << ",\n";
    report << "    \"usable_warning_count\": " << getUsableWarningCount() << "\n";
    report << "  },\n";
    report << "  \"tests\": [\n";

    for (size_t i = 0; i < results_.size(); ++i) {
        const auto& result = results_[i];
        report << "    {\n";
        report << "      \"pdu_name\": \"" << result.pduName << "\",\n";
        report << "      \"category\": \"" << categoryToString(result.category) << "\",\n";
        report << "      \"marshal_unmarshal_passed\": " << (result.marshalUnmarshalPassed ? "true" : "false") << ",\n";
        report << "      \"wire_format_size_passed\": " << (result.wireFormatSizePassed ? "true" : "false") << ",\n";
        report << "      \"field_equality_passed\": " << (result.fieldEqualityPassed ? "true" : "false") << ",\n";
        report << "      \"expected_size\": " << result.expectedSize << ",\n";
        report << "      \"actual_size\": " << result.actualSize << ",\n";
        report << "      \"marshal_time_us\": " << result.marshalTimeUs << ",\n";
        report << "      \"unmarshal_time_us\": " << result.unmarshalTimeUs << ",\n";
        report << "      \"error_message\": \"" << result.errorMessage << "\"\n";
        report << "    }";
        if (i < results_.size() - 1) {
            report << ",";
        }
        report << "\n";
    }

    report << "  ]\n";
    report << "}\n";

    return report.str();
}

} // namespace Test
} // namespace DIS