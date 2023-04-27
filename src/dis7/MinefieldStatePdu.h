#pragma once

#include <vector>

#include "dis7/EntityType.h"
#include "dis7/EulerAngles.h"
#include "dis7/MinefieldFamilyPdu.h"
#include "dis7/MinefieldIdentifier.h"
#include "dis7/Vector2Float.h"
#include "dis7/Vector3Double.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// information about the complete minefield. The minefield presence, perimiter,
// etc. Section 7.9.2 COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT MinefieldStatePdu : public MinefieldFamilyPdu {
 protected:
  /** Minefield ID */
  MinefieldIdentifier _minefieldID;

  /** Minefield sequence */
  uint16_t _minefieldSequence;

  /** force ID */
  uint8_t _forceID;

  /** Number of permieter points */
  uint8_t _numberOfPerimeterPoints;

  /** type of minefield */
  EntityType _minefieldType;

  /** how many mine types */
  uint16_t _numberOfMineTypes;

  /** location of center of minefield in world coords */
  Vector3Double _minefieldLocation;

  /** orientation of minefield */
  EulerAngles _minefieldOrientation;

  /** appearance bitflags */
  uint16_t _appearance;

  /** protocolMode. First two bits are the protocol mode, 14 bits reserved. */
  uint16_t _protocolMode;

  /** perimeter points for the minefield */
  std::vector<Vector2Float> _perimeterPoints;

  /** Type of mines */
  std::vector<EntityType> _mineType;

 public:
  MinefieldStatePdu();
  virtual ~MinefieldStatePdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  MinefieldIdentifier& getMinefieldID();
  const MinefieldIdentifier& getMinefieldID() const;
  void setMinefieldID(const MinefieldIdentifier& pX);

  uint16_t getMinefieldSequence() const;
  void setMinefieldSequence(uint16_t pX);

  uint8_t getForceID() const;
  void setForceID(uint8_t pX);

  uint8_t getNumberOfPerimeterPoints() const;

  EntityType& getMinefieldType();
  const EntityType& getMinefieldType() const;
  void setMinefieldType(const EntityType& pX);

  uint16_t getNumberOfMineTypes() const;

  Vector3Double& getMinefieldLocation();
  const Vector3Double& getMinefieldLocation() const;
  void setMinefieldLocation(const Vector3Double& pX);

  EulerAngles& getMinefieldOrientation();
  const EulerAngles& getMinefieldOrientation() const;
  void setMinefieldOrientation(const EulerAngles& pX);

  uint16_t getAppearance() const;
  void setAppearance(uint16_t pX);

  uint16_t getProtocolMode() const;
  void setProtocolMode(uint16_t pX);

  std::vector<Vector2Float>& getPerimeterPoints();
  const std::vector<Vector2Float>& getPerimeterPoints() const;
  void setPerimeterPoints(const std::vector<Vector2Float>& pX);

  std::vector<EntityType>& getMineType();
  const std::vector<EntityType>& getMineType() const;
  void setMineType(const std::vector<EntityType>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const MinefieldStatePdu& rhs) const;
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
