#include <DIS/RecordQueryReliablePdu.h> 

using namespace DIS;


RecordQueryReliablePdu::RecordQueryReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   _requestID(0), 
   _requiredReliabilityService(0), 
   _pad1(0), 
   _pad2(0), 
   _eventType(0), 
   _time(0), 
   _numberOfRecords(0)
{
    setPduType( 63 );
}

RecordQueryReliablePdu::~RecordQueryReliablePdu()
{
    _recordIDs.clear();
}

unsigned int RecordQueryReliablePdu::getRequestID() const
{
    return _requestID;
}

void RecordQueryReliablePdu::setRequestID(unsigned int pX)
{
    _requestID = pX;
}

unsigned char RecordQueryReliablePdu::getRequiredReliabilityService() const
{
    return _requiredReliabilityService;
}

void RecordQueryReliablePdu::setRequiredReliabilityService(unsigned char pX)
{
    _requiredReliabilityService = pX;
}

unsigned short RecordQueryReliablePdu::getPad1() const
{
    return _pad1;
}

void RecordQueryReliablePdu::setPad1(unsigned short pX)
{
    _pad1 = pX;
}

unsigned char RecordQueryReliablePdu::getPad2() const
{
    return _pad2;
}

void RecordQueryReliablePdu::setPad2(unsigned char pX)
{
    _pad2 = pX;
}

unsigned short RecordQueryReliablePdu::getEventType() const
{
    return _eventType;
}

void RecordQueryReliablePdu::setEventType(unsigned short pX)
{
    _eventType = pX;
}

unsigned int RecordQueryReliablePdu::getTime() const
{
    return _time;
}

void RecordQueryReliablePdu::setTime(unsigned int pX)
{
    _time = pX;
}

unsigned int RecordQueryReliablePdu::getNumberOfRecords() const
{
   return _recordIDs.size();
}

std::vector<FourByteChunk>& RecordQueryReliablePdu::getRecordIDs() 
{
    return _recordIDs;
}

const std::vector<FourByteChunk>& RecordQueryReliablePdu::getRecordIDs() const
{
    return _recordIDs;
}

void RecordQueryReliablePdu::setRecordIDs(const std::vector<FourByteChunk>& pX)
{
     _recordIDs = pX;
}

void RecordQueryReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _requestID;
    dataStream << _requiredReliabilityService;
    dataStream << _pad1;
    dataStream << _pad2;
    dataStream << _eventType;
    dataStream << _time;
    dataStream << ( unsigned int )_recordIDs.size();

     for(size_t idx = 0; idx < _recordIDs.size(); idx++)
     {
        FourByteChunk x = _recordIDs[idx];
        x.marshal(dataStream);
     }

}

void RecordQueryReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _requestID;
    dataStream >> _requiredReliabilityService;
    dataStream >> _pad1;
    dataStream >> _pad2;
    dataStream >> _eventType;
    dataStream >> _time;
    dataStream >> _numberOfRecords;

     _recordIDs.clear();
     for(size_t idx = 0; idx < _numberOfRecords; idx++)
     {
        FourByteChunk x;
        x.unmarshal(dataStream);
        _recordIDs.push_back(x);
     }
}


bool RecordQueryReliablePdu::operator ==(const RecordQueryReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;
     if( ! (_requiredReliabilityService == rhs._requiredReliabilityService) ) ivarsEqual = false;
     if( ! (_pad1 == rhs._pad1) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_eventType == rhs._eventType) ) ivarsEqual = false;
     if( ! (_time == rhs._time) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _recordIDs.size(); idx++)
     {
        if( ! ( _recordIDs[idx] == rhs._recordIDs[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int RecordQueryReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 4;  // _requestID
   marshalSize = marshalSize + 1;  // _requiredReliabilityService
   marshalSize = marshalSize + 2;  // _pad1
   marshalSize = marshalSize + 1;  // _pad2
   marshalSize = marshalSize + 2;  // _eventType
   marshalSize = marshalSize + 4;  // _time
   marshalSize = marshalSize + 4;  // _numberOfRecords

   for(int idx=0; idx < _recordIDs.size(); idx++)
   {
        FourByteChunk listElement = _recordIDs[idx];
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
