#pragma once

#include <vector>

#include "dis7/BeamData.h"
#include "dis7/DistributedEmissionsFamilyPdu.h"
#include "dis7/EntityID.h"
#include "dis7/EventIdentifier.h"
#include "dis7/FundamentalOperationalData.h"
#include "dis7/IFFFundamentalParameterData.h"
#include "dis7/LayerHeader.h"
#include "dis7/SecondaryOperationalData.h"
#include "dis7/SystemIdentifier.h"
#include "dis7/Vector3Float.h"
#include "dis7/opendis7_export.h"
#include "dis7/utils/DataStream.h"

namespace DIS {
// This PDU is written according SISO Standard, the link is on below:
// https://www.sisostds.org/DesktopModules/Bring2mind/DMX/API/Entries/Download?Command=Core_Download&EntryId=36292&PortalId=0&TabId=105
// Another good document for DIS v6 and v7 is:
// https://www.sisostds.org/DesktopModules/Bring2mind/DMX/API/Entries/Download?Command=Core_Download&EntryId=29289&PortalId=0&TabId=105

// @author semihkurt , 09/04/2021

class OPENDIS7_EXPORT IFFPdu : public DistributedEmissionsFamilyPdu {
 protected:
  /** ID of the entity emitting */
  EntityID _emittingEntityID;

  /** ID of event */
  EventIdentifier _eventID;

  Vector3Float _relativeAntennaLocation;

  /** How many iff parameters are in the variable length list */
  uint32_t _numberOfIFFParameters;

  SystemIdentifier _systemID;

  uint8_t _systemDesignator;

  uint8_t _systemSpecificData;

  FundamentalOperationalData _fundamentalOperationalData;

  LayerHeader _layerHeader;

  BeamData _beamData;

  SecondaryOperationalData _secondaryOperationalData;

  std::vector<IFFFundamentalParameterData> _iffParameters;

 public:
  IFFPdu();
  virtual ~IFFPdu();

  virtual void marshal(DataStream& dataStream) const;
  virtual void unmarshal(DataStream& dataStream);

  EntityID& getEmittingEntityID();
  const EntityID& getEmittingEntityID() const;
  void setEmittingEntityID(const EntityID& pX);

  EventIdentifier& getEventID();
  const EventIdentifier& getEventID() const;
  void setEventID(const EventIdentifier& pX);

  Vector3Float& getRelativeAntennaLocation();
  const Vector3Float& getRelativeAntennaLocation() const;
  void setRelativeAntennaLocation(const Vector3Float& pX);

  uint32_t getNumberOfIFFParameters() const;

  SystemIdentifier& getSystemID();
  const SystemIdentifier& getSystemID() const;
  void setSystemID(const SystemIdentifier& pX);

  uint8_t getSystemDesignator() const;
  void setSystemDesignator(uint8_t pX);

  uint8_t getSystemSpecificData() const;
  void setSystemSpecificData(uint8_t pX);

  FundamentalOperationalData& getFundamentalOperationalData();
  const FundamentalOperationalData& getFundamentalOperationalData() const;
  void setFundamentalOperationalData(const FundamentalOperationalData& pX);

  LayerHeader& getLayerHeader();
  const LayerHeader& getLayerHeader() const;
  void setLayerHeader(const LayerHeader& pX);

  BeamData& getBeamData();
  const BeamData& getBeamData() const;
  void setBeamData(const BeamData& pX);

  SecondaryOperationalData& getSecondaryOperationalData();
  const SecondaryOperationalData& getSecondaryOperationalData() const;
  void setSecondaryOperationalData(const SecondaryOperationalData& pX);

  std::vector<IFFFundamentalParameterData>& getIFFParameters();
  const std::vector<IFFFundamentalParameterData>& getIFFParameters() const;
  void setIFFParameters(const std::vector<IFFFundamentalParameterData>& pX);

  virtual int getMarshalledSize() const;

  bool operator==(const IFFPdu& rhs) const;
};
}  // namespace DIS
