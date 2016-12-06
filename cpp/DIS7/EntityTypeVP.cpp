#include <DIS/EntityTypeVP.h> 

using namespace DIS;


EntityTypeVP::EntityTypeVP():
   _recordType(3), 
   _changeIndicator(0), 
   _entityType(), 
   _padding(0), 
   _padding1(0)
{
}

EntityTypeVP::~EntityTypeVP()
{
}

unsigned char EntityTypeVP::getRecordType() const
{
    return _recordType;
}

void EntityTypeVP::setRecordType(unsigned char pX)
{
    _recordType = pX;
}

unsigned char EntityTypeVP::getChangeIndicator() const
{
    return _changeIndicator;
}

void EntityTypeVP::setChangeIndicator(unsigned char pX)
{
    _changeIndicator = pX;
}

EntityType& EntityTypeVP::getEntityType() 
{
    return _entityType;
}

const EntityType& EntityTypeVP::getEntityType() const
{
    return _entityType;
}

void EntityTypeVP::setEntityType(const EntityType &pX)
{
    _entityType = pX;
}

unsigned short EntityTypeVP::getPadding() const
{
    return _padding;
}

void EntityTypeVP::setPadding(unsigned short pX)
{
    _padding = pX;
}

unsigned int EntityTypeVP::getPadding1() const
{
    return _padding1;
}

void EntityTypeVP::setPadding1(unsigned int pX)
{
    _padding1 = pX;
}

void EntityTypeVP::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _changeIndicator;
    _entityType.marshal(dataStream);
    dataStream << _padding;
    dataStream << _padding1;
}

void EntityTypeVP::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _changeIndicator;
    _entityType.unmarshal(dataStream);
    dataStream >> _padding;
    dataStream >> _padding1;
}


bool EntityTypeVP::operator ==(const EntityTypeVP& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_changeIndicator == rhs._changeIndicator) ) ivarsEqual = false;
     if( ! (_entityType == rhs._entityType) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EntityTypeVP::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _recordType
   marshalSize = marshalSize + 1;  // _changeIndicator
   marshalSize = marshalSize + _entityType.getMarshalledSize();  // _entityType
   marshalSize = marshalSize + 2;  // _padding
   marshalSize = marshalSize + 4;  // _padding1
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
