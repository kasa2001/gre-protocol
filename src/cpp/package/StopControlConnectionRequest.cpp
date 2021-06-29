#include "../../hpp/package/StopControlConnectionRequest.h"

string StopControlConnectionRequest::toString() {
    string message = "Stop-Control-Connecting-Request\n";

    message.append(this->getHostDestination());
    message.append(":");
    message.append(to_string(this->getPortDestination()));

    return message;
}
