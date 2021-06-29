#include "../../hpp/package/OutgoingCallRequest.h"

string OutgoingCallRequest::toString() {
    string message = "Outgoing-Call-Request\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}