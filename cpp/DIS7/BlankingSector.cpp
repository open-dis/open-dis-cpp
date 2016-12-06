#include <DIS/BlankingSector.h> 

using namespace DIS;


BlankingSector::BlankingSector():
   _recordType(3500), 
   _recordLength(0), 
   _emitterNumber(0), 
   _beamNumber(0), 
   _stateIndicator(0), 
   _leftAzimuth(0.0), 
   _rightAzimuth(0.0), 
   _lowerElevation(0.0), 
   _upperElevation(0.0), 
   _residualPower(0.0)
{
}

BlankingSector::~BlankingSector()
{
}

unsigned int BlankingSector::getRecordType() const
{
    return _recordType;
}

void BlankingSector::setRecordType(unsigned int pX)
{
    _recordType = pX;
}

unsigned short BlankingSector::getRecordLength() const
{
    return _recordLength;
}

void BlankingSector::setRecordLength(unsigned short pX)
{
    _recordLength = pX;
}

unsigned char BlankingSector::getEmitterNumber() const
{
    return _emitterNumber;
}

void BlankingSector::setEmitterNumber(unsigned char pX)
{
    _emitterNumber = pX;
}

unsigned char BlankingSector::getBeamNumber() const
{
    return _beamNumber;
}

void BlankingSector::setBeamNumber(unsigned char pX)
{
    _beamNumber = pX;
}

unsigned char BlankingSector::getStateIndicator() const
{
    return _stateIndicator;
}

void BlankingSector::setStateIndicator(unsigned char pX)
{
    _stateIndicator = pX;
}

float BlankingSector::getLeftAzimuth() const
{
    return _leftAzimuth;
}

void BlankingSector::setLeftAzimuth(float pX)
{
    _leftAzimuth = pX;
}

float BlankingSector::getRightAzimuth() const
{
    return _rightAzimuth;
}

void BlankingSector::setRightAzimuth(float pX)
{
    _rightAzimuth = pX;
}

float BlankingSector::getLowerElevation() const
{
    return _lowerElevation;
}

void BlankingSector::setLowerElevation(float pX)
{
    _lowerElevation = pX;
}

float BlankingSector::getUpperElevation() const
{
    return _upperElevation;
}

void BlankingSector::setUpperElevation(float pX)
{
    _upperElevation = pX;
}

float BlankingSector::getResidualPower() const
{
    return _residualPower;
}

void BlankingSector::setResidualPower(float pX)
{
    _residualPower = pX;
}

void BlankingSector::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _recordLength;
    dataStream << _emitterNumber;
    dataStream << _beamNumber;
    dataStream << _stateIndicator;
    dataStream << _leftAzimuth;
    dataStream << _rightAzimuth;
    dataStream << _lowerElevation;
    dataStream << _upperElevation;
    dataStream << _residualPower;
}

void BlankingSector::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _recordLength;
    dataStream >> _emitterNumber;
    dataStream >> _beamNumber;
    dataStream >> _stateIndicator;
    dataStream >> _leftAzimuth;
    dataStream >> _rightAzimuth;
    dataStream >> _lowerElevation;
    dataStream >> _upperElevation;
    dataStream >> _residualPower;
}


bool BlankingSector::operator ==(const BlankingSector& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_recordLength == rhs._recordLength) ) ivarsEqual = false;
     if( ! (_emitterNumber == rhs._emitterNumber) ) ivarsEqual = false;
     if( ! (_beamNumber == rhs._beamNumber) ) ivarsEqual = false;
     if( ! (_stateIndicator == rhs._stateIndicator) ) ivarsEqual = false;
     if( ! (_leftAzimuth == rhs._leftAzimuth) ) ivarsEqual = false;
     if( ! (_rightAzimuth == rhs._rightAzimuth) ) ivarsEqual = false;
     if( ! (_lowerElevation == rhs._lowerElevation) ) ivarsEqual = false;
     if( ! (_upperElevation == rhs._upperElevation) ) ivarsEqual = false;
     if( ! (_residualPower == rhs._residualPower) ) ivarsEqual = false;

    return ivarsEqual;
 }

int BlankingSector::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _recordType
   marshalSize = marshalSize + 2;  // _recordLength
   marshalSize = marshalSize + 1;  // _emitterNumber
   marshalSize = marshalSize + 1;  // _beamNumber
   marshalSize = marshalSize + 1;  // _stateIndicator
   marshalSize = marshalSize + 4;  // _leftAzimuth
   marshalSize = marshalSize + 4;  // _rightAzimuth
   marshalSize = marshalSize + 4;  // _lowerElevation
   marshalSize = marshalSize + 4;  // _upperElevation
   marshalSize = marshalSize + 4;  // _residualPower
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
