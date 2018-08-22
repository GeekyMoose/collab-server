#pragma once

#include <cstdint>
#include <string>

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageList.h"
#include "collabserver/core/Broadcaster.h"
#include "collabserver/core/CollabServer.h"

namespace collab {


struct ServerConfig {
    uint16_t    port;
};


/**
 * \brief
 * Server for network communication.
 *
 * \par Default settings
 *  - port: 4242
 */
class Server : public Broadcaster {
    private:
        bool            _isRunning      = false;
        std::string     _address        = "*";
        uint16_t        _port           = 4242;

    private:
        CollabServer*   _collabserver   = nullptr;

    public:
        Server();;
        Server(const ServerConfig& config);
        ~Server();

    public:
        void start();
        void stop();

    private:
        void handleMessage(const Message& msg);
        void handleMessage(const MsgDebug& msg);
        void handleMessage(const MsgConnectionRequest& msg);

    private:
        void sendOperationToUser(const OperationInfo& op,
                                 const int userID) {}
        void sendOperationToStorage(const OperationInfo& op,
                                    const int storageID) {}
};


} // End namespace

