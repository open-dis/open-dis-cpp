#include <DIS/Munition.h> 

using namespace DIS;


Munition::Munition():
   _munitionType(), 
   _station(0), 
   _quantity(0), 
   _munitionStatus(0), 
   _padding(0)
{
}

Munition::~Munition()
{
}

EntityType& Munition::getMunitionType() 
{
    return _munitionType;
}

const EntityType& Munition::getMunitionType() const
{
    return _munitionType;
}

void Munition::setMunitionType(const EntityType &pX)
{
    _munitionType = pX;
}

unsigned int Munition::getStation() const
{
    return _station;
}

void Munition::setStation(unsigned int pX)
{
    _station = pX;
}

unsigned short Munition::getQuantity() const
{
    return _quantity;
}

void Munition::setQuantity(unsigned short pX)
{
    _quantity = pX;
}

unsigned char Munition::getMunitionStatus() const
{
    return _munitionStatus;
}

void Munition::setMunitionStatus(unsigned char pX)
{
    _munitionStatus = pX;
}

unsigned char Munition::getPadding() const
{
    return _padding;
}

void Munition::setPadding(unsigned char pX)
{
    _padding = pX;
}

void Munition::marshal(DataStream& dataStream) const
{
    _munitionType.marshal(dataStream);
    dataStream << _station;
    dataStream << _quantity;
    dataStream << _munitionStatus;
    dataStream << _padding;
}

void Munition::unmarshal(DataStream& dataStream)
{
    _munitionType.unmarshal(dataStream);
    dataStream >> _station;
    dataStream >> _quantity;
    dataStream >> _munitionStatus;
    dataStream >> _padding;
}


bool Munition::operator ==(const Munition& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_munitionType == rhs._munitionType) ) ivarsEqual = false;
     if( ! (_station == rhs._station) ) ivarsEqual = false;
     if( ! (_quantity == rhs._quantity) ) ivarsEqual = false;
     if( ! (_munitionStatus == rhs._munitionStatus) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int Munition::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _munitionType.getMarshalledSize();  // _munitionType
   marshalSize = marshalSize + 4;  // _station
   marshalSize = marshalSize + 2;  // _quantity
   marshalSize = marshalSize + 1;  // _munitionStatus
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
