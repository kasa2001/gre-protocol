#include "../hpp/Network.h"

int Network::getClientPort() const {
    return this->clientPort;
}

int Network::getServerPort() const {
    return this->serverPort;
}

Network::Network(int clientPort, int serverPort, int routerId) {
    this->clientPort = clientPort;
    this->serverPort = serverPort;
    this->startPort = -1;
    this->routerId = routerId;
}

int Network::getStartPort() const {
    return this->startPort;
}

void Network::setStartPort(int port) {
    Network::startPort = port;
}

int Network::getRouterId() const {
    return routerId;
}
