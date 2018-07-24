#include <DIS/IffAtcNavAidsLayer1Pdu.h> 

using namespace DIS;


IffAtcNavAidsLayer1Pdu::IffAtcNavAidsLayer1Pdu() : DistributedEmissionsFamilyPdu(),
   _emittingEntityId(), 
   _eventID(), 
   _location(), 
   _systemID(), 
   _pad2(0), 
   _fundamentalParameters()
{
    setPduType( 28 );
}

IffAtcNavAidsLayer1Pdu::~IffAtcNavAidsLayer1Pdu()
{
}

EntityID& IffAtcNavAidsLayer1Pdu::getEmittingEntityId() 
{
    return _emittingEntityId;
}

const EntityID& IffAtcNavAidsLayer1Pdu::getEmittingEntityId() const
{
    return _emittingEntityId;
}

void IffAtcNavAidsLayer1Pdu::setEmittingEntityId(const EntityID &pX)
{
    _emittingEntityId = pX;
}

EventID& IffAtcNavAidsLayer1Pdu::getEventID() 
{
    return _eventID;
}

const EventID& IffAtcNavAidsLayer1Pdu::getEventID() const
{
    return _eventID;
}

void IffAtcNavAidsLayer1Pdu::setEventID(const EventID &pX)
{
    _eventID = pX;
}

Vector3Float& IffAtcNavAidsLayer1Pdu::getLocation() 
{
    return _location;
}

const Vector3Float& IffAtcNavAidsLayer1Pdu::getLocation() const
{
    return _location;
}

void IffAtcNavAidsLayer1Pdu::setLocation(const Vector3Float &pX)
{
    _location = pX;
}

SystemID& IffAtcNavAidsLayer1Pdu::getSystemID() 
{
    return _systemID;
}

const SystemID& IffAtcNavAidsLayer1Pdu::getSystemID() const
{
    return _systemID;
}

void IffAtcNavAidsLayer1Pdu::setSystemID(const SystemID &pX)
{
    _systemID = pX;
}

unsigned short IffAtcNavAidsLayer1Pdu::getPad2() const
{
    return _pad2;
}

void IffAtcNavAidsLayer1Pdu::setPad2(unsigned short pX)
{
    _pad2 = pX;
}

IffFundamentalData& IffAtcNavAidsLayer1Pdu::getFundamentalParameters() 
{
    return _fundamentalParameters;
}

const IffFundamentalData& IffAtcNavAidsLayer1Pdu::getFundamentalParameters() const
{
    return _fundamentalParameters;
}

void IffAtcNavAidsLayer1Pdu::setFundamentalParameters(const IffFundamentalData &pX)
{
    _fundamentalParameters = pX;
}

void IffAtcNavAidsLayer1Pdu::marshal(DataStream& dataStream) const
{
    DistributedEmissionsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _emittingEntityId.marshal(dataStream);
    _eventID.marshal(dataStream);
    _location.marshal(dataStream);
    _systemID.marshal(dataStream);
    dataStream << _pad2;
    _fundamentalParameters.marshal(dataStream);
}

void IffAtcNavAidsLayer1Pdu::unmarshal(DataStream& dataStream)
{
    DistributedEmissionsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _emittingEntityId.unmarshal(dataStream);
    _eventID.unmarshal(dataStream);
    _location.unmarshal(dataStream);
    _systemID.unmarshal(dataStream);
    dataStream >> _pad2;
    _fundamentalParameters.unmarshal(dataStream);
}


bool IffAtcNavAidsLayer1Pdu::operator ==(const IffAtcNavAidsLayer1Pdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

     if( ! (_emittingEntityId == rhs._emittingEntityId) ) ivarsEqual = false;
     if( ! (_eventID == rhs._eventID) ) ivarsEqual = false;
     if( ! (_location == rhs._location) ) ivarsEqual = false;
     if( ! (_systemID == rhs._systemID) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_fundamentalParameters == rhs._fundamentalParameters) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IffAtcNavAidsLayer1Pdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _emittingEntityId.getMarshalledSize();  // _emittingEntityId
   marshalSize = marshalSize + _eventID.getMarshalledSize();  // _eventID
   marshalSize = marshalSize + _location.getMarshalledSize();  // _location
   marshalSize = marshalSize + _systemID.getMarshalledSize();  // _systemID
   marshalSize = marshalSize + 2;  // _pad2
   marshalSize = marshalSize + _fundamentalParameters.getMarshalledSize();  // _fundamentalParameters
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
