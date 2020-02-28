#ifndef _example_timer_h_
#define _example_timer_h_

#include <SDL.h>
#include <SDL_timer.h>

namespace Example
{
   /// grabs the time of day
   class Timer
   {
   public:
      Timer();
      void Update();

      // @return the ms ticks since SDL_Init in seconds
      double GetSeconds() const;

   private:
      Uint32 _ticks;
   };
}

#endif  // _example_timer_h_
