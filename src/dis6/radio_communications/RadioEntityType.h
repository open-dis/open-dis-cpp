#pragma once


#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.2.25. Identifies the type of radio

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class RadioEntityType {
 protected:
  /** Kind of entity */
  uint8_t _entityKind;

  /** Domain of entity (air, surface, subsurface, space, etc) */
  uint8_t _domain;

  /** country to which the design of the entity is attributed */
  uint16_t _country;

  /** category of entity */
  uint8_t _category;

  /** specific info based on subcategory field */
  uint8_t _nomenclatureVersion;

  uint16_t _nomenclature;

 public:
  RadioEntityType();
  virtual ~RadioEntityType();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint8_t getEntityKind() const;
  void setEntityKind(uint8_t pX);

  uint8_t getDomain() const;
  void setDomain(uint8_t pX);

  uint16_t getCountry() const;
  void setCountry(uint16_t pX);

  uint8_t getCategory() const;
  void setCategory(uint8_t pX);

  uint8_t getNomenclatureVersion() const;
  void setNomenclatureVersion(uint8_t pX);

  uint16_t getNomenclature() const;
  void setNomenclature(uint16_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const RadioEntityType& rhs) const;
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
