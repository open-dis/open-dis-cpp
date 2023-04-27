#pragma once

#include <vector>

#include "dis7/EightByteChunk.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// the variable datum type, the datum length, and the value for that variable
// datum type. NOT COMPLETE. Section 6.2.92

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT VariableDatum {
 protected:
  /** Type of variable datum to be transmitted. 32 bit enumeration defined in
   * EBV */
  uint32_t _variableDatumID;

  /** Length, in bits, of the variable datum. */
  uint32_t _variableDatumLength;

  /** Variable datum. This can be any number of bits long, depending on the
   * datum. */
  uint32_t _variableDatumBits;

  /** padding to put the record on a 64 bit boundary */
  uint32_t _padding;

  // Variable Data
  std::vector<EightByteChunk> _variableDatums;

 public:
  VariableDatum();
  virtual ~VariableDatum();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint32_t getVariableDatumID() const;
  void setVariableDatumID(uint32_t pX);

  uint32_t getVariableDatumLength() const;
  void setVariableDatumLength(uint32_t pX);

  uint32_t getVariableDatumBits() const;
  void setVariableDatumBits(uint32_t pX);

  uint32_t getPadding() const;
  void setPadding(uint32_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const VariableDatum& rhs) const;
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
