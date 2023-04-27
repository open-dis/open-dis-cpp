#include "dis6/SignalPdu.h"

using namespace DIS;

SignalPdu::SignalPdu()
    : RadioCommunicationsFamilyPdu(),
      _encodingScheme(0),
      _tdlType(0),
      _sampleRate(0),
      _dataLength(0),
      _samples(0) {
  setPduType(26);
}

SignalPdu::~SignalPdu() { _data.clear(); }

uint16_t SignalPdu::getEncodingScheme() const { return _encodingScheme; }

void SignalPdu::setEncodingScheme(uint16_t pX) { _encodingScheme = pX; }

uint16_t SignalPdu::getTdlType() const { return _tdlType; }

void SignalPdu::setTdlType(uint16_t pX) { _tdlType = pX; }

uint32_t SignalPdu::getSampleRate() const { return _sampleRate; }

void SignalPdu::setSampleRate(uint32_t pX) { _sampleRate = pX; }

int16_t SignalPdu::getDataLength() const { return _data.size(); }

int16_t SignalPdu::getSamples() const { return _samples; }

void SignalPdu::setSamples(int16_t pX) { _samples = pX; }

std::vector<uint8_t>& SignalPdu::getData() { return _data; }

const std::vector<uint8_t>& SignalPdu::getData() const { return _data; }

void SignalPdu::setData(const std::vector<uint8_t>& pX) { _data = pX; }

void SignalPdu::marshal(DataStream& dataStream) const {
  RadioCommunicationsFamilyPdu::marshal(
      dataStream);  // Marshal information in superclass first
  dataStream << _encodingScheme;
  dataStream << _tdlType;
  dataStream << _sampleRate;
  dataStream << (int16_t)_data.size();
  dataStream << _samples;
  for (auto byte : _data) {
    dataStream << byte;
  }
}

void SignalPdu::unmarshal(DataStream& dataStream) {
  RadioCommunicationsFamilyPdu::unmarshal(
      dataStream);  // unmarshal information in superclass first
  dataStream >> _encodingScheme;
  dataStream >> _tdlType;
  dataStream >> _sampleRate;
  dataStream >> _dataLength;
  dataStream >> _samples;

  _data.clear();
  for (auto idx = 0; idx < _dataLength; ++idx) {
    uint8_t x;
    dataStream >> x;
    _data.push_back(x);
  }
}

bool SignalPdu::operator==(const SignalPdu& rhs) const {
  auto ivarsEqual = true;

  ivarsEqual = RadioCommunicationsFamilyPdu::operator==(rhs) &&
               _encodingScheme == rhs._encodingScheme &&
               _tdlType == rhs._tdlType && _sampleRate == rhs._sampleRate &&
               _samples == rhs._samples && _data == rhs._data;

  return ivarsEqual;
}

int SignalPdu::getMarshalledSize() const {
  auto marshalSize = 0;

  marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize();
  marshalSize += 2;  // _encodingScheme
  marshalSize += 2;  // _tdlType
  marshalSize += 4;  // _sampleRate
  marshalSize += 2;  // _dataLength
  marshalSize += 2;  // _samples
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
