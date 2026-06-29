#include "PduSampleData.h"
#include <dis7/FixedDatum.h>
#include <dis7/VariableDatum.h>
#include <ctime>

namespace DIS {
namespace Test {

// Helper functions for common structures
EntityID createSampleEntityID(unsigned short siteID, unsigned short appID, unsigned short entityID) {
    EntityID id;
    id.setSite(siteID);
    id.setApplication(appID);
    id.setEntity(entityID);
    return id;
}

EntityType createSampleEntityType() {
    EntityType type;
    type.setEntityKind(1);    // Platform
    type.setDomain(1);        // Land
    type.setCountry(225);     // USA
    type.setCategory(1);      // Tank
    type.setSubcategory(1);   // M1 Abrams
    type.setSpecific(3);      // M1A1
    type.setExtra(0);
    return type;
}

Vector3Double createSampleVector3Double(double x, double y, double z) {
    Vector3Double vec;
    vec.setX(x);
    vec.setY(y);
    vec.setZ(z);
    return vec;
}

Vector3Float createSampleVector3Float(float x, float y, float z) {
    Vector3Float vec;
    vec.setX(x);
    vec.setY(y);
    vec.setZ(z);
    return vec;
}

EulerAngles createSampleEulerAngles(float psi, float theta, float phi) {
    EulerAngles angles;
    angles.setPsi(psi);
    angles.setTheta(theta);
    angles.setPhi(phi);
    return angles;
}

ClockTime createSampleClockTime() {
    ClockTime clockTime;
    clockTime.setHour(12);
    clockTime.setTimePastHour(1800000);  // 30 minutes in milliseconds
    return clockTime;
}

RadioType createSampleRadioType() {
    RadioType radioType;
    radioType.setEntityKind(7);      // Radio
    radioType.setDomain(1);          // Air
    radioType.setCountry(225);       // USA
    radioType.setCategory(1);        // Voice transmission/reception
    radioType.setSubcategory(1);     // UHF
    radioType.setSpecific(0);
    radioType.setExtra(0);
    return radioType;
}

EventIdentifier createSampleEventIdentifier() {
    EventIdentifier eventId;
    eventId.setSimulationAddress(createSampleEntityID(1, 1, 0));
    eventId.setEventNumber(1);
    return eventId;
}

// Warfare Family (Family 2)
FirePdu createSampleFirePdu() {
    FirePdu pdu;
    pdu.setFiringEntityID(createSampleEntityID(1, 1, 1));
    pdu.setTargetEntityID(createSampleEntityID(1, 1, 2));
    pdu.setMunitionID(createSampleEntityID(1, 1, 100));
    pdu.setEventID(createSampleEventIdentifier());
    pdu.setFireMissionIndex(0);
    pdu.setLocationInWorldCoordinates(createSampleVector3Double(1000.0, 2000.0, 100.0));
    pdu.setVelocity(createSampleVector3Float(200.0f, 0.0f, -10.0f));
    pdu.setRange(5000.0f);
    return pdu;
}

DetonationPdu createSampleDetonationPdu() {
    DetonationPdu pdu;
    pdu.setFiringEntityID(createSampleEntityID(1, 1, 1));
    pdu.setTargetEntityID(createSampleEntityID(1, 1, 2));
    pdu.setMunitionID(createSampleEntityID(1, 1, 100));
    pdu.setEventID(createSampleEventIdentifier());
    pdu.setVelocity(createSampleVector3Float(200.0f, 0.0f, -10.0f));
    pdu.setLocationInWorldCoordinates(createSampleVector3Double(1000.0, 2000.0, 100.0));
    pdu.setDetonationResult(1);  // Entity impact
    return pdu;
}

// Logistics Family (Family 3)
ServiceRequestPdu createSampleServiceRequestPdu() {
    ServiceRequestPdu pdu;
    pdu.setRequestingEntityID(createSampleEntityID(1, 1, 1));
    pdu.setServicingEntityID(createSampleEntityID(1, 1, 2));
    pdu.setServiceTypeRequested(0);  // Resupply
    pdu.setNumberOfSupplyTypes(0);
    return pdu;
}

ResupplyOfferPdu createSampleResupplyOfferPdu() {
    ResupplyOfferPdu pdu;
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 1));
    pdu.setSupplyingEntityID(createSampleEntityID(1, 1, 2));
    pdu.setNumberOfSupplyTypes(0);
    return pdu;
}

