#include <dis6/ElectromagneticEmissionBeamData.h>

using namespace DIS;


ElectromagneticEmissionBeamData::ElectromagneticEmissionBeamData():
   _beamDataLength(0), 
   _beamIDNumber(0), 
   _beamParameterIndex(0), 
   _fundamentalParameterData(), 
   _beamFunction(0), 
   _numberOfTrackJamTargets(0), 
   _highDensityTrackJam(0), 
   _pad4(0), 
   _jammingModeSequence(0)
{
}

ElectromagneticEmissionBeamData::~ElectromagneticEmissionBeamData()
{
    _trackJamTargets.clear();
}

unsigned char ElectromagneticEmissionBeamData::getBeamDataLength() const
{
    return _beamDataLength;
}

void ElectromagneticEmissionBeamData::setBeamDataLength(unsigned char pX)
{
    _beamDataLength = pX;
}

unsigned char ElectromagneticEmissionBeamData::getBeamIDNumber() const
{
    return _beamIDNumber;
}

void ElectromagneticEmissionBeamData::setBeamIDNumber(unsigned char pX)
{
    _beamIDNumber = pX;
}

unsigned short ElectromagneticEmissionBeamData::getBeamParameterIndex() const
{
    return _beamParameterIndex;
}

void ElectromagneticEmissionBeamData::setBeamParameterIndex(unsigned short pX)
{
    _beamParameterIndex = pX;
}

FundamentalParameterData& ElectromagneticEmissionBeamData::getFundamentalParameterData() 
{
    return _fundamentalParameterData;
}

const FundamentalParameterData& ElectromagneticEmissionBeamData::getFundamentalParameterData() const
{
    return _fundamentalParameterData;
}

void ElectromagneticEmissionBeamData::setFundamentalParameterData(const FundamentalParameterData &pX)
{
    _fundamentalParameterData = pX;
}

unsigned char ElectromagneticEmissionBeamData::getBeamFunction() const
{
    return _beamFunction;
}

void ElectromagneticEmissionBeamData::setBeamFunction(unsigned char pX)
{
    _beamFunction = pX;
}

unsigned char ElectromagneticEmissionBeamData::getNumberOfTrackJamTargets() const
{
   return _trackJamTargets.size();
}

unsigned char ElectromagneticEmissionBeamData::getHighDensityTrackJam() const
{
    return _highDensityTrackJam;
}

void ElectromagneticEmissionBeamData::setHighDensityTrackJam(unsigned char pX)
{
    _highDensityTrackJam = pX;
}

unsigned char ElectromagneticEmissionBeamData::getPad4() const
{
    return _pad4;
}

void ElectromagneticEmissionBeamData::setPad4(unsigned char pX)
{
    _pad4 = pX;
}

unsigned int ElectromagneticEmissionBeamData::getJammingModeSequence() const
{
    return _jammingModeSequence;
}

void ElectromagneticEmissionBeamData::setJammingModeSequence(unsigned int pX)
{
    _jammingModeSequence = pX;
}

std::vector<TrackJamTarget>& ElectromagneticEmissionBeamData::getTrackJamTargets() 
{
    return _trackJamTargets;
}

const std::vector<TrackJamTarget>& ElectromagneticEmissionBeamData::getTrackJamTargets() const
{
    return _trackJamTargets;
}

void ElectromagneticEmissionBeamData::setTrackJamTargets(const std::vector<TrackJamTarget>& pX)
{
     _trackJamTargets = pX;
}

void ElectromagneticEmissionBeamData::marshal(DataStream& dataStream) const
{
    dataStream << _beamDataLength;
    dataStream << _beamIDNumber;
    dataStream << _beamParameterIndex;
    _fundamentalParameterData.marshal(dataStream);
    dataStream << _beamFunction;
    dataStream << ( unsigned char )_trackJamTargets.size();
    dataStream << _highDensityTrackJam;
    dataStream << _pad4;
    dataStream << _jammingModeSequence;

     for(size_t idx = 0; idx < _trackJamTargets.size(); idx++)
     {
        TrackJamTarget x = _trackJamTargets[idx];
        x.marshal(dataStream);
     }

}

void ElectromagneticEmissionBeamData::unmarshal(DataStream& dataStream)
{
    dataStream >> _beamDataLength;
    dataStream >> _beamIDNumber;
    dataStream >> _beamParameterIndex;
    _fundamentalParameterData.unmarshal(dataStream);
    dataStream >> _beamFunction;
    dataStream >> _numberOfTrackJamTargets;
    dataStream >> _highDensityTrackJam;
    dataStream >> _pad4;
    dataStream >> _jammingModeSequence;

     _trackJamTargets.clear();
     for(size_t idx = 0; idx < _numberOfTrackJamTargets; idx++)
     {
        TrackJamTarget x;
        x.unmarshal(dataStream);
        _trackJamTargets.push_back(x);
     }
}


bool ElectromagneticEmissionBeamData::operator ==(const ElectromagneticEmissionBeamData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_beamDataLength == rhs._beamDataLength) ) ivarsEqual = false;
     if( ! (_beamIDNumber == rhs._beamIDNumber) ) ivarsEqual = false;
     if( ! (_beamParameterIndex == rhs._beamParameterIndex) ) ivarsEqual = false;
     if( ! (_fundamentalParameterData == rhs._fundamentalParameterData) ) ivarsEqual = false;
     if( ! (_beamFunction == rhs._beamFunction) ) ivarsEqual = false;
     if( ! (_highDensityTrackJam == rhs._highDensityTrackJam) ) ivarsEqual = false;
     if( ! (_pad4 == rhs._pad4) ) ivarsEqual = false;
     if( ! (_jammingModeSequence == rhs._jammingModeSequence) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _trackJamTargets.size(); idx++)
     {
        if( ! ( _trackJamTargets[idx] == rhs._trackJamTargets[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ElectromagneticEmissionBeamData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _beamDataLength
   marshalSize = marshalSize + 1;  // _beamIDNumber
   marshalSize = marshalSize + 2;  // _beamParameterIndex
   marshalSize = marshalSize + _fundamentalParameterData.getMarshalledSize();  // _fundamentalParameterData
   marshalSize = marshalSize + 1;  // _beamFunction
   marshalSize = marshalSize + 1;  // _numberOfTrackJamTargets
   marshalSize = marshalSize + 1;  // _highDensityTrackJam
   marshalSize = marshalSize + 1;  // _pad4
   marshalSize = marshalSize + 4;  // _jammingModeSequence

   for(unsigned long long idx=0; idx < _trackJamTargets.size(); idx++)
   {
        TrackJamTarget listElement = _trackJamTargets[idx];
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
