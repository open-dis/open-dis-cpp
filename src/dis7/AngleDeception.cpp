#include <DIS/AngleDeception.h> 

using namespace DIS;


AngleDeception::AngleDeception():
   _recordType(3501), 
   _recordLength(48), 
   _padding(0), 
   _emitterNumber(0), 
   _beamNumber(0), 
   _stateIndicator(0), 
   _padding2(0), 
   _azimuthOffset(0.0), 
   _azimuthWidth(0.0), 
   _azimuthPullRate(0.0), 
   _azimuthPullAcceleration(0.0), 
   _elevationOffset(0.0), 
   _elevationWidth(0.0), 
   _elevationPullRate(0.0), 
   _elevationPullAcceleration(0.0), 
   _padding3(0)
{
}

AngleDeception::~AngleDeception()
{
}

unsigned int AngleDeception::getRecordType() const
{
    return _recordType;
}

void AngleDeception::setRecordType(unsigned int pX)
{
    _recordType = pX;
}

unsigned short AngleDeception::getRecordLength() const
{
    return _recordLength;
}

void AngleDeception::setRecordLength(unsigned short pX)
{
    _recordLength = pX;
}

unsigned short AngleDeception::getPadding() const
{
    return _padding;
}

void AngleDeception::setPadding(unsigned short pX)
{
    _padding = pX;
}

unsigned char AngleDeception::getEmitterNumber() const
{
    return _emitterNumber;
}

void AngleDeception::setEmitterNumber(unsigned char pX)
{
    _emitterNumber = pX;
}

unsigned char AngleDeception::getBeamNumber() const
{
    return _beamNumber;
}

void AngleDeception::setBeamNumber(unsigned char pX)
{
    _beamNumber = pX;
}

unsigned char AngleDeception::getStateIndicator() const
{
    return _stateIndicator;
}

void AngleDeception::setStateIndicator(unsigned char pX)
{
    _stateIndicator = pX;
}

unsigned int AngleDeception::getPadding2() const
{
    return _padding2;
}

void AngleDeception::setPadding2(unsigned int pX)
{
    _padding2 = pX;
}

float AngleDeception::getAzimuthOffset() const
{
    return _azimuthOffset;
}

void AngleDeception::setAzimuthOffset(float pX)
{
    _azimuthOffset = pX;
}

float AngleDeception::getAzimuthWidth() const
{
    return _azimuthWidth;
}

void AngleDeception::setAzimuthWidth(float pX)
{
    _azimuthWidth = pX;
}

float AngleDeception::getAzimuthPullRate() const
{
    return _azimuthPullRate;
}

void AngleDeception::setAzimuthPullRate(float pX)
{
    _azimuthPullRate = pX;
}

float AngleDeception::getAzimuthPullAcceleration() const
{
    return _azimuthPullAcceleration;
}

void AngleDeception::setAzimuthPullAcceleration(float pX)
{
    _azimuthPullAcceleration = pX;
}

float AngleDeception::getElevationOffset() const
{
    return _elevationOffset;
}

void AngleDeception::setElevationOffset(float pX)
{
    _elevationOffset = pX;
}

float AngleDeception::getElevationWidth() const
{
    return _elevationWidth;
}

void AngleDeception::setElevationWidth(float pX)
{
    _elevationWidth = pX;
}

float AngleDeception::getElevationPullRate() const
{
    return _elevationPullRate;
}

void AngleDeception::setElevationPullRate(float pX)
{
    _elevationPullRate = pX;
}

float AngleDeception::getElevationPullAcceleration() const
{
    return _elevationPullAcceleration;
}

void AngleDeception::setElevationPullAcceleration(float pX)
{
    _elevationPullAcceleration = pX;
}

unsigned int AngleDeception::getPadding3() const
{
    return _padding3;
}

void AngleDeception::setPadding3(unsigned int pX)
{
    _padding3 = pX;
}

void AngleDeception::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _recordLength;
    dataStream << _padding;
    dataStream << _emitterNumber;
    dataStream << _beamNumber;
    dataStream << _stateIndicator;
    dataStream << _padding2;
    dataStream << _azimuthOffset;
    dataStream << _azimuthWidth;
    dataStream << _azimuthPullRate;
    dataStream << _azimuthPullAcceleration;
    dataStream << _elevationOffset;
    dataStream << _elevationWidth;
    dataStream << _elevationPullRate;
    dataStream << _elevationPullAcceleration;
    dataStream << _padding3;
}

void AngleDeception::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _recordLength;
    dataStream >> _padding;
    dataStream >> _emitterNumber;
    dataStream >> _beamNumber;
    dataStream >> _stateIndicator;
    dataStream >> _padding2;
    dataStream >> _azimuthOffset;
    dataStream >> _azimuthWidth;
    dataStream >> _azimuthPullRate;
    dataStream >> _azimuthPullAcceleration;
    dataStream >> _elevationOffset;
    dataStream >> _elevationWidth;
    dataStream >> _elevationPullRate;
    dataStream >> _elevationPullAcceleration;
    dataStream >> _padding3;
}


bool AngleDeception::operator ==(const AngleDeception& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_recordLength == rhs._recordLength) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;
     if( ! (_emitterNumber == rhs._emitterNumber) ) ivarsEqual = false;
     if( ! (_beamNumber == rhs._beamNumber) ) ivarsEqual = false;
     if( ! (_stateIndicator == rhs._stateIndicator) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;
     if( ! (_azimuthOffset == rhs._azimuthOffset) ) ivarsEqual = false;
     if( ! (_azimuthWidth == rhs._azimuthWidth) ) ivarsEqual = false;
     if( ! (_azimuthPullRate == rhs._azimuthPullRate) ) ivarsEqual = false;
     if( ! (_azimuthPullAcceleration == rhs._azimuthPullAcceleration) ) ivarsEqual = false;
     if( ! (_elevationOffset == rhs._elevationOffset) ) ivarsEqual = false;
     if( ! (_elevationWidth == rhs._elevationWidth) ) ivarsEqual = false;
     if( ! (_elevationPullRate == rhs._elevationPullRate) ) ivarsEqual = false;
     if( ! (_elevationPullAcceleration == rhs._elevationPullAcceleration) ) ivarsEqual = false;
     if( ! (_padding3 == rhs._padding3) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AngleDeception::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _recordType
   marshalSize = marshalSize + 2;  // _recordLength
   marshalSize = marshalSize + 2;  // _padding
   marshalSize = marshalSize + 1;  // _emitterNumber
   marshalSize = marshalSize + 1;  // _beamNumber
   marshalSize = marshalSize + 1;  // _stateIndicator
   marshalSize = marshalSize + 4;  // _padding2
   marshalSize = marshalSize + 4;  // _azimuthOffset
   marshalSize = marshalSize + 4;  // _azimuthWidth
   marshalSize = marshalSize + 4;  // _azimuthPullRate
   marshalSize = marshalSize + 4;  // _azimuthPullAcceleration
   marshalSize = marshalSize + 4;  // _elevationOffset
   marshalSize = marshalSize + 4;  // _elevationWidth
   marshalSize = marshalSize + 4;  // _elevationPullRate
   marshalSize = marshalSize + 4;  // _elevationPullAcceleration
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
