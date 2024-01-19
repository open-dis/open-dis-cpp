#pragma once

#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// Grid axis record for fixed data. Section 6.2.41

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT GridAxis {
 protected:
  /** coordinate of the grid origin or initial value */
  double _domainInitialXi;

  /** coordinate of the endpoint or final value */
  double _domainFinalXi;

  /** The number of grid points along the Xi domain axis for the enviornmental
   * state data */
  uint16_t _domainPointsXi;

  /** interleaf factor along the domain axis. */
  uint8_t _interleafFactor;

  /** type of grid axis */
  uint8_t _axisType;

  /** Number of grid locations along Xi axis */
  uint16_t _numberOfPointsOnXiAxis;

  /** initial grid point for the current pdu */
  uint16_t _initialIndex;

 public:
  GridAxis();
  virtual ~GridAxis();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  double getDomainInitialXi() const;
  void setDomainInitialXi(double pX);

  double getDomainFinalXi() const;
  void setDomainFinalXi(double pX);

  uint16_t getDomainPointsXi() const;
  void setDomainPointsXi(uint16_t pX);

  uint8_t getInterleafFactor() const;
  void setInterleafFactor(uint8_t pX);

  uint8_t getAxisType() const;
  void setAxisType(uint8_t pX);

  uint16_t getNumberOfPointsOnXiAxis() const;
  void setNumberOfPointsOnXiAxis(uint16_t pX);

  uint16_t getInitialIndex() const;
  void setInitialIndex(uint16_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const GridAxis& rhs) const;
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
