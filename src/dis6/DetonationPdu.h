#pragma once

#include <dis6/EntityID.h>
#include <dis6/EventID.h>
#include <dis6/Vector3Float.h>
#include <dis6/Vector3Double.h>
#include <dis6/BurstDescriptor.h>
#include <dis6/Vector3Float.h>
#include <dis6/ArticulationParameter.h>
#include <vector>
#include <dis6/WarfareFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.4.2. Information about stuff exploding. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO DetonationPdu : public WarfareFamilyPdu
{
protected:
  /** ID of muntion that was fired */
  EntityID _munitionID; 

  /** ID firing event */
  EventID _eventID; 

  /** ID firing event */
  Vector3Float _velocity; 

  /** where the detonation is, in world coordinates */
  Vector3Double _locationInWorldCoordinates; 

  /** Describes munition used */
  BurstDescriptor _burstDescriptor; 

  /** location of the detonation or impact in the target entity's coordinate system. This information should be used for damage assessment. */
  Vector3Float _locationInEntityCoordinates; 

  /** result of the explosion */
  unsigned char _detonationResult; 

  /** How many articulation parameters we have */
  unsigned char _numberOfArticulationParameters; 

  /** padding */
  short _pad; 

  std::vector<ArticulationParameter> _articulationParameters; 


 public:
    DetonationPdu();
    virtual ~DetonationPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getMunitionID(); 
    const EntityID&  getMunitionID() const; 
    void setMunitionID(const EntityID    &pX);

    EventID& getEventID(); 
    const EventID&  getEventID() const; 
    void setEventID(const EventID    &pX);

    Vector3Float& getVelocity(); 
    const Vector3Float&  getVelocity() const; 
    void setVelocity(const Vector3Float    &pX);

    Vector3Double& getLocationInWorldCoordinates(); 
    const Vector3Double&  getLocationInWorldCoordinates() const; 
    void setLocationInWorldCoordinates(const Vector3Double    &pX);

    BurstDescriptor& getBurstDescriptor(); 
    const BurstDescriptor&  getBurstDescriptor() const; 
    void setBurstDescriptor(const BurstDescriptor    &pX);

    Vector3Float& getLocationInEntityCoordinates(); 
    const Vector3Float&  getLocationInEntityCoordinates() const; 
    void setLocationInEntityCoordinates(const Vector3Float    &pX);

    unsigned char getDetonationResult() const; 
    void setDetonationResult(unsigned char pX); 

    unsigned char getNumberOfArticulationParameters() const; 

    short getPad() const; 
    void setPad(short pX); 

    std::vector<ArticulationParameter>& getArticulationParameters(); 
    const std::vector<ArticulationParameter>& getArticulationParameters() const; 
    void setArticulationParameters(const std::vector<ArticulationParameter>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const DetonationPdu& rhs) const;
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
