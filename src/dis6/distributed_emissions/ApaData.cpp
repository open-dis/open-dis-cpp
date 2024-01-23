#include "dis6/distributed_emissions/ApaData.h"

namespace dis {
ApaData::ApaData() : parameter_index_(0), parameter_value_(0) {}

uint16_t ApaData::GetParameterIndex() const { return parameter_index_; }

void ApaData::SetParameterIndex(uint16_t pX) { parameter_index_ = pX; }

int16_t ApaData::GetParameterValue() const { return parameter_value_; }

void ApaData::SetParameterValue(int16_t pX) { parameter_value_ = pX; }

void ApaData::Marshal(DataStream& dataStream) const {
  dataStream << parameter_index_;
  dataStream << parameter_value_;
}

void ApaData::Unmarshal(DataStream& dataStream) {
  dataStream >> parameter_index_;
  dataStream >> parameter_value_;
}

bool ApaData::operator==(const ApaData& rhs) const {
  bool ivars_equal = true;

  if (!(parameter_index_ == rhs.parameter_index_)) {
    ivars_equal = false;
  }
  if (!(parameter_value_ == rhs.parameter_value_)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int ApaData::GetMarshalledSize() {
  int marshal_size = 0;

  marshal_size = marshal_size + 2;  // _parameterIndex
  marshal_size = marshal_size + 2;  // _parameterValue
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
