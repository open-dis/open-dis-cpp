#ifndef LOGISTICSPDU_H
#define LOGISTICSPDU_H

#include <DIS/Pdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Section 5.3.5. Abstract superclass for logistics PDUs. COMPLETE

// Copyright (c) 2007, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// This work is licensed under the BSD open source license, available at https://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

class EXPORT_MACRO LogisticsPdu : public Pdu
{
protected:

 public:
    LogisticsPdu();
    virtual ~LogisticsPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


virtual int getMarshalledSize() const;

     bool operator  ==(const LogisticsPdu& rhs) const;
};
}

#endif
