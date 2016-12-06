#ifndef RECORDSPECIFICATIONELEMENT_H
#define RECORDSPECIFICATIONELEMENT_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Synthetic record, made up from section 6.2.72. This is used to acheive a repeating variable list element.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO RecordSpecificationElement
{
protected:
  /** the data structure used to convey the parameter values of the record for each record. 32 bit enumeration. */
  unsigned int _recordID; 

  /** the serial number of the first record in the block of records */
  unsigned int _recordSetSerialNumber; 

  /**  the length, in bits, of the record. Note, bits, not bytes. */
  unsigned short _recordLength; 

  /**  the number of records included in the record set  */
  unsigned short _recordCount; 

  /** the concatenated records of the format specified by the Record ID field. The length of this field is the Record Length multiplied by the Record Count, in units of bits. ^^^This is wrong--variable sized data records, bit values. THis MUST be patched after generation. */
  unsigned short _recordValues; 

  /** Padding of 0 to 31 unused bits as required for 32-bit alignment of the Record Set field. ^^^This is wrong--variable sized padding. MUST be patched post-code generation */
  unsigned char _pad4; 


 public:
    RecordSpecificationElement();
    virtual ~RecordSpecificationElement();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getRecordID() const; 
    void setRecordID(unsigned int pX); 

    unsigned int getRecordSetSerialNumber() const; 
    void setRecordSetSerialNumber(unsigned int pX); 

    unsigned short getRecordLength() const; 
    void setRecordLength(unsigned short pX); 

    unsigned short getRecordCount() const; 
    void setRecordCount(unsigned short pX); 

    unsigned short getRecordValues() const; 
    void setRecordValues(unsigned short pX); 

    unsigned char getPad4() const; 
    void setPad4(unsigned char pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const RecordSpecificationElement& rhs) const;
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
