#include "dis6/distributed_emissions/UnderwaterAcousticsPdu.h"

using namespace DIS;

UnderwaterAcousticsPdu::UnderwaterAcousticsPdu()
    : DistributedEmissionsFamilyPdu(),
      _emittingEntityID(),
      _eventID(),
      _stateChangeIndicator(0),
      _pad(0),
      _passiveParameterIndex(0),
      _propulsionPlantConfiguration(0),
      _numberOfShafts(0),
      _numberOfAPAs(0),
      _numberOfUAEmitterSystems(0) {
  setPduType(29);
}

UnderwaterAcousticsPdu::~UnderwaterAcousticsPdu() {
  _shaftRPMs.clear();
  _apaData.clear();
  _emitterSystems.clear();
}

EntityID& UnderwaterAcousticsPdu::getEmittingEntityID() {
  return _emittingEntityID;
}

const EntityID& UnderwaterAcousticsPdu::getEmittingEntityID() const {
  return _emittingEntityID;
}

void UnderwaterAcousticsPdu::setEmittingEntityID(const EntityID& pX) {
  _emittingEntityID = pX;
}

EventID& UnderwaterAcousticsPdu::getEventID() { return _eventID; }

const EventID& UnderwaterAcousticsPdu::getEventID() const { return _eventID; }

void UnderwaterAcousticsPdu::setEventID(const EventID& pX) { _eventID = pX; }

char UnderwaterAcousticsPdu::getStateChangeIndicator() const {
  return _stateChangeIndicator;
}

void UnderwaterAcousticsPdu::setStateChangeIndicator(char pX) {
  _stateChangeIndicator = pX;
}

char UnderwaterAcousticsPdu::getPad() const { return _pad; }

void UnderwaterAcousticsPdu::setPad(char pX) { _pad = pX; }

uint16_t UnderwaterAcousticsPdu::getPassiveParameterIndex() const {
  return _passiveParameterIndex;
}

void UnderwaterAcousticsPdu::setPassiveParameterIndex(uint16_t pX) {
  _passiveParameterIndex = pX;
}

uint8_t UnderwaterAcousticsPdu::getPropulsionPlantConfiguration() const {
  return _propulsionPlantConfiguration;
}

void UnderwaterAcousticsPdu::setPropulsionPlantConfiguration(uint8_t pX) {
  _propulsionPlantConfiguration = pX;
}

uint8_t UnderwaterAcousticsPdu::getNumberOfShafts() const {
  return _shaftRPMs.size();
}

uint8_t UnderwaterAcousticsPdu::getNumberOfAPAs() const {
  return _apaData.size();
}

uint8_t UnderwaterAcousticsPdu::getNumberOfUAEmitterSystems() const {
  return _emitterSystems.size();
}

std::vector<ShaftRPMs>& UnderwaterAcousticsPdu::getShaftRPMs() {
  return _shaftRPMs;
}

const std::vector<ShaftRPMs>& UnderwaterAcousticsPdu::getShaftRPMs() const {
  return _shaftRPMs;
}

void UnderwaterAcousticsPdu::setShaftRPMs(const std::vector<ShaftRPMs>& pX) {
  _shaftRPMs = pX;
}

std::vector<ApaData>& UnderwaterAcousticsPdu::getApaData() { return _apaData; }

const std::vector<ApaData>& UnderwaterAcousticsPdu::getApaData() const {
  return _apaData;
}

void UnderwaterAcousticsPdu::setApaData(const std::vector<ApaData>& pX) {
  _apaData = pX;
}

std::vector<AcousticEmitterSystemData>&
UnderwaterAcousticsPdu::getEmitterSystems() {
  return _emitterSystems;
}

const std::vector<AcousticEmitterSystemData>&
UnderwaterAcousticsPdu::getEmitterSystems() const {
  return _emitterSystems;
}

void UnderwaterAcousticsPdu::setEmitterSystems(
    const std::vector<AcousticEmitterSystemData>& pX) {
  _emitterSystems = pX;
}

