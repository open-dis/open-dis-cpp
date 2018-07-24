#include <DIS/AcousticBeamData.h> 

using namespace DIS;


AcousticBeamData::AcousticBeamData():
   _beamDataLength(0), 
   _beamIDNumber(0), 
   _pad2(0), 
   _fundamentalDataParameters()
{
}

AcousticBeamData::~AcousticBeamData()
{
}

unsigned short AcousticBeamData::getBeamDataLength() const
{
    return _beamDataLength;
}

void AcousticBeamData::setBeamDataLength(unsigned short pX)
{
    _beamDataLength = pX;
}

unsigned char AcousticBeamData::getBeamIDNumber() const
{
    return _beamIDNumber;
}

void AcousticBeamData::setBeamIDNumber(unsigned char pX)
{
    _beamIDNumber = pX;
}

unsigned short AcousticBeamData::getPad2() const
{
    return _pad2;
}

void AcousticBeamData::setPad2(unsigned short pX)
{
    _pad2 = pX;
}

AcousticBeamFundamentalParameter& AcousticBeamData::getFundamentalDataParameters() 
{
    return _fundamentalDataParameters;
}

const AcousticBeamFundamentalParameter& AcousticBeamData::getFundamentalDataParameters() const
{
    return _fundamentalDataParameters;
}

void AcousticBeamData::setFundamentalDataParameters(const AcousticBeamFundamentalParameter &pX)
{
    _fundamentalDataParameters = pX;
}

void AcousticBeamData::marshal(DataStream& dataStream) const
{
    dataStream << _beamDataLength;
    dataStream << _beamIDNumber;
    dataStream << _pad2;
    _fundamentalDataParameters.marshal(dataStream);
}

void AcousticBeamData::unmarshal(DataStream& dataStream)
{
    dataStream >> _beamDataLength;
    dataStream >> _beamIDNumber;
    dataStream >> _pad2;
    _fundamentalDataParameters.unmarshal(dataStream);
}


bool AcousticBeamData::operator ==(const AcousticBeamData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_beamDataLength == rhs._beamDataLength) ) ivarsEqual = false;
     if( ! (_beamIDNumber == rhs._beamIDNumber) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_fundamentalDataParameters == rhs._fundamentalDataParameters) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AcousticBeamData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _beamDataLength
   marshalSize = marshalSize + 1;  // _beamIDNumber
   marshalSize = marshalSize + 2;  // _pad2
   marshalSize = marshalSize + _fundamentalDataParameters.getMarshalledSize();  // _fundamentalDataParameters
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
