#include "PduUtils.h"

#include <DIS/EntityStatePdu.h>
#include <DIS/DetonationPdu.h>
#include <DIS/CollisionPdu.h>

#include <DIS/Conversion.h>

void TestDIS::InitPDU(DIS::DetonationPdu& pdu)
{
   // some temp variables to be used as content for the detonation
   DIS::EntityID friendly, enemy;
   InitEntityID( friendly );
   InitEntityID( enemy );

   DIS::EntityType vehicle;
   InitEntityType( vehicle );

   DIS::BurstDescriptor burst;
   burst.setFuse( 4 );
   burst.setMunition( vehicle );
   burst.setQuantity( 3 );
   burst.setRate( 4 );
   burst.setWarhead( 2 );

   DIS::EventID eventid;
   InitEventID( eventid );

   DIS::Vector3Double pos;
   pos.setX( 3. );
   pos.setY( 4. );
   pos.setZ( 5. );

   DIS::Vector3Float vel;
   vel.setX( 44.f );
   vel.setY( 44.f );
   vel.setZ( 44.f );

   std::vector<DIS::ArticulationParameter> art_params;
   TestDIS::InitArticulationParams( art_params );

   //pdu.setArticulationParameters( art_params );
   pdu.setBurstDescriptor( burst );
   pdu.setDetonationResult( 2 );
   pdu.setEventID( eventid );
   pdu.setExerciseID( 2 );
   pdu.setFiringEntityID( friendly );
   pdu.setLocationInWorldCoordinates( pos );
   pdu.setMunitionID( friendly );
   pdu.setTargetEntityID( enemy );
   pdu.setTimestamp( 2 );
   pdu.setVelocity( vel );
}

void TestDIS::InitPDU(DIS::EntityStatePdu& pdu)
{
   DIS::EntityID eid;
   InitEntityID( eid );

   DIS::EntityType etype;
   InitEntityType( etype );

   std::vector<DIS::ArticulationParameter> art_params;
   InitArticulationParams( art_params );

   DIS::DeadReckoningParameter drparam;
   InitDeadReckoningParameters( drparam );

   pdu.setEntityID( eid );
   pdu.setEntityType( etype );
   pdu.setEntityAppearance( 2 );
   pdu.setAlternativeEntityType( etype );
   //pdu.setArticulationParameters( art_params );
   pdu.setCapabilities( 3 );
   pdu.setDeadReckoningParameters( drparam );
}

void TestDIS::InitPDU(DIS::CollisionPdu& pdu)
{
   DIS::EntityID eid;
   InitEntityID( eid );

   DIS::EventID evid;
   TestDIS::InitEventID( evid );

   DIS::Vector3Float vec3f;
   TestDIS::InitVec3f( vec3f );

   pdu.setIssuingEntityID( eid );
   pdu.setCollidingEntityID( eid );
   pdu.setEventID( evid );
   pdu.setCollisionType( 3 );
   pdu.setPad( 2 );
   pdu.setVelocity( vec3f );
   pdu.setMass( 3.f );
   pdu.setLocation( vec3f );
}

void TestDIS::InitVec3f(DIS::Vector3Float& vec3f)
{
   vec3f.setX( 33.f );
   vec3f.setY( 33.f );
   vec3f.setZ( 33.f );
}

void TestDIS::InitEventID(DIS::EventID& eventid)
{
   eventid.setApplication( 2 );
   eventid.setEventNumber( 2 );
   eventid.setSite( 3 );
}

void TestDIS::InitEntityID(DIS::EntityID& eid)
{
   eid.setEntity( 2 );
   eid.setApplication( 2 );
   eid.setSite( 2 );
}

void TestDIS::InitEntityType(DIS::EntityType& etype)
{
   etype.setCategory( 2 );
   etype.setCountry( 222 );
   etype.setDomain( 2 );
   etype.setEntityKind( 2 );
   etype.setExtra( 2 );
   etype.setSpecific( 2 );
   etype.setSubcategory( 2 );
}

void TestDIS::InitArticulationParams(std::vector<DIS::ArticulationParameter>& params)
{
   DIS::ArticulationParameter turret_azimuth;
   turret_azimuth.setChangeIndicator( 2 );
   turret_azimuth.setParameterType( DIS::Convert::MakeArticulationParameterType( 4096, 11 ) );
   turret_azimuth.setParameterTypeDesignator( 2 );
   turret_azimuth.setParameterValue( 3.14 );
   turret_azimuth.setPartAttachedTo( 0 );

   params.push_back( turret_azimuth );
}

void TestDIS::InitDeadReckoningParameters(DIS::DeadReckoningParameter& param)
{
   DIS::Vector3Float angvel;
   angvel.setX( 22.f );
   angvel.setY( 22.f );
   angvel.setZ( 22.f );

   DIS::Vector3Float linacc;
   linacc.setX( 33.f );
   linacc.setY( 33.f );
   linacc.setZ( 33.f );

   param.setDeadReckoningAlgorithm( 2 );
   param.setEntityAngularVelocity( angvel );
   param.setEntityLinearAcceleration( linacc );
   //param.setOtherParameters( ??? );
}
