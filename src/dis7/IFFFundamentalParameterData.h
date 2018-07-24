#ifndef IFFFUNDAMENTALPARAMETERDATA_H
#define IFFFUNDAMENTALPARAMETERDATA_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Fundamental IFF atc data. Section 6.2.45

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO IFFFundamentalParameterData
{
protected:
  /** ERP */
  float _erp; 

  /** frequency */
  float _frequency; 

  /** pgrf */
  float _pgrf; 

  /** Pulse width */
  float _pulseWidth; 

  /** Burst length */
  unsigned int _burstLength; 

  /** Applicable modes enumeration */
  unsigned char _applicableModes; 

  /** System-specific data */
  unsigned char _systemSpecificData[3]; 


 public:
    IFFFundamentalParameterData();
    virtual ~IFFFundamentalParameterData();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    float getErp() const; 
    void setErp(float pX); 

    float getFrequency() const; 
    void setFrequency(float pX); 

    float getPgrf() const; 
    void setPgrf(float pX); 

    float getPulseWidth() const; 
    void setPulseWidth(float pX); 

    unsigned int getBurstLength() const; 
    void setBurstLength(unsigned int pX); 

    unsigned char getApplicableModes() const; 
    void setApplicableModes(unsigned char pX); 

    unsigned char*  getSystemSpecificData(); 
    const unsigned char*  getSystemSpecificData() const; 
    void setSystemSpecificData( const unsigned char*    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const IFFFundamentalParameterData& rhs) const;
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
