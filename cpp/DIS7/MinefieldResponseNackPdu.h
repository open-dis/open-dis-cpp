#ifndef MINEFIELDRESPONSENACKPDU_H
#define MINEFIELDRESPONSENACKPDU_H

#include <DIS/EntityID.h>
#include <DIS/EntityID.h>
#include <DIS/EightByteChunk.h>
#include <vector>
#include <DIS/MinefieldFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// proivde the means to request a retransmit of a minefield data pdu. Section 7.9.5 COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO MinefieldResponseNackPdu : public MinefieldFamilyPdu
{
protected:
  /** Minefield ID */
  EntityID _minefieldID; 

  /** entity ID making the request */
  EntityID _requestingEntityID; 

  /** request ID */
  unsigned char _requestID; 

  /** how many pdus were missing */
  unsigned char _numberOfMissingPdus; 

  /** PDU sequence numbers that were missing */
  std::vector<EightByteChunk> _missingPduSequenceNumbers; 


 public:
    MinefieldResponseNackPdu();
    virtual ~MinefieldResponseNackPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getMinefieldID(); 
    const EntityID&  getMinefieldID() const; 
    void setMinefieldID(const EntityID    &pX);

    EntityID& getRequestingEntityID(); 
    const EntityID&  getRequestingEntityID() const; 
    void setRequestingEntityID(const EntityID    &pX);

    unsigned char getRequestID() const; 
    void setRequestID(unsigned char pX); 

    unsigned char getNumberOfMissingPdus() const; 

    std::vector<EightByteChunk>& getMissingPduSequenceNumbers(); 
    const std::vector<EightByteChunk>& getMissingPduSequenceNumbers() const; 
    void setMissingPduSequenceNumbers(const std::vector<EightByteChunk>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const MinefieldResponseNackPdu& rhs) const;
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
