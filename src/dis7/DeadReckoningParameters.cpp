#include <DIS/DeadReckoningParameters.h> 

using namespace DIS;


DeadReckoningParameters::DeadReckoningParameters():
   _deadReckoningAlgorithm(0), 
   _entityLinearAcceleration(), 
   _entityAngularVelocity()
{
     // Initialize fixed length array
     for(int lengthparameters= 0; lengthparameters < 15; lengthparameters++)
     {
         _parameters[lengthparameters] = 0;
     }

}

DeadReckoningParameters::~DeadReckoningParameters()
{
}

unsigned char DeadReckoningParameters::getDeadReckoningAlgorithm() const
{
    return _deadReckoningAlgorithm;
}

void DeadReckoningParameters::setDeadReckoningAlgorithm(unsigned char pX)
{
    _deadReckoningAlgorithm = pX;
}

unsigned char* DeadReckoningParameters::getParameters() 
{
    return _parameters;
}

const unsigned char* DeadReckoningParameters::getParameters() const
{
    return _parameters;
}

void DeadReckoningParameters::setParameters(const unsigned char* x)
{
   for(int i = 0; i < 15; i++)
   {
        _parameters[i] = x[i];
   }
}

Vector3Float& DeadReckoningParameters::getEntityLinearAcceleration() 
{
    return _entityLinearAcceleration;
}

const Vector3Float& DeadReckoningParameters::getEntityLinearAcceleration() const
{
    return _entityLinearAcceleration;
}

void DeadReckoningParameters::setEntityLinearAcceleration(const Vector3Float &pX)
{
    _entityLinearAcceleration = pX;
}

Vector3Float& DeadReckoningParameters::getEntityAngularVelocity() 
{
    return _entityAngularVelocity;
}

const Vector3Float& DeadReckoningParameters::getEntityAngularVelocity() const
{
    return _entityAngularVelocity;
}

void DeadReckoningParameters::setEntityAngularVelocity(const Vector3Float &pX)
{
    _entityAngularVelocity = pX;
}

void DeadReckoningParameters::marshal(DataStream& dataStream) const
{
    dataStream << _deadReckoningAlgorithm;

     for(size_t idx = 0; idx < 15; idx++)
     {
        dataStream << _parameters[idx];
     }

    _entityLinearAcceleration.marshal(dataStream);
    _entityAngularVelocity.marshal(dataStream);
}

void DeadReckoningParameters::unmarshal(DataStream& dataStream)
{
    dataStream >> _deadReckoningAlgorithm;

     for(size_t idx = 0; idx < 15; idx++)
     {
        dataStream >> _parameters[idx];
     }

    _entityLinearAcceleration.unmarshal(dataStream);
    _entityAngularVelocity.unmarshal(dataStream);
}


bool DeadReckoningParameters::operator ==(const DeadReckoningParameters& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_deadReckoningAlgorithm == rhs._deadReckoningAlgorithm) ) ivarsEqual = false;

     for(unsigned char idx = 0; idx < 15; idx++)
     {
          if(!(_parameters[idx] == rhs._parameters[idx]) ) ivarsEqual = false;
     }

     if( ! (_entityLinearAcceleration == rhs._entityLinearAcceleration) ) ivarsEqual = false;
     if( ! (_entityAngularVelocity == rhs._entityAngularVelocity) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DeadReckoningParameters::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _deadReckoningAlgorithm
   marshalSize = marshalSize + 15 * 1;  // _parameters
   marshalSize = marshalSize + _entityLinearAcceleration.getMarshalledSize();  // _entityLinearAcceleration
   marshalSize = marshalSize + _entityAngularVelocity.getMarshalledSize();  // _entityAngularVelocity
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
