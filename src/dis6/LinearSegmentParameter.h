#pragma once

#include "dis6/Orientation.h"
#include "dis6/SixByteChunk.h"
#include "dis6/Vector3Double.h"
#include "dis6/opendis6_export.h"
#include "dis6/utils/DataStream.h"

namespace DIS {
// 5.2.48: Linear segment parameters

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS6_EXPORT LinearSegmentParameter {
 protected:
  /** number of segments */
  uint8_t _segmentNumber;

  /** segment appearance */
  SixByteChunk _segmentAppearance;

  /** location */
  Vector3Double _location;

  /** orientation */
  Orientation _orientation;

  /** segmentLength */
  uint16_t _segmentLength;

  /** segmentWidth */
  uint16_t _segmentWidth;

  /** segmentHeight */
  uint16_t _segmentHeight;

  /** segment Depth */
  uint16_t _segmentDepth;

  /** segment Depth */
  uint32_t _pad1;

 public:
  LinearSegmentParameter();
  virtual ~LinearSegmentParameter();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint8_t getSegmentNumber() const;
  void setSegmentNumber(uint8_t pX);

  SixByteChunk& getSegmentAppearance();
  const SixByteChunk& getSegmentAppearance() const;
  void setSegmentAppearance(const SixByteChunk& pX);

  Vector3Double& getLocation();
  const Vector3Double& getLocation() const;
  void setLocation(const Vector3Double& pX);

  Orientation& getOrientation();
  const Orientation& getOrientation() const;
  void setOrientation(const Orientation& pX);

  uint16_t getSegmentLength() const;
  void setSegmentLength(uint16_t pX);

  uint16_t getSegmentWidth() const;
  void setSegmentWidth(uint16_t pX);

  uint16_t getSegmentHeight() const;
  void setSegmentHeight(uint16_t pX);

  uint16_t getSegmentDepth() const;
  void setSegmentDepth(uint16_t pX);

  uint32_t getPad1() const;
  void setPad1(uint32_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const LinearSegmentParameter& rhs) const;
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
