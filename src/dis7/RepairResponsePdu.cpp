#include <DIS/RepairResponsePdu.h> 

using namespace DIS;


RepairResponsePdu::RepairResponsePdu() : LogisticsFamilyPdu(),
   _receivingEntityID(), 
   _repairingEntityID(), 
   _repairResult(0), 
   _padding1(0), 
   _padding2(0)
{
    setPduType( 10 );
}

RepairResponsePdu::~RepairResponsePdu()
{
}

EntityID& RepairResponsePdu::getReceivingEntityID() 
{
    return _receivingEntityID;
}

const EntityID& RepairResponsePdu::getReceivingEntityID() const
{
    return _receivingEntityID;
}

void RepairResponsePdu::setReceivingEntityID(const EntityID &pX)
{
    _receivingEntityID = pX;
}

EntityID& RepairResponsePdu::getRepairingEntityID() 
{
    return _repairingEntityID;
}

const EntityID& RepairResponsePdu::getRepairingEntityID() const
{
    return _repairingEntityID;
}

void RepairResponsePdu::setRepairingEntityID(const EntityID &pX)
{
    _repairingEntityID = pX;
}

unsigned char RepairResponsePdu::getRepairResult() const
{
    return _repairResult;
}

void RepairResponsePdu::setRepairResult(unsigned char pX)
{
    _repairResult = pX;
}

short RepairResponsePdu::getPadding1() const
{
    return _padding1;
}

void RepairResponsePdu::setPadding1(short pX)
{
    _padding1 = pX;
}

char RepairResponsePdu::getPadding2() const
{
    return _padding2;
}

void RepairResponsePdu::setPadding2(char pX)
{
    _padding2 = pX;
}

void RepairResponsePdu::marshal(DataStream& dataStream) const
{
    LogisticsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _receivingEntityID.marshal(dataStream);
    _repairingEntityID.marshal(dataStream);
    dataStream << _repairResult;
    dataStream << _padding1;
    dataStream << _padding2;
}

void RepairResponsePdu::unmarshal(DataStream& dataStream)
{
    LogisticsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _receivingEntityID.unmarshal(dataStream);
    _repairingEntityID.unmarshal(dataStream);
    dataStream >> _repairResult;
    dataStream >> _padding1;
    dataStream >> _padding2;
}


bool RepairResponsePdu::operator ==(const RepairResponsePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = LogisticsFamilyPdu::operator==(rhs);

     if( ! (_receivingEntityID == rhs._receivingEntityID) ) ivarsEqual = false;
     if( ! (_repairingEntityID == rhs._repairingEntityID) ) ivarsEqual = false;
     if( ! (_repairResult == rhs._repairResult) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;

    return ivarsEqual;
 }

int RepairResponsePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = LogisticsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _receivingEntityID.getMarshalledSize();  // _receivingEntityID
   marshalSize = marshalSize + _repairingEntityID.getMarshalledSize();  // _repairingEntityID
   marshalSize = marshalSize + 1;  // _repairResult
   marshalSize = marshalSize + 2;  // _padding1
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
