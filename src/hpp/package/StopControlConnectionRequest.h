//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_STOPCONTROLCONNECTIONREQUEST_H
#define GRE_PROTOCOL_STOPCONTROLCONNECTIONREQUEST_H

#include "Package.h"

class Package;

class StopControlConnectionRequest : public Package {
public:
    StopControlConnectionRequest(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_STOPCONTROLCONNECTIONREQUEST_H
