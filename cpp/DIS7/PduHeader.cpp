#include <DIS/PduHeader.h> 

using namespace DIS;


PduHeader::PduHeader():
   _protocolVersion(7), 
   _exerciseID(0), 
   _pduType(0), 
   _protocolFamily(0), 
   _timestamp(0), 
   _pduLength(0), 
   _pduStatus(0), 
   _padding(0)
{
}

PduHeader::~PduHeader()
{
}

unsigned char PduHeader::getProtocolVersion() const
{
    return _protocolVersion;
}

void PduHeader::setProtocolVersion(unsigned char pX)
{
    _protocolVersion = pX;
}

unsigned char PduHeader::getExerciseID() const
{
    return _exerciseID;
}

void PduHeader::setExerciseID(unsigned char pX)
{
    _exerciseID = pX;
}

unsigned char PduHeader::getPduType() const
{
    return _pduType;
}

void PduHeader::setPduType(unsigned char pX)
{
    _pduType = pX;
}

unsigned char PduHeader::getProtocolFamily() const
{
    return _protocolFamily;
}

void PduHeader::setProtocolFamily(unsigned char pX)
{
    _protocolFamily = pX;
}

unsigned int PduHeader::getTimestamp() const
{
    return _timestamp;
}

void PduHeader::setTimestamp(unsigned int pX)
{
    _timestamp = pX;
}

unsigned char PduHeader::getPduLength() const
{
    return _pduLength;
}

void PduHeader::setPduLength(unsigned char pX)
{
    _pduLength = pX;
}

unsigned short PduHeader::getPduStatus() const
{
    return _pduStatus;
}

void PduHeader::setPduStatus(unsigned short pX)
{
    _pduStatus = pX;
}

unsigned char PduHeader::getPadding() const
{
    return _padding;
}

void PduHeader::setPadding(unsigned char pX)
{
    _padding = pX;
}

void PduHeader::marshal(DataStream& dataStream) const
{
    dataStream << _protocolVersion;
    dataStream << _exerciseID;
    dataStream << _pduType;
    dataStream << _protocolFamily;
    dataStream << _timestamp;
    dataStream << _pduLength;
    dataStream << _pduStatus;
    dataStream << _padding;
}

void PduHeader::unmarshal(DataStream& dataStream)
{
    dataStream >> _protocolVersion;
    dataStream >> _exerciseID;
    dataStream >> _pduType;
    dataStream >> _protocolFamily;
    dataStream >> _timestamp;
    dataStream >> _pduLength;
    dataStream >> _pduStatus;
    dataStream >> _padding;
}


bool PduHeader::operator ==(const PduHeader& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_protocolVersion == rhs._protocolVersion) ) ivarsEqual = false;
     if( ! (_exerciseID == rhs._exerciseID) ) ivarsEqual = false;
     if( ! (_pduType == rhs._pduType) ) ivarsEqual = false;
     if( ! (_protocolFamily == rhs._protocolFamily) ) ivarsEqual = false;
     if( ! (_timestamp == rhs._timestamp) ) ivarsEqual = false;
     if( ! (_pduLength == rhs._pduLength) ) ivarsEqual = false;
     if( ! (_pduStatus == rhs._pduStatus) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int PduHeader::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _protocolVersion
   marshalSize = marshalSize + 1;  // _exerciseID
   marshalSize = marshalSize + 1;  // _pduType
   marshalSize = marshalSize + 1;  // _protocolFamily
   marshalSize = marshalSize + 4;  // _timestamp
   marshalSize = marshalSize + 1;  // _pduLength
   marshalSize = marshalSize + 2;  // _pduStatus
   marshalSize = marshalSize + 1;  // _padding
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
