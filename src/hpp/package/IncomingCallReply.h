//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_INCOMINGCALLREPLY_H
#define GRE_PROTOCOL_INCOMINGCALLREPLY_H

#include "Package.h"

class Package;

class IncomingCallReply : public Package {
public:
    IncomingCallReply(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_INCOMINGCALLREPLY_H
