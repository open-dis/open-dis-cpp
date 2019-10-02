#include <dis6/DetonationPdu.h>

using namespace DIS;


DetonationPdu::DetonationPdu() : WarfareFamilyPdu(),
   _munitionID(), 
   _eventID(), 
   _velocity(), 
   _locationInWorldCoordinates(), 
   _burstDescriptor(), 
   _locationInEntityCoordinates(), 
   _detonationResult(0), 
   _numberOfArticulationParameters(0), 
   _pad(0)
{
    setPduType( 3 );
}

DetonationPdu::~DetonationPdu()
{
    _articulationParameters.clear();
}

EntityID& DetonationPdu::getMunitionID() 
{
    return _munitionID;
}

const EntityID& DetonationPdu::getMunitionID() const
{
    return _munitionID;
}

void DetonationPdu::setMunitionID(const EntityID &pX)
{
    _munitionID = pX;
}

EventID& DetonationPdu::getEventID() 
{
    return _eventID;
}

const EventID& DetonationPdu::getEventID() const
{
    return _eventID;
}

void DetonationPdu::setEventID(const EventID &pX)
{
    _eventID = pX;
}

Vector3Float& DetonationPdu::getVelocity() 
{
    return _velocity;
}

const Vector3Float& DetonationPdu::getVelocity() const
{
    return _velocity;
}

void DetonationPdu::setVelocity(const Vector3Float &pX)
{
    _velocity = pX;
}

Vector3Double& DetonationPdu::getLocationInWorldCoordinates() 
{
    return _locationInWorldCoordinates;
}

const Vector3Double& DetonationPdu::getLocationInWorldCoordinates() const
{
    return _locationInWorldCoordinates;
}

void DetonationPdu::setLocationInWorldCoordinates(const Vector3Double &pX)
{
    _locationInWorldCoordinates = pX;
}

BurstDescriptor& DetonationPdu::getBurstDescriptor() 
{
    return _burstDescriptor;
}

const BurstDescriptor& DetonationPdu::getBurstDescriptor() const
{
    return _burstDescriptor;
}

void DetonationPdu::setBurstDescriptor(const BurstDescriptor &pX)
{
    _burstDescriptor = pX;
}

Vector3Float& DetonationPdu::getLocationInEntityCoordinates() 
{
    return _locationInEntityCoordinates;
}

const Vector3Float& DetonationPdu::getLocationInEntityCoordinates() const
{
    return _locationInEntityCoordinates;
}

void DetonationPdu::setLocationInEntityCoordinates(const Vector3Float &pX)
{
    _locationInEntityCoordinates = pX;
}

unsigned char DetonationPdu::getDetonationResult() const
{
    return _detonationResult;
}

void DetonationPdu::setDetonationResult(unsigned char pX)
{
    _detonationResult = pX;
}

unsigned char DetonationPdu::getNumberOfArticulationParameters() const
{
   return _articulationParameters.size();
}

short DetonationPdu::getPad() const
{
    return _pad;
}

void DetonationPdu::setPad(short pX)
{
    _pad = pX;
}

std::vector<ArticulationParameter>& DetonationPdu::getArticulationParameters() 
{
    return _articulationParameters;
}

const std::vector<ArticulationParameter>& DetonationPdu::getArticulationParameters() const
{
    return _articulationParameters;
}

void DetonationPdu::setArticulationParameters(const std::vector<ArticulationParameter>& pX)
{
     _articulationParameters = pX;
}

void DetonationPdu::marshal(DataStream& dataStream) const
{
    WarfareFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _munitionID.marshal(dataStream);
    _eventID.marshal(dataStream);
    _velocity.marshal(dataStream);
    _locationInWorldCoordinates.marshal(dataStream);
    _burstDescriptor.marshal(dataStream);
    _locationInEntityCoordinates.marshal(dataStream);
    dataStream << _detonationResult;
    dataStream << ( unsigned char )_articulationParameters.size();
    dataStream << _pad;

     for(size_t idx = 0; idx < _articulationParameters.size(); idx++)
     {
        ArticulationParameter x = _articulationParameters[idx];
        x.marshal(dataStream);
     }

}

void DetonationPdu::unmarshal(DataStream& dataStream)
{
    WarfareFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _munitionID.unmarshal(dataStream);
    _eventID.unmarshal(dataStream);
    _velocity.unmarshal(dataStream);
    _locationInWorldCoordinates.unmarshal(dataStream);
    _burstDescriptor.unmarshal(dataStream);
    _locationInEntityCoordinates.unmarshal(dataStream);
    dataStream >> _detonationResult;
    dataStream >> _numberOfArticulationParameters;
    dataStream >> _pad;

     _articulationParameters.clear();
     for(size_t idx = 0; idx < _numberOfArticulationParameters; idx++)
     {
        ArticulationParameter x;
        x.unmarshal(dataStream);
        _articulationParameters.push_back(x);
     }
}


bool DetonationPdu::operator ==(const DetonationPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = WarfareFamilyPdu::operator==(rhs);

     if( ! (_munitionID == rhs._munitionID) ) ivarsEqual = false;
     if( ! (_eventID == rhs._eventID) ) ivarsEqual = false;
     if( ! (_velocity == rhs._velocity) ) ivarsEqual = false;
     if( ! (_locationInWorldCoordinates == rhs._locationInWorldCoordinates) ) ivarsEqual = false;
     if( ! (_burstDescriptor == rhs._burstDescriptor) ) ivarsEqual = false;
     if( ! (_locationInEntityCoordinates == rhs._locationInEntityCoordinates) ) ivarsEqual = false;
     if( ! (_detonationResult == rhs._detonationResult) ) ivarsEqual = false;
     if( ! (_pad == rhs._pad) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _articulationParameters.size(); idx++)
     {
        if( ! ( _articulationParameters[idx] == rhs._articulationParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int DetonationPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = WarfareFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _munitionID.getMarshalledSize();  // _munitionID
   marshalSize = marshalSize + _eventID.getMarshalledSize();  // _eventID
   marshalSize = marshalSize + _velocity.getMarshalledSize();  // _velocity
   marshalSize = marshalSize + _locationInWorldCoordinates.getMarshalledSize();  // _locationInWorldCoordinates
   marshalSize = marshalSize + _burstDescriptor.getMarshalledSize();  // _burstDescriptor
   marshalSize = marshalSize + _locationInEntityCoordinates.getMarshalledSize();  // _locationInEntityCoordinates
   marshalSize = marshalSize + 1;  // _detonationResult
   marshalSize = marshalSize + 1;  // _numberOfArticulationParameters
   marshalSize = marshalSize + 2;  // _pad

   for(unsigned long long idx=0; idx < _articulationParameters.size(); idx++)
   {
        ArticulationParameter listElement = _articulationParameters[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

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
