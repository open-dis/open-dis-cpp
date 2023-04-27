#include "dis6/EntityType.h"

using namespace DIS;

EntityType::EntityType()
    : _entityKind(0),
      _domain(0),
      _country(0),
      _category(0),
      _subcategory(0),
      _specific(0),
      _extra(0) {}

EntityType::~EntityType() {}

uint8_t EntityType::getEntityKind() const { return _entityKind; }

void EntityType::setEntityKind(uint8_t pX) { _entityKind = pX; }

uint8_t EntityType::getDomain() const { return _domain; }

void EntityType::setDomain(uint8_t pX) { _domain = pX; }

uint16_t EntityType::getCountry() const { return _country; }

void EntityType::setCountry(uint16_t pX) { _country = pX; }

uint8_t EntityType::getCategory() const { return _category; }

void EntityType::setCategory(uint8_t pX) { _category = pX; }

uint8_t EntityType::getSubcategory() const { return _subcategory; }

void EntityType::setSubcategory(uint8_t pX) { _subcategory = pX; }

uint8_t EntityType::getSpecific() const { return _specific; }

void EntityType::setSpecific(uint8_t pX) { _specific = pX; }

uint8_t EntityType::getExtra() const { return _extra; }

void EntityType::setExtra(uint8_t pX) { _extra = pX; }

void EntityType::marshal(DataStream& dataStream) const {
  dataStream << _entityKind;
  dataStream << _domain;
  dataStream << _country;
  dataStream << _category;
  dataStream << _subcategory;
  dataStream << _specific;
  dataStream << _extra;
}

void EntityType::unmarshal(DataStream& dataStream) {
  dataStream >> _entityKind;
  dataStream >> _domain;
  dataStream >> _country;
  dataStream >> _category;
  dataStream >> _subcategory;
  dataStream >> _specific;
  dataStream >> _extra;
}

bool EntityType::operator==(const EntityType& rhs) const {
  bool ivarsEqual = true;

  if (!(_entityKind == rhs._entityKind)) ivarsEqual = false;
  if (!(_domain == rhs._domain)) ivarsEqual = false;
  if (!(_country == rhs._country)) ivarsEqual = false;
  if (!(_category == rhs._category)) ivarsEqual = false;
  if (!(_subcategory == rhs._subcategory)) ivarsEqual = false;
  if (!(_specific == rhs._specific)) ivarsEqual = false;
  if (!(_extra == rhs._extra)) ivarsEqual = false;

  return ivarsEqual;
}

int EntityType::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = marshalSize + 1;  // _entityKind
  marshalSize = marshalSize + 1;  // _domain
  marshalSize = marshalSize + 2;  // _country
  marshalSize = marshalSize + 1;  // _category
  marshalSize = marshalSize + 1;  // _subcategory
  marshalSize = marshalSize + 1;  // _specific
  marshalSize = marshalSize + 1;  // _extra
  return marshalSize;
}

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
