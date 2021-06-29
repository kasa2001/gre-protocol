//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_OUTGOINGCALLREPLY_H
#define GRE_PROTOCOL_OUTGOINGCALLREPLY_H

#include "Package.h"

class Package;

class OutgoingCallReply : public Package {
public:
    OutgoingCallReply(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_OUTGOINGCALLREPLY_H
