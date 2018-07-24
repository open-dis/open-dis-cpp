#include <DIS/AttributePdu.h> 

using namespace DIS;


AttributePdu::AttributePdu() : EntityInformationFamilyPdu(),
   _originatingSimulationAddress(), 
   _padding1(0), 
   _padding2(0), 
   _attributeRecordPduType(0), 
   _attributeRecordProtocolVersion(0), 
   _masterAttributeRecordType(0), 
   _actionCode(0), 
   _padding3(0), 
   _numberAttributeRecordSet(0)
{
}

AttributePdu::~AttributePdu()
{
}

SimulationAddress& AttributePdu::getOriginatingSimulationAddress() 
{
    return _originatingSimulationAddress;
}

const SimulationAddress& AttributePdu::getOriginatingSimulationAddress() const
{
    return _originatingSimulationAddress;
}

void AttributePdu::setOriginatingSimulationAddress(const SimulationAddress &pX)
{
    _originatingSimulationAddress = pX;
}

int AttributePdu::getPadding1() const
{
    return _padding1;
}

void AttributePdu::setPadding1(int pX)
{
    _padding1 = pX;
}

short AttributePdu::getPadding2() const
{
    return _padding2;
}

void AttributePdu::setPadding2(short pX)
{
    _padding2 = pX;
}

unsigned char AttributePdu::getAttributeRecordPduType() const
{
    return _attributeRecordPduType;
}

void AttributePdu::setAttributeRecordPduType(unsigned char pX)
{
    _attributeRecordPduType = pX;
}

unsigned char AttributePdu::getAttributeRecordProtocolVersion() const
{
    return _attributeRecordProtocolVersion;
}

void AttributePdu::setAttributeRecordProtocolVersion(unsigned char pX)
{
    _attributeRecordProtocolVersion = pX;
}

unsigned int AttributePdu::getMasterAttributeRecordType() const
{
    return _masterAttributeRecordType;
}

void AttributePdu::setMasterAttributeRecordType(unsigned int pX)
{
    _masterAttributeRecordType = pX;
}

unsigned char AttributePdu::getActionCode() const
{
    return _actionCode;
}

void AttributePdu::setActionCode(unsigned char pX)
{
    _actionCode = pX;
}

char AttributePdu::getPadding3() const
{
    return _padding3;
}

void AttributePdu::setPadding3(char pX)
{
    _padding3 = pX;
}

unsigned short AttributePdu::getNumberAttributeRecordSet() const
{
    return _numberAttributeRecordSet;
}

void AttributePdu::setNumberAttributeRecordSet(unsigned short pX)
{
    _numberAttributeRecordSet = pX;
}

void AttributePdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _originatingSimulationAddress.marshal(dataStream);
    dataStream << _padding1;
    dataStream << _padding2;
    dataStream << _attributeRecordPduType;
    dataStream << _attributeRecordProtocolVersion;
    dataStream << _masterAttributeRecordType;
    dataStream << _actionCode;
    dataStream << _padding3;
    dataStream << _numberAttributeRecordSet;
}

void AttributePdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _originatingSimulationAddress.unmarshal(dataStream);
    dataStream >> _padding1;
    dataStream >> _padding2;
    dataStream >> _attributeRecordPduType;
    dataStream >> _attributeRecordProtocolVersion;
    dataStream >> _masterAttributeRecordType;
    dataStream >> _actionCode;
    dataStream >> _padding3;
    dataStream >> _numberAttributeRecordSet;
}


bool AttributePdu::operator ==(const AttributePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (_originatingSimulationAddress == rhs._originatingSimulationAddress) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;
     if( ! (_attributeRecordPduType == rhs._attributeRecordPduType) ) ivarsEqual = false;
     if( ! (_attributeRecordProtocolVersion == rhs._attributeRecordProtocolVersion) ) ivarsEqual = false;
     if( ! (_masterAttributeRecordType == rhs._masterAttributeRecordType) ) ivarsEqual = false;
     if( ! (_actionCode == rhs._actionCode) ) ivarsEqual = false;
     if( ! (_padding3 == rhs._padding3) ) ivarsEqual = false;
     if( ! (_numberAttributeRecordSet == rhs._numberAttributeRecordSet) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AttributePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _originatingSimulationAddress.getMarshalledSize();  // _originatingSimulationAddress
   marshalSize = marshalSize + 4;  // _padding1
   marshalSize = marshalSize + 2;  // _padding2
   marshalSize = marshalSize + 1;  // _attributeRecordPduType
   marshalSize = marshalSize + 1;  // _attributeRecordProtocolVersion
   marshalSize = marshalSize + 4;  // _masterAttributeRecordType
   marshalSize = marshalSize + 1;  // _actionCode
   marshalSize = marshalSize + 1;  // _padding3
   marshalSize = marshalSize + 2;  // _numberAttributeRecordSet
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
