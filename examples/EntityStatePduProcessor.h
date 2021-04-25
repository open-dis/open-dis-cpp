#pragma once

#include <dis6/EntityStatePdu.h>                  // for typedef
#include <utils/IPacketProcessor.h>                // for base class

namespace Example
{
   class EntityStatePduProcessor : public DIS::IPacketProcessor
   {
   public:
      typedef DIS::EntityStatePdu PduType;

      void Process(const DIS::Pdu& packet);
   };
}

