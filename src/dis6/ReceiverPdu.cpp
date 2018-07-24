#include <DIS/ReceiverPdu.h> 

using namespace DIS;


ReceiverPdu::ReceiverPdu() : RadioCommunicationsFamilyPdu(),
   _receiverState(0), 
   _padding1(0), 
   _receivedPoser(0.0), 
   _transmitterEntityId(), 
   _transmitterRadioId(0)
{
    setPduType( 27 );
}

ReceiverPdu::~ReceiverPdu()
{
}

unsigned short ReceiverPdu::getReceiverState() const
{
    return _receiverState;
}

void ReceiverPdu::setReceiverState(unsigned short pX)
{
    _receiverState = pX;
}

unsigned short ReceiverPdu::getPadding1() const
{
    return _padding1;
}

void ReceiverPdu::setPadding1(unsigned short pX)
{
    _padding1 = pX;
}

float ReceiverPdu::getReceivedPoser() const
{
    return _receivedPoser;
}

void ReceiverPdu::setReceivedPoser(float pX)
{
    _receivedPoser = pX;
}

EntityID& ReceiverPdu::getTransmitterEntityId() 
{
    return _transmitterEntityId;
}

const EntityID& ReceiverPdu::getTransmitterEntityId() const
{
    return _transmitterEntityId;
}

void ReceiverPdu::setTransmitterEntityId(const EntityID &pX)
{
    _transmitterEntityId = pX;
}

unsigned short ReceiverPdu::getTransmitterRadioId() const
{
    return _transmitterRadioId;
}

void ReceiverPdu::setTransmitterRadioId(unsigned short pX)
{
    _transmitterRadioId = pX;
}

void ReceiverPdu::marshal(DataStream& dataStream) const
{
    RadioCommunicationsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _receiverState;
    dataStream << _padding1;
    dataStream << _receivedPoser;
    _transmitterEntityId.marshal(dataStream);
    dataStream << _transmitterRadioId;
}

void ReceiverPdu::unmarshal(DataStream& dataStream)
{
    RadioCommunicationsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _receiverState;
    dataStream >> _padding1;
    dataStream >> _receivedPoser;
    _transmitterEntityId.unmarshal(dataStream);
    dataStream >> _transmitterRadioId;
}


bool ReceiverPdu::operator ==(const ReceiverPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = RadioCommunicationsFamilyPdu::operator==(rhs);

     if( ! (_receiverState == rhs._receiverState) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_receivedPoser == rhs._receivedPoser) ) ivarsEqual = false;
     if( ! (_transmitterEntityId == rhs._transmitterEntityId) ) ivarsEqual = false;
     if( ! (_transmitterRadioId == rhs._transmitterRadioId) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ReceiverPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 2;  // _receiverState
   marshalSize = marshalSize + 2;  // _padding1
   marshalSize = marshalSize + 4;  // _receivedPoser
   marshalSize = marshalSize + _transmitterEntityId.getMarshalledSize();  // _transmitterEntityId
   marshalSize = marshalSize + 2;  // _transmitterRadioId
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
