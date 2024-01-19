#pragma once


#include "dis6/utils/DataStream.h"

namespace DIS {
// Record sets, used in transfer control request PDU

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class RecordSet {
 protected:
  /** record ID */
  uint32_t _recordID;

  /** record set serial number */
  uint32_t _recordSetSerialNumber;

  /** record length */
  uint16_t _recordLength;

  /** record count */
  uint16_t _recordCount;

  /** ^^^This is wrong--variable sized data records */
  uint16_t _recordValues;

  /** ^^^This is wrong--variable sized padding */
  uint8_t _pad4;

 public:
  RecordSet();
  virtual ~RecordSet();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint32_t getRecordID() const;
  void setRecordID(uint32_t pX);

  uint32_t getRecordSetSerialNumber() const;
  void setRecordSetSerialNumber(uint32_t pX);

  uint16_t getRecordLength() const;
  void setRecordLength(uint16_t pX);

  uint16_t getRecordCount() const;
  void setRecordCount(uint16_t pX);

  uint16_t getRecordValues() const;
  void setRecordValues(uint16_t pX);

  uint8_t getPad4() const;
  void setPad4(uint8_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const RecordSet& rhs) const;
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
