#pragma once

#include <vector>

#include "dis6/EntityID.h"
#include "dis6/EntityType.h"
#include "dis6/Environment.h"
#include "dis6/SyntheticEnvironmentFamilyPdu.h"
#include "dis6/opendis6_export.h"
#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.3.11.1: Information about environmental effects and processes. This
// requires manual cleanup. the environmental        record is variable, as is
// the padding. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS6_EXPORT EnvironmentalProcessPdu
    : public SyntheticEnvironmentFamilyPdu {
 protected:
  /** Environmental process ID */
  EntityID _environementalProcessID;

  /** Environment type */
  EntityType _environmentType;

  /** model type */
  uint8_t _modelType;

  /** Environment status */
  uint8_t _environmentStatus;

  /** number of environment records  */
  uint8_t _numberOfEnvironmentRecords;

  /** PDU sequence number for the environmentla process if pdu sequencing
   * required */
  uint16_t _sequenceNumber;

  /** environemt records */
  std::vector<Environment> _environmentRecords;

 public:
  EnvironmentalProcessPdu();
  virtual ~EnvironmentalProcessPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getEnvironementalProcessID();
  const EntityID& getEnvironementalProcessID() const;
  void setEnvironementalProcessID(const EntityID& pX);

  EntityType& getEnvironmentType();
  const EntityType& getEnvironmentType() const;
  void setEnvironmentType(const EntityType& pX);

  uint8_t getModelType() const;
  void setModelType(uint8_t pX);

  uint8_t getEnvironmentStatus() const;
  void setEnvironmentStatus(uint8_t pX);

  uint8_t getNumberOfEnvironmentRecords() const;

  uint16_t getSequenceNumber() const;
  void setSequenceNumber(uint16_t pX);

  std::vector<Environment>& getEnvironmentRecords();
  const std::vector<Environment>& getEnvironmentRecords() const;
  void setEnvironmentRecords(const std::vector<Environment>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const EnvironmentalProcessPdu& rhs) const;
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
