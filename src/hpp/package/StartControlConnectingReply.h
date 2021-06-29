//
// Created by pawel on 07.06.2021.
//

#ifndef GRE_PROTOCOL_STARTCONTROLCONNECTINGREPLY_H
#define GRE_PROTOCOL_STARTCONTROLCONNECTINGREPLY_H

#include "Package.h"

class Package;

class StartControlConnectingReply : public Package {
public:
    StartControlConnectingReply(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_PROTOCOL_STARTCONTROLCONNECTINGREPLY_H
