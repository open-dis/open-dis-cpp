#pragma once

#include <dis7/EEFundamentalParameterData.h>
#include <dis7/TrackJamData.h>
#include <dis7/JammingTechnique.h>
#include <dis7/BeamData.h>
#include <vector>
#include <utils/DataStream.h>
#include <dis7/msLibMacro.h>


namespace DIS
{
// Description of one electronic emission beam

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO ElectromagneticEmissionBeamData
{
protected:
  /** This field shall specify the length of this beams data in 32 bit words */
  unsigned char _beamDataLength; 

  /** This field shall specify a unique emitter database number assigned to differentiate between otherwise similar or identical emitter beams within an emitter system. */
  unsigned char _beamIDNumber; 

  /** This field shall specify a Beam Parameter Index number that shall be used by receiving entities in conjunction with the Emitter Name field to provide a pointer to the stored database parameters required to regenerate the beam.  */
  unsigned short _beamParameterIndex; 

  /** Fundamental parameter data such as frequency range, erp, pulse width, etc. */
  EEFundamentalParameterData _fundamentalParameterData;

  /** Beam data contains Azimuth, Elevation, Sweep variables */
  BeamData _beamData;

  /** beam function of a particular beam */
  unsigned char _beamFunction; 

  /** Number of track/jam targets */
  unsigned char _numberOfTrackJamTargets; 

  /** wheher or not the receiving simulation apps can assume all the targets in the scan pattern are being tracked/jammed */
  unsigned char _highDensityTrackJam; 

  unsigned char _beamStatus;

  /** Contains Jamming Mode Sequence */
  JammingTechnique _jammingTechnique;

  /** variable length list of track/jam targets */
  std::vector<TrackJamData> _trackJamTargets; 

 public:
     ElectromagneticEmissionBeamData();
    virtual ~ElectromagneticEmissionBeamData();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getBeamDataLength() const; 
    void setBeamDataLength(unsigned char pX); 

    unsigned char getBeamIDNumber() const; 
    void setBeamIDNumber(unsigned char pX); 

    unsigned short getBeamParameterIndex() const; 
    void setBeamParameterIndex(unsigned short pX); 

    EEFundamentalParameterData& getFundamentalParameterData(); 
    const EEFundamentalParameterData&  getFundamentalParameterData() const; 
    void setFundamentalParameterData(const EEFundamentalParameterData    &pX);

	BeamData& getBeamData();
	const BeamData&  getBeamData() const;
	void setBeamData(const BeamData    &pX);

    unsigned char getBeamFunction() const; 
    void setBeamFunction(unsigned char pX); 

    unsigned char getNumberOfTrackJamTargets() const; 

    unsigned char getHighDensityTrackJam() const; 
    void setHighDensityTrackJam(unsigned char pX); 

    unsigned char getBeamStatus() const; 
    void setBeamStatus(unsigned char pX); 

    JammingTechnique& getJammingTechnique();
    const JammingTechnique& getJammingTechnique() const;
    void setJammingTechnique(const JammingTechnique& pX);

    std::vector<TrackJamData>& getTrackJamTargets(); 
    const std::vector<TrackJamData>& getTrackJamTargets() const; 
    void setTrackJamTargets(const std::vector<TrackJamData>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const ElectromagneticEmissionBeamData& rhs) const;
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
