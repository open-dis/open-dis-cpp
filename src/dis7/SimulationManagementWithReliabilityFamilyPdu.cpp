#include <DIS/SimulationManagementWithReliabilityFamilyPdu.h> 

using namespace DIS;


SimulationManagementWithReliabilityFamilyPdu::SimulationManagementWithReliabilityFamilyPdu() : Pdu(),
   _originatingEntityID(), 
   _receivingEntityID()
{
    setProtocolFamily( 10 );
}

SimulationManagementWithReliabilityFamilyPdu::~SimulationManagementWithReliabilityFamilyPdu()
{
}

EntityID& SimulationManagementWithReliabilityFamilyPdu::getOriginatingEntityID() 
{
    return _originatingEntityID;
}

const EntityID& SimulationManagementWithReliabilityFamilyPdu::getOriginatingEntityID() const
{
    return _originatingEntityID;
}

void SimulationManagementWithReliabilityFamilyPdu::setOriginatingEntityID(const EntityID &pX)
{
    _originatingEntityID = pX;
}

EntityID& SimulationManagementWithReliabilityFamilyPdu::getReceivingEntityID() 
{
    return _receivingEntityID;
}

const EntityID& SimulationManagementWithReliabilityFamilyPdu::getReceivingEntityID() const
{
    return _receivingEntityID;
}

void SimulationManagementWithReliabilityFamilyPdu::setReceivingEntityID(const EntityID &pX)
{
    _receivingEntityID = pX;
}

void SimulationManagementWithReliabilityFamilyPdu::marshal(DataStream& dataStream) const
{
    Pdu::marshal(dataStream); // Marshal information in superclass first
    _originatingEntityID.marshal(dataStream);
    _receivingEntityID.marshal(dataStream);
}

void SimulationManagementWithReliabilityFamilyPdu::unmarshal(DataStream& dataStream)
{
    Pdu::unmarshal(dataStream); // unmarshal information in superclass first
    _originatingEntityID.unmarshal(dataStream);
    _receivingEntityID.unmarshal(dataStream);
}


bool SimulationManagementWithReliabilityFamilyPdu::operator ==(const SimulationManagementWithReliabilityFamilyPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = Pdu::operator==(rhs);

     if( ! (_originatingEntityID == rhs._originatingEntityID) ) ivarsEqual = false;
     if( ! (_receivingEntityID == rhs._receivingEntityID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = Pdu::getMarshalledSize();
   marshalSize = marshalSize + _originatingEntityID.getMarshalledSize();  // _originatingEntityID
   marshalSize = marshalSize + _receivingEntityID.getMarshalledSize();  // _receivingEntityID
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
