#include "../../hpp/package/IncomingCallConnected.h"

string IncomingCallConnected::toString() {
    string message = "Incoming-Call-Connected\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}