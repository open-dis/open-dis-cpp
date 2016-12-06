#include <DIS/FastEntityStatePdu.h> 

using namespace DIS;


FastEntityStatePdu::FastEntityStatePdu() : EntityInformationFamilyPdu(),
   _site(0), 
   _application(0), 
   _entity(0), 
   _forceId(0), 
   _numberOfVariableParameters(0), 
   _entityKind(0), 
   _domain(0), 
   _country(0), 
   _category(0), 
   _subcategory(0), 
   _specific(0), 
   _extra(0), 
   _altEntityKind(0), 
   _altDomain(0), 
   _altCountry(0), 
   _altCategory(0), 
   _altSubcategory(0), 
   _altSpecific(0), 
   _altExtra(0), 
   _xVelocity(0.0), 
   _yVelocity(0.0), 
   _zVelocity(0.0), 
   _xLocation(0.0), 
   _yLocation(0.0), 
   _zLocation(0.0), 
   _psi(0.0), 
   _theta(0.0), 
   _phi(0.0), 
   _entityAppearance(0), 
   _deadReckoningAlgorithm(0), 
   _xAcceleration(0.0), 
   _yAcceleration(0.0), 
   _zAcceleration(0.0), 
   _xAngularVelocity(0.0), 
   _yAngularVelocity(0.0), 
   _zAngularVelocity(0.0), 
   _capabilities(0)
{
    setPduType( 1 );
     // Initialize fixed length array
     for(int lengthotherParameters= 0; lengthotherParameters < 15; lengthotherParameters++)
     {
         _otherParameters[lengthotherParameters] = 0;
     }

     // Initialize fixed length array
     for(int lengthmarking= 0; lengthmarking < 12; lengthmarking++)
     {
         _marking[lengthmarking] = 0;
     }

}

FastEntityStatePdu::~FastEntityStatePdu()
{
    _variableParameters.clear();
}

unsigned short FastEntityStatePdu::getSite() const
{
    return _site;
}

void FastEntityStatePdu::setSite(unsigned short pX)
{
    _site = pX;
}

unsigned short FastEntityStatePdu::getApplication() const
{
    return _application;
}

void FastEntityStatePdu::setApplication(unsigned short pX)
{
    _application = pX;
}

unsigned short FastEntityStatePdu::getEntity() const
{
    return _entity;
}

void FastEntityStatePdu::setEntity(unsigned short pX)
{
    _entity = pX;
}

unsigned char FastEntityStatePdu::getForceId() const
{
    return _forceId;
}

void FastEntityStatePdu::setForceId(unsigned char pX)
{
    _forceId = pX;
}

char FastEntityStatePdu::getNumberOfVariableParameters() const
{
   return _variableParameters.size();
}

unsigned char FastEntityStatePdu::getEntityKind() const
{
    return _entityKind;
}

void FastEntityStatePdu::setEntityKind(unsigned char pX)
{
    _entityKind = pX;
}

unsigned char FastEntityStatePdu::getDomain() const
{
    return _domain;
}

void FastEntityStatePdu::setDomain(unsigned char pX)
{
    _domain = pX;
}

unsigned short FastEntityStatePdu::getCountry() const
{
    return _country;
}

void FastEntityStatePdu::setCountry(unsigned short pX)
{
    _country = pX;
}

unsigned char FastEntityStatePdu::getCategory() const
{
    return _category;
}

void FastEntityStatePdu::setCategory(unsigned char pX)
{
    _category = pX;
}

unsigned char FastEntityStatePdu::getSubcategory() const
{
    return _subcategory;
}

void FastEntityStatePdu::setSubcategory(unsigned char pX)
{
    _subcategory = pX;
}

unsigned char FastEntityStatePdu::getSpecific() const
{
    return _specific;
}

void FastEntityStatePdu::setSpecific(unsigned char pX)
{
    _specific = pX;
}

unsigned char FastEntityStatePdu::getExtra() const
{
    return _extra;
}

void FastEntityStatePdu::setExtra(unsigned char pX)
{
    _extra = pX;
}

