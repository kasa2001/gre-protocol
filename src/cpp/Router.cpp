#include <winsock2.h>
#include "../hpp/Router.h"
#include "../hpp/package/PackageFactory.h"
#include <pthread.h>
#include "../hpp/Simulation.h"
#define WM_APP_MY_THREAD_UPDATE 0x9000
#define WM_UPDATE_CONNECTION_SHOW 0x9001
#define WM_REMOVE_THREADS 0x9002

using namespace std;

constexpr unsigned int str2int(const char *str, int h = 0) {
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

void sendMessage(Network *network, Transport *transport, Package *package) {
    SOCKET tmp = transport->createSocket();
    int port = network->getClientPort();

    sockaddr_in server = transport->createSocketData("127.0.0.1", port);

    transport->connectWithSocket(tmp, server);
    char message[100] = "";
    strcpy(message, package->toString().c_str());

    transport->sendMessage(tmp, message);

    transport->closeSocket(tmp);
}

void Router::connectWithNetwork(Network *network, const char *interfaceName) {
    switch (str2int(interfaceName)) {
        case str2int("e00"): {
            this->e00 = new Network(network->getClientPort(), network->getServerPort(), network->getRouterId());
            break;
        }
        case str2int("e01"): {
            this->e01 = new Network(network->getClientPort(), network->getServerPort(), network->getRouterId());
            break;
        }
        case str2int("gre"): {
            this->gre = network;
            break;
        }
    }
}

void Router::movePackage(const string &interfaceName, Package *package) {
    if (interfaceName == "e00") {
        sendMessage(this->e01, this->transport, package);
    }
    if (interfaceName == "e01") {
        sendMessage(this->e00, this->transport, package);
    }
}

void Router::disconnectNetwork(const char *interfaceName) {
    switch (str2int(interfaceName)) {
        case str2int("e00"): {
            delete this->e00;
            break;
        }
        case str2int("e01"): {
            delete this->e01;
            break;
        }
        case str2int("gre"): {
            delete this->gre;
            break;
        }
    }
}

void Router::listenOnNetwork(int simulation) {
    this->typeSimulation = simulation;
    if (this->e00 != nullptr) {
        struct arg_struct *args00 = nullptr;
        args00 = new arg_struct;
        args00->router = this;
        args00->interfaceName = "e00";
        pthread_create(nullptr, nullptr, reinterpret_cast<void *(*)(void *)>(&Router::listenSingleNetwork),
                       (void *) args00);
    }

    if (this->e01 != nullptr) {
        struct arg_struct *args01 = nullptr;
        args01 = new arg_struct;
        args01->router = this;
        args01->interfaceName = "e01";
        pthread_create(nullptr, nullptr, reinterpret_cast<void *(*)(void *)>(&Router::listenSingleNetwork),
                       (void *) args01);
    }
}

[[noreturn]] void *Router::listenSingleNetwork(void *args) {
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, nullptr);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, nullptr);

    auto *arguments = (struct arg_struct *) args;
    Network *network = nullptr;
    string interfaceName = arguments->interfaceName;
    Transport *transport = arguments->router->transport;

    SOCKET socket;
    socket = transport->createSocket();

    if (arguments->interfaceName == "e00") {
        network = arguments->router->e00;
        arguments->router->setE00Socket(socket);
    }

    if (arguments->interfaceName == "e01") {
        network = arguments->router->e01;
        arguments->router->setE01Socket(socket);
    }

    socket = transport->createSocket();

    sockaddr_in server = transport->createServerSocketData(
            socket,
            INADDR_ANY,
            network->getServerPort()
    );

    transport->bindServer(socket, server);

    transport->serverListen(socket);

    while (true) {
        struct sockaddr_in client{};
        char buffer[100] = "";

        int len = sizeof(client);

        SOCKET clientSocket = transport->acceptClient(socket, client, len);

        transport->receiveMessage(clientSocket, buffer, 100);

        if (strlen(buffer) == 0 || clientSocket == SOCKET_ERROR) {
            continue;
        }

        char text[200] = "";

        sprintf(text, "Router %d recv message: %s", arguments->router->getId(), buffer);

        SetWindowTextA(
                arguments->router->logs,
                text
        );

        sprintf(text, "Trace R%d -> R%d", network->getRouterId(), arguments->router->id);

        SetWindowTextA(
                arguments->router->message,
                text
        );

        sprintf(text, "Router %d send message: %s", arguments->router->getId(), buffer);


        SendMessageA(hwnd, WM_UPDATE_CONNECTION_SHOW, (3 + arguments->router->id + network->getRouterId()), 0);

        Sleep(1000);
        char * message = strtok(buffer, "\n");

        char *clientData = strtok(nullptr, "\n");

        char *host;
        int port;

        if (!arguments->router->isGreEndpoint(clientData)) {
            SetWindowTextA(
                    arguments->router->logs,
                    text
            );

            Sleep(1000);

            host = strtok(clientData, ":");
            port = strtol(strtok(nullptr, ":"), nullptr, 0);
            arguments->router->movePackage(
                    interfaceName,
                    PackageFactory::createPackageInstance(
                            message,
                            host,
                            port
                    )
            );
            continue;
        }
        host = strtok(clientData, ":");
        port = arguments->router->getGreConnection()->getClientPort();
        Package *package;

        switch (arguments->router->typeSimulation) {
            case 0: {
                package = PackageFactory::renderBadResponse(
                        message,
                        host,
                        port
                );
                break;
            }
            case 1: {
                package = PackageFactory::renderResponse(
                        message,
                        host,
                        port
                );
            }
        }

        if (package != nullptr) {
            char * messageToCheck = strtok(buffer, "\n");

            if (strcmp(messageToCheck, "No-Response-Server") == 0) {
                sprintf(text, "End simulation");
                SetWindowTextA(
                        arguments->router->message,
                        text
                );

                SendMessageA(hwnd, WM_REMOVE_THREADS, 0, 0);
                continue;
            }

            sprintf(text, "Router %d send message: %s", arguments->router->getId(), package->toString().c_str());

            SetWindowTextA(
                    arguments->router->logs,
                    text
            );

            Sleep(1000);

            arguments->router->movePackage(
                    package
            );

            continue;
        }

        sprintf(text, "End simulation");

        SetWindowTextA(
                arguments->router->message,
                text
        );

        SendMessageA(hwnd, WM_REMOVE_THREADS, 0, 0);
    }
}

