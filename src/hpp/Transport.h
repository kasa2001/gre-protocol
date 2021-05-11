#ifndef GRE_PROTOCOL_TRANSPORT_H
#define GRE_PROTOCOL_TRANSPORT_H


#include <winsock.h>

class Transport {

public:
    char * receiveMessage(SOCKET socket, char *reply, int length);
    SOCKET createSocket();
    void sendMessage(SOCKET socket, char *message);
    struct sockaddr_in createSocketData(const char *address, u_short port);
    void connectWithSocket(SOCKET socket, struct sockaddr_in server);
    void closeSocket(SOCKET socket);
};


#endif //GRE_PROTOCOL_TRANSPORT_H
