#include "../hpp/Transport.h"
#include <winsock2.h>
#include <cstdio>
#include <cstring>

char *Transport::receiveMessage(SOCKET socket, char *reply, int length) {

    if (recv(socket, reply, length, 0) < 0) {
        puts("recv failed");
    }

    return reply;
}

SOCKET Transport::createSocket() {
    return socket(AF_INET, SOCK_STREAM, 0);
}

void Transport::sendMessage(SOCKET socket, const char *message) {
    send(socket, message, (int) strlen(message), 0);
}

/**
 * Socket data
 * @param address
 * @param port
 * @return
 */
struct sockaddr_in Transport::createSocketData(const char *address, u_short port) {
    sockaddr_in socketAddress{};
    socketAddress.sin_addr.s_addr = inet_addr(address);
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(port);

    return socketAddress;
}

sockaddr_in Transport::createServerSocketData(SOCKET socket, u_long address, u_short port) {
    int opt = 1;
    setsockopt(socket, SOL_SOCKET, SO_REUSEADDR,
               (const char *) &opt, sizeof(opt));

    sockaddr_in socketAddress{};
    socketAddress.sin_addr.s_addr = address;
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

int Transport::bindServer(SOCKET socket, struct sockaddr_in server) {
    return bind(socket, (struct sockaddr *) &server, sizeof server);
}

void Transport::serverListen(SOCKET server) {
    listen(server, 5);
}

SOCKET Transport::acceptClient(SOCKET server, struct  sockaddr_in client, int length) {
    return accept(server, (struct sockaddr *) &client, &length);
}
