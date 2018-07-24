#include <DIS/LinearSegmentParameter.h> 

using namespace DIS;


LinearSegmentParameter::LinearSegmentParameter():
   _segmentNumber(0), 
   _segmentAppearance(), 
   _location(), 
   _orientation(), 
   _segmentLength(0), 
   _segmentWidth(0), 
   _segmentHeight(0), 
   _segmentDepth(0), 
   _pad1(0)
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

SixByteChunk& LinearSegmentParameter::getSegmentAppearance() 
{
    return _segmentAppearance;
}

const SixByteChunk& LinearSegmentParameter::getSegmentAppearance() const
{
    return _segmentAppearance;
}

void LinearSegmentParameter::setSegmentAppearance(const SixByteChunk &pX)
{
    _segmentAppearance = pX;
}

Vector3Double& LinearSegmentParameter::getLocation() 
{
    return _location;
}

const Vector3Double& LinearSegmentParameter::getLocation() const
{
    return _location;
}

void LinearSegmentParameter::setLocation(const Vector3Double &pX)
{
    _location = pX;
}

Orientation& LinearSegmentParameter::getOrientation() 
{
    return _orientation;
}

const Orientation& LinearSegmentParameter::getOrientation() const
{
    return _orientation;
}

void LinearSegmentParameter::setOrientation(const Orientation &pX)
{
    _orientation = pX;
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

unsigned int LinearSegmentParameter::getPad1() const
{
    return _pad1;
}

void LinearSegmentParameter::setPad1(unsigned int pX)
{
    _pad1 = pX;
}

void LinearSegmentParameter::marshal(DataStream& dataStream) const
{
    dataStream << _segmentNumber;
    _segmentAppearance.marshal(dataStream);
    _location.marshal(dataStream);
    _orientation.marshal(dataStream);
    dataStream << _segmentLength;
    dataStream << _segmentWidth;
    dataStream << _segmentHeight;
    dataStream << _segmentDepth;
    dataStream << _pad1;
}

void LinearSegmentParameter::unmarshal(DataStream& dataStream)
{
    dataStream >> _segmentNumber;
    _segmentAppearance.unmarshal(dataStream);
    _location.unmarshal(dataStream);
    _orientation.unmarshal(dataStream);
    dataStream >> _segmentLength;
    dataStream >> _segmentWidth;
    dataStream >> _segmentHeight;
    dataStream >> _segmentDepth;
    dataStream >> _pad1;
}


bool LinearSegmentParameter::operator ==(const LinearSegmentParameter& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_segmentNumber == rhs._segmentNumber) ) ivarsEqual = false;
     if( ! (_segmentAppearance == rhs._segmentAppearance) ) ivarsEqual = false;
     if( ! (_location == rhs._location) ) ivarsEqual = false;
     if( ! (_orientation == rhs._orientation) ) ivarsEqual = false;
     if( ! (_segmentLength == rhs._segmentLength) ) ivarsEqual = false;
     if( ! (_segmentWidth == rhs._segmentWidth) ) ivarsEqual = false;
     if( ! (_segmentHeight == rhs._segmentHeight) ) ivarsEqual = false;
     if( ! (_segmentDepth == rhs._segmentDepth) ) ivarsEqual = false;
     if( ! (_pad1 == rhs._pad1) ) ivarsEqual = false;

    return ivarsEqual;
 }

int LinearSegmentParameter::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _segmentNumber
   marshalSize = marshalSize + _segmentAppearance.getMarshalledSize();  // _segmentAppearance
   marshalSize = marshalSize + _location.getMarshalledSize();  // _location
   marshalSize = marshalSize + _orientation.getMarshalledSize();  // _orientation
   marshalSize = marshalSize + 2;  // _segmentLength
   marshalSize = marshalSize + 2;  // _segmentWidth
   marshalSize = marshalSize + 2;  // _segmentHeight
   marshalSize = marshalSize + 2;  // _segmentDepth
   marshalSize = marshalSize + 4;  // _pad1
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
