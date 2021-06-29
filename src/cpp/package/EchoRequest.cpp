#include "../../hpp/package/EchoRequest.h"

string EchoRequest::toString() {
    string message = "Echo-Request\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}