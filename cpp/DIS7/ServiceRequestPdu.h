#ifndef SERVICEREQUESTPDU_H
#define SERVICEREQUESTPDU_H

#include <DIS/EntityID.h>
#include <DIS/EntityID.h>
#include <DIS/SupplyQuantity.h>
#include <vector>
#include <DIS/LogisticsFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Service Request PDU shall be used to communicate information associated with                            one entity requesting a service from another). Section 7.4.2 COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO ServiceRequestPdu : public LogisticsFamilyPdu
{
protected:
  /** Entity that is requesting service (see 6.2.28), Section 7.4.2 */
  EntityID _requestingEntityID; 

  /** Entity that is providing the service (see 6.2.28), Section 7.4.2 */
  EntityID _servicingEntityID; 

  /** Type of service requested, Section 7.4.2 */
  unsigned char _serviceTypeRequested; 

  /** How many requested, Section 7.4.2 */
  unsigned char _numberOfSupplyTypes; 

  /** padding */
  short _serviceRequestPadding; 

  std::vector<SupplyQuantity> _supplies; 


 public:
    ServiceRequestPdu();
    virtual ~ServiceRequestPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getRequestingEntityID(); 
    const EntityID&  getRequestingEntityID() const; 
    void setRequestingEntityID(const EntityID    &pX);

    EntityID& getServicingEntityID(); 
    const EntityID&  getServicingEntityID() const; 
    void setServicingEntityID(const EntityID    &pX);

    unsigned char getServiceTypeRequested() const; 
    void setServiceTypeRequested(unsigned char pX); 

    unsigned char getNumberOfSupplyTypes() const; 

    short getServiceRequestPadding() const; 
    void setServiceRequestPadding(short pX); 

    std::vector<SupplyQuantity>& getSupplies(); 
    const std::vector<SupplyQuantity>& getSupplies() const; 
    void setSupplies(const std::vector<SupplyQuantity>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const ServiceRequestPdu& rhs) const;
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
