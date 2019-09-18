#ifndef IOEFFECT_H
#define IOEFFECT_H

#include <dis7/EntityID.h>
#include <utils/DataStream.h>
#include <dis7/msLibMacro.h>


namespace DIS
{
// Effect of IO on an entity. Section 6.2.49.3

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO IOEffect
{
protected:
  unsigned int _recordType; 

  unsigned short _recordLength; 

  uint8_t _ioStatus; 

  uint8_t _ioLinkType; 

  EntityID _ioEffect; 

  uint8_t _ioEffectDutyCycle; 

  unsigned short _ioEffectDuration; 

  unsigned short _ioProcess; 

  unsigned short _padding; 


 public:
    IOEffect();
    virtual ~IOEffect();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getRecordType() const; 
    void setRecordType(unsigned int pX); 

    unsigned short getRecordLength() const; 
    void setRecordLength(unsigned short pX); 

    uint8_t getIoStatus() const; 
    void setIoStatus(uint8_t pX); 

    uint8_t getIoLinkType() const; 
    void setIoLinkType(uint8_t pX); 

    EntityID& getIoEffect(); 
    const EntityID&  getIoEffect() const; 
    void setIoEffect(const EntityID    &pX);

    uint8_t getIoEffectDutyCycle() const; 
    void setIoEffectDutyCycle(uint8_t pX); 

    unsigned short getIoEffectDuration() const; 
    void setIoEffectDuration(unsigned short pX); 

    unsigned short getIoProcess() const; 
    void setIoProcess(unsigned short pX); 

    unsigned short getPadding() const; 
    void setPadding(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const IOEffect& rhs) const;
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
