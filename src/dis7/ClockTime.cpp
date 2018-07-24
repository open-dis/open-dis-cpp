#include <DIS/ClockTime.h> 

using namespace DIS;


ClockTime::ClockTime():
   _hour(0), 
   _timePastHour(0)
{
}

ClockTime::~ClockTime()
{
}

unsigned int ClockTime::getHour() const
{
    return _hour;
}

void ClockTime::setHour(unsigned int pX)
{
    _hour = pX;
}

unsigned int ClockTime::getTimePastHour() const
{
    return _timePastHour;
}

void ClockTime::setTimePastHour(unsigned int pX)
{
    _timePastHour = pX;
}

void ClockTime::marshal(DataStream& dataStream) const
{
    dataStream << _hour;
    dataStream << _timePastHour;
}

void ClockTime::unmarshal(DataStream& dataStream)
{
    dataStream >> _hour;
    dataStream >> _timePastHour;
}


bool ClockTime::operator ==(const ClockTime& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_hour == rhs._hour) ) ivarsEqual = false;
     if( ! (_timePastHour == rhs._timePastHour) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ClockTime::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _hour
   marshalSize = marshalSize + 4;  // _timePastHour
    return marshalSize;
}

// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
// 
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
