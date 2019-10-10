#include <dis6/AggregateStatePdu.h>

using namespace DIS;


AggregateStatePdu::AggregateStatePdu() : EntityManagementFamilyPdu(),
   _aggregateID(), 
   _forceID(0), 
   _aggregateState(0), 
   _aggregateType(), 
   _formation(0), 
   _aggregateMarking(), 
   _dimensions(), 
   _orientation(), 
   _centerOfMass(), 
   _velocity(), 
   _numberOfDisAggregates(0), 
   _numberOfDisEntities(0), 
   _numberOfSilentAggregateTypes(0), 
   _numberOfSilentEntityTypes(0), 
   _pad2(0), 
   _numberOfVariableDatumRecords(0)
{
    setPduType( 33 );
}

AggregateStatePdu::~AggregateStatePdu()
{
    _aggregateIDList.clear();
    _entityIDList.clear();
    _silentAggregateSystemList.clear();
    _silentEntitySystemList.clear();
    _variableDatumList.clear();
}

EntityID& AggregateStatePdu::getAggregateID() 
{
    return _aggregateID;
}

const EntityID& AggregateStatePdu::getAggregateID() const
{
    return _aggregateID;
}

void AggregateStatePdu::setAggregateID(const EntityID &pX)
{
    _aggregateID = pX;
}

unsigned char AggregateStatePdu::getForceID() const
{
    return _forceID;
}

void AggregateStatePdu::setForceID(unsigned char pX)
{
    _forceID = pX;
}

unsigned char AggregateStatePdu::getAggregateState() const
{
    return _aggregateState;
}

void AggregateStatePdu::setAggregateState(unsigned char pX)
{
    _aggregateState = pX;
}

EntityType& AggregateStatePdu::getAggregateType() 
{
    return _aggregateType;
}

const EntityType& AggregateStatePdu::getAggregateType() const
{
    return _aggregateType;
}

void AggregateStatePdu::setAggregateType(const EntityType &pX)
{
    _aggregateType = pX;
}

unsigned int AggregateStatePdu::getFormation() const
{
    return _formation;
}

void AggregateStatePdu::setFormation(unsigned int pX)
{
    _formation = pX;
}

AggregateMarking& AggregateStatePdu::getAggregateMarking() 
{
    return _aggregateMarking;
}

const AggregateMarking& AggregateStatePdu::getAggregateMarking() const
{
    return _aggregateMarking;
}

void AggregateStatePdu::setAggregateMarking(const AggregateMarking &pX)
{
    _aggregateMarking = pX;
}

Vector3Float& AggregateStatePdu::getDimensions() 
{
    return _dimensions;
}

const Vector3Float& AggregateStatePdu::getDimensions() const
{
    return _dimensions;
}

void AggregateStatePdu::setDimensions(const Vector3Float &pX)
{
    _dimensions = pX;
}

Orientation& AggregateStatePdu::getOrientation() 
{
    return _orientation;
}

const Orientation& AggregateStatePdu::getOrientation() const
{
    return _orientation;
}

void AggregateStatePdu::setOrientation(const Orientation &pX)
{
    _orientation = pX;
}

Vector3Double& AggregateStatePdu::getCenterOfMass() 
{
    return _centerOfMass;
}

const Vector3Double& AggregateStatePdu::getCenterOfMass() const
{
    return _centerOfMass;
}

void AggregateStatePdu::setCenterOfMass(const Vector3Double &pX)
{
    _centerOfMass = pX;
}

Vector3Float& AggregateStatePdu::getVelocity() 
{
    return _velocity;
}

const Vector3Float& AggregateStatePdu::getVelocity() const
{
    return _velocity;
}

void AggregateStatePdu::setVelocity(const Vector3Float &pX)
{
    _velocity = pX;
}

unsigned short AggregateStatePdu::getNumberOfDisAggregates() const
{
   return _aggregateIDList.size();
}

unsigned short AggregateStatePdu::getNumberOfDisEntities() const
{
   return _entityIDList.size();
}

unsigned short AggregateStatePdu::getNumberOfSilentAggregateTypes() const
{
   return _silentAggregateSystemList.size();
}

unsigned short AggregateStatePdu::getNumberOfSilentEntityTypes() const
{
   return _silentEntitySystemList.size();
}

std::vector<AggregateID>& AggregateStatePdu::getAggregateIDList() 
{
    return _aggregateIDList;
}

const std::vector<AggregateID>& AggregateStatePdu::getAggregateIDList() const
{
    return _aggregateIDList;
}

void AggregateStatePdu::setAggregateIDList(const std::vector<AggregateID>& pX)
{
     _aggregateIDList = pX;
}

