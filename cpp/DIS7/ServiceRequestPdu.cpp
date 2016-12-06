#include <DIS/ServiceRequestPdu.h> 

using namespace DIS;


ServiceRequestPdu::ServiceRequestPdu() : LogisticsFamilyPdu(),
   _requestingEntityID(), 
   _servicingEntityID(), 
   _serviceTypeRequested(0), 
   _numberOfSupplyTypes(0), 
   _serviceRequestPadding(0)
{
    setPduType( 5 );
}

ServiceRequestPdu::~ServiceRequestPdu()
{
    _supplies.clear();
}

EntityID& ServiceRequestPdu::getRequestingEntityID() 
{
    return _requestingEntityID;
}

const EntityID& ServiceRequestPdu::getRequestingEntityID() const
{
    return _requestingEntityID;
}

void ServiceRequestPdu::setRequestingEntityID(const EntityID &pX)
{
    _requestingEntityID = pX;
}

EntityID& ServiceRequestPdu::getServicingEntityID() 
{
    return _servicingEntityID;
}

const EntityID& ServiceRequestPdu::getServicingEntityID() const
{
    return _servicingEntityID;
}

void ServiceRequestPdu::setServicingEntityID(const EntityID &pX)
{
    _servicingEntityID = pX;
}

unsigned char ServiceRequestPdu::getServiceTypeRequested() const
{
    return _serviceTypeRequested;
}

void ServiceRequestPdu::setServiceTypeRequested(unsigned char pX)
{
    _serviceTypeRequested = pX;
}

unsigned char ServiceRequestPdu::getNumberOfSupplyTypes() const
{
   return _supplies.size();
}

short ServiceRequestPdu::getServiceRequestPadding() const
{
    return _serviceRequestPadding;
}

void ServiceRequestPdu::setServiceRequestPadding(short pX)
{
    _serviceRequestPadding = pX;
}

std::vector<SupplyQuantity>& ServiceRequestPdu::getSupplies() 
{
    return _supplies;
}

const std::vector<SupplyQuantity>& ServiceRequestPdu::getSupplies() const
{
    return _supplies;
}

void ServiceRequestPdu::setSupplies(const std::vector<SupplyQuantity>& pX)
{
     _supplies = pX;
}

void ServiceRequestPdu::marshal(DataStream& dataStream) const
{
    LogisticsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _requestingEntityID.marshal(dataStream);
    _servicingEntityID.marshal(dataStream);
    dataStream << _serviceTypeRequested;
    dataStream << ( unsigned char )_supplies.size();
    dataStream << _serviceRequestPadding;

     for(size_t idx = 0; idx < _supplies.size(); idx++)
     {
        SupplyQuantity x = _supplies[idx];
        x.marshal(dataStream);
     }

}

void ServiceRequestPdu::unmarshal(DataStream& dataStream)
{
    LogisticsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _requestingEntityID.unmarshal(dataStream);
    _servicingEntityID.unmarshal(dataStream);
    dataStream >> _serviceTypeRequested;
    dataStream >> _numberOfSupplyTypes;
    dataStream >> _serviceRequestPadding;

     _supplies.clear();
     for(size_t idx = 0; idx < _numberOfSupplyTypes; idx++)
     {
        SupplyQuantity x;
        x.unmarshal(dataStream);
        _supplies.push_back(x);
     }
}


bool ServiceRequestPdu::operator ==(const ServiceRequestPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = LogisticsFamilyPdu::operator==(rhs);

     if( ! (_requestingEntityID == rhs._requestingEntityID) ) ivarsEqual = false;
     if( ! (_servicingEntityID == rhs._servicingEntityID) ) ivarsEqual = false;
     if( ! (_serviceTypeRequested == rhs._serviceTypeRequested) ) ivarsEqual = false;
     if( ! (_serviceRequestPadding == rhs._serviceRequestPadding) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _supplies.size(); idx++)
     {
        if( ! ( _supplies[idx] == rhs._supplies[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ServiceRequestPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = LogisticsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _requestingEntityID.getMarshalledSize();  // _requestingEntityID
   marshalSize = marshalSize + _servicingEntityID.getMarshalledSize();  // _servicingEntityID
   marshalSize = marshalSize + 1;  // _serviceTypeRequested
   marshalSize = marshalSize + 1;  // _numberOfSupplyTypes
   marshalSize = marshalSize + 2;  // _serviceRequestPadding

   for(int idx=0; idx < _supplies.size(); idx++)
   {
        SupplyQuantity listElement = _supplies[idx];
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
