#include "dis6/synthetic_environment/ObjectType.h"

using namespace DIS;

ObjectType::ObjectType()
    : _entityKind(0), _domain(0), _country(0), _category(0), _subcategory(0) {}

ObjectType::~ObjectType() = default;

uint8_t ObjectType::getEntityKind() const { return _entityKind; }

void ObjectType::setEntityKind(uint8_t pX) { _entityKind = pX; }

uint8_t ObjectType::getDomain() const { return _domain; }

void ObjectType::setDomain(uint8_t pX) { _domain = pX; }

uint16_t ObjectType::getCountry() const { return _country; }

void ObjectType::setCountry(uint16_t pX) { _country = pX; }

uint8_t ObjectType::getCategory() const { return _category; }

void ObjectType::setCategory(uint8_t pX) { _category = pX; }

uint8_t ObjectType::getSubcategory() const { return _subcategory; }

void ObjectType::setSubcategory(uint8_t pX) { _subcategory = pX; }

void ObjectType::Marshal(DataStream& dataStream) const {
  dataStream << _entityKind;
  dataStream << _domain;
  dataStream << _country;
  dataStream << _category;
  dataStream << _subcategory;
}

void ObjectType::Unmarshal(DataStream& dataStream) {
  dataStream >> _entityKind;
  dataStream >> _domain;
  dataStream >> _country;
  dataStream >> _category;
  dataStream >> _subcategory;
}

bool ObjectType::operator==(const ObjectType& rhs) const {
  bool ivars_equal = true;

  if (!(_entityKind == rhs._entityKind)) {
    ivars_equal = false;
  }
  if (!(_domain == rhs._domain)) {
    ivars_equal = false;
  }
  if (!(_country == rhs._country)) {
    ivars_equal = false;
  }
  if (!(_category == rhs._category)) {
    ivars_equal = false;
  }
  if (!(_subcategory == rhs._subcategory)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int ObjectType::getMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = marshal_size + 1;  // _entityKind
  marshal_size = marshal_size + 1;  // _domain
  marshal_size = marshal_size + 2;  // _country
  marshal_size = marshal_size + 1;  // _category
  marshal_size = marshal_size + 1;  // _subcategory
  return marshal_size;
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
