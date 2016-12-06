
// specific for the example
#include <Example/Connection.h>
#include <Example/Utils.h>
#include <Example/Timer.h>

// the DIS library usage
#include <DIS/EntityStatePdu.h>
#include <DIS/DetonationPdu.h>
#include <DIS/DataStream.h>
#include <DIS/Vector3Double.h>
#include <DIS/BurstDescriptor.h>

#include <DIS/Conversion.h>

#include <iostream>

namespace Example
{
   enum T72_Articulation_Index
   {
      INDEX_TURRET_AZIMUTH = 0,
      INDEX_TURRET_AZIMUTH_RATE = 1,
      INDEX_GUN_ELEVATION = 2,
      INDEX_GUN_2_ELEVATION = 3
   };

   namespace Articulation
   {
      enum Motion
      {
         AZIMUTH = 11,
         AZIMUTH_RATE,
         ELEVATION
      };

      enum Part
      {
         PRIMARY_TURRET = 4096,
         PRIMARY_GUN = 4416,
         SECONDARY_GUN = 6016
      };

      enum Designator
      {
         ARTICULATED = 0,
         ATTACHED = 1
      };
   }

   enum DeadReckoningModel
   {
      STATIC = 1,
      DRM_FPW,
      DRM_RPW,
      DRM_RVW,
      DRM_FVW,
      DRM_FPB,
      DRM_RPB,
      DRM_RVB,
      DRM_FVB,
   };
}


void init_entities(DIS::EntityStatePdu& friendly0,
                   DIS::EntityStatePdu& friendly1,
                   DIS::EntityStatePdu& enemy)
{
   /// basic pdu info

   {
      enemy.setProtocolVersion(6);
      enemy.setExerciseID(0);
      //enemy.setPduType(1);
      //enemy.setProtocolFamily(1);

      friendly0.setProtocolVersion(6);
      friendly0.setExerciseID(0);
      //friendly0.setPduType(1);
      //friendly0.setProtocolFamily(1);
      //friendly0.setArticulationParameterCount(0);

      friendly1.setProtocolVersion(6);
      friendly1.setExerciseID(0);
      //friendly1.setPduType(1);
      //friendly1.setProtocolFamily(1);
      //friendly1.setArticulationParameterCount(0);
   }

   /// entity id data
   {
      // the enemies
      DIS::EntityID enemy_entity_id;
      enemy_entity_id.setSite( 0 );
      enemy_entity_id.setApplication( 1 );
      enemy_entity_id.setEntity( 1 );

      enemy.setEntityID( enemy_entity_id );

      // the friendlies
      DIS::EntityID friendly_entity_id[2];
      friendly_entity_id[0].setSite( 0 );
      friendly_entity_id[0].setApplication( 1 );
      friendly_entity_id[0].setEntity( 2 );

      friendly0.setEntityID( friendly_entity_id[0] );

      friendly_entity_id[1].setSite( 0 );
      friendly_entity_id[1].setApplication( 1 );
      friendly_entity_id[1].setEntity( 3 );

      friendly1.setEntityID( friendly_entity_id[1] );
   }

   // entity type data
   {
      // a T-72M
      DIS::EntityType t72m;
      t72m.setCategory( 1 );
      t72m.setCountry( 222 );
      t72m.setDomain( 1 );
      t72m.setEntityKind( 1 );
      t72m.setExtra( 0 );
      t72m.setSpecific( 2 );
      t72m.setSubcategory( 2 );

      enemy.setEntityType( t72m );

      // an AH-1W
      DIS::EntityType ah_1w;
      ah_1w.setCategory( 20 );
      ah_1w.setCountry( 225 );
      ah_1w.setDomain( 2 );
      ah_1w.setEntityKind( 1 );
      ah_1w.setExtra( 0 );
      ah_1w.setSpecific( 10 );
      ah_1w.setSubcategory( 2 );

      friendly0.setEntityType( ah_1w );
      friendly1.setEntityType( ah_1w );
   }

   // dead reckoning
   {
      DIS::DeadReckoningParameter drp;
      drp.setDeadReckoningAlgorithm( Example::DRM_FVW );

      friendly0.setDeadReckoningParameters( drp );
      friendly1.setDeadReckoningParameters( drp );
      enemy.setDeadReckoningParameters( drp );
   }

   // articulation
   {
      DIS::ArticulationParameter turret_azimuth;
      turret_azimuth.setParameterType( DIS::Convert::MakeArticulationParameterType(Example::Articulation::PRIMARY_TURRET,Example::Articulation::AZIMUTH) );
      turret_azimuth.setPartAttachedTo( 0 );            // 0 = connected directly to the vehicle
      turret_azimuth.setParameterTypeDesignator( Example::Articulation::ARTICULATED );

      DIS::ArticulationParameter turret_azimuth_rate;
      turret_azimuth_rate.setParameterType( DIS::Convert::MakeArticulationParameterType(Example::Articulation::PRIMARY_TURRET,Example::Articulation::AZIMUTH_RATE) );
      turret_azimuth_rate.setPartAttachedTo( 0 );       // 0 = connected directly to the vehicle
      turret_azimuth_rate.setParameterTypeDesignator( Example::Articulation::ARTICULATED );

      DIS::ArticulationParameter turret_gun_elevation;
      turret_gun_elevation.setParameterType( DIS::Convert::MakeArticulationParameterType(Example::Articulation::PRIMARY_GUN,Example::Articulation::ELEVATION) );
      turret_gun_elevation.setPartAttachedTo( 1 );            // 1 = connected to the turret
      turret_gun_elevation.setParameterTypeDesignator( Example::Articulation::ARTICULATED );

      DIS::ArticulationParameter gun2_elevation;
      gun2_elevation.setParameterType( DIS::Convert::MakeArticulationParameterType(Example::Articulation::SECONDARY_GUN,Example::Articulation::ELEVATION) );
      gun2_elevation.setPartAttachedTo( 1 );            // 1 = connected to the turret
      gun2_elevation.setParameterTypeDesignator( Example::Articulation::ARTICULATED );

      std::vector<DIS::ArticulationParameter>& params = enemy.getArticulationParameters();
      params.clear();
      params.resize(4);  // make default number of parameters
      params[Example::INDEX_TURRET_AZIMUTH] = turret_azimuth;
      params[Example::INDEX_TURRET_AZIMUTH_RATE] = turret_azimuth_rate;
      params[Example::INDEX_GUN_ELEVATION] = turret_gun_elevation;
      params[Example::INDEX_GUN_2_ELEVATION] = gun2_elevation;
   }

   friendly0.setLength( friendly0.getMarshalledSize());
   friendly1.setLength( friendly1.getMarshalledSize());
   enemy.setLength(enemy.getMarshalledSize());
}


