#include <windows.h>
#include <string>
#include "../hpp/Simulation.h"
#include "../hpp/routerFunction.h"
#include "../hpp/package/StartControlConnecting.h"

void startSimulation() {
    int wieksza, mniesza, StartRouter;
    mniesza = wieksza = -1;

    wchar_t startRouter[1];
    GetWindowTextW(parametr3, startRouter, 2);

    bool isLogicConnection = false;


    for (auto check: polaczeniaLogiczne) {
        if (check == 1) {
            isLogicConnection = true;
        }
    }

    if (!isLogicConnection) {
        MessageBox(nullptr,
                   "Brak logicznego polaczenia GRE",
                   "Blad", MB_ICONEXCLAMATION);
        return;
    }

    if (startRouter[0] == '/0') {
        MessageBox(nullptr, "Nie podano poczatkowego routera", "Blad", MB_ICONEXCLAMATION);
        return;
    }

    StartRouter = *startRouter - 48;

    if (StartRouter >= 0 && StartRouter <= 3) {
        if (polaczeniaLogiczne[StartRouter] == 0) {
            MessageBox(nullptr,
                       "Brak zdefiniowanego endpoint-a GRE w startowym routerze",
                       "Blad", MB_ICONEXCLAMATION);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (router[i] == nullptr) {
                break;
            }
            if (router[i]->hasGreEndpoint()) {
                if (mniesza == -1) {
                    mniesza = i;
                    router[i]->listenOnNetwork(typeSimulation);
                    router[i]->addMessageLabel(messageLabel);
                    if (canShow == 1) {
                        router[i]->addLogLabel(log);
                    }
                    continue;
                }

                wieksza = i;
            }

            router[i]->listenOnNetwork(typeSimulation);
            router[i]->addMessageLabel(messageLabel);

            if (canShow == 1) {
                router[i]->addLogLabel(log);
            }
        }

        char host[20] = "127.0.0.1";

        router[StartRouter]->movePackage(
                new StartControlConnecting(host, router[(StartRouter == wieksza ? mniesza
                                                                                : wieksza)]->getGreConnection()->getServerPort()));
        return;
    }

    MessageBox(nullptr, "Podano zla wartosc. Dozwolone numery routerow od 0 do 3", "Blad", MB_ICONEXCLAMATION);
}