#pragma once

#include <vector>

#include "dis7/EntityID.h"
#include "dis7/FixedDatum.h"
#include "dis7/SimulationManagementFamilyPdu.h"
#include "dis7/VariableDatum.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// Section 7.5.7. Request from simulation manager to a managed entity to perform
// a specified action. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT ActionRequestPdu : public SimulationManagementFamilyPdu {
 protected:
  /** Identifier for originating entity(or simulation) */
  EntityID _originatingID;

  /** Identifier for the receiving entity(or simulation) */
  EntityID _receivingID;

  /** identifies the request being made by the simulaton manager */
  uint32_t _requestID;

  /** identifies the particular action being requested(see Section 7 of
   * SISO-REF-010). */
  uint32_t _actionID;

  /** Number of fixed datum records */
  uint32_t _numberOfFixedDatumRecords;

  /** Number of variable datum records */
  uint32_t _numberOfVariableDatumRecords;

  /** variable length list of fixed datums */
  std::vector<FixedDatum> _fixedDatums;

  /** variable length list of variable length datums */
  std::vector<VariableDatum> _variableDatums;

 public:
  ActionRequestPdu();
  virtual ~ActionRequestPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getOriginatingID();
  const EntityID& getOriginatingID() const;
  void setOriginatingID(const EntityID& pX);

  EntityID& getReceivingID();
  const EntityID& getReceivingID() const;
  void setReceivingID(const EntityID& pX);

  uint32_t getRequestID() const;
  void setRequestID(uint32_t pX);

  uint32_t getActionID() const;
  void setActionID(uint32_t pX);

  uint32_t getNumberOfFixedDatumRecords() const;

  uint32_t getNumberOfVariableDatumRecords() const;

  std::vector<FixedDatum>& getFixedDatums();
  const std::vector<FixedDatum>& getFixedDatums() const;
  void setFixedDatums(const std::vector<FixedDatum>& pX);

  std::vector<VariableDatum>& getVariableDatums();
  const std::vector<VariableDatum>& getVariableDatums() const;
  void setVariableDatums(const std::vector<VariableDatum>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const ActionRequestPdu& rhs) const;
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
