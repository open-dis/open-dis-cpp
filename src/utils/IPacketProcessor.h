/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dcl_dis_i_packet_processor_h_
#define _dcl_dis_i_packet_processor_h_

namespace DIS
{
   class Pdu;

   /// it is the responsibility of the processor to use the packet
   /// because it will be deleted after this call.
   class IPacketProcessor
   {
   public:
      virtual void Process(const Pdu& p)=0;
   };

}

#endif // _dcl_dis_i_packet_processor_h_
