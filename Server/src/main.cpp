#include <iostream>
#include <NetworkUtils.h>
#include <vector>
#include <IRequestListener.h>
#include "ConnectionsManager.h"
<<<<<<< HEAD
#include "SensorConnectionHandler.h"

using namespace std;
=======
#include "ConnectionException.h"
#include "DatabaseManager.h"
>>>>>>> 6dcc5b5... Added database connection

class MockListener : public IRequestListener
{
public:
    vector<unsigned char> onGotRequest(int clientId, vector<unsigned char> msg) override
    {
        vector<unsigned char> response;

        int cursorPos = 0;
        long timestamp = getData<long>(msg, cursorPos);
        double value = getData<double>(msg, cursorPos);
        cout << "client " << clientId << "     timestamp: " << timestamp << "     value: " << value << endl;

<<<<<<< HEAD
        return response;
    }
};
=======
int initNetwork()
{
#ifdef _WIN64
    WSADATA wsaData;
    return WSAStartup( MAKEWORD( 2, 2 ), & wsaData );
#else
    return 0;
#endif
}
>>>>>>> 6dcc5b5... Added database connection

int main(int argc, char *argv[])
{
    auto* dbManago = new DatabaseManager("ADMIN", "Seikonnoqwaser1!", "tin_high");
    dbManago->printTest();
    initNetwork();

    cout << "START" << endl;

    IRequestListener *listener = new MockListener();

    sc::ISensorConnectionHandler *connectionHandler = new sc::SensorConnectionHandler();
    connectionHandler->addListener(listener);
    connectionHandler->acceptSensors("127.0.0.1", 33333);
//    sc::IConnectionsManager *connectionsManager = new sc::ConnectionsManager("127.0.0.1", 33333);
//    connectionsManager->startAcceptingSensors();

    cout << "END" << endl;
    
    return 0;
}
