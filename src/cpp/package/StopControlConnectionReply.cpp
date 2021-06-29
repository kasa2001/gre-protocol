#include "../../hpp/package/StopControlConnectionReply.h"

string StopControlConnectionReply::toString() {
    string message = "Stop-Control-Connecting-Reply\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}