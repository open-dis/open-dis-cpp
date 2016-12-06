#include <DIS/ActionRequestPdu.h> 

using namespace DIS;


ActionRequestPdu::ActionRequestPdu() : SimulationManagementFamilyPdu(),
   _originatingID(), 
   _receivingID(), 
   _requestID(0), 
   _actionID(0), 
   _numberOfFixedDatumRecords(0), 
   _numberOfVariableDatumRecords(0)
{
    setPduType( 16 );
}

ActionRequestPdu::~ActionRequestPdu()
{
    _fixedDatums.clear();
    _variableDatums.clear();
}

EntityID& ActionRequestPdu::getOriginatingID() 
{
    return _originatingID;
}

const EntityID& ActionRequestPdu::getOriginatingID() const
{
    return _originatingID;
}

void ActionRequestPdu::setOriginatingID(const EntityID &pX)
{
    _originatingID = pX;
}

EntityID& ActionRequestPdu::getReceivingID() 
{
    return _receivingID;
}

const EntityID& ActionRequestPdu::getReceivingID() const
{
    return _receivingID;
}

void ActionRequestPdu::setReceivingID(const EntityID &pX)
{
    _receivingID = pX;
}

unsigned int ActionRequestPdu::getRequestID() const
{
    return _requestID;
}

void ActionRequestPdu::setRequestID(unsigned int pX)
{
    _requestID = pX;
}

unsigned int ActionRequestPdu::getActionID() const
{
    return _actionID;
}

void ActionRequestPdu::setActionID(unsigned int pX)
{
    _actionID = pX;
}

unsigned int ActionRequestPdu::getNumberOfFixedDatumRecords() const
{
   return _fixedDatums.size();
}

unsigned int ActionRequestPdu::getNumberOfVariableDatumRecords() const
{
   return _variableDatums.size();
}

std::vector<FixedDatum>& ActionRequestPdu::getFixedDatums() 
{
    return _fixedDatums;
}

const std::vector<FixedDatum>& ActionRequestPdu::getFixedDatums() const
{
    return _fixedDatums;
}

void ActionRequestPdu::setFixedDatums(const std::vector<FixedDatum>& pX)
{
     _fixedDatums = pX;
}

std::vector<VariableDatum>& ActionRequestPdu::getVariableDatums() 
{
    return _variableDatums;
}

const std::vector<VariableDatum>& ActionRequestPdu::getVariableDatums() const
{
    return _variableDatums;
}

void ActionRequestPdu::setVariableDatums(const std::vector<VariableDatum>& pX)
{
     _variableDatums = pX;
}

void ActionRequestPdu::marshal(DataStream& dataStream) const
{
    SimulationManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _originatingID.marshal(dataStream);
    _receivingID.marshal(dataStream);
    dataStream << _requestID;
    dataStream << _actionID;
    dataStream << ( unsigned int )_fixedDatums.size();
    dataStream << ( unsigned int )_variableDatums.size();

     for(size_t idx = 0; idx < _fixedDatums.size(); idx++)
     {
        FixedDatum x = _fixedDatums[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < _variableDatums.size(); idx++)
     {
        VariableDatum x = _variableDatums[idx];
        x.marshal(dataStream);
     }

}

void ActionRequestPdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _originatingID.unmarshal(dataStream);
    _receivingID.unmarshal(dataStream);
    dataStream >> _requestID;
    dataStream >> _actionID;
    dataStream >> _numberOfFixedDatumRecords;
    dataStream >> _numberOfVariableDatumRecords;

     _fixedDatums.clear();
     for(size_t idx = 0; idx < _numberOfFixedDatumRecords; idx++)
     {
        FixedDatum x;
        x.unmarshal(dataStream);
        _fixedDatums.push_back(x);
     }

     _variableDatums.clear();
     for(size_t idx = 0; idx < _numberOfVariableDatumRecords; idx++)
     {
        VariableDatum x;
        x.unmarshal(dataStream);
        _variableDatums.push_back(x);
     }
}


bool ActionRequestPdu::operator ==(const ActionRequestPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementFamilyPdu::operator==(rhs);

     if( ! (_originatingID == rhs._originatingID) ) ivarsEqual = false;
     if( ! (_receivingID == rhs._receivingID) ) ivarsEqual = false;
     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;
     if( ! (_actionID == rhs._actionID) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _fixedDatums.size(); idx++)
     {
        if( ! ( _fixedDatums[idx] == rhs._fixedDatums[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < _variableDatums.size(); idx++)
     {
        if( ! ( _variableDatums[idx] == rhs._variableDatums[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ActionRequestPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _originatingID.getMarshalledSize();  // _originatingID
   marshalSize = marshalSize + _receivingID.getMarshalledSize();  // _receivingID
   marshalSize = marshalSize + 4;  // _requestID
   marshalSize = marshalSize + 4;  // _actionID
   marshalSize = marshalSize + 4;  // _numberOfFixedDatumRecords
   marshalSize = marshalSize + 4;  // _numberOfVariableDatumRecords

   for(int idx=0; idx < _fixedDatums.size(); idx++)
   {
        FixedDatum listElement = _fixedDatums[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < _variableDatums.size(); idx++)
   {
        VariableDatum listElement = _variableDatums[idx];
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
