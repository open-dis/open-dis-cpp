#include <DIS/MinefieldResponseNackPdu.h> 

using namespace DIS;


MinefieldResponseNackPdu::MinefieldResponseNackPdu() : MinefieldFamilyPdu(),
   _minefieldID(), 
   _requestingEntityID(), 
   _requestID(0), 
   _numberOfMissingPdus(0)
{
    setPduType( 40 );
}

MinefieldResponseNackPdu::~MinefieldResponseNackPdu()
{
    _missingPduSequenceNumbers.clear();
}

EntityID& MinefieldResponseNackPdu::getMinefieldID() 
{
    return _minefieldID;
}

const EntityID& MinefieldResponseNackPdu::getMinefieldID() const
{
    return _minefieldID;
}

void MinefieldResponseNackPdu::setMinefieldID(const EntityID &pX)
{
    _minefieldID = pX;
}

EntityID& MinefieldResponseNackPdu::getRequestingEntityID() 
{
    return _requestingEntityID;
}

const EntityID& MinefieldResponseNackPdu::getRequestingEntityID() const
{
    return _requestingEntityID;
}

void MinefieldResponseNackPdu::setRequestingEntityID(const EntityID &pX)
{
    _requestingEntityID = pX;
}

unsigned char MinefieldResponseNackPdu::getRequestID() const
{
    return _requestID;
}

void MinefieldResponseNackPdu::setRequestID(unsigned char pX)
{
    _requestID = pX;
}

unsigned char MinefieldResponseNackPdu::getNumberOfMissingPdus() const
{
   return _missingPduSequenceNumbers.size();
}

std::vector<EightByteChunk>& MinefieldResponseNackPdu::getMissingPduSequenceNumbers() 
{
    return _missingPduSequenceNumbers;
}

const std::vector<EightByteChunk>& MinefieldResponseNackPdu::getMissingPduSequenceNumbers() const
{
    return _missingPduSequenceNumbers;
}

void MinefieldResponseNackPdu::setMissingPduSequenceNumbers(const std::vector<EightByteChunk>& pX)
{
     _missingPduSequenceNumbers = pX;
}

void MinefieldResponseNackPdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _minefieldID.marshal(dataStream);
    _requestingEntityID.marshal(dataStream);
    dataStream << _requestID;
    dataStream << ( unsigned char )_missingPduSequenceNumbers.size();

     for(size_t idx = 0; idx < _missingPduSequenceNumbers.size(); idx++)
     {
        EightByteChunk x = _missingPduSequenceNumbers[idx];
        x.marshal(dataStream);
     }

}

void MinefieldResponseNackPdu::unmarshal(DataStream& dataStream)
{
    MinefieldFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _minefieldID.unmarshal(dataStream);
    _requestingEntityID.unmarshal(dataStream);
    dataStream >> _requestID;
    dataStream >> _numberOfMissingPdus;

     _missingPduSequenceNumbers.clear();
     for(size_t idx = 0; idx < _numberOfMissingPdus; idx++)
     {
        EightByteChunk x;
        x.unmarshal(dataStream);
        _missingPduSequenceNumbers.push_back(x);
     }
}


bool MinefieldResponseNackPdu::operator ==(const MinefieldResponseNackPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (_minefieldID == rhs._minefieldID) ) ivarsEqual = false;
     if( ! (_requestingEntityID == rhs._requestingEntityID) ) ivarsEqual = false;
     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _missingPduSequenceNumbers.size(); idx++)
     {
        if( ! ( _missingPduSequenceNumbers[idx] == rhs._missingPduSequenceNumbers[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int MinefieldResponseNackPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = MinefieldFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _minefieldID.getMarshalledSize();  // _minefieldID
   marshalSize = marshalSize + _requestingEntityID.getMarshalledSize();  // _requestingEntityID
   marshalSize = marshalSize + 1;  // _requestID
   marshalSize = marshalSize + 1;  // _numberOfMissingPdus

   for(int idx=0; idx < _missingPduSequenceNumbers.size(); idx++)
   {
        EightByteChunk listElement = _missingPduSequenceNumbers[idx];
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
