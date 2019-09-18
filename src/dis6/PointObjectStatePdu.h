#ifndef POINTOBJECTSTATEPDU_H
#define POINTOBJECTSTATEPDU_H

#include <dis6/EntityID.h>
#include <dis6/EntityID.h>
#include <dis6/ObjectType.h>
#include <dis6/Vector3Double.h>
#include <dis6/Orientation.h>
#include <dis6/SimulationAddress.h>
#include <dis6/SimulationAddress.h>
#include <dis6/SyntheticEnvironmentFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.11.3: Inormation abut the addition or modification of a synthecic enviroment object that is anchored      to the terrain with a single point. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO PointObjectStatePdu : public SyntheticEnvironmentFamilyPdu
{
protected:
  /** Object in synthetic environment */
  EntityID _objectID; 

  /** Object with which this point object is associated */
  EntityID _referencedObjectID; 

  /** unique update number of each state transition of an object */
  unsigned short _updateNumber; 

  /** force ID */
  uint8_t _forceID; 

  /** modifications */
  uint8_t _modifications; 

  /** Object type */
  ObjectType _objectType; 

  /** Object location */
  Vector3Double _objectLocation; 

  /** Object orientation */
  Orientation _objectOrientation; 

  /** Object apperance */
  double _objectAppearance; 

  /** requesterID */
  SimulationAddress _requesterID; 

  /** receiver ID */
  SimulationAddress _receivingID; 

  /** padding */
  unsigned int _pad2; 


 public:
    PointObjectStatePdu();
    virtual ~PointObjectStatePdu();

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

    uint8_t getForceID() const; 
    void setForceID(uint8_t pX); 

    uint8_t getModifications() const; 
    void setModifications(uint8_t pX); 

    ObjectType& getObjectType(); 
    const ObjectType&  getObjectType() const; 
    void setObjectType(const ObjectType    &pX);

    Vector3Double& getObjectLocation(); 
    const Vector3Double&  getObjectLocation() const; 
    void setObjectLocation(const Vector3Double    &pX);

    Orientation& getObjectOrientation(); 
    const Orientation&  getObjectOrientation() const; 
    void setObjectOrientation(const Orientation    &pX);

    double getObjectAppearance() const; 
    void setObjectAppearance(double pX); 

    SimulationAddress& getRequesterID(); 
    const SimulationAddress&  getRequesterID() const; 
    void setRequesterID(const SimulationAddress    &pX);

    SimulationAddress& getReceivingID(); 
    const SimulationAddress&  getReceivingID() const; 
    void setReceivingID(const SimulationAddress    &pX);

    unsigned int getPad2() const; 
    void setPad2(unsigned int pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const PointObjectStatePdu& rhs) const;
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
