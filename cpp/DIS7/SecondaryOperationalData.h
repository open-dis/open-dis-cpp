#ifndef SECONDARYOPERATIONALDATA_H
#define SECONDARYOPERATIONALDATA_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Additional operational data for an IFF emitting system and the number of IFF Fundamental Parameter Data records Section 6.2.76.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO SecondaryOperationalData
{
protected:
  /** additional operational characteristics of the IFF emitting system. Each 8-bit field will vary depending on the system type. */
  unsigned char _operationalData1; 

  /** additional operational characteristics of the IFF emitting system. Each 8-bit field will vary depending on the system type. */
  unsigned char _operationalData2; 

  /** the number of IFF Fundamental Parameter Data records that follow */
  unsigned short _numberOfIFFFundamentalParameterRecords; 


 public:
    SecondaryOperationalData();
    virtual ~SecondaryOperationalData();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getOperationalData1() const; 
    void setOperationalData1(unsigned char pX); 

    unsigned char getOperationalData2() const; 
    void setOperationalData2(unsigned char pX); 

    unsigned short getNumberOfIFFFundamentalParameterRecords() const; 
    void setNumberOfIFFFundamentalParameterRecords(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const SecondaryOperationalData& rhs) const;
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
