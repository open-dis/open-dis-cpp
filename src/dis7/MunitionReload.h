#pragma once

#include "dis7/EntityType.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// indicate weapons (munitions) previously communicated via the Munition record.
// Section 6.2.61

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT MunitionReload {
 protected:
  /**  This field shall identify the entity type of the munition. See
   * section 6.2.30. */
  EntityType _munitionType;

  /** the station or launcher to which the munition is assigned. See Annex I */
  uint32_t _station;

  /** the standard quantity of this munition type normally loaded at this
   * station/launcher if a station/launcher is specified. */
  uint16_t _standardQuantity;

  /** the maximum quantity of this munition type that this station/launcher is
   * capable of holding when a station/launcher is specified  */
  uint16_t _maximumQuantity;

  /** the station name within the host at which the part entity is located. */
  uint16_t _stationName;

  /** the number of the particular wing station, cargo hold etc., at which the
   * part is attached. */
  uint16_t _stationNumber;

 public:
  MunitionReload();
  virtual ~MunitionReload();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityType& getMunitionType();
  const EntityType& getMunitionType() const;
  void setMunitionType(const EntityType& pX);

  uint32_t getStation() const;
  void setStation(uint32_t pX);

  uint16_t getStandardQuantity() const;
  void setStandardQuantity(uint16_t pX);

  uint16_t getMaximumQuantity() const;
  void setMaximumQuantity(uint16_t pX);

  uint16_t getStationName() const;
  void setStationName(uint16_t pX);

  uint16_t getStationNumber() const;
  void setStationNumber(uint16_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const MunitionReload& rhs) const;
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
