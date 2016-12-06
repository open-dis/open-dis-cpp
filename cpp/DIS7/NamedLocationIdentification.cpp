#include <DIS/NamedLocationIdentification.h> 

using namespace DIS;


NamedLocationIdentification::NamedLocationIdentification():
   _stationName(0), 
   _stationNumber(0)
{
}

NamedLocationIdentification::~NamedLocationIdentification()
{
}

unsigned short NamedLocationIdentification::getStationName() const
{
    return _stationName;
}

void NamedLocationIdentification::setStationName(unsigned short pX)
{
    _stationName = pX;
}

unsigned short NamedLocationIdentification::getStationNumber() const
{
    return _stationNumber;
}

void NamedLocationIdentification::setStationNumber(unsigned short pX)
{
    _stationNumber = pX;
}

void NamedLocationIdentification::marshal(DataStream& dataStream) const
{
    dataStream << _stationName;
    dataStream << _stationNumber;
}

void NamedLocationIdentification::unmarshal(DataStream& dataStream)
{
    dataStream >> _stationName;
    dataStream >> _stationNumber;
}


bool NamedLocationIdentification::operator ==(const NamedLocationIdentification& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_stationName == rhs._stationName) ) ivarsEqual = false;
     if( ! (_stationNumber == rhs._stationNumber) ) ivarsEqual = false;

    return ivarsEqual;
 }

int NamedLocationIdentification::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _stationName
   marshalSize = marshalSize + 2;  // _stationNumber
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
