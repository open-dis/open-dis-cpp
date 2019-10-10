#include <dis6/SetRecordReliablePdu.h>

using namespace DIS;


SetRecordReliablePdu::SetRecordReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   _requestID(0), 
   _requiredReliabilityService(0), 
   _pad1(0), 
   _pad2(0), 
   _numberOfRecordSets(0)
{
    setPduType( 64 );
}

SetRecordReliablePdu::~SetRecordReliablePdu()
{
    _recordSets.clear();
}

unsigned int SetRecordReliablePdu::getRequestID() const
{
    return _requestID;
}

void SetRecordReliablePdu::setRequestID(unsigned int pX)
{
    _requestID = pX;
}

unsigned char SetRecordReliablePdu::getRequiredReliabilityService() const
{
    return _requiredReliabilityService;
}

void SetRecordReliablePdu::setRequiredReliabilityService(unsigned char pX)
{
    _requiredReliabilityService = pX;
}

unsigned short SetRecordReliablePdu::getPad1() const
{
    return _pad1;
}

void SetRecordReliablePdu::setPad1(unsigned short pX)
{
    _pad1 = pX;
}

unsigned char SetRecordReliablePdu::getPad2() const
{
    return _pad2;
}

void SetRecordReliablePdu::setPad2(unsigned char pX)
{
    _pad2 = pX;
}

unsigned int SetRecordReliablePdu::getNumberOfRecordSets() const
{
   return _recordSets.size();
}

std::vector<RecordSet>& SetRecordReliablePdu::getRecordSets() 
{
    return _recordSets;
}

const std::vector<RecordSet>& SetRecordReliablePdu::getRecordSets() const
{
    return _recordSets;
}

void SetRecordReliablePdu::setRecordSets(const std::vector<RecordSet>& pX)
{
     _recordSets = pX;
}

void SetRecordReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _requestID;
    dataStream << _requiredReliabilityService;
    dataStream << _pad1;
    dataStream << _pad2;
    dataStream << ( unsigned int )_recordSets.size();

     for(size_t idx = 0; idx < _recordSets.size(); idx++)
     {
        RecordSet x = _recordSets[idx];
        x.marshal(dataStream);
     }

}

void SetRecordReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _requestID;
    dataStream >> _requiredReliabilityService;
    dataStream >> _pad1;
    dataStream >> _pad2;
    dataStream >> _numberOfRecordSets;

     _recordSets.clear();
     for(size_t idx = 0; idx < _numberOfRecordSets; idx++)
     {
        RecordSet x;
        x.unmarshal(dataStream);
        _recordSets.push_back(x);
     }
}


bool SetRecordReliablePdu::operator ==(const SetRecordReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;
     if( ! (_requiredReliabilityService == rhs._requiredReliabilityService) ) ivarsEqual = false;
     if( ! (_pad1 == rhs._pad1) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _recordSets.size(); idx++)
     {
        if( ! ( _recordSets[idx] == rhs._recordSets[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int SetRecordReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 4;  // _requestID
   marshalSize = marshalSize + 1;  // _requiredReliabilityService
   marshalSize = marshalSize + 2;  // _pad1
   marshalSize = marshalSize + 1;  // _pad2
   marshalSize = marshalSize + 4;  // _numberOfRecordSets

   for(unsigned long long idx=0; idx < _recordSets.size(); idx++)
   {
        RecordSet listElement = _recordSets[idx];
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
