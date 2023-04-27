#include "dis6/ApaData.h"

using namespace DIS;

ApaData::ApaData() : _parameterIndex(0), _parameterValue(0) {}

ApaData::~ApaData() {}

uint16_t ApaData::getParameterIndex() const { return _parameterIndex; }

void ApaData::setParameterIndex(uint16_t pX) { _parameterIndex = pX; }

int16_t ApaData::getParameterValue() const { return _parameterValue; }

void ApaData::setParameterValue(int16_t pX) { _parameterValue = pX; }

void ApaData::marshal(DataStream& dataStream) const {
  dataStream << _parameterIndex;
  dataStream << _parameterValue;
}

void ApaData::unmarshal(DataStream& dataStream) {
  dataStream >> _parameterIndex;
  dataStream >> _parameterValue;
}

bool ApaData::operator==(const ApaData& rhs) const {
  bool ivarsEqual = true;

  if (!(_parameterIndex == rhs._parameterIndex)) ivarsEqual = false;
  if (!(_parameterValue == rhs._parameterValue)) ivarsEqual = false;

  return ivarsEqual;
}

int ApaData::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = marshalSize + 2;  // _parameterIndex
  marshalSize = marshalSize + 2;  // _parameterValue
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
