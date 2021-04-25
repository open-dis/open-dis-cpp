#pragma once

#include <dis6/AcousticEmitterSystem.h>
#include <dis6/Vector3Float.h>
#include <dis6/AcousticBeamData.h>
#include <vector>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Used in the UA pdu; ties together an emmitter and a location. This requires manual cleanup; the beam data should not be attached to each emitter system.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO AcousticEmitterSystemData
{
protected:
  /** Length of emitter system data */
  unsigned char _emitterSystemDataLength; 

  /** Number of beams */
  unsigned char _numberOfBeams; 

  /** padding */
  unsigned short _pad2; 

  /** This field shall specify the system for a particular UA emitter. */
  AcousticEmitterSystem _acousticEmitterSystem; 

  /** Represents the location wrt the entity */
  Vector3Float _emitterLocation; 

  /** For each beam in numberOfBeams, an emitter system. This is not right--the beam records need to be at the end of the PDU, rather than attached to each system. */
  std::vector<AcousticBeamData> _beamRecords; 


 public:
    AcousticEmitterSystemData();
    virtual ~AcousticEmitterSystemData();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getEmitterSystemDataLength() const; 
    void setEmitterSystemDataLength(unsigned char pX); 

    unsigned char getNumberOfBeams() const; 

    unsigned short getPad2() const; 
    void setPad2(unsigned short pX); 

    AcousticEmitterSystem& getAcousticEmitterSystem(); 
    const AcousticEmitterSystem&  getAcousticEmitterSystem() const; 
    void setAcousticEmitterSystem(const AcousticEmitterSystem    &pX);

    Vector3Float& getEmitterLocation(); 
    const Vector3Float&  getEmitterLocation() const; 
    void setEmitterLocation(const Vector3Float    &pX);

    std::vector<AcousticBeamData>& getBeamRecords(); 
    const std::vector<AcousticBeamData>& getBeamRecords() const; 
    void setBeamRecords(const std::vector<AcousticBeamData>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const AcousticEmitterSystemData& rhs) const;
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
