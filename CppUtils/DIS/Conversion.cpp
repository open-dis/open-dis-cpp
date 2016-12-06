#include <DIS/Conversion.h>
#include <DIS/Masks.h>

using namespace DIS;

//const unsigned char Convert::ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS = 5;


int Convert::MakeArticulationParameterType(int typeclass, int typemetric)
{
   // enforce a ceiling on typemetric
   typemetric = typemetric & ARTICULATION_PARAMETER_TYPE_METRIC_MASK;

   // shift the typeclass bits to the left by the precision amount of typemetric
   // and then add the typemetric bits
   return( (typeclass << ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS)
          + typemetric );
}

int Convert::GetArticulationTypeMetric(int parametertype)
{
   // wipe off the typeclass bits and return the typemetric bits
   return( parametertype & ARTICULATION_PARAMETER_TYPE_METRIC_MASK);
}

int Convert::GetArticulationTypeClass(int parametertype)
{
   // wipe off the typemetric bits and return the typeclass bits
   return( parametertype >> ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS );
}
