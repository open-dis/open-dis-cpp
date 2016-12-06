#include <DIS/EngineFuelReload.h> 

using namespace DIS;


EngineFuelReload::EngineFuelReload():
   _standardQuantity(0), 
   _maximumQuantity(0), 
   _standardQuantityReloadTime(0), 
   _maximumQuantityReloadTime(0), 
   _fuelMeasurmentUnits(0), 
   _fuelLocation(0), 
   _padding(0)
{
}

EngineFuelReload::~EngineFuelReload()
{
}

unsigned int EngineFuelReload::getStandardQuantity() const
{
    return _standardQuantity;
}

void EngineFuelReload::setStandardQuantity(unsigned int pX)
{
    _standardQuantity = pX;
}

unsigned int EngineFuelReload::getMaximumQuantity() const
{
    return _maximumQuantity;
}

void EngineFuelReload::setMaximumQuantity(unsigned int pX)
{
    _maximumQuantity = pX;
}

unsigned int EngineFuelReload::getStandardQuantityReloadTime() const
{
    return _standardQuantityReloadTime;
}

void EngineFuelReload::setStandardQuantityReloadTime(unsigned int pX)
{
    _standardQuantityReloadTime = pX;
}

unsigned int EngineFuelReload::getMaximumQuantityReloadTime() const
{
    return _maximumQuantityReloadTime;
}

void EngineFuelReload::setMaximumQuantityReloadTime(unsigned int pX)
{
    _maximumQuantityReloadTime = pX;
}

unsigned char EngineFuelReload::getFuelMeasurmentUnits() const
{
    return _fuelMeasurmentUnits;
}

void EngineFuelReload::setFuelMeasurmentUnits(unsigned char pX)
{
    _fuelMeasurmentUnits = pX;
}

unsigned char EngineFuelReload::getFuelLocation() const
{
    return _fuelLocation;
}

void EngineFuelReload::setFuelLocation(unsigned char pX)
{
    _fuelLocation = pX;
}

unsigned char EngineFuelReload::getPadding() const
{
    return _padding;
}

void EngineFuelReload::setPadding(unsigned char pX)
{
    _padding = pX;
}

void EngineFuelReload::marshal(DataStream& dataStream) const
{
    dataStream << _standardQuantity;
    dataStream << _maximumQuantity;
    dataStream << _standardQuantityReloadTime;
    dataStream << _maximumQuantityReloadTime;
    dataStream << _fuelMeasurmentUnits;
    dataStream << _fuelLocation;
    dataStream << _padding;
}

void EngineFuelReload::unmarshal(DataStream& dataStream)
{
    dataStream >> _standardQuantity;
    dataStream >> _maximumQuantity;
    dataStream >> _standardQuantityReloadTime;
    dataStream >> _maximumQuantityReloadTime;
    dataStream >> _fuelMeasurmentUnits;
    dataStream >> _fuelLocation;
    dataStream >> _padding;
}


bool EngineFuelReload::operator ==(const EngineFuelReload& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_standardQuantity == rhs._standardQuantity) ) ivarsEqual = false;
     if( ! (_maximumQuantity == rhs._maximumQuantity) ) ivarsEqual = false;
     if( ! (_standardQuantityReloadTime == rhs._standardQuantityReloadTime) ) ivarsEqual = false;
     if( ! (_maximumQuantityReloadTime == rhs._maximumQuantityReloadTime) ) ivarsEqual = false;
     if( ! (_fuelMeasurmentUnits == rhs._fuelMeasurmentUnits) ) ivarsEqual = false;
     if( ! (_fuelLocation == rhs._fuelLocation) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EngineFuelReload::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _standardQuantity
   marshalSize = marshalSize + 4;  // _maximumQuantity
   marshalSize = marshalSize + 4;  // _standardQuantityReloadTime
   marshalSize = marshalSize + 4;  // _maximumQuantityReloadTime
   marshalSize = marshalSize + 1;  // _fuelMeasurmentUnits
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
