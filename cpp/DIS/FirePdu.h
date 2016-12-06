#ifndef FIREPDU_H
#define FIREPDU_H

#include <DIS/EntityID.h>
#include <DIS/EventID.h>
#include <DIS/Vector3Double.h>
#include <DIS/BurstDescriptor.h>
#include <DIS/Vector3Float.h>
#include <DIS/WarfareFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Sectioin 5.3.4.1. Information about someone firing something. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO FirePdu : public WarfareFamilyPdu
{
protected:
  /** ID of the munition that is being shot */
  EntityID _munitionID; 

  /** ID of event */
  EventID _eventID; 

  int _fireMissionIndex; 

  /** location of the firing event */
  Vector3Double _locationInWorldCoordinates; 

  /** Describes munitions used in the firing event */
  BurstDescriptor _burstDescriptor; 

  /** Velocity of the ammunition */
  Vector3Float _velocity; 

  /** range to the target */
  float _range; 


 public:
    FirePdu();
    virtual ~FirePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getMunitionID(); 
    const EntityID&  getMunitionID() const; 
    void setMunitionID(const EntityID    &pX);

    EventID& getEventID(); 
    const EventID&  getEventID() const; 
    void setEventID(const EventID    &pX);

    int getFireMissionIndex() const; 
    void setFireMissionIndex(int pX); 

    Vector3Double& getLocationInWorldCoordinates(); 
    const Vector3Double&  getLocationInWorldCoordinates() const; 
    void setLocationInWorldCoordinates(const Vector3Double    &pX);

    BurstDescriptor& getBurstDescriptor(); 
    const BurstDescriptor&  getBurstDescriptor() const; 
    void setBurstDescriptor(const BurstDescriptor    &pX);

    Vector3Float& getVelocity(); 
    const Vector3Float&  getVelocity() const; 
    void setVelocity(const Vector3Float    &pX);

    float getRange() const; 
    void setRange(float pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const FirePdu& rhs) const;
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
