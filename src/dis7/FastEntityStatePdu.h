#ifndef FASTENTITYSTATEPDU_H
#define FASTENTITYSTATEPDU_H

#include <dis7/VariableParameter.h>
#include <vector>
#include <dis7/EntityInformationFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis7/msLibMacro.h>


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
  uint8_t _forceId; 

  /** How many variable (nee articulation) parameters are in the variable length list */
  int8_t _numberOfVariableParameters; 

  /** Kind of entity */
  uint8_t _entityKind; 

  /** Domain of entity (air, surface, subsurface, space, etc) */
  uint8_t _domain; 

  /** country to which the design of the entity is attributed */
  unsigned short _country; 

  /** category of entity */
  uint8_t _category; 

  /** subcategory of entity */
  uint8_t _subcategory; 

  /** specific info based on subcategory field */
  uint8_t _specific; 

  uint8_t _extra; 

  /** Kind of entity */
  uint8_t _altEntityKind; 

  /** Domain of entity (air, surface, subsurface, space, etc) */
  uint8_t _altDomain; 

  /** country to which the design of the entity is attributed */
  unsigned short _altCountry; 

  /** category of entity */
  uint8_t _altCategory; 

  /** subcategory of entity */
  uint8_t _altSubcategory; 

  /** specific info based on subcategory field */
  uint8_t _altSpecific; 

  uint8_t _altExtra; 

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
  uint8_t _deadReckoningAlgorithm; 

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

    uint8_t getForceId() const; 
    void setForceId(uint8_t pX); 

    char getNumberOfVariableParameters() const; 

    uint8_t getEntityKind() const; 
    void setEntityKind(uint8_t pX); 

    uint8_t getDomain() const; 
    void setDomain(uint8_t pX); 

    unsigned short getCountry() const; 
    void setCountry(unsigned short pX); 

    uint8_t getCategory() const; 
    void setCategory(uint8_t pX); 

    uint8_t getSubcategory() const; 
    void setSubcategory(uint8_t pX); 

    uint8_t getSpecific() const; 
    void setSpecific(uint8_t pX); 

    uint8_t getExtra() const; 
    void setExtra(uint8_t pX); 

    uint8_t getAltEntityKind() const; 
    void setAltEntityKind(uint8_t pX); 

    uint8_t getAltDomain() const; 
    void setAltDomain(uint8_t pX); 

    unsigned short getAltCountry() const; 
    void setAltCountry(unsigned short pX); 

    uint8_t getAltCategory() const; 
    void setAltCategory(uint8_t pX); 

    uint8_t getAltSubcategory() const; 
    void setAltSubcategory(uint8_t pX); 

    uint8_t getAltSpecific() const; 
    void setAltSpecific(uint8_t pX); 

    uint8_t getAltExtra() const; 
    void setAltExtra(uint8_t pX); 

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

    uint8_t getDeadReckoningAlgorithm() const; 
    void setDeadReckoningAlgorithm(uint8_t pX); 

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
