#ifndef DIS6_COMMON_ARTICULATIONPARAMETER_H_
#define DIS6_COMMON_ARTICULATIONPARAMETER_H_

#include <cstdint>

#include "dis6/utils/DataStream.h"

namespace dis {
// Section 5.2.5. Articulation parameters for  movable parts and attached parts
// of an entity. Specifes wether or not a change has occured,  the part
// identifcation of the articulated part to which it is attached, and the type
// and value of each parameter.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class ArticulationParameter {
 protected:
  uint8_t parameter_type_designator_;

  uint8_t change_indicator_;

  uint16_t part_attached_to_;

  int parameter_type_;

  double parameter_value_;

 public:
  ArticulationParameter();
  ~ArticulationParameter() = default;

  void Marshal(DataStream& dataStream) const;
  void Unmarshal(DataStream& dataStream);

  [[nodiscard]] uint8_t GetParameterTypeDesignator() const;
  void SetParameterTypeDesignator(uint8_t pX);

  [[nodiscard]] uint8_t GetChangeIndicator() const;
  void SetChangeIndicator(uint8_t pX);

  [[nodiscard]] uint16_t GetPartAttachedTo() const;
  void SetPartAttachedTo(uint16_t pX);

  [[nodiscard]] int GetParameterType() const;
  void SetParameterType(int pX);

  [[nodiscard]] double GetParameterValue() const;
  void SetParameterValue(double pX);

  [[nodiscard]] size_t GetMarshalledSize() const;

  bool operator==(const ArticulationParameter& rhs) const;
};

}  // namespace dis

#endif  // DIS6_COMMON_ARTICULATIONPARAMETER_H_

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
