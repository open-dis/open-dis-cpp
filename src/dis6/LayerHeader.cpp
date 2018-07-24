#include <DIS/LayerHeader.h> 

using namespace DIS;


LayerHeader::LayerHeader():
   _layerNumber(0), 
   _layerSpecificInformaiton(0), 
   _length(0)
{
}

LayerHeader::~LayerHeader()
{
}

unsigned char LayerHeader::getLayerNumber() const
{
    return _layerNumber;
}

void LayerHeader::setLayerNumber(unsigned char pX)
{
    _layerNumber = pX;
}

unsigned char LayerHeader::getLayerSpecificInformaiton() const
{
    return _layerSpecificInformaiton;
}

void LayerHeader::setLayerSpecificInformaiton(unsigned char pX)
{
    _layerSpecificInformaiton = pX;
}

unsigned short LayerHeader::getLength() const
{
    return _length;
}

void LayerHeader::setLength(unsigned short pX)
{
    _length = pX;
}

void LayerHeader::marshal(DataStream& dataStream) const
{
    dataStream << _layerNumber;
    dataStream << _layerSpecificInformaiton;
    dataStream << _length;
}

void LayerHeader::unmarshal(DataStream& dataStream)
{
    dataStream >> _layerNumber;
    dataStream >> _layerSpecificInformaiton;
    dataStream >> _length;
}


bool LayerHeader::operator ==(const LayerHeader& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_layerNumber == rhs._layerNumber) ) ivarsEqual = false;
     if( ! (_layerSpecificInformaiton == rhs._layerSpecificInformaiton) ) ivarsEqual = false;
     if( ! (_length == rhs._length) ) ivarsEqual = false;

    return ivarsEqual;
 }

int LayerHeader::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _layerNumber
   marshalSize = marshalSize + 1;  // _layerSpecificInformaiton
   marshalSize = marshalSize + 2;  // _length
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
