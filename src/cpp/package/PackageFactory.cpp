#include "../../hpp/package/PackageFactory.h"
#include "../../hpp/package/EchoReply.h"
#include "../../hpp/exception/CannotCreatePackage.h"
#include "../../hpp/package/EchoRequest.h"
#include "../../hpp/package/IncomingCallConnected.h"
#include "../../hpp/package/IncomingCallRequest.h"
#include "../../hpp/package/IncomingCallReply.h"
#include "../../hpp/package/OutgoingCallReply.h"
#include "../../hpp/package/OutgoingCallRequest.h"
#include "../../hpp/package/StartControlConnecting.h"
#include "../../hpp/package/StopControlConnectionReply.h"
#include "../../hpp/package/StartControlConnectingReply.h"
#include "../../hpp/package/StopControlConnectionRequest.h"
#include "../../hpp/package/NoResponseServer.h"
#include <cstring>

using namespace std;

Package *PackageFactory::createPackageInstance(char *message, char *host, int port) {

    if (strcmp(message, "Echo-Reply") == 0) {
        return new EchoReply(host, port);
    }
    if (strcmp(message, "Echo-Request") == 0) {
        return new EchoRequest(host, port);
    }
    if (strcmp(message, "Incoming-Call-Connected") == 0) {
        return new IncomingCallConnected(host, port);
    }
    if (strcmp(message, "Incoming-Call-Reply") == 0) {
        return new IncomingCallReply(host, port);
    }
    if (strcmp(message, "Incoming-Call-Request") == 0) {
        return new IncomingCallRequest(host, port);
    }
    if (strcmp(message, "Outgoing-Call-Reply") == 0) {
        return new OutgoingCallReply(host, port);
    }
    if (strcmp(message, "Outgoing-Call-Request") == 0) {
        return new OutgoingCallRequest(host, port);
    }
    if (strcmp(message, "Start-Control-Connecting") == 0) {
        return new StartControlConnecting(host, port);
    }
    if (strcmp(message, "Start-Control-Connecting-Reply") == 0) {
        return new StartControlConnectingReply(host, port);
    }
    if (strcmp(message, "Stop-Control-Connecting-Reply") == 0) {
        return new StopControlConnectionReply(host, port);
    }
    if (strcmp(message, "Stop-Control-Connecting-Request") == 0) {
        return new StopControlConnectionRequest(host, port);
    }
    if (strcmp(message, "No-Response-Server") == 0) {
        return new NoResponseServer(host, port);
    }

    throw CannotCreatePackage();
}

Package *PackageFactory::renderResponse(char *message, char *host, int port) {
    if (strcmp(message, "Echo-Reply") == 0) {
        return new StopControlConnectionRequest(host, port);
    }
    if (strcmp(message, "Echo-Request") == 0) {
        return new EchoReply(host, port);
    }
    if (strcmp(message, "Incoming-Call-Connected") == 0) {
        return new EchoRequest(host, port);
    }
    if (strcmp(message, "Incoming-Call-Reply") == 0) {
        return new IncomingCallConnected(host, port);
    }
    if (strcmp(message, "Incoming-Call-Request") == 0) {
        return new IncomingCallReply(host, port);
    }
    if (strcmp(message, "Outgoing-Call-Reply") == 0) {
        return new IncomingCallRequest(host, port);
    }
    if (strcmp(message, "Outgoing-Call-Request") == 0) {
        return new OutgoingCallReply(host, port);
    }
    if (strcmp(message, "Start-Control-Connecting") == 0) {
        return new StartControlConnectingReply(host, port);
    }
    if (strcmp(message, "Start-Control-Connecting-Reply") == 0) {
        return new OutgoingCallReply(host, port);
    }
    if (strcmp(message, "Stop-Control-Connecting-Reply") == 0) {
        return nullptr;
    }
    if (strcmp(message, "Stop-Control-Connecting-Request") == 0) {
        return new StopControlConnectionReply(host, port);
    }

    throw CannotCreatePackage();
}

Package *PackageFactory::renderBadResponse(char *message, char *host, int port) {
    if (strcmp(message, "Start-Control-Connecting") == 0) {
        return new NoResponseServer(host, port);
    }

    if (strcmp(message, "No-Response-Server") == 0) {
        return new StartControlConnecting(host, port);
    }

    return nullptr;
}