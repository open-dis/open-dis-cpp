/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dcl_dis_masks_h_
#define _dcl_dis_masks_h_

#include <cstdint>

namespace dis {
/// the mask that will leave only the typemetric
/// from an integer representing the Articulation Parameter's parameter type.
/// this mask is based on the IEEE Std 1278.1-1995
const uint32_t kArticulationParameterTypeMetricMask = 0x001F;
}  // namespace dis

#endif  // _dcl_dis_masks_h_