ResupplyReceivedPdu createSampleResupplyReceivedPdu() {
    ResupplyReceivedPdu pdu;
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 1));
    pdu.setSupplyingEntityID(createSampleEntityID(1, 1, 2));
    pdu.setNumberOfSupplyTypes(0);
    return pdu;
}

RepairCompletePdu createSampleRepairCompletePdu() {
    RepairCompletePdu pdu;
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 1));
    pdu.setRepairingEntityID(createSampleEntityID(1, 1, 2));
    pdu.setRepair(1);  // Minor damage repaired
    return pdu;
}

RepairResponsePdu createSampleRepairResponsePdu() {
    RepairResponsePdu pdu;
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 1));
    pdu.setRepairingEntityID(createSampleEntityID(1, 1, 2));
    pdu.setRepairResult(0);  // Repair ended
    return pdu;
}

// Simulation Management Family (Family 5)
StartResumePdu createSampleStartResumePdu() {
    StartResumePdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setRealWorldTime(createSampleClockTime());
    pdu.setSimulationTime(createSampleClockTime());
    pdu.setRequestID(1);
    return pdu;
}

StopFreezePdu createSampleStopFreezePdu() {
    StopFreezePdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setRealWorldTime(createSampleClockTime());
    pdu.setReason(1);  // Simulation paused by user
    pdu.setFrozenBehavior(0);
    pdu.setRequestID(1);
    return pdu;
}

AcknowledgePdu createSampleAcknowledgePdu() {
    AcknowledgePdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setAcknowledgeFlag(1);  // Acknowledge
    pdu.setResponseFlag(0);
    pdu.setRequestID(1);
    return pdu;
}

ActionRequestPdu createSampleActionRequestPdu() {
    ActionRequestPdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setRequestID(1);
    pdu.setActionID(1);
    // Number of datums auto-calculated from vector sizes
    return pdu;
}

ActionResponsePdu createSampleActionResponsePdu() {
    ActionResponsePdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setRequestID(1);
    pdu.setRequestStatus(0);  // Pending
    // Number of datums auto-calculated from vector sizes
    return pdu;
}

DataQueryPdu createSampleDataQueryPdu() {
    DataQueryPdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setRequestID(1);
    pdu.setTimeInterval(0);
    // Number of datums auto-calculated from vector sizes
    return pdu;
}

SetDataPdu createSampleSetDataPdu() {
    SetDataPdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setRequestID(1);
    // Number of datums auto-calculated from vector sizes
    return pdu;
}

DataPdu createSampleDataPdu() {
    DataPdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setRequestID(1);
    // Number of datums auto-calculated from vector sizes
    return pdu;
}

EventReportPdu createSampleEventReportPdu() {
    EventReportPdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setEventType(1);
    // Number of datums auto-calculated from vector sizes
    return pdu;
}

CommentPdu createSampleCommentPdu() {
    CommentPdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    // Number of datums auto-calculated from vector sizes
    return pdu;
}

CreateEntityPdu createSampleCreateEntityPdu() {
    CreateEntityPdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setRequestID(1);
    return pdu;
}

RemoveEntityPdu createSampleRemoveEntityPdu() {
    RemoveEntityPdu pdu;
    pdu.setOriginatingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setReceivingEntityID(createSampleEntityID(1, 1, 0));
    pdu.setRequestID(1);
    return pdu;
}

// Distributed Emission Regeneration Family (Family 6)
DesignatorPdu createSampleDesignatorPdu() {
    DesignatorPdu pdu;
    pdu.setDesignatingEntityID(createSampleEntityID(1, 1, 1));
    pdu.setDesignatedEntityID(createSampleEntityID(1, 1, 2));
    pdu.setCodeName(1);  // Laser
    pdu.setDesignatorCode(1688);  // Laser code
    pdu.setDesignatorPower(1.0f);
    pdu.setDesignatorWavelength(1.064f);  // Nd:YAG laser wavelength in microns
    pdu.setDesignatorSpotLocation(createSampleVector3Double(1000.0, 2000.0, 100.0));
    pdu.setDesignatorSpotWrtDesignated(createSampleVector3Float(0.0f, 0.0f, 0.0f));
    pdu.setEntityLinearAcceleration(createSampleVector3Float(0.0f, 0.0f, 0.0f));
    return pdu;
}

