#include "../../hpp/package/IncomingCallReply.h"

string IncomingCallReply::toString() {
    string message = "Incoming-Call-Reply\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}