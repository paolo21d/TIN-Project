#include "NetworkUtils.h"

int initNetwork()
{
#if defined(WIN32) || defined(_WIN64)
    WSADATA wsaData;
    return WSAStartup( MAKEWORD( 2, 2 ), & wsaData );
#else
    return 0;
#endif
}

int closeSocket(int socketDescriptor)
{
#if defined(WIN32) || defined(_WIN64)
    return closesocket(socketDescriptor);
#else
    return close(socketDescriptor);
#endif
}