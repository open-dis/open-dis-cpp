#include "dis6/distributed_emissions/AcousticBeamFundamentalParameter.h"

using namespace DIS;

dis::AcousticBeamFundamentalParameter::AcousticBeamFundamentalParameter()
    : active_emission_parameter_index_(0),
      scan_pattern_(0),
      beam_center_azimuth_(0.0),
      azimuthal_beamwidth_(0.0),
      _beamCenterDE(0.0),
      de_beamwidth_(0.0) {}

dis::AcousticBeamFundamentalParameter::~AcousticBeamFundamentalParameter() =
    default;

uint16_t
dis::AcousticBeamFundamentalParameter::GetActiveEmissionParameterIndex() {
  return _activeEmissionParameterIndex;
}

void dis::AcousticBeamFundamentalParameter::SetActiveEmissionParameterIndex(
    uint16_t pX) {
  active_emission_parameter_index_ = pX;
}

uint16_t dis::AcousticBeamFundamentalParameter::GetScanPattern() {
  return _scanPattern;
}

void dis::AcousticBeamFundamentalParameter::SetScanPattern(uint16_t pX) {
  scan_pattern_ = pX;
}

float dis::AcousticBeamFundamentalParameter::GetBeamCenterAzimuth() {
  return _beamCenterAzimuth;
}

void dis::AcousticBeamFundamentalParameter::SetBeamCenterAzimuth(float pX) {
  beam_center_azimuth_ = pX;
}

float dis::AcousticBeamFundamentalParameter::GetAzimuthalBeamwidth() {
  return _azimuthalBeamwidth;
}

void dis::AcousticBeamFundamentalParameter::SetAzimuthalBeamwidth(float pX) {
  azimuthal_beamwidth_ = pX;
}

float dis::AcousticBeamFundamentalParameter::GetBeamCenterDe() {
  return _beamCenterDE;
}

void dis::AcousticBeamFundamentalParameter::SetBeamCenterDe(float pX) {
  _beamCenterDE = pX;
}

float dis::AcousticBeamFundamentalParameter::GetDeBeamwidth() {
  return _deBeamwidth;
}

void dis::AcousticBeamFundamentalParameter::SetDeBeamwidth(float pX) {
  de_beamwidth_ = pX;
}

void dis::AcousticBeamFundamentalParameter::Marshal(
    DataStream& dataStream) const {
  dataStream << (_activeEmissionParameterIndex != nullptr);
  dataStream << _scanPattern;
  dataStream << _beamCenterAzimuth;
  dataStream << _azimuthalBeamwidth;
  dataStream << _beamCenterDE;
  dataStream << _deBeamwidth;
}

void AcousticBeamFundamentalParameter::unmarshal(DataStream& dataStream) {
  dataStream >> _activeEmissionParameterIndex;
  dataStream >> _scanPattern;
  dataStream >> _beamCenterAzimuth;
  dataStream >> _azimuthalBeamwidth;
  dataStream >> _beamCenterDE;
  dataStream >> _deBeamwidth;
}

bool AcousticBeamFundamentalParameter::operator==(
    const AcousticBeamFundamentalParameter& rhs) const {
  bool ivarsEqual = true;

  if (!(_activeEmissionParameterIndex == rhs._activeEmissionParameterIndex))
    ivarsEqual = false;
  if (!(_scanPattern == rhs._scanPattern)) ivarsEqual = false;
  if (!(_beamCenterAzimuth == rhs._beamCenterAzimuth)) ivarsEqual = false;
  if (!(_azimuthalBeamwidth == rhs._azimuthalBeamwidth)) ivarsEqual = false;
  if (!(_beamCenterDE == rhs._beamCenterDE)) ivarsEqual = false;
  if (!(_deBeamwidth == rhs._deBeamwidth)) ivarsEqual = false;

  return ivarsEqual;
}

int AcousticBeamFundamentalParameter::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = marshalSize + 2;  // _activeEmissionParameterIndex
  marshalSize = marshalSize + 2;  // _scanPattern
  marshalSize = marshalSize + 4;  // _beamCenterAzimuth
  marshalSize = marshalSize + 4;  // _azimuthalBeamwidth
  marshalSize = marshalSize + 4;  // _beamCenterDE
  marshalSize = marshalSize + 4;  // _deBeamwidth
  return marshalSize;
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
