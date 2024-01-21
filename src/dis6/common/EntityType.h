#pragma once

#include "dis6/utils/DataStream.h"

namespace dis {
// Section 5.2.16. Identifies the type of entity, including kind of entity,
// domain (surface, subsurface, air, etc) country, category, etc.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class EntityType {
 protected:
  /** Kind of entity */
  uint8_t entity_kind_;  // NOLINT

  /** Domain of entity (air, surface, subsurface, space, etc) */
  uint8_t domain_;  // NOLINT

  /** country to which the design of the entity is attributed */
  uint16_t country_;  // NOLINT

  /** category of entity */
  uint8_t category_;  // NOLINT

  /** subcategory of entity */
  uint8_t subcategory_;  // NOLINT

  /** specific info based on subcategory field */
  uint8_t specific_;  // NOLINT

  uint8_t extra_;  // NOLINT

 public:
  EntityType();
  virtual ~EntityType();

  virtual void Marshal(DataStream& dataStream) const;
  virtual void Unmarshal(DataStream& dataStream);

  [[nodiscard]] static uint8_t GetEntityKind();
  void SetEntityKind(uint8_t pX);

  [[nodiscard]] uint8_t GetDomain() const;
  void SetDomain(uint8_t pX);

  [[nodiscard]] uint16_t GetCountry() const;
  void SetCountry(uint16_t pX);

  [[nodiscard]] uint8_t GetCategory() const;
  void SetCategory(uint8_t pX);

  [[nodiscard]] uint8_t GetSubcategory() const;
  void SetSubcategory(uint8_t pX);

  [[nodiscard]] uint8_t GetSpecific() const;
  void SetSpecific(uint8_t pX);

  [[nodiscard]] uint8_t GetExtra() const;
  void SetExtra(uint8_t pX);

  [[nodiscard]] virtual int GetMarshalledSize() const;

  bool operator==(const EntityType& rhs) const;
};
}  // namespace dis

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
