#pragma once

#include <dis6/OneByteChunk.h>
#include <vector>
#include <dis6/RadioCommunicationsFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.8.2. Detailed information about a radio transmitter. This PDU requires        manually written code to complete. The encodingScheme field can be used in multiple        ways, which requires hand-written code to finish. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO SignalPdu : public RadioCommunicationsFamilyPdu
{
protected:
  /** encoding scheme used, and enumeration */
  unsigned short _encodingScheme; 

  /** tdl type */
  unsigned short _tdlType; 

  /** sample rate */
  unsigned int _sampleRate; 

  /** length od data */
  short _dataLength; 

  /** number of samples */
  short _samples; 

  /** list of eight bit values */
  std::vector<OneByteChunk> _data; 


 public:
    SignalPdu();
    virtual ~SignalPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned short getEncodingScheme() const; 
    void setEncodingScheme(unsigned short pX); 

    unsigned short getTdlType() const; 
    void setTdlType(unsigned short pX); 

    unsigned int getSampleRate() const; 
    void setSampleRate(unsigned int pX); 

    short getDataLength() const; 

    short getSamples() const; 
    void setSamples(short pX); 

    std::vector<OneByteChunk>& getData(); 
    const std::vector<OneByteChunk>& getData() const; 
    void setData(const std::vector<OneByteChunk>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const SignalPdu& rhs) const;
};
}

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
