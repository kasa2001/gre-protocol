//
// Created by Dawid on 27.06.2021.
//

#include <windows.h>
#include <string>
#include "../hpp/addElement.h"

#define ADD_Router 1
#define DO_CONNECTION 2
#define DO_GRE 3
#define START 4
#define CHECKED 5
#define RESTART 7
#define CHANGE_SIMULATION 8

void AddButoon(HWND hwnd) {
    CreateWindowW(L"Button", L"Add router", WS_VISIBLE | WS_CHILD, 100, 60, 100, 50, hwnd, (HMENU) ADD_Router, nullptr,
                  nullptr);
    CreateWindowW(L"Button", L"Connected router", WS_VISIBLE | WS_CHILD, 20, 240, 120, 50, hwnd, (HMENU) DO_CONNECTION,
                  nullptr, nullptr);
    CreateWindowW(L"Button", L"Set GRE endpoint", WS_VISIBLE | WS_CHILD, 150, 240, 120, 50, hwnd, (HMENU) DO_GRE,
                  nullptr, nullptr);
    CreateWindowW(L"Button", L"Start", WS_VISIBLE | WS_CHILD, 75, 290, 120, 50, hwnd, (HMENU) START, nullptr, nullptr);
    CreateWindowW(L"Button", L"Zmiana wyswietlania logow", WS_VISIBLE | WS_CHILD, 10, 0, 190, 50, hwnd, (HMENU) CHECKED,
                  nullptr, nullptr);
    CreateWindowW(L"Button", L"Restart", WS_VISIBLE | WS_CHILD, 140, 500, 300, 50, hwnd, (HMENU) RESTART, nullptr,
                  nullptr);
    CreateWindowW(L"Button", L"Rodzaj symulacji", WS_VISIBLE | WS_CHILD, 0, 550, 150, 50, hwnd, (HMENU) CHANGE_SIMULATION, nullptr,
                  nullptr);

}

//Dodawanie labeli
void AddLabel(HWND hwnd) {
    CreateWindowW(L"static", L"R0", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 350, 40, 100, 20, hwnd, nullptr,
                  nullptr, nullptr);
    CreateWindowW(L"static", L"R1", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 350, 360, 100, 20, hwnd, nullptr,
                  nullptr, nullptr);
    CreateWindowW(L"static", L"R2", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 550, 40, 100, 20, hwnd, nullptr,
                  nullptr, nullptr);
    CreateWindowW(L"static", L"R3", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 550, 360, 100, 20, hwnd, nullptr,
                  nullptr, nullptr);
    CreateWindowW(L"static", L"R1", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 80, 120, 70, 20, hwnd, nullptr,
                  nullptr, nullptr);
    CreateWindowW(L"static", L"R2", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 160, 120, 70, 20, hwnd, nullptr,
                  nullptr, nullptr);
    CreateWindowW(L"static", L"Logi nie będą wyświetlane:", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 200, 15, 200,
                  20, hwnd, nullptr, nullptr, nullptr);
    CreateWindowW(L"static", L"Numer rutera startowego", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 450, 450, 170,
                  20, hwnd, nullptr, nullptr, nullptr);
    CreateWindowW(L"static", L"GRE endpoint i 0", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 0, 180, 150, 20, hwnd,
                  nullptr, nullptr, nullptr);
    CreateWindowW(L"static", L"GRE endpoint i 1", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 160, 180, 150, 20,
                  hwnd, nullptr, nullptr, nullptr);

    CreateWindowW(L"static", L"Symulacjia prawidłowa", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 160, 550, 150, 50,
                  hwnd, nullptr, nullptr, nullptr);

    //Logi i wiadomość
    CreateWindowW(L"static", L"Trasa:", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, 400, 70, 20, hwnd, nullptr,
                  nullptr, nullptr);
    messageLabel = CreateWindowW(L"static", nullptr, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 140, 400, 150, 20,
                                 hwnd, nullptr,
                                 nullptr, nullptr);

    logLabel = CreateWindowW(L"static", L"Log message:", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, 430, 70, 20,
                             hwnd,
                             nullptr, nullptr, nullptr);
    log = CreateWindowW(L"static", nullptr, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 140, 430, 300, 60, hwnd,
                        nullptr,
                        nullptr, nullptr);

}

//Dodawanie pola do wpisywania
void AddTextBox(HWND hwnd) {
    parametr1 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 80, 150, 70, 20, hwnd, nullptr, nullptr,
                              nullptr);
    parametr2 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 160, 150, 70, 20, hwnd, nullptr, nullptr,
                              nullptr);
    parametr3 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 450, 475, 100, 20, hwnd, nullptr,
                              nullptr, nullptr);
    parametr4 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 0, 210, 150, 20, hwnd, nullptr, nullptr,
                              nullptr);
    parametr5 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 160, 210, 150, 20, hwnd, nullptr,
                              nullptr, nullptr);
}