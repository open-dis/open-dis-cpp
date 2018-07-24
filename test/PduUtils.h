/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dis_pdu_utils_h_
#define _dis_pdu_utils_h_

#include <vector>
#include <DIS/ArticulationParameter.h>
#include <DIS/DeadReckoningParameter.h>

namespace DIS
{
   class DetonationPdu;
   class EntityStatePdu;
   class EntityID;
   class EntityType;
   class CollisionPdu;
   class EventID;
   class Vector3Float;
}

namespace TestDIS
{
   void InitPDU(DIS::DetonationPdu& pdu);
   void InitPDU(DIS::EntityStatePdu& pdu);
   void InitPDU(DIS::CollisionPdu& pdu);

   void InitVec3f(DIS::Vector3Float& vec3f);
   void InitEventID(DIS::EventID& eid);
   void InitEntityID(DIS::EntityID& eid);
   void InitEntityType(DIS::EntityType& etype);
   void InitArticulationParams(std::vector<DIS::ArticulationParameter>& params);
   void InitDeadReckoningParameters(DIS::DeadReckoningParameter& param);
}

#endif // _dis_pdu_utils_h_
