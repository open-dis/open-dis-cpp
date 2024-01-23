#pragma once

#include <vector>

#include "dis6/distributed_emissions/FundamentalParameterData.h"
#include "dis6/distributed_emissions/TrackJamTarget.h"
#include "dis6/utils/DataStream.h"

namespace dis {
// Description of one electronic emission beam

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class ElectromagneticEmissionBeamData {
 protected:
  /** This field shall specify the length of this beams data in 32 bit words */
  uint8_t beam_data_length_;

  /** This field shall specify a unique emitter database number assigned to
   * differentiate between otherwise similar or identical emitter beams within
   * an emitter system. */
  uint8_t beam_id_number_;

  /** This field shall specify a Beam Parameter Index number that shall be used
   * by receiving entities in conjunction with the Emitter Name field to provide
   * a pointer to the stored database parameters required to regenerate the
   * beam.  */
  uint16_t beam_parameter_index_;

  /** Fundamental parameter data such as frequency range, beam sweep, etc. */
  FundamentalParameterData fundamental_parameter_data_;

  /** beam function of a particular beam */
  uint8_t beam_function_;

  /** Number of track/jam targets */
  uint8_t number_of_track_jam_targets_;

  /** wheher or not the receiving simulation apps can assume all the targets in
   * the scan pattern are being tracked/jammed */
  uint8_t high_density_track_jam_;

  /** padding */
  uint8_t pad4_;

  /** identify jamming techniques used */
  uint32_t jamming_mode_sequence_;

  /** variable length list of track/jam targets */
  std::vector<TrackJamTarget> track_jam_targets_;

 public:
  ElectromagneticEmissionBeamData();
  ~ElectromagneticEmissionBeamData();

  void Marshal(DataStream& dataStream) const;
  void Unmarshal(DataStream& dataStream);

  [[nodiscard]] uint8_t GetBeamDataLength() const;
  void SetBeamDataLength(uint8_t pX);

  [[nodiscard]] uint8_t GetBeamIdNumber() const;
  void SetBeamIdNumber(uint8_t pX);

  [[nodiscard]] uint16_t GetBeamParameterIndex() const;
  void SetBeamParameterIndex(uint16_t pX);

  FundamentalParameterData& GetFundamentalParameterData();
  [[nodiscard]] const FundamentalParameterData& GetFundamentalParameterData()
      const;
  void SetFundamentalParameterData(const FundamentalParameterData& pX);

  [[nodiscard]] uint8_t GetBeamFunction() const;
  void SetBeamFunction(uint8_t pX);

  [[nodiscard]] uint8_t GetNumberOfTrackJamTargets() const;

  [[nodiscard]] uint8_t GetHighDensityTrackJam() const;
  void SetHighDensityTrackJam(uint8_t pX);

  [[nodiscard]] uint8_t GetPad4() const;
  void SetPad4(uint8_t pX);

  [[nodiscard]] uint32_t GetJammingModeSequence() const;
  void SetJammingModeSequence(uint32_t pX);

  std::vector<TrackJamTarget>& GetTrackJamTargets();
  [[nodiscard]] const std::vector<TrackJamTarget>& GetTrackJamTargets() const;
  void SetTrackJamTargets(const std::vector<TrackJamTarget>& pX);

  [[nodiscard]] size_t GetMarshalledSize() const;

  bool operator==(const ElectromagneticEmissionBeamData& rhs) const;
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