void init_effects(DIS::DetonationPdu &detonation, const DIS::EntityID& firing, const DIS::EntityID& target)
{
   /// basic pdu info
   {
      detonation.setProtocolVersion( 1 );  // not sure what is 1
      detonation.setExerciseID( 1 );
   }

   /// entity id data
   {           
      DIS::EntityID detonation_entity_id;
      detonation_entity_id.setSite( 0 );
      detonation_entity_id.setApplication( 1 );
      detonation_entity_id.setEntity( 4 );

      detonation.setMunitionID( detonation_entity_id );
   }

   /// event id data
   { 
      //Event ID.
      //   This field shall contain the same data as in the Event ID ﬁeld of the Fire PDU that communicated
      //   the launch of the munition. If the detonation is not preceded by a corresponding ﬁre event,
      //   then the Event Number ﬁeld of the Event Identiﬁer record shall be zero (e.g., land mines detonation).
      //   This ﬁeld shall be represented by an Event Identiﬁer record (see 5.2.18).

      // 0200 Point Detonation (PD)
      DIS::EventID detonation_event_id;
      detonation_event_id.setSite( 0 );
      detonation_event_id.setApplication( 1 );
      detonation_event_id.setEventNumber( 0 );
      detonation.setEventID( detonation_event_id );
   }

   // warfare data
   {
      detonation.setFiringEntityID( firing );
      detonation.setTargetEntityID( target );
   }

   /// detonation specific data
   {  ///\todo update this position in the main loop

      // dead reckoning info
      DIS::Vector3Float detonation_velocity;
      detonation_velocity.setX( 0.f );
      detonation_velocity.setY( 0.f );
      detonation_velocity.setZ( 0.f );

      DIS::Vector3Double worldPosition;
      worldPosition.setX( 50.0 );
      worldPosition.setY( 50.0 );
      worldPosition.setZ( 50.0 );

      detonation.setLocationInWorldCoordinates(worldPosition);

      DIS::BurstDescriptor burstDescriptor;
      //burstDescriptor.setMunition( 0 );      ///\todo set this with the 64 bit type.
      burstDescriptor.setWarhead( 1000 );    // 1000 High Explosive (HE)
      burstDescriptor.setFuse( 200 );        // 0200 Point Detonation (PD)
      burstDescriptor.setQuantity( 1 );
      burstDescriptor.setRate( 1 );

      detonation.setDetonationResult( 5 ); // 5 Detonation
   }

   detonation.setLength( detonation.getMarshalledSize() );
}

void UpdateHelo(DIS::EntityStatePdu& helo, Example::HeloFlightDynamics& dynamics, double dt, unsigned int frame_stamp)
{
   dynamics( dt );
   helo.setEntityLocation( dynamics.position );
   helo.setEntityOrientation( dynamics.orientation );
   helo.setEntityLinearVelocity( dynamics.velocity );
   helo.setTimestamp( frame_stamp );
}