std::vector<EntityID>& AggregateStatePdu::getEntityIDList() 
{
    return _entityIDList;
}

const std::vector<EntityID>& AggregateStatePdu::getEntityIDList() const
{
    return _entityIDList;
}

void AggregateStatePdu::setEntityIDList(const std::vector<EntityID>& pX)
{
     _entityIDList = pX;
}

unsigned char AggregateStatePdu::getPad2() const
{
    return _pad2;
}

void AggregateStatePdu::setPad2(unsigned char pX)
{
    _pad2 = pX;
}

std::vector<EntityType>& AggregateStatePdu::getSilentAggregateSystemList() 
{
    return _silentAggregateSystemList;
}

const std::vector<EntityType>& AggregateStatePdu::getSilentAggregateSystemList() const
{
    return _silentAggregateSystemList;
}

void AggregateStatePdu::setSilentAggregateSystemList(const std::vector<EntityType>& pX)
{
     _silentAggregateSystemList = pX;
}

std::vector<EntityType>& AggregateStatePdu::getSilentEntitySystemList() 
{
    return _silentEntitySystemList;
}

const std::vector<EntityType>& AggregateStatePdu::getSilentEntitySystemList() const
{
    return _silentEntitySystemList;
}

void AggregateStatePdu::setSilentEntitySystemList(const std::vector<EntityType>& pX)
{
     _silentEntitySystemList = pX;
}

unsigned int AggregateStatePdu::getNumberOfVariableDatumRecords() const
{
   return _variableDatumList.size();
}

std::vector<VariableDatum>& AggregateStatePdu::getVariableDatumList() 
{
    return _variableDatumList;
}

const std::vector<VariableDatum>& AggregateStatePdu::getVariableDatumList() const
{
    return _variableDatumList;
}

void AggregateStatePdu::setVariableDatumList(const std::vector<VariableDatum>& pX)
{
     _variableDatumList = pX;
}

