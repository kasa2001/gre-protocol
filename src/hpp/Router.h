//
// Created by pawel on 23.04.2021.
//

#ifndef GRE_PROTOCOL_ROUTER_H
#define GRE_PROTOCOL_ROUTER_H


#include "Network.h"
#include "Package.h"
#include <string>

using namespace std;

class Router {

    private:
        Network e00;
        Network e01;
        Network e02;
        Network e03;

    public:
        void connectWithNetwork(Network network, string interface);
        void disconnectNetwork(string interface);
        void movePackage(Package package);

};


#endif //GRE_PROTOCOL_ROUTER_H
