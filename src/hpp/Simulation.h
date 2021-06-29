//
// Created by Dawid on 27.06.2021.
//

#ifndef MAIN_CPP_SIMULATION_H
#define MAIN_CPP_SIMULATION_H
#include <string>
using namespace std;
//zmiene gui
extern MSG Komunikat;
extern HWND hwnd,hLogo[9];
extern HBITMAP hPicture[9];
extern HWND parametr1,parametr2,parametr3;
extern int typeSimulation;

// Logi do GUI
extern HWND messageLabel;
extern HWND log;
extern HWND logLabel;

// END Logi do GUI

//zmiene sterujace
extern string p[9];
extern int polaczeniaLogiczne[4];
extern int polaczeniaFizyczne[4];
extern wstring cos[9];
extern int canShow;
void startSimulation();

#endif //MAIN_CPP_SIMULATION_H
