#pragma once

#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"
#include "event/debug/EventDebugUpdate.h"


namespace collab {


class MessageDebugUpdate : public IMessage {
    public:
        MessageDebugUpdate() {
            this->m_event = new EventDebugUpdate();
        }

        ~MessageDebugUpdate() = default;

    public:
        void apply() override {
            this->m_event->run(*this);
        }

        int getID() const override {
            return static_cast<int>(MessageTypes::Create);
        }
};


} // End namespace
