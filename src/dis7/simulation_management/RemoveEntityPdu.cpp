#include "dis7/RemoveEntityPdu.h"

using namespace DIS;

RemoveEntityPdu::RemoveEntityPdu()
    : SimulationManagementFamilyPdu(),
      _originatingID(),
      _receivingID(),
      _requestID(0) {
  setPduType(12);
}

RemoveEntityPdu::~RemoveEntityPdu() {}

EntityID& RemoveEntityPdu::getOriginatingID() { return _originatingID; }

const EntityID& RemoveEntityPdu::getOriginatingID() const {
  return _originatingID;
}

void RemoveEntityPdu::setOriginatingID(const EntityID& pX) {
  _originatingID = pX;
}

EntityID& RemoveEntityPdu::getReceivingID() { return _receivingID; }

const EntityID& RemoveEntityPdu::getReceivingID() const { return _receivingID; }

void RemoveEntityPdu::setReceivingID(const EntityID& pX) { _receivingID = pX; }

uint32_t RemoveEntityPdu::getRequestID() const { return _requestID; }

void RemoveEntityPdu::setRequestID(uint32_t pX) { _requestID = pX; }

void RemoveEntityPdu::marshal(DataStream& dataStream) const {
  SimulationManagementFamilyPdu::marshal(
      dataStream);  // Marshal information in superclass first
  _originatingID.marshal(dataStream);
  _receivingID.marshal(dataStream);
  dataStream << _requestID;
}

void RemoveEntityPdu::unmarshal(DataStream& dataStream) {
  SimulationManagementFamilyPdu::unmarshal(
      dataStream);  // unmarshal information in superclass first
  _originatingID.unmarshal(dataStream);
  _receivingID.unmarshal(dataStream);
  dataStream >> _requestID;
}

bool RemoveEntityPdu::operator==(const RemoveEntityPdu& rhs) const {
  bool ivarsEqual = true;

  ivarsEqual = SimulationManagementFamilyPdu::operator==(rhs);

  if (!(_originatingID == rhs._originatingID)) ivarsEqual = false;
  if (!(_receivingID == rhs._receivingID)) ivarsEqual = false;
  if (!(_requestID == rhs._requestID)) ivarsEqual = false;

  return ivarsEqual;
}

int RemoveEntityPdu::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = SimulationManagementFamilyPdu::getMarshalledSize();
  marshalSize =
      marshalSize + _originatingID.getMarshalledSize();  // _originatingID
  marshalSize = marshalSize + _receivingID.getMarshalledSize();  // _receivingID
  marshalSize = marshalSize + 4;                                 // _requestID
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