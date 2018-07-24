#ifndef SYSTEMIDENTIFIER_H
#define SYSTEMIDENTIFIER_H

#include <DIS/ChangeOptions.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// The ID of the IFF emitting system. NOT COMPLETE. Section 6.2.86

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO SystemIdentifier
{
protected:
  /** general type of emitting system, an enumeration */
  unsigned short _systemType; 

  /** named type of system, an enumeration */
  unsigned short _systemName; 

  /** mode of operation for the system, an enumeration */
  unsigned short _systemMode; 

  /** status of this PDU, see section 6.2.15 */
  ChangeOptions _changeOptions; 


 public:
    SystemIdentifier();
    virtual ~SystemIdentifier();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned short getSystemType() const; 
    void setSystemType(unsigned short pX); 

    unsigned short getSystemName() const; 
    void setSystemName(unsigned short pX); 

    unsigned short getSystemMode() const; 
    void setSystemMode(unsigned short pX); 

    ChangeOptions& getChangeOptions(); 
    const ChangeOptions&  getChangeOptions() const; 
    void setChangeOptions(const ChangeOptions    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const SystemIdentifier& rhs) const;
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
