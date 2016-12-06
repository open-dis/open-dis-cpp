#include <DIS/VariableDatum.h> 

using namespace DIS;


VariableDatum::VariableDatum():
   _variableDatumID(0), 
   _variableDatumLength(0)
{
}

VariableDatum::~VariableDatum()
{
    _variableDatums.clear();
}

unsigned int VariableDatum::getVariableDatumID() const
{
    return _variableDatumID;
}

void VariableDatum::setVariableDatumID(unsigned int pX)
{
    _variableDatumID = pX;
}

unsigned int VariableDatum::getVariableDatumLength() const
{
   return _variableDatums.size();
}

std::vector<EightByteChunk>& VariableDatum::getVariableDatums() 
{
    return _variableDatums;
}

const std::vector<EightByteChunk>& VariableDatum::getVariableDatums() const
{
    return _variableDatums;
}

void VariableDatum::setVariableDatums(const std::vector<EightByteChunk>& pX)
{
     _variableDatums = pX;
}

void VariableDatum::marshal(DataStream& dataStream) const
{
    dataStream << _variableDatumID;
    dataStream << ( unsigned int )_variableDatums.size();

     for(size_t idx = 0; idx < _variableDatums.size(); idx++)
     {
        EightByteChunk x = _variableDatums[idx];
        x.marshal(dataStream);
     }

}

void VariableDatum::unmarshal(DataStream& dataStream)
{
    dataStream >> _variableDatumID;
    dataStream >> _variableDatumLength;

     _variableDatums.clear();
     for(size_t idx = 0; idx < _variableDatumLength; idx++)
     {
        EightByteChunk x;
        x.unmarshal(dataStream);
        _variableDatums.push_back(x);
     }
}


bool VariableDatum::operator ==(const VariableDatum& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_variableDatumID == rhs._variableDatumID) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _variableDatums.size(); idx++)
     {
        if( ! ( _variableDatums[idx] == rhs._variableDatums[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int VariableDatum::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _variableDatumID
   marshalSize = marshalSize + 4;  // _variableDatumLength

   for(int idx=0; idx < _variableDatums.size(); idx++)
   {
        EightByteChunk listElement = _variableDatums[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

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
