#include <DIS/DirectedEnergyFirePdu.h> 

using namespace DIS;


DirectedEnergyFirePdu::DirectedEnergyFirePdu() : WarfareFamilyPdu(),
   _munitionType(), 
   _shotStartTime(), 
   _commulativeShotTime(0.0), 
   _ApertureEmitterLocation(), 
   _apertureDiameter(0.0), 
   _wavelength(0.0), 
   _peakIrradiance(0.0), 
   _pulseRepetitionFrequency(0.0), 
   _pulseWidth(0), 
   _flags(0), 
   _pulseShape(0), 
   _padding1(0), 
   _padding2(0), 
   _padding3(0), 
   _numberOfDERecords(0)
{
    setPduType( 68 );
}

DirectedEnergyFirePdu::~DirectedEnergyFirePdu()
{
    _dERecords.clear();
}

EntityType& DirectedEnergyFirePdu::getMunitionType() 
{
    return _munitionType;
}

const EntityType& DirectedEnergyFirePdu::getMunitionType() const
{
    return _munitionType;
}

void DirectedEnergyFirePdu::setMunitionType(const EntityType &pX)
{
    _munitionType = pX;
}

ClockTime& DirectedEnergyFirePdu::getShotStartTime() 
{
    return _shotStartTime;
}

const ClockTime& DirectedEnergyFirePdu::getShotStartTime() const
{
    return _shotStartTime;
}

void DirectedEnergyFirePdu::setShotStartTime(const ClockTime &pX)
{
    _shotStartTime = pX;
}

float DirectedEnergyFirePdu::getCommulativeShotTime() const
{
    return _commulativeShotTime;
}

void DirectedEnergyFirePdu::setCommulativeShotTime(float pX)
{
    _commulativeShotTime = pX;
}

Vector3Float& DirectedEnergyFirePdu::getApertureEmitterLocation() 
{
    return _ApertureEmitterLocation;
}

const Vector3Float& DirectedEnergyFirePdu::getApertureEmitterLocation() const
{
    return _ApertureEmitterLocation;
}

void DirectedEnergyFirePdu::setApertureEmitterLocation(const Vector3Float &pX)
{
    _ApertureEmitterLocation = pX;
}

float DirectedEnergyFirePdu::getApertureDiameter() const
{
    return _apertureDiameter;
}

void DirectedEnergyFirePdu::setApertureDiameter(float pX)
{
    _apertureDiameter = pX;
}

float DirectedEnergyFirePdu::getWavelength() const
{
    return _wavelength;
}

void DirectedEnergyFirePdu::setWavelength(float pX)
{
    _wavelength = pX;
}

float DirectedEnergyFirePdu::getPeakIrradiance() const
{
    return _peakIrradiance;
}

void DirectedEnergyFirePdu::setPeakIrradiance(float pX)
{
    _peakIrradiance = pX;
}

float DirectedEnergyFirePdu::getPulseRepetitionFrequency() const
{
    return _pulseRepetitionFrequency;
}

void DirectedEnergyFirePdu::setPulseRepetitionFrequency(float pX)
{
    _pulseRepetitionFrequency = pX;
}

int DirectedEnergyFirePdu::getPulseWidth() const
{
    return _pulseWidth;
}

void DirectedEnergyFirePdu::setPulseWidth(int pX)
{
    _pulseWidth = pX;
}

int DirectedEnergyFirePdu::getFlags() const
{
    return _flags;
}

void DirectedEnergyFirePdu::setFlags(int pX)
{
    _flags = pX;
}

char DirectedEnergyFirePdu::getPulseShape() const
{
    return _pulseShape;
}

void DirectedEnergyFirePdu::setPulseShape(char pX)
{
    _pulseShape = pX;
}

unsigned char DirectedEnergyFirePdu::getPadding1() const
{
    return _padding1;
}

void DirectedEnergyFirePdu::setPadding1(unsigned char pX)
{
    _padding1 = pX;
}

unsigned int DirectedEnergyFirePdu::getPadding2() const
{
    return _padding2;
}

void DirectedEnergyFirePdu::setPadding2(unsigned int pX)
{
    _padding2 = pX;
}

unsigned short DirectedEnergyFirePdu::getPadding3() const
{
    return _padding3;
}

void DirectedEnergyFirePdu::setPadding3(unsigned short pX)
{
    _padding3 = pX;
}

unsigned short DirectedEnergyFirePdu::getNumberOfDERecords() const
{
   return _dERecords.size();
}

std::vector<StandardVariableSpecification>& DirectedEnergyFirePdu::getDERecords() 
{
    return _dERecords;
}

const std::vector<StandardVariableSpecification>& DirectedEnergyFirePdu::getDERecords() const
{
    return _dERecords;
}

