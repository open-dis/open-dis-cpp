#pragma once

#include <dis6/EntityID.h>
#include <dis6/EntityID.h>
#include <dis6/EntityType.h>
#include <dis6/TwoByteChunk.h>
#include <dis6/Vector3Float.h>
#include <vector>
#include <dis6/MinefieldFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.10.3 Information about individual mines within a minefield. This is very, very wrong. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO MinefieldDataPdu : public MinefieldFamilyPdu
{
protected:
  /** Minefield ID */
  EntityID _minefieldID; 

  /** ID of entity making request */
  EntityID _requestingEntityID; 

  /** Minefield sequence number */
  unsigned short _minefieldSequenceNumbeer; 

  /** request ID */
  unsigned char _requestID; 

  /** pdu sequence number */
  unsigned char _pduSequenceNumber; 

  /** number of pdus in response */
  unsigned char _numberOfPdus; 

  /** how many mines are in this PDU */
  unsigned char _numberOfMinesInThisPdu; 

  /** how many sensor type are in this PDU */
  unsigned char _numberOfSensorTypes; 

  /** padding */
  unsigned char _pad2; 

  /** 32 boolean fields */
  unsigned int _dataFilter; 

  /** Mine type */
  EntityType _mineType; 

  /** Sensor types, each 16 bits long */
  std::vector<TwoByteChunk> _sensorTypes; 

  /** Padding to get things 32-bit aligned. ^^^this is wrong--dyanmically sized padding needed */
  unsigned char _pad3; 

  /** Mine locations */
  std::vector<Vector3Float> _mineLocation; 


 public:
    MinefieldDataPdu();
    virtual ~MinefieldDataPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getMinefieldID(); 
    const EntityID&  getMinefieldID() const; 
    void setMinefieldID(const EntityID    &pX);

    EntityID& getRequestingEntityID(); 
    const EntityID&  getRequestingEntityID() const; 
    void setRequestingEntityID(const EntityID    &pX);

    unsigned short getMinefieldSequenceNumbeer() const; 
    void setMinefieldSequenceNumbeer(unsigned short pX); 

    unsigned char getRequestID() const; 
    void setRequestID(unsigned char pX); 

    unsigned char getPduSequenceNumber() const; 
    void setPduSequenceNumber(unsigned char pX); 

    unsigned char getNumberOfPdus() const; 
    void setNumberOfPdus(unsigned char pX); 

    unsigned char getNumberOfMinesInThisPdu() const; 

    unsigned char getNumberOfSensorTypes() const; 

    unsigned char getPad2() const; 
    void setPad2(unsigned char pX); 

    unsigned int getDataFilter() const; 
    void setDataFilter(unsigned int pX); 

    EntityType& getMineType(); 
    const EntityType&  getMineType() const; 
    void setMineType(const EntityType    &pX);

    std::vector<TwoByteChunk>& getSensorTypes(); 
    const std::vector<TwoByteChunk>& getSensorTypes() const; 
    void setSensorTypes(const std::vector<TwoByteChunk>&    pX);

    unsigned char getPad3() const; 
    void setPad3(unsigned char pX); 

    std::vector<Vector3Float>& getMineLocation(); 
    const std::vector<Vector3Float>& getMineLocation() const; 
    void setMineLocation(const std::vector<Vector3Float>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const MinefieldDataPdu& rhs) const;
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
