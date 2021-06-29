#include "../../hpp/package/OutgoingCallReply.h"

string OutgoingCallReply::toString() {
    string message = "Outgoing-Call-Reply\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}