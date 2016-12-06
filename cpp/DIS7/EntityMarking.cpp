#include <DIS/EntityMarking.h> 

using namespace DIS;


EntityMarking::EntityMarking():
   _characterSet(0)
{
     // Initialize fixed length array
     for(int lengthcharacters= 0; lengthcharacters < 11; lengthcharacters++)
     {
         _characters[lengthcharacters] = 0;
     }

}

EntityMarking::~EntityMarking()
{
}

unsigned char EntityMarking::getCharacterSet() const
{
    return _characterSet;
}

void EntityMarking::setCharacterSet(unsigned char pX)
{
    _characterSet = pX;
}

char* EntityMarking::getCharacters() 
{
    return _characters;
}

const char* EntityMarking::getCharacters() const
{
    return _characters;
}

void EntityMarking::setCharacters(const char* x)
{
   for(int i = 0; i < 11; i++)
   {
        _characters[i] = x[i];
   }
}

// An alternate method to set the value if this could be a string. This is not strictly comnpliant with the DIS standard.
void EntityMarking::setByStringCharacters(const char* x)
{
   strncpy(_characters, x, 11-1);
   _characters[11 -1] = '\0';
}

void EntityMarking::marshal(DataStream& dataStream) const
{
    dataStream << _characterSet;

     for(size_t idx = 0; idx < 11; idx++)
     {
        dataStream << _characters[idx];
     }

}

void EntityMarking::unmarshal(DataStream& dataStream)
{
    dataStream >> _characterSet;

     for(size_t idx = 0; idx < 11; idx++)
     {
        dataStream >> _characters[idx];
     }

}


bool EntityMarking::operator ==(const EntityMarking& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_characterSet == rhs._characterSet) ) ivarsEqual = false;

     for(char idx = 0; idx < 11; idx++)
     {
          if(!(_characters[idx] == rhs._characters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int EntityMarking::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _characterSet
   marshalSize = marshalSize + 11 * 1;  // _characters
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
