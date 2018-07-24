#include <DIS/Expendable.h> 

using namespace DIS;


Expendable::Expendable():
   _expendable(), 
   _station(0), 
   _quantity(0), 
   _expendableStatus(0), 
   _padding(0)
{
}

Expendable::~Expendable()
{
}

EntityType& Expendable::getExpendable() 
{
    return _expendable;
}

const EntityType& Expendable::getExpendable() const
{
    return _expendable;
}

void Expendable::setExpendable(const EntityType &pX)
{
    _expendable = pX;
}

unsigned int Expendable::getStation() const
{
    return _station;
}

void Expendable::setStation(unsigned int pX)
{
    _station = pX;
}

unsigned short Expendable::getQuantity() const
{
    return _quantity;
}

void Expendable::setQuantity(unsigned short pX)
{
    _quantity = pX;
}

unsigned char Expendable::getExpendableStatus() const
{
    return _expendableStatus;
}

void Expendable::setExpendableStatus(unsigned char pX)
{
    _expendableStatus = pX;
}

unsigned char Expendable::getPadding() const
{
    return _padding;
}

void Expendable::setPadding(unsigned char pX)
{
    _padding = pX;
}

void Expendable::marshal(DataStream& dataStream) const
{
    _expendable.marshal(dataStream);
    dataStream << _station;
    dataStream << _quantity;
    dataStream << _expendableStatus;
    dataStream << _padding;
}

void Expendable::unmarshal(DataStream& dataStream)
{
    _expendable.unmarshal(dataStream);
    dataStream >> _station;
    dataStream >> _quantity;
    dataStream >> _expendableStatus;
    dataStream >> _padding;
}


bool Expendable::operator ==(const Expendable& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_expendable == rhs._expendable) ) ivarsEqual = false;
     if( ! (_station == rhs._station) ) ivarsEqual = false;
     if( ! (_quantity == rhs._quantity) ) ivarsEqual = false;
     if( ! (_expendableStatus == rhs._expendableStatus) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int Expendable::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _expendable.getMarshalledSize();  // _expendable
   marshalSize = marshalSize + 4;  // _station
   marshalSize = marshalSize + 2;  // _quantity
   marshalSize = marshalSize + 1;  // _expendableStatus
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
