#include "dis6/distributed_emissions/AcousticEmitterSystem.h"

namespace dis {
AcousticEmitterSystem::AcousticEmitterSystem()
    : acoustic_name_(0), acoustic_function_(0), acoustic_id_(0) {}

uint16_t AcousticEmitterSystem::GetAcousticName() const {
  return acoustic_name_;
}

void AcousticEmitterSystem::SetAcousticName(uint16_t pX) {
  acoustic_name_ = pX;
}

uint8_t AcousticEmitterSystem::GetAcousticFunction() const {
  return acoustic_function_;
}

void AcousticEmitterSystem::SetAcousticFunction(uint8_t pX) {
  acoustic_function_ = pX;
}

uint8_t AcousticEmitterSystem::GetAcousticId() const { return acoustic_id_; }

void AcousticEmitterSystem::SetAcousticId(uint8_t pX) { acoustic_id_ = pX; }

void AcousticEmitterSystem::Marshal(DataStream& dataStream) const {
  dataStream << acoustic_name_;
  dataStream << acoustic_function_;
  dataStream << acoustic_id_;
}

void AcousticEmitterSystem::Unmarshal(DataStream& dataStream) {
  dataStream >> acoustic_name_;
  dataStream >> acoustic_function_;
  dataStream >> acoustic_id_;
}

bool AcousticEmitterSystem::operator==(const AcousticEmitterSystem& rhs) const {
  bool ivars_equal = true;

  if (acoustic_name_ != rhs.acoustic_name_) {
    ivars_equal = false;
  }
  if (acoustic_function_ != rhs.acoustic_function_) {
    ivars_equal = false;
  }
  if (acoustic_id_ != rhs.acoustic_id_) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int AcousticEmitterSystem::GetMarshalledSize() {
  int marshal_size = 0;

  marshal_size = marshal_size + 2;  // acoustic_name_
  marshal_size = marshal_size + 1;  // acoustic_function_
  marshal_size = marshal_size + 1;  // acoustic_id_
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
