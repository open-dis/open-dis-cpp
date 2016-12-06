#include <DIS/ExplosionDescriptor.h> 

using namespace DIS;


ExplosionDescriptor::ExplosionDescriptor():
   _explodingObject(), 
   _explosiveMaterial(0), 
   _padding(0), 
   _explosiveForce(0.0)
{
}

ExplosionDescriptor::~ExplosionDescriptor()
{
}

EntityType& ExplosionDescriptor::getExplodingObject() 
{
    return _explodingObject;
}

const EntityType& ExplosionDescriptor::getExplodingObject() const
{
    return _explodingObject;
}

void ExplosionDescriptor::setExplodingObject(const EntityType &pX)
{
    _explodingObject = pX;
}

unsigned short ExplosionDescriptor::getExplosiveMaterial() const
{
    return _explosiveMaterial;
}

void ExplosionDescriptor::setExplosiveMaterial(unsigned short pX)
{
    _explosiveMaterial = pX;
}

unsigned short ExplosionDescriptor::getPadding() const
{
    return _padding;
}

void ExplosionDescriptor::setPadding(unsigned short pX)
{
    _padding = pX;
}

float ExplosionDescriptor::getExplosiveForce() const
{
    return _explosiveForce;
}

void ExplosionDescriptor::setExplosiveForce(float pX)
{
    _explosiveForce = pX;
}

void ExplosionDescriptor::marshal(DataStream& dataStream) const
{
    _explodingObject.marshal(dataStream);
    dataStream << _explosiveMaterial;
    dataStream << _padding;
    dataStream << _explosiveForce;
}

void ExplosionDescriptor::unmarshal(DataStream& dataStream)
{
    _explodingObject.unmarshal(dataStream);
    dataStream >> _explosiveMaterial;
    dataStream >> _padding;
    dataStream >> _explosiveForce;
}


bool ExplosionDescriptor::operator ==(const ExplosionDescriptor& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_explodingObject == rhs._explodingObject) ) ivarsEqual = false;
     if( ! (_explosiveMaterial == rhs._explosiveMaterial) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;
     if( ! (_explosiveForce == rhs._explosiveForce) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ExplosionDescriptor::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _explodingObject.getMarshalledSize();  // _explodingObject
   marshalSize = marshalSize + 2;  // _explosiveMaterial
   marshalSize = marshalSize + 2;  // _padding
   marshalSize = marshalSize + 4;  // _explosiveForce
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
