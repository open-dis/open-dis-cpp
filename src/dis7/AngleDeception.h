#ifndef ANGLEDECEPTION_H
#define ANGLEDECEPTION_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// The Angle Deception attribute record may be used to communicate discrete values that are associated with angle deception jamming that cannot be referenced to an emitter mode. The values provided in the record records (provided in the associated Electromagnetic Emission PDU). (The victim radar beams are those that are targeted by the jammer.) Section 6.2.12.2

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO AngleDeception
{
protected:
  unsigned int _recordType; 

  unsigned short _recordLength; 

  unsigned short _padding; 

  unsigned char _emitterNumber; 

  unsigned char _beamNumber; 

  unsigned char _stateIndicator; 

  unsigned int _padding2; 

  float _azimuthOffset; 

  float _azimuthWidth; 

  float _azimuthPullRate; 

  float _azimuthPullAcceleration; 

  float _elevationOffset; 

  float _elevationWidth; 

  float _elevationPullRate; 

  float _elevationPullAcceleration; 

  unsigned int _padding3; 


 public:
    AngleDeception();
    virtual ~AngleDeception();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getRecordType() const; 
    void setRecordType(unsigned int pX); 

    unsigned short getRecordLength() const; 
    void setRecordLength(unsigned short pX); 

    unsigned short getPadding() const; 
    void setPadding(unsigned short pX); 

    unsigned char getEmitterNumber() const; 
    void setEmitterNumber(unsigned char pX); 

    unsigned char getBeamNumber() const; 
    void setBeamNumber(unsigned char pX); 

    unsigned char getStateIndicator() const; 
    void setStateIndicator(unsigned char pX); 

    unsigned int getPadding2() const; 
    void setPadding2(unsigned int pX); 

    float getAzimuthOffset() const; 
    void setAzimuthOffset(float pX); 

    float getAzimuthWidth() const; 
    void setAzimuthWidth(float pX); 

    float getAzimuthPullRate() const; 
    void setAzimuthPullRate(float pX); 

    float getAzimuthPullAcceleration() const; 
    void setAzimuthPullAcceleration(float pX); 

    float getElevationOffset() const; 
    void setElevationOffset(float pX); 

    float getElevationWidth() const; 
    void setElevationWidth(float pX); 

    float getElevationPullRate() const; 
    void setElevationPullRate(float pX); 

    float getElevationPullAcceleration() const; 
    void setElevationPullAcceleration(float pX); 

    unsigned int getPadding3() const; 
    void setPadding3(unsigned int pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const AngleDeception& rhs) const;
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
