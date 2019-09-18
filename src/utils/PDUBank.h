#ifndef _PDU_BANK_H_
#define _PDU_BANK_H_

#include <dis6/Pdu.h>
#include <utils/PDUType.h>

namespace DIS
{
    /// houses instances for the set of known PDU classes to be returned
    /// when provided with the PDU type's identifier value.
    class PduBank
    {
    public:
        /// finds the PDU instance corresponding to the identifier
        /// @param pdu_type the 8-bit PDU type identifier
        /// @return NULL when the pdu_type is unknown.
        ///\todo make this parameter just 'uint8_t' since that will be easier to generate.
        static Pdu* GetStaticPDU( DIS::PDUType pdu_type );  
    };   
}

#endif // _PDU_BANK_H_

