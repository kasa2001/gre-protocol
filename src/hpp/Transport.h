#ifndef GRE_PROTOCOL_TRANSPORT_H
#define GRE_PROTOCOL_TRANSPORT_H


#include <winsock2.h>

class Transport {

public:
    char *receiveMessage(SOCKET socket, char *reply, int length);

    SOCKET createSocket();

    void sendMessage(SOCKET socket, const char *message);

    struct sockaddr_in createSocketData(const char *address, u_short port);

    void connectWithSocket(SOCKET socket, struct sockaddr_in server);

    void closeSocket(SOCKET socket);

    int bindServer(SOCKET socket, struct sockaddr_in server);

    void serverListen(SOCKET server);

    SOCKET acceptClient(SOCKET server, struct  sockaddr_in client, int length);

    sockaddr_in createServerSocketData(SOCKET socket, u_long address, u_short port);
};


#endif //GRE_PROTOCOL_TRANSPORT_H
