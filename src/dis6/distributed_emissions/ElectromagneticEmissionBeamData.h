#pragma once

#include <vector>

#include "dis6/FundamentalParameterData.h"
#include "dis6/TrackJamTarget.h"

#include "dis6/utils/DataStream.h"

namespace DIS {
// Description of one electronic emission beam

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class ElectromagneticEmissionBeamData {
 protected:
  /** This field shall specify the length of this beams data in 32 bit words */
  uint8_t _beamDataLength;

  /** This field shall specify a unique emitter database number assigned to
   * differentiate between otherwise similar or identical emitter beams within
   * an emitter system. */
  uint8_t _beamIDNumber;

  /** This field shall specify a Beam Parameter Index number that shall be used
   * by receiving entities in conjunction with the Emitter Name field to provide
   * a pointer to the stored database parameters required to regenerate the
   * beam.  */
  uint16_t _beamParameterIndex;

  /** Fundamental parameter data such as frequency range, beam sweep, etc. */
  FundamentalParameterData _fundamentalParameterData;

  /** beam function of a particular beam */
  uint8_t _beamFunction;

  /** Number of track/jam targets */
  uint8_t _numberOfTrackJamTargets;

  /** wheher or not the receiving simulation apps can assume all the targets in
   * the scan pattern are being tracked/jammed */
  uint8_t _highDensityTrackJam;

  /** padding */
  uint8_t _pad4;

  /** identify jamming techniques used */
  uint32_t _jammingModeSequence;

  /** variable length list of track/jam targets */
  std::vector<TrackJamTarget> _trackJamTargets;

 public:
  ElectromagneticEmissionBeamData();
  virtual ~ElectromagneticEmissionBeamData();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint8_t getBeamDataLength() const;
  void setBeamDataLength(uint8_t pX);

  uint8_t getBeamIDNumber() const;
  void setBeamIDNumber(uint8_t pX);

  uint16_t getBeamParameterIndex() const;
  void setBeamParameterIndex(uint16_t pX);

  FundamentalParameterData& getFundamentalParameterData();
  const FundamentalParameterData& getFundamentalParameterData() const;
  void setFundamentalParameterData(const FundamentalParameterData& pX);

  uint8_t getBeamFunction() const;
  void setBeamFunction(uint8_t pX);

  uint8_t getNumberOfTrackJamTargets() const;

  uint8_t getHighDensityTrackJam() const;
  void setHighDensityTrackJam(uint8_t pX);

  uint8_t getPad4() const;
  void setPad4(uint8_t pX);

  uint32_t getJammingModeSequence() const;
  void setJammingModeSequence(uint32_t pX);

  std::vector<TrackJamTarget>& getTrackJamTargets();
  const std::vector<TrackJamTarget>& getTrackJamTargets() const;
  void setTrackJamTargets(const std::vector<TrackJamTarget>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const ElectromagneticEmissionBeamData& rhs) const;
};
}  // namespace DIS

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
