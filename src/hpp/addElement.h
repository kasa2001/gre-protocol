//
// Created by Dawid on 27.06.2021.
//

#ifndef MAIN_CPP_ADDELEMENT_H
#define MAIN_CPP_ADDELEMENT_H

#include <string>
using namespace std;
//zmiene gui
extern MSG Komunikat;
extern HWND hwnd,hLogo[9];
extern HBITMAP hPicture[9];
extern HWND parametr1,parametr2,parametr3,parametr4,parametr5;
//zmiene sterujace
extern string p[9];
extern int polaczeniaLogiczne[4];
extern int polaczeniaFizyczne[4];
extern wstring cos[9];
extern int canShow;

extern HWND messageLabel;
extern HWND log;
extern HWND logLabel;

void AddButoon(HWND hwnd);
void AddLabel(HWND hwnd);
void AddTextBox(HWND hwnd);
#endif //MAIN_CPP_ADDELEMENT_H
