#include "dis6/GridAxisRecord.h"

using namespace DIS;

GridAxisRecord::GridAxisRecord() : _sampleType(0), _dataRepresentation(0) {}

GridAxisRecord::~GridAxisRecord() {}

uint16_t GridAxisRecord::getSampleType() const { return _sampleType; }

void GridAxisRecord::setSampleType(uint16_t pX) { _sampleType = pX; }

uint16_t GridAxisRecord::getDataRepresentation() const {
  return _dataRepresentation;
}

void GridAxisRecord::setDataRepresentation(uint16_t pX) {
  _dataRepresentation = pX;
}

void GridAxisRecord::marshal(DataStream& dataStream) const {
  dataStream << _sampleType;
  dataStream << _dataRepresentation;
}

void GridAxisRecord::unmarshal(DataStream& dataStream) {
  dataStream >> _sampleType;
  dataStream >> _dataRepresentation;
}

bool GridAxisRecord::operator==(const GridAxisRecord& rhs) const {
  bool ivarsEqual = true;

  if (!(_sampleType == rhs._sampleType)) ivarsEqual = false;
  if (!(_dataRepresentation == rhs._dataRepresentation)) ivarsEqual = false;

  return ivarsEqual;
}

int GridAxisRecord::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = marshalSize + 2;  // _sampleType
  marshalSize = marshalSize + 2;  // _dataRepresentation
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
