#include <DIS/FundamentalParameterDataIff.h> 

using namespace DIS;


FundamentalParameterDataIff::FundamentalParameterDataIff():
   _erp(0.0), 
   _frequency(0.0), 
   _pgrf(0.0), 
   _pulseWidth(0.0), 
   _burstLength(0), 
   _applicableModes(0), 
   _pad2(0), 
   _pad3(0)
{
}

FundamentalParameterDataIff::~FundamentalParameterDataIff()
{
}

float FundamentalParameterDataIff::getErp() const
{
    return _erp;
}

void FundamentalParameterDataIff::setErp(float pX)
{
    _erp = pX;
}

float FundamentalParameterDataIff::getFrequency() const
{
    return _frequency;
}

void FundamentalParameterDataIff::setFrequency(float pX)
{
    _frequency = pX;
}

float FundamentalParameterDataIff::getPgrf() const
{
    return _pgrf;
}

void FundamentalParameterDataIff::setPgrf(float pX)
{
    _pgrf = pX;
}

float FundamentalParameterDataIff::getPulseWidth() const
{
    return _pulseWidth;
}

void FundamentalParameterDataIff::setPulseWidth(float pX)
{
    _pulseWidth = pX;
}

unsigned int FundamentalParameterDataIff::getBurstLength() const
{
    return _burstLength;
}

void FundamentalParameterDataIff::setBurstLength(unsigned int pX)
{
    _burstLength = pX;
}

unsigned char FundamentalParameterDataIff::getApplicableModes() const
{
    return _applicableModes;
}

void FundamentalParameterDataIff::setApplicableModes(unsigned char pX)
{
    _applicableModes = pX;
}

unsigned short FundamentalParameterDataIff::getPad2() const
{
    return _pad2;
}

void FundamentalParameterDataIff::setPad2(unsigned short pX)
{
    _pad2 = pX;
}

unsigned char FundamentalParameterDataIff::getPad3() const
{
    return _pad3;
}

void FundamentalParameterDataIff::setPad3(unsigned char pX)
{
    _pad3 = pX;
}

void FundamentalParameterDataIff::marshal(DataStream& dataStream) const
{
    dataStream << _erp;
    dataStream << _frequency;
    dataStream << _pgrf;
    dataStream << _pulseWidth;
    dataStream << _burstLength;
    dataStream << _applicableModes;
    dataStream << _pad2;
    dataStream << _pad3;
}

void FundamentalParameterDataIff::unmarshal(DataStream& dataStream)
{
    dataStream >> _erp;
    dataStream >> _frequency;
    dataStream >> _pgrf;
    dataStream >> _pulseWidth;
    dataStream >> _burstLength;
    dataStream >> _applicableModes;
    dataStream >> _pad2;
    dataStream >> _pad3;
}


bool FundamentalParameterDataIff::operator ==(const FundamentalParameterDataIff& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_erp == rhs._erp) ) ivarsEqual = false;
     if( ! (_frequency == rhs._frequency) ) ivarsEqual = false;
     if( ! (_pgrf == rhs._pgrf) ) ivarsEqual = false;
     if( ! (_pulseWidth == rhs._pulseWidth) ) ivarsEqual = false;
     if( ! (_burstLength == rhs._burstLength) ) ivarsEqual = false;
     if( ! (_applicableModes == rhs._applicableModes) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_pad3 == rhs._pad3) ) ivarsEqual = false;

    return ivarsEqual;
 }

int FundamentalParameterDataIff::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _erp
   marshalSize = marshalSize + 4;  // _frequency
   marshalSize = marshalSize + 4;  // _pgrf
   marshalSize = marshalSize + 4;  // _pulseWidth
   marshalSize = marshalSize + 4;  // _burstLength
   marshalSize = marshalSize + 1;  // _applicableModes
   marshalSize = marshalSize + 2;  // _pad2
   marshalSize = marshalSize + 1;  // _pad3
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
