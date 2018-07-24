#include <DIS/Sensor.h> 

using namespace DIS;


Sensor::Sensor():
   _sensorTypeSource(0), 
   _sensorOnOffStatus(0), 
   _sensorType(0), 
   _station(0), 
   _quantity(0), 
   _padding(0)
{
}

Sensor::~Sensor()
{
}

unsigned char Sensor::getSensorTypeSource() const
{
    return _sensorTypeSource;
}

void Sensor::setSensorTypeSource(unsigned char pX)
{
    _sensorTypeSource = pX;
}

unsigned char Sensor::getSensorOnOffStatus() const
{
    return _sensorOnOffStatus;
}

void Sensor::setSensorOnOffStatus(unsigned char pX)
{
    _sensorOnOffStatus = pX;
}

unsigned short Sensor::getSensorType() const
{
    return _sensorType;
}

void Sensor::setSensorType(unsigned short pX)
{
    _sensorType = pX;
}

unsigned int Sensor::getStation() const
{
    return _station;
}

void Sensor::setStation(unsigned int pX)
{
    _station = pX;
}

unsigned short Sensor::getQuantity() const
{
    return _quantity;
}

void Sensor::setQuantity(unsigned short pX)
{
    _quantity = pX;
}

unsigned short Sensor::getPadding() const
{
    return _padding;
}

void Sensor::setPadding(unsigned short pX)
{
    _padding = pX;
}

void Sensor::marshal(DataStream& dataStream) const
{
    dataStream << _sensorTypeSource;
    dataStream << _sensorOnOffStatus;
    dataStream << _sensorType;
    dataStream << _station;
    dataStream << _quantity;
    dataStream << _padding;
}

void Sensor::unmarshal(DataStream& dataStream)
{
    dataStream >> _sensorTypeSource;
    dataStream >> _sensorOnOffStatus;
    dataStream >> _sensorType;
    dataStream >> _station;
    dataStream >> _quantity;
    dataStream >> _padding;
}


bool Sensor::operator ==(const Sensor& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_sensorTypeSource == rhs._sensorTypeSource) ) ivarsEqual = false;
     if( ! (_sensorOnOffStatus == rhs._sensorOnOffStatus) ) ivarsEqual = false;
     if( ! (_sensorType == rhs._sensorType) ) ivarsEqual = false;
     if( ! (_station == rhs._station) ) ivarsEqual = false;
     if( ! (_quantity == rhs._quantity) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int Sensor::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _sensorTypeSource
   marshalSize = marshalSize + 1;  // _sensorOnOffStatus
   marshalSize = marshalSize + 2;  // _sensorType
   marshalSize = marshalSize + 4;  // _station
   marshalSize = marshalSize + 2;  // _quantity
   marshalSize = marshalSize + 2;  // _padding
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
