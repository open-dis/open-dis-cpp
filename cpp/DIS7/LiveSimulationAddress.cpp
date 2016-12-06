#include <DIS/LiveSimulationAddress.h> 

using namespace DIS;


LiveSimulationAddress::LiveSimulationAddress():
   _liveSiteNumber(0), 
   _liveApplicationNumber(0)
{
}

LiveSimulationAddress::~LiveSimulationAddress()
{
}

unsigned char LiveSimulationAddress::getLiveSiteNumber() const
{
    return _liveSiteNumber;
}

void LiveSimulationAddress::setLiveSiteNumber(unsigned char pX)
{
    _liveSiteNumber = pX;
}

unsigned short LiveSimulationAddress::getLiveApplicationNumber() const
{
    return _liveApplicationNumber;
}

void LiveSimulationAddress::setLiveApplicationNumber(unsigned short pX)
{
    _liveApplicationNumber = pX;
}

void LiveSimulationAddress::marshal(DataStream& dataStream) const
{
    dataStream << _liveSiteNumber;
    dataStream << _liveApplicationNumber;
}

void LiveSimulationAddress::unmarshal(DataStream& dataStream)
{
    dataStream >> _liveSiteNumber;
    dataStream >> _liveApplicationNumber;
}


bool LiveSimulationAddress::operator ==(const LiveSimulationAddress& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_liveSiteNumber == rhs._liveSiteNumber) ) ivarsEqual = false;
     if( ! (_liveApplicationNumber == rhs._liveApplicationNumber) ) ivarsEqual = false;

    return ivarsEqual;
 }

int LiveSimulationAddress::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _liveSiteNumber
   marshalSize = marshalSize + 2;  // _liveApplicationNumber
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
