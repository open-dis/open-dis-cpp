#ifndef _example_dis_connection_h_
#define _example_dis_connection_h_

#include <nl.h>                          // for member & implementation
#include <string>                        // for param
#include <cstddef>                       // for size_t definition


namespace Example
{
   /// the value for a typical ethernet connection's maximum transfer unit.
   const unsigned int MTU_SIZE = 1500;

   /// makes a multicast connection to support DIS networks.
   /// requires the HawkNL socket library.
   /// http://www.hawksoft.com/hawknl/
   class Connection
   {
   public:
      void Connect(unsigned int port, const std::string& host);
      void Disconnect();

      void Send(const char* buf, size_t numbytes);

      /// allocates buf with size numbytes.
      /// @param buf the buffer to be written to with network bytes
      /// @param numbytes the maximum index used for the buffer (buf)
      /// @return the number of bytes read from the connection
      size_t Receive(char* buf, size_t numbytes);

   private:
      void HandleError();

      NLsocket mSocket;
   };
}

#endif  // _example_dis_connection_h_
