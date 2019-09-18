#ifndef PDUHEADER_H
#define PDUHEADER_H

#include <utils/DataStream.h>
#include <dis7/msLibMacro.h>


namespace DIS
{
// Not used. The PDU Header Record is directly incoroporated into the PDU class. Here for completness only. Section 6.2.66

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO PduHeader
{
protected:
  /** The version of the protocol. 5=DIS-1995, 6=DIS-1998, 7=DIS-2009. */
  uint8_t _protocolVersion; 

  /** Exercise ID */
  uint8_t _exerciseID; 

  /** Type of pdu, unique for each PDU class */
  uint8_t _pduType; 

  /** value that refers to the protocol family, eg SimulationManagement, etc */
  uint8_t _protocolFamily; 

  /** Timestamp value */
  unsigned int _timestamp; 

  /** Length, in bytes, of the PDU. Changed name from length to avoid use of Hibernate QL reserved word. */
  uint8_t _pduLength; 

  /** PDU Status Record. Described in 6.2.67. This field is not present in earlier DIS versions  */
  unsigned short _pduStatus; 

  /** zero filled array of padding */
  uint8_t _padding; 


 public:
    PduHeader();
    virtual ~PduHeader();

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

    uint8_t getPduLength() const; 
    void setPduLength(uint8_t pX); 

    unsigned short getPduStatus() const; 
    void setPduStatus(unsigned short pX); 

    uint8_t getPadding() const; 
    void setPadding(uint8_t pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const PduHeader& rhs) const;
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
