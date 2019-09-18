#include <dis7/EnvironmentGeneral.h>

using namespace DIS;


EnvironmentGeneral::EnvironmentGeneral():
   _environmentType(0), 
   _length(0), 
   _index(0), 
   _padding1(0), 
   _geometry(0), 
   _padding2(0)
{
}

EnvironmentGeneral::~EnvironmentGeneral()
{
}

unsigned int EnvironmentGeneral::getEnvironmentType() const
{
    return _environmentType;
}

void EnvironmentGeneral::setEnvironmentType(unsigned int pX)
{
    _environmentType = pX;
}

uint8_t EnvironmentGeneral::getLength() const
{
    return _length;
}

void EnvironmentGeneral::setLength(uint8_t pX)
{
    _length = pX;
}

uint8_t EnvironmentGeneral::getIndex() const
{
    return _index;
}

void EnvironmentGeneral::setIndex(uint8_t pX)
{
    _index = pX;
}

uint8_t EnvironmentGeneral::getPadding1() const
{
    return _padding1;
}

void EnvironmentGeneral::setPadding1(uint8_t pX)
{
    _padding1 = pX;
}

uint8_t EnvironmentGeneral::getGeometry() const
{
    return _geometry;
}

void EnvironmentGeneral::setGeometry(uint8_t pX)
{
    _geometry = pX;
}

uint8_t EnvironmentGeneral::getPadding2() const
{
    return _padding2;
}

void EnvironmentGeneral::setPadding2(uint8_t pX)
{
    _padding2 = pX;
}

void EnvironmentGeneral::marshal(DataStream& dataStream) const
{
    dataStream << _environmentType;
    dataStream << _length;
    dataStream << _index;
    dataStream << _padding1;
    dataStream << _geometry;
    dataStream << _padding2;
}

void EnvironmentGeneral::unmarshal(DataStream& dataStream)
{
    dataStream >> _environmentType;
    dataStream >> _length;
    dataStream >> _index;
    dataStream >> _padding1;
    dataStream >> _geometry;
    dataStream >> _padding2;
}


bool EnvironmentGeneral::operator ==(const EnvironmentGeneral& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_environmentType == rhs._environmentType) ) ivarsEqual = false;
     if( ! (_length == rhs._length) ) ivarsEqual = false;
     if( ! (_index == rhs._index) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_geometry == rhs._geometry) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EnvironmentGeneral::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _environmentType
   marshalSize = marshalSize + 1;  // _length
   marshalSize = marshalSize + 1;  // _index
   marshalSize = marshalSize + 1;  // _padding1
   marshalSize = marshalSize + 1;  // _geometry
   marshalSize = marshalSize + 1;  // _padding2
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
