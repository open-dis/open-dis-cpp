#include "dis6/synthetic_environment/GriddedDataPdu.h"

using namespace DIS;

GriddedDataPdu::GriddedDataPdu()
    : _fieldNumber(0),
      _pduNumber(0),
      _pduTotal(0),
      _coordinateSystem(0),
      _numberOfGridAxes(0),
      _constantGrid(0),

      _sampleTime(0),
      _totalValues(0),
      _vectorDimension(0),
      _padding1(0),
      _padding2(0) {
  SetPduType(42);
}

GriddedDataPdu::~GriddedDataPdu() { _gridDataList.clear(); }

dis::EntityID& GriddedDataPdu::getEnvironmentalSimulationApplicationID() {
  return _environmentalSimulationApplicationID;
}

const dis::EntityID& GriddedDataPdu::getEnvironmentalSimulationApplicationID()
    const {
  return _environmentalSimulationApplicationID;
}

void GriddedDataPdu::setEnvironmentalSimulationApplicationID(
    const dis::EntityID& pX) {
  _environmentalSimulationApplicationID = pX;
}

uint16_t GriddedDataPdu::getFieldNumber() const { return _fieldNumber; }

void GriddedDataPdu::setFieldNumber(uint16_t pX) { _fieldNumber = pX; }

uint16_t GriddedDataPdu::getPduNumber() const { return _pduNumber; }

void GriddedDataPdu::setPduNumber(uint16_t pX) { _pduNumber = pX; }

uint16_t GriddedDataPdu::getPduTotal() const { return _pduTotal; }

void GriddedDataPdu::setPduTotal(uint16_t pX) { _pduTotal = pX; }

uint16_t GriddedDataPdu::getCoordinateSystem() const {
  return _coordinateSystem;
}

void GriddedDataPdu::setCoordinateSystem(uint16_t pX) {
  _coordinateSystem = pX;
}

uint8_t GriddedDataPdu::getNumberOfGridAxes() const {
  return _gridDataList.size();
}

uint8_t GriddedDataPdu::getConstantGrid() const { return _constantGrid; }

void GriddedDataPdu::setConstantGrid(uint8_t pX) { _constantGrid = pX; }

dis::EntityType& GriddedDataPdu::getEnvironmentType() {
  return _environmentType;
}

const dis::EntityType& GriddedDataPdu::getEnvironmentType() const {
  return _environmentType;
}

void GriddedDataPdu::setEnvironmentType(const dis::EntityType& pX) {
  _environmentType = pX;
}

Orientation& GriddedDataPdu::getOrientation() { return _orientation; }

const Orientation& GriddedDataPdu::getOrientation() const {
  return _orientation;
}

void GriddedDataPdu::setOrientation(const Orientation& pX) {
  _orientation = pX;
}

uint64_t GriddedDataPdu::getSampleTime() const { return _sampleTime; }

void GriddedDataPdu::setSampleTime(uint64_t pX) { _sampleTime = pX; }

uint32_t GriddedDataPdu::getTotalValues() const { return _totalValues; }

void GriddedDataPdu::setTotalValues(uint32_t pX) { _totalValues = pX; }

uint8_t GriddedDataPdu::getVectorDimension() const { return _vectorDimension; }

void GriddedDataPdu::setVectorDimension(uint8_t pX) { _vectorDimension = pX; }

uint16_t GriddedDataPdu::getPadding1() const { return _padding1; }

void GriddedDataPdu::setPadding1(uint16_t pX) { _padding1 = pX; }

uint8_t GriddedDataPdu::getPadding2() const { return _padding2; }

void GriddedDataPdu::setPadding2(uint8_t pX) { _padding2 = pX; }

std::vector<GridAxisRecord>& GriddedDataPdu::getGridDataList() {
  return _gridDataList;
}

const std::vector<GridAxisRecord>& GriddedDataPdu::getGridDataList() const {
  return _gridDataList;
}

void GriddedDataPdu::setGridDataList(const std::vector<GridAxisRecord>& pX) {
  _gridDataList = pX;
}

void GriddedDataPdu::marshal(DataStream& dataStream) const {
  SyntheticEnvironmentFamilyPdu::marshal(
      dataStream);  // Marshal information in superclass first
  _environmentalSimulationApplicationID.Marshal(dataStream);
  dataStream << _fieldNumber;
  dataStream << _pduNumber;
  dataStream << _pduTotal;
  dataStream << _coordinateSystem;
  dataStream << static_cast<uint8_t>(_gridDataList.size());
  dataStream << _constantGrid;
  _environmentType.marshal(dataStream);
  _orientation.marshal(dataStream);
  dataStream << _sampleTime;
  dataStream << _totalValues;
  dataStream << _vectorDimension;
  dataStream << _padding1;
  dataStream << _padding2;

  for (auto x : _gridDataList) {
    x.marshal(dataStream);
  }
}

