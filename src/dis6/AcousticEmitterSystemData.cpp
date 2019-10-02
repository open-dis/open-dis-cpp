#include <dis6/AcousticEmitterSystemData.h>

using namespace DIS;


AcousticEmitterSystemData::AcousticEmitterSystemData():
   _emitterSystemDataLength(0), 
   _numberOfBeams(0), 
   _pad2(0), 
   _acousticEmitterSystem(), 
   _emitterLocation()
{
}

AcousticEmitterSystemData::~AcousticEmitterSystemData()
{
    _beamRecords.clear();
}

unsigned char AcousticEmitterSystemData::getEmitterSystemDataLength() const
{
    return _emitterSystemDataLength;
}

void AcousticEmitterSystemData::setEmitterSystemDataLength(unsigned char pX)
{
    _emitterSystemDataLength = pX;
}

unsigned char AcousticEmitterSystemData::getNumberOfBeams() const
{
   return _beamRecords.size();
}

unsigned short AcousticEmitterSystemData::getPad2() const
{
    return _pad2;
}

void AcousticEmitterSystemData::setPad2(unsigned short pX)
{
    _pad2 = pX;
}

AcousticEmitterSystem& AcousticEmitterSystemData::getAcousticEmitterSystem() 
{
    return _acousticEmitterSystem;
}

const AcousticEmitterSystem& AcousticEmitterSystemData::getAcousticEmitterSystem() const
{
    return _acousticEmitterSystem;
}

void AcousticEmitterSystemData::setAcousticEmitterSystem(const AcousticEmitterSystem &pX)
{
    _acousticEmitterSystem = pX;
}

Vector3Float& AcousticEmitterSystemData::getEmitterLocation() 
{
    return _emitterLocation;
}

const Vector3Float& AcousticEmitterSystemData::getEmitterLocation() const
{
    return _emitterLocation;
}

void AcousticEmitterSystemData::setEmitterLocation(const Vector3Float &pX)
{
    _emitterLocation = pX;
}

std::vector<AcousticBeamData>& AcousticEmitterSystemData::getBeamRecords() 
{
    return _beamRecords;
}

const std::vector<AcousticBeamData>& AcousticEmitterSystemData::getBeamRecords() const
{
    return _beamRecords;
}

void AcousticEmitterSystemData::setBeamRecords(const std::vector<AcousticBeamData>& pX)
{
     _beamRecords = pX;
}

void AcousticEmitterSystemData::marshal(DataStream& dataStream) const
{
    dataStream << _emitterSystemDataLength;
    dataStream << ( unsigned char )_beamRecords.size();
    dataStream << _pad2;
    _acousticEmitterSystem.marshal(dataStream);
    _emitterLocation.marshal(dataStream);

     for(size_t idx = 0; idx < _beamRecords.size(); idx++)
     {
        AcousticBeamData x = _beamRecords[idx];
        x.marshal(dataStream);
     }

}

void AcousticEmitterSystemData::unmarshal(DataStream& dataStream)
{
    dataStream >> _emitterSystemDataLength;
    dataStream >> _numberOfBeams;
    dataStream >> _pad2;
    _acousticEmitterSystem.unmarshal(dataStream);
    _emitterLocation.unmarshal(dataStream);

     _beamRecords.clear();
     for(size_t idx = 0; idx < _numberOfBeams; idx++)
     {
        AcousticBeamData x;
        x.unmarshal(dataStream);
        _beamRecords.push_back(x);
     }
}


bool AcousticEmitterSystemData::operator ==(const AcousticEmitterSystemData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_emitterSystemDataLength == rhs._emitterSystemDataLength) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_acousticEmitterSystem == rhs._acousticEmitterSystem) ) ivarsEqual = false;
     if( ! (_emitterLocation == rhs._emitterLocation) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _beamRecords.size(); idx++)
     {
        if( ! ( _beamRecords[idx] == rhs._beamRecords[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int AcousticEmitterSystemData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _emitterSystemDataLength
   marshalSize = marshalSize + 1;  // _numberOfBeams
   marshalSize = marshalSize + 2;  // _pad2
   marshalSize = marshalSize + _acousticEmitterSystem.getMarshalledSize();  // _acousticEmitterSystem
   marshalSize = marshalSize + _emitterLocation.getMarshalledSize();  // _emitterLocation

   for(unsigned long long idx=0; idx < _beamRecords.size(); idx++)
   {
        AcousticBeamData listElement = _beamRecords[idx];
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
