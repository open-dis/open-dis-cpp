
#include "Timer.h"
#include "Logging.h"

#include <iostream>
#include <sstream>

#include <SDL.h>
#include <SDL_timer.h>

using namespace Example;

const double MILLI = 0.001;
const double MICRO = 0.000001;

Timer::Timer() {
   // Added to allow Timer to be a stand alone class
   // Supposedly SDL_Init ignores repeated calls
   // source : https://discourse.libsdl.org/t/behaviour-of-sdl-init-when-called-more-than-once/6156
   if (SDL_Init(0) != 0) {
      std::ostringstream strm;
      strm << "SDL_Init failed due to error: " << SDL_GetError();
      LOG_ERROR(strm.str());
   }

}

void Timer::Update()
{
   _ticks = SDL_GetTicks();
}


double Timer::GetSeconds() const
{
   return (_ticks * MILLI);
}
