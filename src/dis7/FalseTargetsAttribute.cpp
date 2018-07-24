#include <DIS/FalseTargetsAttribute.h> 

using namespace DIS;


FalseTargetsAttribute::FalseTargetsAttribute():
   _recordType(3502), 
   _recordLength(40), 
   _padding(0), 
   _emitterNumber(0), 
   _beamNumber(0), 
   _stateIndicator(0), 
   _padding2(0), 
   _falseTargetCount(0.0), 
   _walkSpeed(0.0), 
   _walkAcceleration(0.0), 
   _maximumWalkDistance(0.0), 
   _keepTime(0.0), 
   _echoSpacing(0.0), 
   _padding3(0)
{
}

FalseTargetsAttribute::~FalseTargetsAttribute()
{
}

unsigned int FalseTargetsAttribute::getRecordType() const
{
    return _recordType;
}

void FalseTargetsAttribute::setRecordType(unsigned int pX)
{
    _recordType = pX;
}

unsigned short FalseTargetsAttribute::getRecordLength() const
{
    return _recordLength;
}

void FalseTargetsAttribute::setRecordLength(unsigned short pX)
{
    _recordLength = pX;
}

unsigned short FalseTargetsAttribute::getPadding() const
{
    return _padding;
}

void FalseTargetsAttribute::setPadding(unsigned short pX)
{
    _padding = pX;
}

unsigned char FalseTargetsAttribute::getEmitterNumber() const
{
    return _emitterNumber;
}

void FalseTargetsAttribute::setEmitterNumber(unsigned char pX)
{
    _emitterNumber = pX;
}

unsigned char FalseTargetsAttribute::getBeamNumber() const
{
    return _beamNumber;
}

void FalseTargetsAttribute::setBeamNumber(unsigned char pX)
{
    _beamNumber = pX;
}

unsigned char FalseTargetsAttribute::getStateIndicator() const
{
    return _stateIndicator;
}

void FalseTargetsAttribute::setStateIndicator(unsigned char pX)
{
    _stateIndicator = pX;
}

unsigned char FalseTargetsAttribute::getPadding2() const
{
    return _padding2;
}

void FalseTargetsAttribute::setPadding2(unsigned char pX)
{
    _padding2 = pX;
}

float FalseTargetsAttribute::getFalseTargetCount() const
{
    return _falseTargetCount;
}

void FalseTargetsAttribute::setFalseTargetCount(float pX)
{
    _falseTargetCount = pX;
}

float FalseTargetsAttribute::getWalkSpeed() const
{
    return _walkSpeed;
}

void FalseTargetsAttribute::setWalkSpeed(float pX)
{
    _walkSpeed = pX;
}

float FalseTargetsAttribute::getWalkAcceleration() const
{
    return _walkAcceleration;
}

void FalseTargetsAttribute::setWalkAcceleration(float pX)
{
    _walkAcceleration = pX;
}

float FalseTargetsAttribute::getMaximumWalkDistance() const
{
    return _maximumWalkDistance;
}

void FalseTargetsAttribute::setMaximumWalkDistance(float pX)
{
    _maximumWalkDistance = pX;
}

float FalseTargetsAttribute::getKeepTime() const
{
    return _keepTime;
}

void FalseTargetsAttribute::setKeepTime(float pX)
{
    _keepTime = pX;
}

float FalseTargetsAttribute::getEchoSpacing() const
{
    return _echoSpacing;
}

void FalseTargetsAttribute::setEchoSpacing(float pX)
{
    _echoSpacing = pX;
}

unsigned int FalseTargetsAttribute::getPadding3() const
{
    return _padding3;
}

void FalseTargetsAttribute::setPadding3(unsigned int pX)
{
    _padding3 = pX;
}

void FalseTargetsAttribute::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _recordLength;
    dataStream << _padding;
    dataStream << _emitterNumber;
    dataStream << _beamNumber;
    dataStream << _stateIndicator;
    dataStream << _padding2;
    dataStream << _falseTargetCount;
    dataStream << _walkSpeed;
    dataStream << _walkAcceleration;
    dataStream << _maximumWalkDistance;
    dataStream << _keepTime;
    dataStream << _echoSpacing;
    dataStream << _padding3;
}

void FalseTargetsAttribute::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _recordLength;
    dataStream >> _padding;
    dataStream >> _emitterNumber;
    dataStream >> _beamNumber;
    dataStream >> _stateIndicator;
    dataStream >> _padding2;
    dataStream >> _falseTargetCount;
    dataStream >> _walkSpeed;
    dataStream >> _walkAcceleration;
    dataStream >> _maximumWalkDistance;
    dataStream >> _keepTime;
    dataStream >> _echoSpacing;
    dataStream >> _padding3;
}


bool FalseTargetsAttribute::operator ==(const FalseTargetsAttribute& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_recordLength == rhs._recordLength) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;
     if( ! (_emitterNumber == rhs._emitterNumber) ) ivarsEqual = false;
     if( ! (_beamNumber == rhs._beamNumber) ) ivarsEqual = false;
     if( ! (_stateIndicator == rhs._stateIndicator) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;
     if( ! (_falseTargetCount == rhs._falseTargetCount) ) ivarsEqual = false;
     if( ! (_walkSpeed == rhs._walkSpeed) ) ivarsEqual = false;
     if( ! (_walkAcceleration == rhs._walkAcceleration) ) ivarsEqual = false;
     if( ! (_maximumWalkDistance == rhs._maximumWalkDistance) ) ivarsEqual = false;
     if( ! (_keepTime == rhs._keepTime) ) ivarsEqual = false;
     if( ! (_echoSpacing == rhs._echoSpacing) ) ivarsEqual = false;
     if( ! (_padding3 == rhs._padding3) ) ivarsEqual = false;

    return ivarsEqual;
 }

int FalseTargetsAttribute::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _recordType
   marshalSize = marshalSize + 2;  // _recordLength
   marshalSize = marshalSize + 2;  // _padding
   marshalSize = marshalSize + 1;  // _emitterNumber
   marshalSize = marshalSize + 1;  // _beamNumber
   marshalSize = marshalSize + 1;  // _stateIndicator
   marshalSize = marshalSize + 1;  // _padding2
   marshalSize = marshalSize + 4;  // _falseTargetCount
   marshalSize = marshalSize + 4;  // _walkSpeed
   marshalSize = marshalSize + 4;  // _walkAcceleration
   marshalSize = marshalSize + 4;  // _maximumWalkDistance
   marshalSize = marshalSize + 4;  // _keepTime
   marshalSize = marshalSize + 4;  // _echoSpacing
   marshalSize = marshalSize + 4;  // _padding3
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
