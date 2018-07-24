#include <DIS/Relationship.h> 

using namespace DIS;


Relationship::Relationship():
   _nature(0), 
   _position(0)
{
}

Relationship::~Relationship()
{
}

unsigned short Relationship::getNature() const
{
    return _nature;
}

void Relationship::setNature(unsigned short pX)
{
    _nature = pX;
}

unsigned short Relationship::getPosition() const
{
    return _position;
}

void Relationship::setPosition(unsigned short pX)
{
    _position = pX;
}

void Relationship::marshal(DataStream& dataStream) const
{
    dataStream << _nature;
    dataStream << _position;
}

void Relationship::unmarshal(DataStream& dataStream)
{
    dataStream >> _nature;
    dataStream >> _position;
}


bool Relationship::operator ==(const Relationship& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_nature == rhs._nature) ) ivarsEqual = false;
     if( ! (_position == rhs._position) ) ivarsEqual = false;

    return ivarsEqual;
 }

int Relationship::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _nature
   marshalSize = marshalSize + 2;  // _position
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
