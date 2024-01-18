#pragma once

#include "dis7/EntityInformationFamilyPdu.h"
#include "dis7/SimulationAddress.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// Information about individual attributes for a particular entity, other
// object, or event may be communicated using an Attribute PDU. The Attribute
// PDU shall not be used to exchange data available in any other PDU except
// where explicitly mentioned in the PDU issuance instructions within this
// standard. See 5.3.6 for the information requirements and issuance and receipt
// rules for this PDU. Section 7.2.6. INCOMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class OPENDIS7_EXPORT AttributePdu : public EntityInformationFamilyPdu {
 protected:
  /** This field shall identify the simulation issuing the Attribute PDU. It
   * shall be represented by a Simulation Address record (see 6.2.79). */
  SimulationAddress _originatingSimulationAddress;

  /** Padding */
  int _padding1;

  /** Padding */
  int16_t _padding2;

  /** This field shall represent the type of the PDU that is being extended or
   * updated, if applicable. It shall be represented by an 8-bit enumeration. */
  uint8_t _attributeRecordPduType;

  /** This field shall indicate the Protocol Version associated with the
   * Attribute Record PDU Type. It shall be represented by an 8-bit enumeration.
   */
  uint8_t _attributeRecordProtocolVersion;

  /** This field shall contain the Attribute record type of the Attribute
   * records in the PDU if they all have the same Attribute record type. It
   * shall be represented by a 32-bit enumeration. */
  uint32_t _masterAttributeRecordType;

  /** This field shall identify the action code applicable to this Attribute
   * PDU. The Action Code shall apply to all Attribute records contained in the
   * PDU. It shall be represented by an 8-bit enumeration. */
  uint8_t _actionCode;

  /** Padding */
  char _padding3;

  /** This field shall specify the number of Attribute Record Sets that make up
   * the remainder of the PDU. It shall be represented by a 16-bit unsigned
   * integer. */
  uint16_t _numberAttributeRecordSet;

 public:
  AttributePdu();
  virtual ~AttributePdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  SimulationAddress& getOriginatingSimulationAddress();
  const SimulationAddress& getOriginatingSimulationAddress() const;
  void setOriginatingSimulationAddress(const SimulationAddress& pX);

  int getPadding1() const;
  void setPadding1(int pX);

  int16_t getPadding2() const;
  void setPadding2(int16_t pX);

  uint8_t getAttributeRecordPduType() const;
  void setAttributeRecordPduType(uint8_t pX);

  uint8_t getAttributeRecordProtocolVersion() const;
  void setAttributeRecordProtocolVersion(uint8_t pX);

  uint32_t getMasterAttributeRecordType() const;
  void setMasterAttributeRecordType(uint32_t pX);

  uint8_t getActionCode() const;
  void setActionCode(uint8_t pX);

  char getPadding3() const;
  void setPadding3(char pX);

  uint16_t getNumberAttributeRecordSet() const;
  void setNumberAttributeRecordSet(uint16_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const AttributePdu& rhs) const;
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
