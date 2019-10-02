#include <dis6/IsGroupOfPdu.h>

using namespace DIS;


IsGroupOfPdu::IsGroupOfPdu() : EntityManagementFamilyPdu(),
   _groupEntityID(), 
   _groupedEntityCategory(0), 
   _numberOfGroupedEntities(0), 
   _pad2(0), 
   _latitude(0.0), 
   _longitude(0.0)
{
    setPduType( 34 );
}

IsGroupOfPdu::~IsGroupOfPdu()
{
    _groupedEntityDescriptions.clear();
}

EntityID& IsGroupOfPdu::getGroupEntityID() 
{
    return _groupEntityID;
}

const EntityID& IsGroupOfPdu::getGroupEntityID() const
{
    return _groupEntityID;
}

void IsGroupOfPdu::setGroupEntityID(const EntityID &pX)
{
    _groupEntityID = pX;
}

unsigned char IsGroupOfPdu::getGroupedEntityCategory() const
{
    return _groupedEntityCategory;
}

void IsGroupOfPdu::setGroupedEntityCategory(unsigned char pX)
{
    _groupedEntityCategory = pX;
}

unsigned char IsGroupOfPdu::getNumberOfGroupedEntities() const
{
   return _groupedEntityDescriptions.size();
}

unsigned int IsGroupOfPdu::getPad2() const
{
    return _pad2;
}

void IsGroupOfPdu::setPad2(unsigned int pX)
{
    _pad2 = pX;
}

double IsGroupOfPdu::getLatitude() const
{
    return _latitude;
}

void IsGroupOfPdu::setLatitude(double pX)
{
    _latitude = pX;
}

double IsGroupOfPdu::getLongitude() const
{
    return _longitude;
}

void IsGroupOfPdu::setLongitude(double pX)
{
    _longitude = pX;
}

std::vector<VariableDatum>& IsGroupOfPdu::getGroupedEntityDescriptions() 
{
    return _groupedEntityDescriptions;
}

const std::vector<VariableDatum>& IsGroupOfPdu::getGroupedEntityDescriptions() const
{
    return _groupedEntityDescriptions;
}

void IsGroupOfPdu::setGroupedEntityDescriptions(const std::vector<VariableDatum>& pX)
{
     _groupedEntityDescriptions = pX;
}

void IsGroupOfPdu::marshal(DataStream& dataStream) const
{
    EntityManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _groupEntityID.marshal(dataStream);
    dataStream << _groupedEntityCategory;
    dataStream << ( unsigned char )_groupedEntityDescriptions.size();
    dataStream << _pad2;
    dataStream << _latitude;
    dataStream << _longitude;

     for(size_t idx = 0; idx < _groupedEntityDescriptions.size(); idx++)
     {
        VariableDatum x = _groupedEntityDescriptions[idx];
        x.marshal(dataStream);
     }

}

void IsGroupOfPdu::unmarshal(DataStream& dataStream)
{
    EntityManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _groupEntityID.unmarshal(dataStream);
    dataStream >> _groupedEntityCategory;
    dataStream >> _numberOfGroupedEntities;
    dataStream >> _pad2;
    dataStream >> _latitude;
    dataStream >> _longitude;

     _groupedEntityDescriptions.clear();
     for(size_t idx = 0; idx < _numberOfGroupedEntities; idx++)
     {
        VariableDatum x;
        x.unmarshal(dataStream);
        _groupedEntityDescriptions.push_back(x);
     }
}


bool IsGroupOfPdu::operator ==(const IsGroupOfPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityManagementFamilyPdu::operator==(rhs);

     if( ! (_groupEntityID == rhs._groupEntityID) ) ivarsEqual = false;
     if( ! (_groupedEntityCategory == rhs._groupedEntityCategory) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_latitude == rhs._latitude) ) ivarsEqual = false;
     if( ! (_longitude == rhs._longitude) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _groupedEntityDescriptions.size(); idx++)
     {
        if( ! ( _groupedEntityDescriptions[idx] == rhs._groupedEntityDescriptions[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int IsGroupOfPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _groupEntityID.getMarshalledSize();  // _groupEntityID
   marshalSize = marshalSize + 1;  // _groupedEntityCategory
   marshalSize = marshalSize + 1;  // _numberOfGroupedEntities
   marshalSize = marshalSize + 4;  // _pad2
   marshalSize = marshalSize + 8;  // _latitude
   marshalSize = marshalSize + 8;  // _longitude

   for(unsigned long long idx=0; idx < _groupedEntityDescriptions.size(); idx++)
   {
        VariableDatum listElement = _groupedEntityDescriptions[idx];
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
