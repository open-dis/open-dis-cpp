#include <DIS/StopFreezeReliablePdu.h> 

using namespace DIS;


StopFreezeReliablePdu::StopFreezeReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   _realWorldTime(), 
   _reason(0), 
   _frozenBehavior(0), 
   _requiredReliablityService(0), 
   _pad1(0), 
   _requestID(0)
{
    setPduType( 54 );
}

StopFreezeReliablePdu::~StopFreezeReliablePdu()
{
}

ClockTime& StopFreezeReliablePdu::getRealWorldTime() 
{
    return _realWorldTime;
}

const ClockTime& StopFreezeReliablePdu::getRealWorldTime() const
{
    return _realWorldTime;
}

void StopFreezeReliablePdu::setRealWorldTime(const ClockTime &pX)
{
    _realWorldTime = pX;
}

unsigned char StopFreezeReliablePdu::getReason() const
{
    return _reason;
}

void StopFreezeReliablePdu::setReason(unsigned char pX)
{
    _reason = pX;
}

unsigned char StopFreezeReliablePdu::getFrozenBehavior() const
{
    return _frozenBehavior;
}

void StopFreezeReliablePdu::setFrozenBehavior(unsigned char pX)
{
    _frozenBehavior = pX;
}

unsigned char StopFreezeReliablePdu::getRequiredReliablityService() const
{
    return _requiredReliablityService;
}

void StopFreezeReliablePdu::setRequiredReliablityService(unsigned char pX)
{
    _requiredReliablityService = pX;
}

unsigned char StopFreezeReliablePdu::getPad1() const
{
    return _pad1;
}

void StopFreezeReliablePdu::setPad1(unsigned char pX)
{
    _pad1 = pX;
}

unsigned int StopFreezeReliablePdu::getRequestID() const
{
    return _requestID;
}

void StopFreezeReliablePdu::setRequestID(unsigned int pX)
{
    _requestID = pX;
}

void StopFreezeReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _realWorldTime.marshal(dataStream);
    dataStream << _reason;
    dataStream << _frozenBehavior;
    dataStream << _requiredReliablityService;
    dataStream << _pad1;
    dataStream << _requestID;
}

void StopFreezeReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _realWorldTime.unmarshal(dataStream);
    dataStream >> _reason;
    dataStream >> _frozenBehavior;
    dataStream >> _requiredReliablityService;
    dataStream >> _pad1;
    dataStream >> _requestID;
}


bool StopFreezeReliablePdu::operator ==(const StopFreezeReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (_realWorldTime == rhs._realWorldTime) ) ivarsEqual = false;
     if( ! (_reason == rhs._reason) ) ivarsEqual = false;
     if( ! (_frozenBehavior == rhs._frozenBehavior) ) ivarsEqual = false;
     if( ! (_requiredReliablityService == rhs._requiredReliablityService) ) ivarsEqual = false;
     if( ! (_pad1 == rhs._pad1) ) ivarsEqual = false;
     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int StopFreezeReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _realWorldTime.getMarshalledSize();  // _realWorldTime
   marshalSize = marshalSize + 1;  // _reason
   marshalSize = marshalSize + 1;  // _frozenBehavior
   marshalSize = marshalSize + 1;  // _requiredReliablityService
   marshalSize = marshalSize + 1;  // _pad1
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
