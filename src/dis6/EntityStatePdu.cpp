#include <dis6/EntityStatePdu.h>

using namespace DIS;


EntityStatePdu::EntityStatePdu() : EntityInformationFamilyPdu(),
   _entityID(), 
   _forceId(0), 
   _numberOfArticulationParameters(0), 
   _entityType(), 
   _alternativeEntityType(), 
   _entityLinearVelocity(), 
   _entityLocation(), 
   _entityOrientation(), 
   _entityAppearance(0), 
   _deadReckoningParameters(), 
   _marking(), 
   _capabilities(0)
{
    setPduType( 1 );
}

EntityStatePdu::~EntityStatePdu()
{
    _articulationParameters.clear();
}

EntityID& EntityStatePdu::getEntityID() 
{
    return _entityID;
}

const EntityID& EntityStatePdu::getEntityID() const
{
    return _entityID;
}

void EntityStatePdu::setEntityID(const EntityID &pX)
{
    _entityID = pX;
}

uint8_t EntityStatePdu::getForceId() const
{
    return _forceId;
}

void EntityStatePdu::setForceId(uint8_t pX)
{
    _forceId = pX;
}

char EntityStatePdu::getNumberOfArticulationParameters() const
{
   return _articulationParameters.size();
}

EntityType& EntityStatePdu::getEntityType() 
{
    return _entityType;
}

const EntityType& EntityStatePdu::getEntityType() const
{
    return _entityType;
}

void EntityStatePdu::setEntityType(const EntityType &pX)
{
    _entityType = pX;
}

EntityType& EntityStatePdu::getAlternativeEntityType() 
{
    return _alternativeEntityType;
}

const EntityType& EntityStatePdu::getAlternativeEntityType() const
{
    return _alternativeEntityType;
}

void EntityStatePdu::setAlternativeEntityType(const EntityType &pX)
{
    _alternativeEntityType = pX;
}

Vector3Float& EntityStatePdu::getEntityLinearVelocity() 
{
    return _entityLinearVelocity;
}

const Vector3Float& EntityStatePdu::getEntityLinearVelocity() const
{
    return _entityLinearVelocity;
}

void EntityStatePdu::setEntityLinearVelocity(const Vector3Float &pX)
{
    _entityLinearVelocity = pX;
}

Vector3Double& EntityStatePdu::getEntityLocation() 
{
    return _entityLocation;
}

const Vector3Double& EntityStatePdu::getEntityLocation() const
{
    return _entityLocation;
}

void EntityStatePdu::setEntityLocation(const Vector3Double &pX)
{
    _entityLocation = pX;
}

Orientation& EntityStatePdu::getEntityOrientation() 
{
    return _entityOrientation;
}

const Orientation& EntityStatePdu::getEntityOrientation() const
{
    return _entityOrientation;
}

void EntityStatePdu::setEntityOrientation(const Orientation &pX)
{
    _entityOrientation = pX;
}

int EntityStatePdu::getEntityAppearance() const
{
    return _entityAppearance;
}

void EntityStatePdu::setEntityAppearance(int pX)
{
    _entityAppearance = pX;
}

DeadReckoningParameter& EntityStatePdu::getDeadReckoningParameters() 
{
    return _deadReckoningParameters;
}

const DeadReckoningParameter& EntityStatePdu::getDeadReckoningParameters() const
{
    return _deadReckoningParameters;
}

void EntityStatePdu::setDeadReckoningParameters(const DeadReckoningParameter &pX)
{
    _deadReckoningParameters = pX;
}

Marking& EntityStatePdu::getMarking() 
{
    return _marking;
}

const Marking& EntityStatePdu::getMarking() const
{
    return _marking;
}

void EntityStatePdu::setMarking(const Marking &pX)
{
    _marking = pX;
}

int EntityStatePdu::getCapabilities() const
{
    return _capabilities;
}

void EntityStatePdu::setCapabilities(int pX)
{
    _capabilities = pX;
}

std::vector<ArticulationParameter>& EntityStatePdu::getArticulationParameters() 
{
    return _articulationParameters;
}

