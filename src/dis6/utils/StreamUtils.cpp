#include <dis6/DetonationPdu.h>
#include <dis6/EntityID.h>
#include <dis6/EntityStatePdu.h>
#include <dis6/utils/StreamUtils.h>

std::ostream& operator<<(std::ostream& lhs, const DIS::EntityType& rhs) {
  lhs << "EntityType (" << (uint32_t)rhs.getEntityKind() << ","
      << (uint32_t)rhs.getDomain() << "," << (uint32_t)rhs.getCountry()
      << "," << (uint32_t)rhs.getCategory() << ","
      << (uint32_t)rhs.getSubcategory() << ") ";
  return lhs;
}

std::ostream& operator<<(std::ostream& lhs, const DIS::EntityID& rhs) {
  lhs << "EntityID (" << (uint32_t)rhs.getEntity() << ") ";
  return lhs;
}

std::ostream& operator<<(std::ostream& lhs, const DIS::EntityStatePdu& rhs) {
  lhs << "EntityStatePdu (" << rhs.getEntityID() << ") ";
  return lhs;
}

std::ostream& operator<<(std::ostream& lhs, const DIS::DetonationPdu& rhs) {
  lhs << "DetonationPDU (" << rhs.getFiringEntityID() << ") ";
  return lhs;
}
