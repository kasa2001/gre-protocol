//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_ECHOREPLY_H
#define GRE_PROTOCOL_ECHOREPLY_H

#include "Package.h"

class Package;

class EchoReply : public Package {
public:
    EchoReply(char *string, int i) : Package(i, string) {}

    string toString();
};


#endif //GRE_PROTOCOL_ECHOREPLY_H
