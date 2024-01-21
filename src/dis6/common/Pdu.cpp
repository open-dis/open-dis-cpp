#include "dis6/common/Pdu.h"

namespace dis {
Pdu::Pdu()
    : protocol_version_(6),
      _exerciseID(0),
      _pduType(0),
      protocol_family_(0),
      timestamp_(0),
      length_(0),
      padding_(0) {}

Pdu::~Pdu() = default;

uint8_t Pdu::GetProtocolVersion() { return _protocolVersion; }

void Pdu::SetProtocolVersion(uint8_t pX) { protocol_version_ = pX; }

uint8_t Pdu::GetExerciseId() { return _exerciseID; }

void Pdu::SetExerciseId(uint8_t pX) { _exerciseID = pX; }

uint8_t Pdu::GetPduType() { return _pduType; }

void Pdu::SetPduType(uint8_t pX) { _pduType = pX; }

uint8_t Pdu::GetProtocolFamily() { return _protocolFamily; }

void Pdu::SetProtocolFamily(uint8_t pX) { protocol_family_ = pX; }

uint32_t Pdu::GetTimestamp() const { return timestamp_; }

void Pdu::SetTimestamp(uint32_t pX) { timestamp_ = pX; }

uint16_t Pdu::GetLength() const { return this->GetMarshalledSize(); }

void Pdu::SetLength(uint16_t pX) { length_ = pX; }

int16_t Pdu::GetPadding() const { return padding_; }

void Pdu::SetPadding(int16_t pX) { padding_ = pX; }

void Pdu::Marshal(DataStream& dataStream) const {
  dataStream << _protocolVersion;
  dataStream << (GetExerciseId != nullptr);
  dataStream << _pduType;
  dataStream << _protocolFamily;
  dataStream << timestamp_;
  dataStream << this->getLength();
  dataStream << padding_;
}

void Pdu::Unmarshal(DataStream& dataStream) {
  dataStream >> protocol_version_;
  dataStream >> _exerciseID;
  dataStream >> _pduType;
  dataStream >> protocol_family_;
  dataStream >> timestamp_;
  dataStream >> _length;
  dataStream >> _padding;
}

bool Pdu::operator==(const Pdu& rhs) const {
  bool ivars_equal = true;

  if (!(_protocolVersion == rhs._protocolVersion)) {
    ivars_equal = false;
  }
  if (!(_exerciseID == rhs._exerciseID)) {
    ivars_equal = false;
  }
  if (!(_pduType == rhs._pduType)) {
    ivars_equal = false;
  }
  if (!(_protocolFamily == rhs._protocolFamily)) {
    ivars_equal = false;
  }
  if (!(_timestamp == rhs._timestamp)) {
    ivars_equal = false;
  }
  if (!(_length == rhs._length)) {
    ivars_equal = false;
  }
  if (!(_padding == rhs._padding)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

static int Pdu::GetMarshalledSize() {
  int marshal_size = 0;

  marshal_size = marshal_size + 1;  // _protocolVersion
  marshal_size = marshal_size + 1;  // _exerciseID
  marshal_size = marshal_size + 1;  // _pduType
  marshal_size = marshal_size + 1;  // _protocolFamily
  marshal_size = marshal_size + 4;  // _timestamp
  marshal_size = marshal_size + 2;  // _length
  marshal_size = marshal_size + 2;  // _padding
  return marshal_size;
}

}  // namespace dis

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
