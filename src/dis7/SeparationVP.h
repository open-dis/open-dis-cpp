#pragma once

#include "dis7/EntityID.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// Physical separation of an entity from another entity.  Section 6.2.93.6

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT SeparationVP {
 protected:
  /** the identification of the Variable Parameter record. Enumeration from EBV
   */
  uint8_t _recordType;

  /** Reason for separation. EBV */
  uint8_t _reasonForSeparation;

  /** Whether the entity existed prior to separation EBV */
  uint8_t _preEntityIndicator;

  /** padding */
  uint8_t _padding1;

  /** ID of parent */
  EntityID _parentEntityID;

  /** padding */
  uint16_t _padding2;

  /** Station separated from */
  uint32_t _stationLocation;

 public:
  SeparationVP();
  virtual ~SeparationVP();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint8_t getRecordType() const;
  void setRecordType(uint8_t pX);

  uint8_t getReasonForSeparation() const;
  void setReasonForSeparation(uint8_t pX);

  uint8_t getPreEntityIndicator() const;
  void setPreEntityIndicator(uint8_t pX);

  uint8_t getPadding1() const;
  void setPadding1(uint8_t pX);

  EntityID& getParentEntityID();
  const EntityID& getParentEntityID() const;
  void setParentEntityID(const EntityID& pX);

  uint16_t getPadding2() const;
  void setPadding2(uint16_t pX);

  uint32_t getStationLocation() const;
  void setStationLocation(uint32_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const SeparationVP& rhs) const;
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
