#ifndef SERVER_NETWORKUTILS_H
#define SERVER_NETWORKUTILS_H

#if defined(WIN32) || defined(_WIN64)
#include "winsock.h"
#else
#include <netinet/in.h>
#include <zconf.h>
#include <arpa/inet.h>
#endif

int initNetwork();
int closeSocket(int socketDescriptor);

#endif //SERVER_NETWORKUTILS_H
