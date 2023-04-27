#pragma once

#include "dis6/EntityID.h"

/**
 * Symbolic names as defined in 5.1.4
 */
namespace DIS {
const uint32_t AGG_HRT_BEAT_TIMER = 30U;  // s
const uint32_t AGG_RESPONSE_DFLT = 10U;   // s
const uint16_t ALL_AGGS = 0xFFFFU;
const uint16_t ALL_APPLIC = 0xFFFFU;
const uint16_t ALL_ENTITIES = 0xFFFFU;
const uint16_t ALL_OBJECTS = 0xFFFFU;
const uint16_t ALL_SITES = 0xFFFFU;
const uint32_t APPEAR_HRT_BEAT_TIMER = 60U;  // se
const uint32_t COLLISION_ELASTIC_TO = 5U;    // s
const uint32_t COLLISION_THRSH_DFLT = 1U;    // m/s

const uint32_t DRA_ORIENT_THRSH_DFLT = 3U;  // degrees
const uint32_t DRA_POS_THRSH_DFLT = 1U;     // m
const uint32_t EE_AZ_THRSH_DFLT = 1U;       // degrees
const uint32_t EE_EL_THRSH_DFLT = 1U;       // degrees

const uint32_t EP_DIMENSION_THRSH_DFLT = 1U;  // m
const uint16_t EP_NO_SEQUENCE = 0xFFFFU;
const uint32_t EP_POS_THRSH_DFLT = 1U;     // m shift
const uint32_t EP_STATE_THRSH_DFLT = 10U;  //%
const uint32_t GD_HRT_BEAT_TIMER = 15U;    // min
const uint32_t HRT_BEAT_MOVE_TIMER = 2U;   // s
const float HRT_BEAT_MPLIER = 2.4f;
const uint32_t HRT_BEAT_TIMER = 5U;         // s
const uint32_t IFF_ATC_NAVAIDS_DFLT = 10U;  // s
const uint32_t IFF_ATC_NAVAIDS_CLAT = 2U;   // s
const uint32_t LE_HRT_BEAT_TIMER = 30;      // s
// MINEFIELD_CHANGE_DFLT between 0 and MINEFIELD_DATA_DFLT
const uint32_t MINEFIELD_DATA_DFLT = 5U;          // s
const uint32_t MINEFIELD_DATA_TIMEOUT_DLFT = 5U;  // s
const uint32_t MINEFIELD_DFLT = 5U;               // s
const uint32_t MINEFIELD_RESPONSE_DFLT = 1U;      // s

const uint16_t NO_AGG = 0U;
const uint16_t NO_APPLIC = 0U;
const uint16_t NO_ENTITY = 0U;

const uint32_t NO_FIRE_MISSION = 0U;

const uint16_t NO_OBJECT = 0U;
const uint16_t NO_SITE = 0U;

const uint32_t REPAR_REC_T1_DFLT = 5U;   // s
const uint32_t REPAR_SUP_T1_DFLT = 12U;  // s
const uint32_t REPAR_SUP_T2_DFLT = 12U;  // s
const uint32_t RESUP_REC_T1_DFLT = 5U;   // s
const uint32_t RESUP_REC_T2_DFLT = 55U;  // s
const uint32_t RESUP_SUP_T1_DFLT = 1U;   // min
const uint16_t RQST_ASSIGN_ID = 0xFFFEU;
const uint32_t SEES_NDA_THRSH_DFLT =
    2U;  // degrees in the axis of deflection
const uint32_t SEES_PS_THRSH_DFLT =
    10U;  //% of the maximum value of the Power Setting
const uint32_t SEES_RPM_DELTA_THRSH_DFLT =
    5U;  //% of the maximum engine speed in RPM
const uint32_t SEES_STATE_UPDATE_DFLT = 3U;  // min
const uint32_t SM_REL_RETRY_CNT_DFLT = 3U;
const uint32_t SM_REL_RETRY_DELAY_DFLT = 2U;  // s

const uint32_t TARGETS_IN_TJ_FIELD_DFLT = 10U;
const uint32_t TI_TIMER1_DFLT = 2U;               // s
const uint32_t TI_TIMER2_DFLT = 12U;              // s
const uint32_t TR_TIMER1_DFLT = 5U;               // s
const uint32_t TR_TIMER2_DFLT = 60U;              // s
const uint32_t TRANS_ORIENT_THRSH_DFLT = 180U;    // degrees
const uint32_t TRANS_POS_THRSH_DFLT = 500U;       // m
const uint32_t UA_LOCATION_CHANGE_DELTA = 10U;    // m
const uint32_t UA_ORIENTATION_CHANGE_DELTA = 2U;  // degrees
const uint32_t UA_SRPM_CHANGE_DELTA = 5U;  //% of maximum shaft speed in RPM
const uint32_t UA_SRPM_ROC_CHANGE_DELTA =
    10U;  //% of maximum rate of change
const uint32_t UA_STATE_UPDATE_HRT_BEAT_TIMER = 3U;  // min

/** If you want to have the EntityID constants below, you
 * need to add the constructor EntityID(uint16_t,uint16_t,unsigned
 * int16_t) and recompile open-dis
 *
 */
/*
const DIS::EntityID D_SPOT_NO_ENTITY(NO_SITE, NO_APPLIC, NO_ENTITY);
const DIS::EntityID ENTITY_ID_UNKNOWN(NO_SITE, NO_APPLIC, NO_ENTITY);
const DIS::EntityID MUNITION_NOT_TRACKED(NO_SITE, NO_APPLIC, NO_ENTITY);
const DIS::EntityID NO_ENTITY_IMPACTED(NO_SITE, NO_APPLIC, NO_ENTITY);
const DIS::EntityID NO_LOCATION(NO_SITE, NO_APPLIC, NO_ENTITY);
const DIS::EntityID NO_SPECIFIC_ENTITY(NO_SITE, NO_APPLIC, NO_ENTITY);
const DIS::EntityID TARGET_ID_UNKNOWN(NO_SITE, NO_APPLIC, NO_ENTITY);
*/
}  // namespace DIS
