#include <DIS/AcousticEmitter.h> 

using namespace DIS;


AcousticEmitter::AcousticEmitter():
   _acousticName(0), 
   _function(0), 
   _acousticIdNumber(0)
{
}

AcousticEmitter::~AcousticEmitter()
{
}

unsigned short AcousticEmitter::getAcousticName() const
{
    return _acousticName;
}

void AcousticEmitter::setAcousticName(unsigned short pX)
{
    _acousticName = pX;
}

unsigned char AcousticEmitter::getFunction() const
{
    return _function;
}

void AcousticEmitter::setFunction(unsigned char pX)
{
    _function = pX;
}

unsigned char AcousticEmitter::getAcousticIdNumber() const
{
    return _acousticIdNumber;
}

void AcousticEmitter::setAcousticIdNumber(unsigned char pX)
{
    _acousticIdNumber = pX;
}

void AcousticEmitter::marshal(DataStream& dataStream) const
{
    dataStream << _acousticName;
    dataStream << _function;
    dataStream << _acousticIdNumber;
}

void AcousticEmitter::unmarshal(DataStream& dataStream)
{
    dataStream >> _acousticName;
    dataStream >> _function;
    dataStream >> _acousticIdNumber;
}


bool AcousticEmitter::operator ==(const AcousticEmitter& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_acousticName == rhs._acousticName) ) ivarsEqual = false;
     if( ! (_function == rhs._function) ) ivarsEqual = false;
     if( ! (_acousticIdNumber == rhs._acousticIdNumber) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AcousticEmitter::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _acousticName
   marshalSize = marshalSize + 1;  // _function
   marshalSize = marshalSize + 1;  // _acousticIdNumber
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
