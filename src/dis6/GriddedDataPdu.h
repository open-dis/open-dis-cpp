#pragma once

#include <dis6/EntityID.h>
#include <dis6/EntityType.h>
#include <dis6/Orientation.h>
#include <dis6/GridAxisRecord.h>
#include <vector>
#include <dis6/SyntheticEnvironmentFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis6/msLibMacro.h>


namespace DIS
{
// Section 5.3.11.2: Information about globat, spatially varying enviornmental effects. This requires manual cleanup; the grid axis        records are variable sized. UNFINISHED

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO GriddedDataPdu : public SyntheticEnvironmentFamilyPdu
{
protected:
  /** environmental simulation application ID */
  EntityID _environmentalSimulationApplicationID; 

  /** unique identifier for each piece of enviornmental data */
  unsigned short _fieldNumber; 

  /** sequence number for the total set of PDUS used to transmit the data */
  unsigned short _pduNumber; 

  /** Total number of PDUS used to transmit the data */
  unsigned short _pduTotal; 

  /** coordinate system of the grid */
  unsigned short _coordinateSystem; 

  /** number of grid axes for the environmental data */
  unsigned char _numberOfGridAxes; 

  /** are domain grid axes identidal to those of the priveious domain update? */
  unsigned char _constantGrid; 

  /** type of environment */
  EntityType _environmentType; 

  /** orientation of the data grid */
  Orientation _orientation; 

  /** valid time of the enviormental data sample, 64 bit unsigned int */
  unsigned long long _sampleTime;

  /** total number of all data values for all pdus for an environmental sample */
  unsigned int _totalValues; 

  /** total number of data values at each grid point. */
  unsigned char _vectorDimension; 

  /** padding */
  unsigned short _padding1; 

  /** padding */
  unsigned char _padding2; 

  /** Grid data ^^^This is wrong */
  std::vector<GridAxisRecord> _gridDataList; 


 public:
    GriddedDataPdu();
    virtual ~GriddedDataPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getEnvironmentalSimulationApplicationID(); 
    const EntityID&  getEnvironmentalSimulationApplicationID() const; 
    void setEnvironmentalSimulationApplicationID(const EntityID    &pX);

    unsigned short getFieldNumber() const; 
    void setFieldNumber(unsigned short pX); 

    unsigned short getPduNumber() const; 
    void setPduNumber(unsigned short pX); 

    unsigned short getPduTotal() const; 
    void setPduTotal(unsigned short pX); 

    unsigned short getCoordinateSystem() const; 
    void setCoordinateSystem(unsigned short pX); 

    unsigned char getNumberOfGridAxes() const; 

    unsigned char getConstantGrid() const; 
    void setConstantGrid(unsigned char pX); 

    EntityType& getEnvironmentType(); 
    const EntityType&  getEnvironmentType() const; 
    void setEnvironmentType(const EntityType    &pX);

    Orientation& getOrientation(); 
    const Orientation&  getOrientation() const; 
    void setOrientation(const Orientation    &pX);

    unsigned long long getSampleTime() const;
    void setSampleTime(unsigned long long pX);

    unsigned int getTotalValues() const; 
    void setTotalValues(unsigned int pX); 

    unsigned char getVectorDimension() const; 
    void setVectorDimension(unsigned char pX); 

    unsigned short getPadding1() const; 
    void setPadding1(unsigned short pX); 

    unsigned char getPadding2() const; 
    void setPadding2(unsigned char pX); 

    std::vector<GridAxisRecord>& getGridDataList(); 
    const std::vector<GridAxisRecord>& getGridDataList() const; 
    void setGridDataList(const std::vector<GridAxisRecord>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const GriddedDataPdu& rhs) const;
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
