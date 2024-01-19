#pragma once


#include "dis6/utils/DataStream.h"

namespace DIS {
// 5.2.42. Basic operational data ofr IFF ATC NAVAIDS

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All
// rights reserved.
//
// @author DMcG, jkg

class IffFundamentalData {
 protected:
  /** system status */
  uint8_t _systemStatus;

  /** Alternate parameter 4 */
  uint8_t _alternateParameter4;

  /** eight boolean fields */
  uint8_t _informationLayers;

  /** enumeration */
  uint8_t _modifier;

  /** parameter, enumeration */
  uint16_t _parameter1;

  /** parameter, enumeration */
  uint16_t _parameter2;

  /** parameter, enumeration */
  uint16_t _parameter3;

  /** parameter, enumeration */
  uint16_t _parameter4;

  /** parameter, enumeration */
  uint16_t _parameter5;

  /** parameter, enumeration */
  uint16_t _parameter6;

 public:
  IffFundamentalData();
  virtual ~IffFundamentalData();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  uint8_t getSystemStatus() const;
  void setSystemStatus(uint8_t pX);

  uint8_t getAlternateParameter4() const;
  void setAlternateParameter4(uint8_t pX);

  uint8_t getInformationLayers() const;
  void setInformationLayers(uint8_t pX);

  uint8_t getModifier() const;
  void setModifier(uint8_t pX);

  uint16_t getParameter1() const;
  void setParameter1(uint16_t pX);

  uint16_t getParameter2() const;
  void setParameter2(uint16_t pX);

  uint16_t getParameter3() const;
  void setParameter3(uint16_t pX);

  uint16_t getParameter4() const;
  void setParameter4(uint16_t pX);

  uint16_t getParameter5() const;
  void setParameter5(uint16_t pX);

  uint16_t getParameter6() const;
  void setParameter6(uint16_t pX);

  virtual int getMarshalledSize() const;

  bool operator==(const IffFundamentalData& rhs) const;
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
