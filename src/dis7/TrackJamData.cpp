#include <dis7/TrackJamData.h>

using namespace DIS;


TrackJamData::TrackJamData():
   _entityID(), 
   _emitterNumber(0), 
   _beamNumber(0)
{
}

TrackJamData::~TrackJamData()
{
}

EntityID& TrackJamData::getEntityID() 
{
    return _entityID;
}

const EntityID& TrackJamData::getEntityID() const
{
    return _entityID;
}

void TrackJamData::setEntityID(const EntityID &pX)
{
    _entityID = pX;
}

uint8_t TrackJamData::getEmitterNumber() const
{
    return _emitterNumber;
}

void TrackJamData::setEmitterNumber(uint8_t pX)
{
    _emitterNumber = pX;
}

uint8_t TrackJamData::getBeamNumber() const
{
    return _beamNumber;
}

void TrackJamData::setBeamNumber(uint8_t pX)
{
    _beamNumber = pX;
}

void TrackJamData::marshal(DataStream& dataStream) const
{
    _entityID.marshal(dataStream);
    dataStream << _emitterNumber;
    dataStream << _beamNumber;
}

void TrackJamData::unmarshal(DataStream& dataStream)
{
    _entityID.unmarshal(dataStream);
    dataStream >> _emitterNumber;
    dataStream >> _beamNumber;
}


bool TrackJamData::operator ==(const TrackJamData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_entityID == rhs._entityID) ) ivarsEqual = false;
     if( ! (_emitterNumber == rhs._emitterNumber) ) ivarsEqual = false;
     if( ! (_beamNumber == rhs._beamNumber) ) ivarsEqual = false;

    return ivarsEqual;
 }

int TrackJamData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _entityID.getMarshalledSize();  // _entityID
   marshalSize = marshalSize + 1;  // _emitterNumber
   marshalSize = marshalSize + 1;  // _beamNumber
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
