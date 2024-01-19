#pragma once

#include <vector>

#include "dis6/EntityID.h"
#include "dis6/EntityType.h"
#include "dis6/GridAxisRecord.h"
#include "dis6/Orientation.h"
#include "dis6/SyntheticEnvironmentFamilyPdu.h"

#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.3.11.2: Information about globat, spatially varying enviornmental
// effects. This requires manual cleanup; the grid axis        records are
// variable sized. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class GriddedDataPdu : public SyntheticEnvironmentFamilyPdu {
 protected:
  /** environmental simulation application ID */
  EntityID _environmentalSimulationApplicationID;

  /** unique identifier for each piece of enviornmental data */
  uint16_t _fieldNumber;

  /** sequence number for the total set of PDUS used to transmit the data */
  uint16_t _pduNumber;

  /** Total number of PDUS used to transmit the data */
  uint16_t _pduTotal;

  /** coordinate system of the grid */
  uint16_t _coordinateSystem;

  /** number of grid axes for the environmental data */
  uint8_t _numberOfGridAxes;

  /** are domain grid axes identidal to those of the priveious domain update? */
  uint8_t _constantGrid;

  /** type of environment */
  EntityType _environmentType;

  /** orientation of the data grid */
  Orientation _orientation;

  /** valid time of the enviormental data sample, 64 bit uint32_t */
  uint64_t _sampleTime;

  /** total number of all data values for all pdus for an environmental sample
   */
  uint32_t _totalValues;

  /** total number of data values at each grid point. */
  uint8_t _vectorDimension;

  /** padding */
  uint16_t _padding1;

  /** padding */
  uint8_t _padding2;

  /** Grid data ^^^This is wrong */
  std::vector<GridAxisRecord> _gridDataList;

 public:
  GriddedDataPdu();
  virtual ~GriddedDataPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getEnvironmentalSimulationApplicationID();
  const EntityID& getEnvironmentalSimulationApplicationID() const;
  void setEnvironmentalSimulationApplicationID(const EntityID& pX);

  uint16_t getFieldNumber() const;
  void setFieldNumber(uint16_t pX);

  uint16_t getPduNumber() const;
  void setPduNumber(uint16_t pX);

  uint16_t getPduTotal() const;
  void setPduTotal(uint16_t pX);

  uint16_t getCoordinateSystem() const;
  void setCoordinateSystem(uint16_t pX);

  uint8_t getNumberOfGridAxes() const;

  uint8_t getConstantGrid() const;
  void setConstantGrid(uint8_t pX);

  EntityType& getEnvironmentType();
  const EntityType& getEnvironmentType() const;
  void setEnvironmentType(const EntityType& pX);

  Orientation& getOrientation();
  const Orientation& getOrientation() const;
  void setOrientation(const Orientation& pX);

  uint64_t getSampleTime() const;
  void setSampleTime(uint64_t pX);

  uint32_t getTotalValues() const;
  void setTotalValues(uint32_t pX);

  uint8_t getVectorDimension() const;
  void setVectorDimension(uint8_t pX);

  uint16_t getPadding1() const;
  void setPadding1(uint16_t pX);

  uint8_t getPadding2() const;
  void setPadding2(uint8_t pX);

  std::vector<GridAxisRecord>& getGridDataList();
  const std::vector<GridAxisRecord>& getGridDataList() const;
  void setGridDataList(const std::vector<GridAxisRecord>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const GriddedDataPdu& rhs) const;
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
