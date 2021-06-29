//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_ECHOREQUEST_H
#define GRE_PROTOCOL_ECHOREQUEST_H

#include "Package.h"

class Package;

class EchoRequest : public Package {
public:
    EchoRequest(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_ECHOREQUEST_H
