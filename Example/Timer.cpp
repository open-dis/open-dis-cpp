
#include <Example/Timer.h>
#include <iostream>

using namespace Example;

const double MILLI = 0.001;
const double MICRO = 0.000001;

void Timer::Update()
{
   nlTime( &_time_of_day );
}

NLlong Timer::GetCurrentSeconds() const
{
   return _time_of_day.useconds;
}

NLlong Timer::GetCurrentMSeconds() const
{
   return _time_of_day.useconds;
}

NLlong Timer::GetCurrentUSeconds() const
{
   return _time_of_day.useconds;
}

double Timer::GetSeconds() const
{
   //return( _time_of_day.seconds + _time_of_day.mseconds*MILLI + _time_of_day.useconds*MICRO );
   return( _time_of_day.seconds + _time_of_day.mseconds*MILLI );
   //return( _time_of_day.seconds + _time_of_day.useconds*MICRO );
}

NLtime Timer::GetData() const
{
   return _time_of_day;
}
