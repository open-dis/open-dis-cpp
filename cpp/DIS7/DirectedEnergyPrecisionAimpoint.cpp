#include <DIS/DirectedEnergyPrecisionAimpoint.h> 

using namespace DIS;


DirectedEnergyPrecisionAimpoint::DirectedEnergyPrecisionAimpoint():
   _recordType(4000), 
   _recordLength(88), 
   _padding(0), 
   _targetSpotLocation(), 
   _targetSpotEntityLocation(), 
   _targetSpotVelocity(), 
   _targetSpotAcceleration(), 
   _targetEntityID(), 
   _targetComponentID(0), 
   _SpotShape(0), 
   _BeamSpotXSecSemiMajorAxis(0), 
   _BeamSpotCrossSectionSemiMinorAxis(0), 
   _BeamSpotCrossSectionOrientAngle(0)
{
}

DirectedEnergyPrecisionAimpoint::~DirectedEnergyPrecisionAimpoint()
{
}

unsigned int DirectedEnergyPrecisionAimpoint::getRecordType() const
{
    return _recordType;
}

void DirectedEnergyPrecisionAimpoint::setRecordType(unsigned int pX)
{
    _recordType = pX;
}

unsigned short DirectedEnergyPrecisionAimpoint::getRecordLength() const
{
    return _recordLength;
}

void DirectedEnergyPrecisionAimpoint::setRecordLength(unsigned short pX)
{
    _recordLength = pX;
}

unsigned short DirectedEnergyPrecisionAimpoint::getPadding() const
{
    return _padding;
}

void DirectedEnergyPrecisionAimpoint::setPadding(unsigned short pX)
{
    _padding = pX;
}

Vector3Double& DirectedEnergyPrecisionAimpoint::getTargetSpotLocation() 
{
    return _targetSpotLocation;
}

const Vector3Double& DirectedEnergyPrecisionAimpoint::getTargetSpotLocation() const
{
    return _targetSpotLocation;
}

void DirectedEnergyPrecisionAimpoint::setTargetSpotLocation(const Vector3Double &pX)
{
    _targetSpotLocation = pX;
}

Vector3Float& DirectedEnergyPrecisionAimpoint::getTargetSpotEntityLocation() 
{
    return _targetSpotEntityLocation;
}

const Vector3Float& DirectedEnergyPrecisionAimpoint::getTargetSpotEntityLocation() const
{
    return _targetSpotEntityLocation;
}

void DirectedEnergyPrecisionAimpoint::setTargetSpotEntityLocation(const Vector3Float &pX)
{
    _targetSpotEntityLocation = pX;
}

Vector3Float& DirectedEnergyPrecisionAimpoint::getTargetSpotVelocity() 
{
    return _targetSpotVelocity;
}

const Vector3Float& DirectedEnergyPrecisionAimpoint::getTargetSpotVelocity() const
{
    return _targetSpotVelocity;
}

void DirectedEnergyPrecisionAimpoint::setTargetSpotVelocity(const Vector3Float &pX)
{
    _targetSpotVelocity = pX;
}

Vector3Float& DirectedEnergyPrecisionAimpoint::getTargetSpotAcceleration() 
{
    return _targetSpotAcceleration;
}

const Vector3Float& DirectedEnergyPrecisionAimpoint::getTargetSpotAcceleration() const
{
    return _targetSpotAcceleration;
}

void DirectedEnergyPrecisionAimpoint::setTargetSpotAcceleration(const Vector3Float &pX)
{
    _targetSpotAcceleration = pX;
}

EntityID& DirectedEnergyPrecisionAimpoint::getTargetEntityID() 
{
    return _targetEntityID;
}

const EntityID& DirectedEnergyPrecisionAimpoint::getTargetEntityID() const
{
    return _targetEntityID;
}

void DirectedEnergyPrecisionAimpoint::setTargetEntityID(const EntityID &pX)
{
    _targetEntityID = pX;
}

unsigned char DirectedEnergyPrecisionAimpoint::getTargetComponentID() const
{
    return _targetComponentID;
}

void DirectedEnergyPrecisionAimpoint::setTargetComponentID(unsigned char pX)
{
    _targetComponentID = pX;
}

unsigned char DirectedEnergyPrecisionAimpoint::getSpotShape() const
{
    return _SpotShape;
}

void DirectedEnergyPrecisionAimpoint::setSpotShape(unsigned char pX)
{
    _SpotShape = pX;
}

float DirectedEnergyPrecisionAimpoint::getBeamSpotXSecSemiMajorAxis() const
{
    return _BeamSpotXSecSemiMajorAxis;
}

void DirectedEnergyPrecisionAimpoint::setBeamSpotXSecSemiMajorAxis(float pX)
{
    _BeamSpotXSecSemiMajorAxis = pX;
}

