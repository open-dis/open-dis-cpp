#include "dis6/distributed_emissions/AcousticEmitter.h"

namespace dis {
AcousticEmitter::AcousticEmitter()
    : acoustic_name_(0), function_(0), acoustic_id_number_(0) {}

uint16_t AcousticEmitter::GetAcousticName() const { return acoustic_name_; }

void AcousticEmitter::SetAcousticName(uint16_t pX) { acoustic_name_ = pX; }

uint8_t AcousticEmitter::GetFunction() const { return function_; }

void AcousticEmitter::SetFunction(uint8_t pX) { function_ = pX; }

uint8_t AcousticEmitter::GetAcousticIdNumber() const {
  return acoustic_id_number_;
}

void AcousticEmitter::SetAcousticIdNumber(uint8_t pX) {
  acoustic_id_number_ = pX;
}

void AcousticEmitter::Marshal(DataStream& dataStream) const {
  dataStream << acoustic_name_;
  dataStream << function_;
  dataStream << acoustic_id_number_;
}

void AcousticEmitter::Unmarshal(DataStream& dataStream) {
  dataStream >> acoustic_name_;
  dataStream >> function_;
  dataStream >> acoustic_id_number_;
}

bool AcousticEmitter::operator==(const AcousticEmitter& rhs) const {
  bool ivars_equal = true;

  if (acoustic_name_ != rhs.acoustic_name_) {
    ivars_equal = false;
  }
  if (function_ != rhs.function_) {
    ivars_equal = false;
  }
  if (acoustic_id_number_ != rhs.acoustic_id_number_) {
    ivars_equal = false;
  }

  return ivars_equal;
}

size_t AcousticEmitter::GetMarshalledSize() const {
  size_t marshal_size =
      sizeof(acoustic_name_) + sizeof(function_) + sizeof(acoustic_id_number_);
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
