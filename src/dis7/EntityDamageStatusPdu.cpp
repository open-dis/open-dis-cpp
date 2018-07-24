#include <DIS/EntityDamageStatusPdu.h> 

using namespace DIS;


EntityDamageStatusPdu::EntityDamageStatusPdu() : WarfareFamilyPdu(),
   _damagedEntityID(), 
   _padding1(0), 
   _padding2(0), 
   _numberOfDamageDescription(0)
{
    setPduType( 69 );
}

EntityDamageStatusPdu::~EntityDamageStatusPdu()
{
    _damageDescriptionRecords.clear();
}

EntityID& EntityDamageStatusPdu::getDamagedEntityID() 
{
    return _damagedEntityID;
}

const EntityID& EntityDamageStatusPdu::getDamagedEntityID() const
{
    return _damagedEntityID;
}

void EntityDamageStatusPdu::setDamagedEntityID(const EntityID &pX)
{
    _damagedEntityID = pX;
}

unsigned short EntityDamageStatusPdu::getPadding1() const
{
    return _padding1;
}

void EntityDamageStatusPdu::setPadding1(unsigned short pX)
{
    _padding1 = pX;
}

unsigned short EntityDamageStatusPdu::getPadding2() const
{
    return _padding2;
}

void EntityDamageStatusPdu::setPadding2(unsigned short pX)
{
    _padding2 = pX;
}

unsigned short EntityDamageStatusPdu::getNumberOfDamageDescription() const
{
   return _damageDescriptionRecords.size();
}

std::vector<DirectedEnergyDamage>& EntityDamageStatusPdu::getDamageDescriptionRecords() 
{
    return _damageDescriptionRecords;
}

const std::vector<DirectedEnergyDamage>& EntityDamageStatusPdu::getDamageDescriptionRecords() const
{
    return _damageDescriptionRecords;
}

void EntityDamageStatusPdu::setDamageDescriptionRecords(const std::vector<DirectedEnergyDamage>& pX)
{
     _damageDescriptionRecords = pX;
}

void EntityDamageStatusPdu::marshal(DataStream& dataStream) const
{
    WarfareFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _damagedEntityID.marshal(dataStream);
    dataStream << _padding1;
    dataStream << _padding2;
    dataStream << ( unsigned short )_damageDescriptionRecords.size();

     for(size_t idx = 0; idx < _damageDescriptionRecords.size(); idx++)
     {
        DirectedEnergyDamage x = _damageDescriptionRecords[idx];
        x.marshal(dataStream);
     }

}

void EntityDamageStatusPdu::unmarshal(DataStream& dataStream)
{
    WarfareFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _damagedEntityID.unmarshal(dataStream);
    dataStream >> _padding1;
    dataStream >> _padding2;
    dataStream >> _numberOfDamageDescription;

     _damageDescriptionRecords.clear();
     for(size_t idx = 0; idx < _numberOfDamageDescription; idx++)
     {
        DirectedEnergyDamage x;
        x.unmarshal(dataStream);
        _damageDescriptionRecords.push_back(x);
     }
}


bool EntityDamageStatusPdu::operator ==(const EntityDamageStatusPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = WarfareFamilyPdu::operator==(rhs);

     if( ! (_damagedEntityID == rhs._damagedEntityID) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _damageDescriptionRecords.size(); idx++)
     {
        if( ! ( _damageDescriptionRecords[idx] == rhs._damageDescriptionRecords[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int EntityDamageStatusPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = WarfareFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _damagedEntityID.getMarshalledSize();  // _damagedEntityID
   marshalSize = marshalSize + 2;  // _padding1
   marshalSize = marshalSize + 2;  // _padding2
   marshalSize = marshalSize + 2;  // _numberOfDamageDescription

   for(int idx=0; idx < _damageDescriptionRecords.size(); idx++)
   {
        DirectedEnergyDamage listElement = _damageDescriptionRecords[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

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
