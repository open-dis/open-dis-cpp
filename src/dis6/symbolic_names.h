#pragma once

#include <dis6/EntityID.h>

/**
 * Symbolic names as defined in 5.1.4
 */
namespace DIS {
const unsigned int AGG_HRT_BEAT_TIMER = 30U; //s
const unsigned int AGG_RESPONSE_DFLT  = 10U; //s
const unsigned short ALL_AGGS           = 0xFFFFU;
const unsigned short ALL_APPLIC         = 0xFFFFU;
const unsigned short ALL_ENTITIES       = 0xFFFFU;
const unsigned short ALL_OBJECTS        = 0xFFFFU;
const unsigned short ALL_SITES          = 0xFFFFU;
const unsigned int APPEAR_HRT_BEAT_TIMER  = 60U;  //se
const unsigned int COLLISION_ELASTIC_TO   = 5U;   //s
const unsigned int COLLISION_THRSH_DFLT   = 1U;   //m/s

const unsigned int DRA_ORIENT_THRSH_DFLT  = 3U; //degrees
const unsigned int DRA_POS_THRSH_DFLT     = 1U; //m
const unsigned int EE_AZ_THRSH_DFLT       = 1U; //degrees
const unsigned int EE_EL_THRSH_DFLT       = 1U; //degrees

const unsigned int EP_DIMENSION_THRSH_DFLT  = 1U; //m
const unsigned short EP_NO_SEQUENCE         = 0xFFFFU;
const unsigned int EP_POS_THRSH_DFLT        = 1U;  //m shift
const unsigned int EP_STATE_THRSH_DFLT      = 10U; //%
const unsigned int GD_HRT_BEAT_TIMER        = 15U; //min
const unsigned int HRT_BEAT_MOVE_TIMER      = 2U; //s
const float        HRT_BEAT_MPLIER          = 2.4f;
const unsigned int HRT_BEAT_TIMER           = 5U; //s
const unsigned int IFF_ATC_NAVAIDS_DFLT     = 10U; //s
const unsigned int IFF_ATC_NAVAIDS_CLAT     = 2U; //s
const unsigned int LE_HRT_BEAT_TIMER        = 30; //s
//MINEFIELD_CHANGE_DFLT between 0 and MINEFIELD_DATA_DFLT
const unsigned int MINEFIELD_DATA_DFLT      = 5U; //s
const unsigned int MINEFIELD_DATA_TIMEOUT_DLFT = 5U; //s
const unsigned int MINEFIELD_DFLT           = 5U; //s
const unsigned int MINEFIELD_RESPONSE_DFLT  = 1U; //s

const unsigned short NO_AGG    = 0U;
const unsigned short NO_APPLIC = 0U;
const unsigned short NO_ENTITY = 0U;

const unsigned int NO_FIRE_MISSION  = 0U;

const unsigned short NO_OBJECT = 0U;
const unsigned short NO_SITE   = 0U;

const unsigned int REPAR_REC_T1_DFLT = 5U; //s
const unsigned int REPAR_SUP_T1_DFLT = 12U; //s
const unsigned int REPAR_SUP_T2_DFLT = 12U; //s
const unsigned int RESUP_REC_T1_DFLT = 5U; //s
const unsigned int RESUP_REC_T2_DFLT = 55U; //s
const unsigned int RESUP_SUP_T1_DFLT = 1U; //min
const unsigned short RQST_ASSIGN_ID    = 0xFFFEU;
const unsigned int SEES_NDA_THRSH_DFLT = 2U;  //degrees in the axis of deflection
const unsigned int SEES_PS_THRSH_DFLT  = 10U; //% of the maximum value of the Power Setting
const unsigned int SEES_RPM_DELTA_THRSH_DFLT = 5U; //% of the maximum engine speed in RPM
const unsigned int SEES_STATE_UPDATE_DFLT    = 3U; //min
const unsigned int SM_REL_RETRY_CNT_DFLT     = 3U;
const unsigned int SM_REL_RETRY_DELAY_DFLT   = 2U; //s

const unsigned int TARGETS_IN_TJ_FIELD_DFLT  = 10U;
const unsigned int TI_TIMER1_DFLT            = 2U; //s
const unsigned int TI_TIMER2_DFLT            = 12U; //s
const unsigned int TR_TIMER1_DFLT            = 5U; //s
const unsigned int TR_TIMER2_DFLT            = 60U; //s
const unsigned int TRANS_ORIENT_THRSH_DFLT   = 180U; //degrees
const unsigned int TRANS_POS_THRSH_DFLT      = 500U; //m
const unsigned int UA_LOCATION_CHANGE_DELTA  = 10U; //m
const unsigned int UA_ORIENTATION_CHANGE_DELTA = 2U; //degrees
const unsigned int UA_SRPM_CHANGE_DELTA        = 5U; //% of maximum shaft speed in RPM
const unsigned int UA_SRPM_ROC_CHANGE_DELTA    = 10U; //% of maximum rate of change
const unsigned int UA_STATE_UPDATE_HRT_BEAT_TIMER = 3U; //min


/** If you want to have the EntityID constants below, you
 * need to add the constructor EntityID(unsigned short,unsigned short,unsigned short)
 * and recompile open-dis
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
}

