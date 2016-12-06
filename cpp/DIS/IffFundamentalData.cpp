#include <DIS/IffFundamentalData.h> 

using namespace DIS;


IffFundamentalData::IffFundamentalData():
   _systemStatus(0), 
   _alternateParameter4(0), 
   _informationLayers(0), 
   _modifier(0), 
   _parameter1(0), 
   _parameter2(0), 
   _parameter3(0), 
   _parameter4(0), 
   _parameter5(0), 
   _parameter6(0)
{
}

IffFundamentalData::~IffFundamentalData()
{
}

unsigned char IffFundamentalData::getSystemStatus() const
{
    return _systemStatus;
}

void IffFundamentalData::setSystemStatus(unsigned char pX)
{
    _systemStatus = pX;
}

unsigned char IffFundamentalData::getAlternateParameter4() const
{
    return _alternateParameter4;
}

void IffFundamentalData::setAlternateParameter4(unsigned char pX)
{
    _alternateParameter4 = pX;
}

unsigned char IffFundamentalData::getInformationLayers() const
{
    return _informationLayers;
}

void IffFundamentalData::setInformationLayers(unsigned char pX)
{
    _informationLayers = pX;
}

unsigned char IffFundamentalData::getModifier() const
{
    return _modifier;
}

void IffFundamentalData::setModifier(unsigned char pX)
{
    _modifier = pX;
}

unsigned short IffFundamentalData::getParameter1() const
{
    return _parameter1;
}

void IffFundamentalData::setParameter1(unsigned short pX)
{
    _parameter1 = pX;
}

unsigned short IffFundamentalData::getParameter2() const
{
    return _parameter2;
}

void IffFundamentalData::setParameter2(unsigned short pX)
{
    _parameter2 = pX;
}

unsigned short IffFundamentalData::getParameter3() const
{
    return _parameter3;
}

void IffFundamentalData::setParameter3(unsigned short pX)
{
    _parameter3 = pX;
}

unsigned short IffFundamentalData::getParameter4() const
{
    return _parameter4;
}

void IffFundamentalData::setParameter4(unsigned short pX)
{
    _parameter4 = pX;
}

unsigned short IffFundamentalData::getParameter5() const
{
    return _parameter5;
}

void IffFundamentalData::setParameter5(unsigned short pX)
{
    _parameter5 = pX;
}

unsigned short IffFundamentalData::getParameter6() const
{
    return _parameter6;
}

void IffFundamentalData::setParameter6(unsigned short pX)
{
    _parameter6 = pX;
}

void IffFundamentalData::marshal(DataStream& dataStream) const
{
    dataStream << _systemStatus;
    dataStream << _alternateParameter4;
    dataStream << _informationLayers;
    dataStream << _modifier;
    dataStream << _parameter1;
    dataStream << _parameter2;
    dataStream << _parameter3;
    dataStream << _parameter4;
    dataStream << _parameter5;
    dataStream << _parameter6;
}

void IffFundamentalData::unmarshal(DataStream& dataStream)
{
    dataStream >> _systemStatus;
    dataStream >> _alternateParameter4;
    dataStream >> _informationLayers;
    dataStream >> _modifier;
    dataStream >> _parameter1;
    dataStream >> _parameter2;
    dataStream >> _parameter3;
    dataStream >> _parameter4;
    dataStream >> _parameter5;
    dataStream >> _parameter6;
}


bool IffFundamentalData::operator ==(const IffFundamentalData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_systemStatus == rhs._systemStatus) ) ivarsEqual = false;
     if( ! (_alternateParameter4 == rhs._alternateParameter4) ) ivarsEqual = false;
     if( ! (_informationLayers == rhs._informationLayers) ) ivarsEqual = false;
     if( ! (_modifier == rhs._modifier) ) ivarsEqual = false;
     if( ! (_parameter1 == rhs._parameter1) ) ivarsEqual = false;
     if( ! (_parameter2 == rhs._parameter2) ) ivarsEqual = false;
     if( ! (_parameter3 == rhs._parameter3) ) ivarsEqual = false;
     if( ! (_parameter4 == rhs._parameter4) ) ivarsEqual = false;
     if( ! (_parameter5 == rhs._parameter5) ) ivarsEqual = false;
     if( ! (_parameter6 == rhs._parameter6) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IffFundamentalData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _systemStatus
   marshalSize = marshalSize + 1;  // _alternateParameter4
   marshalSize = marshalSize + 1;  // _informationLayers
   marshalSize = marshalSize + 1;  // _modifier
   marshalSize = marshalSize + 2;  // _parameter1
   marshalSize = marshalSize + 2;  // _parameter2
   marshalSize = marshalSize + 2;  // _parameter3
   marshalSize = marshalSize + 2;  // _parameter4
   marshalSize = marshalSize + 2;  // _parameter5
   marshalSize = marshalSize + 2;  // _parameter6
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
