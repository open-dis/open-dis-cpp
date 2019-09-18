#ifndef ELECTRONICEMISSIONSPDU_H
#define ELECTRONICEMISSIONSPDU_H

#include <dis7/EntityID.h>
#include <dis7/EventIdentifier.h>
#include <dis7/EmitterSystem.h>
#include <dis7/Vector3Float.h>
#include <dis7/Vector3Float.h>
#include <vector>
#include <dis7/DistributedEmissionsFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis7/msLibMacro.h>


namespace DIS
{
// Section 5.3.7.1. Information about active electronic warfare (EW) emissions and active EW countermeasures shall be communicated using an Electromagnetic Emission PDU. NOT COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO ElectronicEmissionsPdu : public DistributedEmissionsFamilyPdu
{
protected:
  /** ID of the entity emitting */
  EntityID _emittingEntityID; 

  /** ID of event */
  EventIdentifier _eventID; 

  /** This field shall be used to indicate if the data in the PDU represents a state update or just data that has changed since issuance of the last Electromagnetic Emission PDU [relative to the identified entity and emission system(s)]. */
  uint8_t _stateUpdateIndicator; 

  /** This field shall specify the number of emission systems being described in the current PDU. */
  uint8_t _numberOfSystems; 

  /** padding */
  unsigned short _paddingForEmissionsPdu; 

  /**  this field shall specify the length of this emitter system's data in 32-bit words. */
  uint8_t _systemDataLength; 

  /** the number of beams being described in the current PDU for the emitter system being described.  */
  uint8_t _numberOfBeams; 

  /**  information about a particular emitter system and shall be represented by an Emitter System record (see 6.2.23). */
  EmitterSystem _emitterSystem; 

  /** the location of the antenna beam source with respect to the emitting entity's coordinate system. This location shall be the origin of the emitter coordinate system that shall have the same orientation as the entity coordinate system. This field shall be represented by an Entity Coordinate Vector record see 6.2.95  */
  Vector3Float _location; 

  /** Electronic emmissions systems THIS IS WRONG. It has the WRONG class type and will cause problems in any marshalling. */
  std::vector<Vector3Float> _systems; 


 public:
    ElectronicEmissionsPdu();
    virtual ~ElectronicEmissionsPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getEmittingEntityID(); 
    const EntityID&  getEmittingEntityID() const; 
    void setEmittingEntityID(const EntityID    &pX);

    EventIdentifier& getEventID(); 
    const EventIdentifier&  getEventID() const; 
    void setEventID(const EventIdentifier    &pX);

    uint8_t getStateUpdateIndicator() const; 
    void setStateUpdateIndicator(uint8_t pX); 

    uint8_t getNumberOfSystems() const; 

    unsigned short getPaddingForEmissionsPdu() const; 
    void setPaddingForEmissionsPdu(unsigned short pX); 

    uint8_t getSystemDataLength() const; 
    void setSystemDataLength(uint8_t pX); 

    uint8_t getNumberOfBeams() const; 
    void setNumberOfBeams(uint8_t pX); 

    EmitterSystem& getEmitterSystem(); 
    const EmitterSystem&  getEmitterSystem() const; 
    void setEmitterSystem(const EmitterSystem    &pX);

    Vector3Float& getLocation(); 
    const Vector3Float&  getLocation() const; 
    void setLocation(const Vector3Float    &pX);

    std::vector<Vector3Float>& getSystems(); 
    const std::vector<Vector3Float>& getSystems() const; 
    void setSystems(const std::vector<Vector3Float>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const ElectronicEmissionsPdu& rhs) const;
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
