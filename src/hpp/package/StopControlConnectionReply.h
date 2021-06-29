//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_STOPCONTROLCONNECTIONREPLY_H
#define GRE_PROTOCOL_STOPCONTROLCONNECTIONREPLY_H

#include "Package.h"

class Package;

class StopControlConnectionReply : public Package {
public:
    StopControlConnectionReply(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_STOPCONTROLCONNECTIONREPLY_H
