#ifndef ENTITYASSOCIATION_H
#define ENTITYASSOCIATION_H

#include <dis7/EntityID.h>
#include <utils/DataStream.h>
#include <dis7/msLibMacro.h>


namespace DIS
{
// Association or disassociation of two entities.  Section 6.2.93.4

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO EntityAssociation
{
protected:
  /** the identification of the Variable Parameter record. Enumeration from EBV */
  uint8_t _recordType; 

  /** Indicates if this VP has changed since last issuance */
  uint8_t _changeIndicator; 

  /** Indicates association status between two entities; 8 bit enum */
  uint8_t _associationStatus; 

  /** Type of association; 8 bit enum */
  uint8_t _associationType; 

  /** Object ID of entity associated with this entity */
  EntityID _entityID; 

  /** Station location on one's own entity. EBV doc. */
  unsigned short _owsSttionLocation; 

  /** Type of physical connection. EBV doc */
  unsigned short _physicalConnectionType; 

  /** Type of member the entity is within th egroup */
  uint8_t _groupMemberType; 

  /** Group if any to which the entity belongs */
  unsigned short _groupNumber; 


 public:
    EntityAssociation();
    virtual ~EntityAssociation();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    uint8_t getRecordType() const; 
    void setRecordType(uint8_t pX); 

    uint8_t getChangeIndicator() const; 
    void setChangeIndicator(uint8_t pX); 

    uint8_t getAssociationStatus() const; 
    void setAssociationStatus(uint8_t pX); 

    uint8_t getAssociationType() const; 
    void setAssociationType(uint8_t pX); 

    EntityID& getEntityID(); 
    const EntityID&  getEntityID() const; 
    void setEntityID(const EntityID    &pX);

    unsigned short getOwsSttionLocation() const; 
    void setOwsSttionLocation(unsigned short pX); 

    unsigned short getPhysicalConnectionType() const; 
    void setPhysicalConnectionType(unsigned short pX); 

    uint8_t getGroupMemberType() const; 
    void setGroupMemberType(uint8_t pX); 

    unsigned short getGroupNumber() const; 
    void setGroupNumber(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const EntityAssociation& rhs) const;
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
