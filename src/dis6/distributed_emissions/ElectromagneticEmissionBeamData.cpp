#include "dis6/distributed_emissions/ElectromagneticEmissionBeamData.h"

namespace dis {
ElectromagneticEmissionBeamData::ElectromagneticEmissionBeamData()
    : beam_data_length_(0),
      beam_id_number_(0),
      beam_parameter_index_(0),
      beam_function_(0),
      number_of_track_jam_targets_(0),
      high_density_track_jam_(0),
      pad4_(0),
      jamming_mode_sequence_(0) {}

ElectromagneticEmissionBeamData::~ElectromagneticEmissionBeamData() {
  track_jam_targets_.clear();
}

uint8_t ElectromagneticEmissionBeamData::GetBeamDataLength() const {
  return beam_data_length_;
}

void ElectromagneticEmissionBeamData::SetBeamDataLength(uint8_t pX) {
  beam_data_length_ = pX;
}

uint8_t ElectromagneticEmissionBeamData::GetBeamIdNumber() const {
  return beam_id_number_;
}

void ElectromagneticEmissionBeamData::SetBeamIdNumber(uint8_t pX) {
  beam_id_number_ = pX;
}

uint16_t ElectromagneticEmissionBeamData::GetBeamParameterIndex() const {
  return beam_parameter_index_;
}

void ElectromagneticEmissionBeamData::SetBeamParameterIndex(uint16_t pX) {
  beam_parameter_index_ = pX;
}

FundamentalParameterData&
ElectromagneticEmissionBeamData::GetFundamentalParameterData() {
  return fundamental_parameter_data_;
}

const FundamentalParameterData&
ElectromagneticEmissionBeamData::GetFundamentalParameterData() const {
  return fundamental_parameter_data_;
}

void ElectromagneticEmissionBeamData::SetFundamentalParameterData(
    const FundamentalParameterData& pX) {
  fundamental_parameter_data_ = pX;
}

uint8_t ElectromagneticEmissionBeamData::GetBeamFunction() const {
  return beam_function_;
}

void ElectromagneticEmissionBeamData::SetBeamFunction(uint8_t pX) {
  beam_function_ = pX;
}

uint8_t ElectromagneticEmissionBeamData::GetNumberOfTrackJamTargets() const {
  return track_jam_targets_.size();
}

uint8_t ElectromagneticEmissionBeamData::GetHighDensityTrackJam() const {
  return high_density_track_jam_;
}

void ElectromagneticEmissionBeamData::SetHighDensityTrackJam(uint8_t pX) {
  high_density_track_jam_ = pX;
}

uint8_t ElectromagneticEmissionBeamData::GetPad4() const { return pad4_; }

void ElectromagneticEmissionBeamData::SetPad4(uint8_t pX) { pad4_ = pX; }

uint32_t ElectromagneticEmissionBeamData::GetJammingModeSequence() const {
  return jamming_mode_sequence_;
}

void ElectromagneticEmissionBeamData::SetJammingModeSequence(uint32_t pX) {
  jamming_mode_sequence_ = pX;
}

std::vector<TrackJamTarget>&
ElectromagneticEmissionBeamData::GetTrackJamTargets() {
  return track_jam_targets_;
}

const std::vector<TrackJamTarget>&
ElectromagneticEmissionBeamData::GetTrackJamTargets() const {
  return track_jam_targets_;
}

void ElectromagneticEmissionBeamData::SetTrackJamTargets(
    const std::vector<TrackJamTarget>& pX) {
  track_jam_targets_ = pX;
}

void ElectromagneticEmissionBeamData::Marshal(DataStream& dataStream) const {
  dataStream << beam_data_length_;
  dataStream << beam_id_number_;
  dataStream << beam_parameter_index_;
  fundamental_parameter_data_.Marshal(dataStream);
  dataStream << beam_function_;
  dataStream << static_cast<uint8_t>(track_jam_targets_.size());
  dataStream << high_density_track_jam_;
  dataStream << pad4_;
  dataStream << jamming_mode_sequence_;

  for (const auto& x : track_jam_targets_) {
    x.marshal(dataStream);
  }
}

void ElectromagneticEmissionBeamData::Unmarshal(DataStream& dataStream) {
  dataStream >> beam_data_length_;
  dataStream >> beam_id_number_;
  dataStream >> beam_parameter_index_;
  fundamental_parameter_data_.unmarshal(dataStream);
  dataStream >> beam_function_;
  dataStream >> number_of_track_jam_targets_;
  dataStream >> high_density_track_jam_;
  dataStream >> pad4_;
  dataStream >> jamming_mode_sequence_;

  track_jam_targets_.clear();
  for (size_t idx = 0; idx < number_of_track_jam_targets_; idx++) {
    TrackJamTarget x;
    x.Unmarshal(dataStream);
    track_jam_targets_.push_back(x);
  }
}

bool ElectromagneticEmissionBeamData::operator==(
    const ElectromagneticEmissionBeamData& rhs) const {
  bool ivars_equal = true;

  if (!(beam_data_length_ == rhs.beam_data_length_)) {
    ivars_equal = false;
  }
  if (!(beam_id_number_ == rhs.beam_id_number_)) {
    ivars_equal = false;
  }
  if (!(beam_parameter_index_ == rhs.beam_parameter_index_)) {
    ivars_equal = false;
  }
  if (!(fundamental_parameter_data_ == rhs.fundamental_parameter_data_)) {
    ivars_equal = false;
  }
  if (!(beam_function_ == rhs.beam_function_)) {
    ivars_equal = false;
  }
  if (!(high_density_track_jam_ == rhs.high_density_track_jam_)) {
    ivars_equal = false;
  }
  if (!(pad4_ == rhs.pad4_)) {
    ivars_equal = false;
  }
  if (!(jamming_mode_sequence_ == rhs.jamming_mode_sequence_)) {
    ivars_equal = false;
  }

  for (size_t idx = 0; idx < track_jam_targets_.size(); idx++) {
    if (!(track_jam_targets_[idx] == rhs.track_jam_targets_[idx])) {
      ivars_equal = false;
    }
  }

  return ivars_equal;
}

size_t ElectromagneticEmissionBeamData::GetMarshalledSize() const {
  size_t marshal_size =
      sizeof(beam_data_length_) + sizeof(beam_id_number_) +
      sizeof(beam_parameter_index_) +
      fundamental_parameter_data_.GetMarshalledSize() + sizeof(beam_function_) +
      sizeof(number_of_track_jam_targets_) + sizeof(high_density_track_jam_) +
      sizeof(pad4_) + sizeof(jamming_mode_sequence_);

  for (const auto& list_element : track_jam_targets_) {
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
