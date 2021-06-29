//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_STARTCONTROLCONNECTING_H
#define GRE_PROTOCOL_STARTCONTROLCONNECTING_H

#include "Package.h"

class Package;

class StartControlConnecting : public Package {
public:
    StartControlConnecting(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_STARTCONTROLCONNECTING_H
