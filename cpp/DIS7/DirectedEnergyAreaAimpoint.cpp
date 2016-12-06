#include <DIS/DirectedEnergyAreaAimpoint.h> 

using namespace DIS;


DirectedEnergyAreaAimpoint::DirectedEnergyAreaAimpoint():
   _recordType(4001), 
   _recordLength(0), 
   _padding(0), 
   _beamAntennaPatternRecordCount(0), 
   _directedEnergyTargetEnergyDepositionRecordCount(0)
{
}

DirectedEnergyAreaAimpoint::~DirectedEnergyAreaAimpoint()
{
    _beamAntennaParameterList.clear();
    _directedEnergyTargetEnergyDepositionRecordList.clear();
}

unsigned int DirectedEnergyAreaAimpoint::getRecordType() const
{
    return _recordType;
}

void DirectedEnergyAreaAimpoint::setRecordType(unsigned int pX)
{
    _recordType = pX;
}

unsigned short DirectedEnergyAreaAimpoint::getRecordLength() const
{
    return _recordLength;
}

void DirectedEnergyAreaAimpoint::setRecordLength(unsigned short pX)
{
    _recordLength = pX;
}

unsigned short DirectedEnergyAreaAimpoint::getPadding() const
{
    return _padding;
}

void DirectedEnergyAreaAimpoint::setPadding(unsigned short pX)
{
    _padding = pX;
}

unsigned short DirectedEnergyAreaAimpoint::getBeamAntennaPatternRecordCount() const
{
   return _beamAntennaParameterList.size();
}

unsigned short DirectedEnergyAreaAimpoint::getDirectedEnergyTargetEnergyDepositionRecordCount() const
{
   return _directedEnergyTargetEnergyDepositionRecordList.size();
}

std::vector<BeamAntennaPattern>& DirectedEnergyAreaAimpoint::getBeamAntennaParameterList() 
{
    return _beamAntennaParameterList;
}

const std::vector<BeamAntennaPattern>& DirectedEnergyAreaAimpoint::getBeamAntennaParameterList() const
{
    return _beamAntennaParameterList;
}

void DirectedEnergyAreaAimpoint::setBeamAntennaParameterList(const std::vector<BeamAntennaPattern>& pX)
{
     _beamAntennaParameterList = pX;
}

std::vector<DirectedEnergyTargetEnergyDeposition>& DirectedEnergyAreaAimpoint::getDirectedEnergyTargetEnergyDepositionRecordList() 
{
    return _directedEnergyTargetEnergyDepositionRecordList;
}

const std::vector<DirectedEnergyTargetEnergyDeposition>& DirectedEnergyAreaAimpoint::getDirectedEnergyTargetEnergyDepositionRecordList() const
{
    return _directedEnergyTargetEnergyDepositionRecordList;
}

void DirectedEnergyAreaAimpoint::setDirectedEnergyTargetEnergyDepositionRecordList(const std::vector<DirectedEnergyTargetEnergyDeposition>& pX)
{
     _directedEnergyTargetEnergyDepositionRecordList = pX;
}

void DirectedEnergyAreaAimpoint::marshal(DataStream& dataStream) const
{
    dataStream << _recordType;
    dataStream << _recordLength;
    dataStream << _padding;
    dataStream << ( unsigned short )_beamAntennaParameterList.size();
    dataStream << ( unsigned short )_directedEnergyTargetEnergyDepositionRecordList.size();

     for(size_t idx = 0; idx < _beamAntennaParameterList.size(); idx++)
     {
        BeamAntennaPattern x = _beamAntennaParameterList[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < _directedEnergyTargetEnergyDepositionRecordList.size(); idx++)
     {
        DirectedEnergyTargetEnergyDeposition x = _directedEnergyTargetEnergyDepositionRecordList[idx];
        x.marshal(dataStream);
     }

}

void DirectedEnergyAreaAimpoint::unmarshal(DataStream& dataStream)
{
    dataStream >> _recordType;
    dataStream >> _recordLength;
    dataStream >> _padding;
    dataStream >> _beamAntennaPatternRecordCount;
    dataStream >> _directedEnergyTargetEnergyDepositionRecordCount;

     _beamAntennaParameterList.clear();
     for(size_t idx = 0; idx < _beamAntennaPatternRecordCount; idx++)
     {
        BeamAntennaPattern x;
        x.unmarshal(dataStream);
        _beamAntennaParameterList.push_back(x);
     }

     _directedEnergyTargetEnergyDepositionRecordList.clear();
     for(size_t idx = 0; idx < _directedEnergyTargetEnergyDepositionRecordCount; idx++)
     {
        DirectedEnergyTargetEnergyDeposition x;
        x.unmarshal(dataStream);
        _directedEnergyTargetEnergyDepositionRecordList.push_back(x);
     }
}


bool DirectedEnergyAreaAimpoint::operator ==(const DirectedEnergyAreaAimpoint& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_recordType == rhs._recordType) ) ivarsEqual = false;
     if( ! (_recordLength == rhs._recordLength) ) ivarsEqual = false;
     if( ! (_padding == rhs._padding) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _beamAntennaParameterList.size(); idx++)
     {
        if( ! ( _beamAntennaParameterList[idx] == rhs._beamAntennaParameterList[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < _directedEnergyTargetEnergyDepositionRecordList.size(); idx++)
     {
        if( ! ( _directedEnergyTargetEnergyDepositionRecordList[idx] == rhs._directedEnergyTargetEnergyDepositionRecordList[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int DirectedEnergyAreaAimpoint::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _recordType
   marshalSize = marshalSize + 2;  // _recordLength
   marshalSize = marshalSize + 2;  // _padding
   marshalSize = marshalSize + 2;  // _beamAntennaPatternRecordCount
   marshalSize = marshalSize + 2;  // _directedEnergyTargetEnergyDepositionRecordCount

   for(int idx=0; idx < _beamAntennaParameterList.size(); idx++)
   {
        BeamAntennaPattern listElement = _beamAntennaParameterList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < _directedEnergyTargetEnergyDepositionRecordList.size(); idx++)
   {
        DirectedEnergyTargetEnergyDeposition listElement = _directedEnergyTargetEnergyDepositionRecordList[idx];
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
