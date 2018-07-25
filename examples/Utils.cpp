#include "Utils.h"

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <DIS/Orientation.h>
#include <DIS/Vector3Float.h>
#include <DIS/Vector3Double.h>

///\todo make cross platform solution
void Example::sleep(unsigned int ms)
{
#ifdef WIN32
   Sleep( ms );
#else
   usleep( ms*1000 );
#endif
}

using namespace Example;

HeloFlightDynamics::HeloFlightDynamics(float angular_vel,
                                       float radius,
                                       const Point3d& ip,
                                       float init_angle)
   : _angular_velocity(angular_vel)
   , _radius(radius)
   , _rotation(init_angle)
   , _ip(ip)
{
}

void HeloFlightDynamics::operator ()(double dt)
{
   _rotation += _angular_velocity * dt;

   float cos_rot = cos(_rotation);
   float sin_rot = sin(_rotation);
   float r_cos_rot = _radius * cos_rot;
   float r_sin_rot = _radius * sin_rot;

   // set the position
   position.setX( _ip.x + r_cos_rot );
   position.setY( _ip.y );                    // hold this axis constant
   position.setZ( _ip.z + r_sin_rot );

   // set the velocity vector
   float vx = -_angular_velocity * r_sin_rot;
   velocity.setX( vx );
   velocity.setY( 0.f );
   velocity.setZ( _angular_velocity * r_cos_rot );

   // set the orientation
   orientation.setPsi( 0.f);
   orientation.setTheta( 0.f);
   orientation.setPhi( 30.f );
   //if( vx < 0.f )
   //{
   //   orientation.setPhi( M_PI - acos(-vx) );
   //}
   //else
   //{
   //   orientation.setPhi( acos(vx) );
   //}
}


TankDynamics::TankDynamics(double tv, double ev)
   : _angle_primary_turret(0.f)
   , _velocity_turret(tv)
   , _angle_primary_gun(0.f)
   , _angle_secondary_gun(0.f)
   , _primary_gun_range(0.f, Example::DegreesToRadians(45.f) )
   , _secondary_gun_range(Example::DegreesToRadians(270.f), Example::DegreesToRadians(360.f) )
   , _control_elevation( 0. )
   , _control_elevation_velocity(ev)
{
}

void TankDynamics::Update(double dt)
{
   _angle_primary_turret += _velocity_turret * (float)dt;

   // update the gun elevation based on the sin function.
   // the valid range of angles is defined in the normalized range,
   // first calculate the normalized value.
   _control_elevation += _control_elevation_velocity * dt;
   float k = 0.5 * (sin(_control_elevation) + 1.f);

   _angle_primary_gun = _primary_gun_range.Interpolate(k);
   _angle_secondary_gun = _secondary_gun_range.Interpolate(k);
}

NormalizedRange::NormalizedRange(float l, float h)
   : _low_end( l )
   , _high_end( h )
{
}

float NormalizedRange::Interpolate(float k)
{
   return Example::Lerp(_low_end, _high_end, k);
}

/// @param interval the time between alerts
TimedAlert::TimedAlert(double interval)
   : _interval(interval)
   , _time_elapsed( 0.0 )
{
}

/// Update the internal time
bool TimedAlert::operator()(double dt)
{
   _time_elapsed += dt;

   if (_time_elapsed > _interval)
   {
      _time_elapsed = 0.0;
      return true;
   }

   return false;
}
