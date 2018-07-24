/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dis_stream_utils_h_
#define _dis_stream_utils_h_

#include <ostream>             // for parameter type
#include <DIS/msLibMacro.h>       // for library symbols

namespace DIS
{
   class EntityStatePdu;
   class EntityID;
   class DetonationPdu;
   class EntityType;
}

EXPORT_MACRO std::ostream& operator <<(std::ostream& lhs, const DIS::EntityType& rhs);
EXPORT_MACRO std::ostream& operator <<(std::ostream& lhs, const DIS::EntityID& rhs);
EXPORT_MACRO std::ostream& operator <<(std::ostream& lhs, const DIS::EntityStatePdu& rhs);
EXPORT_MACRO std::ostream& operator <<(std::ostream& lhs, const DIS::DetonationPdu& rhs);

#endif // _dis_stream_utils_h_
