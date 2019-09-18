#include <dis6/VariableDatum.h>
#include <iostream>

using namespace DIS;


VariableDatum::VariableDatum():
   _variableDatumID(0),
   _variableDatums(static_cast<std::size_t>(STATIC_ARRAY_LENGTH), '0') // can (theoretically) throw
{

}

VariableDatum::~VariableDatum()
{
}

unsigned int VariableDatum::getVariableDatumID() const
{
    return _variableDatumID;
}

void VariableDatum::setVariableDatumID(unsigned int pX)
{
    _variableDatumID = pX;
}

unsigned int VariableDatum::getVariableDatumLength() const
{
    return _variableDatums.size();
}

void VariableDatum::setVariableDatumLength(unsigned int pX)
{
    _variableDatums.resize(pX);
}

char* VariableDatum::getVariableDatums()
{
    return _variableDatums.data();
}

const char* VariableDatum::getVariableDatums() const
{
    return _variableDatums.data();
}

void VariableDatum::setVariableDatums(const char* x, const unsigned int length)
{
    if(_variableDatums.size() != length)
    {
        // Standard library will set new size to length but may not unallocate memory
        // As a result, resizing to a smaller size doesn't mean we'll waste time allocating
        // when a larger datum arrives.
        _variableDatums.resize(length); 
    }
    std::memcpy(&_variableDatums[0], x, length);
}

void VariableDatum::marshal(DataStream& dataStream) const
{
    dataStream << _variableDatumID;
    dataStream << _variableDatums.size();

    for(size_t idx = 0; idx < _variableDatums.size(); idx++)
    {
        dataStream << _variableDatums[idx];
    }
}

void VariableDatum::unmarshal(DataStream& dataStream)
{
    dataStream >> _variableDatumID;

    size_t incoming_length;

    dataStream >> incoming_length;
	
    int byteLength = incoming_length / 8;
	int chunks = byteLength / 8;
	if(byteLength % 8 > 0)
    {
        chunks++;
    }

	size_t _arrayLength = chunks * 8;

    if(_variableDatums.size() != _arrayLength)
    {
        _variableDatums.resize(_arrayLength);
    }   

    for(size_t idx = 0; idx < _variableDatums.size(); idx++)
    {
        dataStream >> _variableDatums[idx];
    }
}

bool VariableDatum::operator ==(const VariableDatum& rhs) const
{
    return _variableDatumID == rhs._variableDatumID && _variableDatums == rhs._variableDatums;
}

int VariableDatum::getMarshalledSize() const
{
    return sizeof(_variableDatumID) + sizeof(_variableDatums.size()) + _variableDatums.size();
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
