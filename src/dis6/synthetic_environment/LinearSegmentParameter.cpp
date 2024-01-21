#include "dis6/synthetic_environment/LinearSegmentParameter.h"

using namespace DIS;

LinearSegmentParameter::LinearSegmentParameter()
    : _segmentNumber(0),

      _segmentLength(0),
      _segmentWidth(0),
      _segmentHeight(0),
      _segmentDepth(0),
      _pad1(0) {}

LinearSegmentParameter::~LinearSegmentParameter() = default;

uint8_t LinearSegmentParameter::getSegmentNumber() const {
  return _segmentNumber;
}

void LinearSegmentParameter::setSegmentNumber(uint8_t pX) {
  _segmentNumber = pX;
}

SixByteChunk& LinearSegmentParameter::getSegmentAppearance() {
  return _segmentAppearance;
}

const SixByteChunk& LinearSegmentParameter::getSegmentAppearance() const {
  return _segmentAppearance;
}

void LinearSegmentParameter::setSegmentAppearance(const SixByteChunk& pX) {
  _segmentAppearance = pX;
}

Vector3Double& LinearSegmentParameter::getLocation() { return _location; }

const Vector3Double& LinearSegmentParameter::getLocation() const {
  return _location;
}

void LinearSegmentParameter::setLocation(const Vector3Double& pX) {
  _location = pX;
}

Orientation& LinearSegmentParameter::getOrientation() { return _orientation; }

const Orientation& LinearSegmentParameter::getOrientation() const {
  return _orientation;
}

void LinearSegmentParameter::setOrientation(const Orientation& pX) {
  _orientation = pX;
}

uint16_t LinearSegmentParameter::getSegmentLength() const {
  return _segmentLength;
}

void LinearSegmentParameter::setSegmentLength(uint16_t pX) {
  _segmentLength = pX;
}

uint16_t LinearSegmentParameter::getSegmentWidth() const {
  return _segmentWidth;
}

void LinearSegmentParameter::setSegmentWidth(uint16_t pX) {
  _segmentWidth = pX;
}

uint16_t LinearSegmentParameter::getSegmentHeight() const {
  return _segmentHeight;
}

void LinearSegmentParameter::setSegmentHeight(uint16_t pX) {
  _segmentHeight = pX;
}

uint16_t LinearSegmentParameter::getSegmentDepth() const {
  return _segmentDepth;
}

void LinearSegmentParameter::setSegmentDepth(uint16_t pX) {
  _segmentDepth = pX;
}

uint32_t LinearSegmentParameter::getPad1() const { return _pad1; }

void LinearSegmentParameter::setPad1(uint32_t pX) { _pad1 = pX; }

void LinearSegmentParameter::Marshal(DataStream& dataStream) const {
  dataStream << _segmentNumber;
  _segmentAppearance.marshal(dataStream);
  _location.marshal(dataStream);
  _orientation.marshal(dataStream);
  dataStream << _segmentLength;
  dataStream << _segmentWidth;
  dataStream << _segmentHeight;
  dataStream << _segmentDepth;
  dataStream << _pad1;
}

void LinearSegmentParameter::Unmarshal(DataStream& dataStream) {
  dataStream >> _segmentNumber;
  _segmentAppearance.unmarshal(dataStream);
  _location.unmarshal(dataStream);
  _orientation.unmarshal(dataStream);
  dataStream >> _segmentLength;
  dataStream >> _segmentWidth;
  dataStream >> _segmentHeight;
  dataStream >> _segmentDepth;
  dataStream >> _pad1;
}

bool LinearSegmentParameter::operator==(
    const LinearSegmentParameter& rhs) const {
  bool ivars_equal = true;

  if (!(_segmentNumber == rhs._segmentNumber)) {
    ivars_equal = false;
  }
  if (!(_segmentAppearance == rhs._segmentAppearance)) {
    ivars_equal = false;
  }
  if (!(_location == rhs._location)) {
    ivars_equal = false;
  }
  if (!(_orientation == rhs._orientation)) {
    ivars_equal = false;
  }
  if (!(_segmentLength == rhs._segmentLength)) {
    ivars_equal = false;
  }
  if (!(_segmentWidth == rhs._segmentWidth)) {
    ivars_equal = false;
  }
  if (!(_segmentHeight == rhs._segmentHeight)) {
    ivars_equal = false;
  }
  if (!(_segmentDepth == rhs._segmentDepth)) {
    ivars_equal = false;
  }
  if (!(_pad1 == rhs._pad1)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int LinearSegmentParameter::getMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = marshal_size + 1;  // _segmentNumber
  marshal_size = marshal_size +
                 _segmentAppearance.getMarshalledSize();  // _segmentAppearance
  marshal_size = marshal_size + _location.getMarshalledSize();  // _location
  marshal_size =
      marshal_size + _orientation.getMarshalledSize();  // _orientation
  marshal_size = marshal_size + 2;                      // _segmentLength
  marshal_size = marshal_size + 2;                      // _segmentWidth
  marshal_size = marshal_size + 2;                      // _segmentHeight
  marshal_size = marshal_size + 2;                      // _segmentDepth
  marshal_size = marshal_size + 4;                      // _pad1
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
