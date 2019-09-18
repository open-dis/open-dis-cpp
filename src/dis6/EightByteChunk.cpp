#include <dis6/EightByteChunk.h>

using namespace DIS;


EightByteChunk::EightByteChunk()
{
     // Initialize fixed length array
     for(int lengthotherParameters= 0; lengthotherParameters < 8; lengthotherParameters++)
     {
         _otherParameters[lengthotherParameters] = 0;
     }

}

EightByteChunk::~EightByteChunk()
{
}

char* EightByteChunk::getOtherParameters() 
{
    return _otherParameters;
}

const char* EightByteChunk::getOtherParameters() const
{
    return _otherParameters;
}

void EightByteChunk::setOtherParameters(const char* x)
{
   for(int i = 0; i < 8; i++)
   {
        _otherParameters[i] = x[i];
   }
}

void EightByteChunk::marshal(DataStream& dataStream) const
{

     for(size_t idx = 0; idx < 8; idx++)
     {
        dataStream << _otherParameters[idx];
     }

}

void EightByteChunk::unmarshal(DataStream& dataStream)
{

     for(size_t idx = 0; idx < 8; idx++)
     {
        dataStream >> _otherParameters[idx];
     }

}


bool EightByteChunk::operator ==(const EightByteChunk& rhs) const
 {
     bool ivarsEqual = true;


     for(uint8_t idx = 0; idx < 8; idx++)
     {
          if(!(_otherParameters[idx] == rhs._otherParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int EightByteChunk::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 8 * 1;  // _otherParameters
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
