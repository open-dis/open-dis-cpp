#pragma once

#include <cstdint>

#include "dis6/utils/DataStream.h"

namespace dis {
// Used in UaPdu

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class AcousticBeamFundamentalParameter {
 protected:
  /** parameter index */
  uint16_t active_emission_parameter_index_;

  /** scan pattern */
  uint16_t scan_pattern_;

  /** beam center azimuth */
  float beam_center_azimuth_;

  /** azimuthal beamwidth */
  float azimuthal_beamwidth_;

  /** beam center */
  float beam_center_de_;

  /** DE beamwidth (vertical beamwidth) */
  float de_beamwidth_;

 public:
  AcousticBeamFundamentalParameter();
  virtual ~AcousticBeamFundamentalParameter();

  virtual void Marshal(DataStream& dataStream) const;
  virtual void Unmarshal(DataStream& dataStream);

  [[nodiscard]] static uint16_t GetActiveEmissionParameterIndex();
  void SetActiveEmissionParameterIndex(uint16_t pX);

  [[nodiscard]] static uint16_t GetScanPattern();
  void SetScanPattern(uint16_t pX);

  [[nodiscard]] static float GetBeamCenterAzimuth();
  void SetBeamCenterAzimuth(float pX);

  [[nodiscard]] static float GetAzimuthalBeamwidth();
  void SetAzimuthalBeamwidth(float pX);

  [[nodiscard]] static float GetBeamCenterDe();
  void SetBeamCenterDe(float pX);

  [[nodiscard]] static float GetDeBeamwidth();
  void SetDeBeamwidth(float pX);

  [[nodiscard]] virtual int GetMarshalledSize() const;

  bool operator==(const AcousticBeamFundamentalParameter& rhs) const;
};
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
