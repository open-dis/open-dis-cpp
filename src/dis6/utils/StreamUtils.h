/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dis_stream_utils_h_
#define _dis_stream_utils_h_

#include <ostream>             // for parameter type
#include <dis6/opendis6_export.h>       // for library symbols

namespace DIS
{
   class EntityStatePdu;
   class EntityID;
   class DetonationPdu;
   class EntityType;
}

OPENDIS6_EXPORT std::ostream& operator <<(std::ostream& lhs, const DIS::EntityType& rhs);
OPENDIS6_EXPORT std::ostream& operator <<(std::ostream& lhs, const DIS::EntityID& rhs);
OPENDIS6_EXPORT std::ostream& operator <<(std::ostream& lhs, const DIS::EntityStatePdu& rhs);
OPENDIS6_EXPORT std::ostream& operator <<(std::ostream& lhs, const DIS::DetonationPdu& rhs);

#endif // _dis_stream_utils_h_
