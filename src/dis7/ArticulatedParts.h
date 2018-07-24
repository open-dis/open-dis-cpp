#ifndef ARTICULATEDPARTS_H
#define ARTICULATEDPARTS_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
//  articulated parts for movable parts and a combination of moveable/attached parts of an entity. Section 6.2.93.2

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO ArticulatedParts
{
protected:
  /** the identification of the Variable Parameter record. Enumeration from EBV */
  unsigned char _recordType; 

  /** indicate the change of any parameter for any articulated part. Starts at zero, incremented for each change  */
  unsigned char _changeIndicator; 

  /** the identification of the articulated part to which this articulation parameter is attached. This field shall be specified by a 16-bit unsigned integer. This field shall contain the value zero if the articulated part is attached directly to the entity. */
  unsigned short _partAttachedTo; 

  /** the type of parameter represented, 32 bit enumeration */
  unsigned int _parameterType; 

  /** The definition of the 64 bits shall be determined based on the type of parameter specified in the Parameter Type field  */
  long _parameterValue; 


 public:
    ArticulatedParts();
    virtual ~ArticulatedParts();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getRecordType() const; 
    void setRecordType(unsigned char pX); 

    unsigned char getChangeIndicator() const; 
    void setChangeIndicator(unsigned char pX); 

    unsigned short getPartAttachedTo() const; 
    void setPartAttachedTo(unsigned short pX); 

    unsigned int getParameterType() const; 
    void setParameterType(unsigned int pX); 

    long getParameterValue() const; 
    void setParameterValue(long pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const ArticulatedParts& rhs) const;
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
