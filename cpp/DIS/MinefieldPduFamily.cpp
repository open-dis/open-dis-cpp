#include <DIS/MinefieldPduFamily.h> 

using namespace DIS;


MinefieldPduFamily::MinefieldPduFamily() : Pdu()

{
    setProtocolFamily( 8 );
}

MinefieldPduFamily::~MinefieldPduFamily()
{
}

void MinefieldPduFamily::marshal(DataStream& dataStream) const
{
    Pdu::marshal(dataStream); // Marshal information in superclass first
}

void MinefieldPduFamily::unmarshal(DataStream& dataStream)
{
    Pdu::unmarshal(dataStream); // unmarshal information in superclass first
}


bool MinefieldPduFamily::operator ==(const MinefieldPduFamily& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = Pdu::operator==(rhs);


    return ivarsEqual;
 }

int MinefieldPduFamily::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = Pdu::getMarshalledSize();
    return marshalSize;
}

