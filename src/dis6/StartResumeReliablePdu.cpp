#include <dis6/StartResumeReliablePdu.h>

using namespace DIS;


StartResumeReliablePdu::StartResumeReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   _realWorldTime(), 
   _simulationTime(), 
   _requiredReliabilityService(0), 
   _pad1(0), 
   _pad2(0), 
   _requestID(0)
{
    setPduType( 53 );
}

StartResumeReliablePdu::~StartResumeReliablePdu()
{
}

ClockTime& StartResumeReliablePdu::getRealWorldTime() 
{
    return _realWorldTime;
}

const ClockTime& StartResumeReliablePdu::getRealWorldTime() const
{
    return _realWorldTime;
}

void StartResumeReliablePdu::setRealWorldTime(const ClockTime &pX)
{
    _realWorldTime = pX;
}

ClockTime& StartResumeReliablePdu::getSimulationTime() 
{
    return _simulationTime;
}

const ClockTime& StartResumeReliablePdu::getSimulationTime() const
{
    return _simulationTime;
}

void StartResumeReliablePdu::setSimulationTime(const ClockTime &pX)
{
    _simulationTime = pX;
}

uint8_t StartResumeReliablePdu::getRequiredReliabilityService() const
{
    return _requiredReliabilityService;
}

void StartResumeReliablePdu::setRequiredReliabilityService(uint8_t pX)
{
    _requiredReliabilityService = pX;
}

unsigned short StartResumeReliablePdu::getPad1() const
{
    return _pad1;
}

void StartResumeReliablePdu::setPad1(unsigned short pX)
{
    _pad1 = pX;
}

uint8_t StartResumeReliablePdu::getPad2() const
{
    return _pad2;
}

void StartResumeReliablePdu::setPad2(uint8_t pX)
{
    _pad2 = pX;
}

unsigned int StartResumeReliablePdu::getRequestID() const
{
    return _requestID;
}

void StartResumeReliablePdu::setRequestID(unsigned int pX)
{
    _requestID = pX;
}

void StartResumeReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _realWorldTime.marshal(dataStream);
    _simulationTime.marshal(dataStream);
    dataStream << _requiredReliabilityService;
    dataStream << _pad1;
    dataStream << _pad2;
    dataStream << _requestID;
}

void StartResumeReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _realWorldTime.unmarshal(dataStream);
    _simulationTime.unmarshal(dataStream);
    dataStream >> _requiredReliabilityService;
    dataStream >> _pad1;
    dataStream >> _pad2;
    dataStream >> _requestID;
}


bool StartResumeReliablePdu::operator ==(const StartResumeReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (_realWorldTime == rhs._realWorldTime) ) ivarsEqual = false;
     if( ! (_simulationTime == rhs._simulationTime) ) ivarsEqual = false;
     if( ! (_requiredReliabilityService == rhs._requiredReliabilityService) ) ivarsEqual = false;
     if( ! (_pad1 == rhs._pad1) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int StartResumeReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _realWorldTime.getMarshalledSize();  // _realWorldTime
   marshalSize = marshalSize + _simulationTime.getMarshalledSize();  // _simulationTime
   marshalSize = marshalSize + 1;  // _requiredReliabilityService
   marshalSize = marshalSize + 2;  // _pad1
   marshalSize = marshalSize + 1;  // _pad2
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
