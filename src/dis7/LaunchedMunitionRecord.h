#pragma once

#include "dis7/EventIdentifier.h"
#include "dis7/Vector3Double.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// Identity of a communications node. Section 6.2.51

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT LaunchedMunitionRecord {
 protected:
  EventIdentifier _fireEventID;

  uint16_t _padding;

  EventIdentifier _firingEntityID;

  uint16_t _padding2;

  EventIdentifier _targetEntityID;

  uint16_t _padding3;

  Vector3Double _targetLocation;

 public:
  LaunchedMunitionRecord();
  virtual ~LaunchedMunitionRecord();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EventIdentifier& getFireEventID();
  const EventIdentifier& getFireEventID() const;
  void setFireEventID(const EventIdentifier& pX);

  uint16_t getPadding() const;
  void setPadding(uint16_t pX);

  EventIdentifier& getFiringEntityID();
  const EventIdentifier& getFiringEntityID() const;
  void setFiringEntityID(const EventIdentifier& pX);

  uint16_t getPadding2() const;
  void setPadding2(uint16_t pX);

  EventIdentifier& getTargetEntityID();
  const EventIdentifier& getTargetEntityID() const;
  void setTargetEntityID(const EventIdentifier& pX);

  uint16_t getPadding3() const;
  void setPadding3(uint16_t pX);

  Vector3Double& getTargetLocation();
  const Vector3Double& getTargetLocation() const;
  void setTargetLocation(const Vector3Double& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const LaunchedMunitionRecord& rhs) const;
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
