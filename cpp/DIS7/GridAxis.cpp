#include <DIS/GridAxis.h> 

using namespace DIS;


GridAxis::GridAxis():
   _domainInitialXi(0.0), 
   _domainFinalXi(0.0), 
   _domainPointsXi(0), 
   _interleafFactor(0), 
   _axisType(0), 
   _numberOfPointsOnXiAxis(0), 
   _initialIndex(0)
{
}

GridAxis::~GridAxis()
{
}

double GridAxis::getDomainInitialXi() const
{
    return _domainInitialXi;
}

void GridAxis::setDomainInitialXi(double pX)
{
    _domainInitialXi = pX;
}

double GridAxis::getDomainFinalXi() const
{
    return _domainFinalXi;
}

void GridAxis::setDomainFinalXi(double pX)
{
    _domainFinalXi = pX;
}

unsigned short GridAxis::getDomainPointsXi() const
{
    return _domainPointsXi;
}

void GridAxis::setDomainPointsXi(unsigned short pX)
{
    _domainPointsXi = pX;
}

unsigned char GridAxis::getInterleafFactor() const
{
    return _interleafFactor;
}

void GridAxis::setInterleafFactor(unsigned char pX)
{
    _interleafFactor = pX;
}

unsigned char GridAxis::getAxisType() const
{
    return _axisType;
}

void GridAxis::setAxisType(unsigned char pX)
{
    _axisType = pX;
}

unsigned short GridAxis::getNumberOfPointsOnXiAxis() const
{
    return _numberOfPointsOnXiAxis;
}

void GridAxis::setNumberOfPointsOnXiAxis(unsigned short pX)
{
    _numberOfPointsOnXiAxis = pX;
}

unsigned short GridAxis::getInitialIndex() const
{
    return _initialIndex;
}

void GridAxis::setInitialIndex(unsigned short pX)
{
    _initialIndex = pX;
}

void GridAxis::marshal(DataStream& dataStream) const
{
    dataStream << _domainInitialXi;
    dataStream << _domainFinalXi;
    dataStream << _domainPointsXi;
    dataStream << _interleafFactor;
    dataStream << _axisType;
    dataStream << _numberOfPointsOnXiAxis;
    dataStream << _initialIndex;
}

void GridAxis::unmarshal(DataStream& dataStream)
{
    dataStream >> _domainInitialXi;
    dataStream >> _domainFinalXi;
    dataStream >> _domainPointsXi;
    dataStream >> _interleafFactor;
    dataStream >> _axisType;
    dataStream >> _numberOfPointsOnXiAxis;
    dataStream >> _initialIndex;
}


bool GridAxis::operator ==(const GridAxis& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_domainInitialXi == rhs._domainInitialXi) ) ivarsEqual = false;
     if( ! (_domainFinalXi == rhs._domainFinalXi) ) ivarsEqual = false;
     if( ! (_domainPointsXi == rhs._domainPointsXi) ) ivarsEqual = false;
     if( ! (_interleafFactor == rhs._interleafFactor) ) ivarsEqual = false;
     if( ! (_axisType == rhs._axisType) ) ivarsEqual = false;
     if( ! (_numberOfPointsOnXiAxis == rhs._numberOfPointsOnXiAxis) ) ivarsEqual = false;
     if( ! (_initialIndex == rhs._initialIndex) ) ivarsEqual = false;

    return ivarsEqual;
 }

int GridAxis::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 8;  // _domainInitialXi
   marshalSize = marshalSize + 8;  // _domainFinalXi
   marshalSize = marshalSize + 2;  // _domainPointsXi
   marshalSize = marshalSize + 1;  // _interleafFactor
   marshalSize = marshalSize + 1;  // _axisType
   marshalSize = marshalSize + 2;  // _numberOfPointsOnXiAxis
   marshalSize = marshalSize + 2;  // _initialIndex
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
