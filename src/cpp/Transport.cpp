#include "../hpp/Transport.h"
#include <winsock2.h>
#include <cstdio>
#include <cstring>

char * Transport::receiveMessage(SOCKET socket, char *reply, int length) {

    if(recv(socket, reply , length , 0) < 0)
    {
        puts("recv failed");
    }

    return reply;
}

SOCKET Transport::createSocket() {
    return socket(AF_INET, SOCK_STREAM, 0);
}

void Transport::sendMessage(SOCKET socket, char *message) {
    send(socket, message, (int) strlen(message), 0);
}

/**
 * Socket data
 * @param address
 * @param port
 * @return
 */
struct sockaddr_in Transport::createSocketData(const char *address, u_short port) {
    struct sockaddr_in socketAddress;
    socketAddress.sin_addr.s_addr = inet_addr(address);
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(port);

    return socketAddress;
}

void Transport::connectWithSocket(SOCKET socket, struct sockaddr_in server) {
    //Connect to remote server
    if (connect(socket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        puts("connect error");
        return;
    }
}

void Transport::closeSocket(SOCKET socket) {
    closesocket(socket);
}