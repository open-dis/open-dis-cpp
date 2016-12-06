#include <DIS/StopFreezePdu.h> 

using namespace DIS;


StopFreezePdu::StopFreezePdu() : SimulationManagementFamilyPdu(),
   _originatingID(), 
   _receivingID(), 
   _realWorldTime(), 
   _reason(0), 
   _frozenBehavior(0), 
   _padding1(0), 
   _requestID(0)
{
    setPduType( 14 );
}

StopFreezePdu::~StopFreezePdu()
{
}

EntityID& StopFreezePdu::getOriginatingID() 
{
    return _originatingID;
}

const EntityID& StopFreezePdu::getOriginatingID() const
{
    return _originatingID;
}

void StopFreezePdu::setOriginatingID(const EntityID &pX)
{
    _originatingID = pX;
}

EntityID& StopFreezePdu::getReceivingID() 
{
    return _receivingID;
}

const EntityID& StopFreezePdu::getReceivingID() const
{
    return _receivingID;
}

void StopFreezePdu::setReceivingID(const EntityID &pX)
{
    _receivingID = pX;
}

ClockTime& StopFreezePdu::getRealWorldTime() 
{
    return _realWorldTime;
}

const ClockTime& StopFreezePdu::getRealWorldTime() const
{
    return _realWorldTime;
}

void StopFreezePdu::setRealWorldTime(const ClockTime &pX)
{
    _realWorldTime = pX;
}

unsigned char StopFreezePdu::getReason() const
{
    return _reason;
}

void StopFreezePdu::setReason(unsigned char pX)
{
    _reason = pX;
}

unsigned char StopFreezePdu::getFrozenBehavior() const
{
    return _frozenBehavior;
}

void StopFreezePdu::setFrozenBehavior(unsigned char pX)
{
    _frozenBehavior = pX;
}

short StopFreezePdu::getPadding1() const
{
    return _padding1;
}

void StopFreezePdu::setPadding1(short pX)
{
    _padding1 = pX;
}

unsigned int StopFreezePdu::getRequestID() const
{
    return _requestID;
}

void StopFreezePdu::setRequestID(unsigned int pX)
{
    _requestID = pX;
}

void StopFreezePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _originatingID.marshal(dataStream);
    _receivingID.marshal(dataStream);
    _realWorldTime.marshal(dataStream);
    dataStream << _reason;
    dataStream << _frozenBehavior;
    dataStream << _padding1;
    dataStream << _requestID;
}

void StopFreezePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _originatingID.unmarshal(dataStream);
    _receivingID.unmarshal(dataStream);
    _realWorldTime.unmarshal(dataStream);
    dataStream >> _reason;
    dataStream >> _frozenBehavior;
    dataStream >> _padding1;
    dataStream >> _requestID;
}


bool StopFreezePdu::operator ==(const StopFreezePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementFamilyPdu::operator==(rhs);

     if( ! (_originatingID == rhs._originatingID) ) ivarsEqual = false;
     if( ! (_receivingID == rhs._receivingID) ) ivarsEqual = false;
     if( ! (_realWorldTime == rhs._realWorldTime) ) ivarsEqual = false;
     if( ! (_reason == rhs._reason) ) ivarsEqual = false;
     if( ! (_frozenBehavior == rhs._frozenBehavior) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int StopFreezePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _originatingID.getMarshalledSize();  // _originatingID
   marshalSize = marshalSize + _receivingID.getMarshalledSize();  // _receivingID
   marshalSize = marshalSize + _realWorldTime.getMarshalledSize();  // _realWorldTime
   marshalSize = marshalSize + 1;  // _reason
   marshalSize = marshalSize + 1;  // _frozenBehavior
   marshalSize = marshalSize + 2;  // _padding1
   marshalSize = marshalSize + 4;  // _requestID
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
