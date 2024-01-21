#include "dis6/synthetic_environment/EnvironmentalProcessPdu.h"

using namespace DIS;

EnvironmentalProcessPdu::EnvironmentalProcessPdu()
    : _modelType(0),
      _environmentStatus(0),
      _numberOfEnvironmentRecords(0),
      _sequenceNumber(0) {
  SetPduType(41);
}

EnvironmentalProcessPdu::~EnvironmentalProcessPdu() {
  _environmentRecords.clear();
}

dis::EntityID& EnvironmentalProcessPdu::getEnvironementalProcessID() {
  return _environementalProcessID;
}

const dis::EntityID& EnvironmentalProcessPdu::getEnvironementalProcessID()
    const {
  return _environementalProcessID;
}

void EnvironmentalProcessPdu::setEnvironementalProcessID(
    const dis::EntityID& pX) {
  _environementalProcessID = pX;
}

dis::EntityType& EnvironmentalProcessPdu::getEnvironmentType() {
  return _environmentType;
}

const dis::EntityType& EnvironmentalProcessPdu::getEnvironmentType() const {
  return _environmentType;
}

void EnvironmentalProcessPdu::setEnvironmentType(const dis::EntityType& pX) {
  _environmentType = pX;
}

uint8_t EnvironmentalProcessPdu::getModelType() const { return _modelType; }

void EnvironmentalProcessPdu::setModelType(uint8_t pX) { _modelType = pX; }

uint8_t EnvironmentalProcessPdu::getEnvironmentStatus() const {
  return _environmentStatus;
}

void EnvironmentalProcessPdu::setEnvironmentStatus(uint8_t pX) {
  _environmentStatus = pX;
}

uint8_t EnvironmentalProcessPdu::getNumberOfEnvironmentRecords() const {
  return _environmentRecords.size();
}

uint16_t EnvironmentalProcessPdu::getSequenceNumber() const {
  return _sequenceNumber;
}

void EnvironmentalProcessPdu::setSequenceNumber(uint16_t pX) {
  _sequenceNumber = pX;
}

std::vector<Environment>& EnvironmentalProcessPdu::getEnvironmentRecords() {
  return _environmentRecords;
}

const std::vector<Environment>& EnvironmentalProcessPdu::getEnvironmentRecords()
    const {
  return _environmentRecords;
}

void EnvironmentalProcessPdu::setEnvironmentRecords(
    const std::vector<Environment>& pX) {
  _environmentRecords = pX;
}

void EnvironmentalProcessPdu::marshal(DataStream& dataStream) const {
  SyntheticEnvironmentFamilyPdu::marshal(
      dataStream);  // Marshal information in superclass first
  _environementalProcessID.Marshal(dataStream);
  _environmentType.Marshal(dataStream);
  dataStream << _modelType;
  dataStream << _environmentStatus;
  dataStream << static_cast<uint8_t>(_environmentRecords.size());
  dataStream << _sequenceNumber;

  for (const auto& x : _environmentRecords) {
    x.marshal(dataStream);
  }
}

void EnvironmentalProcessPdu::unmarshal(DataStream& dataStream) {
  SyntheticEnvironmentFamilyPdu::unmarshal(
      dataStream);  // unmarshal information in superclass first
  _environementalProcessID.Unmarshal(dataStream);
  _environmentType.Unmarshal(dataStream);
  dataStream >> _modelType;
  dataStream >> _environmentStatus;
  dataStream >> _numberOfEnvironmentRecords;
  dataStream >> _sequenceNumber;

  _environmentRecords.clear();
  for (size_t idx = 0; idx < _numberOfEnvironmentRecords; idx++) {
    Environment x;
    x.unmarshal(dataStream);
    _environmentRecords.push_back(x);
  }
}

bool EnvironmentalProcessPdu::operator==(
    const EnvironmentalProcessPdu& rhs) const {
  bool ivars_equal = true;

  ivars_equal = SyntheticEnvironmentFamilyPdu::operator==(rhs);

  if (!(_environementalProcessID == rhs._environementalProcessID)) {
    ivars_equal = false;
  }
  if (!(_environmentType == rhs._environmentType)) {
    ivars_equal = false;
  }
  if (!(_modelType == rhs._modelType)) {
    ivars_equal = false;
  }
  if (!(_environmentStatus == rhs._environmentStatus)) {
    ivars_equal = false;
  }
  if (!(_sequenceNumber == rhs._sequenceNumber)) {
    ivars_equal = false;
  }

  for (size_t idx = 0; idx < _environmentRecords.size(); idx++) {
    if (!(_environmentRecords[idx] == rhs._environmentRecords[idx])) {
      ivars_equal = false;
    }
  }

  return ivars_equal;
}

int EnvironmentalProcessPdu::getMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = SyntheticEnvironmentFamilyPdu::getMarshalledSize();
  marshal_size =
      marshal_size +
      _environementalProcessID.GetMarshalledSize();  // _environementalProcessID
  marshal_size =
      marshal_size + _environmentType.GetMarshalledSize();  // _environmentType
  marshal_size = marshal_size + 1;                          // _modelType
  marshal_size = marshal_size + 1;  // _environmentStatus
  marshal_size = marshal_size + 1;  // _numberOfEnvironmentRecords
  marshal_size = marshal_size + 2;  // _sequenceNumber

  for (const auto& list_element : _environmentRecords) {
    marshal_size = marshal_size + list_element.getMarshalledSize();
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
