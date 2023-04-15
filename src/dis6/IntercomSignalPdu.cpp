#include <dis6/IntercomSignalPdu.h>

using namespace DIS;

IntercomSignalPdu::IntercomSignalPdu()
    : RadioCommunicationsFamilyPdu(), _entityID(), _communicationsDeviceID(0),
      _encodingScheme(0), _tdlType(0), _sampleRate(0), _dataLength(0),
      _samples(0) {
  setPduType(31);
}

IntercomSignalPdu::~IntercomSignalPdu() { _data.clear(); }

EntityID &IntercomSignalPdu::getEntityID() { return _entityID; }

const EntityID &IntercomSignalPdu::getEntityID() const { return _entityID; }

void IntercomSignalPdu::setEntityID(const EntityID &pX) { _entityID = pX; }

unsigned short IntercomSignalPdu::getCommunicationsDeviceID() const {
  return _communicationsDeviceID;
}

void IntercomSignalPdu::setCommunicationsDeviceID(unsigned short pX) {
  _communicationsDeviceID = pX;
}

unsigned short IntercomSignalPdu::getEncodingScheme() const {
  return _encodingScheme;
}

void IntercomSignalPdu::setEncodingScheme(unsigned short pX) {
  _encodingScheme = pX;
}

unsigned short IntercomSignalPdu::getTdlType() const { return _tdlType; }

void IntercomSignalPdu::setTdlType(unsigned short pX) { _tdlType = pX; }

unsigned int IntercomSignalPdu::getSampleRate() const { return _sampleRate; }

void IntercomSignalPdu::setSampleRate(unsigned int pX) { _sampleRate = pX; }

unsigned short IntercomSignalPdu::getDataLength() const { return _data.size(); }

unsigned short IntercomSignalPdu::getSamples() const { return _samples; }

void IntercomSignalPdu::setSamples(unsigned short pX) { _samples = pX; }

std::vector<uint8_t> &IntercomSignalPdu::getData() { return _data; }

const std::vector<uint8_t> &IntercomSignalPdu::getData() const { return _data; }

void IntercomSignalPdu::setData(const std::vector<uint8_t> &pX) { _data = pX; }

void IntercomSignalPdu::marshal(DataStream &dataStream) const {
  RadioCommunicationsFamilyPdu::marshal(
      dataStream); // Marshal information in superclass first
  _entityID.marshal(dataStream);
  dataStream << _communicationsDeviceID;
  dataStream << _encodingScheme;
  dataStream << _tdlType;
  dataStream << _sampleRate;
  dataStream << (unsigned short)_data.size();
  dataStream << _samples;

  for (auto &byte : _data) {
    dataStream << byte;
  }
}

void IntercomSignalPdu::unmarshal(DataStream &dataStream) {
  RadioCommunicationsFamilyPdu::unmarshal(
      dataStream); // unmarshal information in superclass first
  _entityID.unmarshal(dataStream);
  dataStream >> _communicationsDeviceID;
  dataStream >> _encodingScheme;
  dataStream >> _tdlType;
  dataStream >> _sampleRate;
  dataStream >> _dataLength;
  dataStream >> _samples;

  _data.clear();
  for (auto idx = 0; idx < _dataLength; idx++) {
    uint8_t x;
    dataStream >> x;
    _data.push_back(x);
  }
}

bool IntercomSignalPdu::operator==(const IntercomSignalPdu &rhs) const {
  bool ivarsEqual = true;

  ivarsEqual = RadioCommunicationsFamilyPdu::operator==(rhs);

  if (!(_entityID == rhs._entityID))
    ivarsEqual = false;
  if (!(_communicationsDeviceID == rhs._communicationsDeviceID))
    ivarsEqual = false;
  if (!(_encodingScheme == rhs._encodingScheme))
    ivarsEqual = false;
  if (!(_tdlType == rhs._tdlType))
    ivarsEqual = false;
  if (!(_sampleRate == rhs._sampleRate))
    ivarsEqual = false;
  if (!(_samples == rhs._samples))
    ivarsEqual = false;

  ivarsEqual = (_data == rhs._data);

  return ivarsEqual;
}

int IntercomSignalPdu::getMarshalledSize() const {
  int marshalSize = 0;

  marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize();
  marshalSize += _entityID.getMarshalledSize(); // _entityID
  marshalSize += 2;                             // _communicationsDeviceID
  marshalSize += 2;                             // _encodingScheme
  marshalSize += 2;                             // _tdlType
  marshalSize += 4;                             // _sampleRate
  marshalSize += 2;                             // _dataLength
  marshalSize += 2;                             // _samples
  marshalSize += _data.size();

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
