#include <dis6/ElectronicEmissionsPdu.h>

using namespace DIS;


ElectronicEmissionsPdu::ElectronicEmissionsPdu() : DistributedEmissionsFamilyPdu(),
   _emittingEntityID(), 
   _eventID(), 
   _stateUpdateIndicator(0), 
   _numberOfSystems(0), 
   _paddingForEmissionsPdu(0)
{
    setPduType( 23 );
    setPaddingForEmissionsPdu( 0 );
}

ElectronicEmissionsPdu::~ElectronicEmissionsPdu()
{
    _systems.clear();
}

EntityID& ElectronicEmissionsPdu::getEmittingEntityID() 
{
    return _emittingEntityID;
}

const EntityID& ElectronicEmissionsPdu::getEmittingEntityID() const
{
    return _emittingEntityID;
}

void ElectronicEmissionsPdu::setEmittingEntityID(const EntityID &pX)
{
    _emittingEntityID = pX;
}

EventID& ElectronicEmissionsPdu::getEventID() 
{
    return _eventID;
}

const EventID& ElectronicEmissionsPdu::getEventID() const
{
    return _eventID;
}

void ElectronicEmissionsPdu::setEventID(const EventID &pX)
{
    _eventID = pX;
}

unsigned char ElectronicEmissionsPdu::getStateUpdateIndicator() const
{
    return _stateUpdateIndicator;
}

void ElectronicEmissionsPdu::setStateUpdateIndicator(unsigned char pX)
{
    _stateUpdateIndicator = pX;
}

unsigned char ElectronicEmissionsPdu::getNumberOfSystems() const
{
   return _systems.size();
}

unsigned short ElectronicEmissionsPdu::getPaddingForEmissionsPdu() const
{
    return _paddingForEmissionsPdu;
}

void ElectronicEmissionsPdu::setPaddingForEmissionsPdu(unsigned short pX)
{
    _paddingForEmissionsPdu = pX;
}

std::vector<ElectronicEmissionSystemData>& ElectronicEmissionsPdu::getSystems() 
{
    return _systems;
}

const std::vector<ElectronicEmissionSystemData>& ElectronicEmissionsPdu::getSystems() const
{
    return _systems;
}

void ElectronicEmissionsPdu::setSystems(const std::vector<ElectronicEmissionSystemData>& pX)
{
     _systems = pX;
}

void ElectronicEmissionsPdu::marshal(DataStream& dataStream) const
{
    DistributedEmissionsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _emittingEntityID.marshal(dataStream);
    _eventID.marshal(dataStream);
    dataStream << _stateUpdateIndicator;
    dataStream << ( unsigned char )_systems.size();
    dataStream << _paddingForEmissionsPdu;

     for(size_t idx = 0; idx < _systems.size(); idx++)
     {
        ElectronicEmissionSystemData x = _systems[idx];
        x.marshal(dataStream);
     }

}

void ElectronicEmissionsPdu::unmarshal(DataStream& dataStream)
{
    DistributedEmissionsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _emittingEntityID.unmarshal(dataStream);
    _eventID.unmarshal(dataStream);
    dataStream >> _stateUpdateIndicator;
    dataStream >> _numberOfSystems;
    dataStream >> _paddingForEmissionsPdu;

     _systems.clear();
     for(size_t idx = 0; idx < _numberOfSystems; idx++)
     {
        ElectronicEmissionSystemData x;
        x.unmarshal(dataStream);
        _systems.push_back(x);
     }
}


bool ElectronicEmissionsPdu::operator ==(const ElectronicEmissionsPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

     if( ! (_emittingEntityID == rhs._emittingEntityID) ) ivarsEqual = false;
     if( ! (_eventID == rhs._eventID) ) ivarsEqual = false;
     if( ! (_stateUpdateIndicator == rhs._stateUpdateIndicator) ) ivarsEqual = false;
     if( ! (_paddingForEmissionsPdu == rhs._paddingForEmissionsPdu) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _systems.size(); idx++)
     {
        if( ! ( _systems[idx] == rhs._systems[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ElectronicEmissionsPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _emittingEntityID.getMarshalledSize();  // _emittingEntityID
   marshalSize = marshalSize + _eventID.getMarshalledSize();  // _eventID
   marshalSize = marshalSize + 1;  // _stateUpdateIndicator
   marshalSize = marshalSize + 1;  // _numberOfSystems
   marshalSize = marshalSize + 2;  // _paddingForEmissionsPdu

   for(int idx=0; idx < _systems.size(); idx++)
   {
        ElectronicEmissionSystemData listElement = _systems[idx];
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