void UnderwaterAcousticsPdu::marshal(DataStream& dataStream) const {
  DistributedEmissionsFamilyPdu::marshal(
      dataStream);  // Marshal information in superclass first
  _emittingEntityID.marshal(dataStream);
  _eventID.marshal(dataStream);
  dataStream << _stateChangeIndicator;
  dataStream << _pad;
  dataStream << _passiveParameterIndex;
  dataStream << _propulsionPlantConfiguration;
  dataStream << (uint8_t)_shaftRPMs.size();
  dataStream << (uint8_t)_apaData.size();
  dataStream << (uint8_t)_emitterSystems.size();

  for (size_t idx = 0; idx < _shaftRPMs.size(); idx++) {
    ShaftRPMs x = _shaftRPMs[idx];
    x.marshal(dataStream);
  }

  for (size_t idx = 0; idx < _apaData.size(); idx++) {
    ApaData x = _apaData[idx];
    x.marshal(dataStream);
  }

  for (size_t idx = 0; idx < _emitterSystems.size(); idx++) {
    AcousticEmitterSystemData x = _emitterSystems[idx];
    x.marshal(dataStream);
  }
}

void UnderwaterAcousticsPdu::unmarshal(DataStream& dataStream) {
  DistributedEmissionsFamilyPdu::unmarshal(
      dataStream);  // unmarshal information in superclass first
  _emittingEntityID.unmarshal(dataStream);
  _eventID.unmarshal(dataStream);
  dataStream >> _stateChangeIndicator;
  dataStream >> _pad;
  dataStream >> _passiveParameterIndex;
  dataStream >> _propulsionPlantConfiguration;
  dataStream >> _numberOfShafts;
  dataStream >> _numberOfAPAs;
  dataStream >> _numberOfUAEmitterSystems;

  _shaftRPMs.clear();
  for (size_t idx = 0; idx < _numberOfShafts; idx++) {
    ShaftRPMs x;
    x.unmarshal(dataStream);
    _shaftRPMs.push_back(x);
  }

  _apaData.clear();
  for (size_t idx = 0; idx < _numberOfAPAs; idx++) {
    ApaData x;
    x.unmarshal(dataStream);
    _apaData.push_back(x);
  }

  _emitterSystems.clear();
  for (size_t idx = 0; idx < _numberOfUAEmitterSystems; idx++) {
    AcousticEmitterSystemData x;
    x.unmarshal(dataStream);
    _emitterSystems.push_back(x);
  }
}

bool UnderwaterAcousticsPdu::operator==(
    const UnderwaterAcousticsPdu& rhs) const {
  bool ivarsEqual = true;

  ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

  if (!(_emittingEntityID == rhs._emittingEntityID)) ivarsEqual = false;
  if (!(_eventID == rhs._eventID)) ivarsEqual = false;
  if (!(_stateChangeIndicator == rhs._stateChangeIndicator)) ivarsEqual = false;
  if (!(_pad == rhs._pad)) ivarsEqual = false;
  if (!(_passiveParameterIndex == rhs._passiveParameterIndex))
    ivarsEqual = false;
  if (!(_propulsionPlantConfiguration == rhs._propulsionPlantConfiguration))
    ivarsEqual = false;

  for (size_t idx = 0; idx < _shaftRPMs.size(); idx++) {
    if (!(_shaftRPMs[idx] == rhs._shaftRPMs[idx])) ivarsEqual = false;
  }

  for (size_t idx = 0; idx < _apaData.size(); idx++) {
    if (!(_apaData[idx] == rhs._apaData[idx])) ivarsEqual = false;
  }

  for (size_t idx = 0; idx < _emitterSystems.size(); idx++) {
    if (!(_emitterSystems[idx] == rhs._emitterSystems[idx])) ivarsEqual = false;
  }

  return ivarsEqual;
}

int UnderwaterAcousticsPdu::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
  marshalSize =
      marshalSize + _emittingEntityID.getMarshalledSize();  // _emittingEntityID
  marshalSize = marshalSize + _eventID.getMarshalledSize();  // _eventID
  marshalSize = marshalSize + 1;  // _stateChangeIndicator
  marshalSize = marshalSize + 1;  // _pad
  marshalSize = marshalSize + 2;  // _passiveParameterIndex
  marshalSize = marshalSize + 1;  // _propulsionPlantConfiguration
  marshalSize = marshalSize + 1;  // _numberOfShafts
  marshalSize = marshalSize + 1;  // _numberOfAPAs
  marshalSize = marshalSize + 1;  // _numberOfUAEmitterSystems

  for (uint64_t idx = 0; idx < _shaftRPMs.size(); idx++) {
    ShaftRPMs listElement = _shaftRPMs[idx];
    marshalSize = marshalSize + listElement.getMarshalledSize();
  }

  for (uint64_t idx = 0; idx < _apaData.size(); idx++) {
    ApaData listElement = _apaData[idx];
    marshalSize = marshalSize + listElement.getMarshalledSize();
  }

  for (uint64_t idx = 0; idx < _emitterSystems.size(); idx++) {
    AcousticEmitterSystemData listElement = _emitterSystems[idx];
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