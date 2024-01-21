#include "dis6/common/EightByteChunk.h"

namespace dis {
EightByteChunk::EightByteChunk() {
  // Initialize fixed length array
  for (char& other_parameter : other_parameters_) {
    other_parameter = 0;
  }
}

EightByteChunk::~EightByteChunk() = default;

char* EightByteChunk::GetOtherParameters() { return other_parameters_; }

const char* EightByteChunk::GetOtherParameters() const {
  return other_parameters_;
}

void EightByteChunk::SetOtherParameters(const char* x) {
  for (int i = 0; i < 8; i++) {
    other_parameters_[i] = x[i];
  }
}

void EightByteChunk::Marshal(DataStream& dataStream) const {
  for (char const other_parameter : other_parameters_) {
    dataStream << other_parameter;
  }
}

void EightByteChunk::Unmarshal(DataStream& dataStream) {
  for (char& other_parameter : other_parameters_) {
    dataStream >> other_parameter;
  }
}

bool EightByteChunk::operator==(const EightByteChunk& rhs) const {
  bool ivars_equal = true;

  for (uint8_t idx = 0; idx < 8; idx++) {
    if (!(other_parameters_[idx] == rhs.other_parameters_[idx])) {
      ivars_equal = false;
    }
  }

  return ivars_equal;
}

int EightByteChunk::GetMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = marshal_size + 8 * 1;  // other_parameters_
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
