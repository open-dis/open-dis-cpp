#include <DIS/FirePdu.h> 

using namespace DIS;


FirePdu::FirePdu() : WarfareFamilyPdu(),
   _munitionExpendibleID(), 
   _eventID(), 
   _fireMissionIndex(0), 
   _locationInWorldCoordinates(), 
   _descriptor(), 
   _velocity(), 
   _range(0.0)
{
    setPduType( 2 );
}

FirePdu::~FirePdu()
{
}

EntityID& FirePdu::getMunitionExpendibleID() 
{
    return _munitionExpendibleID;
}

const EntityID& FirePdu::getMunitionExpendibleID() const
{
    return _munitionExpendibleID;
}

void FirePdu::setMunitionExpendibleID(const EntityID &pX)
{
    _munitionExpendibleID = pX;
}

EventIdentifier& FirePdu::getEventID() 
{
    return _eventID;
}

const EventIdentifier& FirePdu::getEventID() const
{
    return _eventID;
}

void FirePdu::setEventID(const EventIdentifier &pX)
{
    _eventID = pX;
}

unsigned int FirePdu::getFireMissionIndex() const
{
    return _fireMissionIndex;
}

void FirePdu::setFireMissionIndex(unsigned int pX)
{
    _fireMissionIndex = pX;
}

Vector3Double& FirePdu::getLocationInWorldCoordinates() 
{
    return _locationInWorldCoordinates;
}

const Vector3Double& FirePdu::getLocationInWorldCoordinates() const
{
    return _locationInWorldCoordinates;
}

void FirePdu::setLocationInWorldCoordinates(const Vector3Double &pX)
{
    _locationInWorldCoordinates = pX;
}

MunitionDescriptor& FirePdu::getDescriptor() 
{
    return _descriptor;
}

const MunitionDescriptor& FirePdu::getDescriptor() const
{
    return _descriptor;
}

void FirePdu::setDescriptor(const MunitionDescriptor &pX)
{
    _descriptor = pX;
}

Vector3Float& FirePdu::getVelocity() 
{
    return _velocity;
}

const Vector3Float& FirePdu::getVelocity() const
{
    return _velocity;
}

void FirePdu::setVelocity(const Vector3Float &pX)
{
    _velocity = pX;
}

float FirePdu::getRange() const
{
    return _range;
}

void FirePdu::setRange(float pX)
{
    _range = pX;
}

void FirePdu::marshal(DataStream& dataStream) const
{
    WarfareFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _munitionExpendibleID.marshal(dataStream);
    _eventID.marshal(dataStream);
    dataStream << _fireMissionIndex;
    _locationInWorldCoordinates.marshal(dataStream);
    _descriptor.marshal(dataStream);
    _velocity.marshal(dataStream);
    dataStream << _range;
}

void FirePdu::unmarshal(DataStream& dataStream)
{
    WarfareFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _munitionExpendibleID.unmarshal(dataStream);
    _eventID.unmarshal(dataStream);
    dataStream >> _fireMissionIndex;
    _locationInWorldCoordinates.unmarshal(dataStream);
    _descriptor.unmarshal(dataStream);
    _velocity.unmarshal(dataStream);
    dataStream >> _range;
}


bool FirePdu::operator ==(const FirePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = WarfareFamilyPdu::operator==(rhs);

     if( ! (_munitionExpendibleID == rhs._munitionExpendibleID) ) ivarsEqual = false;
     if( ! (_eventID == rhs._eventID) ) ivarsEqual = false;
     if( ! (_fireMissionIndex == rhs._fireMissionIndex) ) ivarsEqual = false;
     if( ! (_locationInWorldCoordinates == rhs._locationInWorldCoordinates) ) ivarsEqual = false;
     if( ! (_descriptor == rhs._descriptor) ) ivarsEqual = false;
     if( ! (_velocity == rhs._velocity) ) ivarsEqual = false;
     if( ! (_range == rhs._range) ) ivarsEqual = false;

    return ivarsEqual;
 }

int FirePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = WarfareFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _munitionExpendibleID.getMarshalledSize();  // _munitionExpendibleID
   marshalSize = marshalSize + _eventID.getMarshalledSize();  // _eventID
   marshalSize = marshalSize + 4;  // _fireMissionIndex
   marshalSize = marshalSize + _locationInWorldCoordinates.getMarshalledSize();  // _locationInWorldCoordinates
   marshalSize = marshalSize + _descriptor.getMarshalledSize();  // _descriptor
   marshalSize = marshalSize + _velocity.getMarshalledSize();  // _velocity
   marshalSize = marshalSize + 4;  // _range
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
