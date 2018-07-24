#include <DIS/IOCommunicationsNode.h> 

using namespace DIS;


IOCommunicationsNode::IOCommunicationsNode():
   _recordType(5501), 
   _recordLength(16), 
   _communcationsNodeType(0), 
   _padding(0), 
   _communicationsNode(), 
   _elementID(0)
{
}

IOCommunicationsNode::~IOCommunicationsNode()
{
}

unsigned int IOCommunicationsNode::getRecordType() const
{
    return _recordType;
}

void IOCommunicationsNode::setRecordType(unsigned int pX)
{
    _recordType = pX;
}

unsigned short IOCommunicationsNode::getRecordLength() const
{
    return _recordLength;
}

void IOCommunicationsNode::setRecordLength(unsigned short pX)
{
    _recordLength = pX;
}

unsigned char IOCommunicationsNode::getCommuncationsNodeType() const
{
    return _communcationsNodeType;
}

void IOCommunicationsNode::setCommuncationsNodeType(unsigned char pX)
{
    _communcationsNodeType = pX;
}

unsigned char IOCommunicationsNode::getPadding() const
{
    return _padding;
}

void IOCommunicationsNode::setPadding(unsigned char pX)
{
    _padding = pX;
}

EntityID& IOCommunicationsNode::getCommunicationsNode() 
{
    return _communicationsNode;
}

const EntityID& IOCommunicationsNode::getCommunicationsNode() const
{
    return _communicationsNode;
}

void IOCommunicationsNode::setCommunicationsNode(const EntityID &pX)
{
    _communicationsNode = pX;
}

unsigned short IOCommunicationsNode::getElementID() const
{
    return _elementID;
}

void IOCommunicationsNode::setElementID(unsigned short pX)
{
    _elementID = pX;
}

void IOCommunicationsNode::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _recordLength;
    dataStream << _communcationsNodeType;
    dataStream << _padding;
    _communicationsNode.marshal(dataStream);
    dataStream << _elementID;
}

void IOCommunicationsNode::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _recordLength;
    dataStream >> _communcationsNodeType;
    dataStream >> _padding;
    _communicationsNode.unmarshal(dataStream);
    dataStream >> _elementID;
}


bool IOCommunicationsNode::operator ==(const IOCommunicationsNode& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_recordLength == rhs._recordLength) ) ivarsEqual = false;
     if( ! (_communcationsNodeType == rhs._communcationsNodeType) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;
     if( ! (_communicationsNode == rhs._communicationsNode) ) ivarsEqual = false;
     if( ! (_elementID == rhs._elementID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IOCommunicationsNode::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _recordType
   marshalSize = marshalSize + 2;  // _recordLength
   marshalSize = marshalSize + 1;  // _communcationsNodeType
   marshalSize = marshalSize + 1;  // _padding
   marshalSize = marshalSize + _communicationsNode.getMarshalledSize();  // _communicationsNode
   marshalSize = marshalSize + 2;  // _elementID
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
