/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dcl_dis_i_buffer_processor_h_
#define _dcl_dis_i_buffer_processor_h_

#include <DIS/Endian.h>

namespace DIS
{
   /// the interface class for handling read operations.
   class IBufferProcessor
   {
   public:
      virtual void Process(const char* buf, unsigned int size, Endian e)=0;
   };
}

#endif  // _dcl_dis_i_buffer_processor_h_
