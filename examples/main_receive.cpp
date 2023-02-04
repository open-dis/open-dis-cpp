
#include "Connection.h"                  // for reading packets from the socket
#include "EntityStatePduProcessor.h"     // for usage
#include "Utils.h"

#include <dis6/utils/IncomingMessage.h>                 // for library usage
#include <dis6/EntityStatePdu.h>                  // for library usage

#include <cstring>                       // for strlen
#include <cstddef>                       // for size_t definition

#include <iostream>
int main(int argc, char* argv[])
{
   unsigned int port(62040);
   std::string ip("224.0.0.1");
   if( argc > 2 )
   {
      port = Example::ToType<unsigned int>( argv[1] );
      ip = argv[2];
   }

   Example::Connection multicast;
   multicast.Connect( port , ip , true);
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
      size_t bytes_read = multicast.Receive( buffer );

      // engage the higher level support
      incoming.Process( buffer , bytes_read , endian );

      // Add a short sleep delay to avoid locking up machine
      // (SDL UDP Reads are non-blocking)
      Example::sleep(10);
   }

   incoming.RemoveProcessor( es_pdu_type , &processor );
   multicast.Disconnect();
   return 0;
}
