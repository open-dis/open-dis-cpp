/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dcl_dis_incoming_message_
#define _dcl_dis_incoming_message_

#include <map>  // for member

#include "dis6/utils/Endian.h"            // for internal type
#include "dis6/utils/IBufferProcessor.h"  // for base class
#include "dis6/utils/IPduBank.h"
#include "dis6/utils/PDUType.h"

namespace dis {
class Pdu;
class IPacketProcessor;
class DataStream;

/// A framework for routing the packet to the correct processor.
class IncomingMessage : public IBufferProcessor {
 public:
  /// the container type for supporting processors.
  typedef std::multimap<uint8_t, IPacketProcessor*> PacketProcessorContainer;

  /// the container type for supporting PDU banks.
  typedef std::multimap<uint8_t, IPduBank*> PduBankContainer;

  IncomingMessage();
  ~IncomingMessage();

  void Process(const char* buf, uint32_t size, Endian e);

  /// registers the ipp instance to process packets with the id
  /// @return 'true' if the pair of parameters were not found in the container
  /// and were addded.  'false' if the pair was found.
  bool AddProcessor(uint8_t id, IPacketProcessor* pp);

  /// unregisters the ipp instance for packets with the id.  it does not clean
  /// up the delete the ipp.
  /// @return 'true' if the pair of parameters were found in the container and
  /// removed.  'false' if the pair was not found.
  bool RemoveProcessor(uint8_t id, const IPacketProcessor* pp);

  /// registers the PDU bank instance to provide the PDU object
  /// @return 'true' if the pair of parameters were not found in the container
  /// and were addded.  'false' if the pair was found.
  bool AddPduBank(uint8_t pdu_type, IPduBank* pduBank);

  /// unregisters the PDU bank instance
  /// @return 'true' if the pair of parameters were found in the container and
  /// removed.  'false' if the pair was not found.
  bool RemovePduBank(uint8_t pdu_type, const IPduBank* pduBank);

  PacketProcessorContainer& GetProcessors();
  const PacketProcessorContainer& GetProcessors() const;

  PduBankContainer& GetPduBanks();
  const PduBankContainer& GetPduBanks() const;

 private:
  typedef std::pair<PacketProcessorContainer::iterator,
                    PacketProcessorContainer::iterator>
      PacketProcessIteratorPair;
  PacketProcessorContainer _processors;

  typedef std::pair<PduBankContainer::iterator, PduBankContainer::iterator>
      PduBankIteratorPair;
  PduBankContainer _pduBanks;

  void SwitchOnType(DIS::PDUType pdu_type, DataStream& ds);

  /// Searches the proccesor container multimap for a matching container and
  /// returns the iterator
  bool FindProccessorContainer(
      uint8_t id, const IPacketProcessor* pp,
      PacketProcessorContainer::iterator& containerIter);

  /// Searches the PDU bank container multimap for a matching container and
  /// returns the iterator
  bool FindPduBankContainer(uint8_t pdu_type, const IPduBank* pduBank,
                            PduBankContainer::iterator& containerIter);
};

}  // namespace dis

#endif  // _dcl_dis_incoming_message_
