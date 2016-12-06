#include <DIS/SimulationAddress.h> 

using namespace DIS;


SimulationAddress::SimulationAddress():
   _site(0), 
   _application(0)
{
}

SimulationAddress::~SimulationAddress()
{
}

unsigned short SimulationAddress::getSite() const
{
    return _site;
}

void SimulationAddress::setSite(unsigned short pX)
{
    _site = pX;
}

unsigned short SimulationAddress::getApplication() const
{
    return _application;
}

void SimulationAddress::setApplication(unsigned short pX)
{
    _application = pX;
}

void SimulationAddress::marshal(DataStream& dataStream) const
{
    dataStream << _site;
    dataStream << _application;
}

void SimulationAddress::unmarshal(DataStream& dataStream)
{
    dataStream >> _site;
    dataStream >> _application;
}


bool SimulationAddress::operator ==(const SimulationAddress& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_site == rhs._site) ) ivarsEqual = false;
     if( ! (_application == rhs._application) ) ivarsEqual = false;

    return ivarsEqual;
 }

int SimulationAddress::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _site
   marshalSize = marshalSize + 2;  // _application
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
