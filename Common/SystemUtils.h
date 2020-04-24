#ifndef SERVER_SYSTEMUTILS_H
#define SERVER_SYSTEMUTILS_H

#ifdef _WIN64
#include <windows.h>
#include "winsock.h"
#else
#include <unistd.h>
#endif

void sleepSecs(int secs);
void sleepMillis(int millis);

#endif //SERVER_SYSTEMUTILS_H
