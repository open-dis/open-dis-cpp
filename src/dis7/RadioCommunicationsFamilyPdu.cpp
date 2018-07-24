#include <DIS/RadioCommunicationsFamilyPdu.h> 

using namespace DIS;


RadioCommunicationsFamilyPdu::RadioCommunicationsFamilyPdu() : Pdu(),
   _entityId(), 
   _radioId(0)
{
    setProtocolFamily( 4 );
}

RadioCommunicationsFamilyPdu::~RadioCommunicationsFamilyPdu()
{
}

EntityID& RadioCommunicationsFamilyPdu::getEntityId() 
{
    return _entityId;
}

const EntityID& RadioCommunicationsFamilyPdu::getEntityId() const
{
    return _entityId;
}

void RadioCommunicationsFamilyPdu::setEntityId(const EntityID &pX)
{
    _entityId = pX;
}

unsigned short RadioCommunicationsFamilyPdu::getRadioId() const
{
    return _radioId;
}

void RadioCommunicationsFamilyPdu::setRadioId(unsigned short pX)
{
    _radioId = pX;
}

void RadioCommunicationsFamilyPdu::marshal(DataStream& dataStream) const
{
    Pdu::marshal(dataStream); // Marshal information in superclass first
    _entityId.marshal(dataStream);
    dataStream << _radioId;
}

void RadioCommunicationsFamilyPdu::unmarshal(DataStream& dataStream)
{
    Pdu::unmarshal(dataStream); // unmarshal information in superclass first
    _entityId.unmarshal(dataStream);
    dataStream >> _radioId;
}


bool RadioCommunicationsFamilyPdu::operator ==(const RadioCommunicationsFamilyPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = Pdu::operator==(rhs);

     if( ! (_entityId == rhs._entityId) ) ivarsEqual = false;
     if( ! (_radioId == rhs._radioId) ) ivarsEqual = false;

    return ivarsEqual;
 }

int RadioCommunicationsFamilyPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = Pdu::getMarshalledSize();
   marshalSize = marshalSize + _entityId.getMarshalledSize();  // _entityId
   marshalSize = marshalSize + 2;  // _radioId
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
