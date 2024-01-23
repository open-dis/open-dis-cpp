#include "dis6/distributed_emissions/ElectromagneticEmissionSystemData.h"

namespace dis {
ElectromagneticEmissionSystemData::ElectromagneticEmissionSystemData()
    : system_data_length_(0), number_of_beams_(0), emissions_padding2_(0) {}

ElectromagneticEmissionSystemData::~ElectromagneticEmissionSystemData() {
  beam_data_records_.clear();
}

uint8_t ElectromagneticEmissionSystemData::GetSystemDataLength() const {
  return system_data_length_;
}

void ElectromagneticEmissionSystemData::SetSystemDataLength(uint8_t pX) {
  system_data_length_ = pX;
}

uint8_t ElectromagneticEmissionSystemData::GetNumberOfBeams() const {
  return beam_data_records_.size();
}

uint16_t ElectromagneticEmissionSystemData::GetEmissionsPadding2() const {
  return emissions_padding2_;
}

void ElectromagneticEmissionSystemData::SetEmissionsPadding2(uint16_t pX) {
  emissions_padding2_ = pX;
}

EmitterSystem& ElectromagneticEmissionSystemData::GetEmitterSystem() {
  return emitter_system_;
}

const EmitterSystem& ElectromagneticEmissionSystemData::GetEmitterSystem()
    const {
  return emitter_system_;
}

void ElectromagneticEmissionSystemData::SetEmitterSystem(
    const EmitterSystem& pX) {
  emitter_system_ = pX;
}

Vector3Float& ElectromagneticEmissionSystemData::GetLocation() {
  return location_;
}

const Vector3Float& ElectromagneticEmissionSystemData::GetLocation() const {
  return location_;
}

void ElectromagneticEmissionSystemData::SetLocation(const Vector3Float& pX) {
  location_ = pX;
}

std::vector<ElectromagneticEmissionBeamData>&
ElectromagneticEmissionSystemData::GetBeamDataRecords() {
  return beam_data_records_;
}

const std::vector<ElectromagneticEmissionBeamData>&
ElectromagneticEmissionSystemData::GetBeamDataRecords() const {
  return beam_data_records_;
}

void ElectromagneticEmissionSystemData::SetBeamDataRecords(
    const std::vector<ElectromagneticEmissionBeamData>& pX) {
  beam_data_records_ = pX;
}

void ElectromagneticEmissionSystemData::Marshal(DataStream& dataStream) const {
  dataStream << system_data_length_;
  dataStream << static_cast<uint8_t>(beam_data_records_.size());
  dataStream << emissions_padding2_;
  emitter_system_.Marshal(dataStream);
  location_.Marshal(dataStream);

  for (const auto& x : beam_data_records_) {
    x.Marshal(dataStream);
  }
}

void ElectromagneticEmissionSystemData::Unmarshal(DataStream& dataStream) {
  dataStream >> system_data_length_;
  dataStream >> number_of_beams_;
  dataStream >> emissions_padding2_;
  emitter_system_.Unmarshal(dataStream);
  location_.Unmarshal(dataStream);

  beam_data_records_.clear();
  for (size_t idx = 0; idx < number_of_beams_; idx++) {
    ElectromagneticEmissionBeamData x;
    x.Unmarshal(dataStream);
    beam_data_records_.push_back(x);
  }
}

bool ElectromagneticEmissionSystemData::operator==(
    const ElectromagneticEmissionSystemData& rhs) const {
  bool ivars_equal = true;

  if (!(system_data_length_ == rhs.system_data_length_)) {
    ivars_equal = false;
  }
  if (!(emissions_padding2_ == rhs.emissions_padding2_)) {
    ivars_equal = false;
  }
  if (!(emitter_system_ == rhs.emitter_system_)) {
    ivars_equal = false;
  }
  if (!(location_ == rhs.location_)) {
    ivars_equal = false;
  }

  for (size_t idx = 0; idx < beam_data_records_.size(); idx++) {
    if (!(beam_data_records_[idx] == rhs.beam_data_records_[idx])) {
      ivars_equal = false;
    }
  }

  return ivars_equal;
}

size_t ElectromagneticEmissionSystemData::GetMarshalledSize() const {
  size_t marshal_size = sizeof(system_data_length_) + sizeof(number_of_beams_) +
                        sizeof(emissions_padding2_) +
                        emitter_system_.GetMarshalledSize() +
                        location_.GetMarshalledSize();

  for (const auto& list_element : beam_data_records_) {
    marshal_size += list_element.GetMarshalledSize();
  }

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
