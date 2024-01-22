#pragma once

#include <cstdint>

#include "dis6/utils/DataStream.h"

namespace dis {
// Section 5.2.11. This field shall specify information about a particular
// emitter system

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class EmitterSystem {
 protected:
  /** Name of the emitter, 16 bit enumeration */
  uint16_t emitter_name_;

  /** function of the emitter, 8 bit enumeration */
  uint8_t function_;

  /** emitter ID, 8 bit enumeration */
  uint8_t emitter_id_number_;

 public:
  EmitterSystem();
  ~EmitterSystem() = default;

  void Marshal(DataStream& dataStream) const;
  void Unmarshal(DataStream& dataStream);

  [[nodiscard]] uint16_t GetEmitterName() const;
  void SetEmitterName(uint16_t pX);

  [[nodiscard]] uint8_t GetFunction() const;
  void SetFunction(uint8_t pX);

  [[nodiscard]] uint8_t GetEmitterIdNumber() const;
  void SetEmitterIdNumber(uint8_t pX);

  [[nodiscard]] int GetMarshalledSize() const;

  bool operator==(const EmitterSystem& rhs) const;
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
