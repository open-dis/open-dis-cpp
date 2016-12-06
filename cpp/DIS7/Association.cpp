#include <DIS/Association.h> 

using namespace DIS;


Association::Association():
   _associationType(0), 
   _padding4(0), 
   _associatedEntityID(), 
   _associatedLocation()
{
}

Association::~Association()
{
}

unsigned char Association::getAssociationType() const
{
    return _associationType;
}

void Association::setAssociationType(unsigned char pX)
{
    _associationType = pX;
}

unsigned char Association::getPadding4() const
{
    return _padding4;
}

void Association::setPadding4(unsigned char pX)
{
    _padding4 = pX;
}

EntityID& Association::getAssociatedEntityID() 
{
    return _associatedEntityID;
}

const EntityID& Association::getAssociatedEntityID() const
{
    return _associatedEntityID;
}

void Association::setAssociatedEntityID(const EntityID &pX)
{
    _associatedEntityID = pX;
}

Vector3Double& Association::getAssociatedLocation() 
{
    return _associatedLocation;
}

const Vector3Double& Association::getAssociatedLocation() const
{
    return _associatedLocation;
}

void Association::setAssociatedLocation(const Vector3Double &pX)
{
    _associatedLocation = pX;
}

void Association::marshal(DataStream& dataStream) const
{
    dataStream << _associationType;
    dataStream << _padding4;
    _associatedEntityID.marshal(dataStream);
    _associatedLocation.marshal(dataStream);
}

void Association::unmarshal(DataStream& dataStream)
{
    dataStream >> _associationType;
    dataStream >> _padding4;
    _associatedEntityID.unmarshal(dataStream);
    _associatedLocation.unmarshal(dataStream);
}


bool Association::operator ==(const Association& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_associationType == rhs._associationType) ) ivarsEqual = false;
     if( ! (_padding4 == rhs._padding4) ) ivarsEqual = false;
     if( ! (_associatedEntityID == rhs._associatedEntityID) ) ivarsEqual = false;
     if( ! (_associatedLocation == rhs._associatedLocation) ) ivarsEqual = false;

    return ivarsEqual;
 }

int Association::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _associationType
   marshalSize = marshalSize + 1;  // _padding4
   marshalSize = marshalSize + _associatedEntityID.getMarshalledSize();  // _associatedEntityID
   marshalSize = marshalSize + _associatedLocation.getMarshalledSize();  // _associatedLocation
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