unsigned char FastEntityStatePdu::getAltEntityKind() const
{
    return _altEntityKind;
}

void FastEntityStatePdu::setAltEntityKind(unsigned char pX)
{
    _altEntityKind = pX;
}

unsigned char FastEntityStatePdu::getAltDomain() const
{
    return _altDomain;
}

void FastEntityStatePdu::setAltDomain(unsigned char pX)
{
    _altDomain = pX;
}

unsigned short FastEntityStatePdu::getAltCountry() const
{
    return _altCountry;
}

void FastEntityStatePdu::setAltCountry(unsigned short pX)
{
    _altCountry = pX;
}

unsigned char FastEntityStatePdu::getAltCategory() const
{
    return _altCategory;
}

void FastEntityStatePdu::setAltCategory(unsigned char pX)
{
    _altCategory = pX;
}

unsigned char FastEntityStatePdu::getAltSubcategory() const
{
    return _altSubcategory;
}

void FastEntityStatePdu::setAltSubcategory(unsigned char pX)
{
    _altSubcategory = pX;
}

unsigned char FastEntityStatePdu::getAltSpecific() const
{
    return _altSpecific;
}

void FastEntityStatePdu::setAltSpecific(unsigned char pX)
{
    _altSpecific = pX;
}

unsigned char FastEntityStatePdu::getAltExtra() const
{
    return _altExtra;
}

void FastEntityStatePdu::setAltExtra(unsigned char pX)
{
    _altExtra = pX;
}

float FastEntityStatePdu::getXVelocity() const
{
    return _xVelocity;
}

void FastEntityStatePdu::setXVelocity(float pX)
{
    _xVelocity = pX;
}

float FastEntityStatePdu::getYVelocity() const
{
    return _yVelocity;
}

void FastEntityStatePdu::setYVelocity(float pX)
{
    _yVelocity = pX;
}

float FastEntityStatePdu::getZVelocity() const
{
    return _zVelocity;
}

void FastEntityStatePdu::setZVelocity(float pX)
{
    _zVelocity = pX;
}

double FastEntityStatePdu::getXLocation() const
{
    return _xLocation;
}

void FastEntityStatePdu::setXLocation(double pX)
{
    _xLocation = pX;
}

double FastEntityStatePdu::getYLocation() const
{
    return _yLocation;
}

void FastEntityStatePdu::setYLocation(double pX)
{
    _yLocation = pX;
}

double FastEntityStatePdu::getZLocation() const
{
    return _zLocation;
}

void FastEntityStatePdu::setZLocation(double pX)
{
    _zLocation = pX;
}

float FastEntityStatePdu::getPsi() const
{
    return _psi;
}

void FastEntityStatePdu::setPsi(float pX)
{
    _psi = pX;
}

float FastEntityStatePdu::getTheta() const
{
    return _theta;
}

void FastEntityStatePdu::setTheta(float pX)
{
    _theta = pX;
}

float FastEntityStatePdu::getPhi() const
{
    return _phi;
}

void FastEntityStatePdu::setPhi(float pX)
{
    _phi = pX;
}

int FastEntityStatePdu::getEntityAppearance() const
{
    return _entityAppearance;
}

void FastEntityStatePdu::setEntityAppearance(int pX)
{
    _entityAppearance = pX;
}

unsigned char FastEntityStatePdu::getDeadReckoningAlgorithm() const
{
    return _deadReckoningAlgorithm;
}

void FastEntityStatePdu::setDeadReckoningAlgorithm(unsigned char pX)
{
    _deadReckoningAlgorithm = pX;
}

char* FastEntityStatePdu::getOtherParameters() 
{
    return _otherParameters;
}

const char* FastEntityStatePdu::getOtherParameters() const
{
    return _otherParameters;
}

void FastEntityStatePdu::setOtherParameters(const char* x)
{
   for(int i = 0; i < 15; i++)
   {
        _otherParameters[i] = x[i];
   }
}

