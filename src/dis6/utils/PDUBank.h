#pragma once

#include "dis6/common/Pdu.h"
#include "dis6/utils/PDUType.h"

namespace dis {
/// houses instances for the set of known PDU classes to be returned
/// when provided with the PDU type's identifier value.
class PduBank {
 public:
  /// finds the PDU instance corresponding to the identifier
  /// @param pdu_type the 8-bit PDU type identifier
  /// @return NULL when the pdu_type is unknown.
  ///\todo make this parameter just 'uint8_t' since that will be easier to
  /// generate.
  static Pdu* GetStaticPDU(dis::PDUType pdu_type);
};
}  // namespace dis
