#ifndef DETONATIONPDU_H
#define DETONATIONPDU_H

#include <DIS/EntityID.h>
#include <DIS/EventIdentifier.h>
#include <DIS/Vector3Float.h>
#include <DIS/Vector3Double.h>
#include <DIS/MunitionDescriptor.h>
#include <DIS/Vector3Float.h>
#include <DIS/VariableParameter.h>
#include <vector>
#include <DIS/WarfareFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Detonation or impact of munitions, as well as, non-munition explosions, the burst or initial bloom of chaff, and the ignition of a flare shall be indicated. Section 7.3.3  COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO DetonationPdu : public WarfareFamilyPdu
{
protected:
  /** ID of the expendable entity, Section 7.3.3  */
  EntityID _explodingEntityID; 

  /** ID of event, Section 7.3.3 */
  EventIdentifier _eventID; 

  /** velocity of the munition immediately before detonation/impact, Section 7.3.3  */
  Vector3Float _velocity; 

  /** location of the munition detonation, the expendable detonation, Section 7.3.3  */
  Vector3Double _locationInWorldCoordinates; 

  /** Describes the detonation represented, Section 7.3.3  */
  MunitionDescriptor _descriptor; 

  /** Velocity of the ammunition, Section 7.3.3  */
  Vector3Float _locationOfEntityCoordinates; 

  /** result of the detonation, Section 7.3.3  */
  unsigned char _detonationResult; 

  /** How many articulation parameters we have, Section 7.3.3  */
  unsigned char _numberOfVariableParameters; 

  /** padding */
  unsigned short _pad; 

  /** specify the parameter values for each Variable Parameter record, Section 7.3.3  */
  std::vector<VariableParameter> _variableParameters; 


 public:
    DetonationPdu();
    virtual ~DetonationPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getExplodingEntityID(); 
    const EntityID&  getExplodingEntityID() const; 
    void setExplodingEntityID(const EntityID    &pX);

    EventIdentifier& getEventID(); 
    const EventIdentifier&  getEventID() const; 
    void setEventID(const EventIdentifier    &pX);

    Vector3Float& getVelocity(); 
    const Vector3Float&  getVelocity() const; 
    void setVelocity(const Vector3Float    &pX);

    Vector3Double& getLocationInWorldCoordinates(); 
    const Vector3Double&  getLocationInWorldCoordinates() const; 
    void setLocationInWorldCoordinates(const Vector3Double    &pX);

    MunitionDescriptor& getDescriptor(); 
    const MunitionDescriptor&  getDescriptor() const; 
    void setDescriptor(const MunitionDescriptor    &pX);

    Vector3Float& getLocationOfEntityCoordinates(); 
    const Vector3Float&  getLocationOfEntityCoordinates() const; 
    void setLocationOfEntityCoordinates(const Vector3Float    &pX);

    unsigned char getDetonationResult() const; 
    void setDetonationResult(unsigned char pX); 

    unsigned char getNumberOfVariableParameters() const; 

    unsigned short getPad() const; 
    void setPad(unsigned short pX); 

    std::vector<VariableParameter>& getVariableParameters(); 
    const std::vector<VariableParameter>& getVariableParameters() const; 
    void setVariableParameters(const std::vector<VariableParameter>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const DetonationPdu& rhs) const;
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
