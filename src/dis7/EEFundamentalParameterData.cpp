#include <DIS/EEFundamentalParameterData.h> 

using namespace DIS;


EEFundamentalParameterData::EEFundamentalParameterData():
   _frequency(0.0), 
   _frequencyRange(0.0), 
   _effectiveRadiatedPower(0.0), 
   _pulseRepetitionFrequency(0.0), 
   _pulseWidth(0.0)
{
}

EEFundamentalParameterData::~EEFundamentalParameterData()
{
}

float EEFundamentalParameterData::getFrequency() const
{
    return _frequency;
}

void EEFundamentalParameterData::setFrequency(float pX)
{
    _frequency = pX;
}

float EEFundamentalParameterData::getFrequencyRange() const
{
    return _frequencyRange;
}

void EEFundamentalParameterData::setFrequencyRange(float pX)
{
    _frequencyRange = pX;
}

float EEFundamentalParameterData::getEffectiveRadiatedPower() const
{
    return _effectiveRadiatedPower;
}

void EEFundamentalParameterData::setEffectiveRadiatedPower(float pX)
{
    _effectiveRadiatedPower = pX;
}

float EEFundamentalParameterData::getPulseRepetitionFrequency() const
{
    return _pulseRepetitionFrequency;
}

void EEFundamentalParameterData::setPulseRepetitionFrequency(float pX)
{
    _pulseRepetitionFrequency = pX;
}

float EEFundamentalParameterData::getPulseWidth() const
{
    return _pulseWidth;
}

void EEFundamentalParameterData::setPulseWidth(float pX)
{
    _pulseWidth = pX;
}

void EEFundamentalParameterData::marshal(DataStream& dataStream) const
{
    dataStream << _frequency;
    dataStream << _frequencyRange;
    dataStream << _effectiveRadiatedPower;
    dataStream << _pulseRepetitionFrequency;
    dataStream << _pulseWidth;
}

void EEFundamentalParameterData::unmarshal(DataStream& dataStream)
{
    dataStream >> _frequency;
    dataStream >> _frequencyRange;
    dataStream >> _effectiveRadiatedPower;
    dataStream >> _pulseRepetitionFrequency;
    dataStream >> _pulseWidth;
}


bool EEFundamentalParameterData::operator ==(const EEFundamentalParameterData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_frequency == rhs._frequency) ) ivarsEqual = false;
     if( ! (_frequencyRange == rhs._frequencyRange) ) ivarsEqual = false;
     if( ! (_effectiveRadiatedPower == rhs._effectiveRadiatedPower) ) ivarsEqual = false;
     if( ! (_pulseRepetitionFrequency == rhs._pulseRepetitionFrequency) ) ivarsEqual = false;
     if( ! (_pulseWidth == rhs._pulseWidth) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EEFundamentalParameterData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _frequency
   marshalSize = marshalSize + 4;  // _frequencyRange
   marshalSize = marshalSize + 4;  // _effectiveRadiatedPower
   marshalSize = marshalSize + 4;  // _pulseRepetitionFrequency
   marshalSize = marshalSize + 4;  // _pulseWidth
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
