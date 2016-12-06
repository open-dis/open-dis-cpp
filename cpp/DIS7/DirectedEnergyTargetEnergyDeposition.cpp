#include <DIS/DirectedEnergyTargetEnergyDeposition.h> 

using namespace DIS;


DirectedEnergyTargetEnergyDeposition::DirectedEnergyTargetEnergyDeposition():
   _targetEntityID(), 
   _padding(0), 
   _peakIrradiance(0.0)
{
}

DirectedEnergyTargetEnergyDeposition::~DirectedEnergyTargetEnergyDeposition()
{
}

EntityID& DirectedEnergyTargetEnergyDeposition::getTargetEntityID() 
{
    return _targetEntityID;
}

const EntityID& DirectedEnergyTargetEnergyDeposition::getTargetEntityID() const
{
    return _targetEntityID;
}

void DirectedEnergyTargetEnergyDeposition::setTargetEntityID(const EntityID &pX)
{
    _targetEntityID = pX;
}

unsigned short DirectedEnergyTargetEnergyDeposition::getPadding() const
{
    return _padding;
}

void DirectedEnergyTargetEnergyDeposition::setPadding(unsigned short pX)
{
    _padding = pX;
}

float DirectedEnergyTargetEnergyDeposition::getPeakIrradiance() const
{
    return _peakIrradiance;
}

void DirectedEnergyTargetEnergyDeposition::setPeakIrradiance(float pX)
{
    _peakIrradiance = pX;
}

void DirectedEnergyTargetEnergyDeposition::marshal(DataStream& dataStream) const
{
    _targetEntityID.marshal(dataStream);
    dataStream << _padding;
    dataStream << _peakIrradiance;
}

void DirectedEnergyTargetEnergyDeposition::unmarshal(DataStream& dataStream)
{
    _targetEntityID.unmarshal(dataStream);
    dataStream >> _padding;
    dataStream >> _peakIrradiance;
}


bool DirectedEnergyTargetEnergyDeposition::operator ==(const DirectedEnergyTargetEnergyDeposition& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_targetEntityID == rhs._targetEntityID) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;
     if( ! (_peakIrradiance == rhs._peakIrradiance) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DirectedEnergyTargetEnergyDeposition::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _targetEntityID.getMarshalledSize();  // _targetEntityID
   marshalSize = marshalSize + 2;  // _padding
   marshalSize = marshalSize + 4;  // _peakIrradiance
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
