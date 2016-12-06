#include <DIS/EntityAssociation.h> 

using namespace DIS;


EntityAssociation::EntityAssociation():
   _recordType(2), 
   _changeIndicator(0), 
   _associationStatus(0), 
   _associationType(0), 
   _entityID(), 
   _owsSttionLocation(0), 
   _physicalConnectionType(0), 
   _groupMemberType(0), 
   _groupNumber(0)
{
}

EntityAssociation::~EntityAssociation()
{
}

unsigned char EntityAssociation::getRecordType() const
{
    return _recordType;
}

void EntityAssociation::setRecordType(unsigned char pX)
{
    _recordType = pX;
}

unsigned char EntityAssociation::getChangeIndicator() const
{
    return _changeIndicator;
}

void EntityAssociation::setChangeIndicator(unsigned char pX)
{
    _changeIndicator = pX;
}

unsigned char EntityAssociation::getAssociationStatus() const
{
    return _associationStatus;
}

void EntityAssociation::setAssociationStatus(unsigned char pX)
{
    _associationStatus = pX;
}

unsigned char EntityAssociation::getAssociationType() const
{
    return _associationType;
}

void EntityAssociation::setAssociationType(unsigned char pX)
{
    _associationType = pX;
}

EntityID& EntityAssociation::getEntityID() 
{
    return _entityID;
}

const EntityID& EntityAssociation::getEntityID() const
{
    return _entityID;
}

void EntityAssociation::setEntityID(const EntityID &pX)
{
    _entityID = pX;
}

unsigned short EntityAssociation::getOwsSttionLocation() const
{
    return _owsSttionLocation;
}

void EntityAssociation::setOwsSttionLocation(unsigned short pX)
{
    _owsSttionLocation = pX;
}

unsigned short EntityAssociation::getPhysicalConnectionType() const
{
    return _physicalConnectionType;
}

void EntityAssociation::setPhysicalConnectionType(unsigned short pX)
{
    _physicalConnectionType = pX;
}

unsigned char EntityAssociation::getGroupMemberType() const
{
    return _groupMemberType;
}

void EntityAssociation::setGroupMemberType(unsigned char pX)
{
    _groupMemberType = pX;
}

unsigned short EntityAssociation::getGroupNumber() const
{
    return _groupNumber;
}

void EntityAssociation::setGroupNumber(unsigned short pX)
{
    _groupNumber = pX;
}

void EntityAssociation::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _changeIndicator;
    dataStream << _associationStatus;
    dataStream << _associationType;
    _entityID.marshal(dataStream);
    dataStream << _owsSttionLocation;
    dataStream << _physicalConnectionType;
    dataStream << _groupMemberType;
    dataStream << _groupNumber;
}

void EntityAssociation::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _changeIndicator;
    dataStream >> _associationStatus;
    dataStream >> _associationType;
    _entityID.unmarshal(dataStream);
    dataStream >> _owsSttionLocation;
    dataStream >> _physicalConnectionType;
    dataStream >> _groupMemberType;
    dataStream >> _groupNumber;
}


bool EntityAssociation::operator ==(const EntityAssociation& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_changeIndicator == rhs._changeIndicator) ) ivarsEqual = false;
     if( ! (_associationStatus == rhs._associationStatus) ) ivarsEqual = false;
     if( ! (_associationType == rhs._associationType) ) ivarsEqual = false;
     if( ! (_entityID == rhs._entityID) ) ivarsEqual = false;
     if( ! (_owsSttionLocation == rhs._owsSttionLocation) ) ivarsEqual = false;
     if( ! (_physicalConnectionType == rhs._physicalConnectionType) ) ivarsEqual = false;
     if( ! (_groupMemberType == rhs._groupMemberType) ) ivarsEqual = false;
     if( ! (_groupNumber == rhs._groupNumber) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EntityAssociation::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _recordType
   marshalSize = marshalSize + 1;  // _changeIndicator
   marshalSize = marshalSize + 1;  // _associationStatus
   marshalSize = marshalSize + 1;  // _associationType
   marshalSize = marshalSize + _entityID.getMarshalledSize();  // _entityID
   marshalSize = marshalSize + 2;  // _owsSttionLocation
   marshalSize = marshalSize + 2;  // _physicalConnectionType
   marshalSize = marshalSize + 1;  // _groupMemberType
   marshalSize = marshalSize + 2;  // _groupNumber
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
