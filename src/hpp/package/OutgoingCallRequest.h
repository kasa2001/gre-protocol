//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_OUTGOINGCALLREQUEST_H
#define GRE_PROTOCOL_OUTGOINGCALLREQUEST_H

#include "Package.h"

class Package;

class OutgoingCallRequest : public Package {
public:
    OutgoingCallRequest(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_OUTGOINGCALLREQUEST_H
