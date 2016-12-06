#include <DIS/JammingTechnique.h> 

using namespace DIS;


JammingTechnique::JammingTechnique():
   _kind(0), 
   _category(0), 
   _subcategory(0), 
   _specific(0)
{
}

JammingTechnique::~JammingTechnique()
{
}

unsigned char JammingTechnique::getKind() const
{
    return _kind;
}

void JammingTechnique::setKind(unsigned char pX)
{
    _kind = pX;
}

unsigned char JammingTechnique::getCategory() const
{
    return _category;
}

void JammingTechnique::setCategory(unsigned char pX)
{
    _category = pX;
}

unsigned char JammingTechnique::getSubcategory() const
{
    return _subcategory;
}

void JammingTechnique::setSubcategory(unsigned char pX)
{
    _subcategory = pX;
}

unsigned char JammingTechnique::getSpecific() const
{
    return _specific;
}

void JammingTechnique::setSpecific(unsigned char pX)
{
    _specific = pX;
}

void JammingTechnique::marshal(DataStream& dataStream) const
{
    dataStream << _kind;
    dataStream << _category;
    dataStream << _subcategory;
    dataStream << _specific;
}

void JammingTechnique::unmarshal(DataStream& dataStream)
{
    dataStream >> _kind;
    dataStream >> _category;
    dataStream >> _subcategory;
    dataStream >> _specific;
}


bool JammingTechnique::operator ==(const JammingTechnique& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_kind == rhs._kind) ) ivarsEqual = false;
     if( ! (_category == rhs._category) ) ivarsEqual = false;
     if( ! (_subcategory == rhs._subcategory) ) ivarsEqual = false;
     if( ! (_specific == rhs._specific) ) ivarsEqual = false;

    return ivarsEqual;
 }

int JammingTechnique::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _kind
   marshalSize = marshalSize + 1;  // _category
   marshalSize = marshalSize + 1;  // _subcategory
   marshalSize = marshalSize + 1;  // _specific
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
