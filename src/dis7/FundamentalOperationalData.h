#ifndef FUNDAMENTALOPERATIONALDATA_H
#define FUNDAMENTALOPERATIONALDATA_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Basic operational data for IFF. Section 6.2.40.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO FundamentalOperationalData
{
protected:
  /** system status */
  unsigned char _systemStatus; 

  /** data field 1 */
  unsigned char _dataField1; 

  /** eight boolean fields */
  unsigned char _informationLayers; 

  /** enumeration */
  unsigned char _dataField2; 

  /** parameter, enumeration */
  unsigned short _parameter1; 

  /** parameter, enumeration */
  unsigned short _parameter2; 

  /** parameter, enumeration */
  unsigned short _parameter3; 

  /** parameter, enumeration */
  unsigned short _parameter4; 

  /** parameter, enumeration */
  unsigned short _parameter5; 

  /** parameter, enumeration */
  unsigned short _parameter6; 


 public:
    FundamentalOperationalData();
    virtual ~FundamentalOperationalData();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getSystemStatus() const; 
    void setSystemStatus(unsigned char pX); 

    unsigned char getDataField1() const; 
    void setDataField1(unsigned char pX); 

    unsigned char getInformationLayers() const; 
    void setInformationLayers(unsigned char pX); 

    unsigned char getDataField2() const; 
    void setDataField2(unsigned char pX); 

    unsigned short getParameter1() const; 
    void setParameter1(unsigned short pX); 

    unsigned short getParameter2() const; 
    void setParameter2(unsigned short pX); 

    unsigned short getParameter3() const; 
    void setParameter3(unsigned short pX); 

    unsigned short getParameter4() const; 
    void setParameter4(unsigned short pX); 

    unsigned short getParameter5() const; 
    void setParameter5(unsigned short pX); 

    unsigned short getParameter6() const; 
    void setParameter6(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const FundamentalOperationalData& rhs) const;
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
