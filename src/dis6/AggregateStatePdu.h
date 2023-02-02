#pragma once

#include <dis6/EntityID.h>
#include <dis6/EntityType.h>
#include <dis6/AggregateMarking.h>
#include <dis6/Vector3Float.h>
#include <dis6/Orientation.h>
#include <dis6/Vector3Double.h>
#include <dis6/Vector3Float.h>
#include <dis6/AggregateID.h>
#include <dis6/EntityID.h>
#include <dis6/EntityType.h>
#include <dis6/EntityType.h>
#include <dis6/VariableDatum.h>
#include <vector>
#include <dis6/EntityManagementFamilyPdu.h>
#include <dis6/utils/DataStream.h>
#include <dis6/opendis6_export.h>


namespace DIS
{
// Section 5.3.9.1 informationa bout aggregating entities anc communicating information about the aggregated entities.        requires manual intervention to fix the padding between entityID lists and silent aggregate sysem lists--this padding        is dependent on how many entityIDs there are, and needs to be on a 32 bit word boundary. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class OPENDIS6_EXPORT AggregateStatePdu : public EntityManagementFamilyPdu
{
protected:
  /** ID of aggregated entities */
  EntityID _aggregateID; 

  /** force ID */
  unsigned char _forceID; 

  /** state of aggregate */
  unsigned char _aggregateState; 

  /** entity type of the aggregated entities */
  EntityType _aggregateType; 

  /** formation of aggregated entities */
  unsigned int _formation; 

  /** marking for aggregate; first char is charset type, rest is char data */
  AggregateMarking _aggregateMarking; 

  /** dimensions of bounding box for the aggregated entities, origin at the center of mass */
  Vector3Float _dimensions; 

  /** orientation of the bounding box */
  Orientation _orientation; 

  /** center of mass of the aggregation */
  Vector3Double _centerOfMass; 

  /** velocity of aggregation */
  Vector3Float _velocity; 

  /** number of aggregates */
  unsigned short _numberOfDisAggregates; 

  /** number of entities */
  unsigned short _numberOfDisEntities; 

  /** number of silent aggregate types */
  unsigned short _numberOfSilentAggregateTypes; 

  /** number of silent entity types */
  unsigned short _numberOfSilentEntityTypes; 

  /** aggregates  list */
  std::vector<AggregateID> _aggregateIDList; 

  /** entity ID list */
  std::vector<EntityID> _entityIDList; 

  /** ^^^padding to put the start of the next list on a 32 bit boundary. This needs to be fixed */
  unsigned char _pad2; 

  /** silent entity types */
  std::vector<EntityType> _silentAggregateSystemList; 

  /** silent entity types */
  std::vector<EntityType> _silentEntitySystemList; 

  /** number of variable datum records */
  unsigned int _numberOfVariableDatumRecords; 

  /** variableDatums */
  std::vector<VariableDatum> _variableDatumList; 


 public:
    AggregateStatePdu();
    virtual ~AggregateStatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getAggregateID(); 
    const EntityID&  getAggregateID() const; 
    void setAggregateID(const EntityID    &pX);

    unsigned char getForceID() const; 
    void setForceID(unsigned char pX); 

    unsigned char getAggregateState() const; 
    void setAggregateState(unsigned char pX); 

    EntityType& getAggregateType(); 
    const EntityType&  getAggregateType() const; 
    void setAggregateType(const EntityType    &pX);

    unsigned int getFormation() const; 
    void setFormation(unsigned int pX); 

    AggregateMarking& getAggregateMarking(); 
    const AggregateMarking&  getAggregateMarking() const; 
    void setAggregateMarking(const AggregateMarking    &pX);

    Vector3Float& getDimensions(); 
    const Vector3Float&  getDimensions() const; 
    void setDimensions(const Vector3Float    &pX);

    Orientation& getOrientation(); 
    const Orientation&  getOrientation() const; 
    void setOrientation(const Orientation    &pX);

    Vector3Double& getCenterOfMass(); 
    const Vector3Double&  getCenterOfMass() const; 
    void setCenterOfMass(const Vector3Double    &pX);

    Vector3Float& getVelocity(); 
    const Vector3Float&  getVelocity() const; 
    void setVelocity(const Vector3Float    &pX);

    unsigned short getNumberOfDisAggregates() const; 

    unsigned short getNumberOfDisEntities() const; 

    unsigned short getNumberOfSilentAggregateTypes() const; 

    unsigned short getNumberOfSilentEntityTypes() const; 

    std::vector<AggregateID>& getAggregateIDList(); 
    const std::vector<AggregateID>& getAggregateIDList() const; 
    void setAggregateIDList(const std::vector<AggregateID>&    pX);

    std::vector<EntityID>& getEntityIDList(); 
    const std::vector<EntityID>& getEntityIDList() const; 
    void setEntityIDList(const std::vector<EntityID>&    pX);

    unsigned char getPad2() const; 
    void setPad2(unsigned char pX); 

    std::vector<EntityType>& getSilentAggregateSystemList(); 
    const std::vector<EntityType>& getSilentAggregateSystemList() const; 
    void setSilentAggregateSystemList(const std::vector<EntityType>&    pX);

    std::vector<EntityType>& getSilentEntitySystemList(); 
    const std::vector<EntityType>& getSilentEntitySystemList() const; 
    void setSilentEntitySystemList(const std::vector<EntityType>&    pX);

    unsigned int getNumberOfVariableDatumRecords() const; 

    std::vector<VariableDatum>& getVariableDatumList(); 
    const std::vector<VariableDatum>& getVariableDatumList() const; 
    void setVariableDatumList(const std::vector<VariableDatum>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const AggregateStatePdu& rhs) const;
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
