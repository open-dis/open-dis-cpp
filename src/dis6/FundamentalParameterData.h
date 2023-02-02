#pragma once

#include <dis6/utils/DataStream.h>
#include <dis6/opendis6_export.h>


namespace DIS
{
// Section 5.2.22. Contains electromagnetic emmision regineratin parameters that are        variable throughout a scenario dependent on the actions of the participants in the simulation. Also provides basic parametric data that may be used to support low-fidelity simulations.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class OPENDIS6_EXPORT FundamentalParameterData
{
protected:
  /** center frequency of the emission in hertz. */
  float _frequency; 

  /** Bandwidth of the frequencies corresponding to the fequency field. */
  float _frequencyRange; 

  /** Effective radiated power for the emission in DdBm. For a      radar noise jammer, indicates the peak of the transmitted power. */
  float _effectiveRadiatedPower; 

  /** Average repetition frequency of the emission in hertz. */
  float _pulseRepetitionFrequency; 

  /** Average pulse width  of the emission in microseconds. */
  float _pulseWidth; 

  /** Specifies the beam azimuth an elevation centers and corresponding half-angles     to describe the scan volume */
  float _beamAzimuthCenter; 

  /** Specifies the beam azimuth sweep to determine scan volume */
  float _beamAzimuthSweep; 

  /** Specifies the beam elevation center to determine scan volume */
  float _beamElevationCenter; 

  /** Specifies the beam elevation sweep to determine scan volume */
  float _beamElevationSweep; 

  /** allows receiver to synchronize its regenerated scan pattern to     that of the emmitter. Specifies the percentage of time a scan is through its pattern from its origion. */
  float _beamSweepSync; 


 public:
    FundamentalParameterData();
    virtual ~FundamentalParameterData();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    float getFrequency() const; 
    void setFrequency(float pX); 

    float getFrequencyRange() const; 
    void setFrequencyRange(float pX); 

    float getEffectiveRadiatedPower() const; 
    void setEffectiveRadiatedPower(float pX); 

    float getPulseRepetitionFrequency() const; 
    void setPulseRepetitionFrequency(float pX); 

    float getPulseWidth() const; 
    void setPulseWidth(float pX); 

    float getBeamAzimuthCenter() const; 
    void setBeamAzimuthCenter(float pX); 

    float getBeamAzimuthSweep() const; 
    void setBeamAzimuthSweep(float pX); 

    float getBeamElevationCenter() const; 
    void setBeamElevationCenter(float pX); 

    float getBeamElevationSweep() const; 
    void setBeamElevationSweep(float pX); 

    float getBeamSweepSync() const; 
    void setBeamSweepSync(float pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const FundamentalParameterData& rhs) const;
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
