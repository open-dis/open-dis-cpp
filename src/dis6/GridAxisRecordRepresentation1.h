#pragma once

#include <dis6/TwoByteChunk.h>
#include <vector>
#include <dis6/GridAxisRecord.h>
#include <dis6/utils/DataStream.h>
#include <dis6/opendis6_export.h>


namespace DIS
{
// 5.2.44: Grid data record, representation 1

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class OPENDIS6_EXPORT GridAxisRecordRepresentation1 : public GridAxisRecord
{
protected:
  /** constant scale factor */
  float _fieldScale; 

  /** constant offset used to scale grid data */
  float _fieldOffset; 

  /** Number of data values */
  unsigned short _numberOfValues; 

  /** variable length list of data parameters ^^^this is wrong--need padding as well */
  std::vector<TwoByteChunk> _dataValues; 


 public:
    GridAxisRecordRepresentation1();
    virtual ~GridAxisRecordRepresentation1();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    float getFieldScale() const; 
    void setFieldScale(float pX); 

    float getFieldOffset() const; 
    void setFieldOffset(float pX); 

    unsigned short getNumberOfValues() const; 

    std::vector<TwoByteChunk>& getDataValues(); 
    const std::vector<TwoByteChunk>& getDataValues() const; 
    void setDataValues(const std::vector<TwoByteChunk>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const GridAxisRecordRepresentation1& rhs) const;
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
