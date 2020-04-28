#include "SystemUtils.h"

void sleepSecs(int secs)
{
#if defined(WIN32) || defined(_WIN64)
    Sleep(secs / 1000);
#else
    sleep(secs);
#endif
}

void sleepMillis(int millis)
{
#if defined(WIN32) || defined(_WIN64)  
    Sleep(millis);
#else
    usleep(millis * 1000);
#endif
}