float FastEntityStatePdu::getXAcceleration() const
{
    return _xAcceleration;
}

void FastEntityStatePdu::setXAcceleration(float pX)
{
    _xAcceleration = pX;
}

float FastEntityStatePdu::getYAcceleration() const
{
    return _yAcceleration;
}

void FastEntityStatePdu::setYAcceleration(float pX)
{
    _yAcceleration = pX;
}

float FastEntityStatePdu::getZAcceleration() const
{
    return _zAcceleration;
}

void FastEntityStatePdu::setZAcceleration(float pX)
{
    _zAcceleration = pX;
}

float FastEntityStatePdu::getXAngularVelocity() const
{
    return _xAngularVelocity;
}

void FastEntityStatePdu::setXAngularVelocity(float pX)
{
    _xAngularVelocity = pX;
}

float FastEntityStatePdu::getYAngularVelocity() const
{
    return _yAngularVelocity;
}

void FastEntityStatePdu::setYAngularVelocity(float pX)
{
    _yAngularVelocity = pX;
}

float FastEntityStatePdu::getZAngularVelocity() const
{
    return _zAngularVelocity;
}

void FastEntityStatePdu::setZAngularVelocity(float pX)
{
    _zAngularVelocity = pX;
}

char* FastEntityStatePdu::getMarking() 
{
    return _marking;
}

const char* FastEntityStatePdu::getMarking() const
{
    return _marking;
}

void FastEntityStatePdu::setMarking(const char* x)
{
   for(int i = 0; i < 12; i++)
   {
        _marking[i] = x[i];
   }
}

// An alternate method to set the value if this could be a string. This is not strictly comnpliant with the DIS standard.
void FastEntityStatePdu::setByStringMarking(const char* x)
{
   strncpy(_marking, x, 12-1);
   _marking[12 -1] = '\0';
}

int FastEntityStatePdu::getCapabilities() const
{
    return _capabilities;
}

void FastEntityStatePdu::setCapabilities(int pX)
{
    _capabilities = pX;
}

std::vector<VariableParameter>& FastEntityStatePdu::getVariableParameters() 
{
    return _variableParameters;
}

const std::vector<VariableParameter>& FastEntityStatePdu::getVariableParameters() const
{
    return _variableParameters;
}

void FastEntityStatePdu::setVariableParameters(const std::vector<VariableParameter>& pX)
{
     _variableParameters = pX;
}

void FastEntityStatePdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _site;
    dataStream << _application;
    dataStream << _entity;
    dataStream << _forceId;
    dataStream << ( char )_variableParameters.size();
    dataStream << _entityKind;
    dataStream << _domain;
    dataStream << _country;
    dataStream << _category;
    dataStream << _subcategory;
    dataStream << _specific;
    dataStream << _extra;
    dataStream << _altEntityKind;
    dataStream << _altDomain;
    dataStream << _altCountry;
    dataStream << _altCategory;
    dataStream << _altSubcategory;
    dataStream << _altSpecific;
    dataStream << _altExtra;
    dataStream << _xVelocity;
    dataStream << _yVelocity;
    dataStream << _zVelocity;
    dataStream << _xLocation;
    dataStream << _yLocation;
    dataStream << _zLocation;
    dataStream << _psi;
    dataStream << _theta;
    dataStream << _phi;
    dataStream << _entityAppearance;
    dataStream << _deadReckoningAlgorithm;

     for(size_t idx = 0; idx < 15; idx++)
     {
        dataStream << _otherParameters[idx];
     }

    dataStream << _xAcceleration;
    dataStream << _yAcceleration;
    dataStream << _zAcceleration;
    dataStream << _xAngularVelocity;
    dataStream << _yAngularVelocity;
    dataStream << _zAngularVelocity;

     for(size_t idx = 0; idx < 12; idx++)
     {
        dataStream << _marking[idx];
     }

    dataStream << _capabilities;

     for(size_t idx = 0; idx < _variableParameters.size(); idx++)
     {
        VariableParameter x = _variableParameters[idx];
        x.marshal(dataStream);
     }

}

void FastEntityStatePdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _site;
    dataStream >> _application;
    dataStream >> _entity;
    dataStream >> _forceId;
    dataStream >> _numberOfVariableParameters;
    dataStream >> _entityKind;
    dataStream >> _domain;
    dataStream >> _country;
    dataStream >> _category;
    dataStream >> _subcategory;
    dataStream >> _specific;
    dataStream >> _extra;
    dataStream >> _altEntityKind;
    dataStream >> _altDomain;
    dataStream >> _altCountry;
    dataStream >> _altCategory;
    dataStream >> _altSubcategory;
    dataStream >> _altSpecific;
    dataStream >> _altExtra;
    dataStream >> _xVelocity;
    dataStream >> _yVelocity;
    dataStream >> _zVelocity;
    dataStream >> _xLocation;
    dataStream >> _yLocation;
    dataStream >> _zLocation;
    dataStream >> _psi;
    dataStream >> _theta;
    dataStream >> _phi;
    dataStream >> _entityAppearance;
    dataStream >> _deadReckoningAlgorithm;

     for(size_t idx = 0; idx < 15; idx++)
     {
        dataStream >> _otherParameters[idx];
     }

    dataStream >> _xAcceleration;
    dataStream >> _yAcceleration;
    dataStream >> _zAcceleration;
    dataStream >> _xAngularVelocity;
    dataStream >> _yAngularVelocity;
    dataStream >> _zAngularVelocity;

     for(size_t idx = 0; idx < 12; idx++)
     {
        dataStream >> _marking[idx];
     }

    dataStream >> _capabilities;

     _variableParameters.clear();
     for(size_t idx = 0; idx < _numberOfVariableParameters; idx++)
     {
        VariableParameter x;
        x.unmarshal(dataStream);
        _variableParameters.push_back(x);
     }
}


