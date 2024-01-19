#pragma once

#include <vector>

#include "dis6/EntityID.h"
#include "dis6/EntityType.h"
#include "dis6/MinefieldFamilyPdu.h"
#include "dis6/Point.h"
#include "dis6/TwoByteChunk.h"

#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.3.10.2 Query a minefield for information about individual mines.
// Requires manual clean up to get the padding right. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class MinefieldQueryPdu : public MinefieldFamilyPdu {
 protected:
  /** Minefield ID */
  EntityID _minefieldID;

  /** EID of entity making the request */
  EntityID _requestingEntityID;

  /** request ID */
  uint8_t _requestID;

  /** Number of perimeter points for the minefield */
  uint8_t _numberOfPerimeterPoints;

  /** Padding */
  uint8_t _pad2;

  /** Number of sensor types */
  uint8_t _numberOfSensorTypes;

  /** data filter, 32 boolean fields */
  uint32_t _dataFilter;

  /** Entity type of mine being requested */
  EntityType _requestedMineType;

  /** perimeter points of request */
  std::vector<Point> _requestedPerimeterPoints;

  /** Sensor types, each 16 bits long */
  std::vector<TwoByteChunk> _sensorTypes;

 public:
  MinefieldQueryPdu();
  virtual ~MinefieldQueryPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getMinefieldID();
  const EntityID& getMinefieldID() const;
  void setMinefieldID(const EntityID& pX);

  EntityID& getRequestingEntityID();
  const EntityID& getRequestingEntityID() const;
  void setRequestingEntityID(const EntityID& pX);

  uint8_t getRequestID() const;
  void setRequestID(uint8_t pX);

  uint8_t getNumberOfPerimeterPoints() const;

  uint8_t getPad2() const;
  void setPad2(uint8_t pX);

  uint8_t getNumberOfSensorTypes() const;

  uint32_t getDataFilter() const;
  void setDataFilter(uint32_t pX);

  EntityType& getRequestedMineType();
  const EntityType& getRequestedMineType() const;
  void setRequestedMineType(const EntityType& pX);

  std::vector<Point>& getRequestedPerimeterPoints();
  const std::vector<Point>& getRequestedPerimeterPoints() const;
  void setRequestedPerimeterPoints(const std::vector<Point>& pX);

  std::vector<TwoByteChunk>& getSensorTypes();
  const std::vector<TwoByteChunk>& getSensorTypes() const;
  void setSensorTypes(const std::vector<TwoByteChunk>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const MinefieldQueryPdu& rhs) const;
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
