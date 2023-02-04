#pragma once

#include <dis6/LayerHeader.h>
#include <dis6/BeamData.h>
#include <dis6/BeamData.h>
#include <dis6/FundamentalParameterDataIff.h>
#include <vector>
#include <dis6/IffAtcNavAidsLayer1Pdu.h>
#include <dis6/utils/DataStream.h>
#include <dis6/opendis6_export.h>


namespace DIS
{
// Section 5.3.7.4.2 When present, layer 2 should follow layer 1 and have the following fields. This requires manual cleanup.        the beamData attribute semantics are used in multiple ways. UNFINSISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class OPENDIS6_EXPORT IffAtcNavAidsLayer2Pdu : public IffAtcNavAidsLayer1Pdu
{
protected:
  /** layer header */
  LayerHeader _layerHeader; 

  /** beam data */
  BeamData _beamData; 

  /** Secondary operational data, 5.2.57 */
  BeamData _secondaryOperationalData; 

  /** variable length list of fundamental parameters. ^^^This is wrong */
  std::vector<FundamentalParameterDataIff> _fundamentalIffParameters; 


 public:
    IffAtcNavAidsLayer2Pdu();
    virtual ~IffAtcNavAidsLayer2Pdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    LayerHeader& getLayerHeader(); 
    const LayerHeader&  getLayerHeader() const; 
    void setLayerHeader(const LayerHeader    &pX);

    BeamData& getBeamData(); 
    const BeamData&  getBeamData() const; 
    void setBeamData(const BeamData    &pX);

    BeamData& getSecondaryOperationalData(); 
    const BeamData&  getSecondaryOperationalData() const; 
    void setSecondaryOperationalData(const BeamData    &pX);

    std::vector<FundamentalParameterDataIff>& getFundamentalIffParameters(); 
    const std::vector<FundamentalParameterDataIff>& getFundamentalIffParameters() const; 
    void setFundamentalIffParameters(const std::vector<FundamentalParameterDataIff>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const IffAtcNavAidsLayer2Pdu& rhs) const;
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
