//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_INCOMINGCALLCONNECTED_H
#define GRE_PROTOCOL_INCOMINGCALLCONNECTED_H

#include "Package.h"

class Package;

class IncomingCallConnected : public Package {
public:
    IncomingCallConnected(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_INCOMINGCALLCONNECTED_H
