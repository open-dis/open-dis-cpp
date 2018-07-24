#include <DIS/MunitionReload.h> 

using namespace DIS;


MunitionReload::MunitionReload():
   _munitionType(), 
   _station(0), 
   _standardQuantity(0), 
   _maximumQuantity(0), 
   _stationName(0), 
   _stationNumber(0)
{
}

MunitionReload::~MunitionReload()
{
}

EntityType& MunitionReload::getMunitionType() 
{
    return _munitionType;
}

const EntityType& MunitionReload::getMunitionType() const
{
    return _munitionType;
}

void MunitionReload::setMunitionType(const EntityType &pX)
{
    _munitionType = pX;
}

unsigned int MunitionReload::getStation() const
{
    return _station;
}

void MunitionReload::setStation(unsigned int pX)
{
    _station = pX;
}

unsigned short MunitionReload::getStandardQuantity() const
{
    return _standardQuantity;
}

void MunitionReload::setStandardQuantity(unsigned short pX)
{
    _standardQuantity = pX;
}

unsigned short MunitionReload::getMaximumQuantity() const
{
    return _maximumQuantity;
}

void MunitionReload::setMaximumQuantity(unsigned short pX)
{
    _maximumQuantity = pX;
}

unsigned short MunitionReload::getStationName() const
{
    return _stationName;
}

void MunitionReload::setStationName(unsigned short pX)
{
    _stationName = pX;
}

unsigned short MunitionReload::getStationNumber() const
{
    return _stationNumber;
}

void MunitionReload::setStationNumber(unsigned short pX)
{
    _stationNumber = pX;
}

void MunitionReload::marshal(DataStream& dataStream) const
{
    _munitionType.marshal(dataStream);
    dataStream << _station;
    dataStream << _standardQuantity;
    dataStream << _maximumQuantity;
    dataStream << _stationName;
    dataStream << _stationNumber;
}

void MunitionReload::unmarshal(DataStream& dataStream)
{
    _munitionType.unmarshal(dataStream);
    dataStream >> _station;
    dataStream >> _standardQuantity;
    dataStream >> _maximumQuantity;
    dataStream >> _stationName;
    dataStream >> _stationNumber;
}


bool MunitionReload::operator ==(const MunitionReload& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_munitionType == rhs._munitionType) ) ivarsEqual = false;
     if( ! (_station == rhs._station) ) ivarsEqual = false;
     if( ! (_standardQuantity == rhs._standardQuantity) ) ivarsEqual = false;
     if( ! (_maximumQuantity == rhs._maximumQuantity) ) ivarsEqual = false;
     if( ! (_stationName == rhs._stationName) ) ivarsEqual = false;
     if( ! (_stationNumber == rhs._stationNumber) ) ivarsEqual = false;

    return ivarsEqual;
 }

int MunitionReload::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _munitionType.getMarshalledSize();  // _munitionType
   marshalSize = marshalSize + 4;  // _station
   marshalSize = marshalSize + 2;  // _standardQuantity
   marshalSize = marshalSize + 2;  // _maximumQuantity
   marshalSize = marshalSize + 2;  // _stationName
   marshalSize = marshalSize + 2;  // _stationNumber
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
