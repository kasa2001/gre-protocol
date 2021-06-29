#include "../hpp/routerFunction.h"
#include "../hpp/GRE.h"


Router *router[4];

int port = 8000;

void renderRouter(int positionX, int positionY) {
    router[positionX]->connectWithNetwork(
            new Network(
                    port + 1,
                    port,
                    positionY
            ),
            (polaczeniaFizyczne[positionX] == 1 ? "e00" : "e01")
    );

    router[positionY]->connectWithNetwork(
            new Network(
                    port,
                    port + 1,
                    positionX
            ),
            (polaczeniaFizyczne[positionY] == 1 ? "e00" : "e01")
    );

    port += 2;
}

void renderGre(int positionX, int positionY, int firstInterface, int secondInterface) {
    auto *network1 = new Network(port, port + 1, positionY);
    auto *network2 = new Network(port + 1, port, positionX);

    auto *networkRouter1 = (firstInterface == 0 ? router[positionX]->getE00() : router[positionX]->getE01());
    auto *networkRouter2 = (secondInterface == 0 ? router[positionY]->getE00() : router[positionX]->getE01());

    network1->setStartPort(
            networkRouter1->getServerPort()
    );

    network2->setStartPort(
            networkRouter2->getServerPort()
    );

    router[positionX]->connectWithNetwork(
            network1,
            "gre"
    );

    router[positionY]->connectWithNetwork(
            network2,
            "gre"
    );

    port += 2;
}
