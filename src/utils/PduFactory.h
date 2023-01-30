#pragma once

#include <dis6/opendis6_export.h>         // for library symbols
#include <dis6/Pdu.h>

namespace DIS
{
	/**
	* PduFactory turns byte buffers in IEEE-1278.1 (DIS) format into
	* C++ language objects. For example, if you read a datagram packet
	* and extract a payload, and that payload is in DIS format, you can
	* hand it off to this class and get back an EntityStatePdu, FirePdu,
	* or whatever.<p>
	*
	* @author DMcG
	*/

class OPENDIS6_EXPORT PduFactory
{
public:
	PduFactory(void);
	~PduFactory(void);

	/** Returns a PDU of the appropriate concrete subclass. Returns NULL
	 * for failures or unrecognized PDU types.
	 */
	Pdu* createPdu(const char * data);
};
}
