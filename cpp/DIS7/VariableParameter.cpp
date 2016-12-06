#include <DIS/VariableParameter.h> 

using namespace DIS;


VariableParameter::VariableParameter():
   _recordType(0), 
   _variableParameterFields1(0.0), 
   _variableParameterFields2(0), 
   _variableParameterFields3(0), 
   _variableParameterFields4(0)
{
}

VariableParameter::~VariableParameter()
{
}

unsigned char VariableParameter::getRecordType() const
{
    return _recordType;
}

void VariableParameter::setRecordType(unsigned char pX)
{
    _recordType = pX;
}

double VariableParameter::getVariableParameterFields1() const
{
    return _variableParameterFields1;
}

void VariableParameter::setVariableParameterFields1(double pX)
{
    _variableParameterFields1 = pX;
}

unsigned int VariableParameter::getVariableParameterFields2() const
{
    return _variableParameterFields2;
}

void VariableParameter::setVariableParameterFields2(unsigned int pX)
{
    _variableParameterFields2 = pX;
}

unsigned short VariableParameter::getVariableParameterFields3() const
{
    return _variableParameterFields3;
}

void VariableParameter::setVariableParameterFields3(unsigned short pX)
{
    _variableParameterFields3 = pX;
}

unsigned char VariableParameter::getVariableParameterFields4() const
{
    return _variableParameterFields4;
}

void VariableParameter::setVariableParameterFields4(unsigned char pX)
{
    _variableParameterFields4 = pX;
}

void VariableParameter::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _variableParameterFields1;
    dataStream << _variableParameterFields2;
    dataStream << _variableParameterFields3;
    dataStream << _variableParameterFields4;
}

void VariableParameter::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _variableParameterFields1;
    dataStream >> _variableParameterFields2;
    dataStream >> _variableParameterFields3;
    dataStream >> _variableParameterFields4;
}


bool VariableParameter::operator ==(const VariableParameter& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_variableParameterFields1 == rhs._variableParameterFields1) ) ivarsEqual = false;
     if( ! (_variableParameterFields2 == rhs._variableParameterFields2) ) ivarsEqual = false;
     if( ! (_variableParameterFields3 == rhs._variableParameterFields3) ) ivarsEqual = false;
     if( ! (_variableParameterFields4 == rhs._variableParameterFields4) ) ivarsEqual = false;

    return ivarsEqual;
 }

int VariableParameter::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _recordType
   marshalSize = marshalSize + 8;  // _variableParameterFields1
   marshalSize = marshalSize + 4;  // _variableParameterFields2
   marshalSize = marshalSize + 2;  // _variableParameterFields3
   marshalSize = marshalSize + 1;  // _variableParameterFields4
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
