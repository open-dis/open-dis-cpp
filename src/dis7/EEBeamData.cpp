#include <dis7/EEBeamData.h>

using namespace DIS;


EEBeamData::EEBeamData():
   _beamDataLength(0), 
   _beamIDNumber(0), 
   _beamParameterIndex(0), 
   _fundamentalParameterData(), 
   _beamFunction(0), 
   _numberOfTrackJamTargets(0), 
   _highDensityTrackJam(0), 
   _beamStatus(0),
   _jammingTechnique()
{
}

EEBeamData::~EEBeamData()
{
    _trackJamTargets.clear();
}

unsigned char EEBeamData::getBeamDataLength() const
{
    return _beamDataLength;
}

void EEBeamData::setBeamDataLength(unsigned char pX)
{
    _beamDataLength = pX;
}

unsigned char EEBeamData::getBeamIDNumber() const
{
    return _beamIDNumber;
}

void EEBeamData::setBeamIDNumber(unsigned char pX)
{
    _beamIDNumber = pX;
}

unsigned short EEBeamData::getBeamParameterIndex() const
{
    return _beamParameterIndex;
}

void EEBeamData::setBeamParameterIndex(unsigned short pX)
{
    _beamParameterIndex = pX;
}

EEFundamentalParameterData& EEBeamData::getFundamentalParameterData() 
{
    return _fundamentalParameterData;
}

const EEFundamentalParameterData& EEBeamData::getFundamentalParameterData() const
{
    return _fundamentalParameterData;
}

void EEBeamData::setFundamentalParameterData(const EEFundamentalParameterData &pX)
{
    _fundamentalParameterData = pX;
}

unsigned char EEBeamData::getBeamFunction() const
{
    return _beamFunction;
}

void EEBeamData::setBeamFunction(unsigned char pX)
{
    _beamFunction = pX;
}

unsigned char EEBeamData::getNumberOfTrackJamTargets() const
{
   return _trackJamTargets.size();
}

unsigned char EEBeamData::getHighDensityTrackJam() const
{
    return _highDensityTrackJam;
}

void EEBeamData::setHighDensityTrackJam(unsigned char pX)
{
    _highDensityTrackJam = pX;
}

unsigned char EEBeamData::getBeamStatus() const
{
    return _beamStatus;
}

void EEBeamData::setBeamStatus(unsigned char pX)
{
    _beamStatus = pX;
}

JammingTechnique& EEBeamData::getJammingTechnique()
{
    return _jammingTechnique;
}

const JammingTechnique& EEBeamData::getJammingTechnique() const
{
    return _jammingTechnique;
}

void EEBeamData::setJammingTechnique(const JammingTechnique& pX)
{
    _jammingTechnique = pX;
}

std::vector<TrackJamData>& EEBeamData::getTrackJamTargets() 
{
    return _trackJamTargets;
}

const std::vector<TrackJamData>& EEBeamData::getTrackJamTargets() const
{
    return _trackJamTargets;
}

void EEBeamData::setTrackJamTargets(const std::vector<TrackJamData>& pX)
{
     _trackJamTargets = pX;
}

void EEBeamData::marshal(DataStream& dataStream) const
{
    dataStream << _beamDataLength;
    dataStream << _beamIDNumber;
    dataStream << _beamParameterIndex;
    _fundamentalParameterData.marshal(dataStream);
    dataStream << _beamFunction;
    dataStream << ( unsigned char )_trackJamTargets.size();
    dataStream << _highDensityTrackJam;
    dataStream << _beamStatus;
    _jammingTechnique.marshal(dataStream);

     for(size_t idx = 0; idx < _trackJamTargets.size(); idx++)
     {
        TrackJamData x = _trackJamTargets[idx];
        x.marshal(dataStream);
     }

}

void EEBeamData::unmarshal(DataStream& dataStream)
{
    dataStream >> _beamDataLength;
    dataStream >> _beamIDNumber;
    dataStream >> _beamParameterIndex;
    _fundamentalParameterData.unmarshal(dataStream);
    dataStream >> _beamFunction;
    dataStream >> _numberOfTrackJamTargets;
    dataStream >> _highDensityTrackJam;
    dataStream >> _beamStatus;
    _jammingTechnique.unmarshal(dataStream);

    _trackJamTargets.clear();
    for(size_t idx = 0; idx < _numberOfTrackJamTargets; idx++)
    {
       TrackJamData x;
       x.unmarshal(dataStream);
       _trackJamTargets.push_back(x);
    }
}

bool EEBeamData::operator ==(const EEBeamData& rhs) const
{
    bool ivarsEqual = true;

    if( ! (_beamDataLength == rhs._beamDataLength) ) ivarsEqual = false;
    if( ! (_beamIDNumber == rhs._beamIDNumber) ) ivarsEqual = false;
    if( ! (_beamParameterIndex == rhs._beamParameterIndex) ) ivarsEqual = false;
    if( ! (_fundamentalParameterData == rhs._fundamentalParameterData) ) ivarsEqual = false;
    if( ! (_beamFunction == rhs._beamFunction) ) ivarsEqual = false;
    if( ! (_highDensityTrackJam == rhs._highDensityTrackJam) ) ivarsEqual = false;
    if( ! (_beamStatus == rhs._beamStatus) ) ivarsEqual = false;
    if( ! (_jammingTechnique == rhs._jammingTechnique) ) ivarsEqual = false;

    for(size_t idx = 0; idx < _trackJamTargets.size(); idx++)
    {
       if( ! ( _trackJamTargets[idx] == rhs._trackJamTargets[idx]) ) ivarsEqual = false;
    }

    return ivarsEqual;
}

int EEBeamData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _beamDataLength
   marshalSize = marshalSize + 1;  // _beamIDNumber
   marshalSize = marshalSize + 2;  // _beamParameterIndex
   marshalSize = marshalSize + _fundamentalParameterData.getMarshalledSize();  // _fundamentalParameterData
   marshalSize = marshalSize + 1;  // _beamFunction
   marshalSize = marshalSize + 1;  // _numberOfTrackJamTargets
   marshalSize = marshalSize + 1;  // _highDensityTrackJam
   marshalSize = marshalSize + 1;  // _beamStatus
   marshalSize = marshalSize + _jammingTechnique.getMarshalledSize();  // _jammingTechnique

   for(unsigned long long idx=0; idx < _trackJamTargets.size(); idx++)
   {
        TrackJamData listElement = _trackJamTargets[idx];
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
