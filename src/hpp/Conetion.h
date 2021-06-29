//
// Created by Dawid on 27.06.2021.
//

#ifndef MAIN_CPP_CONETION_H
#define MAIN_CPP_CONETION_H
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
void coneting();
void changeConetion1(int pozition,int wieksza,int mniesza);
void changeConetion2(int pozition,int wieksza,int mniesza);
void changeConetion3(int pozition,int wieksza,int mniesza);
void changeConetion4(int pozition,int wieksza,int mniesza);
#endif //MAIN_CPP_CONETION_H
