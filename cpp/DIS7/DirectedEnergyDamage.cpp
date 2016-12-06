#include <DIS/DirectedEnergyDamage.h> 

using namespace DIS;


DirectedEnergyDamage::DirectedEnergyDamage():
   _recordType(4500), 
   _recordLength(40), 
   _padding(0), 
   _damageLocation(), 
   _damageDiameter(0.0), 
   _temperature(-273.15), 
   _componentIdentification(0), 
   _componentDamageStatus(0), 
   _componentVisualDamageStatus(0), 
   _componentVisualSmokeColor(0), 
   _fireEventID(), 
   _padding2(0)
{
}

DirectedEnergyDamage::~DirectedEnergyDamage()
{
}

unsigned int DirectedEnergyDamage::getRecordType() const
{
    return _recordType;
}

void DirectedEnergyDamage::setRecordType(unsigned int pX)
{
    _recordType = pX;
}

unsigned short DirectedEnergyDamage::getRecordLength() const
{
    return _recordLength;
}

void DirectedEnergyDamage::setRecordLength(unsigned short pX)
{
    _recordLength = pX;
}

unsigned short DirectedEnergyDamage::getPadding() const
{
    return _padding;
}

void DirectedEnergyDamage::setPadding(unsigned short pX)
{
    _padding = pX;
}

Vector3Float& DirectedEnergyDamage::getDamageLocation() 
{
    return _damageLocation;
}

const Vector3Float& DirectedEnergyDamage::getDamageLocation() const
{
    return _damageLocation;
}

void DirectedEnergyDamage::setDamageLocation(const Vector3Float &pX)
{
    _damageLocation = pX;
}

float DirectedEnergyDamage::getDamageDiameter() const
{
    return _damageDiameter;
}

void DirectedEnergyDamage::setDamageDiameter(float pX)
{
    _damageDiameter = pX;
}

float DirectedEnergyDamage::getTemperature() const
{
    return _temperature;
}

void DirectedEnergyDamage::setTemperature(float pX)
{
    _temperature = pX;
}

unsigned char DirectedEnergyDamage::getComponentIdentification() const
{
    return _componentIdentification;
}

void DirectedEnergyDamage::setComponentIdentification(unsigned char pX)
{
    _componentIdentification = pX;
}

unsigned char DirectedEnergyDamage::getComponentDamageStatus() const
{
    return _componentDamageStatus;
}

void DirectedEnergyDamage::setComponentDamageStatus(unsigned char pX)
{
    _componentDamageStatus = pX;
}

unsigned char DirectedEnergyDamage::getComponentVisualDamageStatus() const
{
    return _componentVisualDamageStatus;
}

void DirectedEnergyDamage::setComponentVisualDamageStatus(unsigned char pX)
{
    _componentVisualDamageStatus = pX;
}

unsigned char DirectedEnergyDamage::getComponentVisualSmokeColor() const
{
    return _componentVisualSmokeColor;
}

void DirectedEnergyDamage::setComponentVisualSmokeColor(unsigned char pX)
{
    _componentVisualSmokeColor = pX;
}

EventIdentifier& DirectedEnergyDamage::getFireEventID() 
{
    return _fireEventID;
}

const EventIdentifier& DirectedEnergyDamage::getFireEventID() const
{
    return _fireEventID;
}

void DirectedEnergyDamage::setFireEventID(const EventIdentifier &pX)
{
    _fireEventID = pX;
}

unsigned short DirectedEnergyDamage::getPadding2() const
{
    return _padding2;
}

void DirectedEnergyDamage::setPadding2(unsigned short pX)
{
    _padding2 = pX;
}

void DirectedEnergyDamage::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _recordLength;
    dataStream << _padding;
    _damageLocation.marshal(dataStream);
    dataStream << _damageDiameter;
    dataStream << _temperature;
    dataStream << _componentIdentification;
    dataStream << _componentDamageStatus;
    dataStream << _componentVisualDamageStatus;
    dataStream << _componentVisualSmokeColor;
    _fireEventID.marshal(dataStream);
    dataStream << _padding2;
}

void DirectedEnergyDamage::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _recordLength;
    dataStream >> _padding;
    _damageLocation.unmarshal(dataStream);
    dataStream >> _damageDiameter;
    dataStream >> _temperature;
    dataStream >> _componentIdentification;
    dataStream >> _componentDamageStatus;
    dataStream >> _componentVisualDamageStatus;
    dataStream >> _componentVisualSmokeColor;
    _fireEventID.unmarshal(dataStream);
    dataStream >> _padding2;
}


bool DirectedEnergyDamage::operator ==(const DirectedEnergyDamage& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_recordLength == rhs._recordLength) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;
     if( ! (_damageLocation == rhs._damageLocation) ) ivarsEqual = false;
     if( ! (_damageDiameter == rhs._damageDiameter) ) ivarsEqual = false;
     if( ! (_temperature == rhs._temperature) ) ivarsEqual = false;
     if( ! (_componentIdentification == rhs._componentIdentification) ) ivarsEqual = false;
     if( ! (_componentDamageStatus == rhs._componentDamageStatus) ) ivarsEqual = false;
     if( ! (_componentVisualDamageStatus == rhs._componentVisualDamageStatus) ) ivarsEqual = false;
     if( ! (_componentVisualSmokeColor == rhs._componentVisualSmokeColor) ) ivarsEqual = false;
     if( ! (_fireEventID == rhs._fireEventID) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DirectedEnergyDamage::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _recordType
   marshalSize = marshalSize + 2;  // _recordLength
   marshalSize = marshalSize + 2;  // _padding
   marshalSize = marshalSize + _damageLocation.getMarshalledSize();  // _damageLocation
   marshalSize = marshalSize + 4;  // _damageDiameter
   marshalSize = marshalSize + 4;  // _temperature
   marshalSize = marshalSize + 1;  // _componentIdentification
   marshalSize = marshalSize + 1;  // _componentDamageStatus
   marshalSize = marshalSize + 1;  // _componentVisualDamageStatus
   marshalSize = marshalSize + 1;  // _componentVisualSmokeColor
   marshalSize = marshalSize + _fireEventID.getMarshalledSize();  // _fireEventID
   marshalSize = marshalSize + 2;  // _padding2
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
