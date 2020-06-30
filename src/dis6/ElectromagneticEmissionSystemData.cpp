#include <dis6/ElectromagneticEmissionSystemData.h>

using namespace DIS;


ElectromagneticEmissionSystemData::ElectromagneticEmissionSystemData():
   _systemDataLength(0), 
   _numberOfBeams(0), 
   _emissionsPadding2(0), 
   _emitterSystem(), 
   _location()
{
}

ElectromagneticEmissionSystemData::~ElectromagneticEmissionSystemData()
{
    _beamDataRecords.clear();
}

unsigned char ElectromagneticEmissionSystemData::getSystemDataLength() const
{
    return _systemDataLength;
}

void ElectromagneticEmissionSystemData::setSystemDataLength(unsigned char pX)
{
    _systemDataLength = pX;
}

unsigned char ElectromagneticEmissionSystemData::getNumberOfBeams() const
{
   return _beamDataRecords.size();
}

unsigned short ElectromagneticEmissionSystemData::getEmissionsPadding2() const
{
    return _emissionsPadding2;
}

void ElectromagneticEmissionSystemData::setEmissionsPadding2(unsigned short pX)
{
    _emissionsPadding2 = pX;
}

EmitterSystem& ElectromagneticEmissionSystemData::getEmitterSystem() 
{
    return _emitterSystem;
}

const EmitterSystem& ElectromagneticEmissionSystemData::getEmitterSystem() const
{
    return _emitterSystem;
}

void ElectromagneticEmissionSystemData::setEmitterSystem(const EmitterSystem &pX)
{
    _emitterSystem = pX;
}

Vector3Float& ElectromagneticEmissionSystemData::getLocation() 
{
    return _location;
}

const Vector3Float& ElectromagneticEmissionSystemData::getLocation() const
{
    return _location;
}

void ElectromagneticEmissionSystemData::setLocation(const Vector3Float &pX)
{
    _location = pX;
}

std::vector<ElectromagneticEmissionBeamData>& ElectromagneticEmissionSystemData::getBeamDataRecords() 
{
    return _beamDataRecords;
}

const std::vector<ElectromagneticEmissionBeamData>& ElectromagneticEmissionSystemData::getBeamDataRecords() const
{
    return _beamDataRecords;
}

void ElectromagneticEmissionSystemData::setBeamDataRecords(const std::vector<ElectromagneticEmissionBeamData>& pX)
{
     _beamDataRecords = pX;
}

void ElectromagneticEmissionSystemData::marshal(DataStream& dataStream) const
{
    dataStream << _systemDataLength;
    dataStream << ( unsigned char )_beamDataRecords.size();
    dataStream << _emissionsPadding2;
    _emitterSystem.marshal(dataStream);
    _location.marshal(dataStream);

     for(size_t idx = 0; idx < _beamDataRecords.size(); idx++)
     {
        ElectromagneticEmissionBeamData x = _beamDataRecords[idx];
        x.marshal(dataStream);
     }

}

void ElectromagneticEmissionSystemData::unmarshal(DataStream& dataStream)
{
    dataStream >> _systemDataLength;
    dataStream >> _numberOfBeams;
    dataStream >> _emissionsPadding2;
    _emitterSystem.unmarshal(dataStream);
    _location.unmarshal(dataStream);

     _beamDataRecords.clear();
     for(size_t idx = 0; idx < _numberOfBeams; idx++)
     {
        ElectromagneticEmissionBeamData x;
        x.unmarshal(dataStream);
        _beamDataRecords.push_back(x);
     }
}


bool ElectromagneticEmissionSystemData::operator ==(const ElectromagneticEmissionSystemData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_systemDataLength == rhs._systemDataLength) ) ivarsEqual = false;
     if( ! (_emissionsPadding2 == rhs._emissionsPadding2) ) ivarsEqual = false;
     if( ! (_emitterSystem == rhs._emitterSystem) ) ivarsEqual = false;
     if( ! (_location == rhs._location) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _beamDataRecords.size(); idx++)
     {
        if( ! ( _beamDataRecords[idx] == rhs._beamDataRecords[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ElectromagneticEmissionSystemData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _systemDataLength
   marshalSize = marshalSize + 1;  // _numberOfBeams
   marshalSize = marshalSize + 2;  // _emissionsPadding2
   marshalSize = marshalSize + _emitterSystem.getMarshalledSize();  // _emitterSystem
   marshalSize = marshalSize + _location.getMarshalledSize();  // _location

   for(unsigned long long idx=0; idx < _beamDataRecords.size(); idx++)
   {
        ElectromagneticEmissionBeamData listElement = _beamDataRecords[idx];
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
