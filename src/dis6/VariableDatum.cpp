#include <dis6/VariableDatum.h>
#include <iostream>

using namespace DIS;


VariableDatum::VariableDatum():
   _variableDatumID(0), 
   _variableDatumLength(0),
   _variableDatums(static_cast<std::size_t>(STATIC_ARRAY_LENGTH), char(0)), // can (theoretically) throw
   _arrayLength(0)
{

}

VariableDatum::~VariableDatum()
{
	//delete [] _variableDatums;
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
    return _variableDatumLength;
}

void VariableDatum::setVariableDatumLength(unsigned int pX)
{
    _variableDatumLength = pX;
}

char* VariableDatum::getVariableDatums() // a bit dangerous. we could just return a ref to _variableDatums
{
    return _variableDatums.data();
}

const char* VariableDatum::getVariableDatums() const
{
    return _variableDatums.data();
}

void VariableDatum::setVariableDatums(const char* x, const unsigned int length)
{
    // convert and store length as bits
    _variableDatumLength = length * 8;

    // Figure out _arrayLength (including padding to force whole 8 byte chunks)
    unsigned int chunks = length / 8;
    int remainder = length % 8;
    if(remainder > 0)
		chunks++;
    _arrayLength = chunks * 8;

    // .resize() might (theoretically) throw. want to catch? : what to do? zombie datum?
    if(_variableDatums.size() < length)
        _variableDatums.resize(length);

    for(unsigned int i = 0; i < length; i++)
    {
        _variableDatums[i] = x[i];
    }
    for(unsigned long i = length; i < _variableDatums.size(); i++)
    {
        _variableDatums[i] = 0;
    }
}

void VariableDatum::marshal(DataStream& dataStream) const
{
    dataStream << _variableDatumID;
    dataStream << _variableDatumLength;

    for(unsigned int idx = 0; idx < _arrayLength; idx++)
    {
        dataStream << _variableDatums[idx];
    }

}

void VariableDatum::unmarshal(DataStream& dataStream)
{
    dataStream >> _variableDatumID;
    dataStream >> _variableDatumLength;

    int byteLength = _variableDatumLength / 8;
	int chunks = byteLength / 8;
	if(byteLength % 8 > 0)
		chunks++;
	_arrayLength = chunks * 8;

	//std::cout << "Variable datum #" << (int)_variableDatumID << " arrayLength=" << (int)_arrayLength << " ";

    // .resize() might (theoretically) throw. want to catch? : what to do? zombie datum?
    if(_variableDatums.size() < _arrayLength)
        _variableDatums.resize(_arrayLength);

     for(unsigned int idx = 0; idx < _arrayLength; idx++)
     {
        dataStream >> _variableDatums[idx];
		//std::cout << (int)_variableDatums[idx] << " ";
     }
	 //std::cout << std::endl;
     for(unsigned long long idx = _arrayLength; idx < _variableDatums.size(); idx++)
	 {
		 _variableDatums[idx] = 0;
	 }
	 //std::cout << " Created and copied data to new _variableDatums array" << std::endl;

}

bool VariableDatum::operator ==(const VariableDatum& rhs) const
{
    bool ivarsEqual = true;

    if( ! (_variableDatumID == rhs._variableDatumID) ) ivarsEqual = false;
    if( ! (_variableDatumLength == rhs._variableDatumLength) ) ivarsEqual = false;
    if( ! (_variableDatums.size() == rhs._variableDatums.size()) ) ivarsEqual = false;
    else {
        for(std::size_t idx = 0; idx < _variableDatums.size(); idx++)
        {
            if(!(_variableDatums[idx] == rhs._variableDatums[idx]) ) {ivarsEqual = false; break; }
        }
    }

    return ivarsEqual;
}

unsigned int VariableDatum::getMarshalledSize() const
{
   unsigned int marshalSize = 0;

   marshalSize = marshalSize + 4;  // _variableDatumID
   marshalSize = marshalSize + 4;  // _variableDatumLength

	marshalSize = marshalSize + _arrayLength;

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
