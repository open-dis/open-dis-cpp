#include <dis6/IffAtcNavAidsLayer2Pdu.h>

using namespace DIS;


IffAtcNavAidsLayer2Pdu::IffAtcNavAidsLayer2Pdu() : IffAtcNavAidsLayer1Pdu(),
   _layerHeader(), 
   _beamData(), 
   _secondaryOperationalData()
{
}

IffAtcNavAidsLayer2Pdu::~IffAtcNavAidsLayer2Pdu()
{
    _fundamentalIffParameters.clear();
}

LayerHeader& IffAtcNavAidsLayer2Pdu::getLayerHeader() 
{
    return _layerHeader;
}

const LayerHeader& IffAtcNavAidsLayer2Pdu::getLayerHeader() const
{
    return _layerHeader;
}

void IffAtcNavAidsLayer2Pdu::setLayerHeader(const LayerHeader &pX)
{
    _layerHeader = pX;
}

BeamData& IffAtcNavAidsLayer2Pdu::getBeamData() 
{
    return _beamData;
}

const BeamData& IffAtcNavAidsLayer2Pdu::getBeamData() const
{
    return _beamData;
}

void IffAtcNavAidsLayer2Pdu::setBeamData(const BeamData &pX)
{
    _beamData = pX;
}

BeamData& IffAtcNavAidsLayer2Pdu::getSecondaryOperationalData() 
{
    return _secondaryOperationalData;
}

const BeamData& IffAtcNavAidsLayer2Pdu::getSecondaryOperationalData() const
{
    return _secondaryOperationalData;
}

void IffAtcNavAidsLayer2Pdu::setSecondaryOperationalData(const BeamData &pX)
{
    _secondaryOperationalData = pX;
}

std::vector<FundamentalParameterDataIff>& IffAtcNavAidsLayer2Pdu::getFundamentalIffParameters() 
{
    return _fundamentalIffParameters;
}

const std::vector<FundamentalParameterDataIff>& IffAtcNavAidsLayer2Pdu::getFundamentalIffParameters() const
{
    return _fundamentalIffParameters;
}

void IffAtcNavAidsLayer2Pdu::setFundamentalIffParameters(const std::vector<FundamentalParameterDataIff>& pX)
{
     _fundamentalIffParameters = pX;
}

void IffAtcNavAidsLayer2Pdu::marshal(DataStream& dataStream) const
{
    IffAtcNavAidsLayer1Pdu::marshal(dataStream); // Marshal information in superclass first
    _layerHeader.marshal(dataStream);
    _beamData.marshal(dataStream);
    _secondaryOperationalData.marshal(dataStream);

     for(size_t idx = 0; idx < _fundamentalIffParameters.size(); idx++)
     {
        FundamentalParameterDataIff x = _fundamentalIffParameters[idx];
        x.marshal(dataStream);
     }

}

void IffAtcNavAidsLayer2Pdu::unmarshal(DataStream& dataStream)
{
    IffAtcNavAidsLayer1Pdu::unmarshal(dataStream); // unmarshal information in superclass first
    _layerHeader.unmarshal(dataStream);
    _beamData.unmarshal(dataStream);
    _secondaryOperationalData.unmarshal(dataStream);

     _fundamentalIffParameters.clear();
     for(size_t idx = 0; idx < _pad2; idx++)
     {
        FundamentalParameterDataIff x;
        x.unmarshal(dataStream);
        _fundamentalIffParameters.push_back(x);
     }
}


bool IffAtcNavAidsLayer2Pdu::operator ==(const IffAtcNavAidsLayer2Pdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = IffAtcNavAidsLayer1Pdu::operator==(rhs);

     if( ! (_layerHeader == rhs._layerHeader) ) ivarsEqual = false;
     if( ! (_beamData == rhs._beamData) ) ivarsEqual = false;
     if( ! (_secondaryOperationalData == rhs._secondaryOperationalData) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _fundamentalIffParameters.size(); idx++)
     {
        if( ! ( _fundamentalIffParameters[idx] == rhs._fundamentalIffParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int IffAtcNavAidsLayer2Pdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = IffAtcNavAidsLayer1Pdu::getMarshalledSize();
   marshalSize = marshalSize + _layerHeader.getMarshalledSize();  // _layerHeader
   marshalSize = marshalSize + _beamData.getMarshalledSize();  // _beamData
   marshalSize = marshalSize + _secondaryOperationalData.getMarshalledSize();  // _secondaryOperationalData

   for(unsigned long long idx=0; idx < _fundamentalIffParameters.size(); idx++)
   {
        FundamentalParameterDataIff listElement = _fundamentalIffParameters[idx];
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
