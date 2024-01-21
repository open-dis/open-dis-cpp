#include "dis6/warfare/WarfareFamilyPdu.h"

namespace dis {
WarfareFamilyPdu::WarfareFamilyPdu() { SetProtocolFamily(2); }

WarfareFamilyPdu::~WarfareFamilyPdu() = default;

EntityID& WarfareFamilyPdu::getFiringEntityID() { return _firingEntityID; }

const EntityID& WarfareFamilyPdu::getFiringEntityID() const {
  return _firingEntityID;
}

void WarfareFamilyPdu::setFiringEntityID(const EntityID& pX) {
  _firingEntityID = pX;
}

EntityID& WarfareFamilyPdu::getTargetEntityID() { return _targetEntityID; }

const EntityID& WarfareFamilyPdu::getTargetEntityID() const {
  return _targetEntityID;
}

void WarfareFamilyPdu::setTargetEntityID(const EntityID& pX) {
  _targetEntityID = pX;
}

void WarfareFamilyPdu::Marshal(DataStream& dataStream) const {
  Pdu::marshal(data_stream);  // Marshal information in superclass first
  _firingEntityID.Marshal(dataStream);
  _targetEntityID.Marshal(dataStream);
}

void WarfareFamilyPdu::Unmarshal(DataStream& dataStream) {
  Pdu::unmarshal(data_stream);  // unmarshal information in superclass first
  _firingEntityID.Unmarshal(dataStream);
  _targetEntityID.Unmarshal(dataStream);
}

bool WarfareFamilyPdu::operator==(const WarfareFamilyPdu& rhs) const {
  bool ivars_equal = true;

  ivars_equal = Pdu::operator==(rhs);

  if (!(_firingEntityID == rhs._firingEntityID)) {
    ivars_equal = false;
  }
  if (!(_targetEntityID == rhs._targetEntityID)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int WarfareFamilyPdu::GetMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = getMarshalledSize();
  marshal_size =
      marshal_size + _firingEntityID.GetMarshalledSize();  // _firingEntityID
  marshal_size =
      marshal_size + _targetEntityID.GetMarshalledSize();  // _targetEntityID
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
