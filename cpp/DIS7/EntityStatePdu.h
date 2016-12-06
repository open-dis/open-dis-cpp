#ifndef ENTITYSTATEPDU_H
#define ENTITYSTATEPDU_H

#include <DIS/EntityID.h>
#include <DIS/EntityType.h>
#include <DIS/EntityType.h>
#include <DIS/Vector3Float.h>
#include <DIS/Vector3Double.h>
#include <DIS/EulerAngles.h>
#include <DIS/DeadReckoningParameters.h>
#include <DIS/EntityMarking.h>
#include <DIS/VariableParameter.h>
#include <vector>
#include <DIS/EntityInformationFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Represents the postion and state of one entity in the world. Section 7.2.2. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO EntityStatePdu : public EntityInformationFamilyPdu
{
protected:
  /** Unique ID for an entity that is tied to this state information */
  EntityID _entityID; 

  /** What force this entity is affiliated with, eg red, blue, neutral, etc */
  unsigned char _forceId; 

  /** How many variable parameters are in the variable length list. In earlier versions of DIS these were known as articulation parameters */
  unsigned char _numberOfVariableParameters; 

  /** Describes the type of entity in the world */
  EntityType _entityType; 

  EntityType _alternativeEntityType; 

  /** Describes the speed of the entity in the world */
  Vector3Float _entityLinearVelocity; 

  /** describes the location of the entity in the world */
  Vector3Double _entityLocation; 

  /** describes the orientation of the entity, in euler angles */
  EulerAngles _entityOrientation; 

  /** a series of bit flags that are used to help draw the entity, such as smoking, on fire, etc. */
  unsigned int _entityAppearance; 

  /** parameters used for dead reckoning */
  DeadReckoningParameters _deadReckoningParameters; 

  /** characters that can be used for debugging, or to draw unique strings on the side of entities in the world */
  EntityMarking _marking; 

  /** a series of bit flags */
  unsigned int _capabilities; 

  /** variable length list of variable parameters. In earlier DIS versions this was articulation parameters. */
  std::vector<VariableParameter> _variableParameters; 


 public:
    EntityStatePdu();
    virtual ~EntityStatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getEntityID(); 
    const EntityID&  getEntityID() const; 
    void setEntityID(const EntityID    &pX);

    unsigned char getForceId() const; 
    void setForceId(unsigned char pX); 

    unsigned char getNumberOfVariableParameters() const; 

    EntityType& getEntityType(); 
    const EntityType&  getEntityType() const; 
    void setEntityType(const EntityType    &pX);

    EntityType& getAlternativeEntityType(); 
    const EntityType&  getAlternativeEntityType() const; 
    void setAlternativeEntityType(const EntityType    &pX);

    Vector3Float& getEntityLinearVelocity(); 
    const Vector3Float&  getEntityLinearVelocity() const; 
    void setEntityLinearVelocity(const Vector3Float    &pX);

    Vector3Double& getEntityLocation(); 
    const Vector3Double&  getEntityLocation() const; 
    void setEntityLocation(const Vector3Double    &pX);

    EulerAngles& getEntityOrientation(); 
    const EulerAngles&  getEntityOrientation() const; 
    void setEntityOrientation(const EulerAngles    &pX);

    unsigned int getEntityAppearance() const; 
    void setEntityAppearance(unsigned int pX); 

    DeadReckoningParameters& getDeadReckoningParameters(); 
    const DeadReckoningParameters&  getDeadReckoningParameters() const; 
    void setDeadReckoningParameters(const DeadReckoningParameters    &pX);

    EntityMarking& getMarking(); 
    const EntityMarking&  getMarking() const; 
    void setMarking(const EntityMarking    &pX);

    unsigned int getCapabilities() const; 
    void setCapabilities(unsigned int pX); 

    std::vector<VariableParameter>& getVariableParameters(); 
    const std::vector<VariableParameter>& getVariableParameters() const; 
    void setVariableParameters(const std::vector<VariableParameter>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const EntityStatePdu& rhs) const;
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
