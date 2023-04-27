#pragma once

#include <vector>

#include "dis7/FixedDatum.h"
#include "dis7/SimulationManagementWithReliabilityFamilyPdu.h"
#include "dis7/VariableDatum.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// Section 5.3.12.11: reports the occurance of a significatnt event to the
// simulation manager. Needs manual     intervention to fix padding in variable
// datums. UNFINISHED.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT EventReportReliablePdu
    : public SimulationManagementWithReliabilityFamilyPdu {
 protected:
  /** Event type */
  uint16_t _eventType;

  /** padding */
  uint32_t _pad1;

  /** Fixed datum record count */
  uint32_t _numberOfFixedDatumRecords;

  /** variable datum record count */
  uint32_t _numberOfVariableDatumRecords;

  /** Fixed datum records */
  std::vector<FixedDatum> _fixedDatumRecords;

  /** Variable datum records */
  std::vector<VariableDatum> _variableDatumRecords;

 public:
  EventReportReliablePdu();
  virtual ~EventReportReliablePdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint16_t getEventType() const;
  void setEventType(uint16_t pX);

  uint32_t getPad1() const;
  void setPad1(uint32_t pX);

  uint32_t getNumberOfFixedDatumRecords() const;

  uint32_t getNumberOfVariableDatumRecords() const;

  std::vector<FixedDatum>& getFixedDatumRecords();
  const std::vector<FixedDatum>& getFixedDatumRecords() const;
  void setFixedDatumRecords(const std::vector<FixedDatum>& pX);

  std::vector<VariableDatum>& getVariableDatumRecords();
  const std::vector<VariableDatum>& getVariableDatumRecords() const;
  void setVariableDatumRecords(const std::vector<VariableDatum>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const EventReportReliablePdu& rhs) const;
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
