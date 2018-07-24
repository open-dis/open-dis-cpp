#include <DIS/PacketFactory.h>
#include <DIS/Pdu.h>
#include <cstdlib>

using namespace DIS;

Pdu* PacketFactory::CreatePacket(unsigned char id)
{
   FunctionMap::iterator iter =_fMap.find( id );
   if( iter != _fMap.end() )
   {
      return (iter->second)();
   }

   return NULL;
}

void PacketFactory::DestroyPacket(Pdu* pdu)
{
   delete pdu;
}

bool PacketFactory::IsRegistered(unsigned char id) const
{
   FunctionMap::const_iterator iter = _fMap.find(id);
   return( iter != _fMap.end() );
}
