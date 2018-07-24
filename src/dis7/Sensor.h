#ifndef SENSOR_H
#define SENSOR_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// An entity's sensor information.  Section 6.2.77.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO Sensor
{
protected:
  /**  the source of the Sensor Type field  */
  unsigned char _sensorTypeSource; 

  /** the on/off status of the sensor */
  unsigned char _sensorOnOffStatus; 

  /** the sensor type and shall be represented by a 16-bit enumeration.  */
  unsigned short _sensorType; 

  /**  the station to which the sensor is assigned. A zero value shall indi- cate that this Sensor record is not associated with any particular station and represents the total quan- tity of this sensor for this entity. If this field is non-zero, it shall either reference an attached part or an articulated part */
  unsigned int _station; 

  /** quantity of the sensor  */
  unsigned short _quantity; 

  /** padding */
  unsigned short _padding; 


 public:
    Sensor();
    virtual ~Sensor();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned char getSensorTypeSource() const; 
    void setSensorTypeSource(unsigned char pX); 

    unsigned char getSensorOnOffStatus() const; 
    void setSensorOnOffStatus(unsigned char pX); 

    unsigned short getSensorType() const; 
    void setSensorType(unsigned short pX); 

    unsigned int getStation() const; 
    void setStation(unsigned int pX); 

    unsigned short getQuantity() const; 
    void setQuantity(unsigned short pX); 

    unsigned short getPadding() const; 
    void setPadding(unsigned short pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const Sensor& rhs) const;
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
