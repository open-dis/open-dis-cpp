#pragma once

#include <vector>

#include "dis6/DistributedEmissionsFamilyPdu.h"
#include "dis6/EntityID.h"
#include "dis6/PropulsionSystemData.h"
#include "dis6/VectoringNozzleSystemData.h"
#include "dis6/opendis6_export.h"
#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.3.7.5. SEES PDU, supplemental emissions entity state information.
// COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS6_EXPORT SeesPdu : public DistributedEmissionsFamilyPdu {
 protected:
  /** Originating entity ID */
  EntityID _orginatingEntityID;

  /** IR Signature representation index */
  uint16_t _infraredSignatureRepresentationIndex;

  /** acoustic Signature representation index */
  uint16_t _acousticSignatureRepresentationIndex;

  /** radar cross section representation index */
  uint16_t _radarCrossSectionSignatureRepresentationIndex;

  /** how many propulsion systems */
  uint16_t _numberOfPropulsionSystems;

  /** how many vectoring nozzle systems */
  uint16_t _numberOfVectoringNozzleSystems;

  /** variable length list of propulsion system data */
  std::vector<PropulsionSystemData> _propulsionSystemData;

  /** variable length list of vectoring system data */
  std::vector<VectoringNozzleSystemData> _vectoringSystemData;

 public:
  SeesPdu();
  virtual ~SeesPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getOrginatingEntityID();
  const EntityID& getOrginatingEntityID() const;
  void setOrginatingEntityID(const EntityID& pX);

  uint16_t getInfraredSignatureRepresentationIndex() const;
  void setInfraredSignatureRepresentationIndex(uint16_t pX);

  uint16_t getAcousticSignatureRepresentationIndex() const;
  void setAcousticSignatureRepresentationIndex(uint16_t pX);

  uint16_t getRadarCrossSectionSignatureRepresentationIndex() const;
  void setRadarCrossSectionSignatureRepresentationIndex(uint16_t pX);

  uint16_t getNumberOfPropulsionSystems() const;

  uint16_t getNumberOfVectoringNozzleSystems() const;

  std::vector<PropulsionSystemData>& getPropulsionSystemData();
  const std::vector<PropulsionSystemData>& getPropulsionSystemData() const;
  void setPropulsionSystemData(const std::vector<PropulsionSystemData>& pX);

  std::vector<VectoringNozzleSystemData>& getVectoringSystemData();
  const std::vector<VectoringNozzleSystemData>& getVectoringSystemData() const;
  void setVectoringSystemData(const std::vector<VectoringNozzleSystemData>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const SeesPdu& rhs) const;
};
}  // namespace DIS

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
