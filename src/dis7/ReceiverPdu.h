#pragma once

#include "dis7/EntityID.h"
#include "dis7/RadioCommunicationsFamilyPdu.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
//  Communication of a receiver state. Section 7.7.4 COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT ReceiverPdu : public RadioCommunicationsFamilyPdu {
 protected:
  /** encoding scheme used, and enumeration */
  uint16_t _receiverState;

  /** padding */
  uint16_t _padding1;

  /** received power */
  float _receivedPower;

  /** ID of transmitter */
  EntityID _transmitterEntityId;

  /** ID of transmitting radio */
  uint16_t _transmitterRadioId;

 public:
  ReceiverPdu();
  virtual ~ReceiverPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint16_t getReceiverState() const;
  void setReceiverState(uint16_t pX);

  uint16_t getPadding1() const;
  void setPadding1(uint16_t pX);

  float getReceivedPower() const;
  void setReceivedPower(float pX);

  EntityID& getTransmitterEntityId();
  const EntityID& getTransmitterEntityId() const;
  void setTransmitterEntityId(const EntityID& pX);

  uint16_t getTransmitterRadioId() const;
  void setTransmitterRadioId(uint16_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const ReceiverPdu& rhs) const;
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
