#ifndef STORAGEFUELRELOAD_H
#define STORAGEFUELRELOAD_H

#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// For each type or location of Storage Fuel, this record shall specify the type, location, fuel measure- ment units, reload quantity and maximum quantity for storage fuel either for the whole entity or a specific storage fuel location (tank). Section 6.2.84.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO StorageFuelReload
{
protected:
  /**  the standard quantity of this fuel type normally loaded at this station/launcher if a station/launcher is specified. If the Station/Launcher field is set to zero, then this is the total quantity of this fuel type that would be present in a standard reload of all appli- cable stations/launchers associated with this entity. */
  unsigned int _standardQuantity; 

  /** the maximum quantity of this fuel type that this sta- tion/launcher is capable of holding when a station/launcher is specified. This would be the value used when a maximum reload was desired to be set for this station/launcher. If the Station/launcher field is set to zero, then this is the maximum quantity of this fuel type that would be present on this entity at all stations/launchers that can accept this fuel type. */
  unsigned int _maximumQuantity; 

  /** the seconds normally required to reload the standard quantity of this fuel type at this specific station/launcher. When the Station/Launcher field is set to zero, this shall be the time it takes to perform a standard quantity reload of this fuel type at all applicable stations/launchers for this entity. */
  unsigned char _standardQuantityReloadTime; 

  /** the seconds normally required to reload the maximum possible quantity of this fuel type at this station/launcher. When the Station/Launcher field is set to zero, this shall be the time it takes to perform a maximum quantity load/reload of this fuel type at all applicable stations/launchers for this entity. */
  unsigned char _maximumQuantityReloadTime; 

  /** the fuel measurement units. Enumeration */
  unsigned char _fuelMeasurementUnits; 

  /** Fuel type. Enumeration */
  unsigned char _fuelType; 

  /** Location of fuel as related to entity. See section 14 of EBV document */
  unsigned char _fuelLocation; 

  /** padding */
  unsigned char _padding; 


 public:
    StorageFuelReload();
    virtual ~StorageFuelReload();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getStandardQuantity() const; 
    void setStandardQuantity(unsigned int pX); 

    unsigned int getMaximumQuantity() const; 
    void setMaximumQuantity(unsigned int pX); 

    unsigned char getStandardQuantityReloadTime() const; 
    void setStandardQuantityReloadTime(unsigned char pX); 

    unsigned char getMaximumQuantityReloadTime() const; 
    void setMaximumQuantityReloadTime(unsigned char pX); 

    unsigned char getFuelMeasurementUnits() const; 
    void setFuelMeasurementUnits(unsigned char pX); 

    unsigned char getFuelType() const; 
    void setFuelType(unsigned char pX); 

    unsigned char getFuelLocation() const; 
    void setFuelLocation(unsigned char pX); 

    unsigned char getPadding() const; 
    void setPadding(unsigned char pX); 


virtual int getMarshalledSize() const;

     bool operator  ==(const StorageFuelReload& rhs) const;
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
