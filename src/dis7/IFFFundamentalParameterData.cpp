#include <DIS/IFFFundamentalParameterData.h> 

using namespace DIS;


IFFFundamentalParameterData::IFFFundamentalParameterData():
   _erp(0.0), 
   _frequency(0.0), 
   _pgrf(0.0), 
   _pulseWidth(0.0), 
   _burstLength(0), 
   _applicableModes(0)
{
     // Initialize fixed length array
     for(int lengthsystemSpecificData= 0; lengthsystemSpecificData < 3; lengthsystemSpecificData++)
     {
         _systemSpecificData[lengthsystemSpecificData] = 0;
     }

}

IFFFundamentalParameterData::~IFFFundamentalParameterData()
{
}

float IFFFundamentalParameterData::getErp() const
{
    return _erp;
}

void IFFFundamentalParameterData::setErp(float pX)
{
    _erp = pX;
}

float IFFFundamentalParameterData::getFrequency() const
{
    return _frequency;
}

void IFFFundamentalParameterData::setFrequency(float pX)
{
    _frequency = pX;
}

float IFFFundamentalParameterData::getPgrf() const
{
    return _pgrf;
}

void IFFFundamentalParameterData::setPgrf(float pX)
{
    _pgrf = pX;
}

float IFFFundamentalParameterData::getPulseWidth() const
{
    return _pulseWidth;
}

void IFFFundamentalParameterData::setPulseWidth(float pX)
{
    _pulseWidth = pX;
}

unsigned int IFFFundamentalParameterData::getBurstLength() const
{
    return _burstLength;
}

void IFFFundamentalParameterData::setBurstLength(unsigned int pX)
{
    _burstLength = pX;
}

unsigned char IFFFundamentalParameterData::getApplicableModes() const
{
    return _applicableModes;
}

void IFFFundamentalParameterData::setApplicableModes(unsigned char pX)
{
    _applicableModes = pX;
}

unsigned char* IFFFundamentalParameterData::getSystemSpecificData() 
{
    return _systemSpecificData;
}

const unsigned char* IFFFundamentalParameterData::getSystemSpecificData() const
{
    return _systemSpecificData;
}

void IFFFundamentalParameterData::setSystemSpecificData(const unsigned char* x)
{
   for(int i = 0; i < 3; i++)
   {
        _systemSpecificData[i] = x[i];
   }
}

void IFFFundamentalParameterData::marshal(DataStream& dataStream) const
{
    dataStream << _erp;
    dataStream << _frequency;
    dataStream << _pgrf;
    dataStream << _pulseWidth;
    dataStream << _burstLength;
    dataStream << _applicableModes;

     for(size_t idx = 0; idx < 3; idx++)
     {
        dataStream << _systemSpecificData[idx];
     }

}

void IFFFundamentalParameterData::unmarshal(DataStream& dataStream)
{
    dataStream >> _erp;
    dataStream >> _frequency;
    dataStream >> _pgrf;
    dataStream >> _pulseWidth;
    dataStream >> _burstLength;
    dataStream >> _applicableModes;

     for(size_t idx = 0; idx < 3; idx++)
     {
        dataStream >> _systemSpecificData[idx];
     }

}


bool IFFFundamentalParameterData::operator ==(const IFFFundamentalParameterData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_erp == rhs._erp) ) ivarsEqual = false;
     if( ! (_frequency == rhs._frequency) ) ivarsEqual = false;
     if( ! (_pgrf == rhs._pgrf) ) ivarsEqual = false;
     if( ! (_pulseWidth == rhs._pulseWidth) ) ivarsEqual = false;
     if( ! (_burstLength == rhs._burstLength) ) ivarsEqual = false;
     if( ! (_applicableModes == rhs._applicableModes) ) ivarsEqual = false;

     for(unsigned char idx = 0; idx < 3; idx++)
     {
          if(!(_systemSpecificData[idx] == rhs._systemSpecificData[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int IFFFundamentalParameterData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _erp
   marshalSize = marshalSize + 4;  // _frequency
   marshalSize = marshalSize + 4;  // _pgrf
   marshalSize = marshalSize + 4;  // _pulseWidth
   marshalSize = marshalSize + 4;  // _burstLength
   marshalSize = marshalSize + 1;  // _applicableModes
   marshalSize = marshalSize + 3 * 1;  // _systemSpecificData
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
