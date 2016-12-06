#include <DIS/ActionResponseReliablePdu.h> 

using namespace DIS;


ActionResponseReliablePdu::ActionResponseReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   _requestID(0), 
   _responseStatus(0), 
   _numberOfFixedDatumRecords(0), 
   _numberOfVariableDatumRecords(0)
{
    setPduType( 57 );
}

ActionResponseReliablePdu::~ActionResponseReliablePdu()
{
    _fixedDatumRecords.clear();
    _variableDatumRecords.clear();
}

unsigned int ActionResponseReliablePdu::getRequestID() const
{
    return _requestID;
}

void ActionResponseReliablePdu::setRequestID(unsigned int pX)
{
    _requestID = pX;
}

unsigned int ActionResponseReliablePdu::getResponseStatus() const
{
    return _responseStatus;
}

void ActionResponseReliablePdu::setResponseStatus(unsigned int pX)
{
    _responseStatus = pX;
}

unsigned int ActionResponseReliablePdu::getNumberOfFixedDatumRecords() const
{
   return _fixedDatumRecords.size();
}

unsigned int ActionResponseReliablePdu::getNumberOfVariableDatumRecords() const
{
   return _variableDatumRecords.size();
}

std::vector<FixedDatum>& ActionResponseReliablePdu::getFixedDatumRecords() 
{
    return _fixedDatumRecords;
}

const std::vector<FixedDatum>& ActionResponseReliablePdu::getFixedDatumRecords() const
{
    return _fixedDatumRecords;
}

void ActionResponseReliablePdu::setFixedDatumRecords(const std::vector<FixedDatum>& pX)
{
     _fixedDatumRecords = pX;
}

std::vector<VariableDatum>& ActionResponseReliablePdu::getVariableDatumRecords() 
{
    return _variableDatumRecords;
}

const std::vector<VariableDatum>& ActionResponseReliablePdu::getVariableDatumRecords() const
{
    return _variableDatumRecords;
}

void ActionResponseReliablePdu::setVariableDatumRecords(const std::vector<VariableDatum>& pX)
{
     _variableDatumRecords = pX;
}

void ActionResponseReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _requestID;
    dataStream << _responseStatus;
    dataStream << ( unsigned int )_fixedDatumRecords.size();
    dataStream << ( unsigned int )_variableDatumRecords.size();

     for(size_t idx = 0; idx < _fixedDatumRecords.size(); idx++)
     {
        FixedDatum x = _fixedDatumRecords[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < _variableDatumRecords.size(); idx++)
     {
        VariableDatum x = _variableDatumRecords[idx];
        x.marshal(dataStream);
     }

}

void ActionResponseReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _requestID;
    dataStream >> _responseStatus;
    dataStream >> _numberOfFixedDatumRecords;
    dataStream >> _numberOfVariableDatumRecords;

     _fixedDatumRecords.clear();
     for(size_t idx = 0; idx < _numberOfFixedDatumRecords; idx++)
     {
        FixedDatum x;
        x.unmarshal(dataStream);
        _fixedDatumRecords.push_back(x);
     }

     _variableDatumRecords.clear();
     for(size_t idx = 0; idx < _numberOfVariableDatumRecords; idx++)
     {
        VariableDatum x;
        x.unmarshal(dataStream);
        _variableDatumRecords.push_back(x);
     }
}


bool ActionResponseReliablePdu::operator ==(const ActionResponseReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;
     if( ! (_responseStatus == rhs._responseStatus) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _fixedDatumRecords.size(); idx++)
     {
        if( ! ( _fixedDatumRecords[idx] == rhs._fixedDatumRecords[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < _variableDatumRecords.size(); idx++)
     {
        if( ! ( _variableDatumRecords[idx] == rhs._variableDatumRecords[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ActionResponseReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 4;  // _requestID
   marshalSize = marshalSize + 4;  // _responseStatus
   marshalSize = marshalSize + 4;  // _numberOfFixedDatumRecords
   marshalSize = marshalSize + 4;  // _numberOfVariableDatumRecords

   for(int idx=0; idx < _fixedDatumRecords.size(); idx++)
   {
        FixedDatum listElement = _fixedDatumRecords[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < _variableDatumRecords.size(); idx++)
   {
        VariableDatum listElement = _variableDatumRecords[idx];
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
