#include "dis6/utils/Conversion.h"

#include "dis6/utils/Masks.h"

namespace dis {

// const uint8_t
// Convert::ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS = 5;

int Convert::MakeArticulationParameterType(int typeclass, int typemetric) {
  // enforce a ceiling on typemetric
  typemetric = typemetric & kArticulationParameterTypeMetricMask;

  // shift the typeclass bits to the left by the precision amount of typemetric
  // and then add the typemetric bits
  return ((typeclass << kArticulationParameterTypeMetricNumberOfBits) +
          typemetric);
}

int Convert::GetArticulationTypeMetric(int parametertype) {
  // wipe off the typeclass bits and return the typemetric bits
  return (parametertype & kArticulationParameterTypeMetricMask);
}

int Convert::GetArticulationTypeClass(int parametertype) {
  // wipe off the typemetric bits and return the typeclass bits
  return (parametertype >> kArticulationParameterTypeMetricNumberOfBits);
}

}  // namespace dis
