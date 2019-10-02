#include <dis6/GriddedDataPdu.h>

using namespace DIS;


GriddedDataPdu::GriddedDataPdu() : SyntheticEnvironmentFamilyPdu(),
   _environmentalSimulationApplicationID(), 
   _fieldNumber(0), 
   _pduNumber(0), 
   _pduTotal(0), 
   _coordinateSystem(0), 
   _numberOfGridAxes(0), 
   _constantGrid(0), 
   _environmentType(), 
   _orientation(), 
   _sampleTime(0), 
   _totalValues(0), 
   _vectorDimension(0), 
   _padding1(0), 
   _padding2(0)
{
    setPduType( 42 );
}

GriddedDataPdu::~GriddedDataPdu()
{
    _gridDataList.clear();
}

EntityID& GriddedDataPdu::getEnvironmentalSimulationApplicationID() 
{
    return _environmentalSimulationApplicationID;
}

const EntityID& GriddedDataPdu::getEnvironmentalSimulationApplicationID() const
{
    return _environmentalSimulationApplicationID;
}

void GriddedDataPdu::setEnvironmentalSimulationApplicationID(const EntityID &pX)
{
    _environmentalSimulationApplicationID = pX;
}

unsigned short GriddedDataPdu::getFieldNumber() const
{
    return _fieldNumber;
}

void GriddedDataPdu::setFieldNumber(unsigned short pX)
{
    _fieldNumber = pX;
}

unsigned short GriddedDataPdu::getPduNumber() const
{
    return _pduNumber;
}

void GriddedDataPdu::setPduNumber(unsigned short pX)
{
    _pduNumber = pX;
}

unsigned short GriddedDataPdu::getPduTotal() const
{
    return _pduTotal;
}

void GriddedDataPdu::setPduTotal(unsigned short pX)
{
    _pduTotal = pX;
}

unsigned short GriddedDataPdu::getCoordinateSystem() const
{
    return _coordinateSystem;
}

void GriddedDataPdu::setCoordinateSystem(unsigned short pX)
{
    _coordinateSystem = pX;
}

unsigned char GriddedDataPdu::getNumberOfGridAxes() const
{
   return _gridDataList.size();
}

unsigned char GriddedDataPdu::getConstantGrid() const
{
    return _constantGrid;
}

void GriddedDataPdu::setConstantGrid(unsigned char pX)
{
    _constantGrid = pX;
}

EntityType& GriddedDataPdu::getEnvironmentType() 
{
    return _environmentType;
}

const EntityType& GriddedDataPdu::getEnvironmentType() const
{
    return _environmentType;
}

void GriddedDataPdu::setEnvironmentType(const EntityType &pX)
{
    _environmentType = pX;
}

Orientation& GriddedDataPdu::getOrientation() 
{
    return _orientation;
}

const Orientation& GriddedDataPdu::getOrientation() const
{
    return _orientation;
}

void GriddedDataPdu::setOrientation(const Orientation &pX)
{
    _orientation = pX;
}

unsigned long long GriddedDataPdu::getSampleTime() const
{
    return _sampleTime;
}

void GriddedDataPdu::setSampleTime(unsigned long long pX)
{
    _sampleTime = pX;
}

unsigned int GriddedDataPdu::getTotalValues() const
{
    return _totalValues;
}

void GriddedDataPdu::setTotalValues(unsigned int pX)
{
    _totalValues = pX;
}

unsigned char GriddedDataPdu::getVectorDimension() const
{
    return _vectorDimension;
}

void GriddedDataPdu::setVectorDimension(unsigned char pX)
{
    _vectorDimension = pX;
}

unsigned short GriddedDataPdu::getPadding1() const
{
    return _padding1;
}

void GriddedDataPdu::setPadding1(unsigned short pX)
{
    _padding1 = pX;
}

unsigned char GriddedDataPdu::getPadding2() const
{
    return _padding2;
}

void GriddedDataPdu::setPadding2(unsigned char pX)
{
    _padding2 = pX;
}