void DirectedEnergyFirePdu::setDERecords(const std::vector<StandardVariableSpecification>& pX)
{
     _dERecords = pX;
}

void DirectedEnergyFirePdu::marshal(DataStream& dataStream) const
{
    WarfareFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _munitionType.marshal(dataStream);
    _shotStartTime.marshal(dataStream);
    dataStream << _commulativeShotTime;
    _ApertureEmitterLocation.marshal(dataStream);
    dataStream << _apertureDiameter;
    dataStream << _wavelength;
    dataStream << _peakIrradiance;
    dataStream << _pulseRepetitionFrequency;
    dataStream << _pulseWidth;
    dataStream << _flags;
    dataStream << _pulseShape;
    dataStream << _padding1;
    dataStream << _padding2;
    dataStream << _padding3;
    dataStream << ( unsigned short )_dERecords.size();

     for(size_t idx = 0; idx < _dERecords.size(); idx++)
     {
        StandardVariableSpecification x = _dERecords[idx];
        x.marshal(dataStream);
     }

}

void DirectedEnergyFirePdu::unmarshal(DataStream& dataStream)
{
    WarfareFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _munitionType.unmarshal(dataStream);
    _shotStartTime.unmarshal(dataStream);
    dataStream >> _commulativeShotTime;
    _ApertureEmitterLocation.unmarshal(dataStream);
    dataStream >> _apertureDiameter;
    dataStream >> _wavelength;
    dataStream >> _peakIrradiance;
    dataStream >> _pulseRepetitionFrequency;
    dataStream >> _pulseWidth;
    dataStream >> _flags;
    dataStream >> _pulseShape;
    dataStream >> _padding1;
    dataStream >> _padding2;
    dataStream >> _padding3;
    dataStream >> _numberOfDERecords;

     _dERecords.clear();
     for(size_t idx = 0; idx < _numberOfDERecords; idx++)
     {
        StandardVariableSpecification x;
        x.unmarshal(dataStream);
        _dERecords.push_back(x);
     }
}


bool DirectedEnergyFirePdu::operator ==(const DirectedEnergyFirePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = WarfareFamilyPdu::operator==(rhs);

     if( ! (_munitionType == rhs._munitionType) ) ivarsEqual = false;
     if( ! (_shotStartTime == rhs._shotStartTime) ) ivarsEqual = false;
     if( ! (_commulativeShotTime == rhs._commulativeShotTime) ) ivarsEqual = false;
     if( ! (_ApertureEmitterLocation == rhs._ApertureEmitterLocation) ) ivarsEqual = false;
     if( ! (_apertureDiameter == rhs._apertureDiameter) ) ivarsEqual = false;
     if( ! (_wavelength == rhs._wavelength) ) ivarsEqual = false;
     if( ! (_peakIrradiance == rhs._peakIrradiance) ) ivarsEqual = false;
     if( ! (_pulseRepetitionFrequency == rhs._pulseRepetitionFrequency) ) ivarsEqual = false;
     if( ! (_pulseWidth == rhs._pulseWidth) ) ivarsEqual = false;
     if( ! (_flags == rhs._flags) ) ivarsEqual = false;
     if( ! (_pulseShape == rhs._pulseShape) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;
     if( ! (_padding3 == rhs._padding3) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _dERecords.size(); idx++)
     {
        if( ! ( _dERecords[idx] == rhs._dERecords[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int DirectedEnergyFirePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = WarfareFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _munitionType.getMarshalledSize();  // _munitionType
   marshalSize = marshalSize + _shotStartTime.getMarshalledSize();  // _shotStartTime
   marshalSize = marshalSize + 4;  // _commulativeShotTime
   marshalSize = marshalSize + _ApertureEmitterLocation.getMarshalledSize();  // _ApertureEmitterLocation
   marshalSize = marshalSize + 4;  // _apertureDiameter
   marshalSize = marshalSize + 4;  // _wavelength
   marshalSize = marshalSize + 4;  // _peakIrradiance
   marshalSize = marshalSize + 4;  // _pulseRepetitionFrequency
   marshalSize = marshalSize + 4;  // _pulseWidth
   marshalSize = marshalSize + 4;  // _flags
   marshalSize = marshalSize + 1;  // _pulseShape
   marshalSize = marshalSize + 1;  // _padding1
   marshalSize = marshalSize + 4;  // _padding2
   marshalSize = marshalSize + 2;  // _padding3
   marshalSize = marshalSize + 2;  // _numberOfDERecords

   for(int idx=0; idx < _dERecords.size(); idx++)
   {
        StandardVariableSpecification listElement = _dERecords[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

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
