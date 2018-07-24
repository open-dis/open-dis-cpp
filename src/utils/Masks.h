/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dcl_dis_masks_h_
#define _dcl_dis_masks_h_

#include <DIS/msLibMacro.h>       // for library symbols

namespace DIS
{
   /// the mask that will leave only the typemetric
   /// from an integer representing the Articulation Parameter's parameter type.
   /// this mask is based on the IEEE Std 1278.1-1995
   const unsigned int ARTICULATION_PARAMETER_TYPE_METRIC_MASK = 0x001F;
}

#endif // _dcl_dis_masks_h_
