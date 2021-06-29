#include <windows.h>
#include <string>
#include "src/hpp/Other.h"
#include "src/hpp/GRE.h"
#include "src/hpp/Conetion.h"
#include "src/hpp/Image.h"
#include "src/hpp/addElement.h"
#include "src/hpp/Simulation.h"
#include "src/hpp/routerFunction.h"

# define ADD_Router 1
# define DO_CONNECTION 2
# define DO_GRE 3
# define START 4
# define CHECKED 5
# define RESTART 7
#define CHANGE_SIMULATION 8
#define WM_APP_MY_THREAD_UPDATE 0x9000
#define WM_UPDATE_CONNECTION_SHOW 0x9001
#define WM_REMOVE_THREADS 0x9002

using namespace std;
//zmiene gui
char NazwaKlasy[] = "Klasa Okienka";
MSG Komunikat;
HWND hwnd, hLogo[9];
HBITMAP hPicture[9];
HWND parametr1, parametr2, parametr3, parametr4, parametr5;

// Logi do GUI
HWND messageLabel;
HWND log;
HWND logLabel;
// END Logi do GUI

//zmiene sterujace
string p[9];
int polaczeniaLogiczne[4];
int polaczeniaFizyczne[4];
wstring cos[9];
int canShow = 0;
int typeSimulation = 1;


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WSADATA wsaData;

    if (WSAStartup(0x202, &wsaData) != 0) {
        exit(255);
    }

    // WYPEŁNIANIE STRUKTURY
    WNDCLASSEX wc;


    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

    // REJESTROWANIE KLASY OKNA
    if (!RegisterClassEx(&wc)) {
        MessageBox(nullptr, "Blad przy tworzenu obiektu okna", "Blad krytyczny",
                   MB_ICONEXCLAMATION | MB_OK);
        return 1;
    }

    // TWORZENIE OKNA

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, NazwaKlasy, "GRE", WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT, 800, 800, nullptr, nullptr, hInstance, nullptr);

    if (hwnd == nullptr) {
        MessageBox(nullptr, "Nie przechwycono uchwytu", "Blad krytyczny", MB_ICONEXCLAMATION);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow); // Pokaż okienko...
    UpdateWindow(hwnd);

    // Pętla komunikatów
    while (GetMessage(&Komunikat, nullptr, 0, 0)) {
        TranslateMessage(&Komunikat);
        DispatchMessage(&Komunikat);
    }
    //Dodawanie obrazka


    return Komunikat.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            switch (wp) {
                case ADD_Router:
                    addRouter();
                    break;
                case DO_CONNECTION:

                    coneting();
                    break;
                case DO_GRE:
                    GRE();
                    break;
                case START:
                    startSimulation();
                    break;
                case CHECKED:
                    if (canShow == 0) {
                        CreateWindowW(L"static", L"Logi będą wyświetlane:",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 200, 15, 200, 20, hwnd, nullptr,
                                      nullptr, nullptr);
                        canShow = 1;
                    } else {
                        CreateWindowW(L"static", L"Logi nie będą wyswietlane:",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 200, 15, 200, 20, hwnd, nullptr,
                                      nullptr, nullptr);
                        canShow = 0;
                    }
                    break;
                case RESTART :
                    inicial();
                    loadImages();
                    resteRouter();
                    clearReference();
                    break;
                case CHANGE_SIMULATION:
                    if (typeSimulation == 0) {
                        CreateWindowW(L"static", L"Symulacjia prawidłowa",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 160, 550, 150, 50, hwnd, nullptr,
                                      nullptr, nullptr);
                        typeSimulation = 1;
                    } else {
                        CreateWindowW(L"static", L"Symulacjia nieprawidłowa",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 160, 550, 150, 50, hwnd, nullptr,
                                      nullptr, nullptr);
                        typeSimulation = 0;
                    }

                    break;

            }
            break;


        case WM_APP_MY_THREAD_UPDATE:
            break;
        case WM_UPDATE_CONNECTION_SHOW: {
            wstring active;
            wstring actual;
            active = cos[wp];
            active += L"-active.bmp";
            actual = cos[wp];
            actual += L".bmp";
            hPicture[wp] = (HBITMAP) LoadImageW(nullptr, active.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            SendMessage(hLogo[wp], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[wp]);
            Sleep(500);
            hPicture[wp] = (HBITMAP) LoadImageW(nullptr, actual.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            SendMessage(hLogo[wp], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[wp]);
            Sleep(500);
            break;
        }
        case WM_REMOVE_THREADS: {
            for(auto route : router) {
                if (route != nullptr) {
                    route->removeThreads();
                }
            }
            MessageBox( nullptr, "Zakonczono symulacje", "Informacja", MB_ICONEXCLAMATION );
            break;
        }
        case WM_CLOSE:
            WSACleanup();
            DestroyWindow(hwnd);
            break;

        case WM_DESTROY:
            WSACleanup();
            PostQuitMessage(0);
            break;
        case WM_CREATE:
            loadImages();
            CreateImage(hwnd);
            AddButoon(hwnd);
            inicial();
            AddLabel(hwnd);
            AddTextBox(hwnd);
            break;

        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }

    return 0;
}

