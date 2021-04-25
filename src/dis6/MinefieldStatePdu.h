#pragma once

#include <dis6/EntityID.h>
#include <dis6/EntityType.h>
#include <dis6/Vector3Double.h>
#include <dis6/Orientation.h>
#include <dis6/Point.h>
#include <dis6/EntityType.h>
#include <vector>
#include <dis6/MinefieldFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.10.1 Abstract superclass for PDUs relating to minefields. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO MinefieldStatePdu : public MinefieldFamilyPdu
{
protected:
  /** Minefield ID */
  EntityID _minefieldID; 

  /** Minefield sequence */
  unsigned short _minefieldSequence; 

  /** force ID */
  unsigned char _forceID; 

  /** Number of permieter points */
  unsigned char _numberOfPerimeterPoints; 

  /** type of minefield */
  EntityType _minefieldType; 

  /** how many mine types */
  unsigned short _numberOfMineTypes; 

  /** location of minefield in world coords */
  Vector3Double _minefieldLocation; 

  /** orientation of minefield */
  Orientation _minefieldOrientation; 

  /** appearance bitflags */
  unsigned short _appearance; 

  /** protocolMode */
  unsigned short _protocolMode; 

  /** perimeter points for the minefield */
  std::vector<Point> _perimeterPoints; 

  /** Type of mines */
  std::vector<EntityType> _mineType; 


 public:
    MinefieldStatePdu();
    virtual ~MinefieldStatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getMinefieldID(); 
    const EntityID&  getMinefieldID() const; 
    void setMinefieldID(const EntityID    &pX);

    unsigned short getMinefieldSequence() const; 
    void setMinefieldSequence(unsigned short pX); 

    unsigned char getForceID() const; 
    void setForceID(unsigned char pX); 

    unsigned char getNumberOfPerimeterPoints() const; 

    EntityType& getMinefieldType(); 
    const EntityType&  getMinefieldType() const; 
    void setMinefieldType(const EntityType    &pX);

    unsigned short getNumberOfMineTypes() const; 

    Vector3Double& getMinefieldLocation(); 
    const Vector3Double&  getMinefieldLocation() const; 
    void setMinefieldLocation(const Vector3Double    &pX);

    Orientation& getMinefieldOrientation(); 
    const Orientation&  getMinefieldOrientation() const; 
    void setMinefieldOrientation(const Orientation    &pX);

    unsigned short getAppearance() const; 
    void setAppearance(unsigned short pX); 

    unsigned short getProtocolMode() const; 
    void setProtocolMode(unsigned short pX); 

    std::vector<Point>& getPerimeterPoints(); 
    const std::vector<Point>& getPerimeterPoints() const; 
    void setPerimeterPoints(const std::vector<Point>&    pX);

    std::vector<EntityType>& getMineType(); 
    const std::vector<EntityType>& getMineType() const; 
    void setMineType(const std::vector<EntityType>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const MinefieldStatePdu& rhs) const;
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
