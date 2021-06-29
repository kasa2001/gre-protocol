#include "../../hpp/package/EchoReply.h"

string EchoReply::toString() {
    string message = "Echo-Reply\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}
