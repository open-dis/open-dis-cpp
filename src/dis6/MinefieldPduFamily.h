#ifndef MINEFIELDPDUFAMILY_H
#define MINEFIELDPDUFAMILY_H

#include <DIS/Pdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Section 5.3.10.1 Abstract superclass for PDUs relating to minefields

// Copyright (c) 2007, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// This work is licensed under the BSD open source license, available at https://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

class EXPORT_MACRO MinefieldPduFamily : public Pdu
{
protected:

 public:
    MinefieldPduFamily();
    virtual ~MinefieldPduFamily();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


virtual int getMarshalledSize() const;

     bool operator  ==(const MinefieldPduFamily& rhs) const;
};
}

#endif
