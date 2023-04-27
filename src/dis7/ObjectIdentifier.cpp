#include "dis7/ObjectIdentifier.h"

using namespace DIS;

ObjectIdentifier::ObjectIdentifier() : _simulationAddress(), _objectNumber(0) {}

ObjectIdentifier::~ObjectIdentifier() {}

SimulationAddress& ObjectIdentifier::getSimulationAddress() {
  return _simulationAddress;
}

const SimulationAddress& ObjectIdentifier::getSimulationAddress() const {
  return _simulationAddress;
}

void ObjectIdentifier::setSimulationAddress(const SimulationAddress& pX) {
  _simulationAddress = pX;
}

uint16_t ObjectIdentifier::getObjectNumber() const {
  return _objectNumber;
}

void ObjectIdentifier::setObjectNumber(uint16_t pX) {
  _objectNumber = pX;
}

void ObjectIdentifier::marshal(DataStream& dataStream) const {
  _simulationAddress.marshal(dataStream);
  dataStream << _objectNumber;
}

void ObjectIdentifier::unmarshal(DataStream& dataStream) {
  _simulationAddress.unmarshal(dataStream);
  dataStream >> _objectNumber;
}

bool ObjectIdentifier::operator==(const ObjectIdentifier& rhs) const {
  bool ivarsEqual = true;

  if (!(_simulationAddress == rhs._simulationAddress)) ivarsEqual = false;
  if (!(_objectNumber == rhs._objectNumber)) ivarsEqual = false;

  return ivarsEqual;
}

int ObjectIdentifier::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = marshalSize +
                _simulationAddress.getMarshalledSize();  // _simulationAddress
  marshalSize = marshalSize + 2;                         // _objectNumber
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
