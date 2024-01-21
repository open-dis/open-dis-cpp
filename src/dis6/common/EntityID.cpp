#include "dis6/common/EntityID.h"

namespace dis {
EntityID::EntityID() : site_(0), application_(0), entity_(0) {}

EntityID::~EntityID() = default;

uint16_t EntityID::GetSite() const { return site_; }

void EntityID::SetSite(uint16_t pX) { site_ = pX; }

uint16_t EntityID::GetApplication() const { return application_; }

void EntityID::SetApplication(uint16_t pX) { application_ = pX; }

uint16_t EntityID::GetEntity() const { return entity_; }

void EntityID::SetEntity(uint16_t pX) { entity_ = pX; }

void EntityID::Marshal(DataStream& dataStream) const {
  dataStream << site_;
  dataStream << application_;
  dataStream << entity_;
}

void EntityID::Unmarshal(DataStream& dataStream) {
  dataStream >> site_;
  dataStream >> application_;
  dataStream >> entity_;
}

bool EntityID::operator==(const EntityID& rhs) const {
  bool ivars_equal = true;

  if (!(site_ == rhs.site_)) {
    ivars_equal = false;
  }
  if (!(application_ == rhs.application_)) {
    ivars_equal = false;
  }
  if (!(entity_ == rhs.entity_)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int EntityID::GetMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = marshal_size + 2;  // site_
  marshal_size = marshal_size + 2;  // application_
  marshal_size = marshal_size + 2;  // entity_
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
