#include <DIS/ModulationType.h> 

using namespace DIS;


ModulationType::ModulationType():
   _spreadSpectrum(0), 
   _majorModulation(0), 
   _detail(0), 
   _radioSystem(0)
{
}

ModulationType::~ModulationType()
{
}

unsigned short ModulationType::getSpreadSpectrum() const
{
    return _spreadSpectrum;
}

void ModulationType::setSpreadSpectrum(unsigned short pX)
{
    _spreadSpectrum = pX;
}

unsigned short ModulationType::getMajorModulation() const
{
    return _majorModulation;
}

void ModulationType::setMajorModulation(unsigned short pX)
{
    _majorModulation = pX;
}

unsigned short ModulationType::getDetail() const
{
    return _detail;
}

void ModulationType::setDetail(unsigned short pX)
{
    _detail = pX;
}

unsigned short ModulationType::getRadioSystem() const
{
    return _radioSystem;
}

void ModulationType::setRadioSystem(unsigned short pX)
{
    _radioSystem = pX;
}

void ModulationType::marshal(DataStream& dataStream) const
{
    dataStream << _spreadSpectrum;
    dataStream << _majorModulation;
    dataStream << _detail;
    dataStream << _radioSystem;
}

void ModulationType::unmarshal(DataStream& dataStream)
{
    dataStream >> _spreadSpectrum;
    dataStream >> _majorModulation;
    dataStream >> _detail;
    dataStream >> _radioSystem;
}


bool ModulationType::operator ==(const ModulationType& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_spreadSpectrum == rhs._spreadSpectrum) ) ivarsEqual = false;
     if( ! (_majorModulation == rhs._majorModulation) ) ivarsEqual = false;
     if( ! (_detail == rhs._detail) ) ivarsEqual = false;
     if( ! (_radioSystem == rhs._radioSystem) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ModulationType::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _spreadSpectrum
   marshalSize = marshalSize + 2;  // _majorModulation
   marshalSize = marshalSize + 2;  // _detail
   marshalSize = marshalSize + 2;  // _radioSystem
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