// Radio Communications Family (Family 4)
TransmitterPdu createSampleTransmitterPdu() {
    TransmitterPdu pdu;
    pdu.setEntityId(createSampleEntityID(1, 1, 1));
    pdu.setRadioId(1);
    pdu.setRadioType(createSampleRadioType());
    pdu.setTransmitState(1);  // On but not transmitting
    pdu.setInputSource(1);    // Operator
    pdu.setAntennaLocation(createSampleVector3Double(1000.0, 2000.0, 100.0));
    pdu.setRelativeAntennaLocation(createSampleVector3Float(0.0f, 0.0f, 2.5f));
    pdu.setFrequency(243000000ULL);  // 243 MHz (guard frequency)
    pdu.setPower(30.0f);  // 1 watt ERP
    return pdu;
}

SignalPdu createSampleSignalPdu() {
    SignalPdu pdu;
    pdu.setEntityId(createSampleEntityID(1, 1, 1));
    pdu.setRadioId(1);
    pdu.setEncodingScheme(0x0001);  // 8-bit mu-law
    pdu.setTdlType(0);  // Voice
    pdu.setSampleRate(8000);  // 8 kHz

    // 20ms of silence in mu-law (160 samples)
    std::vector<uint8_t> voiceData(160, 0x7F);
    pdu.setData(voiceData);
    pdu.setDataLength(static_cast<short>(voiceData.size() * 8));  // Length in bits
    pdu.setSamples(160);

    return pdu;
}

ReceiverPdu createSampleReceiverPdu() {
    ReceiverPdu pdu;
    pdu.setEntityId(createSampleEntityID(1, 1, 1));
    pdu.setRadioId(1);
    pdu.setReceiverState(1);  // On but not receiving
    pdu.setReceivedPower(0.0f);
    pdu.setTransmitterEntityId(createSampleEntityID(1, 1, 2));
    pdu.setTransmitterRadioId(1);
    return pdu;
}

// Entity Information/Interaction Family (Family 1)
EntityStatePdu createSampleEntityStatePdu() {
    EntityStatePdu pdu;
    pdu.setEntityID(createSampleEntityID(1, 1, 1));
    pdu.setForceId(1);  // Friendly
    // Number of articulation parameters auto-calculated from vector size
    pdu.setEntityType(createSampleEntityType());
    pdu.setEntityLocation(createSampleVector3Double(1000.0, 2000.0, 100.0));
    pdu.setEntityLinearVelocity(createSampleVector3Float(10.0f, 0.0f, 0.0f));
    pdu.setEntityOrientation(createSampleEulerAngles(0.0f, 0.0f, 0.0f));
    pdu.setEntityAppearance(0);
    pdu.setDeadReckoningParameters(DIS::DeadReckoningParameters());
    pdu.setMarking(DIS::EntityMarking());
    pdu.setCapabilities(0);
    return pdu;
}

CollisionPdu createSampleCollisionPdu() {
    CollisionPdu pdu;
    pdu.setIssuingEntityID(createSampleEntityID(1, 1, 1));
    pdu.setCollidingEntityID(createSampleEntityID(1, 1, 2));
    pdu.setEventID(createSampleEventIdentifier());
    pdu.setCollisionType(1);  // Inelastic
    pdu.setVelocity(createSampleVector3Float(10.0f, 5.0f, 0.0f));
    pdu.setMass(5000.0f);  // 5000 kg
    pdu.setLocation(createSampleVector3Float(0.0f, 0.0f, 1.0f));
    return pdu;
}

EntityStateUpdatePdu createSampleEntityStateUpdatePdu() {
    EntityStateUpdatePdu pdu;
    pdu.setEntityID(createSampleEntityID(1, 1, 1));
    // Number of articulation parameters auto-calculated from vector size
    pdu.setEntityLinearVelocity(createSampleVector3Float(10.0f, 0.0f, 0.0f));
    pdu.setEntityLocation(createSampleVector3Double(1000.0, 2000.0, 100.0));
    pdu.setEntityOrientation(createSampleEulerAngles(0.0f, 0.0f, 0.0f));
    pdu.setEntityAppearance(0);
    return pdu;
}

} // namespace Test
} // namespace DIS