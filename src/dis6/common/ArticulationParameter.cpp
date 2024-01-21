#include "dis6/common/ArticulationParameter.h"

namespace dis {

ArticulationParameter::ArticulationParameter()
    : parameter_type_designator_(0),
      change_indicator_(0),
      part_attached_to_(0),
      parameter_type_(0),
      parameter_value_(0.0) {}

ArticulationParameter::~ArticulationParameter() = default;

uint8_t ArticulationParameter::GetParameterTypeDesignator() const {
  return parameter_type_designator_;
}

void ArticulationParameter::SetParameterTypeDesignator(uint8_t pX) {
  parameter_type_designator_ = pX;
}

uint8_t ArticulationParameter::GetChangeIndicator() const {
  return change_indicator_;
}

void ArticulationParameter::SetChangeIndicator(uint8_t pX) {
  change_indicator_ = pX;
}

uint16_t ArticulationParameter::GetPartAttachedTo() const {
  return part_attached_to_;
}

void ArticulationParameter::SetPartAttachedTo(uint16_t pX) {
  part_attached_to_ = pX;
}

int ArticulationParameter::GetParameterType() const { return parameter_type_; }

void ArticulationParameter::SetParameterType(int pX) { parameter_type_ = pX; }

double ArticulationParameter::GetParameterValue() const {
  return parameter_value_;
}

void ArticulationParameter::SetParameterValue(double pX) {
  parameter_value_ = pX;
}

void ArticulationParameter::Marshal(DataStream& dataStream) const {
  dataStream << parameter_type_designator_;
  dataStream << change_indicator_;
  dataStream << part_attached_to_;
  dataStream << parameter_type_;
  dataStream << parameter_value_;
}

void ArticulationParameter::Unmarshal(DataStream& dataStream) {
  dataStream >> parameter_type_designator_;
  dataStream >> change_indicator_;
  dataStream >> part_attached_to_;
  dataStream >> parameter_type_;
  dataStream >> parameter_value_;
}

bool ArticulationParameter::operator==(const ArticulationParameter& rhs) const {
  bool ivars_equal = true;

  if (!(parameter_type_designator_ == rhs.parameter_type_designator_)) {
    ivars_equal = false;
  }
  if (!(change_indicator_ == rhs.change_indicator_)) {
    ivars_equal = false;
  }
  if (!(part_attached_to_ == rhs.part_attached_to_)) {
    ivars_equal = false;
  }
  if (!(parameter_type_ == rhs.parameter_type_)) {
    ivars_equal = false;
  }
  if (!(parameter_value_ == rhs.parameter_value_)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int ArticulationParameter::GetMarshalledSize() const {
  int marshal_size = 0;

  marshal_size = marshal_size + 1;  // _parameterTypeDesignator
  marshal_size = marshal_size + 1;  // _changeIndicator
  marshal_size = marshal_size + 2;  // _partAttachedTo
  marshal_size = marshal_size + 4;  // _parameterType
  marshal_size = marshal_size + 8;  // _parameterValue
  return marshal_size;
}

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
