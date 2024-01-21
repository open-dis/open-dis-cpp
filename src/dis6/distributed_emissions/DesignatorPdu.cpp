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

EntityID& DesignatorPdu::getDesignatingEntityID() {
  return _designatingEntityID;
}

const EntityID& DesignatorPdu::getDesignatingEntityID() const {
  return _designatingEntityID;
}

void DesignatorPdu::setDesignatingEntityID(const EntityID& pX) {
  _designatingEntityID = pX;
}

uint16_t DesignatorPdu::getCodeName() const { return _codeName; }

void DesignatorPdu::setCodeName(uint16_t pX) { _codeName = pX; }

EntityID& DesignatorPdu::getDesignatedEntityID() { return _designatedEntityID; }

const EntityID& DesignatorPdu::getDesignatedEntityID() const {
  return _designatedEntityID;
}

void DesignatorPdu::setDesignatedEntityID(const EntityID& pX) {
  _designatedEntityID = pX;
}

uint16_t DesignatorPdu::getDesignatorCode() const { return _designatorCode; }

void DesignatorPdu::setDesignatorCode(uint16_t pX) { _designatorCode = pX; }

float DesignatorPdu::getDesignatorPower() const { return _designatorPower; }

void DesignatorPdu::setDesignatorPower(float pX) { _designatorPower = pX; }

float DesignatorPdu::getDesignatorWavelength() const {
  return _designatorWavelength;
}

void DesignatorPdu::setDesignatorWavelength(float pX) {
  _designatorWavelength = pX;
}

Vector3Float& DesignatorPdu::getDesignatorSpotWrtDesignated() {
  return _designatorSpotWrtDesignated;
}

const Vector3Float& DesignatorPdu::getDesignatorSpotWrtDesignated() const {
  return _designatorSpotWrtDesignated;
}

void DesignatorPdu::setDesignatorSpotWrtDesignated(const Vector3Float& pX) {
  _designatorSpotWrtDesignated = pX;
}

Vector3Double& DesignatorPdu::getDesignatorSpotLocation() {
  return _designatorSpotLocation;
}

const Vector3Double& DesignatorPdu::getDesignatorSpotLocation() const {
  return _designatorSpotLocation;
}

void DesignatorPdu::setDesignatorSpotLocation(const Vector3Double& pX) {
  _designatorSpotLocation = pX;
}

char DesignatorPdu::getDeadReckoningAlgorithm() const {
  return _deadReckoningAlgorithm;
}

void DesignatorPdu::setDeadReckoningAlgorithm(char pX) {
  _deadReckoningAlgorithm = pX;
}

uint16_t DesignatorPdu::getPadding1() const { return _padding1; }

void DesignatorPdu::setPadding1(uint16_t pX) { _padding1 = pX; }

char DesignatorPdu::getPadding2() const { return _padding2; }

void DesignatorPdu::setPadding2(char pX) { _padding2 = pX; }

Vector3Float& DesignatorPdu::getEntityLinearAcceleration() {
  return _entityLinearAcceleration;
}

const Vector3Float& DesignatorPdu::getEntityLinearAcceleration() const {
  return _entityLinearAcceleration;
}

void DesignatorPdu::setEntityLinearAcceleration(const Vector3Float& pX) {
  _entityLinearAcceleration = pX;
}

void DesignatorPdu::marshal(DataStream& dataStream) const {
  DistributedEmissionsFamilyPdu::marshal(
      dataStream);  // Marshal information in superclass first
  _designatingEntityID.marshal(dataStream);
  dataStream << _codeName;
  _designatedEntityID.marshal(dataStream);
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

void DesignatorPdu::unmarshal(DataStream& dataStream) {
  DistributedEmissionsFamilyPdu::unmarshal(
      dataStream);  // unmarshal information in superclass first
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
