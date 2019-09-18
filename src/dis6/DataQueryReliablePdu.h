#ifndef DATAQUERYRELIABLEPDU_H
#define DATAQUERYRELIABLEPDU_H

#include <dis6/FixedDatum.h>
#include <dis6/VariableDatum.h>
#include <vector>
#include <dis6/SimulationManagementWithReliabilityFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.12.8: request for data from an entity. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO DataQueryReliablePdu : public SimulationManagementWithReliabilityFamilyPdu
{
protected:
  /** level of reliability service used for this transaction */
  uint8_t _requiredReliabilityService; 

  /** padding */
  unsigned short _pad1; 

  /** padding */
  uint8_t _pad2; 

  /** request ID */
  unsigned int _requestID; 

  /** time interval between issuing data query PDUs */
  unsigned int _timeInterval; 

  /** Fixed datum record count */
  unsigned int _numberOfFixedDatumRecords; 

  /** variable datum record count */
  unsigned int _numberOfVariableDatumRecords; 

  /** Fixed datum records */
  std::vector<FixedDatum> _fixedDatumRecords; 

  /** Variable datum records */
  std::vector<VariableDatum> _variableDatumRecords; 


 public:
    DataQueryReliablePdu();
    virtual ~DataQueryReliablePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    uint8_t getRequiredReliabilityService() const; 
    void setRequiredReliabilityService(uint8_t pX); 

    unsigned short getPad1() const; 
    void setPad1(unsigned short pX); 

    uint8_t getPad2() const; 
    void setPad2(uint8_t pX); 

    unsigned int getRequestID() const; 
    void setRequestID(unsigned int pX); 

    unsigned int getTimeInterval() const; 
    void setTimeInterval(unsigned int pX); 

    unsigned int getNumberOfFixedDatumRecords() const; 

    unsigned int getNumberOfVariableDatumRecords() const; 

    std::vector<FixedDatum>& getFixedDatumRecords(); 
    const std::vector<FixedDatum>& getFixedDatumRecords() const; 
    void setFixedDatumRecords(const std::vector<FixedDatum>&    pX);

    std::vector<VariableDatum>& getVariableDatumRecords(); 
    const std::vector<VariableDatum>& getVariableDatumRecords() const; 
    void setVariableDatumRecords(const std::vector<VariableDatum>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const DataQueryReliablePdu& rhs) const;
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
