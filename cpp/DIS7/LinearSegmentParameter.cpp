#include <DIS/LinearSegmentParameter.h> 

using namespace DIS;


LinearSegmentParameter::LinearSegmentParameter():
   _segmentNumber(0), 
   _segmentModification(0), 
   _generalSegmentAppearance(0), 
   _specificSegmentAppearance(0), 
   _segmentLocation(), 
   _segmentOrientation(), 
   _segmentLength(0), 
   _segmentWidth(0), 
   _segmentHeight(0), 
   _segmentDepth(0)
{
}

LinearSegmentParameter::~LinearSegmentParameter()
{
}

unsigned char LinearSegmentParameter::getSegmentNumber() const
{
    return _segmentNumber;
}

void LinearSegmentParameter::setSegmentNumber(unsigned char pX)
{
    _segmentNumber = pX;
}

unsigned char LinearSegmentParameter::getSegmentModification() const
{
    return _segmentModification;
}

void LinearSegmentParameter::setSegmentModification(unsigned char pX)
{
    _segmentModification = pX;
}

unsigned short LinearSegmentParameter::getGeneralSegmentAppearance() const
{
    return _generalSegmentAppearance;
}

void LinearSegmentParameter::setGeneralSegmentAppearance(unsigned short pX)
{
    _generalSegmentAppearance = pX;
}

unsigned short LinearSegmentParameter::getSpecificSegmentAppearance() const
{
    return _specificSegmentAppearance;
}

void LinearSegmentParameter::setSpecificSegmentAppearance(unsigned short pX)
{
    _specificSegmentAppearance = pX;
}

Vector3Double& LinearSegmentParameter::getSegmentLocation() 
{
    return _segmentLocation;
}

const Vector3Double& LinearSegmentParameter::getSegmentLocation() const
{
    return _segmentLocation;
}

void LinearSegmentParameter::setSegmentLocation(const Vector3Double &pX)
{
    _segmentLocation = pX;
}

EulerAngles& LinearSegmentParameter::getSegmentOrientation() 
{
    return _segmentOrientation;
}

const EulerAngles& LinearSegmentParameter::getSegmentOrientation() const
{
    return _segmentOrientation;
}

void LinearSegmentParameter::setSegmentOrientation(const EulerAngles &pX)
{
    _segmentOrientation = pX;
}

unsigned short LinearSegmentParameter::getSegmentLength() const
{
    return _segmentLength;
}

void LinearSegmentParameter::setSegmentLength(unsigned short pX)
{
    _segmentLength = pX;
}

unsigned short LinearSegmentParameter::getSegmentWidth() const
{
    return _segmentWidth;
}

void LinearSegmentParameter::setSegmentWidth(unsigned short pX)
{
    _segmentWidth = pX;
}

unsigned short LinearSegmentParameter::getSegmentHeight() const
{
    return _segmentHeight;
}

void LinearSegmentParameter::setSegmentHeight(unsigned short pX)
{
    _segmentHeight = pX;
}

unsigned short LinearSegmentParameter::getSegmentDepth() const
{
    return _segmentDepth;
}

void LinearSegmentParameter::setSegmentDepth(unsigned short pX)
{
    _segmentDepth = pX;
}

void LinearSegmentParameter::marshal(DataStream& dataStream) const
{
    dataStream << _segmentNumber;
    dataStream << _segmentModification;
    dataStream << _generalSegmentAppearance;
    dataStream << _specificSegmentAppearance;
    _segmentLocation.marshal(dataStream);
    _segmentOrientation.marshal(dataStream);
    dataStream << _segmentLength;
    dataStream << _segmentWidth;
    dataStream << _segmentHeight;
    dataStream << _segmentDepth;
}

void LinearSegmentParameter::unmarshal(DataStream& dataStream)
{
    dataStream >> _segmentNumber;
    dataStream >> _segmentModification;
    dataStream >> _generalSegmentAppearance;
    dataStream >> _specificSegmentAppearance;
    _segmentLocation.unmarshal(dataStream);
    _segmentOrientation.unmarshal(dataStream);
    dataStream >> _segmentLength;
    dataStream >> _segmentWidth;
    dataStream >> _segmentHeight;
    dataStream >> _segmentDepth;
}


bool LinearSegmentParameter::operator ==(const LinearSegmentParameter& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_segmentNumber == rhs._segmentNumber) ) ivarsEqual = false;
     if( ! (_segmentModification == rhs._segmentModification) ) ivarsEqual = false;
     if( ! (_generalSegmentAppearance == rhs._generalSegmentAppearance) ) ivarsEqual = false;
     if( ! (_specificSegmentAppearance == rhs._specificSegmentAppearance) ) ivarsEqual = false;
     if( ! (_segmentLocation == rhs._segmentLocation) ) ivarsEqual = false;
     if( ! (_segmentOrientation == rhs._segmentOrientation) ) ivarsEqual = false;
     if( ! (_segmentLength == rhs._segmentLength) ) ivarsEqual = false;
     if( ! (_segmentWidth == rhs._segmentWidth) ) ivarsEqual = false;
     if( ! (_segmentHeight == rhs._segmentHeight) ) ivarsEqual = false;
     if( ! (_segmentDepth == rhs._segmentDepth) ) ivarsEqual = false;

    return ivarsEqual;
 }

int LinearSegmentParameter::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _segmentNumber
   marshalSize = marshalSize + 1;  // _segmentModification
   marshalSize = marshalSize + 2;  // _generalSegmentAppearance
   marshalSize = marshalSize + 2;  // _specificSegmentAppearance
   marshalSize = marshalSize + _segmentLocation.getMarshalledSize();  // _segmentLocation
   marshalSize = marshalSize + _segmentOrientation.getMarshalledSize();  // _segmentOrientation
   marshalSize = marshalSize + 2;  // _segmentLength
   marshalSize = marshalSize + 2;  // _segmentWidth
   marshalSize = marshalSize + 2;  // _segmentHeight
   marshalSize = marshalSize + 2;  // _segmentDepth
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
