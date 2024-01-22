#pragma once

#include <cstdint>

#include "dis6/utils/DataStream.h"

namespace dis {
// 5.3.35: Information about a particular UA emitter shall be represented using
// an Acoustic Emitter System record. This record shall consist of three fields:
// Acoustic Name, Function, and Acoustic ID Number

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class AcousticEmitterSystem {
 protected:
  /** This field shall specify the system for a particular UA emitter. */
  uint16_t acoustic_name_;  // NOLINT

  /** This field shall describe the function of the acoustic system.  */
  uint8_t acoustic_function_;  // NOLINT

  /** This field shall specify the UA emitter identification number relative to
   * a specific system. This field shall be represented by an 8-bit unsigned
   * integer. This field allows the differentiation of multiple systems on an
   * entity, even if in some instances two or more of the systems may be
   * identical UA emitter types. Numbering of systems shall begin with the
   * value 1.  */
  uint8_t acoustic_id_;  // NOLINT

 public:
  AcousticEmitterSystem();
  ~AcousticEmitterSystem() = default;

  void Marshal(DataStream& dataStream) const;
  void Unmarshal(DataStream& dataStream);

  [[nodiscard]] uint16_t GetAcousticName() const;
  void SetAcousticName(uint16_t pX);

  [[nodiscard]] uint8_t GetAcousticFunction() const;
  void SetAcousticFunction(uint8_t pX);

  [[nodiscard]] uint8_t GetAcousticId() const;
  void SetAcousticId(uint8_t pX);

  [[nodiscard]] static int GetMarshalledSize();

  bool operator==(const AcousticEmitterSystem& rhs) const;
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
