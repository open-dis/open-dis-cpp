/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dcl_dis_incoming_message_
#define _dcl_dis_incoming_message_

#include <utils/IBufferProcessor.h>   // for base class
#include <map>                      // for member
#include <utils/Endian.h>             // for internal type
#include <dis6/msLibMacro.h>         // for library symbols

namespace DIS
{
   class Pdu;
   class IPacketProcessor;
   class DataStream;

   /// A framework for routing the packet to the correct processor.
   class EXPORT_MACRO IncomingMessage : public IBufferProcessor
   {
   public:
      /// the container type for supporting processors.
      typedef std::multimap<uint8_t,IPacketProcessor*> PacketProcessorContainer;

      IncomingMessage();
      ~IncomingMessage();

      void Process(const char* buf, unsigned int size, Endian e);

      /// registers the ipp instance to process packets with the id
      /// @return 'true' if the pair of parameters were not found in the container and were addded.  'false' if the pair was found.
      bool AddProcessor(uint8_t id, IPacketProcessor* pp);

      /// unregisters the ipp instance for packets with the id.  it does not clean up the delete the ipp.
      /// @return 'true' if the pair of parameters were found in the container and removed.  'false' if the pair was not found.
      bool RemoveProcessor(uint8_t id, const IPacketProcessor* pp);

      PacketProcessorContainer& GetProcessors();
      const PacketProcessorContainer& GetProcessors() const;

   private:
      typedef std::pair<PacketProcessorContainer::iterator, PacketProcessorContainer::iterator> PacketProcessIteratorPair;

      PacketProcessorContainer _processors;

      void SwitchOnType(uint8_t pdu_type, DataStream& ds);

      /// Searches the proccesor container multimap for a matching container and returns the iterator
      bool FindProccessorContainer(uint8_t id, const IPacketProcessor* pp, PacketProcessorContainer::iterator &containerIter);
   };

}

#endif  // _dcl_dis_incoming_message_

