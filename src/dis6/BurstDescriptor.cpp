#include <DIS/BurstDescriptor.h> 

using namespace DIS;


BurstDescriptor::BurstDescriptor():
   _munition(), 
   _warhead(0), 
   _fuse(0), 
   _quantity(0), 
   _rate(0)
{
}

BurstDescriptor::~BurstDescriptor()
{
}

EntityType& BurstDescriptor::getMunition() 
{
    return _munition;
}

const EntityType& BurstDescriptor::getMunition() const
{
    return _munition;
}

void BurstDescriptor::setMunition(const EntityType &pX)
{
    _munition = pX;
}

unsigned short BurstDescriptor::getWarhead() const
{
    return _warhead;
}

void BurstDescriptor::setWarhead(unsigned short pX)
{
    _warhead = pX;
}

unsigned short BurstDescriptor::getFuse() const
{
    return _fuse;
}

void BurstDescriptor::setFuse(unsigned short pX)
{
    _fuse = pX;
}

unsigned short BurstDescriptor::getQuantity() const
{
    return _quantity;
}

void BurstDescriptor::setQuantity(unsigned short pX)
{
    _quantity = pX;
}

unsigned short BurstDescriptor::getRate() const
{
    return _rate;
}

void BurstDescriptor::setRate(unsigned short pX)
{
    _rate = pX;
}

void BurstDescriptor::marshal(DataStream& dataStream) const
{
    _munition.marshal(dataStream);
    dataStream << _warhead;
    dataStream << _fuse;
    dataStream << _quantity;
    dataStream << _rate;
}

void BurstDescriptor::unmarshal(DataStream& dataStream)
{
    _munition.unmarshal(dataStream);
    dataStream >> _warhead;
    dataStream >> _fuse;
    dataStream >> _quantity;
    dataStream >> _rate;
}


bool BurstDescriptor::operator ==(const BurstDescriptor& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_munition == rhs._munition) ) ivarsEqual = false;
     if( ! (_warhead == rhs._warhead) ) ivarsEqual = false;
     if( ! (_fuse == rhs._fuse) ) ivarsEqual = false;
     if( ! (_quantity == rhs._quantity) ) ivarsEqual = false;
     if( ! (_rate == rhs._rate) ) ivarsEqual = false;

    return ivarsEqual;
 }

int BurstDescriptor::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _munition.getMarshalledSize();  // _munition
   marshalSize = marshalSize + 2;  // _warhead
   marshalSize = marshalSize + 2;  // _fuse
   marshalSize = marshalSize + 2;  // _quantity
   marshalSize = marshalSize + 2;  // _rate
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