bool Router::isGreEndpoint(char *string) {
    char *port;
    if (this->gre != nullptr) {
        strtok(string, ":");
        port = strtok(nullptr, ":");

        return this->gre->getServerPort() == strtol(port, nullptr, 0);
    }

    return false;
}

Router::Router(int id) {
    this->id = id;
    this->transport = new Transport();
    this->e00 = nullptr;
    this->e01 = nullptr;
    this->gre = nullptr;
}

bool Router::hasGreEndpoint() {
    return nullptr != this->gre;
}

void Router::setE00Socket(SOCKET i) {
    this->e00Socket = i;
}

void Router::setE01Socket(SOCKET i) {
    this->e01Socket = i;
}

Network *Router::getGreConnection() {
    return this->gre;
}

void Router::movePackage(Package *package) {
    int port = this->gre->getStartPort();

    if (this->e00->getServerPort() == port) {
        sendMessage(this->e00, this->transport, package);
    }

    if (this->e01 != nullptr && this->e01->getClientPort() == port) {
        sendMessage(this->e01, this->transport, package);
    }
}

Network *Router::getE00() const {
    return this->e00;
}

Network *Router::getE01() const {
    return this->e01;
}

void Router::addMessageLabel(HWND pHwnd) {
    this->message = pHwnd;
}

void Router::addLogLabel(HWND pHwnd) {
    this->logs = pHwnd;
}

int Router::getId() const {
    return this->id;
}

void Router::removeThreads() {
    pthread_cancel(this->e00Thread);
    pthread_cancel(this->e01Thread);
    pthread_join(this->e00Thread, nullptr);
    pthread_join(this->e00Thread, nullptr);

    this->transport->closeSocket(this->e00Socket);
    this->transport->closeSocket(this->e01Socket);
}