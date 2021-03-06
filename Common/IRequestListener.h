#ifndef SERVER_IREQUESTLISTENER_H
#define SERVER_IREQUESTLISTENER_H

#include <vector>
#include <BytesParser.h>

class IRequestListener
{
public:
    virtual std::vector<unsigned char> onGotRequest(int clientId, std::vector<unsigned char> msg) = 0;
//    virtual int onClientAccepted(int socketId) = 0;
//    virtual void onClientDisconnected(int socketId) = 0;

    template <class T>
    inline T getData(const std::vector<unsigned char> &bytes, int &offset);
};

template <class T>
T IRequestListener::getData(const std::vector<unsigned char> &bytes, int &offset)
{
    int fs = offset;
    offset += sizeof(T);
    return BytesParser::parse<T>(bytes, fs);
}

#endif //SERVER_IREQUESTLISTENER_H
