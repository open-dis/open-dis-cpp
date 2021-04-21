#include "Connection.h"
#include "Logging.h"

#include <sstream>
#include <cstring>

#include <SDL.h>
#include <SDL_net.h>

using namespace Example;


void Connection::Connect(unsigned int port, const std::string& host, bool listening)
{
   bool success = SDL_Init(0) != -1 && SDLNet_Init() != -1;
   if (!success)
   {
      HandleError();
      return;
   }

   if (SDLNet_ResolveHost(&mAddr, host.c_str(), port) == -1 )
   {
      std::ostringstream strm;
      strm << "Can't get address for : " + host + ". "
           << "Error:" << SDLNet_GetError()
		       << "\n. System: " <<  SDL_GetError();
      LOG_ERROR( strm.str() );
   }

   if (listening) {
      mSocket = SDLNet_UDP_Open(port);
   } else {
      mSocket = SDLNet_UDP_Open(0);
   }

   if(!mSocket)
   {
      std::ostringstream strm;
      strm << "Can't open socket: " << SDLNet_GetError();
      LOG_ERROR( strm.str() )
   }

}

void Connection::Disconnect()
{
   SDLNet_UDP_Close(mSocket);
   SDLNet_Quit();
}

void Connection::Send(const char* buf, size_t numbytes)
{
   if( numbytes < 1 )
   {
      return;
   }

   UDPpacket * packet = SDLNet_AllocPacket(numbytes);
   if (!packet)
   {
      HandleError();
   }
   else
   {
      memcpy(packet->data, buf, numbytes);
      packet->address = mAddr;
      packet->len = numbytes;
      int ret = SDLNet_UDP_Send(mSocket, -1, packet);
      if (ret == 0)
      {
         HandleError();
      }
      SDLNet_FreePacket(packet);
   }
}

size_t Connection::Receive(char* buf)
{
   UDPpacket* packet = SDLNet_AllocPacket(MTU_SIZE);
   int packetRecvd = SDLNet_UDP_Recv(mSocket, packet);

   if ( packetRecvd != 1 )
   {
      if (packetRecvd == -1) {
         HandleError();
      }
      return 0;
   }
   memcpy(buf, packet->data, packet->len);
   return packet->len;
}

void Connection::HandleError()
{
   const char* errorString = SDLNet_GetError();

   LOG_ERROR("A network error occurred: " + std::string(errorString));
}
