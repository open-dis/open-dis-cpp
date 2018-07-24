#ifndef DIRECTEDENERGYFIREPDU_H
#define DIRECTEDENERGYFIREPDU_H

#include <DIS/EntityType.h>
#include <DIS/ClockTime.h>
#include <DIS/Vector3Float.h>
#include <DIS/StandardVariableSpecification.h>
#include <vector>
#include <DIS/WarfareFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Firing of a directed energy weapon shall be communicated by issuing a Directed Energy Fire PDU Section 7.3.4  COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO DirectedEnergyFirePdu : public WarfareFamilyPdu
{
protected:
  /** Field shall identify the munition type enumeration for the DE weapon beam, Section 7.3.4  */
  EntityType _munitionType; 

  /** Field shall indicate the simulation time at start of the shot, Section 7.3.4  */
  ClockTime _shotStartTime; 

  /** Field shall indicate the current cumulative duration of the shot, Section 7.3.4  */
  float _commulativeShotTime; 

  /** Field shall identify the location of the DE weapon aperture/emitter, Section 7.3.4  */
  Vector3Float _ApertureEmitterLocation; 

  /** Field shall identify the beam diameter at the aperture/emitter, Section 7.3.4  */
  float _apertureDiameter; 

  /** Field shall identify the emissions wavelength in units of meters, Section 7.3.4  */
  float _wavelength; 

  /** Field shall identify the current peak irradiance of emissions in units of Watts per square meter, Section 7.3.4  */
  float _peakIrradiance; 

  /** field shall identify the current pulse repetition frequency in units of cycles per second (Hertz), Section 7.3.4  */
  float _pulseRepetitionFrequency; 

  /** field shall identify the pulse width emissions in units of seconds, Section 7.3.4 */
  int _pulseWidth; 

  /** 16bit Boolean field shall contain various flags to indicate status information needed to process a DE, Section 7.3.4  */
  int _flags; 

  /** Field shall identify the pulse shape and shall be represented as an 8-bit enumeration, Section 7.3.4  */
  char _pulseShape; 

  /** padding, Section 7.3.4  */
  unsigned char _padding1; 

  /** padding, Section 7.3.4  */
  unsigned int _padding2; 

  /** padding, Section 7.3.4  */
  unsigned short _padding3; 

  /** Field shall specify the number of DE records, Section 7.3.4  */
  unsigned short _numberOfDERecords; 

  /** Fields shall contain one or more DE records, records shall conform to the variable record format (Section6.2.82), Section 7.3.4 */
  std::vector<StandardVariableSpecification> _dERecords; 


 public:
    DirectedEnergyFirePdu();
    virtual ~DirectedEnergyFirePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityType& getMunitionType(); 
    const EntityType&  getMunitionType() const; 
    void setMunitionType(const EntityType    &pX);

    ClockTime& getShotStartTime(); 
    const ClockTime&  getShotStartTime() const; 
    void setShotStartTime(const ClockTime    &pX);

    float getCommulativeShotTime() const; 
    void setCommulativeShotTime(float pX); 

    Vector3Float& getApertureEmitterLocation(); 
    const Vector3Float&  getApertureEmitterLocation() const; 
    void setApertureEmitterLocation(const Vector3Float    &pX);

    float getApertureDiameter() const; 
    void setApertureDiameter(float pX); 

    float getWavelength() const; 
    void setWavelength(float pX); 

    float getPeakIrradiance() const; 
    void setPeakIrradiance(float pX); 

    float getPulseRepetitionFrequency() const; 
    void setPulseRepetitionFrequency(float pX); 

    int getPulseWidth() const; 
    void setPulseWidth(int pX); 

    int getFlags() const; 
    void setFlags(int pX); 

    char getPulseShape() const; 
    void setPulseShape(char pX); 

    unsigned char getPadding1() const; 
    void setPadding1(unsigned char pX); 

    unsigned int getPadding2() const; 
    void setPadding2(unsigned int pX); 

    unsigned short getPadding3() const; 
    void setPadding3(unsigned short pX); 

    unsigned short getNumberOfDERecords() const; 

    std::vector<StandardVariableSpecification>& getDERecords(); 
    const std::vector<StandardVariableSpecification>& getDERecords() const; 
    void setDERecords(const std::vector<StandardVariableSpecification>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const DirectedEnergyFirePdu& rhs) const;
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
