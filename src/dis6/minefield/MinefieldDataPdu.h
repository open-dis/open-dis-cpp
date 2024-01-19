#pragma once

#include <vector>

#include "dis6/EntityID.h"
#include "dis6/EntityType.h"
#include "dis6/MinefieldFamilyPdu.h"
#include "dis6/TwoByteChunk.h"
#include "dis6/Vector3Float.h"

#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.3.10.3 Information about individual mines within a minefield. This
// is very, very wrong. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class MinefieldDataPdu : public MinefieldFamilyPdu {
 protected:
  /** Minefield ID */
  EntityID _minefieldID;

  /** ID of entity making request */
  EntityID _requestingEntityID;

  /** Minefield sequence number */
  uint16_t _minefieldSequenceNumbeer;

  /** request ID */
  uint8_t _requestID;

  /** pdu sequence number */
  uint8_t _pduSequenceNumber;

  /** number of pdus in response */
  uint8_t _numberOfPdus;

  /** how many mines are in this PDU */
  uint8_t _numberOfMinesInThisPdu;

  /** how many sensor type are in this PDU */
  uint8_t _numberOfSensorTypes;

  /** padding */
  uint8_t _pad2;

  /** 32 boolean fields */
  uint32_t _dataFilter;

  /** Mine type */
  EntityType _mineType;

  /** Sensor types, each 16 bits long */
  std::vector<TwoByteChunk> _sensorTypes;

  /** Padding to get things 32-bit aligned. ^^^this is wrong--dyanmically sized
   * padding needed */
  uint8_t _pad3;

  /** Mine locations */
  std::vector<Vector3Float> _mineLocation;

 public:
  MinefieldDataPdu();
  virtual ~MinefieldDataPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getMinefieldID();
  const EntityID& getMinefieldID() const;
  void setMinefieldID(const EntityID& pX);

  EntityID& getRequestingEntityID();
  const EntityID& getRequestingEntityID() const;
  void setRequestingEntityID(const EntityID& pX);

  uint16_t getMinefieldSequenceNumbeer() const;
  void setMinefieldSequenceNumbeer(uint16_t pX);

  uint8_t getRequestID() const;
  void setRequestID(uint8_t pX);

  uint8_t getPduSequenceNumber() const;
  void setPduSequenceNumber(uint8_t pX);

  uint8_t getNumberOfPdus() const;
  void setNumberOfPdus(uint8_t pX);

  uint8_t getNumberOfMinesInThisPdu() const;

  uint8_t getNumberOfSensorTypes() const;

  uint8_t getPad2() const;
  void setPad2(uint8_t pX);

  uint32_t getDataFilter() const;
  void setDataFilter(uint32_t pX);

  EntityType& getMineType();
  const EntityType& getMineType() const;
  void setMineType(const EntityType& pX);

  std::vector<TwoByteChunk>& getSensorTypes();
  const std::vector<TwoByteChunk>& getSensorTypes() const;
  void setSensorTypes(const std::vector<TwoByteChunk>& pX);

  uint8_t getPad3() const;
  void setPad3(uint8_t pX);

  std::vector<Vector3Float>& getMineLocation();
  const std::vector<Vector3Float>& getMineLocation() const;
  void setMineLocation(const std::vector<Vector3Float>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const MinefieldDataPdu& rhs) const;
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
