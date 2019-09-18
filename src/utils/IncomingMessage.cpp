#include <utils/IncomingMessage.h>
#include <utils/IPacketProcessor.h>
#include <dis6/Pdu.h>
#include <utils/DataStream.h>
#include <utils/PDUType.h>
#include <utils/PDUBank.h>
#include <iostream>

#include <dis6/EntityStatePdu.h>

#include <iostream>

using namespace DIS;

// the DIS specification says the type is known for all PDUs at the 3rd byte of the PDU buffer.
const unsigned int PDU_TYPE_POSITION = 2;

IncomingMessage::IncomingMessage()
: _processors()
{
}

IncomingMessage::~IncomingMessage()
{
}

void IncomingMessage::Process(const char* buf, unsigned int size, Endian e)
{
   if( size < 1 )
   {
      return;
   }

   DataStream ds( buf , size , e );

   while( ds.GetReadPos() < ds.size() )
   {  
      uint8_t pdu_type = ds[PDU_TYPE_POSITION];
      SwitchOnType( pdu_type, ds );
   }
}

void IncomingMessage::SwitchOnType(uint8_t pdu_type, DataStream& ds)
{
   DIS::PDUType enumType = (DIS::PDUType)pdu_type;
   Pdu *pdu = PduBank::GetStaticPDU(enumType);

   // if valid pdu point, and at least 1 processor
   if (pdu && (_processors.count(pdu_type) > 0))
   {
      pdu->unmarshal( ds );

      // assumes the location in the buffer is the packet id.
      typedef std::pair<PacketProcessorContainer::iterator,PacketProcessorContainer::iterator> RangePair;
      RangePair rangepair = _processors.equal_range( pdu_type );
      PacketProcessorContainer::iterator processor_iter = rangepair.first;
      PacketProcessorContainer::iterator processor_end = rangepair.second;
      while( processor_iter != processor_end )
      {
        (processor_iter->second)->Process( *pdu );
        ++processor_iter;
      }
   }
   else
   {
      ds.clear();
   }   
}


bool IncomingMessage::AddProcessor(uint8_t id, IPacketProcessor* pp)
{
   PacketProcessorContainer::value_type candidate(id,pp);
   PacketProcessorContainer::iterator containerIter;

   // If this id doesn't already have this processor (it shouldn't)
   if (!FindProccessorContainer(id, pp, containerIter))
   {
       _processors.insert( candidate );
       return true;
   }

   return false;    
}

///\todo add proper support for erasing from a multimap.
///\warning erases any processor registered for the id
bool IncomingMessage::RemoveProcessor(uint8_t id, const IPacketProcessor* pp)
{
   PacketProcessorContainer::iterator containerIter;

   if (FindProccessorContainer(id, pp, containerIter))
   {
      // Erases only the single pair found in the interator
      _processors.erase( containerIter );
      return true;
   }

   // The pair doesn't exist
   return false;
}

IncomingMessage::PacketProcessorContainer& IncomingMessage::GetProcessors()
{
   return _processors;
}

const IncomingMessage::PacketProcessorContainer& IncomingMessage::GetProcessors() const
{
   return _processors;
}


bool IncomingMessage::FindProccessorContainer(uint8_t id, const IPacketProcessor* pp, PacketProcessorContainer::iterator &containerIter)
{  
   PacketProcessIteratorPair iterPair = _processors.equal_range(id);

   // Check to make sure that the processor we're trying to add is not already there
   while (iterPair.first != iterPair.second)
   {
      // If this processor with a matching id has a the exact same processor, bail
      if ((iterPair.first)->second == pp)
      {
         containerIter = iterPair.first;
         return true;
      }

      iterPair.first++;
   }

   // No matches were found in the loop
   return false;
}
