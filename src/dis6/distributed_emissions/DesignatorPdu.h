#pragma once

#include <cstdint>

#include "dis6/common/EntityID.h"
#include "dis6/common/Vector3Double.h"
#include "dis6/common/Vector3Float.h"
#include "dis6/distributed_emissions/DistributedEmissionsFamilyPdu.h"
#include "dis6/utils/DataStream.h"

namespace dis {
// Section 5.3.7.2. Handles designating operations. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class DesignatorPdu final : public DistributedEmissionsFamilyPdu {
 protected:
  /** ID of the entity designating */
  EntityID designating_entity_id_;  // NOLINT

  /** This field shall specify a unique emitter database number assigned to
   * differentiate between otherwise similar or identical emitter beams within
   * an emitter system. */
  uint16_t code_name_;  // NOLINT

  /** ID of the entity being designated */
  EntityID designated_entity_id_;  // NOLINT

  /** This field shall identify the designator code being used by the
   * designating entity  */
  uint16_t designator_code_;  // NOLINT

  /** This field shall identify the designator output power in watts */
  float designator_power_;  // NOLINT

  /** This field shall identify the designator wavelength in units of microns */
  float designator_wavelength_;  // NOLINT

  /** designtor spot wrt the designated entity */
  Vector3Float designator_spot_wrt_designated_;  // NOLINT

  /** designtor spot wrt the designated entity */
  Vector3Double designator_spot_location_;  // NOLINT

  /** Dead reckoning algorithm */
  char dead_reckoning_algorithm_;  // NOLINT

  /** padding */
  uint16_t padding1_;  // NOLINT

  /** padding */
  char padding2_;  // NOLINT

  /** linear accelleration of entity */
  Vector3Float entity_linear_acceleration_;  // NOLINT

 public:
  DesignatorPdu();
  ~DesignatorPdu() final;

  void Marshal(DataStream& dataStream) const override;
  void Unmarshal(DataStream& dataStream) override;

  EntityID& GetDesignatingEntityId();
  [[nodiscard]] const EntityID& GetDesignatingEntityId() const;
  void SetDesignatingEntityId(const EntityID& pX);

  [[nodiscard]] uint16_t GetCodeName() const;
  void SetCodeName(uint16_t pX);

  EntityID& GetDesignatedEntityId();
  [[nodiscard]] const EntityID& GetDesignatedEntityId() const;
  void SetDesignatedEntityId(const EntityID& pX);

  [[nodiscard]] uint16_t GetDesignatorCode() const;
  void SetDesignatorCode(uint16_t pX);

  [[nodiscard]] float GetDesignatorPower() const;
  void SetDesignatorPower(float pX);

  [[nodiscard]] float GetDesignatorWavelength() const;
  void SetDesignatorWavelength(float pX);

  Vector3Float& GetDesignatorSpotWrtDesignated();
  [[nodiscard]] const Vector3Float& GetDesignatorSpotWrtDesignated() const;
  void SetDesignatorSpotWrtDesignated(const Vector3Float& pX);

  Vector3Double& GetDesignatorSpotLocation();
  [[nodiscard]] const Vector3Double& GetDesignatorSpotLocation() const;
  void SetDesignatorSpotLocation(const Vector3Double& pX);

  [[nodiscard]] char GetDeadReckoningAlgorithm() const;
  void SetDeadReckoningAlgorithm(char pX);

  [[nodiscard]] uint16_t GetPadding1() const;
  void SetPadding1(uint16_t pX);

  [[nodiscard]] char GetPadding2() const;
  void SetPadding2(char pX);

  Vector3Float& GetEntityLinearAcceleration();
  [[nodiscard]] const Vector3Float& GetEntityLinearAcceleration() const;
  void SetEntityLinearAcceleration(const Vector3Float& pX);

  [[nodiscard]] int GetMarshalledSize() const override;

  bool operator==(const DesignatorPdu& rhs) const;
};
}  // namespace dis

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
