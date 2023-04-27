#pragma once

#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// The Angle Deception attribute record may be used to communicate discrete
// values that are associated with angle deception jamming that cannot be
// referenced to an emitter mode. The values provided in the record records
// (provided in the associated Electromagnetic Emission PDU). (The victim radar
// beams are those that are targeted by the jammer.) Section 6.2.12.2

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT AngleDeception {
 protected:
  uint32_t _recordType;

  uint16_t _recordLength;

  uint16_t _padding;

  uint8_t _emitterNumber;

  uint8_t _beamNumber;

  uint8_t _stateIndicator;

  uint32_t _padding2;

  float _azimuthOffset;

  float _azimuthWidth;

  float _azimuthPullRate;

  float _azimuthPullAcceleration;

  float _elevationOffset;

  float _elevationWidth;

  float _elevationPullRate;

  float _elevationPullAcceleration;

  uint32_t _padding3;

 public:
  AngleDeception();
  virtual ~AngleDeception();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint32_t getRecordType() const;
  void setRecordType(uint32_t pX);

  uint16_t getRecordLength() const;
  void setRecordLength(uint16_t pX);

  uint16_t getPadding() const;
  void setPadding(uint16_t pX);

  uint8_t getEmitterNumber() const;
  void setEmitterNumber(uint8_t pX);

  uint8_t getBeamNumber() const;
  void setBeamNumber(uint8_t pX);

  uint8_t getStateIndicator() const;
  void setStateIndicator(uint8_t pX);

  uint32_t getPadding2() const;
  void setPadding2(uint32_t pX);

  float getAzimuthOffset() const;
  void setAzimuthOffset(float pX);

  float getAzimuthWidth() const;
  void setAzimuthWidth(float pX);

  float getAzimuthPullRate() const;
  void setAzimuthPullRate(float pX);

  float getAzimuthPullAcceleration() const;
  void setAzimuthPullAcceleration(float pX);

  float getElevationOffset() const;
  void setElevationOffset(float pX);

  float getElevationWidth() const;
  void setElevationWidth(float pX);

  float getElevationPullRate() const;
  void setElevationPullRate(float pX);

  float getElevationPullAcceleration() const;
  void setElevationPullAcceleration(float pX);

  uint32_t getPadding3() const;
  void setPadding3(uint32_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const AngleDeception& rhs) const;
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
