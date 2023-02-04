/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dcl_dis_incoming_message_
#define _dcl_dis_incoming_message_

#include <dis6/utils/IBufferProcessor.h>   // for base class
#include <dis6/utils/IPduBank.h> 
#include <map>                      // for member
#include <dis6/utils/Endian.h>             // for internal type
#include <dis6/opendis6_export.h>         // for library symbols
#include <dis6/utils/PDUType.h>

namespace DIS
{
   class Pdu;
   class IPacketProcessor;
   class DataStream;

   /// A framework for routing the packet to the correct processor.
   class OPENDIS6_EXPORT IncomingMessage : public IBufferProcessor
   {
   public:
      /// the container type for supporting processors.
      typedef std::multimap<unsigned char,IPacketProcessor*> PacketProcessorContainer;
      
      /// the container type for supporting PDU banks.
      typedef std::multimap<unsigned char,IPduBank*> PduBankContainer;

      IncomingMessage();
      ~IncomingMessage();

      void Process(const char* buf, unsigned int size, Endian e);

      /// registers the ipp instance to process packets with the id
      /// @return 'true' if the pair of parameters were not found in the container and were addded.  'false' if the pair was found.
      bool AddProcessor(unsigned char id, IPacketProcessor* pp);

      /// unregisters the ipp instance for packets with the id.  it does not clean up the delete the ipp.
      /// @return 'true' if the pair of parameters were found in the container and removed.  'false' if the pair was not found.
      bool RemoveProcessor(unsigned char id, const IPacketProcessor* pp);

      /// registers the PDU bank instance to provide the PDU object
      /// @return 'true' if the pair of parameters were not found in the container and were addded.  'false' if the pair was found.
      bool AddPduBank(unsigned char pdu_type, IPduBank* pduBank);

      /// unregisters the PDU bank instance
      /// @return 'true' if the pair of parameters were found in the container and removed.  'false' if the pair was not found.
      bool RemovePduBank(unsigned char pdu_type, const IPduBank* pduBank);

      PacketProcessorContainer& GetProcessors();
      const PacketProcessorContainer& GetProcessors() const;

      PduBankContainer& GetPduBanks();
      const PduBankContainer& GetPduBanks() const;

   private:
      typedef std::pair<PacketProcessorContainer::iterator, PacketProcessorContainer::iterator> PacketProcessIteratorPair;
      PacketProcessorContainer _processors;
      
      typedef std::pair<PduBankContainer::iterator, PduBankContainer::iterator> PduBankIteratorPair;
      PduBankContainer _pduBanks;

      void SwitchOnType(DIS::PDUType pdu_type, DataStream& ds);

      /// Searches the proccesor container multimap for a matching container and returns the iterator
      bool FindProccessorContainer(unsigned char id, const IPacketProcessor* pp, PacketProcessorContainer::iterator &containerIter);

      /// Searches the PDU bank container multimap for a matching container and returns the iterator
      bool FindPduBankContainer(unsigned char pdu_type, const IPduBank* pduBank, PduBankContainer::iterator &containerIter);
   };

}

#endif  // _dcl_dis_incoming_message_

