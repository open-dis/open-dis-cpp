#include <DIS/ArealObjectStatePdu.h> 

using namespace DIS;


ArealObjectStatePdu::ArealObjectStatePdu() : SyntheticEnvironmentFamilyPdu(),
   _objectID(), 
   _referencedObjectID(), 
   _updateNumber(0), 
   _forceID(0), 
   _modifications(0), 
   _objectType(), 
   _specificObjectAppearance(0), 
   _generalObjectAppearance(0), 
   _numberOfPoints(0), 
   _requesterID(), 
   _receivingID()
{
    setPduType( 45 );
}

ArealObjectStatePdu::~ArealObjectStatePdu()
{
    _objectLocation.clear();
}

EntityID& ArealObjectStatePdu::getObjectID() 
{
    return _objectID;
}

const EntityID& ArealObjectStatePdu::getObjectID() const
{
    return _objectID;
}

void ArealObjectStatePdu::setObjectID(const EntityID &pX)
{
    _objectID = pX;
}

EntityID& ArealObjectStatePdu::getReferencedObjectID() 
{
    return _referencedObjectID;
}

const EntityID& ArealObjectStatePdu::getReferencedObjectID() const
{
    return _referencedObjectID;
}

void ArealObjectStatePdu::setReferencedObjectID(const EntityID &pX)
{
    _referencedObjectID = pX;
}

unsigned short ArealObjectStatePdu::getUpdateNumber() const
{
    return _updateNumber;
}

void ArealObjectStatePdu::setUpdateNumber(unsigned short pX)
{
    _updateNumber = pX;
}

unsigned char ArealObjectStatePdu::getForceID() const
{
    return _forceID;
}

void ArealObjectStatePdu::setForceID(unsigned char pX)
{
    _forceID = pX;
}

unsigned char ArealObjectStatePdu::getModifications() const
{
    return _modifications;
}

void ArealObjectStatePdu::setModifications(unsigned char pX)
{
    _modifications = pX;
}

EntityType& ArealObjectStatePdu::getObjectType() 
{
    return _objectType;
}

const EntityType& ArealObjectStatePdu::getObjectType() const
{
    return _objectType;
}

void ArealObjectStatePdu::setObjectType(const EntityType &pX)
{
    _objectType = pX;
}

unsigned int ArealObjectStatePdu::getSpecificObjectAppearance() const
{
    return _specificObjectAppearance;
}

void ArealObjectStatePdu::setSpecificObjectAppearance(unsigned int pX)
{
    _specificObjectAppearance = pX;
}

unsigned short ArealObjectStatePdu::getGeneralObjectAppearance() const
{
    return _generalObjectAppearance;
}

void ArealObjectStatePdu::setGeneralObjectAppearance(unsigned short pX)
{
    _generalObjectAppearance = pX;
}

unsigned short ArealObjectStatePdu::getNumberOfPoints() const
{
   return _objectLocation.size();
}

SimulationAddress& ArealObjectStatePdu::getRequesterID() 
{
    return _requesterID;
}

const SimulationAddress& ArealObjectStatePdu::getRequesterID() const
{
    return _requesterID;
}

void ArealObjectStatePdu::setRequesterID(const SimulationAddress &pX)
{
    _requesterID = pX;
}

SimulationAddress& ArealObjectStatePdu::getReceivingID() 
{
    return _receivingID;
}

const SimulationAddress& ArealObjectStatePdu::getReceivingID() const
{
    return _receivingID;
}

void ArealObjectStatePdu::setReceivingID(const SimulationAddress &pX)
{
    _receivingID = pX;
}

std::vector<Vector3Double>& ArealObjectStatePdu::getObjectLocation() 
{
    return _objectLocation;
}

const std::vector<Vector3Double>& ArealObjectStatePdu::getObjectLocation() const
{
    return _objectLocation;
}

void ArealObjectStatePdu::setObjectLocation(const std::vector<Vector3Double>& pX)
{
     _objectLocation = pX;
}

void ArealObjectStatePdu::marshal(DataStream& dataStream) const
{
    SyntheticEnvironmentFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _objectID.marshal(dataStream);
    _referencedObjectID.marshal(dataStream);
    dataStream << _updateNumber;
    dataStream << _forceID;
    dataStream << _modifications;
    _objectType.marshal(dataStream);
    dataStream << _specificObjectAppearance;
    dataStream << _generalObjectAppearance;
    dataStream << ( unsigned short )_objectLocation.size();
    _requesterID.marshal(dataStream);
    _receivingID.marshal(dataStream);

     for(size_t idx = 0; idx < _objectLocation.size(); idx++)
     {
        Vector3Double x = _objectLocation[idx];
        x.marshal(dataStream);
     }

}

void ArealObjectStatePdu::unmarshal(DataStream& dataStream)
{
    SyntheticEnvironmentFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _objectID.unmarshal(dataStream);
    _referencedObjectID.unmarshal(dataStream);
    dataStream >> _updateNumber;
    dataStream >> _forceID;
    dataStream >> _modifications;
    _objectType.unmarshal(dataStream);
    dataStream >> _specificObjectAppearance;
    dataStream >> _generalObjectAppearance;
    dataStream >> _numberOfPoints;
    _requesterID.unmarshal(dataStream);
    _receivingID.unmarshal(dataStream);

     _objectLocation.clear();
     for(size_t idx = 0; idx < _numberOfPoints; idx++)
     {
        Vector3Double x;
        x.unmarshal(dataStream);
        _objectLocation.push_back(x);
     }
}


bool ArealObjectStatePdu::operator ==(const ArealObjectStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SyntheticEnvironmentFamilyPdu::operator==(rhs);

     if( ! (_objectID == rhs._objectID) ) ivarsEqual = false;
     if( ! (_referencedObjectID == rhs._referencedObjectID) ) ivarsEqual = false;
     if( ! (_updateNumber == rhs._updateNumber) ) ivarsEqual = false;
     if( ! (_forceID == rhs._forceID) ) ivarsEqual = false;
     if( ! (_modifications == rhs._modifications) ) ivarsEqual = false;
     if( ! (_objectType == rhs._objectType) ) ivarsEqual = false;
     if( ! (_specificObjectAppearance == rhs._specificObjectAppearance) ) ivarsEqual = false;
     if( ! (_generalObjectAppearance == rhs._generalObjectAppearance) ) ivarsEqual = false;
     if( ! (_requesterID == rhs._requesterID) ) ivarsEqual = false;
     if( ! (_receivingID == rhs._receivingID) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _objectLocation.size(); idx++)
     {
        if( ! ( _objectLocation[idx] == rhs._objectLocation[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ArealObjectStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SyntheticEnvironmentFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _objectID.getMarshalledSize();  // _objectID
   marshalSize = marshalSize + _referencedObjectID.getMarshalledSize();  // _referencedObjectID
   marshalSize = marshalSize + 2;  // _updateNumber
   marshalSize = marshalSize + 1;  // _forceID
   marshalSize = marshalSize + 1;  // _modifications
   marshalSize = marshalSize + _objectType.getMarshalledSize();  // _objectType
   marshalSize = marshalSize + 4;  // _specificObjectAppearance
   marshalSize = marshalSize + 2;  // _generalObjectAppearance
   marshalSize = marshalSize + 2;  // _numberOfPoints
   marshalSize = marshalSize + _requesterID.getMarshalledSize();  // _requesterID
   marshalSize = marshalSize + _receivingID.getMarshalledSize();  // _receivingID

   for(int idx=0; idx < _objectLocation.size(); idx++)
   {
        Vector3Double listElement = _objectLocation[idx];
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
