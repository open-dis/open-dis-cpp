#include <DIS/ArticulatedParts.h> 

using namespace DIS;


ArticulatedParts::ArticulatedParts():
   _recordType(0), 
   _changeIndicator(0), 
   _partAttachedTo(0), 
   _parameterType(0), 
   _parameterValue(0)
{
}

ArticulatedParts::~ArticulatedParts()
{
}

unsigned char ArticulatedParts::getRecordType() const
{
    return _recordType;
}

void ArticulatedParts::setRecordType(unsigned char pX)
{
    _recordType = pX;
}

unsigned char ArticulatedParts::getChangeIndicator() const
{
    return _changeIndicator;
}

void ArticulatedParts::setChangeIndicator(unsigned char pX)
{
    _changeIndicator = pX;
}

unsigned short ArticulatedParts::getPartAttachedTo() const
{
    return _partAttachedTo;
}

void ArticulatedParts::setPartAttachedTo(unsigned short pX)
{
    _partAttachedTo = pX;
}

unsigned int ArticulatedParts::getParameterType() const
{
    return _parameterType;
}

void ArticulatedParts::setParameterType(unsigned int pX)
{
    _parameterType = pX;
}

long ArticulatedParts::getParameterValue() const
{
    return _parameterValue;
}

void ArticulatedParts::setParameterValue(long pX)
{
    _parameterValue = pX;
}

void ArticulatedParts::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _changeIndicator;
    dataStream << _partAttachedTo;
    dataStream << _parameterType;
    dataStream << _parameterValue;
}

void ArticulatedParts::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _changeIndicator;
    dataStream >> _partAttachedTo;
    dataStream >> _parameterType;
    dataStream >> _parameterValue;
}


bool ArticulatedParts::operator ==(const ArticulatedParts& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_changeIndicator == rhs._changeIndicator) ) ivarsEqual = false;
     if( ! (_partAttachedTo == rhs._partAttachedTo) ) ivarsEqual = false;
     if( ! (_parameterType == rhs._parameterType) ) ivarsEqual = false;
     if( ! (_parameterValue == rhs._parameterValue) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ArticulatedParts::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _recordType
   marshalSize = marshalSize + 1;  // _changeIndicator
   marshalSize = marshalSize + 2;  // _partAttachedTo
   marshalSize = marshalSize + 4;  // _parameterType
   marshalSize = marshalSize + 8;  // _parameterValue
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
