#include <DIS/EulerAngles.h> 

using namespace DIS;


EulerAngles::EulerAngles():
   _psi(0.0), 
   _theta(0.0), 
   _phi(0.0)
{
}

EulerAngles::~EulerAngles()
{
}

float EulerAngles::getPsi() const
{
    return _psi;
}

void EulerAngles::setPsi(float pX)
{
    _psi = pX;
}

float EulerAngles::getTheta() const
{
    return _theta;
}

void EulerAngles::setTheta(float pX)
{
    _theta = pX;
}

float EulerAngles::getPhi() const
{
    return _phi;
}

void EulerAngles::setPhi(float pX)
{
    _phi = pX;
}

void EulerAngles::marshal(DataStream& dataStream) const
{
    dataStream << _psi;
    dataStream << _theta;
    dataStream << _phi;
}

void EulerAngles::unmarshal(DataStream& dataStream)
{
    dataStream >> _psi;
    dataStream >> _theta;
    dataStream >> _phi;
}


bool EulerAngles::operator ==(const EulerAngles& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_psi == rhs._psi) ) ivarsEqual = false;
     if( ! (_theta == rhs._theta) ) ivarsEqual = false;
     if( ! (_phi == rhs._phi) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EulerAngles::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _psi
   marshalSize = marshalSize + 4;  // _theta
   marshalSize = marshalSize + 4;  // _phi
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
