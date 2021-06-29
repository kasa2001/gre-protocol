#ifndef GRE_PROTOCOL_CANNOTCREATEPACKAGE_H
#define GRE_PROTOCOL_CANNOTCREATEPACKAGE_H

#include <iostream>

using namespace std;

class CannotCreatePackage : exception {


    virtual const char* what();
};


#endif //GRE_PROTOCOL_CANNOTCREATEPACKAGE_H
