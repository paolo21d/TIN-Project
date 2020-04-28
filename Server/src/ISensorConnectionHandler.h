#ifndef ISensorConnectionHandler_h
#define ISensorConnectionHandler_h


#include <NetworkUtils.h>

#ifdef _WIN64
#include "winsock.h"
#else
#include <netinet/in.h>
#include <zconf.h>
#include <arpa/inet.h>
#endif

#include <iostream>
#include <string>
#include <BytesParser.h>
#include "IConnectionsManager.h"
#include <ConnectionException.h>
#include <IRequestListener.h>

namespace sc
{
    class ISensorConnectionHandler
    {
    public:
        virtual void handleSensor(int socketDescriptor) = 0;
        virtual void acceptSensors(std::string ipAddress, int port) = 0;
        virtual void addListener(IRequestListener *requestListener) = 0;

    protected:
        int getAcceptingSocket(std::string ipAddress, int port, int listeningQueue = 10);
    };
}

#endif /* ISensorConnectionHandler_h */
