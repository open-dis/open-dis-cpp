#include "dis6/common/Vector3Double.h"

namespace dis {
Vector3Double::Vector3Double() : x_(0.0), y_(0.0), z_(0.0) {}

double Vector3Double::GetX() const { return x_; }

void Vector3Double::SetX(double pX) { x_ = pX; }

double Vector3Double::GetY() const { return y_; }

void Vector3Double::SetY(double pX) { y_ = pX; }

double Vector3Double::GetZ() const { return z_; }

void Vector3Double::SetZ(double pX) { z_ = pX; }

void Vector3Double::Marshal(DataStream& dataStream) const {
  dataStream << x_;
  dataStream << y_;
  dataStream << z_;
}

void Vector3Double::Unmarshal(DataStream& dataStream) {
  dataStream >> x_;
  dataStream >> y_;
  dataStream >> z_;
}

bool Vector3Double::operator==(const Vector3Double& rhs) const {
  bool ivars_equal = true;

  if (!(x_ == rhs.x_)) {
    ivars_equal = false;
  }
  if (!(y_ == rhs.y_)) {
    ivars_equal = false;
  }
  if (!(z_ == rhs.z_)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

size_t Vector3Double::GetMarshalledSize() const {
  size_t marshal_size = sizeof(x_) + sizeof(y_) + sizeof(z_);
  return marshal_size;
}

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
