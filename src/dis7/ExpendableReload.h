#ifndef EXPENDABLERELOAD_H
#define EXPENDABLERELOAD_H

#include <DIS/EntityType.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// An entity's expendable (chaff, flares, etc) information. Section 6.2.37

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO ExpendableReload
{
protected:
  /** Type of expendable */
  EntityType _expendable; 

  unsigned int _station; 

  unsigned short _standardQuantity; 

  unsigned short _maximumQuantity; 

  unsigned int _standardQuantityReloadTime; 

  unsigned int _maximumQuantityReloadTime; 


 public:
    ExpendableReload();
    virtual ~ExpendableReload();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityType& getExpendable(); 
    const EntityType&  getExpendable() const; 
    void setExpendable(const EntityType    &pX);

    unsigned int getStation() const; 
    void setStation(unsigned int pX); 

    unsigned short getStandardQuantity() const; 
    void setStandardQuantity(unsigned short pX); 

    unsigned short getMaximumQuantity() const; 
    void setMaximumQuantity(unsigned short pX); 

    unsigned int getStandardQuantityReloadTime() const; 
    void setStandardQuantityReloadTime(unsigned int pX); 

    unsigned int getMaximumQuantityReloadTime() const; 
    void setMaximumQuantityReloadTime(unsigned int pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const ExpendableReload& rhs) const;
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
