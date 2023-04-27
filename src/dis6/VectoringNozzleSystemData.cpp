#include "dis6/VectoringNozzleSystemData.h"

using namespace DIS;

VectoringNozzleSystemData::VectoringNozzleSystemData()
    : _horizontalDeflectionAngle(0.0), _verticalDeflectionAngle(0.0) {}

VectoringNozzleSystemData::~VectoringNozzleSystemData() {}

float VectoringNozzleSystemData::getHorizontalDeflectionAngle() const {
  return _horizontalDeflectionAngle;
}

void VectoringNozzleSystemData::setHorizontalDeflectionAngle(float pX) {
  _horizontalDeflectionAngle = pX;
}

float VectoringNozzleSystemData::getVerticalDeflectionAngle() const {
  return _verticalDeflectionAngle;
}

void VectoringNozzleSystemData::setVerticalDeflectionAngle(float pX) {
  _verticalDeflectionAngle = pX;
}

void VectoringNozzleSystemData::marshal(DataStream& dataStream) const {
  dataStream << _horizontalDeflectionAngle;
  dataStream << _verticalDeflectionAngle;
}

void VectoringNozzleSystemData::unmarshal(DataStream& dataStream) {
  dataStream >> _horizontalDeflectionAngle;
  dataStream >> _verticalDeflectionAngle;
}

bool VectoringNozzleSystemData::operator==(
    const VectoringNozzleSystemData& rhs) const {
  bool ivarsEqual = true;

  if (!(_horizontalDeflectionAngle == rhs._horizontalDeflectionAngle))
    ivarsEqual = false;
  if (!(_verticalDeflectionAngle == rhs._verticalDeflectionAngle))
    ivarsEqual = false;

  return ivarsEqual;
}

int VectoringNozzleSystemData::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = marshalSize + 4;  // _horizontalDeflectionAngle
  marshalSize = marshalSize + 4;  // _verticalDeflectionAngle
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
