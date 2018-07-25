#ifndef _example_utils_h_
#define _example_utils_h_

#include <string>
#include <sstream>

#define _USE_MATH_DEFINES
#include <cmath>

#include <DIS/Vector3Double.h>
#include <DIS/Vector3Float.h>
#include <DIS/Orientation.h>

namespace Example
{
   const double PI_UNDER_180 = 180.0 / M_PI;
   const double PI_OVER_180 = M_PI / 180.0;

   struct Point3d
   {
      float x;
      float y;
      float z;
   };


   /// alerts the user when the incremented time passes a threshhold interval
   struct TimedAlert
   {
   public:
      /// @param interval the time between alerts
      TimedAlert(double interval);

      /// Update the internal time
      bool operator()(double dt);

   private:
      TimedAlert();  ///< not implemented by design

      double _interval;
      double _time_elapsed;
   };

   /// hovers in a circle
   struct HeloFlightDynamics
   {
      /// pass the initialization parameters to affect the behavior or the model around an IP.
      /// @param angular_vel the velocity for sweeping the circle, in radians / second.
      HeloFlightDynamics(float angular_vel,
                         float radius,
                         const Point3d& ip,
                         float init_angle);

      /// @param dt the time change
      void operator ()(double dt);

      DIS::Vector3Double position;
      DIS::Orientation orientation;
      DIS::Vector3Float velocity;

   private:
      HeloFlightDynamics();  ///< not implemented by design

      float _angular_velocity;
      float _radius;
      float _rotation;
      Point3d _ip;
   };

   /// utility to hold state about a range
   /// and get an interpolated value from a normalized value.
   struct NormalizedRange
   {
      NormalizedRange(float low, float high);

      float Interpolate(float k);

   private:
      NormalizedRange();  ///< not implemented by design

      float _low_end;
      float _high_end;
   };

   class TankDynamics
   {
   public:
      TankDynamics(double turret_velocity, double elevation_controller_rate);

      void Update(double dt);

   private:
      TankDynamics();  ///< not implemented by design

   public:
      float _angle_primary_turret;
      double _velocity_turret;

      float _angle_primary_gun;
      float _angle_secondary_gun;

      NormalizedRange _primary_gun_range;  ///< stores the limited movement values
      NormalizedRange _secondary_gun_range;  ///< stores the limited movement values

   private:
      float _control_elevation;
      double _control_elevation_velocity;
   };

   /// converts degrees to radians
   /// @param radians
   template<typename Real>
   Real DegreesToRadians(Real degrees)
   {
      return( degrees * PI_OVER_180 );
   }

   /// converts radians to degrees
   /// @return degrees
   template<typename Real>
   Real RadiansToDegrees(Real radians)
   {
      return( radians * PI_UNDER_180 );
   }

   /// calculate a point between 2 others.
   /// @param p a point.
   /// @param q another point.
   /// @param k the multiplier defining the distance between the points
   /// @return the linearly interpolated point.
   template<typename Real>
   Real Lerp(Real p, Real q, Real k)
   {
      return k*(q-p) + p;
   }

   /// @param ms The number of milliseconds to wait.
   void sleep(unsigned int ms);

   template<typename T>
   T ToType(const std::string& data)
   {
      std::stringstream ss;
      ss << data;
      T t;
      ss >> t;
      return t;
   }
}

#endif  // _example_utils_h_
