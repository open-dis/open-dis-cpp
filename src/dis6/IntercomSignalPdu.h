#pragma once

#include <cstdint>
#include <vector>

#include "dis6/EntityID.h"
#include "dis6/RadioCommunicationsFamilyPdu.h"
#include "dis6/opendis6_export.h"
#include "dis6/utils/DataStream.h"

namespace DIS {
// Section 5.3.8.4. Actual transmission of intercome voice data. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS6_EXPORT IntercomSignalPdu : public RadioCommunicationsFamilyPdu {
 protected:
  /** entity ID */
  EntityID _entityID;

  /** ID of communications device */
  uint16_t _communicationsDeviceID;

  /** encoding scheme */
  uint16_t _encodingScheme;

  /** tactical data link type */
  uint16_t _tdlType;

  /** sample rate */
  unsigned int _sampleRate;

  /** data length */
  uint16_t _dataLength;

  /** samples */
  uint16_t _samples;

  /** data bytes */
  std::vector<uint8_t> _data;

 public:
  IntercomSignalPdu();
  virtual ~IntercomSignalPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getEntityID();
  const EntityID& getEntityID() const;
  void setEntityID(const EntityID& pX);

  uint16_t getCommunicationsDeviceID() const;
  void setCommunicationsDeviceID(uint16_t pX);

  uint16_t getEncodingScheme() const;
  void setEncodingScheme(uint16_t pX);

  uint16_t getTdlType() const;
  void setTdlType(uint16_t pX);

  unsigned int getSampleRate() const;
  void setSampleRate(unsigned int pX);

  uint16_t getDataLength() const;

  uint16_t getSamples() const;
  void setSamples(uint16_t pX);

  std::vector<uint8_t>& getData();
  const std::vector<uint8_t>& getData() const;
  void setData(const std::vector<uint8_t>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const IntercomSignalPdu& rhs) const;
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
