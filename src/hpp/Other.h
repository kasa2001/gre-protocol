//
// Created by Dawid on 27.06.2021.
//

#ifndef MAIN_CPP_OTHER_H
#define MAIN_CPP_OTHER_H
#include <string>
#include <string>
using namespace std;
//zmiene gui
extern MSG Komunikat;
extern HWND hwnd,hLogo[9];
extern HBITMAP hPicture[9];
extern HWND parametr1,parametr2;
//zmiene sterujace
extern string p[9];
extern int polaczeniaLogiczne[4];
extern int polaczeniaFizyczne[4];
extern wstring cos[9];
extern int canShow;
int chec(int parametrs1, int parametrs2);
void addRouter();
void inicial();
void clearReference();

#endif //MAIN_CPP_OTHER_H
