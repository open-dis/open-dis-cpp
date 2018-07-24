#ifndef DATAQUERYDATUMSPECIFICATION_H
#define DATAQUERYDATUMSPECIFICATION_H

#include <DIS/UnsignedDISInteger.h>
#include <DIS/UnsignedDISInteger.h>
#include <vector>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// List of fixed and variable datum records. Section 6.2.18 

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO DataQueryDatumSpecification
{
protected:
  /** Number of fixed datums */
  unsigned int _numberOfFixedDatums; 

  /** Number of variable datums */
  unsigned int _numberOfVariableDatums; 

  /** variable length list fixed datum IDs */
  std::vector<UnsignedDISInteger> _fixedDatumIDList; 

  /** variable length list variable datum IDs */
  std::vector<UnsignedDISInteger> _variableDatumIDList; 


 public:
    DataQueryDatumSpecification();
    virtual ~DataQueryDatumSpecification();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getNumberOfFixedDatums() const; 

    unsigned int getNumberOfVariableDatums() const; 

    std::vector<UnsignedDISInteger>& getFixedDatumIDList(); 
    const std::vector<UnsignedDISInteger>& getFixedDatumIDList() const; 
    void setFixedDatumIDList(const std::vector<UnsignedDISInteger>&    pX);

    std::vector<UnsignedDISInteger>& getVariableDatumIDList(); 
    const std::vector<UnsignedDISInteger>& getVariableDatumIDList() const; 
    void setVariableDatumIDList(const std::vector<UnsignedDISInteger>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const DataQueryDatumSpecification& rhs) const;
};
}

#endif
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
