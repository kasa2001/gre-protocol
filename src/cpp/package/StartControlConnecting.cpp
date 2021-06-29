#include "../../hpp/package/StartControlConnecting.h"

string StartControlConnecting::toString() {
    string message = "Start-Control-Connecting\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}