#ifndef GRE_PROTOCOL_NETWORK_H
#define GRE_PROTOCOL_NETWORK_H


#include "Router.h"
#include <winsock2.h>

class Router;

class Network {

private:
    int clientPort;
    int serverPort;
    int startPort;
    int routerId;
public:

    Network(int clientPort, int serverPort, int routerId);

    int getClientPort() const;

    int getServerPort() const;

    int getStartPort() const;

    void setStartPort(int port);

    int getRouterId() const;
};


#endif
