#include <DIS/StandardVariableSpecification.h> 

using namespace DIS;


StandardVariableSpecification::StandardVariableSpecification():
   _numberOfStandardVariableRecords(0)
{
}

StandardVariableSpecification::~StandardVariableSpecification()
{
    _standardVariables.clear();
}

unsigned short StandardVariableSpecification::getNumberOfStandardVariableRecords() const
{
   return _standardVariables.size();
}

std::vector<SimulationManagementPduHeader>& StandardVariableSpecification::getStandardVariables() 
{
    return _standardVariables;
}

const std::vector<SimulationManagementPduHeader>& StandardVariableSpecification::getStandardVariables() const
{
    return _standardVariables;
}

void StandardVariableSpecification::setStandardVariables(const std::vector<SimulationManagementPduHeader>& pX)
{
     _standardVariables = pX;
}

void StandardVariableSpecification::marshal(DataStream& dataStream) const
{
    dataStream << ( unsigned short )_standardVariables.size();

     for(size_t idx = 0; idx < _standardVariables.size(); idx++)
     {
        SimulationManagementPduHeader x = _standardVariables[idx];
        x.marshal(dataStream);
     }

}

void StandardVariableSpecification::unmarshal(DataStream& dataStream)
{
    dataStream >> _numberOfStandardVariableRecords;

     _standardVariables.clear();
     for(size_t idx = 0; idx < _numberOfStandardVariableRecords; idx++)
     {
        SimulationManagementPduHeader x;
        x.unmarshal(dataStream);
        _standardVariables.push_back(x);
     }
}


bool StandardVariableSpecification::operator ==(const StandardVariableSpecification& rhs) const
 {
     bool ivarsEqual = true;


     for(size_t idx = 0; idx < _standardVariables.size(); idx++)
     {
        if( ! ( _standardVariables[idx] == rhs._standardVariables[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int StandardVariableSpecification::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _numberOfStandardVariableRecords

   for(int idx=0; idx < _standardVariables.size(); idx++)
   {
        SimulationManagementPduHeader listElement = _standardVariables[idx];
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
