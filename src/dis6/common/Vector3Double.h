#ifndef DIS6_COMMON_VECTOR3DOUBLE_H_
#define DIS6_COMMON_VECTOR3DOUBLE_H_

#include "dis6/utils/DataStream.h"

namespace dis {
// Section 5.3.34. Three double precision floating point values, x, y, and z

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class Vector3Double {
 protected:
  /** X value */
  double x_;  // NOLINT

  /** Y value */
  double y_;  // NOLINT

  /** Z value */
  double z_;  // NOLINT

 public:
  Vector3Double();
  ~Vector3Double() = default;

  void Marshal(DataStream& dataStream) const;
  void Unmarshal(DataStream& dataStream);

  [[nodiscard]] double GetX() const;
  void SetX(double pX);

  [[nodiscard]] double GetY() const;
  void SetY(double pX);

  [[nodiscard]] double GetZ() const;
  void SetZ(double pX);

  [[nodiscard]] size_t GetMarshalledSize() const;

  bool operator==(const Vector3Double& rhs) const;
};
}  // namespace dis

#endif  // DIS6_COMMON_VECTOR3DOUBLE_H_

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
