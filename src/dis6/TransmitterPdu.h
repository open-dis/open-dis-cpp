#pragma once

#include <vector>

#include "dis6/ModulationType.h"
#include "dis6/RadioCommunicationsFamilyPdu.h"
#include "dis6/RadioEntityType.h"
#include "dis6/Vector3Double.h"
#include "dis6/Vector3Float.h"
#include "dis6/opendis6_export.h"
#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.3.8.1. Detailed information about a radio transmitter. This PDU
// requires manually         written code to complete, since the modulation
// parameters are of variable length. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS6_EXPORT TransmitterPdu : public RadioCommunicationsFamilyPdu {
 protected:
  /** linear accelleration of entity */
  RadioEntityType _radioEntityType;

  /** transmit state */
  uint8_t _transmitState;

  /** input source */
  uint8_t _inputSource;

  /** padding */
  uint16_t _padding1;

  /** Location of antenna */
  Vector3Double _antennaLocation;

  /** relative location of antenna */
  Vector3Float _relativeAntennaLocation;

  /** antenna pattern type */
  uint16_t _antennaPatternType;

  /** atenna pattern length */
  uint16_t _antennaPatternCount;

  /** frequency */
  uint64_t _frequency;

  /** transmit frequency Bandwidth */
  float _transmitFrequencyBandwidth;

  /** transmission power */
  float _power;

  /** modulation */
  ModulationType _modulationType;

  /** crypto system enumeration */
  uint16_t _cryptoSystem;

  /** crypto system key identifer */
  uint16_t _cryptoKeyId;

  /** how many modulation parameters we have */
  uint8_t _modulationParameterCount;

  /** padding2 */
  uint16_t _padding2;

  /** padding3 */
  uint8_t _padding3;

  /** variable length list of modulation parameters */
  std::vector<Vector3Float> _modulationParametersList;

  /** variable length list of antenna pattern records */
  std::vector<Vector3Float> _antennaPatternList;

 public:
  TransmitterPdu();
  virtual ~TransmitterPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  RadioEntityType& getRadioEntityType();
  const RadioEntityType& getRadioEntityType() const;
  void setRadioEntityType(const RadioEntityType& pX);

  uint8_t getTransmitState() const;
  void setTransmitState(uint8_t pX);

  uint8_t getInputSource() const;
  void setInputSource(uint8_t pX);

  uint16_t getPadding1() const;
  void setPadding1(uint16_t pX);

  Vector3Double& getAntennaLocation();
  const Vector3Double& getAntennaLocation() const;
  void setAntennaLocation(const Vector3Double& pX);

  Vector3Float& getRelativeAntennaLocation();
  const Vector3Float& getRelativeAntennaLocation() const;
  void setRelativeAntennaLocation(const Vector3Float& pX);

  uint16_t getAntennaPatternType() const;
  void setAntennaPatternType(uint16_t pX);

  uint16_t getAntennaPatternCount() const;

  uint64_t getFrequency() const;
  void setFrequency(uint64_t pX);

  float getTransmitFrequencyBandwidth() const;
  void setTransmitFrequencyBandwidth(float pX);

  float getPower() const;
  void setPower(float pX);

  ModulationType& getModulationType();
  const ModulationType& getModulationType() const;
  void setModulationType(const ModulationType& pX);

  uint16_t getCryptoSystem() const;
  void setCryptoSystem(uint16_t pX);

  uint16_t getCryptoKeyId() const;
  void setCryptoKeyId(uint16_t pX);

  uint8_t getModulationParameterCount() const;

  uint16_t getPadding2() const;
  void setPadding2(uint16_t pX);

  uint8_t getPadding3() const;
  void setPadding3(uint8_t pX);

  std::vector<Vector3Float>& getModulationParametersList();
  const std::vector<Vector3Float>& getModulationParametersList() const;
  void setModulationParametersList(const std::vector<Vector3Float>& pX);

  std::vector<Vector3Float>& getAntennaPatternList();
  const std::vector<Vector3Float>& getAntennaPatternList() const;
  void setAntennaPatternList(const std::vector<Vector3Float>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const TransmitterPdu& rhs) const;
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
