#ifndef DEADRECKONINGPARAMETER_H
#define DEADRECKONINGPARAMETER_H

#include <dis6/Vector3Float.h>
#include <dis6/Vector3Float.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// represents values used in dead reckoning algorithms

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO DeadReckoningParameter
{
protected:
  /** enumeration of what dead reckoning algorighm to use */
  uint8_t _deadReckoningAlgorithm; 

  /** other parameters to use in the dead reckoning algorithm */
  char _otherParameters[15]; 

  /** Linear acceleration of the entity */
  Vector3Float _entityLinearAcceleration; 

  /** angular velocity of the entity */
  Vector3Float _entityAngularVelocity; 


 public:
    DeadReckoningParameter();
    virtual ~DeadReckoningParameter();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    uint8_t getDeadReckoningAlgorithm() const; 
    void setDeadReckoningAlgorithm(uint8_t pX); 

    char*  getOtherParameters(); 
    const char*  getOtherParameters() const; 
    void setOtherParameters( const char*    pX);

    Vector3Float& getEntityLinearAcceleration(); 
    const Vector3Float&  getEntityLinearAcceleration() const; 
    void setEntityLinearAcceleration(const Vector3Float    &pX);

    Vector3Float& getEntityAngularVelocity(); 
    const Vector3Float&  getEntityAngularVelocity() const; 
    void setEntityAngularVelocity(const Vector3Float    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const DeadReckoningParameter& rhs) const;
};
}

#endif
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
