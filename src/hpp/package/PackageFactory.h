//
// Created by pawel on 26.06.2021.
//

#ifndef GRE_PROTOCOL_PACKAGEFACTORY_H
#define GRE_PROTOCOL_PACKAGEFACTORY_H


#include "Package.h"

class Package;

class PackageFactory {
public:
    static Package *createPackageInstance(char *message, char * host, int port);

    static Package *renderResponse(char *message, char * host, int port);

    static Package *renderBadResponse(char *message, char *host, int port);
};


#endif //GRE_PROTOCOL_PACKAGEFACTORY_H
