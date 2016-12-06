#include <DIS/RadioEntityType.h> 

using namespace DIS;


RadioEntityType::RadioEntityType():
   _entityKind(0), 
   _domain(0), 
   _country(0), 
   _category(0), 
   _nomenclatureVersion(0), 
   _nomenclature(0)
{
}

RadioEntityType::~RadioEntityType()
{
}

unsigned char RadioEntityType::getEntityKind() const
{
    return _entityKind;
}

void RadioEntityType::setEntityKind(unsigned char pX)
{
    _entityKind = pX;
}

unsigned char RadioEntityType::getDomain() const
{
    return _domain;
}

void RadioEntityType::setDomain(unsigned char pX)
{
    _domain = pX;
}

unsigned short RadioEntityType::getCountry() const
{
    return _country;
}

void RadioEntityType::setCountry(unsigned short pX)
{
    _country = pX;
}

unsigned char RadioEntityType::getCategory() const
{
    return _category;
}

void RadioEntityType::setCategory(unsigned char pX)
{
    _category = pX;
}

unsigned char RadioEntityType::getNomenclatureVersion() const
{
    return _nomenclatureVersion;
}

void RadioEntityType::setNomenclatureVersion(unsigned char pX)
{
    _nomenclatureVersion = pX;
}

unsigned short RadioEntityType::getNomenclature() const
{
    return _nomenclature;
}

void RadioEntityType::setNomenclature(unsigned short pX)
{
    _nomenclature = pX;
}

void RadioEntityType::marshal(DataStream& dataStream) const
{
    dataStream << _entityKind;
    dataStream << _domain;
    dataStream << _country;
    dataStream << _category;
    dataStream << _nomenclatureVersion;
    dataStream << _nomenclature;
}

void RadioEntityType::unmarshal(DataStream& dataStream)
{
    dataStream >> _entityKind;
    dataStream >> _domain;
    dataStream >> _country;
    dataStream >> _category;
    dataStream >> _nomenclatureVersion;
    dataStream >> _nomenclature;
}


bool RadioEntityType::operator ==(const RadioEntityType& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_entityKind == rhs._entityKind) ) ivarsEqual = false;
     if( ! (_domain == rhs._domain) ) ivarsEqual = false;
     if( ! (_country == rhs._country) ) ivarsEqual = false;
     if( ! (_category == rhs._category) ) ivarsEqual = false;
     if( ! (_nomenclatureVersion == rhs._nomenclatureVersion) ) ivarsEqual = false;
     if( ! (_nomenclature == rhs._nomenclature) ) ivarsEqual = false;

    return ivarsEqual;
 }

int RadioEntityType::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _entityKind
   marshalSize = marshalSize + 1;  // _domain
   marshalSize = marshalSize + 2;  // _country
   marshalSize = marshalSize + 1;  // _category
   marshalSize = marshalSize + 1;  // _nomenclatureVersion
   marshalSize = marshalSize + 2;  // _nomenclature
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
