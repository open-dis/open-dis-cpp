#pragma once

#include "dis6/ClockTime.h"
#include "dis6/SimulationManagementFamilyPdu.h"

#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.2.3.4. Stop or freeze an exercise. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class StopFreezePdu : public SimulationManagementFamilyPdu {
 protected:
  /** UTC time at which the simulation shall stop or freeze */
  ClockTime _realWorldTime;

  /** Reason the simulation was stopped or frozen */
  uint8_t _reason;

  /** Internal behavior of the simulation and its appearance while frozento the
   * other participants */
  uint8_t _frozenBehavior;

  /** padding */
  int16_t _padding1;

  /** Request ID that is unique */
  uint32_t _requestID;

 public:
  StopFreezePdu();
  virtual ~StopFreezePdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  ClockTime& getRealWorldTime();
  const ClockTime& getRealWorldTime() const;
  void setRealWorldTime(const ClockTime& pX);

  uint8_t getReason() const;
  void setReason(uint8_t pX);

  uint8_t getFrozenBehavior() const;
  void setFrozenBehavior(uint8_t pX);

  int16_t getPadding1() const;
  void setPadding1(int16_t pX);

  uint32_t getRequestID() const;
  void setRequestID(uint32_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const StopFreezePdu& rhs) const;
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
