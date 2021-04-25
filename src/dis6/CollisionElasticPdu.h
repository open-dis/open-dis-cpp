#pragma once

#include <dis6/EntityID.h>
#include <dis6/EntityID.h>
#include <dis6/EventID.h>
#include <dis6/Vector3Float.h>
#include <dis6/Vector3Float.h>
#include <dis6/Vector3Float.h>
#include <dis6/EntityInformationFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// 5.3.3.3. Information about elastic collisions in a DIS exercise shall be communicated using a Collision-Elastic PDU. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO CollisionElasticPdu : public EntityInformationFamilyPdu
{
protected:
  /** ID of the entity that issued the collision PDU */
  EntityID _issuingEntityID; 

  /** ID of entity that has collided with the issuing entity ID */
  EntityID _collidingEntityID; 

  /** ID of event */
  EventID _collisionEventID; 

  /** some padding */
  short _pad; 

  /** velocity at collision */
  Vector3Float _contactVelocity; 

  /** mass of issuing entity */
  float _mass; 

  /** Location with respect to entity the issuing entity collided with */
  Vector3Float _location; 

  /** tensor values */
  float _collisionResultXX; 

  /** tensor values */
  float _collisionResultXY; 

  /** tensor values */
  float _collisionResultXZ; 

  /** tensor values */
  float _collisionResultYY; 

  /** tensor values */
  float _collisionResultYZ; 

  /** tensor values */
  float _collisionResultZZ; 

  /** This record shall represent the normal vector to the surface at the point of collision detection. The surface normal shall be represented in world coordinates. */
  Vector3Float _unitSurfaceNormal; 

  /** This field shall represent the degree to which energy is conserved in a collision */
  float _coefficientOfRestitution; 


 public:
    CollisionElasticPdu();
    virtual ~CollisionElasticPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getIssuingEntityID(); 
    const EntityID&  getIssuingEntityID() const; 
    void setIssuingEntityID(const EntityID    &pX);

    EntityID& getCollidingEntityID(); 
    const EntityID&  getCollidingEntityID() const; 
    void setCollidingEntityID(const EntityID    &pX);

    EventID& getCollisionEventID(); 
    const EventID&  getCollisionEventID() const; 
    void setCollisionEventID(const EventID    &pX);

    short getPad() const; 
    void setPad(short pX); 

    Vector3Float& getContactVelocity(); 
    const Vector3Float&  getContactVelocity() const; 
    void setContactVelocity(const Vector3Float    &pX);

    float getMass() const; 
    void setMass(float pX); 

    Vector3Float& getLocation(); 
    const Vector3Float&  getLocation() const; 
    void setLocation(const Vector3Float    &pX);

    float getCollisionResultXX() const; 
    void setCollisionResultXX(float pX); 

    float getCollisionResultXY() const; 
    void setCollisionResultXY(float pX); 

    float getCollisionResultXZ() const; 
    void setCollisionResultXZ(float pX); 

    float getCollisionResultYY() const; 
    void setCollisionResultYY(float pX); 

    float getCollisionResultYZ() const; 
    void setCollisionResultYZ(float pX); 

    float getCollisionResultZZ() const; 
    void setCollisionResultZZ(float pX); 

    Vector3Float& getUnitSurfaceNormal(); 
    const Vector3Float&  getUnitSurfaceNormal() const; 
    void setUnitSurfaceNormal(const Vector3Float    &pX);

    float getCoefficientOfRestitution() const; 
    void setCoefficientOfRestitution(float pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const CollisionElasticPdu& rhs) const;
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
