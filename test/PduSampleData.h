#pragma once

// All compliant PDUs from open-dis-cpp dis7
#include <dis7/AcknowledgePdu.h>
#include <dis7/ActionRequestPdu.h>
#include <dis7/ActionResponsePdu.h>
#include <dis7/CollisionPdu.h>
#include <dis7/CommentPdu.h>
#include <dis7/CreateEntityPdu.h>
#include <dis7/DataPdu.h>
#include <dis7/DataQueryPdu.h>
#include <dis7/DesignatorPdu.h>
#include <dis7/DetonationPdu.h>
#include <dis7/EntityStatePdu.h>
#include <dis7/EntityStateUpdatePdu.h>
#include <dis7/EventReportPdu.h>
#include <dis7/FirePdu.h>
#include <dis7/ReceiverPdu.h>
#include <dis7/RemoveEntityPdu.h>
#include <dis7/RepairCompletePdu.h>
#include <dis7/RepairResponsePdu.h>
#include <dis7/ResupplyOfferPdu.h>
#include <dis7/ResupplyReceivedPdu.h>
#include <dis7/ServiceRequestPdu.h>
#include <dis7/SetDataPdu.h>
#include <dis7/SignalPdu.h>
#include <dis7/StartResumePdu.h>
#include <dis7/StopFreezePdu.h>
#include <dis7/TransmitterPdu.h>

// Supporting structures
#include <dis7/EntityID.h>
#include <dis7/EntityType.h>
#include <dis7/Vector3Double.h>
#include <dis7/Vector3Float.h>
#include <dis7/EulerAngles.h>
#include <dis7/ClockTime.h>
#include <dis7/RadioType.h>
#include <dis7/EventIdentifier.h>

namespace DIS {
namespace Test {

// Helper functions for common structures
EntityID createSampleEntityID(unsigned short siteID = 1, unsigned short appID = 1, unsigned short entityID = 1);
EntityType createSampleEntityType();
Vector3Double createSampleVector3Double(double x = 0.0, double y = 0.0, double z = 0.0);
Vector3Float createSampleVector3Float(float x = 0.0f, float y = 0.0f, float z = 0.0f);
EulerAngles createSampleEulerAngles(float psi = 0.0f, float theta = 0.0f, float phi = 0.0f);
ClockTime createSampleClockTime();
RadioType createSampleRadioType();
EventIdentifier createSampleEventIdentifier();

// Sample PDU creation functions - Warfare Family (Family 2)
FirePdu createSampleFirePdu();
DetonationPdu createSampleDetonationPdu();

// Sample PDU creation functions - Logistics Family (Family 3)
ServiceRequestPdu createSampleServiceRequestPdu();
ResupplyOfferPdu createSampleResupplyOfferPdu();
ResupplyReceivedPdu createSampleResupplyReceivedPdu();
RepairCompletePdu createSampleRepairCompletePdu();
RepairResponsePdu createSampleRepairResponsePdu();

// Sample PDU creation functions - Simulation Management Family (Family 5)
StartResumePdu createSampleStartResumePdu();
StopFreezePdu createSampleStopFreezePdu();
AcknowledgePdu createSampleAcknowledgePdu();
ActionRequestPdu createSampleActionRequestPdu();
ActionResponsePdu createSampleActionResponsePdu();
DataQueryPdu createSampleDataQueryPdu();
SetDataPdu createSampleSetDataPdu();
DataPdu createSampleDataPdu();
EventReportPdu createSampleEventReportPdu();
CommentPdu createSampleCommentPdu();
CreateEntityPdu createSampleCreateEntityPdu();
RemoveEntityPdu createSampleRemoveEntityPdu();

// Sample PDU creation functions - Distributed Emission Regeneration Family (Family 6)
DesignatorPdu createSampleDesignatorPdu();

// Sample PDU creation functions - Radio Communications Family (Family 4)
TransmitterPdu createSampleTransmitterPdu();
SignalPdu createSampleSignalPdu();
ReceiverPdu createSampleReceiverPdu();

// Sample PDU creation functions - Entity Information/Interaction Family (Family 1)
EntityStatePdu createSampleEntityStatePdu();
CollisionPdu createSampleCollisionPdu();
EntityStateUpdatePdu createSampleEntityStateUpdatePdu();

} // namespace Test
} // namespace DIS