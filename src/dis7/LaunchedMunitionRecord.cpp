#include <DIS/LaunchedMunitionRecord.h> 

using namespace DIS;


LaunchedMunitionRecord::LaunchedMunitionRecord():
   _fireEventID(), 
   _padding(0), 
   _firingEntityID(), 
   _padding2(0), 
   _targetEntityID(), 
   _padding3(0), 
   _targetLocation()
{
}

LaunchedMunitionRecord::~LaunchedMunitionRecord()
{
}

EventIdentifier& LaunchedMunitionRecord::getFireEventID() 
{
    return _fireEventID;
}

const EventIdentifier& LaunchedMunitionRecord::getFireEventID() const
{
    return _fireEventID;
}

void LaunchedMunitionRecord::setFireEventID(const EventIdentifier &pX)
{
    _fireEventID = pX;
}

unsigned short LaunchedMunitionRecord::getPadding() const
{
    return _padding;
}

void LaunchedMunitionRecord::setPadding(unsigned short pX)
{
    _padding = pX;
}

EventIdentifier& LaunchedMunitionRecord::getFiringEntityID() 
{
    return _firingEntityID;
}

const EventIdentifier& LaunchedMunitionRecord::getFiringEntityID() const
{
    return _firingEntityID;
}

void LaunchedMunitionRecord::setFiringEntityID(const EventIdentifier &pX)
{
    _firingEntityID = pX;
}

unsigned short LaunchedMunitionRecord::getPadding2() const
{
    return _padding2;
}

void LaunchedMunitionRecord::setPadding2(unsigned short pX)
{
    _padding2 = pX;
}

EventIdentifier& LaunchedMunitionRecord::getTargetEntityID() 
{
    return _targetEntityID;
}

const EventIdentifier& LaunchedMunitionRecord::getTargetEntityID() const
{
    return _targetEntityID;
}

void LaunchedMunitionRecord::setTargetEntityID(const EventIdentifier &pX)
{
    _targetEntityID = pX;
}

unsigned short LaunchedMunitionRecord::getPadding3() const
{
    return _padding3;
}

void LaunchedMunitionRecord::setPadding3(unsigned short pX)
{
    _padding3 = pX;
}

Vector3Double& LaunchedMunitionRecord::getTargetLocation() 
{
    return _targetLocation;
}

const Vector3Double& LaunchedMunitionRecord::getTargetLocation() const
{
    return _targetLocation;
}

void LaunchedMunitionRecord::setTargetLocation(const Vector3Double &pX)
{
    _targetLocation = pX;
}

void LaunchedMunitionRecord::marshal(DataStream& dataStream) const
{
    _fireEventID.marshal(dataStream);
    dataStream << _padding;
    _firingEntityID.marshal(dataStream);
    dataStream << _padding2;
    _targetEntityID.marshal(dataStream);
    dataStream << _padding3;
    _targetLocation.marshal(dataStream);
}

void LaunchedMunitionRecord::unmarshal(DataStream& dataStream)
{
    _fireEventID.unmarshal(dataStream);
    dataStream >> _padding;
    _firingEntityID.unmarshal(dataStream);
    dataStream >> _padding2;
    _targetEntityID.unmarshal(dataStream);
    dataStream >> _padding3;
    _targetLocation.unmarshal(dataStream);
}


bool LaunchedMunitionRecord::operator ==(const LaunchedMunitionRecord& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_fireEventID == rhs._fireEventID) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;
     if( ! (_firingEntityID == rhs._firingEntityID) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;
     if( ! (_targetEntityID == rhs._targetEntityID) ) ivarsEqual = false;
     if( ! (_padding3 == rhs._padding3) ) ivarsEqual = false;
     if( ! (_targetLocation == rhs._targetLocation) ) ivarsEqual = false;

    return ivarsEqual;
 }

int LaunchedMunitionRecord::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + _fireEventID.getMarshalledSize();  // _fireEventID
   marshalSize = marshalSize + 2;  // _padding
   marshalSize = marshalSize + _firingEntityID.getMarshalledSize();  // _firingEntityID
   marshalSize = marshalSize + 2;  // _padding2
   marshalSize = marshalSize + _targetEntityID.getMarshalledSize();  // _targetEntityID
   marshalSize = marshalSize + 2;  // _padding3
   marshalSize = marshalSize + _targetLocation.getMarshalledSize();  // _targetLocation
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
