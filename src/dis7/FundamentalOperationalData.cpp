#include <DIS/FundamentalOperationalData.h> 

using namespace DIS;


FundamentalOperationalData::FundamentalOperationalData():
   _systemStatus(0), 
   _dataField1(0), 
   _informationLayers(0), 
   _dataField2(0), 
   _parameter1(0), 
   _parameter2(0), 
   _parameter3(0), 
   _parameter4(0), 
   _parameter5(0), 
   _parameter6(0)
{
}

FundamentalOperationalData::~FundamentalOperationalData()
{
}

unsigned char FundamentalOperationalData::getSystemStatus() const
{
    return _systemStatus;
}

void FundamentalOperationalData::setSystemStatus(unsigned char pX)
{
    _systemStatus = pX;
}

unsigned char FundamentalOperationalData::getDataField1() const
{
    return _dataField1;
}

void FundamentalOperationalData::setDataField1(unsigned char pX)
{
    _dataField1 = pX;
}

unsigned char FundamentalOperationalData::getInformationLayers() const
{
    return _informationLayers;
}

void FundamentalOperationalData::setInformationLayers(unsigned char pX)
{
    _informationLayers = pX;
}

unsigned char FundamentalOperationalData::getDataField2() const
{
    return _dataField2;
}

void FundamentalOperationalData::setDataField2(unsigned char pX)
{
    _dataField2 = pX;
}

unsigned short FundamentalOperationalData::getParameter1() const
{
    return _parameter1;
}

void FundamentalOperationalData::setParameter1(unsigned short pX)
{
    _parameter1 = pX;
}

unsigned short FundamentalOperationalData::getParameter2() const
{
    return _parameter2;
}

void FundamentalOperationalData::setParameter2(unsigned short pX)
{
    _parameter2 = pX;
}

unsigned short FundamentalOperationalData::getParameter3() const
{
    return _parameter3;
}

void FundamentalOperationalData::setParameter3(unsigned short pX)
{
    _parameter3 = pX;
}

unsigned short FundamentalOperationalData::getParameter4() const
{
    return _parameter4;
}

void FundamentalOperationalData::setParameter4(unsigned short pX)
{
    _parameter4 = pX;
}

unsigned short FundamentalOperationalData::getParameter5() const
{
    return _parameter5;
}

void FundamentalOperationalData::setParameter5(unsigned short pX)
{
    _parameter5 = pX;
}

unsigned short FundamentalOperationalData::getParameter6() const
{
    return _parameter6;
}

void FundamentalOperationalData::setParameter6(unsigned short pX)
{
    _parameter6 = pX;
}

void FundamentalOperationalData::marshal(DataStream& dataStream) const
{
    dataStream << _systemStatus;
    dataStream << _dataField1;
    dataStream << _informationLayers;
    dataStream << _dataField2;
    dataStream << _parameter1;
    dataStream << _parameter2;
    dataStream << _parameter3;
    dataStream << _parameter4;
    dataStream << _parameter5;
    dataStream << _parameter6;
}

void FundamentalOperationalData::unmarshal(DataStream& dataStream)
{
    dataStream >> _systemStatus;
    dataStream >> _dataField1;
    dataStream >> _informationLayers;
    dataStream >> _dataField2;
    dataStream >> _parameter1;
    dataStream >> _parameter2;
    dataStream >> _parameter3;
    dataStream >> _parameter4;
    dataStream >> _parameter5;
    dataStream >> _parameter6;
}


bool FundamentalOperationalData::operator ==(const FundamentalOperationalData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_systemStatus == rhs._systemStatus) ) ivarsEqual = false;
     if( ! (_dataField1 == rhs._dataField1) ) ivarsEqual = false;
     if( ! (_informationLayers == rhs._informationLayers) ) ivarsEqual = false;
     if( ! (_dataField2 == rhs._dataField2) ) ivarsEqual = false;
     if( ! (_parameter1 == rhs._parameter1) ) ivarsEqual = false;
     if( ! (_parameter2 == rhs._parameter2) ) ivarsEqual = false;
     if( ! (_parameter3 == rhs._parameter3) ) ivarsEqual = false;
     if( ! (_parameter4 == rhs._parameter4) ) ivarsEqual = false;
     if( ! (_parameter5 == rhs._parameter5) ) ivarsEqual = false;
     if( ! (_parameter6 == rhs._parameter6) ) ivarsEqual = false;

    return ivarsEqual;
 }

int FundamentalOperationalData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _systemStatus
   marshalSize = marshalSize + 1;  // _dataField1
   marshalSize = marshalSize + 1;  // _informationLayers
   marshalSize = marshalSize + 1;  // _dataField2
   marshalSize = marshalSize + 2;  // _parameter1
   marshalSize = marshalSize + 2;  // _parameter2
   marshalSize = marshalSize + 2;  // _parameter3
   marshalSize = marshalSize + 2;  // _parameter4
   marshalSize = marshalSize + 2;  // _parameter5
   marshalSize = marshalSize + 2;  // _parameter6
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
