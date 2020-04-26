#ifndef ISensorConnectionHandler_h
#define ISensorConnectionHandler_h

#include <NetworkUtils.h>

#include <iostream>
#include <string>
#include "IConnectionsManager.h"
#include "BytesParser.h"
#include "ConnectionException.h"

namespace sc
{
    class ISensorConnectionHandler
    {
    public:
        virtual void handleSensor(int socketDescriptor) = 0;
        virtual void acceptSensors(std::string ipAddress, int port, IConnectionsManager *connectionsListener) = 0;

    protected:
        int getAcceptingSocket(std::string ipAddress, int port, int listeningQueue = 10);
        int closeSocket(int socketDescriptor);
    };
}

#endif /* ISensorConnectionHandler_h */
