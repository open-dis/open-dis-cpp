#include <dis7/EmissionSystem.h>

using namespace DIS;


EmissionSystem::EmissionSystem():
   _numberOfBeams(0),
   _emitterSystem(), 
   _location()
{
}

EmissionSystem::~EmissionSystem()
{
    _beams.clear();
}

unsigned char EmissionSystem::getNumberOfBeams() const
{
    return _beams.size();
}

EmitterSystem& EmissionSystem::getEmitterSystem() 
{
    return _emitterSystem;
}

const EmitterSystem& EmissionSystem::getEmitterSystem() const
{
    return _emitterSystem;
}

void EmissionSystem::setEmitterSystem(const EmitterSystem &pX)
{
    _emitterSystem = pX;
}

Vector3Float& EmissionSystem::getLocation() 
{
    return _location;
}

const Vector3Float& EmissionSystem::getLocation() const
{
    return _location;
}

void EmissionSystem::setLocation(const Vector3Float &pX)
{
    _location = pX;
}

std::vector<EEBeamData>& DIS::EmissionSystem::getBeams()
{
    return _beams;
}

const std::vector<EEBeamData>& DIS::EmissionSystem::getBeams() const
{
    return _beams;
}

void DIS::EmissionSystem::setBeams(const std::vector<EEBeamData>& pX)
{
    _beams = pX;
}

void EmissionSystem::marshal(DataStream& dataStream) const
{
    dataStream << ( unsigned char )_beams.size();;
    _emitterSystem.marshal(dataStream);
    _location.marshal(dataStream);

    for(size_t idx = 0; idx < _beams.size(); idx++)
    {
        EEBeamData x = _beams[idx];
        x.marshal(dataStream);
    }
}

void EmissionSystem::unmarshal(DataStream& dataStream)
{
    dataStream >> _numberOfBeams;
    _emitterSystem.unmarshal(dataStream);
    _location.unmarshal(dataStream);

    _beams.clear();
    for(size_t idx = 0; idx < _numberOfBeams; idx++)
    {
        EEBeamData x;
        x.unmarshal(dataStream);
        _beams.push_back(x);
    }
}

bool EmissionSystem::operator ==(const EmissionSystem& rhs) const
{
    bool ivarsEqual = true;

    if( ! (_numberOfBeams == rhs._numberOfBeams) ) ivarsEqual = false;
    if( ! (_emitterSystem == rhs._emitterSystem) ) ivarsEqual = false;
    if( ! (_location == rhs._location) ) ivarsEqual = false;

    for(size_t idx = 0; idx < _beams.size(); idx++)
    {
       if( ! ( _beams[idx] == rhs._beams[idx]) ) ivarsEqual = false;
    }
    return ivarsEqual;
}

int EmissionSystem::getMarshalledSize() const
{
    int marshalSize = 0;

    marshalSize += 1;  // _numberOfBeams
    marshalSize += _emitterSystem.getMarshalledSize(); //_emitterSystem
    marshalSize += _location.getMarshalledSize(); //_location

    for(unsigned long long idx=0; idx < _beams.size(); idx++)
    {
        EEBeamData listElement = _beams[idx];
        marshalSize += listElement.getMarshalledSize();
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
