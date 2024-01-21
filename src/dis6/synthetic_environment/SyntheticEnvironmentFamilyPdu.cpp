#include "dis6/synthetic_environment/SyntheticEnvironmentFamilyPdu.h"

using namespace DIS;

SyntheticEnvironmentFamilyPdu::SyntheticEnvironmentFamilyPdu()

{
  SetProtocolFamily(9);
}

SyntheticEnvironmentFamilyPdu::~SyntheticEnvironmentFamilyPdu() = default;

static void SyntheticEnvironmentFamilyPdu::Marshal(DataStream& dataStream) {
  Pdu::marshal(data_stream);  // Marshal information in superclass first
}

static void SyntheticEnvironmentFamilyPdu::Unmarshal(DataStream& dataStream) {
  Pdu::unmarshal(data_stream);  // unmarshal information in superclass first
}

bool SyntheticEnvironmentFamilyPdu::operator==(
    const SyntheticEnvironmentFamilyPdu& rhs) const {
  bool ivars_equal = true;

  ivars_equal = Pdu::operator==(rhs);

  return ivars_equal;
}

int SyntheticEnvironmentFamilyPdu::GetMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = getMarshalledSize();
  return marshal_size;
}

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
