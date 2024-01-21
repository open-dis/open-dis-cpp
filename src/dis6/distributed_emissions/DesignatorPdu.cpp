#include "dis6/distributed_emissions/DesignatorPdu.h"

using namespace DIS;

dis::DesignatorPdu::DesignatorPdu()
    : _codeName(0),

      _designatorCode(0),
      _designatorPower(0.0),
      _designatorWavelength(0.0),

      _deadReckoningAlgorithm(0),
      _padding1(0),
      _padding2(0) {
  SetPduType(24);
}

dis::DesignatorPdu::~DesignatorPdu() = default;

dis::EntityID& dis::DesignatorPdu::getDesignatingEntityID() {
  return _designatingEntityID;
}

const dis::EntityID& dis::DesignatorPdu::getDesignatingEntityID() const {
  return _designatingEntityID;
}

void dis::DesignatorPdu::setDesignatingEntityID(const EntityID& pX) {
  _designatingEntityID = pX;
}

uint16_t dis::DesignatorPdu::getCodeName() const { return _codeName; }

void dis::DesignatorPdu::setCodeName(uint16_t pX) { _codeName = pX; }

dis::EntityID& dis::DesignatorPdu::getDesignatedEntityID() {
  return _designatedEntityID;
}

const dis::EntityID& dis::DesignatorPdu::getDesignatedEntityID() const {
  return _designatedEntityID;
}

void dis::DesignatorPdu::setDesignatedEntityID(const EntityID& pX) {
  _designatedEntityID = pX;
}

uint16_t dis::DesignatorPdu::getDesignatorCode() const {
  return _designatorCode;
}

void dis::DesignatorPdu::setDesignatorCode(uint16_t pX) {
  _designatorCode = pX;
}

float dis::DesignatorPdu::getDesignatorPower() const {
  return _designatorPower;
}

void dis::DesignatorPdu::setDesignatorPower(float pX) { _designatorPower = pX; }

float dis::DesignatorPdu::getDesignatorWavelength() const {
  return _designatorWavelength;
}

void dis::DesignatorPdu::setDesignatorWavelength(float pX) {
  _designatorWavelength = pX;
}

Vector3Float& dis::DesignatorPdu::getDesignatorSpotWrtDesignated() {
  return _designatorSpotWrtDesignated;
}

const Vector3Float& dis::DesignatorPdu::getDesignatorSpotWrtDesignated() const {
  return _designatorSpotWrtDesignated;
}

void dis::DesignatorPdu::setDesignatorSpotWrtDesignated(
    const Vector3Float& pX) {
  _designatorSpotWrtDesignated = pX;
}

Vector3Double& dis::DesignatorPdu::getDesignatorSpotLocation() {
  return _designatorSpotLocation;
}

const Vector3Double& dis::DesignatorPdu::getDesignatorSpotLocation() const {
  return _designatorSpotLocation;
}

void dis::DesignatorPdu::setDesignatorSpotLocation(const Vector3Double& pX) {
  _designatorSpotLocation = pX;
}

char dis::DesignatorPdu::getDeadReckoningAlgorithm() const {
  return _deadReckoningAlgorithm;
}

void dis::DesignatorPdu::setDeadReckoningAlgorithm(char pX) {
  _deadReckoningAlgorithm = pX;
}

uint16_t dis::DesignatorPdu::getPadding1() const { return _padding1; }

void dis::DesignatorPdu::setPadding1(uint16_t pX) { _padding1 = pX; }

char dis::DesignatorPdu::getPadding2() const { return _padding2; }

void dis::DesignatorPdu::setPadding2(char pX) { _padding2 = pX; }

Vector3Float& dis::DesignatorPdu::getEntityLinearAcceleration() {
  return _entityLinearAcceleration;
}

const Vector3Float& dis::DesignatorPdu::getEntityLinearAcceleration() const {
  return _entityLinearAcceleration;
}

void dis::DesignatorPdu::setEntityLinearAcceleration(const Vector3Float& pX) {
  _entityLinearAcceleration = pX;
}

