#pragma once

#include <dis6/EntityID.h>
#include <dis6/EntityID.h>
#include <dis6/EntityType.h>
#include <dis6/SixByteChunk.h>
#include <dis6/SimulationAddress.h>
#include <dis6/SimulationAddress.h>
#include <dis6/Vector3Double.h>
#include <vector>
#include <dis6/SyntheticEnvironmentFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.11.5: Information about the addition/modification of an oobject that is geometrically      achored to the terrain with a set of three or more points that come to a closure. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO ArealObjectStatePdu : public SyntheticEnvironmentFamilyPdu
{
protected:
  /** Object in synthetic environment */
  EntityID _objectID; 

  /** Object with which this point object is associated */
  EntityID _referencedObjectID; 

  /** unique update number of each state transition of an object */
  unsigned short _updateNumber; 

  /** force ID */
  unsigned char _forceID; 

  /** modifications enumeration */
  unsigned char _modifications; 

  /** Object type */
  EntityType _objectType; 

  /** Object appearance */
  SixByteChunk _objectAppearance; 

  /** Number of points */
  unsigned short _numberOfPoints; 

  /** requesterID */
  SimulationAddress _requesterID; 

  /** receiver ID */
  SimulationAddress _receivingID; 

  /** location of object */
  std::vector<Vector3Double> _objectLocation; 


 public:
    ArealObjectStatePdu();
    virtual ~ArealObjectStatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getObjectID(); 
    const EntityID&  getObjectID() const; 
    void setObjectID(const EntityID    &pX);

    EntityID& getReferencedObjectID(); 
    const EntityID&  getReferencedObjectID() const; 
    void setReferencedObjectID(const EntityID    &pX);

    unsigned short getUpdateNumber() const; 
    void setUpdateNumber(unsigned short pX); 

    unsigned char getForceID() const; 
    void setForceID(unsigned char pX); 

    unsigned char getModifications() const; 
    void setModifications(unsigned char pX); 

    EntityType& getObjectType(); 
    const EntityType&  getObjectType() const; 
    void setObjectType(const EntityType    &pX);

    SixByteChunk& getObjectAppearance(); 
    const SixByteChunk&  getObjectAppearance() const; 
    void setObjectAppearance(const SixByteChunk    &pX);

    unsigned short getNumberOfPoints() const; 

    SimulationAddress& getRequesterID(); 
    const SimulationAddress&  getRequesterID() const; 
    void setRequesterID(const SimulationAddress    &pX);

    SimulationAddress& getReceivingID(); 
    const SimulationAddress&  getReceivingID() const; 
    void setReceivingID(const SimulationAddress    &pX);

    std::vector<Vector3Double>& getObjectLocation(); 
    const std::vector<Vector3Double>& getObjectLocation() const; 
    void setObjectLocation(const std::vector<Vector3Double>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const ArealObjectStatePdu& rhs) const;
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
