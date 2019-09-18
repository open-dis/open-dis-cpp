#ifndef COLLISIONPDU_H
#define COLLISIONPDU_H

#include <dis6/EntityID.h>
#include <dis6/EntityID.h>
#include <dis6/EventID.h>
#include <dis6/Vector3Float.h>
#include <dis6/Vector3Float.h>
#include <dis6/EntityInformationFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.3.2. Information about a collision. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO CollisionPdu : public EntityInformationFamilyPdu
{
protected:
  /** ID of the entity that issued the collision PDU */
  EntityID _issuingEntityID; 

  /** ID of entity that has collided with the issuing entity ID */
  EntityID _collidingEntityID; 

  /** ID of event */
  EventID _eventID; 

  /** ID of event */
  uint8_t _collisionType; 

  /** some padding */
  char _pad; 

  /** velocity at collision */
  Vector3Float _velocity; 

  /** mass of issuing entity */
  float _mass; 

  /** Location with respect to entity the issuing entity collided with */
  Vector3Float _location; 


 public:
    CollisionPdu();
    virtual ~CollisionPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getIssuingEntityID(); 
    const EntityID&  getIssuingEntityID() const; 
    void setIssuingEntityID(const EntityID    &pX);

    EntityID& getCollidingEntityID(); 
    const EntityID&  getCollidingEntityID() const; 
    void setCollidingEntityID(const EntityID    &pX);

    EventID& getEventID(); 
    const EventID&  getEventID() const; 
    void setEventID(const EventID    &pX);

    uint8_t getCollisionType() const; 
    void setCollisionType(uint8_t pX); 

    char getPad() const; 
    void setPad(char pX); 

    Vector3Float& getVelocity(); 
    const Vector3Float&  getVelocity() const; 
    void setVelocity(const Vector3Float    &pX);

    float getMass() const; 
    void setMass(float pX); 

    Vector3Float& getLocation(); 
    const Vector3Float&  getLocation() const; 
    void setLocation(const Vector3Float    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const CollisionPdu& rhs) const;
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
