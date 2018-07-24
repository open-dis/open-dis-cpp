#include <DIS/SimulationManagementPduHeader.h> 

using namespace DIS;


SimulationManagementPduHeader::SimulationManagementPduHeader():
   _pduHeader(), 
   _originatingID(), 
   _recevingID()
{
}

SimulationManagementPduHeader::~SimulationManagementPduHeader()
{
}

PduHeader& SimulationManagementPduHeader::getPduHeader() 
{
    return _pduHeader;
}

const PduHeader& SimulationManagementPduHeader::getPduHeader() const
{
    return _pduHeader;
}

void SimulationManagementPduHeader::setPduHeader(const PduHeader &pX)
{
    _pduHeader = pX;
}

EntityID& SimulationManagementPduHeader::getOriginatingID() 
{
    return _originatingID;
}

const EntityID& SimulationManagementPduHeader::getOriginatingID() const
{
    return _originatingID;
}

void SimulationManagementPduHeader::setOriginatingID(const EntityID &pX)
{
    _originatingID = pX;
}

EntityID& SimulationManagementPduHeader::getRecevingID() 
{
    return _recevingID;
}

const EntityID& SimulationManagementPduHeader::getRecevingID() const
{
    return _recevingID;
}

void SimulationManagementPduHeader::setRecevingID(const EntityID &pX)
{
    _recevingID = pX;
}

void SimulationManagementPduHeader::marshal(DataStream& dataStream) const
{
    _pduHeader.marshal(dataStream);
    _originatingID.marshal(dataStream);
    _recevingID.marshal(dataStream);
}

void SimulationManagementPduHeader::unmarshal(DataStream& dataStream)
{
    _pduHeader.unmarshal(dataStream);
    _originatingID.unmarshal(dataStream);
    _recevingID.unmarshal(dataStream);
}


bool SimulationManagementPduHeader::operator ==(const SimulationManagementPduHeader& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_pduHeader == rhs._pduHeader) ) ivarsEqual = false;
     if( ! (_originatingID == rhs._originatingID) ) ivarsEqual = false;
     if( ! (_recevingID == rhs._recevingID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int SimulationManagementPduHeader::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _pduHeader.getMarshalledSize();  // _pduHeader
   marshalSize = marshalSize + _originatingID.getMarshalledSize();  // _originatingID
   marshalSize = marshalSize + _recevingID.getMarshalledSize();  // _recevingID
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
