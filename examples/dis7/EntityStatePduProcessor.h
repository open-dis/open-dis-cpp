#ifndef _example_entity_state_pdu_processor_h_
#define _example_entity_state_pdu_processor_h_

#include <dis7/EntityStatePdu.h>                  // for typedef
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

#endif  // _example_entity_state_pdu_processor_h_
