#include <DIS/AntennaLocation.h> 

using namespace DIS;


AntennaLocation::AntennaLocation():
   _antennaLocation(), 
   _relativeAntennaLocation()
{
}

AntennaLocation::~AntennaLocation()
{
}

Vector3Double& AntennaLocation::getAntennaLocation() 
{
    return _antennaLocation;
}

const Vector3Double& AntennaLocation::getAntennaLocation() const
{
    return _antennaLocation;
}

void AntennaLocation::setAntennaLocation(const Vector3Double &pX)
{
    _antennaLocation = pX;
}

Vector3Float& AntennaLocation::getRelativeAntennaLocation() 
{
    return _relativeAntennaLocation;
}

const Vector3Float& AntennaLocation::getRelativeAntennaLocation() const
{
    return _relativeAntennaLocation;
}

void AntennaLocation::setRelativeAntennaLocation(const Vector3Float &pX)
{
    _relativeAntennaLocation = pX;
}

void AntennaLocation::marshal(DataStream& dataStream) const
{
    _antennaLocation.marshal(dataStream);
    _relativeAntennaLocation.marshal(dataStream);
}

void AntennaLocation::unmarshal(DataStream& dataStream)
{
    _antennaLocation.unmarshal(dataStream);
    _relativeAntennaLocation.unmarshal(dataStream);
}


bool AntennaLocation::operator ==(const AntennaLocation& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_antennaLocation == rhs._antennaLocation) ) ivarsEqual = false;
     if( ! (_relativeAntennaLocation == rhs._relativeAntennaLocation) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AntennaLocation::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _antennaLocation.getMarshalledSize();  // _antennaLocation
   marshalSize = marshalSize + _relativeAntennaLocation.getMarshalledSize();  // _relativeAntennaLocation
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
