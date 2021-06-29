    #include "../../hpp/package/Package.h"
#include <string>

using namespace std;


string Package::toString() {
    return "Not Implement";
}

Package::Package(int port, string dest) {
    this->portDestination = port;
    this->hostDestination = move(dest);
}

int Package::getPortDestination() const {
    return portDestination;
}

void Package::setPortDestination(int portDestination) {
    Package::portDestination = portDestination;
}

const string &Package::getHostDestination() const {
    return hostDestination;
}

void Package::setHostDestination(const string &hostDestination) {
    Package::hostDestination = hostDestination;
}

Package::Package() {}
