/// Copyright goes here
/// License goes here
/// @author John K. Grant
/// @author Michael Guerrero

#ifndef _dcl_dis_conversion_h_
#define _dcl_dis_conversion_h_

#include <DIS/msLibMacro.h>       // for library symbols

namespace DIS
{
   /// a name-scope for conversion functions.
   struct EXPORT_MACRO Convert
   {
      /// the number of bits used to store the type metric value
      /// within the Articulation Parameter's parameter type value.
      /// this mask is based on the IEEE Std 1278.1-1995
      static const unsigned char ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS = 5;

      /// make the value needed for the ArticulationParameter's Parameter Type.
      /// @param typeclass the enumeration for the articulated part.
      /// This must have less precision than ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS.
      /// @param typemetric the enumeration for the motion description.
      /// this must have less precision than 32 - ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS.
      /// @return the value to be used as the Parameter Type, with 32 bits precision.
      static int MakeArticulationParameterType(int typeclass, int typemetric);

      /// extract the data for the type metric value stored within the parameter type value.
      /// this an inverse to the function, MakeArticulationParameterType.
      /// @param parametertype the value storing the type metric and type class values.
      /// @return the type metric value, with ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS bits precision.
      static int GetArticulationTypeMetric(int parametertype);

      /// extract the data for the type class value stored within the parameter type value.
      /// this an inverse to the function, MakeArticulationParameterType.
      /// @param parametertype the value storing the type metric and type class values.
      /// @return the type class value, with ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS bits precision
      static int GetArticulationTypeClass(int parametertype);
   };
}

#endif // _dcl_dis_conversion_h_
