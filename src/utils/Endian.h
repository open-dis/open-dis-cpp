#ifndef _dcl_dis_endian_h_
#define _dcl_dis_endian_h_

#include <DIS/msLibMacro.h>       // for library symbols

namespace DIS
{
   /// the order of bytes that are on the left
   EXPORT_MACRO enum Endian
   {
      LITTLE=1,
      BIG=0,
   };
}

#endif   // _dcl_dis_endian_h_
