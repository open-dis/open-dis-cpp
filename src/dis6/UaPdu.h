#ifndef UAPDU_H
#define UAPDU_H

#include <dis6/EntityID.h>
#include <dis6/EventID.h>
#include <dis6/ShaftRPMs.h>
#include <dis6/ApaData.h>
#include <dis6/AcousticEmitterSystemData.h>
#include <vector>
#include <dis6/DistributedEmissionsFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.7.3. Information about underwater acoustic emmissions. This requires manual cleanup.  The beam data records should ALL be a the finish, rather than attached to each emitter system. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO UaPdu : public DistributedEmissionsFamilyPdu
{
protected:
  /** ID of the entity that is the source of the emission */
  EntityID _emittingEntityID; 

  /** ID of event */
  EventID _eventID; 

  /** This field shall be used to indicate whether the data in the UA PDU represent a state update or data that have changed since issuance of the last UA PDU */
  char _stateChangeIndicator; 

  /** padding */
  char _pad; 

  /** This field indicates which database record (or file) shall be used in the definition of passive signature (unintentional) emissions of the entity. The indicated database record (or  file) shall define all noise generated as a function of propulsion plant configurations and associated  auxiliaries. */
  unsigned short _passiveParameterIndex; 

  /** This field shall specify the entity propulsion plant configuration. This field is used to determine the passive signature characteristics of an entity. */
  uint8_t _propulsionPlantConfiguration; 

  /**  This field shall represent the number of shafts on a platform */
  uint8_t _numberOfShafts; 

  /** This field shall indicate the number of APAs described in the current UA PDU */
  uint8_t _numberOfAPAs; 

  /** This field shall specify the number of UA emitter systems being described in the current UA PDU */
  uint8_t _numberOfUAEmitterSystems; 

  /** shaft RPM values */
  std::vector<ShaftRPMs> _shaftRPMs; 

  /** apaData */
  std::vector<ApaData> _apaData; 

  std::vector<AcousticEmitterSystemData> _emitterSystems; 


 public:
    UaPdu();
    virtual ~UaPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getEmittingEntityID(); 
    const EntityID&  getEmittingEntityID() const; 
    void setEmittingEntityID(const EntityID    &pX);

    EventID& getEventID(); 
    const EventID&  getEventID() const; 
    void setEventID(const EventID    &pX);

    char getStateChangeIndicator() const; 
    void setStateChangeIndicator(char pX); 

    char getPad() const; 
    void setPad(char pX); 

    unsigned short getPassiveParameterIndex() const; 
    void setPassiveParameterIndex(unsigned short pX); 

    uint8_t getPropulsionPlantConfiguration() const; 
    void setPropulsionPlantConfiguration(uint8_t pX); 

    uint8_t getNumberOfShafts() const; 

    uint8_t getNumberOfAPAs() const; 

    uint8_t getNumberOfUAEmitterSystems() const; 

    std::vector<ShaftRPMs>& getShaftRPMs(); 
    const std::vector<ShaftRPMs>& getShaftRPMs() const; 
    void setShaftRPMs(const std::vector<ShaftRPMs>&    pX);

    std::vector<ApaData>& getApaData(); 
    const std::vector<ApaData>& getApaData() const; 
    void setApaData(const std::vector<ApaData>&    pX);

    std::vector<AcousticEmitterSystemData>& getEmitterSystems(); 
    const std::vector<AcousticEmitterSystemData>& getEmitterSystems() const; 
    void setEmitterSystems(const std::vector<AcousticEmitterSystemData>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const UaPdu& rhs) const;
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
