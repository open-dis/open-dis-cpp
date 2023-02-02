#pragma once

#include <dis6/EmitterSystem.h>
#include <dis6/Vector3Float.h>
#include <dis6/ElectromagneticEmissionBeamData.h>
#include <vector>
#include <dis6/utils/DataStream.h>
#include <dis6/opendis6_export.h>


namespace DIS
{
// Data about one electronic system

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class OPENDIS6_EXPORT ElectromagneticEmissionSystemData
{
protected:
  /** This field shall specify the length of this emitter system�s data (including beam data and its track/jam information) in 32-bit words. The length shall include the System Data Length field.  */
  unsigned char _systemDataLength; 

  /** This field shall specify the number of beams being described in the current PDU for the system being described.  */
  unsigned char _numberOfBeams; 

  /** padding. */
  unsigned short _emissionsPadding2; 

  /** This field shall specify information about a particular emitter system */
  EmitterSystem _emitterSystem; 

  /** Location with respect to the entity */
  Vector3Float _location; 

  /** variable length list of beam data records */
  std::vector<ElectromagneticEmissionBeamData> _beamDataRecords; 


 public:
    ElectromagneticEmissionSystemData();
    virtual ~ElectromagneticEmissionSystemData();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getSystemDataLength() const; 
    void setSystemDataLength(unsigned char pX); 

    unsigned char getNumberOfBeams() const; 

    unsigned short getEmissionsPadding2() const; 
    void setEmissionsPadding2(unsigned short pX); 

    EmitterSystem& getEmitterSystem(); 
    const EmitterSystem&  getEmitterSystem() const; 
    void setEmitterSystem(const EmitterSystem    &pX);

    Vector3Float& getLocation(); 
    const Vector3Float&  getLocation() const; 
    void setLocation(const Vector3Float    &pX);

    std::vector<ElectromagneticEmissionBeamData>& getBeamDataRecords(); 
    const std::vector<ElectromagneticEmissionBeamData>& getBeamDataRecords() const; 
    void setBeamDataRecords(const std::vector<ElectromagneticEmissionBeamData>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const ElectromagneticEmissionSystemData& rhs) const;
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
