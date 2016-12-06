#ifndef ATTRIBUTEPDU_H
#define ATTRIBUTEPDU_H

#include <DIS/SimulationAddress.h>
#include <DIS/EntityInformationFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Information about individual attributes for a particular entity, other object, or event may be communicated using an Attribute PDU. The Attribute PDU shall not be used to exchange data available in any other PDU except where explicitly mentioned in the PDU issuance instructions within this standard. See 5.3.6 for the information requirements and issuance and receipt rules for this PDU. Section 7.2.6. INCOMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO AttributePdu : public EntityInformationFamilyPdu
{
protected:
  /** This field shall identify the simulation issuing the Attribute PDU. It shall be represented by a Simulation Address record (see 6.2.79). */
  SimulationAddress _originatingSimulationAddress; 

  /** Padding */
  int _padding1; 

  /** Padding */
  short _padding2; 

  /** This field shall represent the type of the PDU that is being extended or updated, if applicable. It shall be represented by an 8-bit enumeration. */
  unsigned char _attributeRecordPduType; 

  /** This field shall indicate the Protocol Version associated with the Attribute Record PDU Type. It shall be represented by an 8-bit enumeration. */
  unsigned char _attributeRecordProtocolVersion; 

  /** This field shall contain the Attribute record type of the Attribute records in the PDU if they all have the same Attribute record type. It shall be represented by a 32-bit enumeration. */
  unsigned int _masterAttributeRecordType; 

  /** This field shall identify the action code applicable to this Attribute PDU. The Action Code shall apply to all Attribute records contained in the PDU. It shall be represented by an 8-bit enumeration. */
  unsigned char _actionCode; 

  /** Padding */
  char _padding3; 

  /** This field shall specify the number of Attribute Record Sets that make up the remainder of the PDU. It shall be represented by a 16-bit unsigned integer. */
  unsigned short _numberAttributeRecordSet; 


 public:
    AttributePdu();
    virtual ~AttributePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    SimulationAddress& getOriginatingSimulationAddress(); 
    const SimulationAddress&  getOriginatingSimulationAddress() const; 
    void setOriginatingSimulationAddress(const SimulationAddress    &pX);

    int getPadding1() const; 
    void setPadding1(int pX); 

    short getPadding2() const; 
    void setPadding2(short pX); 

    unsigned char getAttributeRecordPduType() const; 
    void setAttributeRecordPduType(unsigned char pX); 

    unsigned char getAttributeRecordProtocolVersion() const; 
    void setAttributeRecordProtocolVersion(unsigned char pX); 

    unsigned int getMasterAttributeRecordType() const; 
    void setMasterAttributeRecordType(unsigned int pX); 

    unsigned char getActionCode() const; 
    void setActionCode(unsigned char pX); 

    char getPadding3() const; 
    void setPadding3(char pX); 

    unsigned short getNumberAttributeRecordSet() const; 
    void setNumberAttributeRecordSet(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const AttributePdu& rhs) const;
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
