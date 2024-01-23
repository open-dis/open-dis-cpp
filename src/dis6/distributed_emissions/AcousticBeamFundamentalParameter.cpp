#include "dis6/distributed_emissions/AcousticBeamFundamentalParameter.h"

namespace dis {

AcousticBeamFundamentalParameter::AcousticBeamFundamentalParameter()
    : active_emission_parameter_index_(0),
      scan_pattern_(0),
      beam_center_azimuth_(0.0),
      azimuthal_beamwidth_(0.0),
      beam_center_de_(0.0),
      de_beamwidth_(0.0) {}

uint16_t AcousticBeamFundamentalParameter::GetActiveEmissionParameterIndex()
    const {
  return active_emission_parameter_index_;
}

void AcousticBeamFundamentalParameter::SetActiveEmissionParameterIndex(
    uint16_t pX) {
  active_emission_parameter_index_ = pX;
}

uint16_t AcousticBeamFundamentalParameter::GetScanPattern() const {
  return scan_pattern_;
}

void AcousticBeamFundamentalParameter::SetScanPattern(uint16_t pX) {
  scan_pattern_ = pX;
}

float AcousticBeamFundamentalParameter::GetBeamCenterAzimuth() const {
  return beam_center_azimuth_;
}

void AcousticBeamFundamentalParameter::SetBeamCenterAzimuth(float pX) {
  beam_center_azimuth_ = pX;
}

float AcousticBeamFundamentalParameter::GetAzimuthalBeamwidth() const {
  return azimuthal_beamwidth_;
}

void AcousticBeamFundamentalParameter::SetAzimuthalBeamwidth(float pX) {
  azimuthal_beamwidth_ = pX;
}

float AcousticBeamFundamentalParameter::GetBeamCenterDe() const {
  return beam_center_de_;
}

void AcousticBeamFundamentalParameter::SetBeamCenterDe(float pX) {
  beam_center_de_ = pX;
}

float AcousticBeamFundamentalParameter::GetDeBeamwidth() const {
  return de_beamwidth_;
}

void AcousticBeamFundamentalParameter::SetDeBeamwidth(float pX) {
  de_beamwidth_ = pX;
}

void AcousticBeamFundamentalParameter::Marshal(DataStream& dataStream) const {
  dataStream << active_emission_parameter_index_;
  dataStream << scan_pattern_;
  dataStream << beam_center_azimuth_;
  dataStream << azimuthal_beamwidth_;
  dataStream << beam_center_de_;
  dataStream << de_beamwidth_;
}

void AcousticBeamFundamentalParameter::Unmarshal(DataStream& dataStream) {
  dataStream >> active_emission_parameter_index_;
  dataStream >> scan_pattern_;
  dataStream >> beam_center_azimuth_;
  dataStream >> azimuthal_beamwidth_;
  dataStream >> beam_center_de_;
  dataStream >> de_beamwidth_;
}

bool AcousticBeamFundamentalParameter::operator==(
    const AcousticBeamFundamentalParameter& rhs) const {
  bool ivars_equal = true;

  if (active_emission_parameter_index_ !=
      rhs.active_emission_parameter_index_) {
    ivars_equal = false;
  }
  if (scan_pattern_ != rhs.scan_pattern_) {
    ivars_equal = false;
  }
  if (beam_center_azimuth_ != rhs.beam_center_azimuth_) {
    ivars_equal = false;
  }
  if (azimuthal_beamwidth_ != rhs.azimuthal_beamwidth_) {
    ivars_equal = false;
  }
  if (beam_center_de_ != rhs.beam_center_de_) {
    ivars_equal = false;
  }
  if (de_beamwidth_ != rhs.de_beamwidth_) {
    ivars_equal = false;
  }

  return ivars_equal;
}

size_t AcousticBeamFundamentalParameter::GetMarshalledSize() const {
  size_t marshal_size = sizeof(active_emission_parameter_index_) +
                        sizeof(scan_pattern_) + sizeof(beam_center_azimuth_) +
                        sizeof(azimuthal_beamwidth_) + sizeof(beam_center_de_) +
                        sizeof(de_beamwidth_);
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
