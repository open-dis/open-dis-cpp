#include <DIS/RecordSet.h> 

using namespace DIS;


RecordSet::RecordSet():
   _recordID(0), 
   _recordSetSerialNumber(0), 
   _recordLength(0), 
   _recordCount(0), 
   _recordValues(0), 
   _pad4(0)
{
}

RecordSet::~RecordSet()
{
}

unsigned int RecordSet::getRecordID() const
{
    return _recordID;
}

void RecordSet::setRecordID(unsigned int pX)
{
    _recordID = pX;
}

unsigned int RecordSet::getRecordSetSerialNumber() const
{
    return _recordSetSerialNumber;
}

void RecordSet::setRecordSetSerialNumber(unsigned int pX)
{
    _recordSetSerialNumber = pX;
}

unsigned short RecordSet::getRecordLength() const
{
    return _recordLength;
}

void RecordSet::setRecordLength(unsigned short pX)
{
    _recordLength = pX;
}

unsigned short RecordSet::getRecordCount() const
{
    return _recordCount;
}

void RecordSet::setRecordCount(unsigned short pX)
{
    _recordCount = pX;
}

unsigned short RecordSet::getRecordValues() const
{
    return _recordValues;
}

void RecordSet::setRecordValues(unsigned short pX)
{
    _recordValues = pX;
}

unsigned char RecordSet::getPad4() const
{
    return _pad4;
}

void RecordSet::setPad4(unsigned char pX)
{
    _pad4 = pX;
}

void RecordSet::marshal(DataStream& dataStream) const
{
    dataStream << _recordID;
    dataStream << _recordSetSerialNumber;
    dataStream << _recordLength;
    dataStream << _recordCount;
    dataStream << _recordValues;
    dataStream << _pad4;
}

void RecordSet::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordID;
    dataStream >> _recordSetSerialNumber;
    dataStream >> _recordLength;
    dataStream >> _recordCount;
    dataStream >> _recordValues;
    dataStream >> _pad4;
}


bool RecordSet::operator ==(const RecordSet& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordID == rhs._recordID) ) ivarsEqual = false;
     if( ! (_recordSetSerialNumber == rhs._recordSetSerialNumber) ) ivarsEqual = false;
     if( ! (_recordLength == rhs._recordLength) ) ivarsEqual = false;
     if( ! (_recordCount == rhs._recordCount) ) ivarsEqual = false;
     if( ! (_recordValues == rhs._recordValues) ) ivarsEqual = false;
     if( ! (_pad4 == rhs._pad4) ) ivarsEqual = false;

    return ivarsEqual;
 }

int RecordSet::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _recordID
   marshalSize = marshalSize + 4;  // _recordSetSerialNumber
   marshalSize = marshalSize + 2;  // _recordLength
   marshalSize = marshalSize + 2;  // _recordCount
   marshalSize = marshalSize + 2;  // _recordValues
   marshalSize = marshalSize + 1;  // _pad4
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
