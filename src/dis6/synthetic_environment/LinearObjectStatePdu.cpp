#include "dis6/synthetic_environment/LinearObjectStatePdu.h"

using namespace DIS;

LinearObjectStatePdu::LinearObjectStatePdu()
    : _updateNumber(0), _forceID(0), _numberOfSegments(0) {
  SetPduType(44);
}

LinearObjectStatePdu::~LinearObjectStatePdu() {
  _linearSegmentParameters.clear();
}

dis::EntityID& LinearObjectStatePdu::getObjectID() { return _objectID; }

const dis::EntityID& LinearObjectStatePdu::getObjectID() const {
  return _objectID;
}

void LinearObjectStatePdu::setObjectID(const dis::EntityID& pX) {
  _objectID = pX;
}

dis::EntityID& LinearObjectStatePdu::getReferencedObjectID() {
  return _referencedObjectID;
}

const EntityID& LinearObjectStatePdu::getReferencedObjectID() const {
  return _referencedObjectID;
}

void LinearObjectStatePdu::SetReferencedObjectId(const EntityID& pX) {
  _referencedObjectID = pX;
}

uint16_t LinearObjectStatePdu::getUpdateNumber() const { return _updateNumber; }

void LinearObjectStatePdu::setUpdateNumber(uint16_t pX) { _updateNumber = pX; }

uint8_t LinearObjectStatePdu::getForceID() const { return _forceID; }

void LinearObjectStatePdu::setForceID(uint8_t pX) { _forceID = pX; }

uint8_t LinearObjectStatePdu::getNumberOfSegments() const {
  return _linearSegmentParameters.size();
}

SimulationAddress& LinearObjectStatePdu::getRequesterID() {
  return _requesterID;
}

const SimulationAddress& LinearObjectStatePdu::getRequesterID() const {
  return _requesterID;
}

void LinearObjectStatePdu::setRequesterID(const SimulationAddress& pX) {
  _requesterID = pX;
}

SimulationAddress& LinearObjectStatePdu::getReceivingID() {
  return _receivingID;
}

const SimulationAddress& LinearObjectStatePdu::getReceivingID() const {
  return _receivingID;
}

void LinearObjectStatePdu::setReceivingID(const SimulationAddress& pX) {
  _receivingID = pX;
}

ObjectType& LinearObjectStatePdu::getObjectType() { return _objectType; }

const ObjectType& LinearObjectStatePdu::getObjectType() const {
  return _objectType;
}

void LinearObjectStatePdu::setObjectType(const ObjectType& pX) {
  _objectType = pX;
}

std::vector<LinearSegmentParameter>&
LinearObjectStatePdu::GetLinearSegmentParameters() {
  return _linearSegmentParameters;
}

const std::vector<LinearSegmentParameter>&
LinearObjectStatePdu::GetLinearSegmentParameters() const {
  return _linearSegmentParameters;
}

void LinearObjectStatePdu::SetLinearSegmentParameters(
    const std::vector<LinearSegmentParameter>& pX) {
  _linearSegmentParameters = pX;
}

void LinearObjectStatePdu::marshal(DataStream& dataStream) const {
  SyntheticEnvironmentFamilyPdu::marshal(
      dataStream);  // Marshal information in superclass first
  _objectID.marshal(dataStream);
  _referencedObjectID.marshal(dataStream);
  dataStream << _updateNumber;
  dataStream << _forceID;
  dataStream << static_cast<uint8_t>(_linearSegmentParameters.size());
  _requesterID.marshal(dataStream);
  _receivingID.marshal(dataStream);
  _objectType.marshal(dataStream);

  for (auto x : _linearSegmentParameters) {
    x.marshal(dataStream);
  }
}

void LinearObjectStatePdu::unmarshal(DataStream& dataStream) {
  SyntheticEnvironmentFamilyPdu::unmarshal(
      dataStream);  // unmarshal information in superclass first
  _objectID.unmarshal(dataStream);
  _referencedObjectID.unmarshal(dataStream);
  dataStream >> _updateNumber;
  dataStream >> _forceID;
  dataStream >> _numberOfSegments;
  _requesterID.unmarshal(dataStream);
  _receivingID.unmarshal(dataStream);
  _objectType.unmarshal(dataStream);

  _linearSegmentParameters.clear();
  for (size_t idx = 0; idx < _numberOfSegments; idx++) {
    LinearSegmentParameter x;
    x.unmarshal(dataStream);
    _linearSegmentParameters.push_back(x);
  }
}

bool LinearObjectStatePdu::operator==(const LinearObjectStatePdu& rhs) const {
  bool ivars_equal = true;

  ivars_equal = SyntheticEnvironmentFamilyPdu::operator==(rhs);

  if (!(_objectID == rhs._objectID)) {
    ivars_equal = false;
  }
  if (!(_referencedObjectID == rhs._referencedObjectID)) {
    ivars_equal = false;
  }
  if (!(_updateNumber == rhs._updateNumber)) {
    ivars_equal = false;
  }
  if (!(_forceID == rhs._forceID)) {
    ivars_equal = false;
  }
  if (!(_requesterID == rhs._requesterID)) {
    ivars_equal = false;
  }
  if (!(_receivingID == rhs._receivingID)) {
    ivars_equal = false;
  }
  if (!(_objectType == rhs._objectType)) {
    ivars_equal = false;
  }

  for (size_t idx = 0; idx < _linearSegmentParameters.size(); idx++) {
    if (!(_linearSegmentParameters[idx] == rhs._linearSegmentParameters[idx])) {
      ivars_equal = false;
    }
  }

  return ivars_equal;
}

int LinearObjectStatePdu::getMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = SyntheticEnvironmentFamilyPdu::getMarshalledSize();
  marshal_size = marshal_size + _objectID.getMarshalledSize();  // _objectID
  marshal_size =
      marshal_size +
      _referencedObjectID.getMarshalledSize();  // _referencedObjectID
  marshal_size = marshal_size + 2;              // _updateNumber
  marshal_size = marshal_size + 1;              // _forceID
  marshal_size = marshal_size + 1;              // _numberOfSegments
  marshal_size =
      marshal_size + _requesterID.getMarshalledSize();  // _requesterID
  marshal_size =
      marshal_size + _receivingID.getMarshalledSize();  // _receivingID
  marshal_size = marshal_size + _objectType.getMarshalledSize();  // _objectType

  for (auto listElement : _linearSegmentParameters) {
    marshal_size = marshal_size + listElement.getMarshalledSize();
  }

  return marshal_size;
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