void UpdateTank(DIS::EntityStatePdu& tank, Example::TankDynamics& dynamics, double dt, unsigned int frame_stamp)
{
   dynamics.Update( dt );

   // articulation
   std::vector<DIS::ArticulationParameter> &params = tank.getArticulationParameters();

   DIS::ArticulationParameter& turret_azimuth = params[Example::INDEX_TURRET_AZIMUTH];
   turret_azimuth.setParameterValue( dynamics._angle_primary_turret );
   turret_azimuth.setChangeIndicator( frame_stamp );  // constantly changing

   DIS::ArticulationParameter& turret_azimuth_rate = params[Example::INDEX_TURRET_AZIMUTH_RATE];
   turret_azimuth_rate.setChangeIndicator( 0 ); // no change
   turret_azimuth_rate.setParameterValue( dynamics._velocity_turret );

   DIS::ArticulationParameter& gun_elevation = params[Example::INDEX_GUN_ELEVATION];
   gun_elevation.setChangeIndicator( 0 );  // no change
   gun_elevation.setParameterValue( dynamics._angle_primary_gun );

   DIS::ArticulationParameter& gun2_elevation = params[Example::INDEX_GUN_2_ELEVATION];
   gun2_elevation.setChangeIndicator( frame_stamp );  // no change
   gun2_elevation.setParameterValue( dynamics._angle_secondary_gun );
}

int main(int argc, char* argv[])
{
   unsigned int port(62040);
   std::string ip("239.1.2.3");
   if( argc > 2 )
   {
      port = Example::ToType<unsigned int>( argv[1] );
      ip = argv[2];
   }

   /// the basic pieces for sending data
   Example::Connection multicast;
   multicast.Connect( port , ip );
   DIS::DataStream buffer( DIS::BIG );

   DIS::EntityStatePdu enemy;
   DIS::EntityStatePdu friendly[2];   
   init_entities( friendly[0], friendly[1], enemy );

   DIS::DetonationPdu tank_round;
   init_effects( tank_round, friendly[0].getEntityID(), enemy.getEntityID());

   // -- initialize the flight controllers -- //
   // the holding location of the friendly aircraft
   Example::Point3d IP;
   IP.x = 50.f;
   IP.y = 50.f; // altitude?
   IP.z = 50.f;
   Example::HeloFlightDynamics helo_flight_dynamics_0(Example::DegreesToRadians(20.f),20., IP, 0.);
   IP.x = 75.f;
   IP.y = 75.f; // altitude?
   IP.z = 75.f;
   Example::HeloFlightDynamics helo_flight_dynamics_1(Example::DegreesToRadians(40.f),40., IP, 0.);

   Example::TankDynamics tank_dynamics( Example::DegreesToRadians(10.f), Example::DegreesToRadians(20.f) );
   // Initialize the timer
   Example::Timer timer;
   timer.Update();

   // define the content to be sent of the network
   double sim_time = 0;
   double dt = 0;  
   unsigned int frame_stamp=0;

   Example::TimedAlert isDetonationReady(10.0);   // alert us at 10.0 second intervals
   Example::TimedAlert isTimeToPrintStatistics(5.0);   // alert us at 10.0 second intervals

   double last_time = timer.GetSeconds();  

   // the simulation loop
   ///\todo find an exit condition so we don't need to explicitly kill the app
   while( true )
   {
      timer.Update();
      double current_time = timer.GetSeconds();
      dt = current_time - last_time;
      sim_time += dt;
      last_time = current_time;

      // use the dynamics to update the entities' state.
      UpdateHelo( friendly[0], helo_flight_dynamics_0, dt, frame_stamp );
      UpdateHelo( friendly[1], helo_flight_dynamics_1, dt, frame_stamp );
      UpdateTank( enemy, tank_dynamics, dt, frame_stamp );

      // serialize for network send
      friendly[0].marshal( buffer );
      friendly[1].marshal( buffer );
      enemy.marshal( buffer );

      // Are we ready for le boom boom?
      if( isDetonationReady(dt) )
      {
         tank_round.marshal( buffer );
         // some feedback
         std::cout << "detonation!" << std::endl;
      }

      // some feedback
      if( isTimeToPrintStatistics(dt) )
      {
         std::cout << "frame:" << frame_stamp
            << "\t dt:" << dt
            //<< " | x:" << temp_position.getX()
            //<< " | y:" << temp_position.getY()
            << std::endl;
      }

      // send it over the line
      multicast.Send( &buffer[0] , buffer.size() );

      // clear for next frame
      buffer.clear();

      // increase for next frame
      frame_stamp++;

      Example::sleep( 10000 );
   }

   multicast.Disconnect();
   return 0;
}
