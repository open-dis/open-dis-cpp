#ifndef MODULATIONTYPE_H
#define MODULATIONTYPE_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Information about the type of modulation used for radio transmission. 6.2.59 

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO ModulationType
{
protected:
  /** This field shall indicate the spread spectrum technique or combination of spread spectrum techniques in use. Bt field. */
  unsigned short _spreadSpectrum; 

  /** the major classification of the modulation type.  */
  unsigned short _majorModulation; 

  /** provide certain detailed information depending upon the major modulation type */
  unsigned short _detail; 

  /** the radio system associated with this Transmitter PDU and shall be used as the basis to interpret other fields whose values depend on a specific radio system. */
  unsigned short _radioSystem; 


 public:
    ModulationType();
    virtual ~ModulationType();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned short getSpreadSpectrum() const; 
    void setSpreadSpectrum(unsigned short pX); 

    unsigned short getMajorModulation() const; 
    void setMajorModulation(unsigned short pX); 

    unsigned short getDetail() const; 
    void setDetail(unsigned short pX); 

    unsigned short getRadioSystem() const; 
    void setRadioSystem(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const ModulationType& rhs) const;
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
