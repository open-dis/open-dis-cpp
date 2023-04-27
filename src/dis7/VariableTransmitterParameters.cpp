#include "dis7/VariableTransmitterParameters.h"

using namespace DIS;

VariableTransmitterParameters::VariableTransmitterParameters()
    : _recordType(4), _recordLength(4) {}

VariableTransmitterParameters::~VariableTransmitterParameters() {}

uint32_t VariableTransmitterParameters::getRecordType() const {
  return _recordType;
}

void VariableTransmitterParameters::setRecordType(uint32_t pX) {
  _recordType = pX;
}

uint32_t VariableTransmitterParameters::getRecordLength() const {
  return _recordLength;
}

void VariableTransmitterParameters::setRecordLength(uint32_t pX) {
  _recordLength = pX;
}

void VariableTransmitterParameters::marshal(DataStream& dataStream) const {
  dataStream << _recordType;
  dataStream << _recordLength;
}

void VariableTransmitterParameters::unmarshal(DataStream& dataStream) {
  dataStream >> _recordType;
  dataStream >> _recordLength;
}

bool VariableTransmitterParameters::operator==(
    const VariableTransmitterParameters& rhs) const {
  bool ivarsEqual = true;

  if (!(_recordType == rhs._recordType)) ivarsEqual = false;
  if (!(_recordLength == rhs._recordLength)) ivarsEqual = false;

  return ivarsEqual;
}

int VariableTransmitterParameters::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = marshalSize + 4;  // _recordType
  marshalSize = marshalSize + 4;  // _recordLength
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
