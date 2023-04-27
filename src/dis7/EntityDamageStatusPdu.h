#pragma once

#include <vector>

#include "dis7/DirectedEnergyDamage.h"
#include "dis7/EntityID.h"
#include "dis7/WarfareFamilyPdu.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// shall be used to communicate detailed damage information sustained by an
// entity regardless of the source of the damage Section 7.3.5  COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT EntityDamageStatusPdu : public WarfareFamilyPdu {
 protected:
  /** Field shall identify the damaged entity (see 6.2.28), Section 7.3.4
   * COMPLETE */
  EntityID _damagedEntityID;

  /** Padding. */
  uint16_t _padding1;

  /** Padding. */
  uint16_t _padding2;

  /** field shall specify the number of Damage Description records,
   * Section 7.3.5 */
  uint16_t _numberOfDamageDescription;

  /** Fields shall contain one or more Damage Description records (see 6.2.17)
   * and may contain other Standard Variable records, Section 7.3.5 */
  std::vector<DirectedEnergyDamage> _damageDescriptionRecords;

 public:
  EntityDamageStatusPdu();
  virtual ~EntityDamageStatusPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getDamagedEntityID();
  const EntityID& getDamagedEntityID() const;
  void setDamagedEntityID(const EntityID& pX);

  uint16_t getPadding1() const;
  void setPadding1(uint16_t pX);

  uint16_t getPadding2() const;
  void setPadding2(uint16_t pX);

  uint16_t getNumberOfDamageDescription() const;

  std::vector<DirectedEnergyDamage>& getDamageDescriptionRecords();
  const std::vector<DirectedEnergyDamage>& getDamageDescriptionRecords() const;
  void setDamageDescriptionRecords(const std::vector<DirectedEnergyDamage>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const EntityDamageStatusPdu& rhs) const;
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