float DirectedEnergyPrecisionAimpoint::getBeamSpotCrossSectionSemiMinorAxis() const
{
    return _BeamSpotCrossSectionSemiMinorAxis;
}

void DirectedEnergyPrecisionAimpoint::setBeamSpotCrossSectionSemiMinorAxis(float pX)
{
    _BeamSpotCrossSectionSemiMinorAxis = pX;
}

float DirectedEnergyPrecisionAimpoint::getBeamSpotCrossSectionOrientAngle() const
{
    return _BeamSpotCrossSectionOrientAngle;
}

void DirectedEnergyPrecisionAimpoint::setBeamSpotCrossSectionOrientAngle(float pX)
{
    _BeamSpotCrossSectionOrientAngle = pX;
}

void DirectedEnergyPrecisionAimpoint::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _recordLength;
    dataStream << _padding;
    _targetSpotLocation.marshal(dataStream);
    _targetSpotEntityLocation.marshal(dataStream);
    _targetSpotVelocity.marshal(dataStream);
    _targetSpotAcceleration.marshal(dataStream);
    _targetEntityID.marshal(dataStream);
    dataStream << _targetComponentID;
    dataStream << _SpotShape;
    dataStream << _BeamSpotXSecSemiMajorAxis;
    dataStream << _BeamSpotCrossSectionSemiMinorAxis;
    dataStream << _BeamSpotCrossSectionOrientAngle;
}

void DirectedEnergyPrecisionAimpoint::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _recordLength;
    dataStream >> _padding;
    _targetSpotLocation.unmarshal(dataStream);
    _targetSpotEntityLocation.unmarshal(dataStream);
    _targetSpotVelocity.unmarshal(dataStream);
    _targetSpotAcceleration.unmarshal(dataStream);
    _targetEntityID.unmarshal(dataStream);
    dataStream >> _targetComponentID;
    dataStream >> _SpotShape;
    dataStream >> _BeamSpotXSecSemiMajorAxis;
    dataStream >> _BeamSpotCrossSectionSemiMinorAxis;
    dataStream >> _BeamSpotCrossSectionOrientAngle;
}


bool DirectedEnergyPrecisionAimpoint::operator ==(const DirectedEnergyPrecisionAimpoint& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_recordLength == rhs._recordLength) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;
     if( ! (_targetSpotLocation == rhs._targetSpotLocation) ) ivarsEqual = false;
     if( ! (_targetSpotEntityLocation == rhs._targetSpotEntityLocation) ) ivarsEqual = false;
     if( ! (_targetSpotVelocity == rhs._targetSpotVelocity) ) ivarsEqual = false;
     if( ! (_targetSpotAcceleration == rhs._targetSpotAcceleration) ) ivarsEqual = false;
     if( ! (_targetEntityID == rhs._targetEntityID) ) ivarsEqual = false;
     if( ! (_targetComponentID == rhs._targetComponentID) ) ivarsEqual = false;
     if( ! (_SpotShape == rhs._SpotShape) ) ivarsEqual = false;
     if( ! (_BeamSpotXSecSemiMajorAxis == rhs._BeamSpotXSecSemiMajorAxis) ) ivarsEqual = false;
     if( ! (_BeamSpotCrossSectionSemiMinorAxis == rhs._BeamSpotCrossSectionSemiMinorAxis) ) ivarsEqual = false;
     if( ! (_BeamSpotCrossSectionOrientAngle == rhs._BeamSpotCrossSectionOrientAngle) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DirectedEnergyPrecisionAimpoint::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _recordType
   marshalSize = marshalSize + 2;  // _recordLength
   marshalSize = marshalSize + 2;  // _padding
   marshalSize = marshalSize + _targetSpotLocation.getMarshalledSize();  // _targetSpotLocation
   marshalSize = marshalSize + _targetSpotEntityLocation.getMarshalledSize();  // _targetSpotEntityLocation
   marshalSize = marshalSize + _targetSpotVelocity.getMarshalledSize();  // _targetSpotVelocity
   marshalSize = marshalSize + _targetSpotAcceleration.getMarshalledSize();  // _targetSpotAcceleration
   marshalSize = marshalSize + _targetEntityID.getMarshalledSize();  // _targetEntityID
   marshalSize = marshalSize + 1;  // _targetComponentID
   marshalSize = marshalSize + 1;  // _SpotShape
   marshalSize = marshalSize + 4;  // _BeamSpotXSecSemiMajorAxis
   marshalSize = marshalSize + 4;  // _BeamSpotCrossSectionSemiMinorAxis
   marshalSize = marshalSize + 4;  // _BeamSpotCrossSectionOrientAngle
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
