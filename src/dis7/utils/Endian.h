#ifndef _dcl_dis_endian_h_
#define _dcl_dis_endian_h_

#include <dis7/opendis7_export.h>  // for library symbols

namespace DIS {
/// the order of bytes that are on the left
enum OPENDIS7_EXPORT Endian {
  LITTLE = 1,
  BIG = 0,
};
}  // namespace DIS

#endif  // _dcl_dis_endian_h_
