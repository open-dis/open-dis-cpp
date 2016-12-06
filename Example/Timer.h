#ifndef _example_timer_h_
#define _example_timer_h_

#include <nl.h>          // for member

namespace Example
{
   /// grabs the time of day
   class Timer
   {
   public:
      void Update();

      NLlong GetCurrentSeconds() const;
      NLlong GetCurrentMSeconds() const;
      NLlong GetCurrentUSeconds() const;

      // @return the time of day in seconds
      double GetSeconds() const;

      NLtime GetData() const;

   private:
      NLtime _time_of_day;
   };
}

#endif  // _example_timer_h_
