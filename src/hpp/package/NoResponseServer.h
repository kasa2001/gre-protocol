//
// Created by pawel on 28.06.2021.
//

#ifndef GRE_NORESPONSESERVER_H
#define GRE_NORESPONSESERVER_H

#include "Package.h"

class Package;

class NoResponseServer : public Package {
public:
    NoResponseServer(char *string, int i) : Package(i, string) {}
    string toString();
};


#endif //GRE_NORESPONSESERVER_H