void GriddedDataPdu::unmarshal(DataStream& dataStream) {
  SyntheticEnvironmentFamilyPdu::unmarshal(
      dataStream);  // unmarshal information in superclass first
  _environmentalSimulationApplicationID.unmarshal(dataStream);
  dataStream >> _fieldNumber;
  dataStream >> _pduNumber;
  dataStream >> _pduTotal;
  dataStream >> _coordinateSystem;
  dataStream >> _numberOfGridAxes;
  dataStream >> _constantGrid;
  _environmentType.unmarshal(dataStream);
  _orientation.unmarshal(dataStream);
  dataStream >> _sampleTime;
  dataStream >> _totalValues;
  dataStream >> _vectorDimension;
  dataStream >> _padding1;
  dataStream >> _padding2;

  _gridDataList.clear();
  for (size_t idx = 0; idx < _numberOfGridAxes; idx++) {
    GridAxisRecord x;
    x.unmarshal(dataStream);
    _gridDataList.push_back(x);
  }
}

bool GriddedDataPdu::operator==(const GriddedDataPdu& rhs) const {
  bool ivars_equal = true;

  ivars_equal = SyntheticEnvironmentFamilyPdu::operator==(rhs);

  if (!(_environmentalSimulationApplicationID ==
        rhs._environmentalSimulationApplicationID)) {
    ivars_equal = false;
  }
  if (!(_fieldNumber == rhs._fieldNumber)) {
    ivars_equal = false;
  }
  if (!(_pduNumber == rhs._pduNumber)) {
    ivars_equal = false;
  }
  if (!(_pduTotal == rhs._pduTotal)) {
    ivars_equal = false;
  }
  if (!(_coordinateSystem == rhs._coordinateSystem)) {
    ivars_equal = false;
  }
  if (!(_constantGrid == rhs._constantGrid)) {
    ivars_equal = false;
  }
  if (!(_environmentType == rhs._environmentType)) {
    ivars_equal = false;
  }
  if (!(_orientation == rhs._orientation)) {
    ivars_equal = false;
  }
  if (!(_sampleTime == rhs._sampleTime)) {
    ivars_equal = false;
  }
  if (!(_totalValues == rhs._totalValues)) {
    ivars_equal = false;
  }
  if (!(_vectorDimension == rhs._vectorDimension)) {
    ivars_equal = false;
  }
  if (!(_padding1 == rhs._padding1)) {
    ivars_equal = false;
  }
  if (!(_padding2 == rhs._padding2)) {
    ivars_equal = false;
  }

  for (size_t idx = 0; idx < _gridDataList.size(); idx++) {
    if (!(_gridDataList[idx] == rhs._gridDataList[idx])) {
      ivars_equal = false;
    }
  }

  return ivars_equal;
}

int GriddedDataPdu::getMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = SyntheticEnvironmentFamilyPdu::getMarshalledSize();
  marshal_size =
      marshal_size +
      _environmentalSimulationApplicationID
          .getMarshalledSize();     // _environmentalSimulationApplicationID
  marshal_size = marshal_size + 2;  // _fieldNumber
  marshal_size = marshal_size + 2;  // _pduNumber
  marshal_size = marshal_size + 2;  // _pduTotal
  marshal_size = marshal_size + 2;  // _coordinateSystem
  marshal_size = marshal_size + 1;  // _numberOfGridAxes
  marshal_size = marshal_size + 1;  // _constantGrid
  marshal_size =
      marshal_size + _environmentType.getMarshalledSize();  // _environmentType
  marshal_size =
      marshal_size + _orientation.getMarshalledSize();  // _orientation
  marshal_size = marshal_size + 8;                      // _sampleTime
  marshal_size = marshal_size + 4;                      // _totalValues
  marshal_size = marshal_size + 1;                      // _vectorDimension
  marshal_size = marshal_size + 2;                      // _padding1
  marshal_size = marshal_size + 1;                      // _padding2

  for (auto listElement : _gridDataList) {
    marshal_size = marshal_size + listElement.getMarshalledSize();
  }

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
