#pragma once

#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// specification of additional information associated with an entity or
// detonation, not otherwise accounted for in a PDU 6.2.93.1

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT VariableParameter {
 protected:
  /** the identification of the Variable Parameter record. Enumeration from EBV
   */
  uint8_t _recordType;

  /** Variable parameter data fields. Two doubles minus one byte */
  double _variableParameterFields1;

  /** Variable parameter data fields.  */
  uint32_t _variableParameterFields2;

  /** Variable parameter data fields.  */
  uint16_t _variableParameterFields3;

  /** Variable parameter data fields.  */
  uint8_t _variableParameterFields4;

 public:
  VariableParameter();
  virtual ~VariableParameter();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint8_t getRecordType() const;
  void setRecordType(uint8_t pX);

  double getVariableParameterFields1() const;
  void setVariableParameterFields1(double pX);

  uint32_t getVariableParameterFields2() const;
  void setVariableParameterFields2(uint32_t pX);

  uint16_t getVariableParameterFields3() const;
  void setVariableParameterFields3(uint16_t pX);

  uint8_t getVariableParameterFields4() const;
  void setVariableParameterFields4(uint8_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const VariableParameter& rhs) const;
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
