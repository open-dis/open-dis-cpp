#pragma once

#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// The False Targets attribute record shall be used to communicate discrete
// values that are associated with false targets jamming that cannot be
// referenced to an emitter mode. The values provided in the False Targets
// attri- bute record shall be considered valid only for the victim radar beams
// listed in the jamming beam's Track/Jam Data records (provided in the
// associated Electromagnetic Emission PDU). Section 6.2.12.3

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT FalseTargetsAttribute {
 protected:
  uint32_t _recordType;

  uint16_t _recordLength;

  uint16_t _padding;

  uint8_t _emitterNumber;

  uint8_t _beamNumber;

  uint8_t _stateIndicator;

  uint8_t _padding2;

  float _falseTargetCount;

  float _walkSpeed;

  float _walkAcceleration;

  float _maximumWalkDistance;

  float _keepTime;

  float _echoSpacing;

  uint32_t _padding3;

 public:
  FalseTargetsAttribute();
  virtual ~FalseTargetsAttribute();

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

  uint8_t getPadding2() const;
  void setPadding2(uint8_t pX);

  float getFalseTargetCount() const;
  void setFalseTargetCount(float pX);

  float getWalkSpeed() const;
  void setWalkSpeed(float pX);

  float getWalkAcceleration() const;
  void setWalkAcceleration(float pX);

  float getMaximumWalkDistance() const;
  void setMaximumWalkDistance(float pX);

  float getKeepTime() const;
  void setKeepTime(float pX);

  float getEchoSpacing() const;
  void setEchoSpacing(float pX);

  uint32_t getPadding3() const;
  void setPadding3(uint32_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const FalseTargetsAttribute& rhs) const;
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
