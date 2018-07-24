#ifndef ENGINEFUELRELOAD_H
#define ENGINEFUELRELOAD_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// For each type or location of engine fuell, this record specifies the type, location, fuel measurement units, and reload quantity and maximum quantity. Section 6.2.25.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO EngineFuelReload
{
protected:
  /** standard quantity of fuel loaded */
  unsigned int _standardQuantity; 

  /** maximum quantity of fuel loaded */
  unsigned int _maximumQuantity; 

  /** seconds normally required to to reload standard qty */
  unsigned int _standardQuantityReloadTime; 

  /** seconds normally required to to reload maximum qty */
  unsigned int _maximumQuantityReloadTime; 

  /** Units of measure */
  unsigned char _fuelMeasurmentUnits; 

  /** fuel  location as related to the entity */
  unsigned char _fuelLocation; 

  /** padding */
  unsigned char _padding; 


 public:
    EngineFuelReload();
    virtual ~EngineFuelReload();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getStandardQuantity() const; 
    void setStandardQuantity(unsigned int pX); 

    unsigned int getMaximumQuantity() const; 
    void setMaximumQuantity(unsigned int pX); 

    unsigned int getStandardQuantityReloadTime() const; 
    void setStandardQuantityReloadTime(unsigned int pX); 

    unsigned int getMaximumQuantityReloadTime() const; 
    void setMaximumQuantityReloadTime(unsigned int pX); 

    unsigned char getFuelMeasurmentUnits() const; 
    void setFuelMeasurmentUnits(unsigned char pX); 

    unsigned char getFuelLocation() const; 
    void setFuelLocation(unsigned char pX); 

    unsigned char getPadding() const; 
    void setPadding(unsigned char pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const EngineFuelReload& rhs) const;
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
