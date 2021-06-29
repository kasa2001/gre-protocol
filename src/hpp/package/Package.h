#ifndef GRE_PROTOCOL_PACKAGE_H
#define GRE_PROTOCOL_PACKAGE_H

#include <string>

using namespace std;

class Package {
protected:
    int portDestination;
    string hostDestination;

public:
    Package(int port, string dest);

    Package();

    virtual string toString();

    int getPortDestination() const;

    void setPortDestination(int portDestination);

    const string &getHostDestination() const;

    void setHostDestination(const string &hostDestination);
};


#endif //GRE_PROTOCOL_PACKAGE_H
