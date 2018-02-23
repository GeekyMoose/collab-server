#pragma once

#include "messaging/IMessage.h"
#include "messaging/IMessageEvent.h"


namespace collab {


/**
 * Implements IMessage for Read operation.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageViewLoadById : public IMessage {
    private:
        /** Event that process this message. */
        IMessageEvent<MessageViewLoadById> *m_event = nullptr;

    public:
        MessageViewLoadById() = default;
        ~MessageViewLoadById() = default;

    public:
        void apply() override;
        bool serialize(std::stringstream & buffer) const override;
        bool unserialize(std::stringstream & buffer) override;
        MessageTypes getType() const override;
};


} // End namespace
