#include <DIS/DetonationPdu.h> 

using namespace DIS;


DetonationPdu::DetonationPdu() : WarfareFamilyPdu(),
   _explodingEntityID(), 
   _eventID(), 
   _velocity(), 
   _locationInWorldCoordinates(), 
   _descriptor(), 
   _locationOfEntityCoordinates(), 
   _detonationResult(0), 
   _numberOfVariableParameters(0), 
   _pad(0)
{
    setPduType( 3 );
}

DetonationPdu::~DetonationPdu()
{
    _variableParameters.clear();
}

EntityID& DetonationPdu::getExplodingEntityID() 
{
    return _explodingEntityID;
}

const EntityID& DetonationPdu::getExplodingEntityID() const
{
    return _explodingEntityID;
}

void DetonationPdu::setExplodingEntityID(const EntityID &pX)
{
    _explodingEntityID = pX;
}

EventIdentifier& DetonationPdu::getEventID() 
{
    return _eventID;
}

const EventIdentifier& DetonationPdu::getEventID() const
{
    return _eventID;
}

void DetonationPdu::setEventID(const EventIdentifier &pX)
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

MunitionDescriptor& DetonationPdu::getDescriptor() 
{
    return _descriptor;
}

const MunitionDescriptor& DetonationPdu::getDescriptor() const
{
    return _descriptor;
}

void DetonationPdu::setDescriptor(const MunitionDescriptor &pX)
{
    _descriptor = pX;
}

Vector3Float& DetonationPdu::getLocationOfEntityCoordinates() 
{
    return _locationOfEntityCoordinates;
}

const Vector3Float& DetonationPdu::getLocationOfEntityCoordinates() const
{
    return _locationOfEntityCoordinates;
}

void DetonationPdu::setLocationOfEntityCoordinates(const Vector3Float &pX)
{
    _locationOfEntityCoordinates = pX;
}

unsigned char DetonationPdu::getDetonationResult() const
{
    return _detonationResult;
}

void DetonationPdu::setDetonationResult(unsigned char pX)
{
    _detonationResult = pX;
}

unsigned char DetonationPdu::getNumberOfVariableParameters() const
{
   return _variableParameters.size();
}

unsigned short DetonationPdu::getPad() const
{
    return _pad;
}

void DetonationPdu::setPad(unsigned short pX)
{
    _pad = pX;
}

std::vector<VariableParameter>& DetonationPdu::getVariableParameters() 
{
    return _variableParameters;
}

const std::vector<VariableParameter>& DetonationPdu::getVariableParameters() const
{
    return _variableParameters;
}

void DetonationPdu::setVariableParameters(const std::vector<VariableParameter>& pX)
{
     _variableParameters = pX;
}

void DetonationPdu::marshal(DataStream& dataStream) const
{
    WarfareFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _explodingEntityID.marshal(dataStream);
    _eventID.marshal(dataStream);
    _velocity.marshal(dataStream);
    _locationInWorldCoordinates.marshal(dataStream);
    _descriptor.marshal(dataStream);
    _locationOfEntityCoordinates.marshal(dataStream);
    dataStream << _detonationResult;
    dataStream << ( unsigned char )_variableParameters.size();
    dataStream << _pad;

     for(size_t idx = 0; idx < _variableParameters.size(); idx++)
     {
        VariableParameter x = _variableParameters[idx];
        x.marshal(dataStream);
     }

}

void DetonationPdu::unmarshal(DataStream& dataStream)
{
    WarfareFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _explodingEntityID.unmarshal(dataStream);
    _eventID.unmarshal(dataStream);
    _velocity.unmarshal(dataStream);
    _locationInWorldCoordinates.unmarshal(dataStream);
    _descriptor.unmarshal(dataStream);
    _locationOfEntityCoordinates.unmarshal(dataStream);
    dataStream >> _detonationResult;
    dataStream >> _numberOfVariableParameters;
    dataStream >> _pad;

     _variableParameters.clear();
     for(size_t idx = 0; idx < _numberOfVariableParameters; idx++)
     {
        VariableParameter x;
        x.unmarshal(dataStream);
        _variableParameters.push_back(x);
     }
}


bool DetonationPdu::operator ==(const DetonationPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = WarfareFamilyPdu::operator==(rhs);

     if( ! (_explodingEntityID == rhs._explodingEntityID) ) ivarsEqual = false;
     if( ! (_eventID == rhs._eventID) ) ivarsEqual = false;
     if( ! (_velocity == rhs._velocity) ) ivarsEqual = false;
     if( ! (_locationInWorldCoordinates == rhs._locationInWorldCoordinates) ) ivarsEqual = false;
     if( ! (_descriptor == rhs._descriptor) ) ivarsEqual = false;
     if( ! (_locationOfEntityCoordinates == rhs._locationOfEntityCoordinates) ) ivarsEqual = false;
     if( ! (_detonationResult == rhs._detonationResult) ) ivarsEqual = false;
     if( ! (_pad == rhs._pad) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _variableParameters.size(); idx++)
     {
        if( ! ( _variableParameters[idx] == rhs._variableParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int DetonationPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = WarfareFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _explodingEntityID.getMarshalledSize();  // _explodingEntityID
   marshalSize = marshalSize + _eventID.getMarshalledSize();  // _eventID
   marshalSize = marshalSize + _velocity.getMarshalledSize();  // _velocity
   marshalSize = marshalSize + _locationInWorldCoordinates.getMarshalledSize();  // _locationInWorldCoordinates
   marshalSize = marshalSize + _descriptor.getMarshalledSize();  // _descriptor
   marshalSize = marshalSize + _locationOfEntityCoordinates.getMarshalledSize();  // _locationOfEntityCoordinates
   marshalSize = marshalSize + 1;  // _detonationResult
   marshalSize = marshalSize + 1;  // _numberOfVariableParameters
   marshalSize = marshalSize + 2;  // _pad

   for(int idx=0; idx < _variableParameters.size(); idx++)
   {
        VariableParameter listElement = _variableParameters[idx];
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
