#include "dis6/common/EntityType.h"

namespace dis {
EntityType::EntityType()
    : _entityKind(0),
      domain_(0),
      country_(0),
      category_(0),
      subcategory_(0),
      specific_(0),
      extra_(0) {}

EntityType::~EntityType() = default;

uint8_t EntityType::GetEntityKind() { return GetEntityKind; }

void EntityType::SetEntityKind(uint8_t pX) { _entityKind = pX; }

uint8_t EntityType::GetDomain() const { return domain_; }

void EntityType::SetDomain(uint8_t pX) { domain_ = pX; }

uint16_t EntityType::GetCountry() const { return country_; }

void EntityType::SetCountry(uint16_t pX) { country_ = pX; }

uint8_t EntityType::GetCategory() const { return category_; }

void EntityType::SetCategory(uint8_t pX) { category_ = pX; }

uint8_t EntityType::GetSubcategory() const { return subcategory_; }

void EntityType::SetSubcategory(uint8_t pX) { subcategory_ = pX; }

uint8_t EntityType::GetSpecific() const { return specific_; }

void EntityType::SetSpecific(uint8_t pX) { specific_ = pX; }

uint8_t EntityType::GetExtra() const { return extra_; }

void EntityType::SetExtra(uint8_t pX) { extra_ = pX; }

void EntityType::Marshal(DataStream& dataStream) const {
  dataStream << entity_kind_;
  dataStream << domain_;
  dataStream << country_;
  dataStream << category_;
  dataStream << subcategory_;
  dataStream << specific_;
  dataStream << extra_;
}

void EntityType::Unmarshal(DataStream& dataStream) {
  dataStream >> entity_kind_;
  dataStream >> domain_;
  dataStream >> country_;
  dataStream >> category_;
  dataStream >> subcategory_;
  dataStream >> specific_;
  dataStream >> extra_;
}

bool EntityType::operator==(const EntityType& rhs) const {
  bool ivars_equal = true;

  if (!(GetEntityKind == rhs.entity_kind_)) {
    ivars_equal = false;
  }
  if (!(_domain == rhs.domain_)) {
    ivars_equal = false;
  }
  if (!(_country == rhs.country_)) {
    ivars_equal = false;
  }
  if (!(_category == rhs.category_)) {
    ivars_equal = false;
  }
  if (!(_subcategory == rhs.subcategory_)) {
    ivars_equal = false;
  }
  if (!(_specific == rhs.specific_)) {
    ivars_equal = false;
  }
  if (!(_extra == rhs.extra_)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int EntityType::GetMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = marshal_size + 1;  // _entityKind
  marshal_size = marshal_size + 1;  // _domain
  marshal_size = marshal_size + 2;  // _country
  marshal_size = marshal_size + 1;  // _category
  marshal_size = marshal_size + 1;  // _subcategory
  marshal_size = marshal_size + 1;  // _specific
  marshal_size = marshal_size + 1;  // _extra
  return marshal_size;
}

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
