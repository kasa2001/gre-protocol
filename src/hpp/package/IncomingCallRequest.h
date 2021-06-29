//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_INCOMINGCALLREQUEST_H
#define GRE_PROTOCOL_INCOMINGCALLREQUEST_H

#include "Package.h"

class Package;

class IncomingCallRequest : public Package {
public:
    IncomingCallRequest(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_INCOMINGCALLREQUEST_H
