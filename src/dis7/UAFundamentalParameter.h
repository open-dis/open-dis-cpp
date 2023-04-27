#pragma once

#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// Regeneration parameters for active emission systems that are variable
// throughout a scenario. Section 6.2.90

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT UAFundamentalParameter {
 protected:
  /** Which database record shall be used. An enumeration from EBV document */
  uint16_t _activeEmissionParameterIndex;

  /** The type of scan pattern, If not used, zero. An enumeration from EBV
   * document */
  uint16_t _scanPattern;

  /** center azimuth bearing of th emain beam. In radians. */
  float _beamCenterAzimuthHorizontal;

  /** Horizontal beamwidth of th emain beam Meastued at the 3dB down point of
   * peak radiated power. In radians. */
  float _azimuthalBeamwidthHorizontal;

  /** center of the d/e angle of th emain beam relative to the stablised de
   * angle of the target. In radians. */
  float _beamCenterDepressionElevation;

  /** vertical beamwidth of the main beam. Meastured at the 3dB down point of
   * peak radiated power. In radians. */
  float _beamwidthDownElevation;

 public:
  UAFundamentalParameter();
  virtual ~UAFundamentalParameter();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint16_t getActiveEmissionParameterIndex() const;
  void setActiveEmissionParameterIndex(uint16_t pX);

  uint16_t getScanPattern() const;
  void setScanPattern(uint16_t pX);

  float getBeamCenterAzimuthHorizontal() const;
  void setBeamCenterAzimuthHorizontal(float pX);

  float getAzimuthalBeamwidthHorizontal() const;
  void setAzimuthalBeamwidthHorizontal(float pX);

  float getBeamCenterDepressionElevation() const;
  void setBeamCenterDepressionElevation(float pX);

  float getBeamwidthDownElevation() const;
  void setBeamwidthDownElevation(float pX);

  virtual int getMarshalledSize() const;

  bool operator==(const UAFundamentalParameter& rhs) const;
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
