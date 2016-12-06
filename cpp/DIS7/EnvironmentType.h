#ifndef ENVIRONMENTTYPE_H
#define ENVIRONMENTTYPE_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Description of environmental data in environmental process and gridded data PDUs. Section 6.2.32

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO EnvironmentType
{
protected:
  /** Kind of entity */
  unsigned char _entityKind; 

  /** Domain of entity (air, surface, subsurface, space, etc) */
  unsigned char _domain; 

  /** class of environmental entity */
  unsigned short _entityClass; 

  /** category of entity */
  unsigned char _category; 

  /** subcategory of entity */
  unsigned char _subcategory; 

  /** specific info based on subcategory field */
  unsigned char _specific; 

  unsigned char _extra; 


 public:
    EnvironmentType();
    virtual ~EnvironmentType();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getEntityKind() const; 
    void setEntityKind(unsigned char pX); 

    unsigned char getDomain() const; 
    void setDomain(unsigned char pX); 

    unsigned short getEntityClass() const; 
    void setEntityClass(unsigned short pX); 

    unsigned char getCategory() const; 
    void setCategory(unsigned char pX); 

    unsigned char getSubcategory() const; 
    void setSubcategory(unsigned char pX); 

    unsigned char getSpecific() const; 
    void setSpecific(unsigned char pX); 

    unsigned char getExtra() const; 
    void setExtra(unsigned char pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const EnvironmentType& rhs) const;
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
