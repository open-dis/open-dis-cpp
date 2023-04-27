#pragma once

#include "dis6/EntityID.h"
#include "dis6/LogisticsFamilyPdu.h"
#include "dis6/opendis6_export.h"
#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.2.5.5. Repair is complete. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS6_EXPORT RepairCompletePdu : public LogisticsFamilyPdu {
 protected:
  /** Entity that is receiving service */
  EntityID _receivingEntityID;

  /** Entity that is supplying */
  EntityID _repairingEntityID;

  /** Enumeration for type of repair */
  uint16_t _repair;

  /** padding, number prevents conflict with superclass ivar name */
  int16_t _padding2;

 public:
  RepairCompletePdu();
  virtual ~RepairCompletePdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getReceivingEntityID();
  const EntityID& getReceivingEntityID() const;
  void setReceivingEntityID(const EntityID& pX);

  EntityID& getRepairingEntityID();
  const EntityID& getRepairingEntityID() const;
  void setRepairingEntityID(const EntityID& pX);

  uint16_t getRepair() const;
  void setRepair(uint16_t pX);

  int16_t getPadding2() const;
  void setPadding2(int16_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const RepairCompletePdu& rhs) const;
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
