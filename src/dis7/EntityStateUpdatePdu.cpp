#include <DIS/EntityStateUpdatePdu.h> 

using namespace DIS;


EntityStateUpdatePdu::EntityStateUpdatePdu() : EntityInformationFamilyPdu(),
   _entityID(), 
   _padding1(0), 
   _numberOfVariableParameters(0), 
   _entityLinearVelocity(), 
   _entityLocation(), 
   _entityOrientation(), 
   _entityAppearance(0)
{
    setPduType( 67 );
    setProtocolFamily( 1 );
}

EntityStateUpdatePdu::~EntityStateUpdatePdu()
{
    _variableParameters.clear();
}

EntityID& EntityStateUpdatePdu::getEntityID() 
{
    return _entityID;
}

const EntityID& EntityStateUpdatePdu::getEntityID() const
{
    return _entityID;
}

void EntityStateUpdatePdu::setEntityID(const EntityID &pX)
{
    _entityID = pX;
}

char EntityStateUpdatePdu::getPadding1() const
{
    return _padding1;
}

void EntityStateUpdatePdu::setPadding1(char pX)
{
    _padding1 = pX;
}

unsigned char EntityStateUpdatePdu::getNumberOfVariableParameters() const
{
   return _variableParameters.size();
}

Vector3Float& EntityStateUpdatePdu::getEntityLinearVelocity() 
{
    return _entityLinearVelocity;
}

const Vector3Float& EntityStateUpdatePdu::getEntityLinearVelocity() const
{
    return _entityLinearVelocity;
}

void EntityStateUpdatePdu::setEntityLinearVelocity(const Vector3Float &pX)
{
    _entityLinearVelocity = pX;
}

Vector3Double& EntityStateUpdatePdu::getEntityLocation() 
{
    return _entityLocation;
}

const Vector3Double& EntityStateUpdatePdu::getEntityLocation() const
{
    return _entityLocation;
}

void EntityStateUpdatePdu::setEntityLocation(const Vector3Double &pX)
{
    _entityLocation = pX;
}

EulerAngles& EntityStateUpdatePdu::getEntityOrientation() 
{
    return _entityOrientation;
}

const EulerAngles& EntityStateUpdatePdu::getEntityOrientation() const
{
    return _entityOrientation;
}

void EntityStateUpdatePdu::setEntityOrientation(const EulerAngles &pX)
{
    _entityOrientation = pX;
}

unsigned int EntityStateUpdatePdu::getEntityAppearance() const
{
    return _entityAppearance;
}

void EntityStateUpdatePdu::setEntityAppearance(unsigned int pX)
{
    _entityAppearance = pX;
}

std::vector<VariableParameter>& EntityStateUpdatePdu::getVariableParameters() 
{
    return _variableParameters;
}

const std::vector<VariableParameter>& EntityStateUpdatePdu::getVariableParameters() const
{
    return _variableParameters;
}

void EntityStateUpdatePdu::setVariableParameters(const std::vector<VariableParameter>& pX)
{
     _variableParameters = pX;
}

void EntityStateUpdatePdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _entityID.marshal(dataStream);
    dataStream << _padding1;
    dataStream << ( unsigned char )_variableParameters.size();
    _entityLinearVelocity.marshal(dataStream);
    _entityLocation.marshal(dataStream);
    _entityOrientation.marshal(dataStream);
    dataStream << _entityAppearance;

     for(size_t idx = 0; idx < _variableParameters.size(); idx++)
     {
        VariableParameter x = _variableParameters[idx];
        x.marshal(dataStream);
     }

}

void EntityStateUpdatePdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _entityID.unmarshal(dataStream);
    dataStream >> _padding1;
    dataStream >> _numberOfVariableParameters;
    _entityLinearVelocity.unmarshal(dataStream);
    _entityLocation.unmarshal(dataStream);
    _entityOrientation.unmarshal(dataStream);
    dataStream >> _entityAppearance;

     _variableParameters.clear();
     for(size_t idx = 0; idx < _numberOfVariableParameters; idx++)
     {
        VariableParameter x;
        x.unmarshal(dataStream);
        _variableParameters.push_back(x);
     }
}


bool EntityStateUpdatePdu::operator ==(const EntityStateUpdatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (_entityID == rhs._entityID) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_entityLinearVelocity == rhs._entityLinearVelocity) ) ivarsEqual = false;
     if( ! (_entityLocation == rhs._entityLocation) ) ivarsEqual = false;
     if( ! (_entityOrientation == rhs._entityOrientation) ) ivarsEqual = false;
     if( ! (_entityAppearance == rhs._entityAppearance) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _variableParameters.size(); idx++)
     {
        if( ! ( _variableParameters[idx] == rhs._variableParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int EntityStateUpdatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _entityID.getMarshalledSize();  // _entityID
   marshalSize = marshalSize + 1;  // _padding1
   marshalSize = marshalSize + 1;  // _numberOfVariableParameters
   marshalSize = marshalSize + _entityLinearVelocity.getMarshalledSize();  // _entityLinearVelocity
   marshalSize = marshalSize + _entityLocation.getMarshalledSize();  // _entityLocation
   marshalSize = marshalSize + _entityOrientation.getMarshalledSize();  // _entityOrientation
   marshalSize = marshalSize + 4;  // _entityAppearance

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
