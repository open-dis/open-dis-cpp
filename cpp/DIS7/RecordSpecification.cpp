#include <DIS/RecordSpecification.h> 

using namespace DIS;


RecordSpecification::RecordSpecification():
   _numberOfRecordSets(0)
{
}

RecordSpecification::~RecordSpecification()
{
    _recordSets.clear();
}

unsigned int RecordSpecification::getNumberOfRecordSets() const
{
   return _recordSets.size();
}

std::vector<RecordSpecificationElement>& RecordSpecification::getRecordSets() 
{
    return _recordSets;
}

const std::vector<RecordSpecificationElement>& RecordSpecification::getRecordSets() const
{
    return _recordSets;
}

void RecordSpecification::setRecordSets(const std::vector<RecordSpecificationElement>& pX)
{
     _recordSets = pX;
}

void RecordSpecification::marshal(DataStream& dataStream) const
{
    dataStream << ( unsigned int )_recordSets.size();

     for(size_t idx = 0; idx < _recordSets.size(); idx++)
     {
        RecordSpecificationElement x = _recordSets[idx];
        x.marshal(dataStream);
     }

}

void RecordSpecification::unmarshal(DataStream& dataStream)
{
    dataStream >> _numberOfRecordSets;

     _recordSets.clear();
     for(size_t idx = 0; idx < _numberOfRecordSets; idx++)
     {
        RecordSpecificationElement x;
        x.unmarshal(dataStream);
        _recordSets.push_back(x);
     }
}


bool RecordSpecification::operator ==(const RecordSpecification& rhs) const
 {
     bool ivarsEqual = true;


     for(size_t idx = 0; idx < _recordSets.size(); idx++)
     {
        if( ! ( _recordSets[idx] == rhs._recordSets[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int RecordSpecification::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _numberOfRecordSets

   for(int idx=0; idx < _recordSets.size(); idx++)
   {
        RecordSpecificationElement listElement = _recordSets[idx];
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
