#include <DIS/StorageFuelReload.h> 

using namespace DIS;


StorageFuelReload::StorageFuelReload():
   _standardQuantity(0), 
   _maximumQuantity(0), 
   _standardQuantityReloadTime(0), 
   _maximumQuantityReloadTime(0), 
   _fuelMeasurementUnits(0), 
   _fuelType(0), 
   _fuelLocation(0), 
   _padding(0)
{
}

StorageFuelReload::~StorageFuelReload()
{
}

unsigned int StorageFuelReload::getStandardQuantity() const
{
    return _standardQuantity;
}

void StorageFuelReload::setStandardQuantity(unsigned int pX)
{
    _standardQuantity = pX;
}

unsigned int StorageFuelReload::getMaximumQuantity() const
{
    return _maximumQuantity;
}

void StorageFuelReload::setMaximumQuantity(unsigned int pX)
{
    _maximumQuantity = pX;
}

unsigned char StorageFuelReload::getStandardQuantityReloadTime() const
{
    return _standardQuantityReloadTime;
}

void StorageFuelReload::setStandardQuantityReloadTime(unsigned char pX)
{
    _standardQuantityReloadTime = pX;
}

unsigned char StorageFuelReload::getMaximumQuantityReloadTime() const
{
    return _maximumQuantityReloadTime;
}

void StorageFuelReload::setMaximumQuantityReloadTime(unsigned char pX)
{
    _maximumQuantityReloadTime = pX;
}

unsigned char StorageFuelReload::getFuelMeasurementUnits() const
{
    return _fuelMeasurementUnits;
}

void StorageFuelReload::setFuelMeasurementUnits(unsigned char pX)
{
    _fuelMeasurementUnits = pX;
}

unsigned char StorageFuelReload::getFuelType() const
{
    return _fuelType;
}

void StorageFuelReload::setFuelType(unsigned char pX)
{
    _fuelType = pX;
}

unsigned char StorageFuelReload::getFuelLocation() const
{
    return _fuelLocation;
}

void StorageFuelReload::setFuelLocation(unsigned char pX)
{
    _fuelLocation = pX;
}

unsigned char StorageFuelReload::getPadding() const
{
    return _padding;
}

void StorageFuelReload::setPadding(unsigned char pX)
{
    _padding = pX;
}

void StorageFuelReload::marshal(DataStream& dataStream) const
{
    dataStream << _standardQuantity;
    dataStream << _maximumQuantity;
    dataStream << _standardQuantityReloadTime;
    dataStream << _maximumQuantityReloadTime;
    dataStream << _fuelMeasurementUnits;
    dataStream << _fuelType;
    dataStream << _fuelLocation;
    dataStream << _padding;
}

void StorageFuelReload::unmarshal(DataStream& dataStream)
{
    dataStream >> _standardQuantity;
    dataStream >> _maximumQuantity;
    dataStream >> _standardQuantityReloadTime;
    dataStream >> _maximumQuantityReloadTime;
    dataStream >> _fuelMeasurementUnits;
    dataStream >> _fuelType;
    dataStream >> _fuelLocation;
    dataStream >> _padding;
}


bool StorageFuelReload::operator ==(const StorageFuelReload& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_standardQuantity == rhs._standardQuantity) ) ivarsEqual = false;
     if( ! (_maximumQuantity == rhs._maximumQuantity) ) ivarsEqual = false;
     if( ! (_standardQuantityReloadTime == rhs._standardQuantityReloadTime) ) ivarsEqual = false;
     if( ! (_maximumQuantityReloadTime == rhs._maximumQuantityReloadTime) ) ivarsEqual = false;
     if( ! (_fuelMeasurementUnits == rhs._fuelMeasurementUnits) ) ivarsEqual = false;
     if( ! (_fuelType == rhs._fuelType) ) ivarsEqual = false;
     if( ! (_fuelLocation == rhs._fuelLocation) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int StorageFuelReload::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _standardQuantity
   marshalSize = marshalSize + 4;  // _maximumQuantity
   marshalSize = marshalSize + 1;  // _standardQuantityReloadTime
   marshalSize = marshalSize + 1;  // _maximumQuantityReloadTime
   marshalSize = marshalSize + 1;  // _fuelMeasurementUnits
   marshalSize = marshalSize + 1;  // _fuelType
   marshalSize = marshalSize + 1;  // _fuelLocation
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
