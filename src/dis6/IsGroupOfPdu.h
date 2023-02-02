#pragma once

#include <dis6/EntityID.h>
#include <dis6/VariableDatum.h>
#include <vector>
#include <dis6/EntityManagementFamilyPdu.h>
#include <dis6/utils/DataStream.h>
#include <dis6/opendis6_export.h>


namespace DIS
{
// Section 5.3.9.2 Information about a particular group of entities grouped together for the purposes of netowrk bandwidth         reduction or aggregation. Needs manual cleanup. The GED size requires a database lookup. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class OPENDIS6_EXPORT IsGroupOfPdu : public EntityManagementFamilyPdu
{
protected:
  /** ID of aggregated entities */
  EntityID _groupEntityID; 

  /** type of entities constituting the group */
  unsigned char _groupedEntityCategory; 

  /** Number of individual entities constituting the group */
  unsigned char _numberOfGroupedEntities; 

  /** padding */
  unsigned int _pad2; 

  /** latitude */
  double _latitude; 

  /** longitude */
  double _longitude; 

  /** GED records about each individual entity in the group. ^^^this is wrong--need a database lookup to find the actual size of the list elements */
  std::vector<VariableDatum> _groupedEntityDescriptions; 


 public:
    IsGroupOfPdu();
    virtual ~IsGroupOfPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getGroupEntityID(); 
    const EntityID&  getGroupEntityID() const; 
    void setGroupEntityID(const EntityID    &pX);

    unsigned char getGroupedEntityCategory() const; 
    void setGroupedEntityCategory(unsigned char pX); 

    unsigned char getNumberOfGroupedEntities() const; 

    unsigned int getPad2() const; 
    void setPad2(unsigned int pX); 

    double getLatitude() const; 
    void setLatitude(double pX); 

    double getLongitude() const; 
    void setLongitude(double pX); 

    std::vector<VariableDatum>& getGroupedEntityDescriptions(); 
    const std::vector<VariableDatum>& getGroupedEntityDescriptions() const; 
    void setGroupedEntityDescriptions(const std::vector<VariableDatum>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const IsGroupOfPdu& rhs) const;
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
