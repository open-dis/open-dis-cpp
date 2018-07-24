#include <Example/EntityStatePduProcessor.h>

#include <iostream>

using namespace Example;

void EntityStatePduProcessor::Process(const DIS::Pdu& packet)
{
   const DIS::EntityStatePdu& espdu = static_cast<const DIS::EntityStatePdu&>( packet );
   if( espdu.getTimestamp() % 10 )
   {
      const DIS::Vector3Double& position = espdu.getEntityLocation();
      std::cout << "x:" << position.getX()
                << "\ty:" << position.getY()
                << "\tz:" << position.getZ()
                << std::endl;
   }
}

