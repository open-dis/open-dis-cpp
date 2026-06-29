#include "catch.hpp"
#include "PduTestUtils.h"
#include "PduSampleData.h"
#include <fstream>
#include <iostream>

using namespace DIS;
using namespace DIS::Test;

// Global reporter to collect all results
static PduTestReporter g_reporter;

// Test all compliant PDUs
TEST_CASE("EntityStatePdu Marshal/Unmarshal", "[pdu][entity][compliant]") {
    EntityStatePdu pdu = createSampleEntityStatePdu();
    auto result = testMarshalUnmarshal(pdu, "EntityStatePdu", PduTestCategory::COMPLIANT, 144);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("FirePdu Marshal/Unmarshal", "[pdu][warfare][compliant]") {
    FirePdu pdu = createSampleFirePdu();
    auto result = testMarshalUnmarshal(pdu, "FirePdu", PduTestCategory::COMPLIANT, 128);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("DetonationPdu Marshal/Unmarshal", "[pdu][warfare][compliant]") {
    DetonationPdu pdu = createSampleDetonationPdu();
    auto result = testMarshalUnmarshal(pdu, "DetonationPdu", PduTestCategory::COMPLIANT, 128);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("CollisionPdu Marshal/Unmarshal", "[pdu][entity][compliant]") {
    CollisionPdu pdu = createSampleCollisionPdu();
    auto result = testMarshalUnmarshal(pdu, "CollisionPdu", PduTestCategory::COMPLIANT, 96);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("ServiceRequestPdu Marshal/Unmarshal", "[pdu][logistics][compliant]") {
    ServiceRequestPdu pdu = createSampleServiceRequestPdu();
    auto result = testMarshalUnmarshal(pdu, "ServiceRequestPdu", PduTestCategory::COMPLIANT, 52);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("ResupplyOfferPdu Marshal/Unmarshal", "[pdu][logistics][compliant]") {
    ResupplyOfferPdu pdu = createSampleResupplyOfferPdu();
    auto result = testMarshalUnmarshal(pdu, "ResupplyOfferPdu", PduTestCategory::COMPLIANT, 60);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("ResupplyReceivedPdu Marshal/Unmarshal", "[pdu][logistics][compliant]") {
    ResupplyReceivedPdu pdu = createSampleResupplyReceivedPdu();
    auto result = testMarshalUnmarshal(pdu, "ResupplyReceivedPdu", PduTestCategory::COMPLIANT, 52);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("RepairCompletePdu Marshal/Unmarshal", "[pdu][logistics][compliant]") {
    RepairCompletePdu pdu = createSampleRepairCompletePdu();
    auto result = testMarshalUnmarshal(pdu, "RepairCompletePdu", PduTestCategory::COMPLIANT, 40);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("RepairResponsePdu Marshal/Unmarshal", "[pdu][logistics][compliant]") {
    RepairResponsePdu pdu = createSampleRepairResponsePdu();
    auto result = testMarshalUnmarshal(pdu, "RepairResponsePdu", PduTestCategory::COMPLIANT, 44);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("StartResumePdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    StartResumePdu pdu = createSampleStartResumePdu();
    auto result = testMarshalUnmarshal(pdu, "StartResumePdu", PduTestCategory::COMPLIANT, 56);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("StopFreezePdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    StopFreezePdu pdu = createSampleStopFreezePdu();
    auto result = testMarshalUnmarshal(pdu, "StopFreezePdu", PduTestCategory::COMPLIANT, 56);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("AcknowledgePdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    AcknowledgePdu pdu = createSampleAcknowledgePdu();
    auto result = testMarshalUnmarshal(pdu, "AcknowledgePdu", PduTestCategory::COMPLIANT, 52);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("ActionRequestPdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    ActionRequestPdu pdu = createSampleActionRequestPdu();
    auto result = testMarshalUnmarshal(pdu, "ActionRequestPdu", PduTestCategory::COMPLIANT, 56);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("ActionResponsePdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    ActionResponsePdu pdu = createSampleActionResponsePdu();
    auto result = testMarshalUnmarshal(pdu, "ActionResponsePdu", PduTestCategory::COMPLIANT, 56);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("DataQueryPdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    DataQueryPdu pdu = createSampleDataQueryPdu();
    auto result = testMarshalUnmarshal(pdu, "DataQueryPdu", PduTestCategory::COMPLIANT, 60);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("SetDataPdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    SetDataPdu pdu = createSampleSetDataPdu();
    auto result = testMarshalUnmarshal(pdu, "SetDataPdu", PduTestCategory::COMPLIANT, 56);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("DataPdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    DataPdu pdu = createSampleDataPdu();
    auto result = testMarshalUnmarshal(pdu, "DataPdu", PduTestCategory::COMPLIANT, 56);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("EventReportPdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    EventReportPdu pdu = createSampleEventReportPdu();
    auto result = testMarshalUnmarshal(pdu, "EventReportPdu", PduTestCategory::COMPLIANT, 60);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("CommentPdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    CommentPdu pdu = createSampleCommentPdu();
    auto result = testMarshalUnmarshal(pdu, "CommentPdu", PduTestCategory::COMPLIANT, 52);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("CreateEntityPdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    CreateEntityPdu pdu = createSampleCreateEntityPdu();
    auto result = testMarshalUnmarshal(pdu, "CreateEntityPdu", PduTestCategory::COMPLIANT, 48);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("RemoveEntityPdu Marshal/Unmarshal", "[pdu][simman][compliant]") {
    RemoveEntityPdu pdu = createSampleRemoveEntityPdu();
    auto result = testMarshalUnmarshal(pdu, "RemoveEntityPdu", PduTestCategory::COMPLIANT, 48);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("DesignatorPdu Marshal/Unmarshal", "[pdu][der][compliant]") {
    DesignatorPdu pdu = createSampleDesignatorPdu();
    auto result = testMarshalUnmarshal(pdu, "DesignatorPdu", PduTestCategory::COMPLIANT, 116);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("TransmitterPdu Marshal/Unmarshal", "[pdu][radio][compliant]") {
    TransmitterPdu pdu = createSampleTransmitterPdu();
    auto result = testMarshalUnmarshal(pdu, "TransmitterPdu", PduTestCategory::COMPLIANT, 104);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("SignalPdu Marshal/Unmarshal", "[pdu][radio][compliant]") {
    SignalPdu pdu = createSampleSignalPdu();
    auto result = testMarshalUnmarshal(pdu, "SignalPdu", PduTestCategory::COMPLIANT, 196);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("ReceiverPdu Marshal/Unmarshal", "[pdu][radio][compliant]") {
    ReceiverPdu pdu = createSampleReceiverPdu();
    auto result = testMarshalUnmarshal(pdu, "ReceiverPdu", PduTestCategory::COMPLIANT, 48);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

TEST_CASE("EntityStateUpdatePdu Marshal/Unmarshal", "[pdu][entity][compliant]") {
    EntityStateUpdatePdu pdu = createSampleEntityStateUpdatePdu();
    auto result = testMarshalUnmarshal(pdu, "EntityStateUpdatePdu", PduTestCategory::COMPLIANT, 88);
    g_reporter.addResult(result);
    REQUIRE(result.allTestsPassed());
}

// Report generation at the end of test run
TEST_CASE("Generate Test Reports", "[pdu][report]") {
    std::cout << "\n=== PDU Test Suite Results ===\n";
    std::cout << "Total tests: " << g_reporter.getTotalTests() << "\n";
    std::cout << "Passed: " << g_reporter.getPassedTests() << "\n";
    std::cout << "Failed: " << g_reporter.getFailedTests() << "\n\n";

    // Generate Markdown report
    std::string markdownReport = g_reporter.generateMarkdownReport();
    std::ofstream mdFile("pdu_test_results.md");
    if (mdFile.is_open()) {
        mdFile << markdownReport;
        mdFile.close();
        std::cout << "Markdown report: pdu_test_results.md\n";
    }

    // Generate XML report
    std::string xmlReport = g_reporter.generateXmlReport();
    std::ofstream xmlFile("pdu_test_results.xml");
    if (xmlFile.is_open()) {
        xmlFile << xmlReport;
        xmlFile.close();
        std::cout << "XML report: pdu_test_results.xml\n";
    }

    // Generate JSON report
    std::string jsonReport = g_reporter.generateJsonReport();
    std::ofstream jsonFile("pdu_test_results.json");
    if (jsonFile.is_open()) {
        jsonFile << jsonReport;
        jsonFile.close();
        std::cout << "JSON report: pdu_test_results.json\n";
    }

    std::cout << "\n";

    // This test always passes - it's just for report generation
    REQUIRE(true);
}