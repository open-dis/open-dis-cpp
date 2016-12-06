#include <DIS/DataQueryDatumSpecification.h> 

using namespace DIS;


DataQueryDatumSpecification::DataQueryDatumSpecification():
   _numberOfFixedDatums(0), 
   _numberOfVariableDatums(0)
{
}

DataQueryDatumSpecification::~DataQueryDatumSpecification()
{
    _fixedDatumIDList.clear();
    _variableDatumIDList.clear();
}

unsigned int DataQueryDatumSpecification::getNumberOfFixedDatums() const
{
   return _fixedDatumIDList.size();
}

unsigned int DataQueryDatumSpecification::getNumberOfVariableDatums() const
{
   return _variableDatumIDList.size();
}

std::vector<UnsignedDISInteger>& DataQueryDatumSpecification::getFixedDatumIDList() 
{
    return _fixedDatumIDList;
}

const std::vector<UnsignedDISInteger>& DataQueryDatumSpecification::getFixedDatumIDList() const
{
    return _fixedDatumIDList;
}

void DataQueryDatumSpecification::setFixedDatumIDList(const std::vector<UnsignedDISInteger>& pX)
{
     _fixedDatumIDList = pX;
}

std::vector<UnsignedDISInteger>& DataQueryDatumSpecification::getVariableDatumIDList() 
{
    return _variableDatumIDList;
}

const std::vector<UnsignedDISInteger>& DataQueryDatumSpecification::getVariableDatumIDList() const
{
    return _variableDatumIDList;
}

void DataQueryDatumSpecification::setVariableDatumIDList(const std::vector<UnsignedDISInteger>& pX)
{
     _variableDatumIDList = pX;
}

void DataQueryDatumSpecification::marshal(DataStream& dataStream) const
{
    dataStream << ( unsigned int )_fixedDatumIDList.size();
    dataStream << ( unsigned int )_variableDatumIDList.size();

     for(size_t idx = 0; idx < _fixedDatumIDList.size(); idx++)
     {
        UnsignedDISInteger x = _fixedDatumIDList[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < _variableDatumIDList.size(); idx++)
     {
        UnsignedDISInteger x = _variableDatumIDList[idx];
        x.marshal(dataStream);
     }

}

void DataQueryDatumSpecification::unmarshal(DataStream& dataStream)
{
    dataStream >> _numberOfFixedDatums;
    dataStream >> _numberOfVariableDatums;

     _fixedDatumIDList.clear();
     for(size_t idx = 0; idx < _numberOfFixedDatums; idx++)
     {
        UnsignedDISInteger x;
        x.unmarshal(dataStream);
        _fixedDatumIDList.push_back(x);
     }

     _variableDatumIDList.clear();
     for(size_t idx = 0; idx < _numberOfVariableDatums; idx++)
     {
        UnsignedDISInteger x;
        x.unmarshal(dataStream);
        _variableDatumIDList.push_back(x);
     }
}


bool DataQueryDatumSpecification::operator ==(const DataQueryDatumSpecification& rhs) const
 {
     bool ivarsEqual = true;


     for(size_t idx = 0; idx < _fixedDatumIDList.size(); idx++)
     {
        if( ! ( _fixedDatumIDList[idx] == rhs._fixedDatumIDList[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < _variableDatumIDList.size(); idx++)
     {
        if( ! ( _variableDatumIDList[idx] == rhs._variableDatumIDList[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int DataQueryDatumSpecification::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _numberOfFixedDatums
   marshalSize = marshalSize + 4;  // _numberOfVariableDatums

   for(int idx=0; idx < _fixedDatumIDList.size(); idx++)
   {
        UnsignedDISInteger listElement = _fixedDatumIDList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < _variableDatumIDList.size(); idx++)
   {
        UnsignedDISInteger listElement = _variableDatumIDList[idx];
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
