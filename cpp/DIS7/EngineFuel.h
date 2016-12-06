#ifndef ENGINEFUEL_H
#define ENGINEFUEL_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Information about an entity's engine fuel. Section 6.2.24.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO EngineFuel
{
protected:
  /** Fuel quantity, units specified by next field */
  unsigned int _fuelQuantity; 

  /** Units in which the fuel is measured */
  unsigned char _fuelMeasurementUnits; 

  /** Type of fuel */
  unsigned char _fuelType; 

  /** Location of fuel as related to entity. See section 14 of EBV document */
  unsigned char _fuelLocation; 

  /** padding */
  unsigned char _padding; 


 public:
    EngineFuel();
    virtual ~EngineFuel();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getFuelQuantity() const; 
    void setFuelQuantity(unsigned int pX); 

    unsigned char getFuelMeasurementUnits() const; 
    void setFuelMeasurementUnits(unsigned char pX); 

    unsigned char getFuelType() const; 
    void setFuelType(unsigned char pX); 

    unsigned char getFuelLocation() const; 
    void setFuelLocation(unsigned char pX); 

    unsigned char getPadding() const; 
    void setPadding(unsigned char pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const EngineFuel& rhs) const;
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
