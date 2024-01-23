#pragma once

#include <vector>

#include "dis6/common/Vector3Float.h"
#include "dis6/distributed_emissions/ElectromagneticEmissionBeamData.h"
#include "dis6/distributed_emissions/EmitterSystem.h"
#include "dis6/utils/DataStream.h"

namespace dis {
// Data about one electronic system

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class ElectromagneticEmissionSystemData {
 protected:
  /** This field shall specify the length of this emitter system�s data
   * (including beam data and its track/jam information) in 32-bit words. The
   * length shall include the System Data Length field.  */
  uint8_t system_data_length_;

  /** This field shall specify the number of beams being described in the
   * current PDU for the system being described.  */
  uint8_t number_of_beams_;

  /** padding. */
  uint16_t emissions_padding2_;

  /** This field shall specify information about a particular emitter system */
  EmitterSystem emitter_system_;

  /** Location with respect to the entity */
  Vector3Float location_;

  /** variable length list of beam data records */
  std::vector<ElectromagneticEmissionBeamData> beam_data_records_;

 public:
  ElectromagneticEmissionSystemData();
  ~ElectromagneticEmissionSystemData();

  void Marshal(DataStream& dataStream) const;
  void Unmarshal(DataStream& dataStream);

  [[nodiscard]] uint8_t GetSystemDataLength() const;
  void SetSystemDataLength(uint8_t pX);

  [[nodiscard]] uint8_t GetNumberOfBeams() const;

  [[nodiscard]] uint16_t GetEmissionsPadding2() const;
  void SetEmissionsPadding2(uint16_t pX);

  EmitterSystem& GetEmitterSystem();
  [[nodiscard]] const EmitterSystem& GetEmitterSystem() const;
  void SetEmitterSystem(const EmitterSystem& pX);

  Vector3Float& GetLocation();
  [[nodiscard]] const Vector3Float& GetLocation() const;
  void SetLocation(const Vector3Float& pX);

  std::vector<ElectromagneticEmissionBeamData>& GetBeamDataRecords();
  [[nodiscard]] const std::vector<ElectromagneticEmissionBeamData>&
  GetBeamDataRecords() const;
  void SetBeamDataRecords(
      const std::vector<ElectromagneticEmissionBeamData>& pX);

  [[nodiscard]] size_t GetMarshalledSize() const;

  bool operator==(const ElectromagneticEmissionSystemData& rhs) const;
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
