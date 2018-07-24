#ifndef EXPLOSIONDESCRIPTOR_H
#define EXPLOSIONDESCRIPTOR_H

#include <DIS/EntityType.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Explosion of a non-munition. Section 6.2.20.3

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO ExplosionDescriptor
{
protected:
  /** Type of the object that exploded. See 6.2.30 */
  EntityType _explodingObject; 

  /** Material that exploded. Can be grain dust, tnt, gasoline, etc. */
  unsigned short _explosiveMaterial; 

  /** padding */
  unsigned short _padding; 

  /** Force of explosion, in equivalent KG of TNT */
  float _explosiveForce; 


 public:
    ExplosionDescriptor();
    virtual ~ExplosionDescriptor();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityType& getExplodingObject(); 
    const EntityType&  getExplodingObject() const; 
    void setExplodingObject(const EntityType    &pX);

    unsigned short getExplosiveMaterial() const; 
    void setExplosiveMaterial(unsigned short pX); 

    unsigned short getPadding() const; 
    void setPadding(unsigned short pX); 

    float getExplosiveForce() const; 
    void setExplosiveForce(float pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const ExplosionDescriptor& rhs) const;
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
