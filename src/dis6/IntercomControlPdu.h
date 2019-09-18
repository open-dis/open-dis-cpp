#ifndef INTERCOMCONTROLPDU_H
#define INTERCOMCONTROLPDU_H

#include <dis6/EntityID.h>
#include <dis6/EntityID.h>
#include <dis6/IntercomCommunicationsParameters.h>
#include <vector>
#include <dis6/RadioCommunicationsFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.8.5. Detailed inofrmation about the state of an intercom device and the actions it is requestion         of another intercom device, or the response to a requested action. Required manual intervention to fix the intercom parameters,        which can be of varialbe length. UNFINSISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO IntercomControlPdu : public RadioCommunicationsFamilyPdu
{
protected:
  /** control type */
  uint8_t _controlType; 

  /** control type */
  uint8_t _communicationsChannelType; 

  /** Source entity ID */
  EntityID _sourceEntityID; 

  /** The specific intercom device being simulated within an entity. */
  uint8_t _sourceCommunicationsDeviceID; 

  /** Line number to which the intercom control refers */
  uint8_t _sourceLineID; 

  /** priority of this message relative to transmissons from other intercom devices */
  uint8_t _transmitPriority; 

  /** current transmit state of the line */
  uint8_t _transmitLineState; 

  /** detailed type requested. */
  uint8_t _command; 

  /** eid of the entity that has created this intercom channel. */
  EntityID _masterEntityID; 

  /** specific intercom device that has created this intercom channel */
  unsigned short _masterCommunicationsDeviceID; 

  /** number of intercom parameters */
  unsigned int _intercomParametersLength; 

  /** ^^^This is wrong--the length of the data field is variable. Using a long for now. */
  std::vector<IntercomCommunicationsParameters> _intercomParameters; 


 public:
    IntercomControlPdu();
    virtual ~IntercomControlPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    uint8_t getControlType() const; 
    void setControlType(uint8_t pX); 

    uint8_t getCommunicationsChannelType() const; 
    void setCommunicationsChannelType(uint8_t pX); 

    EntityID& getSourceEntityID(); 
    const EntityID&  getSourceEntityID() const; 
    void setSourceEntityID(const EntityID    &pX);

    uint8_t getSourceCommunicationsDeviceID() const; 
    void setSourceCommunicationsDeviceID(uint8_t pX); 

    uint8_t getSourceLineID() const; 
    void setSourceLineID(uint8_t pX); 

    uint8_t getTransmitPriority() const; 
    void setTransmitPriority(uint8_t pX); 

    uint8_t getTransmitLineState() const; 
    void setTransmitLineState(uint8_t pX); 

    uint8_t getCommand() const; 
    void setCommand(uint8_t pX); 

    EntityID& getMasterEntityID(); 
    const EntityID&  getMasterEntityID() const; 
    void setMasterEntityID(const EntityID    &pX);

    unsigned short getMasterCommunicationsDeviceID() const; 
    void setMasterCommunicationsDeviceID(unsigned short pX); 

    unsigned int getIntercomParametersLength() const; 

    std::vector<IntercomCommunicationsParameters>& getIntercomParameters(); 
    const std::vector<IntercomCommunicationsParameters>& getIntercomParameters() const; 
    void setIntercomParameters(const std::vector<IntercomCommunicationsParameters>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const IntercomControlPdu& rhs) const;
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
