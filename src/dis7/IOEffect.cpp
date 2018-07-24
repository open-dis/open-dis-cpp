#include <DIS/IOEffect.h> 

using namespace DIS;


IOEffect::IOEffect():
   _recordType(5500), 
   _recordLength(16), 
   _ioStatus(0), 
   _ioLinkType(0), 
   _ioEffect(), 
   _ioEffectDutyCycle(0), 
   _ioEffectDuration(0), 
   _ioProcess(0), 
   _padding(0)
{
}

IOEffect::~IOEffect()
{
}

unsigned int IOEffect::getRecordType() const
{
    return _recordType;
}

void IOEffect::setRecordType(unsigned int pX)
{
    _recordType = pX;
}

unsigned short IOEffect::getRecordLength() const
{
    return _recordLength;
}

void IOEffect::setRecordLength(unsigned short pX)
{
    _recordLength = pX;
}

unsigned char IOEffect::getIoStatus() const
{
    return _ioStatus;
}

void IOEffect::setIoStatus(unsigned char pX)
{
    _ioStatus = pX;
}

unsigned char IOEffect::getIoLinkType() const
{
    return _ioLinkType;
}

void IOEffect::setIoLinkType(unsigned char pX)
{
    _ioLinkType = pX;
}

EntityID& IOEffect::getIoEffect() 
{
    return _ioEffect;
}

const EntityID& IOEffect::getIoEffect() const
{
    return _ioEffect;
}

void IOEffect::setIoEffect(const EntityID &pX)
{
    _ioEffect = pX;
}

unsigned char IOEffect::getIoEffectDutyCycle() const
{
    return _ioEffectDutyCycle;
}

void IOEffect::setIoEffectDutyCycle(unsigned char pX)
{
    _ioEffectDutyCycle = pX;
}

unsigned short IOEffect::getIoEffectDuration() const
{
    return _ioEffectDuration;
}

void IOEffect::setIoEffectDuration(unsigned short pX)
{
    _ioEffectDuration = pX;
}

unsigned short IOEffect::getIoProcess() const
{
    return _ioProcess;
}

void IOEffect::setIoProcess(unsigned short pX)
{
    _ioProcess = pX;
}

unsigned short IOEffect::getPadding() const
{
    return _padding;
}

void IOEffect::setPadding(unsigned short pX)
{
    _padding = pX;
}

void IOEffect::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _recordLength;
    dataStream << _ioStatus;
    dataStream << _ioLinkType;
    _ioEffect.marshal(dataStream);
    dataStream << _ioEffectDutyCycle;
    dataStream << _ioEffectDuration;
    dataStream << _ioProcess;
    dataStream << _padding;
}

void IOEffect::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _recordLength;
    dataStream >> _ioStatus;
    dataStream >> _ioLinkType;
    _ioEffect.unmarshal(dataStream);
    dataStream >> _ioEffectDutyCycle;
    dataStream >> _ioEffectDuration;
    dataStream >> _ioProcess;
    dataStream >> _padding;
}


bool IOEffect::operator ==(const IOEffect& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_recordLength == rhs._recordLength) ) ivarsEqual = false;
     if( ! (_ioStatus == rhs._ioStatus) ) ivarsEqual = false;
     if( ! (_ioLinkType == rhs._ioLinkType) ) ivarsEqual = false;
     if( ! (_ioEffect == rhs._ioEffect) ) ivarsEqual = false;
     if( ! (_ioEffectDutyCycle == rhs._ioEffectDutyCycle) ) ivarsEqual = false;
     if( ! (_ioEffectDuration == rhs._ioEffectDuration) ) ivarsEqual = false;
     if( ! (_ioProcess == rhs._ioProcess) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IOEffect::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _recordType
   marshalSize = marshalSize + 2;  // _recordLength
   marshalSize = marshalSize + 1;  // _ioStatus
   marshalSize = marshalSize + 1;  // _ioLinkType
   marshalSize = marshalSize + _ioEffect.getMarshalledSize();  // _ioEffect
   marshalSize = marshalSize + 1;  // _ioEffectDutyCycle
   marshalSize = marshalSize + 2;  // _ioEffectDuration
   marshalSize = marshalSize + 2;  // _ioProcess
   marshalSize = marshalSize + 2;  // _padding
    return marshalSize;
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