bool FastEntityStatePdu::operator ==(const FastEntityStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (_site == rhs._site) ) ivarsEqual = false;
     if( ! (_application == rhs._application) ) ivarsEqual = false;
     if( ! (_entity == rhs._entity) ) ivarsEqual = false;
     if( ! (_forceId == rhs._forceId) ) ivarsEqual = false;
     if( ! (_entityKind == rhs._entityKind) ) ivarsEqual = false;
     if( ! (_domain == rhs._domain) ) ivarsEqual = false;
     if( ! (_country == rhs._country) ) ivarsEqual = false;
     if( ! (_category == rhs._category) ) ivarsEqual = false;
     if( ! (_subcategory == rhs._subcategory) ) ivarsEqual = false;
     if( ! (_specific == rhs._specific) ) ivarsEqual = false;
     if( ! (_extra == rhs._extra) ) ivarsEqual = false;
     if( ! (_altEntityKind == rhs._altEntityKind) ) ivarsEqual = false;
     if( ! (_altDomain == rhs._altDomain) ) ivarsEqual = false;
     if( ! (_altCountry == rhs._altCountry) ) ivarsEqual = false;
     if( ! (_altCategory == rhs._altCategory) ) ivarsEqual = false;
     if( ! (_altSubcategory == rhs._altSubcategory) ) ivarsEqual = false;
     if( ! (_altSpecific == rhs._altSpecific) ) ivarsEqual = false;
     if( ! (_altExtra == rhs._altExtra) ) ivarsEqual = false;
     if( ! (_xVelocity == rhs._xVelocity) ) ivarsEqual = false;
     if( ! (_yVelocity == rhs._yVelocity) ) ivarsEqual = false;
     if( ! (_zVelocity == rhs._zVelocity) ) ivarsEqual = false;
     if( ! (_xLocation == rhs._xLocation) ) ivarsEqual = false;
     if( ! (_yLocation == rhs._yLocation) ) ivarsEqual = false;
     if( ! (_zLocation == rhs._zLocation) ) ivarsEqual = false;
     if( ! (_psi == rhs._psi) ) ivarsEqual = false;
     if( ! (_theta == rhs._theta) ) ivarsEqual = false;
     if( ! (_phi == rhs._phi) ) ivarsEqual = false;
     if( ! (_entityAppearance == rhs._entityAppearance) ) ivarsEqual = false;
     if( ! (_deadReckoningAlgorithm == rhs._deadReckoningAlgorithm) ) ivarsEqual = false;

     for(char idx = 0; idx < 15; idx++)
     {
          if(!(_otherParameters[idx] == rhs._otherParameters[idx]) ) ivarsEqual = false;
     }

     if( ! (_xAcceleration == rhs._xAcceleration) ) ivarsEqual = false;
     if( ! (_yAcceleration == rhs._yAcceleration) ) ivarsEqual = false;
     if( ! (_zAcceleration == rhs._zAcceleration) ) ivarsEqual = false;
     if( ! (_xAngularVelocity == rhs._xAngularVelocity) ) ivarsEqual = false;
     if( ! (_yAngularVelocity == rhs._yAngularVelocity) ) ivarsEqual = false;
     if( ! (_zAngularVelocity == rhs._zAngularVelocity) ) ivarsEqual = false;

     for(char idx = 0; idx < 12; idx++)
     {
          if(!(_marking[idx] == rhs._marking[idx]) ) ivarsEqual = false;
     }

     if( ! (_capabilities == rhs._capabilities) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _variableParameters.size(); idx++)
     {
        if( ! ( _variableParameters[idx] == rhs._variableParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int FastEntityStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 2;  // _site
   marshalSize = marshalSize + 2;  // _application
   marshalSize = marshalSize + 2;  // _entity
   marshalSize = marshalSize + 1;  // _forceId
   marshalSize = marshalSize + 1;  // _numberOfVariableParameters
   marshalSize = marshalSize + 1;  // _entityKind
   marshalSize = marshalSize + 1;  // _domain
   marshalSize = marshalSize + 2;  // _country
   marshalSize = marshalSize + 1;  // _category
   marshalSize = marshalSize + 1;  // _subcategory
   marshalSize = marshalSize + 1;  // _specific
   marshalSize = marshalSize + 1;  // _extra
   marshalSize = marshalSize + 1;  // _altEntityKind
   marshalSize = marshalSize + 1;  // _altDomain
   marshalSize = marshalSize + 2;  // _altCountry
   marshalSize = marshalSize + 1;  // _altCategory
   marshalSize = marshalSize + 1;  // _altSubcategory
   marshalSize = marshalSize + 1;  // _altSpecific
   marshalSize = marshalSize + 1;  // _altExtra
   marshalSize = marshalSize + 4;  // _xVelocity
   marshalSize = marshalSize + 4;  // _yVelocity
   marshalSize = marshalSize + 4;  // _zVelocity
   marshalSize = marshalSize + 8;  // _xLocation
   marshalSize = marshalSize + 8;  // _yLocation
   marshalSize = marshalSize + 8;  // _zLocation
   marshalSize = marshalSize + 4;  // _psi
   marshalSize = marshalSize + 4;  // _theta
   marshalSize = marshalSize + 4;  // _phi
   marshalSize = marshalSize + 4;  // _entityAppearance
   marshalSize = marshalSize + 1;  // _deadReckoningAlgorithm
   marshalSize = marshalSize + 15 * 1;  // _otherParameters
   marshalSize = marshalSize + 4;  // _xAcceleration
   marshalSize = marshalSize + 4;  // _yAcceleration
   marshalSize = marshalSize + 4;  // _zAcceleration
   marshalSize = marshalSize + 4;  // _xAngularVelocity
   marshalSize = marshalSize + 4;  // _yAngularVelocity
   marshalSize = marshalSize + 4;  // _zAngularVelocity
   marshalSize = marshalSize + 12 * 1;  // _marking
   marshalSize = marshalSize + 4;  // _capabilities

   for(int idx=0; idx < _variableParameters.size(); idx++)
   {
        VariableParameter listElement = _variableParameters[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

    return marshalSize;
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
