#include "dis6/distributed_emissions/BeamData.h"

namespace dis {
BeamData::BeamData()
    : beam_azimuth_center_(0.0),
      beam_azimuth_sweep_(0.0),
      beam_elevation_center_(0.0),
      beam_elevation_sweep_(0.0),
      beam_sweep_sync_(0.0) {}

float BeamData::GetBeamAzimuthCenter() const { return beam_azimuth_center_; }

void BeamData::SetBeamAzimuthCenter(float pX) { beam_azimuth_center_ = pX; }

float BeamData::GetBeamAzimuthSweep() const { return beam_azimuth_sweep_; }

void BeamData::SetBeamAzimuthSweep(float pX) { beam_azimuth_sweep_ = pX; }

float BeamData::GetBeamElevationCenter() const {
  return beam_elevation_center_;
}

void BeamData::SetBeamElevationCenter(float pX) { beam_elevation_center_ = pX; }

float BeamData::GetBeamElevationSweep() const { return beam_elevation_sweep_; }

void BeamData::SetBeamElevationSweep(float pX) { beam_elevation_sweep_ = pX; }

float BeamData::GetBeamSweepSync() const { return beam_sweep_sync_; }

void BeamData::SetBeamSweepSync(float pX) { beam_sweep_sync_ = pX; }

void BeamData::Marshal(DataStream& dataStream) const {
  dataStream << beam_azimuth_center_;
  dataStream << beam_azimuth_sweep_;
  dataStream << beam_elevation_center_;
  dataStream << beam_elevation_sweep_;
  dataStream << beam_sweep_sync_;
}

void BeamData::Unmarshal(DataStream& dataStream) {
  dataStream >> beam_azimuth_center_;
  dataStream >> beam_azimuth_sweep_;
  dataStream >> beam_elevation_center_;
  dataStream >> beam_elevation_sweep_;
  dataStream >> beam_sweep_sync_;
}

bool BeamData::operator==(const BeamData& rhs) const {
  bool ivars_equal = true;

  if (beam_azimuth_center_ != rhs.beam_azimuth_center_) {
    ivars_equal = false;
  }
  if (beam_azimuth_sweep_ != rhs.beam_azimuth_sweep_) {
    ivars_equal = false;
  }
  if (beam_elevation_center_ != rhs.beam_elevation_center_) {
    ivars_equal = false;
  }
  if (beam_elevation_sweep_ != rhs.beam_elevation_sweep_) {
    ivars_equal = false;
  }
  if (beam_sweep_sync_ != rhs.beam_sweep_sync_) {
    ivars_equal = false;
  }

  return ivars_equal;
}

int BeamData::GetMarshalledSize() {
  int marshal_size = 0;

  marshal_size = marshal_size + 4;  // beam_azimuth_center_
  marshal_size = marshal_size + 4;  // beam_azimuth_sweep_
  marshal_size = marshal_size + 4;  // beam_elevation_center_
  marshal_size = marshal_size + 4;  // beam_elevation_sweep_
  marshal_size = marshal_size + 4;  // beam_sweep_sync_
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
