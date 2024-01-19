/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dcl_dis_i_buffer_processor_h_
#define _dcl_dis_i_buffer_processor_h_

#include "dis6/utils/Endian.h"

namespace dis {
/// the interface class for handling read operations.
class IBufferProcessor {
 public:
  virtual ~IBufferProcessor() = default;
  virtual void Process(const char* buf, uint32_t size, Endian e) = 0;
};
}  // namespace dis

#endif  // _dcl_dis_i_buffer_processor_h_