void dis::DesignatorPdu::Marshal(DataStream& dataStream) const {
  DistributedEmissionsFamilyPdu::marshal(
      data_stream);  // Marshal information in superclass first
  _designatingEntityID.Marshal(dataStream);
  dataStream << _codeName;
  _designatedEntityID.Marshal(dataStream);
  dataStream << _designatorCode;
  dataStream << _designatorPower;
  dataStream << _designatorWavelength;
  _designatorSpotWrtDesignated.marshal(dataStream);
  _designatorSpotLocation.marshal(dataStream);
  dataStream << _deadReckoningAlgorithm;
  dataStream << _padding1;
  dataStream << _padding2;
  _entityLinearAcceleration.marshal(dataStream);
}

void dis::DesignatorPdu::Unmarshal(DataStream& dataStream) {
  DistributedEmissionsFamilyPdu::unmarshal(
      data_stream);  // unmarshal information in superclass first
  _designatingEntityID.unmarshal(dataStream);
  dataStream >> _codeName;
  _designatedEntityID.unmarshal(dataStream);
  dataStream >> _designatorCode;
  dataStream >> _designatorPower;
  dataStream >> _designatorWavelength;
  _designatorSpotWrtDesignated.unmarshal(dataStream);
  _designatorSpotLocation.unmarshal(dataStream);
  dataStream >> _deadReckoningAlgorithm;
  dataStream >> _padding1;
  dataStream >> _padding2;
  _entityLinearAcceleration.unmarshal(dataStream);
}

bool DesignatorPdu::operator==(const DesignatorPdu& rhs) const {
  bool ivarsEqual = true;

  ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

  if (!(_designatingEntityID == rhs._designatingEntityID)) ivarsEqual = false;
  if (!(_codeName == rhs._codeName)) ivarsEqual = false;
  if (!(_designatedEntityID == rhs._designatedEntityID)) ivarsEqual = false;
  if (!(_designatorCode == rhs._designatorCode)) ivarsEqual = false;
  if (!(_designatorPower == rhs._designatorPower)) ivarsEqual = false;
  if (!(_designatorWavelength == rhs._designatorWavelength)) ivarsEqual = false;
  if (!(_designatorSpotWrtDesignated == rhs._designatorSpotWrtDesignated))
    ivarsEqual = false;
  if (!(_designatorSpotLocation == rhs._designatorSpotLocation))
    ivarsEqual = false;
  if (!(_deadReckoningAlgorithm == rhs._deadReckoningAlgorithm))
    ivarsEqual = false;
  if (!(_padding1 == rhs._padding1)) ivarsEqual = false;
  if (!(_padding2 == rhs._padding2)) ivarsEqual = false;
  if (!(_entityLinearAcceleration == rhs._entityLinearAcceleration))
    ivarsEqual = false;

  return ivarsEqual;
}

int DesignatorPdu::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
  marshalSize =
      marshalSize +
      _designatingEntityID.getMarshalledSize();  // _designatingEntityID
  marshalSize = marshalSize + 2;                 // _codeName
  marshalSize = marshalSize +
                _designatedEntityID.getMarshalledSize();  // _designatedEntityID
  marshalSize = marshalSize + 2;                          // _designatorCode
  marshalSize = marshalSize + 4;                          // _designatorPower
  marshalSize = marshalSize + 4;  // _designatorWavelength
  marshalSize =
      marshalSize + _designatorSpotWrtDesignated
                        .getMarshalledSize();  // _designatorSpotWrtDesignated
  marshalSize =
      marshalSize +
      _designatorSpotLocation.getMarshalledSize();  // _designatorSpotLocation
  marshalSize = marshalSize + 1;                    // _deadReckoningAlgorithm
  marshalSize = marshalSize + 2;                    // _padding1
  marshalSize = marshalSize + 1;                    // _padding2
  marshalSize =
      marshalSize + _entityLinearAcceleration
                        .getMarshalledSize();  // _entityLinearAcceleration
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
