#pragma once

#include "dis7/EulerAngles.h"
#include "dis7/Vector3Double.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// The specification of an individual segment of a linear segment synthetic
// environment object in a Linear Object State PDU Section 6.2.53

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT LinearSegmentParameter {
 protected:
  /** the individual segment of the linear segment  */
  uint8_t _segmentNumber;

  /**  whether a modification has been made to the point object’s location or
   * orientation */
  uint8_t _segmentModification;

  /** general dynamic appearance attributes of the segment. This record shall be
   * defined as a 16-bit record of enumerations. The values defined for this
   * record are included in Section 12 of SISO-REF-010. */
  uint16_t _generalSegmentAppearance;

  /** This field shall specify specific dynamic appearance attributes of the
   * segment. This record shall be defined as a 32-bit record of enumerations.
   */
  uint16_t _specificSegmentAppearance;

  /** This field shall specify the location of the linear segment in the
   * simulated world and shall be represented by a World Coordinates record  */
  Vector3Double _segmentLocation;

  /** orientation of the linear segment about the segment location and shall be
   * represented by a Euler Angles record  */
  EulerAngles _segmentOrientation;

  /** length of the linear segment, in meters, extending in the positive X
   * direction */
  uint16_t _segmentLength;

  /** The total width of the linear segment, in meters, shall be specified by a
   * 16-bit uint32_teger. One-half of the width shall extend in the positive
   * Y direction, and one-half of the width shall extend in the negative Y
   * direction. */
  uint16_t _segmentWidth;

  /** The height of the linear segment, in meters, above ground shall be
   * specified by a 16-bit uint32_teger. */
  uint16_t _segmentHeight;

  /** The depth of the linear segment, in meters, below ground level  */
  uint16_t _segmentDepth;

 public:
  LinearSegmentParameter();
  virtual ~LinearSegmentParameter();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint8_t getSegmentNumber() const;
  void setSegmentNumber(uint8_t pX);

  uint8_t getSegmentModification() const;
  void setSegmentModification(uint8_t pX);

  uint16_t getGeneralSegmentAppearance() const;
  void setGeneralSegmentAppearance(uint16_t pX);

  uint16_t getSpecificSegmentAppearance() const;
  void setSpecificSegmentAppearance(uint16_t pX);

  Vector3Double& getSegmentLocation();
  const Vector3Double& getSegmentLocation() const;
  void setSegmentLocation(const Vector3Double& pX);

  EulerAngles& getSegmentOrientation();
  const EulerAngles& getSegmentOrientation() const;
  void setSegmentOrientation(const EulerAngles& pX);

  uint16_t getSegmentLength() const;
  void setSegmentLength(uint16_t pX);

  uint16_t getSegmentWidth() const;
  void setSegmentWidth(uint16_t pX);

  uint16_t getSegmentHeight() const;
  void setSegmentHeight(uint16_t pX);

  uint16_t getSegmentDepth() const;
  void setSegmentDepth(uint16_t pX);

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
