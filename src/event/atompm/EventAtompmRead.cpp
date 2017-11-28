#include "event/atompm/EventAtompmRead.h"
#include "message/atompm/MessageAtompmRead.h"

#include <elephant.h>


using namespace collab;


void EventAtompmRead::run(IMessage& message) const {
    message = static_cast<MessageAtompmRead&>(message);
    LOG_DEBUG(0, "EventRead (AtomPM)");
}

