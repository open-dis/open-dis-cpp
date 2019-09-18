#ifndef PDU_H
#define PDU_H

#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// The superclass for all PDUs. This incorporates the PduHeader record, section 5.2.29.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO Pdu
{
protected:
  /** The version of the protocol. 5=DIS-1995, 6=DIS-1998. */
  uint8_t _protocolVersion; 

  /** Exercise ID */
  uint8_t _exerciseID; 

  /** Type of pdu, unique for each PDU class */
  uint8_t _pduType; 

  /** value that refers to the protocol family, eg SimulationManagement, et */
  uint8_t _protocolFamily; 

  /** Timestamp value */
  unsigned int _timestamp; 

  /** Length, in bytes, of the PDU */
  unsigned short _length; 

  /** zero-filled array of padding */
  short _padding; 


 public:
    Pdu();
    virtual ~Pdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    uint8_t getProtocolVersion() const; 
    void setProtocolVersion(uint8_t pX); 

    uint8_t getExerciseID() const; 
    void setExerciseID(uint8_t pX); 

    uint8_t getPduType() const; 
    void setPduType(uint8_t pX); 

    uint8_t getProtocolFamily() const; 
    void setProtocolFamily(uint8_t pX); 

    unsigned int getTimestamp() const; 
    void setTimestamp(unsigned int pX); 

    unsigned short getLength() const; 
    void setLength(unsigned short pX); 

    short getPadding() const; 
    void setPadding(short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const Pdu& rhs) const;
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
