#pragma once

#include <dis6/EntityID.h>
#include <dis6/Vector3Float.h>
#include <dis6/Vector3Double.h>
#include <dis6/Orientation.h>
#include <dis6/ArticulationParameter.h>
#include <vector>
#include <dis6/EntityInformationFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// 5.3.3.4. Nonstatic information about a particular entity may be communicated by issuing an Entity State Update PDU. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO EntityStateUpdatePdu : public EntityInformationFamilyPdu
{
protected:
  /** This field shall identify the entity issuing the PDU */
  EntityID _entityID; 

  /** Padding */
  char _padding1; 

  /** How many articulation parameters are in the variable length list */
  unsigned char _numberOfArticulationParameters; 

  /** Describes the speed of the entity in the world */
  Vector3Float _entityLinearVelocity; 

  /** describes the location of the entity in the world */
  Vector3Double _entityLocation; 

  /** describes the orientation of the entity, in euler angles */
  Orientation _entityOrientation; 

  /** a series of bit flags that are used to help draw the entity, such as smoking, on fire, etc. */
  int _entityAppearance; 

  std::vector<ArticulationParameter> _articulationParameters; 


 public:
    EntityStateUpdatePdu();
    virtual ~EntityStateUpdatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getEntityID(); 
    const EntityID&  getEntityID() const; 
    void setEntityID(const EntityID    &pX);

    char getPadding1() const; 
    void setPadding1(char pX); 

    unsigned char getNumberOfArticulationParameters() const; 

    Vector3Float& getEntityLinearVelocity(); 
    const Vector3Float&  getEntityLinearVelocity() const; 
    void setEntityLinearVelocity(const Vector3Float    &pX);

    Vector3Double& getEntityLocation(); 
    const Vector3Double&  getEntityLocation() const; 
    void setEntityLocation(const Vector3Double    &pX);

    Orientation& getEntityOrientation(); 
    const Orientation&  getEntityOrientation() const; 
    void setEntityOrientation(const Orientation    &pX);

    int getEntityAppearance() const; 
    void setEntityAppearance(int pX); 

    std::vector<ArticulationParameter>& getArticulationParameters(); 
    const std::vector<ArticulationParameter>& getArticulationParameters() const; 
    void setArticulationParameters(const std::vector<ArticulationParameter>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const EntityStateUpdatePdu& rhs) const;
};
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
