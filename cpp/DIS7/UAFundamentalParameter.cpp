#include <DIS/UAFundamentalParameter.h> 

using namespace DIS;


UAFundamentalParameter::UAFundamentalParameter():
   _activeEmissionParameterIndex(0), 
   _scanPattern(0), 
   _beamCenterAzimuthHorizontal(0.0), 
   _azimuthalBeamwidthHorizontal(0.0), 
   _beamCenterDepressionElevation(0.0), 
   _beamwidthDownElevation(0.0)
{
}

UAFundamentalParameter::~UAFundamentalParameter()
{
}

unsigned short UAFundamentalParameter::getActiveEmissionParameterIndex() const
{
    return _activeEmissionParameterIndex;
}

void UAFundamentalParameter::setActiveEmissionParameterIndex(unsigned short pX)
{
    _activeEmissionParameterIndex = pX;
}

unsigned short UAFundamentalParameter::getScanPattern() const
{
    return _scanPattern;
}

void UAFundamentalParameter::setScanPattern(unsigned short pX)
{
    _scanPattern = pX;
}

float UAFundamentalParameter::getBeamCenterAzimuthHorizontal() const
{
    return _beamCenterAzimuthHorizontal;
}

void UAFundamentalParameter::setBeamCenterAzimuthHorizontal(float pX)
{
    _beamCenterAzimuthHorizontal = pX;
}

float UAFundamentalParameter::getAzimuthalBeamwidthHorizontal() const
{
    return _azimuthalBeamwidthHorizontal;
}

void UAFundamentalParameter::setAzimuthalBeamwidthHorizontal(float pX)
{
    _azimuthalBeamwidthHorizontal = pX;
}

float UAFundamentalParameter::getBeamCenterDepressionElevation() const
{
    return _beamCenterDepressionElevation;
}

void UAFundamentalParameter::setBeamCenterDepressionElevation(float pX)
{
    _beamCenterDepressionElevation = pX;
}

float UAFundamentalParameter::getBeamwidthDownElevation() const
{
    return _beamwidthDownElevation;
}

void UAFundamentalParameter::setBeamwidthDownElevation(float pX)
{
    _beamwidthDownElevation = pX;
}

void UAFundamentalParameter::marshal(DataStream& dataStream) const
{
    dataStream << _activeEmissionParameterIndex;
    dataStream << _scanPattern;
    dataStream << _beamCenterAzimuthHorizontal;
    dataStream << _azimuthalBeamwidthHorizontal;
    dataStream << _beamCenterDepressionElevation;
    dataStream << _beamwidthDownElevation;
}

void UAFundamentalParameter::unmarshal(DataStream& dataStream)
{
    dataStream >> _activeEmissionParameterIndex;
    dataStream >> _scanPattern;
    dataStream >> _beamCenterAzimuthHorizontal;
    dataStream >> _azimuthalBeamwidthHorizontal;
    dataStream >> _beamCenterDepressionElevation;
    dataStream >> _beamwidthDownElevation;
}


bool UAFundamentalParameter::operator ==(const UAFundamentalParameter& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_activeEmissionParameterIndex == rhs._activeEmissionParameterIndex) ) ivarsEqual = false;
     if( ! (_scanPattern == rhs._scanPattern) ) ivarsEqual = false;
     if( ! (_beamCenterAzimuthHorizontal == rhs._beamCenterAzimuthHorizontal) ) ivarsEqual = false;
     if( ! (_azimuthalBeamwidthHorizontal == rhs._azimuthalBeamwidthHorizontal) ) ivarsEqual = false;
     if( ! (_beamCenterDepressionElevation == rhs._beamCenterDepressionElevation) ) ivarsEqual = false;
     if( ! (_beamwidthDownElevation == rhs._beamwidthDownElevation) ) ivarsEqual = false;

    return ivarsEqual;
 }

int UAFundamentalParameter::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _activeEmissionParameterIndex
   marshalSize = marshalSize + 2;  // _scanPattern
   marshalSize = marshalSize + 4;  // _beamCenterAzimuthHorizontal
   marshalSize = marshalSize + 4;  // _azimuthalBeamwidthHorizontal
   marshalSize = marshalSize + 4;  // _beamCenterDepressionElevation
   marshalSize = marshalSize + 4;  // _beamwidthDownElevation
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
