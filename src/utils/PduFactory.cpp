#include "PduFactory.h"
#include <dis6/EntityStatePdu.h>
#include <dis6/FirePdu.h>
#include <dis6/SetDataPdu.h>
#include <dis6/DetonationPdu.h>
#include <dis6/CreateEntityPdu.h>
#include <dis6/RemoveEntityPdu.h>
#include <utils/Endian.h>
#include <utils/PDUType.h>

#include <iostream>

using namespace DIS;

PduFactory::PduFactory(void)
{
}

PduFactory::~PduFactory(void)
{
}

/**
 * Converts data read from the wire--a byte array--to a DIS PDU language
 * object. A new PDU is created for every data buffer. The consumer of this 
 * object is responsible for freeing it. The PDUs can be up to MTU in size;
 * in some fairly rare instances, mostly involving multiple PDUs in a single
 * datagram packet, PDUs may be larger than this and this will fail horribly.
 * If the PDU type is unrecognized, or cannot be unmarshalled, the method
 * returns NULL. The caller should check for this.
 */

Pdu * PduFactory::createPdu(const char* data)
{
	int dataLength = 1500; // MTU, might fail for some very large PDUs
	int pduType = data[2];

	//std::cout << "Decoding PDU of type " << (int)pduType << std::endl;

	DataStream dataStream(data, dataLength, DIS::BIG);

	Pdu* pdu = NULL;

	switch(pduType)
	{
	case PDU_ENTITY_STATE:
	    pdu = new EntityStatePdu();
		pdu->unmarshal(dataStream);
		break;

	case PDU_FIRE:
		pdu = new FirePdu();
		pdu->unmarshal(dataStream);
		break;

	case PDU_DETONATION:
		pdu = new DetonationPdu();
		pdu->unmarshal(dataStream);
		break;

	case PDU_SET_DATA:
		pdu = new SetDataPdu();
		pdu->unmarshal(dataStream);
		break;

	case PDU_CREATE_ENTITY:
		pdu = new CreateEntityPdu();
		pdu->unmarshal(dataStream);
		break;

	case PDU_REMOVE_ENTITY:
		pdu = new RemoveEntityPdu();
		pdu->unmarshal(dataStream);
		break;

	default:
		std::cout << "Received Unrecognized PDU of type " << (int)pduType << " change PduFactory.cpp to add new PDUs" << std::endl;
		break;
	}

	return pdu;

}

void deletePdu(Pdu* del)
{
	delete del;
	del = nullptr;
}