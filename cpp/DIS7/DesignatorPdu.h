#ifndef DESIGNATORPDU_H
#define DESIGNATORPDU_H

#include <DIS/EntityID.h>
#include <DIS/EntityID.h>
#include <DIS/Vector3Float.h>
#include <DIS/Vector3Double.h>
#include <DIS/Vector3Float.h>
#include <DIS/DistributedEmissionsFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Section 5.3.7.2. Handles designating operations. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO DesignatorPdu : public DistributedEmissionsFamilyPdu
{
protected:
  /** ID of the entity designating */
  EntityID _designatingEntityID; 

  /** This field shall specify a unique emitter database number assigned to  differentiate between otherwise similar or identical emitter beams within an emitter system. */
  unsigned short _codeName; 

  /** ID of the entity being designated */
  EntityID _designatedEntityID; 

  /** This field shall identify the designator code being used by the designating entity  */
  unsigned short _designatorCode; 

  /** This field shall identify the designator output power in watts */
  float _designatorPower; 

  /** This field shall identify the designator wavelength in units of microns */
  float _designatorWavelength; 

  /** designtor spot wrt the designated entity */
  Vector3Float _designatorSpotWrtDesignated; 

  /** designtor spot wrt the designated entity */
  Vector3Double _designatorSpotLocation; 

  /** Dead reckoning algorithm */
  char _deadReckoningAlgorithm; 

  /** padding */
  unsigned short _padding1; 

  /** padding */
  char _padding2; 

  /** linear accelleration of entity */
  Vector3Float _entityLinearAcceleration; 


 public:
    DesignatorPdu();
    virtual ~DesignatorPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getDesignatingEntityID(); 
    const EntityID&  getDesignatingEntityID() const; 
    void setDesignatingEntityID(const EntityID    &pX);

    unsigned short getCodeName() const; 
    void setCodeName(unsigned short pX); 

    EntityID& getDesignatedEntityID(); 
    const EntityID&  getDesignatedEntityID() const; 
    void setDesignatedEntityID(const EntityID    &pX);

    unsigned short getDesignatorCode() const; 
    void setDesignatorCode(unsigned short pX); 

    float getDesignatorPower() const; 
    void setDesignatorPower(float pX); 

    float getDesignatorWavelength() const; 
    void setDesignatorWavelength(float pX); 

    Vector3Float& getDesignatorSpotWrtDesignated(); 
    const Vector3Float&  getDesignatorSpotWrtDesignated() const; 
    void setDesignatorSpotWrtDesignated(const Vector3Float    &pX);

    Vector3Double& getDesignatorSpotLocation(); 
    const Vector3Double&  getDesignatorSpotLocation() const; 
    void setDesignatorSpotLocation(const Vector3Double    &pX);

    char getDeadReckoningAlgorithm() const; 
    void setDeadReckoningAlgorithm(char pX); 

    unsigned short getPadding1() const; 
    void setPadding1(unsigned short pX); 

    char getPadding2() const; 
    void setPadding2(char pX); 

    Vector3Float& getEntityLinearAcceleration(); 
    const Vector3Float&  getEntityLinearAcceleration() const; 
    void setEntityLinearAcceleration(const Vector3Float    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const DesignatorPdu& rhs) const;
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
