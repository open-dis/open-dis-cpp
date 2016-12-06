#include <DIS/CollisionElasticPdu.h> 

using namespace DIS;


CollisionElasticPdu::CollisionElasticPdu() : EntityInformationFamilyPdu(),
   _issuingEntityID(), 
   _collidingEntityID(), 
   _collisionEventID(), 
   _pad(0), 
   _contactVelocity(), 
   _mass(0.0), 
   _location(), 
   _collisionResultXX(0.0), 
   _collisionResultXY(0.0), 
   _collisionResultXZ(0.0), 
   _collisionResultYY(0.0), 
   _collisionResultYZ(0.0), 
   _collisionResultZZ(0.0), 
   _unitSurfaceNormal(), 
   _coefficientOfRestitution(0.0)
{
    setPduType( 66 );
    setProtocolFamily( 1 );
}

CollisionElasticPdu::~CollisionElasticPdu()
{
}

EntityID& CollisionElasticPdu::getIssuingEntityID() 
{
    return _issuingEntityID;
}

const EntityID& CollisionElasticPdu::getIssuingEntityID() const
{
    return _issuingEntityID;
}

void CollisionElasticPdu::setIssuingEntityID(const EntityID &pX)
{
    _issuingEntityID = pX;
}

EntityID& CollisionElasticPdu::getCollidingEntityID() 
{
    return _collidingEntityID;
}

const EntityID& CollisionElasticPdu::getCollidingEntityID() const
{
    return _collidingEntityID;
}

void CollisionElasticPdu::setCollidingEntityID(const EntityID &pX)
{
    _collidingEntityID = pX;
}

EventID& CollisionElasticPdu::getCollisionEventID() 
{
    return _collisionEventID;
}

const EventID& CollisionElasticPdu::getCollisionEventID() const
{
    return _collisionEventID;
}

void CollisionElasticPdu::setCollisionEventID(const EventID &pX)
{
    _collisionEventID = pX;
}

short CollisionElasticPdu::getPad() const
{
    return _pad;
}

void CollisionElasticPdu::setPad(short pX)
{
    _pad = pX;
}

Vector3Float& CollisionElasticPdu::getContactVelocity() 
{
    return _contactVelocity;
}

const Vector3Float& CollisionElasticPdu::getContactVelocity() const
{
    return _contactVelocity;
}

void CollisionElasticPdu::setContactVelocity(const Vector3Float &pX)
{
    _contactVelocity = pX;
}

float CollisionElasticPdu::getMass() const
{
    return _mass;
}

void CollisionElasticPdu::setMass(float pX)
{
    _mass = pX;
}

Vector3Float& CollisionElasticPdu::getLocation() 
{
    return _location;
}

const Vector3Float& CollisionElasticPdu::getLocation() const
{
    return _location;
}

void CollisionElasticPdu::setLocation(const Vector3Float &pX)
{
    _location = pX;
}

float CollisionElasticPdu::getCollisionResultXX() const
{
    return _collisionResultXX;
}

void CollisionElasticPdu::setCollisionResultXX(float pX)
{
    _collisionResultXX = pX;
}

float CollisionElasticPdu::getCollisionResultXY() const
{
    return _collisionResultXY;
}

void CollisionElasticPdu::setCollisionResultXY(float pX)
{
    _collisionResultXY = pX;
}

float CollisionElasticPdu::getCollisionResultXZ() const
{
    return _collisionResultXZ;
}

void CollisionElasticPdu::setCollisionResultXZ(float pX)
{
    _collisionResultXZ = pX;
}

float CollisionElasticPdu::getCollisionResultYY() const
{
    return _collisionResultYY;
}

void CollisionElasticPdu::setCollisionResultYY(float pX)
{
    _collisionResultYY = pX;
}

float CollisionElasticPdu::getCollisionResultYZ() const
{
    return _collisionResultYZ;
}

void CollisionElasticPdu::setCollisionResultYZ(float pX)
{
    _collisionResultYZ = pX;
}

float CollisionElasticPdu::getCollisionResultZZ() const
{
    return _collisionResultZZ;
}

void CollisionElasticPdu::setCollisionResultZZ(float pX)
{
    _collisionResultZZ = pX;
}

Vector3Float& CollisionElasticPdu::getUnitSurfaceNormal() 
{
    return _unitSurfaceNormal;
}

const Vector3Float& CollisionElasticPdu::getUnitSurfaceNormal() const
{
    return _unitSurfaceNormal;
}

