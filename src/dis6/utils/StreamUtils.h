/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dis_stream_utils_h_
#define _dis_stream_utils_h_

#include <ostream>  // for parameter type

namespace dis {
class EntityStatePdu;
class EntityID;
class DetonationPdu;
class EntityType;
}  // namespace dis

std::ostream& operator<<(std::ostream& lhs, const dis::EntityType& rhs);
std::ostream& operator<<(std::ostream& lhs, const dis::EntityID& rhs);
std::ostream& operator<<(std::ostream& lhs, const dis::EntityStatePdu& rhs);
std::ostream& operator<<(std::ostream& lhs, const dis::DetonationPdu& rhs);

#endif  // _dis_stream_utils_h_
