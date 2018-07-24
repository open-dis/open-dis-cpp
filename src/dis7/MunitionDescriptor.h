#ifndef MUNITIONDESCRIPTOR_H
#define MUNITIONDESCRIPTOR_H

#include <DIS/EntityType.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Represents the firing or detonation of a munition. Section 6.2.20.2

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO MunitionDescriptor
{
protected:
  /** What munition was used in the burst */
  EntityType _munitionType; 

  /** type of warhead */
  unsigned short _warhead; 

  /** type of fuse used */
  unsigned short _fuse; 

  /** how many of the munition were fired */
  unsigned short _quantity; 

  /** rate at which the munition was fired */
  unsigned short _rate; 


 public:
    MunitionDescriptor();
    virtual ~MunitionDescriptor();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityType& getMunitionType(); 
    const EntityType&  getMunitionType() const; 
    void setMunitionType(const EntityType    &pX);

    unsigned short getWarhead() const; 
    void setWarhead(unsigned short pX); 

    unsigned short getFuse() const; 
    void setFuse(unsigned short pX); 

    unsigned short getQuantity() const; 
    void setQuantity(unsigned short pX); 

    unsigned short getRate() const; 
    void setRate(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const MunitionDescriptor& rhs) const;
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