void CollisionElasticPdu::setUnitSurfaceNormal(const Vector3Float &pX)
{
    _unitSurfaceNormal = pX;
}

float CollisionElasticPdu::getCoefficientOfRestitution() const
{
    return _coefficientOfRestitution;
}

void CollisionElasticPdu::setCoefficientOfRestitution(float pX)
{
    _coefficientOfRestitution = pX;
}

void CollisionElasticPdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _issuingEntityID.marshal(dataStream);
    _collidingEntityID.marshal(dataStream);
    _collisionEventID.marshal(dataStream);
    dataStream << _pad;
    _contactVelocity.marshal(dataStream);
    dataStream << _mass;
    _location.marshal(dataStream);
    dataStream << _collisionResultXX;
    dataStream << _collisionResultXY;
    dataStream << _collisionResultXZ;
    dataStream << _collisionResultYY;
    dataStream << _collisionResultYZ;
    dataStream << _collisionResultZZ;
    _unitSurfaceNormal.marshal(dataStream);
    dataStream << _coefficientOfRestitution;
}

void CollisionElasticPdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _issuingEntityID.unmarshal(dataStream);
    _collidingEntityID.unmarshal(dataStream);
    _collisionEventID.unmarshal(dataStream);
    dataStream >> _pad;
    _contactVelocity.unmarshal(dataStream);
    dataStream >> _mass;
    _location.unmarshal(dataStream);
    dataStream >> _collisionResultXX;
    dataStream >> _collisionResultXY;
    dataStream >> _collisionResultXZ;
    dataStream >> _collisionResultYY;
    dataStream >> _collisionResultYZ;
    dataStream >> _collisionResultZZ;
    _unitSurfaceNormal.unmarshal(dataStream);
    dataStream >> _coefficientOfRestitution;
}


bool CollisionElasticPdu::operator ==(const CollisionElasticPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (_issuingEntityID == rhs._issuingEntityID) ) ivarsEqual = false;
     if( ! (_collidingEntityID == rhs._collidingEntityID) ) ivarsEqual = false;
     if( ! (_collisionEventID == rhs._collisionEventID) ) ivarsEqual = false;
     if( ! (_pad == rhs._pad) ) ivarsEqual = false;
     if( ! (_contactVelocity == rhs._contactVelocity) ) ivarsEqual = false;
     if( ! (_mass == rhs._mass) ) ivarsEqual = false;
     if( ! (_location == rhs._location) ) ivarsEqual = false;
     if( ! (_collisionResultXX == rhs._collisionResultXX) ) ivarsEqual = false;
     if( ! (_collisionResultXY == rhs._collisionResultXY) ) ivarsEqual = false;
     if( ! (_collisionResultXZ == rhs._collisionResultXZ) ) ivarsEqual = false;
     if( ! (_collisionResultYY == rhs._collisionResultYY) ) ivarsEqual = false;
     if( ! (_collisionResultYZ == rhs._collisionResultYZ) ) ivarsEqual = false;
     if( ! (_collisionResultZZ == rhs._collisionResultZZ) ) ivarsEqual = false;
     if( ! (_unitSurfaceNormal == rhs._unitSurfaceNormal) ) ivarsEqual = false;
     if( ! (_coefficientOfRestitution == rhs._coefficientOfRestitution) ) ivarsEqual = false;

    return ivarsEqual;
 }

int CollisionElasticPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _issuingEntityID.getMarshalledSize();  // _issuingEntityID
   marshalSize = marshalSize + _collidingEntityID.getMarshalledSize();  // _collidingEntityID
   marshalSize = marshalSize + _collisionEventID.getMarshalledSize();  // _collisionEventID
   marshalSize = marshalSize + 2;  // _pad
   marshalSize = marshalSize + _contactVelocity.getMarshalledSize();  // _contactVelocity
   marshalSize = marshalSize + 4;  // _mass
   marshalSize = marshalSize + _location.getMarshalledSize();  // _location
   marshalSize = marshalSize + 4;  // _collisionResultXX
   marshalSize = marshalSize + 4;  // _collisionResultXY
   marshalSize = marshalSize + 4;  // _collisionResultXZ
   marshalSize = marshalSize + 4;  // _collisionResultYY
   marshalSize = marshalSize + 4;  // _collisionResultYZ
   marshalSize = marshalSize + 4;  // _collisionResultZZ
   marshalSize = marshalSize + _unitSurfaceNormal.getMarshalledSize();  // _unitSurfaceNormal
   marshalSize = marshalSize + 4;  // _coefficientOfRestitution
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
