#ifndef FASTENTITYSTATEPDU_H
#define FASTENTITYSTATEPDU_H

#include <DIS/VariableParameter.h>
#include <vector>
#include <DIS/EntityInformationFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Represents the postion and state of one entity in the world. This is identical in function to entity state pdu, but generates less garbage to collect in the Java world. Section 7.2.2. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO FastEntityStatePdu : public EntityInformationFamilyPdu
{
protected:
  /** The site ID */
  unsigned short _site; 

  /** The application ID */
  unsigned short _application; 

  /** the entity ID */
  unsigned short _entity; 

  /** what force this entity is affiliated with, eg red, blue, neutral, etc */
  unsigned char _forceId; 

  /** How many variable (nee articulation) parameters are in the variable length list */
  char _numberOfVariableParameters; 

  /** Kind of entity */
  unsigned char _entityKind; 

  /** Domain of entity (air, surface, subsurface, space, etc) */
  unsigned char _domain; 

  /** country to which the design of the entity is attributed */
  unsigned short _country; 

  /** category of entity */
  unsigned char _category; 

  /** subcategory of entity */
  unsigned char _subcategory; 

  /** specific info based on subcategory field */
  unsigned char _specific; 

  unsigned char _extra; 

  /** Kind of entity */
  unsigned char _altEntityKind; 

  /** Domain of entity (air, surface, subsurface, space, etc) */
  unsigned char _altDomain; 

  /** country to which the design of the entity is attributed */
  unsigned short _altCountry; 

  /** category of entity */
  unsigned char _altCategory; 

  /** subcategory of entity */
  unsigned char _altSubcategory; 

  /** specific info based on subcategory field */
  unsigned char _altSpecific; 

  unsigned char _altExtra; 

  /** X velo */
  float _xVelocity; 

  /** y Value */
  float _yVelocity; 

  /** Z value */
  float _zVelocity; 

  /** X value */
  double _xLocation; 

  /** y Value */
  double _yLocation; 

  /** Z value */
  double _zLocation; 

  float _psi; 

  float _theta; 

  float _phi; 

  /** a series of bit flags that are used to help draw the entity, such as smoking, on fire, etc. */
  int _entityAppearance; 

  /** enumeration of what dead reckoning algorighm to use */
  unsigned char _deadReckoningAlgorithm; 

  /** other parameters to use in the dead reckoning algorithm */
  char _otherParameters[15]; 

  /** X value */
  float _xAcceleration; 

  /** y Value */
  float _yAcceleration; 

  /** Z value */
  float _zAcceleration; 

  /** X value */
  float _xAngularVelocity; 

  /** y Value */
  float _yAngularVelocity; 

  /** Z value */
  float _zAngularVelocity; 

  /** characters that can be used for debugging, or to draw unique strings on the side of entities in the world */
  char _marking[12]; 

  /** a series of bit flags */
  int _capabilities; 

  /** variable length list of variable parameters. In earlier versions of DIS these were known as articulation parameters */
  std::vector<VariableParameter> _variableParameters; 


 public:
    FastEntityStatePdu();
    virtual ~FastEntityStatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned short getSite() const; 
    void setSite(unsigned short pX); 

    unsigned short getApplication() const; 
    void setApplication(unsigned short pX); 

    unsigned short getEntity() const; 
    void setEntity(unsigned short pX); 

    unsigned char getForceId() const; 
    void setForceId(unsigned char pX); 

    char getNumberOfVariableParameters() const; 

    unsigned char getEntityKind() const; 
    void setEntityKind(unsigned char pX); 

    unsigned char getDomain() const; 
    void setDomain(unsigned char pX); 

    unsigned short getCountry() const; 
    void setCountry(unsigned short pX); 

    unsigned char getCategory() const; 
    void setCategory(unsigned char pX); 

    unsigned char getSubcategory() const; 
    void setSubcategory(unsigned char pX); 

    unsigned char getSpecific() const; 
    void setSpecific(unsigned char pX); 

    unsigned char getExtra() const; 
    void setExtra(unsigned char pX); 

    unsigned char getAltEntityKind() const; 
    void setAltEntityKind(unsigned char pX); 

    unsigned char getAltDomain() const; 
    void setAltDomain(unsigned char pX); 

    unsigned short getAltCountry() const; 
    void setAltCountry(unsigned short pX); 

    unsigned char getAltCategory() const; 
    void setAltCategory(unsigned char pX); 

    unsigned char getAltSubcategory() const; 
    void setAltSubcategory(unsigned char pX); 

    unsigned char getAltSpecific() const; 
    void setAltSpecific(unsigned char pX); 

    unsigned char getAltExtra() const; 
    void setAltExtra(unsigned char pX); 

    float getXVelocity() const; 
    void setXVelocity(float pX); 

    float getYVelocity() const; 
    void setYVelocity(float pX); 

    float getZVelocity() const; 
    void setZVelocity(float pX); 

    double getXLocation() const; 
    void setXLocation(double pX); 

    double getYLocation() const; 
    void setYLocation(double pX); 

    double getZLocation() const; 
    void setZLocation(double pX); 

    float getPsi() const; 
    void setPsi(float pX); 

    float getTheta() const; 
    void setTheta(float pX); 

    float getPhi() const; 
    void setPhi(float pX); 

    int getEntityAppearance() const; 
    void setEntityAppearance(int pX); 

    unsigned char getDeadReckoningAlgorithm() const; 
    void setDeadReckoningAlgorithm(unsigned char pX); 

    char*  getOtherParameters(); 
    const char*  getOtherParameters() const; 
    void setOtherParameters( const char*    pX);

    float getXAcceleration() const; 
    void setXAcceleration(float pX); 

    float getYAcceleration() const; 
    void setYAcceleration(float pX); 

    float getZAcceleration() const; 
    void setZAcceleration(float pX); 

    float getXAngularVelocity() const; 
    void setXAngularVelocity(float pX); 

    float getYAngularVelocity() const; 
    void setYAngularVelocity(float pX); 

    float getZAngularVelocity() const; 
    void setZAngularVelocity(float pX); 

    char*  getMarking(); 
    const char*  getMarking() const; 
    void setMarking( const char*    pX);
    void setByStringMarking(const char* pX);

    int getCapabilities() const; 
    void setCapabilities(int pX); 

    std::vector<VariableParameter>& getVariableParameters(); 
    const std::vector<VariableParameter>& getVariableParameters() const; 
    void setVariableParameters(const std::vector<VariableParameter>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const FastEntityStatePdu& rhs) const;
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