void AggregateStatePdu::marshal(DataStream& dataStream) const
{
    EntityManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _aggregateID.marshal(dataStream);
    dataStream << _forceID;
    dataStream << _aggregateState;
    _aggregateType.marshal(dataStream);
    dataStream << _formation;
    _aggregateMarking.marshal(dataStream);
    _dimensions.marshal(dataStream);
    _orientation.marshal(dataStream);
    _centerOfMass.marshal(dataStream);
    _velocity.marshal(dataStream);
    dataStream << ( unsigned short )_aggregateIDList.size();
    dataStream << ( unsigned short )_entityIDList.size();
    dataStream << ( unsigned short )_silentAggregateSystemList.size();
    dataStream << ( unsigned short )_silentEntitySystemList.size();

     for(size_t idx = 0; idx < _aggregateIDList.size(); idx++)
     {
        AggregateID x = _aggregateIDList[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < _entityIDList.size(); idx++)
     {
        EntityID x = _entityIDList[idx];
        x.marshal(dataStream);
     }

    dataStream << _pad2;

     for(size_t idx = 0; idx < _silentAggregateSystemList.size(); idx++)
     {
        EntityType x = _silentAggregateSystemList[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < _silentEntitySystemList.size(); idx++)
     {
        EntityType x = _silentEntitySystemList[idx];
        x.marshal(dataStream);
     }

    dataStream << ( unsigned int )_variableDatumList.size();

     for(size_t idx = 0; idx < _variableDatumList.size(); idx++)
     {
        VariableDatum x = _variableDatumList[idx];
        x.marshal(dataStream);
     }

}

void AggregateStatePdu::unmarshal(DataStream& dataStream)
{
    EntityManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _aggregateID.unmarshal(dataStream);
    dataStream >> _forceID;
    dataStream >> _aggregateState;
    _aggregateType.unmarshal(dataStream);
    dataStream >> _formation;
    _aggregateMarking.unmarshal(dataStream);
    _dimensions.unmarshal(dataStream);
    _orientation.unmarshal(dataStream);
    _centerOfMass.unmarshal(dataStream);
    _velocity.unmarshal(dataStream);
    dataStream >> _numberOfDisAggregates;
    dataStream >> _numberOfDisEntities;
    dataStream >> _numberOfSilentAggregateTypes;
    dataStream >> _numberOfSilentEntityTypes;

     _aggregateIDList.clear();
     for(size_t idx = 0; idx < _numberOfDisAggregates; idx++)
     {
        AggregateID x;
        x.unmarshal(dataStream);
        _aggregateIDList.push_back(x);
     }

     _entityIDList.clear();
     for(size_t idx = 0; idx < _numberOfDisEntities; idx++)
     {
        EntityID x;
        x.unmarshal(dataStream);
        _entityIDList.push_back(x);
     }
    dataStream >> _pad2;

     _silentAggregateSystemList.clear();
     for(size_t idx = 0; idx < _numberOfSilentAggregateTypes; idx++)
     {
        EntityType x;
        x.unmarshal(dataStream);
        _silentAggregateSystemList.push_back(x);
     }

     _silentEntitySystemList.clear();
     for(size_t idx = 0; idx < _numberOfSilentEntityTypes; idx++)
     {
        EntityType x;
        x.unmarshal(dataStream);
        _silentEntitySystemList.push_back(x);
     }
    dataStream >> _numberOfVariableDatumRecords;

     _variableDatumList.clear();
     for(size_t idx = 0; idx < _numberOfVariableDatumRecords; idx++)
     {
        VariableDatum x;
        x.unmarshal(dataStream);
        _variableDatumList.push_back(x);
     }
}


bool AggregateStatePdu::operator ==(const AggregateStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityManagementFamilyPdu::operator==(rhs);

     if( ! (_aggregateID == rhs._aggregateID) ) ivarsEqual = false;
     if( ! (_forceID == rhs._forceID) ) ivarsEqual = false;
     if( ! (_aggregateState == rhs._aggregateState) ) ivarsEqual = false;
     if( ! (_aggregateType == rhs._aggregateType) ) ivarsEqual = false;
     if( ! (_formation == rhs._formation) ) ivarsEqual = false;
     if( ! (_aggregateMarking == rhs._aggregateMarking) ) ivarsEqual = false;
     if( ! (_dimensions == rhs._dimensions) ) ivarsEqual = false;
     if( ! (_orientation == rhs._orientation) ) ivarsEqual = false;
     if( ! (_centerOfMass == rhs._centerOfMass) ) ivarsEqual = false;
     if( ! (_velocity == rhs._velocity) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _aggregateIDList.size(); idx++)
     {
        if( ! ( _aggregateIDList[idx] == rhs._aggregateIDList[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < _entityIDList.size(); idx++)
     {
        if( ! ( _entityIDList[idx] == rhs._entityIDList[idx]) ) ivarsEqual = false;
     }

     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _silentAggregateSystemList.size(); idx++)
     {
        if( ! ( _silentAggregateSystemList[idx] == rhs._silentAggregateSystemList[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < _silentEntitySystemList.size(); idx++)
     {
        if( ! ( _silentEntitySystemList[idx] == rhs._silentEntitySystemList[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < _variableDatumList.size(); idx++)
     {
        if( ! ( _variableDatumList[idx] == rhs._variableDatumList[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int AggregateStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _aggregateID.getMarshalledSize();  // _aggregateID
   marshalSize = marshalSize + 1;  // _forceID
   marshalSize = marshalSize + 1;  // _aggregateState
   marshalSize = marshalSize + _aggregateType.getMarshalledSize();  // _aggregateType
   marshalSize = marshalSize + 4;  // _formation
   marshalSize = marshalSize + _aggregateMarking.getMarshalledSize();  // _aggregateMarking
   marshalSize = marshalSize + _dimensions.getMarshalledSize();  // _dimensions
   marshalSize = marshalSize + _orientation.getMarshalledSize();  // _orientation
   marshalSize = marshalSize + _centerOfMass.getMarshalledSize();  // _centerOfMass
   marshalSize = marshalSize + _velocity.getMarshalledSize();  // _velocity
   marshalSize = marshalSize + 2;  // _numberOfDisAggregates
   marshalSize = marshalSize + 2;  // _numberOfDisEntities
   marshalSize = marshalSize + 2;  // _numberOfSilentAggregateTypes
   marshalSize = marshalSize + 2;  // _numberOfSilentEntityTypes

   for(unsigned long long idx=0; idx < _aggregateIDList.size(); idx++)
   {
        AggregateID listElement = _aggregateIDList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(unsigned long long idx=0; idx < _entityIDList.size(); idx++)
   {
        EntityID listElement = _entityIDList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

   marshalSize = marshalSize + 1;  // _pad2

   for(unsigned long long idx=0; idx < _silentAggregateSystemList.size(); idx++)
   {
        EntityType listElement = _silentAggregateSystemList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(unsigned long long idx=0; idx < _silentEntitySystemList.size(); idx++)
   {
        EntityType listElement = _silentEntitySystemList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

   marshalSize = marshalSize + 4;  // _numberOfVariableDatumRecords

   for(unsigned long long idx=0; idx < _variableDatumList.size(); idx++)
   {
        VariableDatum listElement = _variableDatumList[idx];
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
