#ifndef SEESPDU_H
#define SEESPDU_H

#include <DIS/EntityID.h>
#include <DIS/PropulsionSystemData.h>
#include <DIS/VectoringNozzleSystem.h>
#include <vector>
#include <DIS/DistributedEmissionsFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
//  SEES PDU, supplemental emissions entity state information. Section 7.6.6 COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO SeesPdu : public DistributedEmissionsFamilyPdu
{
protected:
  /** Originating entity ID */
  EntityID _orginatingEntityID; 

  /** IR Signature representation index */
  unsigned short _infraredSignatureRepresentationIndex; 

  /** acoustic Signature representation index */
  unsigned short _acousticSignatureRepresentationIndex; 

  /** radar cross section representation index */
  unsigned short _radarCrossSectionSignatureRepresentationIndex; 

  /** how many propulsion systems */
  unsigned short _numberOfPropulsionSystems; 

  /** how many vectoring nozzle systems */
  unsigned short _numberOfVectoringNozzleSystems; 

  /** variable length list of propulsion system data */
  std::vector<PropulsionSystemData> _propulsionSystemData; 

  /** variable length list of vectoring system data */
  std::vector<VectoringNozzleSystem> _vectoringSystemData; 


 public:
    SeesPdu();
    virtual ~SeesPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getOrginatingEntityID(); 
    const EntityID&  getOrginatingEntityID() const; 
    void setOrginatingEntityID(const EntityID    &pX);

    unsigned short getInfraredSignatureRepresentationIndex() const; 
    void setInfraredSignatureRepresentationIndex(unsigned short pX); 

    unsigned short getAcousticSignatureRepresentationIndex() const; 
    void setAcousticSignatureRepresentationIndex(unsigned short pX); 

    unsigned short getRadarCrossSectionSignatureRepresentationIndex() const; 
    void setRadarCrossSectionSignatureRepresentationIndex(unsigned short pX); 

    unsigned short getNumberOfPropulsionSystems() const; 

    unsigned short getNumberOfVectoringNozzleSystems() const; 

    std::vector<PropulsionSystemData>& getPropulsionSystemData(); 
    const std::vector<PropulsionSystemData>& getPropulsionSystemData() const; 
    void setPropulsionSystemData(const std::vector<PropulsionSystemData>&    pX);

    std::vector<VectoringNozzleSystem>& getVectoringSystemData(); 
    const std::vector<VectoringNozzleSystem>& getVectoringSystemData() const; 
    void setVectoringSystemData(const std::vector<VectoringNozzleSystem>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const SeesPdu& rhs) const;
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
