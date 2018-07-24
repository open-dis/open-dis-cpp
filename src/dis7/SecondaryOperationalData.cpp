#include <DIS/SecondaryOperationalData.h> 

using namespace DIS;


SecondaryOperationalData::SecondaryOperationalData():
   _operationalData1(0), 
   _operationalData2(0), 
   _numberOfIFFFundamentalParameterRecords(0)
{
}

SecondaryOperationalData::~SecondaryOperationalData()
{
}

unsigned char SecondaryOperationalData::getOperationalData1() const
{
    return _operationalData1;
}

void SecondaryOperationalData::setOperationalData1(unsigned char pX)
{
    _operationalData1 = pX;
}

unsigned char SecondaryOperationalData::getOperationalData2() const
{
    return _operationalData2;
}

void SecondaryOperationalData::setOperationalData2(unsigned char pX)
{
    _operationalData2 = pX;
}

unsigned short SecondaryOperationalData::getNumberOfIFFFundamentalParameterRecords() const
{
    return _numberOfIFFFundamentalParameterRecords;
}

void SecondaryOperationalData::setNumberOfIFFFundamentalParameterRecords(unsigned short pX)
{
    _numberOfIFFFundamentalParameterRecords = pX;
}

void SecondaryOperationalData::marshal(DataStream& dataStream) const
{
    dataStream << _operationalData1;
    dataStream << _operationalData2;
    dataStream << _numberOfIFFFundamentalParameterRecords;
}

void SecondaryOperationalData::unmarshal(DataStream& dataStream)
{
    dataStream >> _operationalData1;
    dataStream >> _operationalData2;
    dataStream >> _numberOfIFFFundamentalParameterRecords;
}


bool SecondaryOperationalData::operator ==(const SecondaryOperationalData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_operationalData1 == rhs._operationalData1) ) ivarsEqual = false;
     if( ! (_operationalData2 == rhs._operationalData2) ) ivarsEqual = false;
     if( ! (_numberOfIFFFundamentalParameterRecords == rhs._numberOfIFFFundamentalParameterRecords) ) ivarsEqual = false;

    return ivarsEqual;
 }

int SecondaryOperationalData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _operationalData1
   marshalSize = marshalSize + 1;  // _operationalData2
   marshalSize = marshalSize + 2;  // _numberOfIFFFundamentalParameterRecords
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
