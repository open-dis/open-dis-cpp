#include <dis6/MinefieldQueryPdu.h>

using namespace DIS;


MinefieldQueryPdu::MinefieldQueryPdu() : MinefieldFamilyPdu(),
   _minefieldID(), 
   _requestingEntityID(), 
   _requestID(0), 
   _numberOfPerimeterPoints(0), 
   _pad2(0), 
   _numberOfSensorTypes(0), 
   _dataFilter(0), 
   _requestedMineType()
{
    setPduType( 38 );
}

MinefieldQueryPdu::~MinefieldQueryPdu()
{
    _requestedPerimeterPoints.clear();
    _sensorTypes.clear();
}

EntityID& MinefieldQueryPdu::getMinefieldID() 
{
    return _minefieldID;
}

const EntityID& MinefieldQueryPdu::getMinefieldID() const
{
    return _minefieldID;
}

void MinefieldQueryPdu::setMinefieldID(const EntityID &pX)
{
    _minefieldID = pX;
}

EntityID& MinefieldQueryPdu::getRequestingEntityID() 
{
    return _requestingEntityID;
}

const EntityID& MinefieldQueryPdu::getRequestingEntityID() const
{
    return _requestingEntityID;
}

void MinefieldQueryPdu::setRequestingEntityID(const EntityID &pX)
{
    _requestingEntityID = pX;
}

unsigned char MinefieldQueryPdu::getRequestID() const
{
    return _requestID;
}

void MinefieldQueryPdu::setRequestID(unsigned char pX)
{
    _requestID = pX;
}

unsigned char MinefieldQueryPdu::getNumberOfPerimeterPoints() const
{
   return _requestedPerimeterPoints.size();
}

unsigned char MinefieldQueryPdu::getPad2() const
{
    return _pad2;
}

void MinefieldQueryPdu::setPad2(unsigned char pX)
{
    _pad2 = pX;
}

unsigned char MinefieldQueryPdu::getNumberOfSensorTypes() const
{
   return _sensorTypes.size();
}

unsigned int MinefieldQueryPdu::getDataFilter() const
{
    return _dataFilter;
}

void MinefieldQueryPdu::setDataFilter(unsigned int pX)
{
    _dataFilter = pX;
}

EntityType& MinefieldQueryPdu::getRequestedMineType() 
{
    return _requestedMineType;
}

const EntityType& MinefieldQueryPdu::getRequestedMineType() const
{
    return _requestedMineType;
}

void MinefieldQueryPdu::setRequestedMineType(const EntityType &pX)
{
    _requestedMineType = pX;
}

std::vector<Point>& MinefieldQueryPdu::getRequestedPerimeterPoints() 
{
    return _requestedPerimeterPoints;
}

const std::vector<Point>& MinefieldQueryPdu::getRequestedPerimeterPoints() const
{
    return _requestedPerimeterPoints;
}

void MinefieldQueryPdu::setRequestedPerimeterPoints(const std::vector<Point>& pX)
{
     _requestedPerimeterPoints = pX;
}

std::vector<TwoByteChunk>& MinefieldQueryPdu::getSensorTypes() 
{
    return _sensorTypes;
}

const std::vector<TwoByteChunk>& MinefieldQueryPdu::getSensorTypes() const
{
    return _sensorTypes;
}

void MinefieldQueryPdu::setSensorTypes(const std::vector<TwoByteChunk>& pX)
{
     _sensorTypes = pX;
}

void MinefieldQueryPdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _minefieldID.marshal(dataStream);
    _requestingEntityID.marshal(dataStream);
    dataStream << _requestID;
    dataStream << ( unsigned char )_requestedPerimeterPoints.size();
    dataStream << _pad2;
    dataStream << ( unsigned char )_sensorTypes.size();
    dataStream << _dataFilter;
    _requestedMineType.marshal(dataStream);

     for(size_t idx = 0; idx < _requestedPerimeterPoints.size(); idx++)
     {
        Point x = _requestedPerimeterPoints[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < _sensorTypes.size(); idx++)
     {
        TwoByteChunk x = _sensorTypes[idx];
        x.marshal(dataStream);
     }

}

void MinefieldQueryPdu::unmarshal(DataStream& dataStream)
{
    MinefieldFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _minefieldID.unmarshal(dataStream);
    _requestingEntityID.unmarshal(dataStream);
    dataStream >> _requestID;
    dataStream >> _numberOfPerimeterPoints;
    dataStream >> _pad2;
    dataStream >> _numberOfSensorTypes;
    dataStream >> _dataFilter;
    _requestedMineType.unmarshal(dataStream);

     _requestedPerimeterPoints.clear();
     for(size_t idx = 0; idx < _numberOfPerimeterPoints; idx++)
     {
        Point x;
        x.unmarshal(dataStream);
        _requestedPerimeterPoints.push_back(x);
     }

     _sensorTypes.clear();
     for(size_t idx = 0; idx < _numberOfSensorTypes; idx++)
     {
        TwoByteChunk x;
        x.unmarshal(dataStream);
        _sensorTypes.push_back(x);
     }
}


bool MinefieldQueryPdu::operator ==(const MinefieldQueryPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (_minefieldID == rhs._minefieldID) ) ivarsEqual = false;
     if( ! (_requestingEntityID == rhs._requestingEntityID) ) ivarsEqual = false;
     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_dataFilter == rhs._dataFilter) ) ivarsEqual = false;
     if( ! (_requestedMineType == rhs._requestedMineType) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _requestedPerimeterPoints.size(); idx++)
     {
        if( ! ( _requestedPerimeterPoints[idx] == rhs._requestedPerimeterPoints[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < _sensorTypes.size(); idx++)
     {
        if( ! ( _sensorTypes[idx] == rhs._sensorTypes[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int MinefieldQueryPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = MinefieldFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _minefieldID.getMarshalledSize();  // _minefieldID
   marshalSize = marshalSize + _requestingEntityID.getMarshalledSize();  // _requestingEntityID
   marshalSize = marshalSize + 1;  // _requestID
   marshalSize = marshalSize + 1;  // _numberOfPerimeterPoints
   marshalSize = marshalSize + 1;  // _pad2
   marshalSize = marshalSize + 1;  // _numberOfSensorTypes
   marshalSize = marshalSize + 4;  // _dataFilter
   marshalSize = marshalSize + _requestedMineType.getMarshalledSize();  // _requestedMineType

   for(unsigned long long idx=0; idx < _requestedPerimeterPoints.size(); idx++)
   {
        Point listElement = _requestedPerimeterPoints[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(unsigned long long idx=0; idx < _sensorTypes.size(); idx++)
   {
        TwoByteChunk listElement = _sensorTypes[idx];
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
