#include "dis6/distributed_emissions/AcousticBeamData.h"

namespace dis {

AcousticBeamData::AcousticBeamData()
    : beam_data_length_(0), beam_id_number_(0), pad2_(0) {}

uint16_t AcousticBeamData::GetBeamDataLength() const {
  return beam_data_length_;
}

void AcousticBeamData::SetBeamDataLength(uint16_t pX) {
  beam_data_length_ = pX;
}

uint8_t AcousticBeamData::GetBeamIdNumber() const { return beam_id_number_; }

void AcousticBeamData::SetBeamIdNumber(uint8_t pX) { beam_id_number_ = pX; }

uint16_t AcousticBeamData::GetPad2() const { return pad2_; }

void AcousticBeamData::SetPad2(uint16_t pX) { pad2_ = pX; }

AcousticBeamFundamentalParameter&
AcousticBeamData::GetFundamentalDataParameters() {
  return fundamental_data_parameters_;
}

const AcousticBeamFundamentalParameter&
AcousticBeamData::GetFundamentalDataParameters() const {
  return fundamental_data_parameters_;
}

void AcousticBeamData::SetFundamentalDataParameters(
    const AcousticBeamFundamentalParameter& pX) {
  fundamental_data_parameters_ = pX;
}

void AcousticBeamData::Marshal(DataStream& dataStream) const {
  dataStream << beam_data_length_;
  dataStream << beam_id_number_;
  dataStream << pad2_;
  fundamental_data_parameters_.Marshal(dataStream);
}

void AcousticBeamData::Unmarshal(DataStream& dataStream) {
  dataStream >> beam_data_length_;
  dataStream >> beam_id_number_;
  dataStream >> pad2_;
  fundamental_data_parameters_.Unmarshal(dataStream);
}

bool AcousticBeamData::operator==(const AcousticBeamData& rhs) const {
  bool ivars_equal = true;

  if (!(beam_data_length_ == rhs.beam_data_length_)) {
    ivars_equal = false;
  }
  if (!(beam_id_number_ == rhs.beam_id_number_)) {
    ivars_equal = false;
  }
  if (!(pad2_ == rhs.pad2_)) {
    ivars_equal = false;
  }
  if (!(fundamental_data_parameters_ == rhs.fundamental_data_parameters_)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

size_t AcousticBeamData::GetMarshalledSize() const {
  size_t marshal_size = sizeof(beam_data_length_) + sizeof(beam_id_number_) +
                        sizeof(pad2_) +
                        fundamental_data_parameters_.GetMarshalledSize();
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
