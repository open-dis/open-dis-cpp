#include "dis7/EntityID.h"

using namespace DIS;

EntityID::EntityID() : _simulationAddress(), _entityNumber(0) {}

EntityID::~EntityID() {}

SimulationAddress& EntityID::getSimulationAddress() {
  return _simulationAddress;
}

const SimulationAddress& EntityID::getSimulationAddress() const {
  return _simulationAddress;
}

void EntityID::setSimulationAddress(const SimulationAddress& pX) {
  _simulationAddress = pX;
}

uint16_t EntityID::getEntityNumber() const { return _entityNumber; }

void EntityID::setEntityNumber(uint16_t pX) { _entityNumber = pX; }

void EntityID::marshal(DataStream& dataStream) const {
  _simulationAddress.marshal(dataStream);
  dataStream << _entityNumber;
}

void EntityID::unmarshal(DataStream& dataStream) {
  _simulationAddress.unmarshal(dataStream);
  dataStream >> _entityNumber;
}

bool EntityID::operator==(const EntityID& rhs) const {
  bool ivarsEqual = true;

  if (!(_simulationAddress == rhs._simulationAddress)) ivarsEqual = false;
  if (!(_entityNumber == rhs._entityNumber)) ivarsEqual = false;

  return ivarsEqual;
}

int EntityID::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = marshalSize +
                _simulationAddress.getMarshalledSize();  // _simulationAddress
  marshalSize = marshalSize + 2;                         // _entityNumber
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
