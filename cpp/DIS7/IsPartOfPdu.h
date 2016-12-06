#ifndef ISPARTOFPDU_H
#define ISPARTOFPDU_H

#include <DIS/EntityID.h>
#include <DIS/EntityID.h>
#include <DIS/Relationship.h>
#include <DIS/Vector3Float.h>
#include <DIS/NamedLocationIdentification.h>
#include <DIS/EntityType.h>
#include <DIS/EntityManagementFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
//  The joining of two or more simulation entities is communicated by this PDU. Section 7.8.5 COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO IsPartOfPdu : public EntityManagementFamilyPdu
{
protected:
  /** ID of entity originating PDU */
  EntityID _orginatingEntityID; 

  /** ID of entity receiving PDU */
  EntityID _receivingEntityID; 

  /** relationship of joined parts */
  Relationship _relationship; 

  /** location of part; centroid of part in host's coordinate system. x=range, y=bearing, z=0 */
  Vector3Float _partLocation; 

  /** named location */
  NamedLocationIdentification _namedLocationID; 

  /** entity type */
  EntityType _partEntityType; 


 public:
    IsPartOfPdu();
    virtual ~IsPartOfPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getOrginatingEntityID(); 
    const EntityID&  getOrginatingEntityID() const; 
    void setOrginatingEntityID(const EntityID    &pX);

    EntityID& getReceivingEntityID(); 
    const EntityID&  getReceivingEntityID() const; 
    void setReceivingEntityID(const EntityID    &pX);

    Relationship& getRelationship(); 
    const Relationship&  getRelationship() const; 
    void setRelationship(const Relationship    &pX);

    Vector3Float& getPartLocation(); 
    const Vector3Float&  getPartLocation() const; 
    void setPartLocation(const Vector3Float    &pX);

    NamedLocationIdentification& getNamedLocationID(); 
    const NamedLocationIdentification&  getNamedLocationID() const; 
    void setNamedLocationID(const NamedLocationIdentification    &pX);

    EntityType& getPartEntityType(); 
    const EntityType&  getPartEntityType() const; 
    void setPartEntityType(const EntityType    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const IsPartOfPdu& rhs) const;
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
