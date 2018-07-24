#ifndef GRIDAXIS_H
#define GRIDAXIS_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Grid axis record for fixed data. Section 6.2.41

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO GridAxis
{
protected:
  /** coordinate of the grid origin or initial value */
  double _domainInitialXi; 

  /** coordinate of the endpoint or final value */
  double _domainFinalXi; 

  /** The number of grid points along the Xi domain axis for the enviornmental state data */
  unsigned short _domainPointsXi; 

  /** interleaf factor along the domain axis. */
  unsigned char _interleafFactor; 

  /** type of grid axis */
  unsigned char _axisType; 

  /** Number of grid locations along Xi axis */
  unsigned short _numberOfPointsOnXiAxis; 

  /** initial grid point for the current pdu */
  unsigned short _initialIndex; 


 public:
    GridAxis();
    virtual ~GridAxis();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    double getDomainInitialXi() const; 
    void setDomainInitialXi(double pX); 

    double getDomainFinalXi() const; 
    void setDomainFinalXi(double pX); 

    unsigned short getDomainPointsXi() const; 
    void setDomainPointsXi(unsigned short pX); 

    unsigned char getInterleafFactor() const; 
    void setInterleafFactor(unsigned char pX); 

    unsigned char getAxisType() const; 
    void setAxisType(unsigned char pX); 

    unsigned short getNumberOfPointsOnXiAxis() const; 
    void setNumberOfPointsOnXiAxis(unsigned short pX); 

    unsigned short getInitialIndex() const; 
    void setInitialIndex(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const GridAxis& rhs) const;
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
