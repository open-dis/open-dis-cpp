#pragma once

#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Each entity in a given DIS simulation application shall be given an entity identifier number unique to all  other entities in that application. This identifier number is valid for the duration of the exercise; however,  entity identifier numbers may be reused when all possible numbers have been exhausted. No entity shall  have an entity identifier number of NO_ENTITY, ALL_ENTITIES, or RQST_ASSIGN_ID. The entity iden-  tifier number need not be registered or retained for future exercises. The entity identifier number shall be  specified by a 16-bit unsigned integer.  An entity identifier number equal to zero with valid site and application identification shall address a  simulation application. An entity identifier number equal to ALL_ENTITIES shall mean all entities within  the specified site and application. An entity identifier number equal to RQST_ASSIGN_ID allows the  receiver of the create entity to define the entity identifier number of the new entity.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO EntityID
{
protected:
  /** The site ID */
  unsigned short _site; 

  /** The application ID */
  unsigned short _application; 

  /** the entity ID */
  unsigned short _entity; 


 public:
    EntityID();
    virtual ~EntityID();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned short getSite() const; 
    void setSite(unsigned short pX); 

    unsigned short getApplication() const; 
    void setApplication(unsigned short pX); 

    unsigned short getEntity() const; 
    void setEntity(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const EntityID& rhs) const;
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
