#pragma once

#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Used in UaPdu

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO AcousticBeamFundamentalParameter
{
protected:
  /** parameter index */
  unsigned short _activeEmissionParameterIndex; 

  /** scan pattern */
  unsigned short _scanPattern; 

  /** beam center azimuth */
  float _beamCenterAzimuth; 

  /** azimuthal beamwidth */
  float _azimuthalBeamwidth; 

  /** beam center */
  float _beamCenterDE; 

  /** DE beamwidth (vertical beamwidth) */
  float _deBeamwidth; 


 public:
    AcousticBeamFundamentalParameter();
    virtual ~AcousticBeamFundamentalParameter();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned short getActiveEmissionParameterIndex() const; 
    void setActiveEmissionParameterIndex(unsigned short pX); 

    unsigned short getScanPattern() const; 
    void setScanPattern(unsigned short pX); 

    float getBeamCenterAzimuth() const; 
    void setBeamCenterAzimuth(float pX); 

    float getAzimuthalBeamwidth() const; 
    void setAzimuthalBeamwidth(float pX); 

    float getBeamCenterDE() const; 
    void setBeamCenterDE(float pX); 

    float getDeBeamwidth() const; 
    void setDeBeamwidth(float pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const AcousticBeamFundamentalParameter& rhs) const;
};
}

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
