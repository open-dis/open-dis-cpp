#include <DIS/OwnershipStatus.h> 

using namespace DIS;


OwnershipStatus::OwnershipStatus():
   _entityId(), 
   _ownershipStatus(0), 
   _padding(0)
{
}

OwnershipStatus::~OwnershipStatus()
{
}

EntityID& OwnershipStatus::getEntityId() 
{
    return _entityId;
}

const EntityID& OwnershipStatus::getEntityId() const
{
    return _entityId;
}

void OwnershipStatus::setEntityId(const EntityID &pX)
{
    _entityId = pX;
}

unsigned char OwnershipStatus::getOwnershipStatus() const
{
    return _ownershipStatus;
}

void OwnershipStatus::setOwnershipStatus(unsigned char pX)
{
    _ownershipStatus = pX;
}

unsigned char OwnershipStatus::getPadding() const
{
    return _padding;
}

void OwnershipStatus::setPadding(unsigned char pX)
{
    _padding = pX;
}

void OwnershipStatus::marshal(DataStream& dataStream) const
{
    _entityId.marshal(dataStream);
    dataStream << _ownershipStatus;
    dataStream << _padding;
}

void OwnershipStatus::unmarshal(DataStream& dataStream)
{
    _entityId.unmarshal(dataStream);
    dataStream >> _ownershipStatus;
    dataStream >> _padding;
}


bool OwnershipStatus::operator ==(const OwnershipStatus& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_entityId == rhs._entityId) ) ivarsEqual = false;
     if( ! (_ownershipStatus == rhs._ownershipStatus) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int OwnershipStatus::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _entityId.getMarshalledSize();  // _entityId
   marshalSize = marshalSize + 1;  // _ownershipStatus
   marshalSize = marshalSize + 1;  // _padding
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
