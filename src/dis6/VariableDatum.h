#pragma once

#include <dis6/utils/DataStream.h>
#include <dis6/opendis6_export.h>
#include <vector>

// length in bytes for the variable data. This should be a dynamically allocated array.
#define STATIC_ARRAY_LENGTH 128

namespace DIS
{
// Section 5.2.32. Variable Datum Record

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved.
//
// @author DMcG, jkg

class OPENDIS6_EXPORT VariableDatum
{
protected:
  /** ID of the variable datum */
  unsigned int _variableDatumID;

  /** length of the variable datums */
  unsigned int _variableDatumLength;

  /** The variable datum data.*/
  std::vector<char> _variableDatums;
  unsigned int _arrayLength;


 public:
    VariableDatum();
    virtual ~VariableDatum();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getVariableDatumID() const;
    void setVariableDatumID(unsigned int pX);

    unsigned int getVariableDatumLength() const;
    void setVariableDatumLength(unsigned int pX);

    char*  getVariableDatums();
    const char*  getVariableDatums() const;
    void setVariableDatums(const char* pX, const unsigned int length);


virtual unsigned int getMarshalledSize() const;

     bool operator  ==(const VariableDatum& rhs) const;
};
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
