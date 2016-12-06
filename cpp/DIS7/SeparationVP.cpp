#include <DIS/SeparationVP.h> 

using namespace DIS;


SeparationVP::SeparationVP():
   _recordType(4), 
   _reasonForSeparation(0), 
   _preEntityIndicator(0), 
   _padding1(0), 
   _parentEntityID(), 
   _padding2(0), 
   _stationLocation(0)
{
}

SeparationVP::~SeparationVP()
{
}

unsigned char SeparationVP::getRecordType() const
{
    return _recordType;
}

void SeparationVP::setRecordType(unsigned char pX)
{
    _recordType = pX;
}

unsigned char SeparationVP::getReasonForSeparation() const
{
    return _reasonForSeparation;
}

void SeparationVP::setReasonForSeparation(unsigned char pX)
{
    _reasonForSeparation = pX;
}

unsigned char SeparationVP::getPreEntityIndicator() const
{
    return _preEntityIndicator;
}

void SeparationVP::setPreEntityIndicator(unsigned char pX)
{
    _preEntityIndicator = pX;
}

unsigned char SeparationVP::getPadding1() const
{
    return _padding1;
}

void SeparationVP::setPadding1(unsigned char pX)
{
    _padding1 = pX;
}

EntityID& SeparationVP::getParentEntityID() 
{
    return _parentEntityID;
}

const EntityID& SeparationVP::getParentEntityID() const
{
    return _parentEntityID;
}

void SeparationVP::setParentEntityID(const EntityID &pX)
{
    _parentEntityID = pX;
}

unsigned short SeparationVP::getPadding2() const
{
    return _padding2;
}

void SeparationVP::setPadding2(unsigned short pX)
{
    _padding2 = pX;
}

unsigned int SeparationVP::getStationLocation() const
{
    return _stationLocation;
}

void SeparationVP::setStationLocation(unsigned int pX)
{
    _stationLocation = pX;
}

void SeparationVP::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _reasonForSeparation;
    dataStream << _preEntityIndicator;
    dataStream << _padding1;
    _parentEntityID.marshal(dataStream);
    dataStream << _padding2;
    dataStream << _stationLocation;
}

void SeparationVP::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _reasonForSeparation;
    dataStream >> _preEntityIndicator;
    dataStream >> _padding1;
    _parentEntityID.unmarshal(dataStream);
    dataStream >> _padding2;
    dataStream >> _stationLocation;
}


bool SeparationVP::operator ==(const SeparationVP& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_reasonForSeparation == rhs._reasonForSeparation) ) ivarsEqual = false;
     if( ! (_preEntityIndicator == rhs._preEntityIndicator) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_parentEntityID == rhs._parentEntityID) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;
     if( ! (_stationLocation == rhs._stationLocation) ) ivarsEqual = false;

    return ivarsEqual;
 }

int SeparationVP::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _recordType
   marshalSize = marshalSize + 1;  // _reasonForSeparation
   marshalSize = marshalSize + 1;  // _preEntityIndicator
   marshalSize = marshalSize + 1;  // _padding1
   marshalSize = marshalSize + _parentEntityID.getMarshalledSize();  // _parentEntityID
   marshalSize = marshalSize + 2;  // _padding2
   marshalSize = marshalSize + 4;  // _stationLocation
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
