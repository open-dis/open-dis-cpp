#pragma once

#include "dis7/EntityID.h"
#include "dis7/Vector3Double.h"
#include "dis7/Vector3Float.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// DE Precision Aimpoint Record. Section 6.2.21.3

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT DirectedEnergyPrecisionAimpoint {
 protected:
  /** Type of Record */
  uint32_t _recordType;

  /** Length of Record */
  uint16_t _recordLength;

  /** Padding */
  uint16_t _padding;

  /** Position of Target Spot in World Coordinates. */
  Vector3Double _targetSpotLocation;

  /** Position (meters) of Target Spot relative to Entity Position. */
  Vector3Float _targetSpotEntityLocation;

  /** Velocity (meters/sec) of Target Spot. */
  Vector3Float _targetSpotVelocity;

  /** Acceleration (meters/sec/sec) of Target Spot. */
  Vector3Float _targetSpotAcceleration;

  /** Unique ID of the target entity. */
  EntityID _targetEntityID;

  /** Target Component ID ENUM, same as in DamageDescriptionRecord. */
  uint8_t _targetComponentID;

  /** Spot Shape ENUM. */
  uint8_t _SpotShape;

  /** Beam Spot Cross Section Semi-Major Axis. */
  float _BeamSpotXSecSemiMajorAxis;

  /** Beam Spot Cross Section Semi-Major Axis. */
  float _BeamSpotCrossSectionSemiMinorAxis;

  /** Beam Spot Cross Section Orientation Angle. */
  float _BeamSpotCrossSectionOrientAngle;

 public:
  DirectedEnergyPrecisionAimpoint();
  virtual ~DirectedEnergyPrecisionAimpoint();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint32_t getRecordType() const;
  void setRecordType(uint32_t pX);

  uint16_t getRecordLength() const;
  void setRecordLength(uint16_t pX);

  uint16_t getPadding() const;
  void setPadding(uint16_t pX);

  Vector3Double& getTargetSpotLocation();
  const Vector3Double& getTargetSpotLocation() const;
  void setTargetSpotLocation(const Vector3Double& pX);

  Vector3Float& getTargetSpotEntityLocation();
  const Vector3Float& getTargetSpotEntityLocation() const;
  void setTargetSpotEntityLocation(const Vector3Float& pX);

  Vector3Float& getTargetSpotVelocity();
  const Vector3Float& getTargetSpotVelocity() const;
  void setTargetSpotVelocity(const Vector3Float& pX);

  Vector3Float& getTargetSpotAcceleration();
  const Vector3Float& getTargetSpotAcceleration() const;
  void setTargetSpotAcceleration(const Vector3Float& pX);

  EntityID& getTargetEntityID();
  const EntityID& getTargetEntityID() const;
  void setTargetEntityID(const EntityID& pX);

  uint8_t getTargetComponentID() const;
  void setTargetComponentID(uint8_t pX);

  uint8_t getSpotShape() const;
  void setSpotShape(uint8_t pX);

  float getBeamSpotXSecSemiMajorAxis() const;
  void setBeamSpotXSecSemiMajorAxis(float pX);

  float getBeamSpotCrossSectionSemiMinorAxis() const;
  void setBeamSpotCrossSectionSemiMinorAxis(float pX);

  float getBeamSpotCrossSectionOrientAngle() const;
  void setBeamSpotCrossSectionOrientAngle(float pX);

  virtual int getMarshalledSize() const;

  bool operator==(const DirectedEnergyPrecisionAimpoint& rhs) const;
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
