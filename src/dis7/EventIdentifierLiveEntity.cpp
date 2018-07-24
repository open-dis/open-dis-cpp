#include <DIS/EventIdentifierLiveEntity.h> 

using namespace DIS;


EventIdentifierLiveEntity::EventIdentifierLiveEntity():
   _siteNumber(0), 
   _applicationNumber(0), 
   _eventNumber(0)
{
}

EventIdentifierLiveEntity::~EventIdentifierLiveEntity()
{
}

unsigned char EventIdentifierLiveEntity::getSiteNumber() const
{
    return _siteNumber;
}

void EventIdentifierLiveEntity::setSiteNumber(unsigned char pX)
{
    _siteNumber = pX;
}

unsigned char EventIdentifierLiveEntity::getApplicationNumber() const
{
    return _applicationNumber;
}

void EventIdentifierLiveEntity::setApplicationNumber(unsigned char pX)
{
    _applicationNumber = pX;
}

unsigned short EventIdentifierLiveEntity::getEventNumber() const
{
    return _eventNumber;
}

void EventIdentifierLiveEntity::setEventNumber(unsigned short pX)
{
    _eventNumber = pX;
}

void EventIdentifierLiveEntity::marshal(DataStream& dataStream) const
{
    dataStream << _siteNumber;
    dataStream << _applicationNumber;
    dataStream << _eventNumber;
}

void EventIdentifierLiveEntity::unmarshal(DataStream& dataStream)
{
    dataStream >> _siteNumber;
    dataStream >> _applicationNumber;
    dataStream >> _eventNumber;
}


bool EventIdentifierLiveEntity::operator ==(const EventIdentifierLiveEntity& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_siteNumber == rhs._siteNumber) ) ivarsEqual = false;
     if( ! (_applicationNumber == rhs._applicationNumber) ) ivarsEqual = false;
     if( ! (_eventNumber == rhs._eventNumber) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EventIdentifierLiveEntity::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _siteNumber
   marshalSize = marshalSize + 1;  // _applicationNumber
   marshalSize = marshalSize + 2;  // _eventNumber
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
