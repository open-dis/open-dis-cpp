#ifndef BLANKINGSECTOR_H
#define BLANKINGSECTOR_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// The Blanking Sector attribute record may be used to convey persistent areas within a scan volume where emitter power for a specific active emitter beam is reduced to an insignificant value. Section 6.2.12

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO BlankingSector
{
protected:
  unsigned int _recordType; 

  unsigned short _recordLength; 

  unsigned char _emitterNumber; 

  unsigned char _beamNumber; 

  unsigned char _stateIndicator; 

  float _leftAzimuth; 

  float _rightAzimuth; 

  float _lowerElevation; 

  float _upperElevation; 

  float _residualPower; 


 public:
    BlankingSector();
    virtual ~BlankingSector();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getRecordType() const; 
    void setRecordType(unsigned int pX); 

    unsigned short getRecordLength() const; 
    void setRecordLength(unsigned short pX); 

    unsigned char getEmitterNumber() const; 
    void setEmitterNumber(unsigned char pX); 

    unsigned char getBeamNumber() const; 
    void setBeamNumber(unsigned char pX); 

    unsigned char getStateIndicator() const; 
    void setStateIndicator(unsigned char pX); 

    float getLeftAzimuth() const; 
    void setLeftAzimuth(float pX); 

    float getRightAzimuth() const; 
    void setRightAzimuth(float pX); 

    float getLowerElevation() const; 
    void setLowerElevation(float pX); 

    float getUpperElevation() const; 
    void setUpperElevation(float pX); 

    float getResidualPower() const; 
    void setResidualPower(float pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const BlankingSector& rhs) const;
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
