#ifndef _dtdis_pdu_type_h_
#define _dtdis_pdu_type_h_

namespace DIS
{
   enum PDUType
   {
      PDU_OTHER = 0,
      PDU_ENTITY_STATE = 1,
      PDU_FIRE = 2,
      PDU_DETONATION = 3,
      PDU_COLLISION = 4,
      PDU_SERVICE_REQUEST = 5,
      PDU_RESUPPLY_OFFER = 6,
      PDU_RESUPPLY_RECEIVED = 7,
      PDU_RESUPPLY_CANCEL = 8,
      PDU_REPAIR_COMPLETE = 9,
      PDU_REPAIR_RESPONSE = 10,
      PDU_CREATE_ENTITY = 11,
      PDU_REMOVE_ENTITY = 12,
      PDU_START_RESUME = 13,
      PDU_STOP_FREEZE = 14,
      PDU_ACKNOWLEDGE = 15,
      PDU_ACTION_REQUEST = 16,
      PDU_ACTION_RESPONSE = 17,
      PDU_DATA_QUERY = 18,
      PDU_SET_DATA = 19,
      // PDU_WTF = 20
      PDU_EVENT_REPORT = 21,
      PDU_COMMENT = 22,
   };
}

#endif // _dtdis_pdu_type_h_
