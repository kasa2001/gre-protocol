#ifndef GRE_PROTOCOL_ROUTER_H
#define GRE_PROTOCOL_ROUTER_H


#include "Network.h"
#include "package/Package.h"
#include "Transport.h"
#include <string>

class Network;

class Transport;

using namespace std;

class Router;


struct arg_struct {
    string interfaceName;
    Router *router;
};

class Router {

private:
    Network *e00;
    Network *e01;
    Network *gre;
    Transport *transport;
    pthread_t e00Thread;
    pthread_t e01Thread;
    SOCKET e00Socket;
    SOCKET e01Socket;
    HWND message;
    HWND logs;
    int id;
    int typeSimulation;

public:
    Router(int id);

    void connectWithNetwork(Network *network, const char *interfaceName);

    void disconnectNetwork(const char *interfaceName);

    void movePackage(const string &interfaceName, Package *package);

    void movePackage(Package *package);

    void listenOnNetwork(int simulation);

    [[noreturn]] static void *listenSingleNetwork(void *args);

    bool isGreEndpoint(char *string);

    bool hasGreEndpoint();

    void setE00Socket(SOCKET i);

    void setE01Socket(SOCKET i);

    Network * getGreConnection();

    Network *getE00() const;

    Network *getE01() const;

    void addMessageLabel(HWND pHwnd);

    void addLogLabel(HWND pHwnd);

    int getId() const;

    void removeThreads();
};


#endif //GRE_PROTOCOL_ROUTER_H
