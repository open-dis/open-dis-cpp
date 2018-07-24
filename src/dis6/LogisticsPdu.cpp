#include <DIS/LogisticsPdu.h> 

using namespace DIS;


LogisticsPdu::LogisticsPdu() : Pdu()

{
    setProtocolFamily( 3 );
}

LogisticsPdu::~LogisticsPdu()
{
}

void LogisticsPdu::marshal(DataStream& dataStream) const
{
    Pdu::marshal(dataStream); // Marshal information in superclass first
}

void LogisticsPdu::unmarshal(DataStream& dataStream)
{
    Pdu::unmarshal(dataStream); // unmarshal information in superclass first
}


bool LogisticsPdu::operator ==(const LogisticsPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = Pdu::operator==(rhs);


    return ivarsEqual;
 }

int LogisticsPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = Pdu::getMarshalledSize();
    return marshalSize;
}

