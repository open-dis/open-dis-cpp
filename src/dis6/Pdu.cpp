#include <DIS/Pdu.h> 

using namespace DIS;


Pdu::Pdu():
   _protocolVersion(6), 
   _exerciseID(0), 
   _pduType(0), 
   _protocolFamily(0), 
   _timestamp(0), 
   _length(0), 
   _padding(0)
{
}

Pdu::~Pdu()
{
}

unsigned char Pdu::getProtocolVersion() const
{
    return _protocolVersion;
}

void Pdu::setProtocolVersion(unsigned char pX)
{
    _protocolVersion = pX;
}

unsigned char Pdu::getExerciseID() const
{
    return _exerciseID;
}

void Pdu::setExerciseID(unsigned char pX)
{
    _exerciseID = pX;
}

unsigned char Pdu::getPduType() const
{
    return _pduType;
}

void Pdu::setPduType(unsigned char pX)
{
    _pduType = pX;
}

unsigned char Pdu::getProtocolFamily() const
{
    return _protocolFamily;
}

void Pdu::setProtocolFamily(unsigned char pX)
{
    _protocolFamily = pX;
}

unsigned int Pdu::getTimestamp() const
{
    return _timestamp;
}

void Pdu::setTimestamp(unsigned int pX)
{
    _timestamp = pX;
}

unsigned short Pdu::getLength() const
{
    return this->getMarshalledSize();
}

void Pdu::setLength(unsigned short pX)
{
    _length = pX;
}

short Pdu::getPadding() const
{
    return _padding;
}

void Pdu::setPadding(short pX)
{
    _padding = pX;
}

void Pdu::marshal(DataStream& dataStream) const
{
    dataStream << _protocolVersion;
    dataStream << _exerciseID;
    dataStream << _pduType;
    dataStream << _protocolFamily;
    dataStream << _timestamp;
    dataStream << this->getLength();
    dataStream << _padding;
}

void Pdu::unmarshal(DataStream& dataStream)
{
    dataStream >> _protocolVersion;
    dataStream >> _exerciseID;
    dataStream >> _pduType;
    dataStream >> _protocolFamily;
    dataStream >> _timestamp;
    dataStream >> _length;
    dataStream >> _padding;
}


bool Pdu::operator ==(const Pdu& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_protocolVersion == rhs._protocolVersion) ) ivarsEqual = false;
     if( ! (_exerciseID == rhs._exerciseID) ) ivarsEqual = false;
     if( ! (_pduType == rhs._pduType) ) ivarsEqual = false;
     if( ! (_protocolFamily == rhs._protocolFamily) ) ivarsEqual = false;
     if( ! (_timestamp == rhs._timestamp) ) ivarsEqual = false;
     if( ! (_length == rhs._length) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int Pdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _protocolVersion
   marshalSize = marshalSize + 1;  // _exerciseID
   marshalSize = marshalSize + 1;  // _pduType
   marshalSize = marshalSize + 1;  // _protocolFamily
   marshalSize = marshalSize + 4;  // _timestamp
   marshalSize = marshalSize + 2;  // _length
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
