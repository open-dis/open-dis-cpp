#ifndef SIMULATIONMANAGEMENTPDUHEADER_H
#define SIMULATIONMANAGEMENTPDUHEADER_H

#include <DIS/PduHeader.h>
#include <DIS/EntityID.h>
#include <DIS/EntityID.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// First part of a simulation management (SIMAN) PDU and SIMAN-Reliability (SIMAN-R) PDU. Sectionn 6.2.81

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO SimulationManagementPduHeader
{
protected:
  /** Conventional PDU header */
  PduHeader _pduHeader; 

  /** IDs the simulation or entity, etiehr a simulation or an entity. Either 6.2.80 or 6.2.28 */
  EntityID _originatingID; 

  /** simulation, all simulations, a special ID, or an entity. See 5.6.5 and 5.12.4 */
  EntityID _recevingID; 


 public:
    SimulationManagementPduHeader();
    virtual ~SimulationManagementPduHeader();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    PduHeader& getPduHeader(); 
    const PduHeader&  getPduHeader() const; 
    void setPduHeader(const PduHeader    &pX);

    EntityID& getOriginatingID(); 
    const EntityID&  getOriginatingID() const; 
    void setOriginatingID(const EntityID    &pX);

    EntityID& getRecevingID(); 
    const EntityID&  getRecevingID() const; 
    void setRecevingID(const EntityID    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const SimulationManagementPduHeader& rhs) const;
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
