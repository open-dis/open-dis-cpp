#include <DIS/SystemIdentifier.h> 

using namespace DIS;


SystemIdentifier::SystemIdentifier():
   _systemType(0), 
   _systemName(0), 
   _systemMode(0), 
   _changeOptions()
{
}

SystemIdentifier::~SystemIdentifier()
{
}

unsigned short SystemIdentifier::getSystemType() const
{
    return _systemType;
}

void SystemIdentifier::setSystemType(unsigned short pX)
{
    _systemType = pX;
}

unsigned short SystemIdentifier::getSystemName() const
{
    return _systemName;
}

void SystemIdentifier::setSystemName(unsigned short pX)
{
    _systemName = pX;
}

unsigned short SystemIdentifier::getSystemMode() const
{
    return _systemMode;
}

void SystemIdentifier::setSystemMode(unsigned short pX)
{
    _systemMode = pX;
}

ChangeOptions& SystemIdentifier::getChangeOptions() 
{
    return _changeOptions;
}

const ChangeOptions& SystemIdentifier::getChangeOptions() const
{
    return _changeOptions;
}

void SystemIdentifier::setChangeOptions(const ChangeOptions &pX)
{
    _changeOptions = pX;
}

void SystemIdentifier::marshal(DataStream& dataStream) const
{
    dataStream << _systemType;
    dataStream << _systemName;
    dataStream << _systemMode;
    _changeOptions.marshal(dataStream);
}

void SystemIdentifier::unmarshal(DataStream& dataStream)
{
    dataStream >> _systemType;
    dataStream >> _systemName;
    dataStream >> _systemMode;
    _changeOptions.unmarshal(dataStream);
}


bool SystemIdentifier::operator ==(const SystemIdentifier& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_systemType == rhs._systemType) ) ivarsEqual = false;
     if( ! (_systemName == rhs._systemName) ) ivarsEqual = false;
     if( ! (_systemMode == rhs._systemMode) ) ivarsEqual = false;
     if( ! (_changeOptions == rhs._changeOptions) ) ivarsEqual = false;

    return ivarsEqual;
 }

int SystemIdentifier::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _systemType
   marshalSize = marshalSize + 2;  // _systemName
   marshalSize = marshalSize + 2;  // _systemMode
   marshalSize = marshalSize + _changeOptions.getMarshalledSize();  // _changeOptions
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
