#ifndef SERVER_CONNECTIONSMANAGER_H
#define SERVER_CONNECTIONSMANAGER_H

#include "IConnectionsManager.h"
#include "SensorConnectionHandler.h"

class ConnectionsManager : public IConnectionsManager
{
public:
    ConnectionsManager(std::string ipAddress, int port);

    void startAcceptingSensors() override ;
    void onClientAccepted(int socketDescriptor) override ;

private:
    const std::string ipAddress;
    const int port;

    ISensorConnectionHandler *sensorsHandler;
};

#endif //SERVER_CONNECTIONSMANAGER_H
