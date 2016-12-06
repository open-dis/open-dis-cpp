#include <DIS/IsPartOfPdu.h> 

using namespace DIS;


IsPartOfPdu::IsPartOfPdu() : EntityManagementFamilyPdu(),
   _orginatingEntityID(), 
   _receivingEntityID(), 
   _relationship(), 
   _partLocation(), 
   _namedLocationID(), 
   _partEntityType()
{
    setPduType( 36 );
}

IsPartOfPdu::~IsPartOfPdu()
{
}

EntityID& IsPartOfPdu::getOrginatingEntityID() 
{
    return _orginatingEntityID;
}

const EntityID& IsPartOfPdu::getOrginatingEntityID() const
{
    return _orginatingEntityID;
}

void IsPartOfPdu::setOrginatingEntityID(const EntityID &pX)
{
    _orginatingEntityID = pX;
}

EntityID& IsPartOfPdu::getReceivingEntityID() 
{
    return _receivingEntityID;
}

const EntityID& IsPartOfPdu::getReceivingEntityID() const
{
    return _receivingEntityID;
}

void IsPartOfPdu::setReceivingEntityID(const EntityID &pX)
{
    _receivingEntityID = pX;
}

Relationship& IsPartOfPdu::getRelationship() 
{
    return _relationship;
}

const Relationship& IsPartOfPdu::getRelationship() const
{
    return _relationship;
}

void IsPartOfPdu::setRelationship(const Relationship &pX)
{
    _relationship = pX;
}

Vector3Float& IsPartOfPdu::getPartLocation() 
{
    return _partLocation;
}

const Vector3Float& IsPartOfPdu::getPartLocation() const
{
    return _partLocation;
}

void IsPartOfPdu::setPartLocation(const Vector3Float &pX)
{
    _partLocation = pX;
}

NamedLocationIdentification& IsPartOfPdu::getNamedLocationID() 
{
    return _namedLocationID;
}

const NamedLocationIdentification& IsPartOfPdu::getNamedLocationID() const
{
    return _namedLocationID;
}

void IsPartOfPdu::setNamedLocationID(const NamedLocationIdentification &pX)
{
    _namedLocationID = pX;
}

EntityType& IsPartOfPdu::getPartEntityType() 
{
    return _partEntityType;
}

const EntityType& IsPartOfPdu::getPartEntityType() const
{
    return _partEntityType;
}

void IsPartOfPdu::setPartEntityType(const EntityType &pX)
{
    _partEntityType = pX;
}

void IsPartOfPdu::marshal(DataStream& dataStream) const
{
    EntityManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _orginatingEntityID.marshal(dataStream);
    _receivingEntityID.marshal(dataStream);
    _relationship.marshal(dataStream);
    _partLocation.marshal(dataStream);
    _namedLocationID.marshal(dataStream);
    _partEntityType.marshal(dataStream);
}

void IsPartOfPdu::unmarshal(DataStream& dataStream)
{
    EntityManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _orginatingEntityID.unmarshal(dataStream);
    _receivingEntityID.unmarshal(dataStream);
    _relationship.unmarshal(dataStream);
    _partLocation.unmarshal(dataStream);
    _namedLocationID.unmarshal(dataStream);
    _partEntityType.unmarshal(dataStream);
}


bool IsPartOfPdu::operator ==(const IsPartOfPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityManagementFamilyPdu::operator==(rhs);

     if( ! (_orginatingEntityID == rhs._orginatingEntityID) ) ivarsEqual = false;
     if( ! (_receivingEntityID == rhs._receivingEntityID) ) ivarsEqual = false;
     if( ! (_relationship == rhs._relationship) ) ivarsEqual = false;
     if( ! (_partLocation == rhs._partLocation) ) ivarsEqual = false;
     if( ! (_namedLocationID == rhs._namedLocationID) ) ivarsEqual = false;
     if( ! (_partEntityType == rhs._partEntityType) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IsPartOfPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _orginatingEntityID.getMarshalledSize();  // _orginatingEntityID
   marshalSize = marshalSize + _receivingEntityID.getMarshalledSize();  // _receivingEntityID
   marshalSize = marshalSize + _relationship.getMarshalledSize();  // _relationship
   marshalSize = marshalSize + _partLocation.getMarshalledSize();  // _partLocation
   marshalSize = marshalSize + _namedLocationID.getMarshalledSize();  // _namedLocationID
   marshalSize = marshalSize + _partEntityType.getMarshalledSize();  // _partEntityType
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
