#ifndef ATTACHEDPARTS_H
#define ATTACHEDPARTS_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Removable parts that may be attached to an entity.  Section 6.2.93.3

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO AttachedParts
{
protected:
  /** the identification of the Variable Parameter record. Enumeration from EBV */
  unsigned char _recordType; 

  /** 0 = attached, 1 = detached. See I.2.3.1 for state transition diagram */
  unsigned char _detachedIndicator; 

  /** the identification of the articulated part to which this articulation parameter is attached. This field shall be specified by a 16-bit unsigned integer. This field shall contain the value zero if the articulated part is attached directly to the entity. */
  unsigned short _partAttachedTo; 

  /** The location or station to which the part is attached */
  unsigned int _parameterType; 

  /** The definition of the 64 bits shall be determined based on the type of parameter specified in the Parameter Type field  */
  long _parameterValue; 


 public:
    AttachedParts();
    virtual ~AttachedParts();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getRecordType() const; 
    void setRecordType(unsigned char pX); 

    unsigned char getDetachedIndicator() const; 
    void setDetachedIndicator(unsigned char pX); 

    unsigned short getPartAttachedTo() const; 
    void setPartAttachedTo(unsigned short pX); 

    unsigned int getParameterType() const; 
    void setParameterType(unsigned int pX); 

    long getParameterValue() const; 
    void setParameterValue(long pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const AttachedParts& rhs) const;
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
