#pragma once

#include <cstdint>

#include "dis6/utils/DataStream.h"

namespace dis {
// The superclass for all PDUs. This incorporates the PduHeader record,
// section 5.2.29.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class Pdu {
 protected:
  /** The version of the protocol. 5=DIS-1995, 6=DIS-1998. */
  uint8_t protocol_version_;

  /** Exercise ID */
  uint8_t exercise_id_;

  /** Type of pdu, unique for each PDU class */
  uint8_t pdu_type_;

  /** value that refers to the protocol family, eg SimulationManagement, et */
  uint8_t protocol_family_;

  /** Timestamp value */
  uint32_t timestamp_;

  /** Length, in bytes, of the PDU */
  uint16_t length_;

  /** zero-filled array of padding */
  int16_t padding_;

 public:
  Pdu();
  virtual ~Pdu();

  virtual void Marshal(DataStream& dataStream) const;
  virtual void Unmarshal(DataStream& dataStream);

  [[nodiscard]] static uint8_t GetProtocolVersion();
  void SetProtocolVersion(uint8_t pX);

  [[nodiscard]] static uint8_t GetExerciseId();
  void SetExerciseId(uint8_t pX);

  [[nodiscard]] static uint8_t GetPduType();
  void SetPduType(uint8_t pX);

  [[nodiscard]] static uint8_t GetProtocolFamily();
  void SetProtocolFamily(uint8_t pX);

  [[nodiscard]] uint32_t GetTimestamp() const;
  void SetTimestamp(uint32_t pX);

  [[nodiscard]] uint16_t GetLength() const;
  void SetLength(uint16_t pX);

  [[nodiscard]] int16_t GetPadding() const;
  void SetPadding(int16_t pX);

  [[nodiscard]] virtual int GetMarshalledSize() const;

  bool operator==(const Pdu& rhs) const;
};
}  // namespace dis

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
