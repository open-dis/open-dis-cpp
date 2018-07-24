#include <DIS/BeamData.h> 

using namespace DIS;


BeamData::BeamData():
   _beamAzimuthCenter(0.0), 
   _beamAzimuthSweep(0.0), 
   _beamElevationCenter(0.0), 
   _beamElevationSweep(0.0), 
   _beamSweepSync(0.0)
{
}

BeamData::~BeamData()
{
}

float BeamData::getBeamAzimuthCenter() const
{
    return _beamAzimuthCenter;
}

void BeamData::setBeamAzimuthCenter(float pX)
{
    _beamAzimuthCenter = pX;
}

float BeamData::getBeamAzimuthSweep() const
{
    return _beamAzimuthSweep;
}

void BeamData::setBeamAzimuthSweep(float pX)
{
    _beamAzimuthSweep = pX;
}

float BeamData::getBeamElevationCenter() const
{
    return _beamElevationCenter;
}

void BeamData::setBeamElevationCenter(float pX)
{
    _beamElevationCenter = pX;
}

float BeamData::getBeamElevationSweep() const
{
    return _beamElevationSweep;
}

void BeamData::setBeamElevationSweep(float pX)
{
    _beamElevationSweep = pX;
}

float BeamData::getBeamSweepSync() const
{
    return _beamSweepSync;
}

void BeamData::setBeamSweepSync(float pX)
{
    _beamSweepSync = pX;
}

void BeamData::marshal(DataStream& dataStream) const
{
    dataStream << _beamAzimuthCenter;
    dataStream << _beamAzimuthSweep;
    dataStream << _beamElevationCenter;
    dataStream << _beamElevationSweep;
    dataStream << _beamSweepSync;
}

void BeamData::unmarshal(DataStream& dataStream)
{
    dataStream >> _beamAzimuthCenter;
    dataStream >> _beamAzimuthSweep;
    dataStream >> _beamElevationCenter;
    dataStream >> _beamElevationSweep;
    dataStream >> _beamSweepSync;
}


bool BeamData::operator ==(const BeamData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_beamAzimuthCenter == rhs._beamAzimuthCenter) ) ivarsEqual = false;
     if( ! (_beamAzimuthSweep == rhs._beamAzimuthSweep) ) ivarsEqual = false;
     if( ! (_beamElevationCenter == rhs._beamElevationCenter) ) ivarsEqual = false;
     if( ! (_beamElevationSweep == rhs._beamElevationSweep) ) ivarsEqual = false;
     if( ! (_beamSweepSync == rhs._beamSweepSync) ) ivarsEqual = false;

    return ivarsEqual;
 }

int BeamData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _beamAzimuthCenter
   marshalSize = marshalSize + 4;  // _beamAzimuthSweep
   marshalSize = marshalSize + 4;  // _beamElevationCenter
   marshalSize = marshalSize + 4;  // _beamElevationSweep
   marshalSize = marshalSize + 4;  // _beamSweepSync
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
