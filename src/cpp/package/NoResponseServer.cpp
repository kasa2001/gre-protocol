#include "../../hpp/package/NoResponseServer.h"

string NoResponseServer::toString() {
    string message = "No-Response-Server\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}