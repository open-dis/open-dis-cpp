
#include <Example/Connection.h>                  // for reading packets from the socket
#include <Example/EntityStatePduProcessor.h>     // for usage
#include <Example/Utils.h>

#include <DIS/IncomingMessage.h>                 // for library usage
#include <DIS/EntityStatePdu.h>                  // for library usage

#include <cstring>                       // for strlen
#include <cstddef>                       // for size_t definition

int main(int argc, char* argv[])
{
   unsigned int port(62040);
   std::string ip("239.1.2.3");
   if( argc > 2 )
   {
      port = Example::ToType<unsigned int>( argv[1] );
      ip = argv[2];
   }

   Example::Connection multicast;
   multicast.Connect( port , ip );
   DIS::Endian endian = DIS::BIG;

   char buffer[Example::MTU_SIZE+1];
   buffer[Example::MTU_SIZE] = '\0';   // should be NULL terminated somewhere in case the network read does not do this?

   Example::EntityStatePduProcessor processor;

   const unsigned char es_pdu_type = 1;
   DIS::IncomingMessage incoming;
   incoming.AddProcessor( es_pdu_type , &processor );
   while( true )
   {
      ///\todo find a way to use the stream rather than a raw char buffer,
      /// so that copying the buffer into the DataStream within the IncomingMessage
      /// will not be necessary.
      size_t bytes_read = multicast.Receive( buffer , Example::MTU_SIZE );

      // engage the higher level support
      incoming.Process( buffer , bytes_read , endian );
   }

   incoming.RemoveProcessor( es_pdu_type , &processor );
   multicast.Disconnect();
   return 0;
}