const std::vector<ArticulationParameter>& EntityStatePdu::getArticulationParameters() const
{
    return _articulationParameters;
}

void EntityStatePdu::setArticulationParameters(const std::vector<ArticulationParameter>& pX)
{
     _articulationParameters = pX;
}

void EntityStatePdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _entityID.marshal(dataStream);
    dataStream << _forceId;
    dataStream << ( char )_articulationParameters.size();
    _entityType.marshal(dataStream);
    _alternativeEntityType.marshal(dataStream);
    _entityLinearVelocity.marshal(dataStream);
    _entityLocation.marshal(dataStream);
    _entityOrientation.marshal(dataStream);
    dataStream << _entityAppearance;
    _deadReckoningParameters.marshal(dataStream);
    _marking.marshal(dataStream);
    dataStream << _capabilities;

     for(size_t idx = 0; idx < _articulationParameters.size(); idx++)
     {
        ArticulationParameter x = _articulationParameters[idx];
        x.marshal(dataStream);
     }

}

void EntityStatePdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _entityID.unmarshal(dataStream);
    dataStream >> _forceId;
    dataStream >> _numberOfArticulationParameters;
    _entityType.unmarshal(dataStream);
    _alternativeEntityType.unmarshal(dataStream);
    _entityLinearVelocity.unmarshal(dataStream);
    _entityLocation.unmarshal(dataStream);
    _entityOrientation.unmarshal(dataStream);
    dataStream >> _entityAppearance;
    _deadReckoningParameters.unmarshal(dataStream);
    _marking.unmarshal(dataStream);
    dataStream >> _capabilities;

     _articulationParameters.clear();
     for(int8_t idx = 0; idx < _numberOfArticulationParameters; idx++)
     {
        ArticulationParameter x;
        x.unmarshal(dataStream);
        _articulationParameters.push_back(x);
     }
}


bool EntityStatePdu::operator ==(const EntityStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (_entityID == rhs._entityID) ) ivarsEqual = false;
     if( ! (_forceId == rhs._forceId) ) ivarsEqual = false;
     if( ! (_entityType == rhs._entityType) ) ivarsEqual = false;
     if( ! (_alternativeEntityType == rhs._alternativeEntityType) ) ivarsEqual = false;
     if( ! (_entityLinearVelocity == rhs._entityLinearVelocity) ) ivarsEqual = false;
     if( ! (_entityLocation == rhs._entityLocation) ) ivarsEqual = false;
     if( ! (_entityOrientation == rhs._entityOrientation) ) ivarsEqual = false;
     if( ! (_entityAppearance == rhs._entityAppearance) ) ivarsEqual = false;
     if( ! (_deadReckoningParameters == rhs._deadReckoningParameters) ) ivarsEqual = false;
     if( ! (_marking == rhs._marking) ) ivarsEqual = false;
     if( ! (_capabilities == rhs._capabilities) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _articulationParameters.size(); idx++)
     {
        if( ! ( _articulationParameters[idx] == rhs._articulationParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int EntityStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _entityID.getMarshalledSize();  // _entityID
   marshalSize = marshalSize + 1;  // _forceId
   marshalSize = marshalSize + 1;  // _numberOfArticulationParameters
   marshalSize = marshalSize + _entityType.getMarshalledSize();  // _entityType
   marshalSize = marshalSize + _alternativeEntityType.getMarshalledSize();  // _alternativeEntityType
   marshalSize = marshalSize + _entityLinearVelocity.getMarshalledSize();  // _entityLinearVelocity
   marshalSize = marshalSize + _entityLocation.getMarshalledSize();  // _entityLocation
   marshalSize = marshalSize + _entityOrientation.getMarshalledSize();  // _entityOrientation
   marshalSize = marshalSize + 4;  // _entityAppearance
   marshalSize = marshalSize + _deadReckoningParameters.getMarshalledSize();  // _deadReckoningParameters
   marshalSize = marshalSize + _marking.getMarshalledSize();  // _marking
   marshalSize = marshalSize + 4;  // _capabilities

   for(size_t idx=0; idx < _articulationParameters.size(); idx++)
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
