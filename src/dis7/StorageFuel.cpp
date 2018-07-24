#include <DIS/StorageFuel.h> 

using namespace DIS;


StorageFuel::StorageFuel():
   _fuelQuantity(0), 
   _fuelMeasurementUnits(0), 
   _fuelType(0), 
   _fuelLocation(0), 
   _padding(0)
{
}

StorageFuel::~StorageFuel()
{
}

unsigned int StorageFuel::getFuelQuantity() const
{
    return _fuelQuantity;
}

void StorageFuel::setFuelQuantity(unsigned int pX)
{
    _fuelQuantity = pX;
}

unsigned char StorageFuel::getFuelMeasurementUnits() const
{
    return _fuelMeasurementUnits;
}

void StorageFuel::setFuelMeasurementUnits(unsigned char pX)
{
    _fuelMeasurementUnits = pX;
}

unsigned char StorageFuel::getFuelType() const
{
    return _fuelType;
}

void StorageFuel::setFuelType(unsigned char pX)
{
    _fuelType = pX;
}

unsigned char StorageFuel::getFuelLocation() const
{
    return _fuelLocation;
}

void StorageFuel::setFuelLocation(unsigned char pX)
{
    _fuelLocation = pX;
}

unsigned char StorageFuel::getPadding() const
{
    return _padding;
}

void StorageFuel::setPadding(unsigned char pX)
{
    _padding = pX;
}

void StorageFuel::marshal(DataStream& dataStream) const
{
    dataStream << _fuelQuantity;
    dataStream << _fuelMeasurementUnits;
    dataStream << _fuelType;
    dataStream << _fuelLocation;
    dataStream << _padding;
}

void StorageFuel::unmarshal(DataStream& dataStream)
{
    dataStream >> _fuelQuantity;
    dataStream >> _fuelMeasurementUnits;
    dataStream >> _fuelType;
    dataStream >> _fuelLocation;
    dataStream >> _padding;
}


bool StorageFuel::operator ==(const StorageFuel& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_fuelQuantity == rhs._fuelQuantity) ) ivarsEqual = false;
     if( ! (_fuelMeasurementUnits == rhs._fuelMeasurementUnits) ) ivarsEqual = false;
     if( ! (_fuelType == rhs._fuelType) ) ivarsEqual = false;
     if( ! (_fuelLocation == rhs._fuelLocation) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int StorageFuel::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _fuelQuantity
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
