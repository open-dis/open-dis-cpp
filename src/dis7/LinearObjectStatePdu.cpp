#include <DIS/LinearObjectStatePdu.h> 

using namespace DIS;


LinearObjectStatePdu::LinearObjectStatePdu() : SyntheticEnvironmentFamilyPdu(),
   _objectID(), 
   _referencedObjectID(), 
   _updateNumber(0), 
   _forceID(0), 
   _numberOfSegments(0), 
   _requesterID(), 
   _receivingID(), 
   _objectType()
{
    setPduType( 44 );
}

LinearObjectStatePdu::~LinearObjectStatePdu()
{
    _linearSegmentParameters.clear();
}

EntityID& LinearObjectStatePdu::getObjectID() 
{
    return _objectID;
}

const EntityID& LinearObjectStatePdu::getObjectID() const
{
    return _objectID;
}

void LinearObjectStatePdu::setObjectID(const EntityID &pX)
{
    _objectID = pX;
}

EntityID& LinearObjectStatePdu::getReferencedObjectID() 
{
    return _referencedObjectID;
}

const EntityID& LinearObjectStatePdu::getReferencedObjectID() const
{
    return _referencedObjectID;
}

void LinearObjectStatePdu::setReferencedObjectID(const EntityID &pX)
{
    _referencedObjectID = pX;
}

unsigned short LinearObjectStatePdu::getUpdateNumber() const
{
    return _updateNumber;
}

void LinearObjectStatePdu::setUpdateNumber(unsigned short pX)
{
    _updateNumber = pX;
}

unsigned char LinearObjectStatePdu::getForceID() const
{
    return _forceID;
}

void LinearObjectStatePdu::setForceID(unsigned char pX)
{
    _forceID = pX;
}

unsigned char LinearObjectStatePdu::getNumberOfSegments() const
{
   return _linearSegmentParameters.size();
}

SimulationAddress& LinearObjectStatePdu::getRequesterID() 
{
    return _requesterID;
}

const SimulationAddress& LinearObjectStatePdu::getRequesterID() const
{
    return _requesterID;
}

void LinearObjectStatePdu::setRequesterID(const SimulationAddress &pX)
{
    _requesterID = pX;
}

SimulationAddress& LinearObjectStatePdu::getReceivingID() 
{
    return _receivingID;
}

const SimulationAddress& LinearObjectStatePdu::getReceivingID() const
{
    return _receivingID;
}

void LinearObjectStatePdu::setReceivingID(const SimulationAddress &pX)
{
    _receivingID = pX;
}

ObjectType& LinearObjectStatePdu::getObjectType() 
{
    return _objectType;
}

const ObjectType& LinearObjectStatePdu::getObjectType() const
{
    return _objectType;
}

void LinearObjectStatePdu::setObjectType(const ObjectType &pX)
{
    _objectType = pX;
}

std::vector<LinearSegmentParameter>& LinearObjectStatePdu::getLinearSegmentParameters() 
{
    return _linearSegmentParameters;
}

const std::vector<LinearSegmentParameter>& LinearObjectStatePdu::getLinearSegmentParameters() const
{
    return _linearSegmentParameters;
}

void LinearObjectStatePdu::setLinearSegmentParameters(const std::vector<LinearSegmentParameter>& pX)
{
     _linearSegmentParameters = pX;
}

void LinearObjectStatePdu::marshal(DataStream& dataStream) const
{
    SyntheticEnvironmentFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _objectID.marshal(dataStream);
    _referencedObjectID.marshal(dataStream);
    dataStream << _updateNumber;
    dataStream << _forceID;
    dataStream << ( unsigned char )_linearSegmentParameters.size();
    _requesterID.marshal(dataStream);
    _receivingID.marshal(dataStream);
    _objectType.marshal(dataStream);

     for(size_t idx = 0; idx < _linearSegmentParameters.size(); idx++)
     {
        LinearSegmentParameter x = _linearSegmentParameters[idx];
        x.marshal(dataStream);
     }

}

void LinearObjectStatePdu::unmarshal(DataStream& dataStream)
{
    SyntheticEnvironmentFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _objectID.unmarshal(dataStream);
    _referencedObjectID.unmarshal(dataStream);
    dataStream >> _updateNumber;
    dataStream >> _forceID;
    dataStream >> _numberOfSegments;
    _requesterID.unmarshal(dataStream);
    _receivingID.unmarshal(dataStream);
    _objectType.unmarshal(dataStream);

     _linearSegmentParameters.clear();
     for(size_t idx = 0; idx < _numberOfSegments; idx++)
     {
        LinearSegmentParameter x;
        x.unmarshal(dataStream);
        _linearSegmentParameters.push_back(x);
     }
}


bool LinearObjectStatePdu::operator ==(const LinearObjectStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SyntheticEnvironmentFamilyPdu::operator==(rhs);

     if( ! (_objectID == rhs._objectID) ) ivarsEqual = false;
     if( ! (_referencedObjectID == rhs._referencedObjectID) ) ivarsEqual = false;
     if( ! (_updateNumber == rhs._updateNumber) ) ivarsEqual = false;
     if( ! (_forceID == rhs._forceID) ) ivarsEqual = false;
     if( ! (_requesterID == rhs._requesterID) ) ivarsEqual = false;
     if( ! (_receivingID == rhs._receivingID) ) ivarsEqual = false;
     if( ! (_objectType == rhs._objectType) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _linearSegmentParameters.size(); idx++)
     {
        if( ! ( _linearSegmentParameters[idx] == rhs._linearSegmentParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int LinearObjectStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SyntheticEnvironmentFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _objectID.getMarshalledSize();  // _objectID
   marshalSize = marshalSize + _referencedObjectID.getMarshalledSize();  // _referencedObjectID
   marshalSize = marshalSize + 2;  // _updateNumber
   marshalSize = marshalSize + 1;  // _forceID
   marshalSize = marshalSize + 1;  // _numberOfSegments
   marshalSize = marshalSize + _requesterID.getMarshalledSize();  // _requesterID
   marshalSize = marshalSize + _receivingID.getMarshalledSize();  // _receivingID
   marshalSize = marshalSize + _objectType.getMarshalledSize();  // _objectType

   for(int idx=0; idx < _linearSegmentParameters.size(); idx++)
   {
        LinearSegmentParameter listElement = _linearSegmentParameters[idx];
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
