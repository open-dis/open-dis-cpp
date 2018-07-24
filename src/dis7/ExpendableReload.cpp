#include <DIS/ExpendableReload.h> 

using namespace DIS;


ExpendableReload::ExpendableReload():
   _expendable(), 
   _station(0), 
   _standardQuantity(0), 
   _maximumQuantity(0), 
   _standardQuantityReloadTime(0), 
   _maximumQuantityReloadTime(0)
{
}

ExpendableReload::~ExpendableReload()
{
}

EntityType& ExpendableReload::getExpendable() 
{
    return _expendable;
}

const EntityType& ExpendableReload::getExpendable() const
{
    return _expendable;
}

void ExpendableReload::setExpendable(const EntityType &pX)
{
    _expendable = pX;
}

unsigned int ExpendableReload::getStation() const
{
    return _station;
}

void ExpendableReload::setStation(unsigned int pX)
{
    _station = pX;
}

unsigned short ExpendableReload::getStandardQuantity() const
{
    return _standardQuantity;
}

void ExpendableReload::setStandardQuantity(unsigned short pX)
{
    _standardQuantity = pX;
}

unsigned short ExpendableReload::getMaximumQuantity() const
{
    return _maximumQuantity;
}

void ExpendableReload::setMaximumQuantity(unsigned short pX)
{
    _maximumQuantity = pX;
}

unsigned int ExpendableReload::getStandardQuantityReloadTime() const
{
    return _standardQuantityReloadTime;
}

void ExpendableReload::setStandardQuantityReloadTime(unsigned int pX)
{
    _standardQuantityReloadTime = pX;
}

unsigned int ExpendableReload::getMaximumQuantityReloadTime() const
{
    return _maximumQuantityReloadTime;
}

void ExpendableReload::setMaximumQuantityReloadTime(unsigned int pX)
{
    _maximumQuantityReloadTime = pX;
}

void ExpendableReload::marshal(DataStream& dataStream) const
{
    _expendable.marshal(dataStream);
    dataStream << _station;
    dataStream << _standardQuantity;
    dataStream << _maximumQuantity;
    dataStream << _standardQuantityReloadTime;
    dataStream << _maximumQuantityReloadTime;
}

void ExpendableReload::unmarshal(DataStream& dataStream)
{
    _expendable.unmarshal(dataStream);
    dataStream >> _station;
    dataStream >> _standardQuantity;
    dataStream >> _maximumQuantity;
    dataStream >> _standardQuantityReloadTime;
    dataStream >> _maximumQuantityReloadTime;
}


bool ExpendableReload::operator ==(const ExpendableReload& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_expendable == rhs._expendable) ) ivarsEqual = false;
     if( ! (_station == rhs._station) ) ivarsEqual = false;
     if( ! (_standardQuantity == rhs._standardQuantity) ) ivarsEqual = false;
     if( ! (_maximumQuantity == rhs._maximumQuantity) ) ivarsEqual = false;
     if( ! (_standardQuantityReloadTime == rhs._standardQuantityReloadTime) ) ivarsEqual = false;
     if( ! (_maximumQuantityReloadTime == rhs._maximumQuantityReloadTime) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ExpendableReload::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _expendable.getMarshalledSize();  // _expendable
   marshalSize = marshalSize + 4;  // _station
   marshalSize = marshalSize + 2;  // _standardQuantity
   marshalSize = marshalSize + 2;  // _maximumQuantity
   marshalSize = marshalSize + 4;  // _standardQuantityReloadTime
   marshalSize = marshalSize + 4;  // _maximumQuantityReloadTime
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
