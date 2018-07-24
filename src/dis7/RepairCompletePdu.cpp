#include <DIS/RepairCompletePdu.h> 

using namespace DIS;


RepairCompletePdu::RepairCompletePdu() : LogisticsFamilyPdu(),
   _receivingEntityID(), 
   _repairingEntityID(), 
   _repair(0), 
   _padding4(0)
{
    setPduType( 9 );
}

RepairCompletePdu::~RepairCompletePdu()
{
}

EntityID& RepairCompletePdu::getReceivingEntityID() 
{
    return _receivingEntityID;
}

const EntityID& RepairCompletePdu::getReceivingEntityID() const
{
    return _receivingEntityID;
}

void RepairCompletePdu::setReceivingEntityID(const EntityID &pX)
{
    _receivingEntityID = pX;
}

EntityID& RepairCompletePdu::getRepairingEntityID() 
{
    return _repairingEntityID;
}

const EntityID& RepairCompletePdu::getRepairingEntityID() const
{
    return _repairingEntityID;
}

void RepairCompletePdu::setRepairingEntityID(const EntityID &pX)
{
    _repairingEntityID = pX;
}

unsigned short RepairCompletePdu::getRepair() const
{
    return _repair;
}

void RepairCompletePdu::setRepair(unsigned short pX)
{
    _repair = pX;
}

short RepairCompletePdu::getPadding4() const
{
    return _padding4;
}

void RepairCompletePdu::setPadding4(short pX)
{
    _padding4 = pX;
}

void RepairCompletePdu::marshal(DataStream& dataStream) const
{
    LogisticsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _receivingEntityID.marshal(dataStream);
    _repairingEntityID.marshal(dataStream);
    dataStream << _repair;
    dataStream << _padding4;
}

void RepairCompletePdu::unmarshal(DataStream& dataStream)
{
    LogisticsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _receivingEntityID.unmarshal(dataStream);
    _repairingEntityID.unmarshal(dataStream);
    dataStream >> _repair;
    dataStream >> _padding4;
}


bool RepairCompletePdu::operator ==(const RepairCompletePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = LogisticsFamilyPdu::operator==(rhs);

     if( ! (_receivingEntityID == rhs._receivingEntityID) ) ivarsEqual = false;
     if( ! (_repairingEntityID == rhs._repairingEntityID) ) ivarsEqual = false;
     if( ! (_repair == rhs._repair) ) ivarsEqual = false;
     if( ! (_padding4 == rhs._padding4) ) ivarsEqual = false;

    return ivarsEqual;
 }

int RepairCompletePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = LogisticsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _receivingEntityID.getMarshalledSize();  // _receivingEntityID
   marshalSize = marshalSize + _repairingEntityID.getMarshalledSize();  // _repairingEntityID
   marshalSize = marshalSize + 2;  // _repair
   marshalSize = marshalSize + 2;  // _padding4
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
