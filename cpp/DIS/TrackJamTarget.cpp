#include <DIS/TrackJamTarget.h> 

using namespace DIS;


TrackJamTarget::TrackJamTarget():
   _trackJam(), 
   _emitterID(0), 
   _beamID(0)
{
}

TrackJamTarget::~TrackJamTarget()
{
}

EntityID& TrackJamTarget::getTrackJam() 
{
    return _trackJam;
}

const EntityID& TrackJamTarget::getTrackJam() const
{
    return _trackJam;
}

void TrackJamTarget::setTrackJam(const EntityID &pX)
{
    _trackJam = pX;
}

unsigned char TrackJamTarget::getEmitterID() const
{
    return _emitterID;
}

void TrackJamTarget::setEmitterID(unsigned char pX)
{
    _emitterID = pX;
}

unsigned char TrackJamTarget::getBeamID() const
{
    return _beamID;
}

void TrackJamTarget::setBeamID(unsigned char pX)
{
    _beamID = pX;
}

void TrackJamTarget::marshal(DataStream& dataStream) const
{
    _trackJam.marshal(dataStream);
    dataStream << _emitterID;
    dataStream << _beamID;
}

void TrackJamTarget::unmarshal(DataStream& dataStream)
{
    _trackJam.unmarshal(dataStream);
    dataStream >> _emitterID;
    dataStream >> _beamID;
}


bool TrackJamTarget::operator ==(const TrackJamTarget& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_trackJam == rhs._trackJam) ) ivarsEqual = false;
     if( ! (_emitterID == rhs._emitterID) ) ivarsEqual = false;
     if( ! (_beamID == rhs._beamID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int TrackJamTarget::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _trackJam.getMarshalledSize();  // _trackJam
   marshalSize = marshalSize + 1;  // _emitterID
   marshalSize = marshalSize + 1;  // _beamID
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
