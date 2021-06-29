#include "../../hpp/package/IncomingCallRequest.h"

string IncomingCallRequest::toString() {
    string message = "Incoming-Call-Request\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}