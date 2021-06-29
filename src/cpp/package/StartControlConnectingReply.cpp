#include "../../hpp/package/StartControlConnectingReply.h"

string StartControlConnectingReply::toString() {
    string message = "Start-Control-Connecting-Reply\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}