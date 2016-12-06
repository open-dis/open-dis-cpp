#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <DIS/EntityID.h>
#include <DIS/Vector3Double.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// An entity's associations with other entities and/or locations. For each association, this record shall specify the type of the association, the associated entity's EntityID and/or the associated location's world coordinates. This record may be used (optionally) in a transfer transaction to send internal state data from the divesting simulation to the acquiring simulation (see 5.9.4). This record may also be used for other purposes. Section 6.2.10

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO Association
{
protected:
  unsigned char _associationType; 

  unsigned char _padding4; 

  /** identity of associated entity. If none, NO_SPECIFIC_ENTITY */
  EntityID _associatedEntityID; 

  /** location, in world coordinates */
  Vector3Double _associatedLocation; 


 public:
    Association();
    virtual ~Association();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getAssociationType() const; 
    void setAssociationType(unsigned char pX); 

    unsigned char getPadding4() const; 
    void setPadding4(unsigned char pX); 

    EntityID& getAssociatedEntityID(); 
    const EntityID&  getAssociatedEntityID() const; 
    void setAssociatedEntityID(const EntityID    &pX);

    Vector3Double& getAssociatedLocation(); 
    const Vector3Double&  getAssociatedLocation() const; 
    void setAssociatedLocation(const Vector3Double    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const Association& rhs) const;
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
