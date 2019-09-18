#ifndef _example_dis_connection_h_
#define _example_dis_connection_h_

#include <string>                        // for param
#include <cstddef>                       // for size_t definition

#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>


namespace Example
{
   /// the value for a typical ethernet connection's maximum transfer unit.
   const unsigned int MTU_SIZE = 1500;

   /// makes a multicast connection to support DIS networks.
   /// requires the HawkNL socket library.
   /// http://www.hawksoft.com/hawknl/ <- That is outdated
   class Connection
   {
   public:
      void Connect(unsigned int port, const std::string& host, bool listen);
      void Disconnect();

      void Send(const char* buf, size_t numbytes);

      /// allocates buf with size numbytes.
      /// @param buf the buffer to be written to with network bytes
      /// @param numbytes the maximum index used for the buffer (buf)
      /// @return the number of bytes read from the connection
      size_t Receive(char* buf);

   private:
      void HandleError();

      UDPsocket mSocket;
      IPaddress mAddr;
   };
}

#endif  // _example_dis_connection_h_
