#include <utils/PacketFactory.h>
#include <dis6/Pdu.h>
#include <cstdlib>

using namespace DIS;

Pdu* PacketFactory::CreatePacket(uint8_t id)
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

bool PacketFactory::IsRegistered(uint8_t id) const
{
   FunctionMap::const_iterator iter = _fMap.find(id);
   return( iter != _fMap.end() );
}
