#include <utils/PDUBank.h>
#include <dis6/EntityStatePdu.h>
#include <dis6/FirePdu.h>
#include <dis6/DetonationPdu.h>
#include <dis6/CollisionPdu.h>
#include <dis6/ServiceRequestPdu.h>
#include <dis6/ResupplyOfferPdu.h>
#include <dis6/ResupplyReceivedPdu.h>
#include <dis6/ResupplyCancelPdu.h>
#include <dis6/RepairCompletePdu.h>
#include <dis6/RepairResponsePdu.h>
#include <dis6/CreateEntityPdu.h>
#include <dis6/RemoveEntityPdu.h>
#include <dis6/StartResumePdu.h>
#include <dis6/AcknowledgePdu.h>
#include <dis6/ActionRequestPdu.h>
#include <dis6/ActionResponsePdu.h>
#include <dis6/DataQueryPdu.h>
#include <dis6/SetDataPdu.h>
#include <dis6/EventReportPdu.h>
#include <dis6/CommentPdu.h>
#include <dis6/StopFreezePdu.h>


using namespace DIS;

Pdu* PduBank::GetStaticPDU( DIS::PDUType pdu_type )
{
   static EntityStatePdu      entityStatePdu;
   static FirePdu             firePdu;
   static DetonationPdu       detonationPdu;
   static CollisionPdu        collisionPdu;
   static ServiceRequestPdu   ServiceRequestPdu;
   static ResupplyOfferPdu    resupplyOfferPdu;
   static ResupplyReceivedPdu resupplyReceivedPdu;
   static ResupplyCancelPdu   resupplyCancelPdu;
   static RepairCompletePdu   repairCompletePdu;
   static RepairResponsePdu   repairResponsePdu;
   static CreateEntityPdu     createEntityPdu;
   static RemoveEntityPdu     removeEntityPdu;
   static StartResumePdu      startResumePdu;
   static AcknowledgePdu      acknowledgePdu;
   static ActionRequestPdu    actionRequestPdu;
   static ActionResponsePdu   actionResponsePdu;
   static DataQueryPdu        dataQueryPdu;
   static SetDataPdu          setDataPdu;
   static EventReportPdu      eventReportPdu;
   static CommentPdu          commentPdu;
   static StopFreezePdu       stopFreezePdu;

   switch(pdu_type)
   {
      case PDU_ENTITY_STATE:      return &entityStatePdu;      break;
      case PDU_FIRE:              return &firePdu;             break; 
      case PDU_DETONATION:        return &detonationPdu;       break; 
      case PDU_COLLISION:         return &collisionPdu;        break; 
      case PDU_SERVICE_REQUEST:   return &ServiceRequestPdu;   break; 
      case PDU_RESUPPLY_OFFER:    return &resupplyOfferPdu;    break; 
      case PDU_RESUPPLY_RECEIVED: return &resupplyReceivedPdu; break; 
      case PDU_RESUPPLY_CANCEL:   return &resupplyCancelPdu;   break; 
      case PDU_REPAIR_COMPLETE:   return &repairCompletePdu;   break; 
      case PDU_REPAIR_RESPONSE:   return &repairResponsePdu;   break; 
      case PDU_CREATE_ENTITY:     return &createEntityPdu;     break; 
      case PDU_REMOVE_ENTITY:     return &removeEntityPdu;     break; 
      case PDU_START_RESUME:      return &startResumePdu;      break; 
      case PDU_ACKNOWLEDGE:       return &acknowledgePdu;      break;
      case PDU_ACTION_REQUEST:    return &actionRequestPdu;    break; 
      case PDU_ACTION_RESPONSE:   return &actionResponsePdu;   break; 
      case PDU_DATA_QUERY:        return &dataQueryPdu;        break; 
      case PDU_SET_DATA:          return &setDataPdu;          break; 
      case PDU_EVENT_REPORT:      return &eventReportPdu;      break; 
      case PDU_COMMENT:           return &commentPdu;          break; 
      case PDU_STOP_FREEZE:       return &stopFreezePdu;       break;
      default:                    return nullptr;              break;
   }

   return NULL;
}