std::vector<GridAxisRecord>& GriddedDataPdu::getGridDataList() 
{
    return _gridDataList;
}

const std::vector<GridAxisRecord>& GriddedDataPdu::getGridDataList() const
{
    return _gridDataList;
}

void GriddedDataPdu::setGridDataList(const std::vector<GridAxisRecord>& pX)
{
     _gridDataList = pX;
}

void GriddedDataPdu::marshal(DataStream& dataStream) const
{
    SyntheticEnvironmentFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _environmentalSimulationApplicationID.marshal(dataStream);
    dataStream << _fieldNumber;
    dataStream << _pduNumber;
    dataStream << _pduTotal;
    dataStream << _coordinateSystem;
    dataStream << ( unsigned char )_gridDataList.size();
    dataStream << _constantGrid;
    _environmentType.marshal(dataStream);
    _orientation.marshal(dataStream);
    dataStream << _sampleTime;
    dataStream << _totalValues;
    dataStream << _vectorDimension;
    dataStream << _padding1;
    dataStream << _padding2;

     for(size_t idx = 0; idx < _gridDataList.size(); idx++)
     {
        GridAxisRecord x = _gridDataList[idx];
        x.marshal(dataStream);
     }

}

void GriddedDataPdu::unmarshal(DataStream& dataStream)
{
    SyntheticEnvironmentFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
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
     for(size_t idx = 0; idx < _numberOfGridAxes; idx++)
     {
        GridAxisRecord x;
        x.unmarshal(dataStream);
        _gridDataList.push_back(x);
     }
}


bool GriddedDataPdu::operator ==(const GriddedDataPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SyntheticEnvironmentFamilyPdu::operator==(rhs);

     if( ! (_environmentalSimulationApplicationID == rhs._environmentalSimulationApplicationID) ) ivarsEqual = false;
     if( ! (_fieldNumber == rhs._fieldNumber) ) ivarsEqual = false;
     if( ! (_pduNumber == rhs._pduNumber) ) ivarsEqual = false;
     if( ! (_pduTotal == rhs._pduTotal) ) ivarsEqual = false;
     if( ! (_coordinateSystem == rhs._coordinateSystem) ) ivarsEqual = false;
     if( ! (_constantGrid == rhs._constantGrid) ) ivarsEqual = false;
     if( ! (_environmentType == rhs._environmentType) ) ivarsEqual = false;
     if( ! (_orientation == rhs._orientation) ) ivarsEqual = false;
     if( ! (_sampleTime == rhs._sampleTime) ) ivarsEqual = false;
     if( ! (_totalValues == rhs._totalValues) ) ivarsEqual = false;
     if( ! (_vectorDimension == rhs._vectorDimension) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _gridDataList.size(); idx++)
     {
        if( ! ( _gridDataList[idx] == rhs._gridDataList[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int GriddedDataPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SyntheticEnvironmentFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _environmentalSimulationApplicationID.getMarshalledSize();  // _environmentalSimulationApplicationID
   marshalSize = marshalSize + 2;  // _fieldNumber
   marshalSize = marshalSize + 2;  // _pduNumber
   marshalSize = marshalSize + 2;  // _pduTotal
   marshalSize = marshalSize + 2;  // _coordinateSystem
   marshalSize = marshalSize + 1;  // _numberOfGridAxes
   marshalSize = marshalSize + 1;  // _constantGrid
   marshalSize = marshalSize + _environmentType.getMarshalledSize();  // _environmentType
   marshalSize = marshalSize + _orientation.getMarshalledSize();  // _orientation
   marshalSize = marshalSize + 8;  // _sampleTime
   marshalSize = marshalSize + 4;  // _totalValues
   marshalSize = marshalSize + 1;  // _vectorDimension
   marshalSize = marshalSize + 2;  // _padding1
   marshalSize = marshalSize + 1;  // _padding2

   for(unsigned long long idx=0; idx < _gridDataList.size(); idx++)
   {
        GridAxisRecord listElement = _gridDataList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

    return marshalSize;
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
