#include <DIS/BeamAntennaPattern.h> 

using namespace DIS;


BeamAntennaPattern::BeamAntennaPattern():
   _beamDirection(), 
   _azimuthBeamwidth(0), 
   _referenceSystem(0), 
   _padding1(0), 
   _padding2(0), 
   _ez(0.0), 
   _ex(0.0), 
   _phase(0.0)
{
}

BeamAntennaPattern::~BeamAntennaPattern()
{
}

Orientation& BeamAntennaPattern::getBeamDirection() 
{
    return _beamDirection;
}

const Orientation& BeamAntennaPattern::getBeamDirection() const
{
    return _beamDirection;
}

void BeamAntennaPattern::setBeamDirection(const Orientation &pX)
{
    _beamDirection = pX;
}

float BeamAntennaPattern::getAzimuthBeamwidth() const
{
    return _azimuthBeamwidth;
}

void BeamAntennaPattern::setAzimuthBeamwidth(float pX)
{
    _azimuthBeamwidth = pX;
}

float BeamAntennaPattern::getReferenceSystem() const
{
    return _referenceSystem;
}

void BeamAntennaPattern::setReferenceSystem(float pX)
{
    _referenceSystem = pX;
}

short BeamAntennaPattern::getPadding1() const
{
    return _padding1;
}

void BeamAntennaPattern::setPadding1(short pX)
{
    _padding1 = pX;
}

char BeamAntennaPattern::getPadding2() const
{
    return _padding2;
}

void BeamAntennaPattern::setPadding2(char pX)
{
    _padding2 = pX;
}

float BeamAntennaPattern::getEz() const
{
    return _ez;
}

void BeamAntennaPattern::setEz(float pX)
{
    _ez = pX;
}

float BeamAntennaPattern::getEx() const
{
    return _ex;
}

void BeamAntennaPattern::setEx(float pX)
{
    _ex = pX;
}

float BeamAntennaPattern::getPhase() const
{
    return _phase;
}

void BeamAntennaPattern::setPhase(float pX)
{
    _phase = pX;
}

void BeamAntennaPattern::marshal(DataStream& dataStream) const
{
    _beamDirection.marshal(dataStream);
    dataStream << _azimuthBeamwidth;
    dataStream << _referenceSystem;
    dataStream << _padding1;
    dataStream << _padding2;
    dataStream << _ez;
    dataStream << _ex;
    dataStream << _phase;
}

void BeamAntennaPattern::unmarshal(DataStream& dataStream)
{
    _beamDirection.unmarshal(dataStream);
    dataStream >> _azimuthBeamwidth;
    dataStream >> _referenceSystem;
    dataStream >> _padding1;
    dataStream >> _padding2;
    dataStream >> _ez;
    dataStream >> _ex;
    dataStream >> _phase;
}


bool BeamAntennaPattern::operator ==(const BeamAntennaPattern& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_beamDirection == rhs._beamDirection) ) ivarsEqual = false;
     if( ! (_azimuthBeamwidth == rhs._azimuthBeamwidth) ) ivarsEqual = false;
     if( ! (_referenceSystem == rhs._referenceSystem) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;
     if( ! (_ez == rhs._ez) ) ivarsEqual = false;
     if( ! (_ex == rhs._ex) ) ivarsEqual = false;
     if( ! (_phase == rhs._phase) ) ivarsEqual = false;

    return ivarsEqual;
 }

int BeamAntennaPattern::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _beamDirection.getMarshalledSize();  // _beamDirection
   marshalSize = marshalSize + 4;  // _azimuthBeamwidth
   marshalSize = marshalSize + 4;  // _referenceSystem
   marshalSize = marshalSize + 2;  // _padding1
   marshalSize = marshalSize + 1;  // _padding2
   marshalSize = marshalSize + 4;  // _ez
   marshalSize = marshalSize + 4;  // _ex
   marshalSize = marshalSize + 4;  // _phase
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
