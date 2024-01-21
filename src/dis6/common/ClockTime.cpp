#include "dis6/common/ClockTime.h"

namespace dis {
ClockTime::ClockTime() : hour_(0), time_past_hour_(0) {}

ClockTime::~ClockTime() = default;

int ClockTime::GetHour() const { return hour_; }

void ClockTime::SetHour(int pX) { hour_ = pX; }

uint32_t ClockTime::GetTimePastHour() const { return time_past_hour_; }

void ClockTime::SetTimePastHour(uint32_t pX) { time_past_hour_ = pX; }

void ClockTime::Marshal(DataStream& dataStream) const {
  dataStream << hour_;
  dataStream << time_past_hour_;
}

void ClockTime::Unmarshal(DataStream& dataStream) {
  dataStream >> hour_;
  dataStream >> time_past_hour_;
}

bool ClockTime::operator==(const ClockTime& rhs) const {
  bool ivars_equal = true;

  if (!(hour_ == rhs.hour_)) {
    ivars_equal = false;
  }
  if (!(time_past_hour_ == rhs.time_past_hour_)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int ClockTime::GetMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = marshal_size + 4;  // hour_
  marshal_size = marshal_size + 4;  // time_past_hour_
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
