#include <windows.h>
#include <string>
#include "../hpp/Conetion.h"
#include "../hpp/Other.h"
#include "../hpp/routerFunction.h"

void coneting() {
    int wieksza, mniesza;
    wchar_t text1[1];
    wchar_t text2[1];
    GetWindowTextW(parametr1, text1, 2);
    GetWindowTextW(parametr2, text2, 2);
    if (!((text1[0] != '/0' || text2[0] != '/0') && (text1[0] >= 48 && text1[0] <= 51) &&
          (text2[0] >= 48 && text2[0] <= 51))) {
        MessageBox(nullptr, "Nie podano wartosci w R1 lub R2 albo nie podano cyfry z zakresu od 0 do 3", "Blad",
                   MB_ICONEXCLAMATION);
        return;
    } else if (*text1 - 48 < *text2 - 48) {
        wieksza = *text2 - 48;
        mniesza = *text1 - 48;
    } else {
        wieksza = *text1 - 48;
        mniesza = *text2 - 48;
    }
    if (chec(wieksza, mniesza) == 0) {
        if (mniesza == 0 && wieksza == 1 && (p[4] == "n" || p[4] == "g") && polaczeniaFizyczne[0] < 2 &&
            polaczeniaFizyczne[1] < 2) {
            changeConetion1(4, wieksza, mniesza);
        } else if (mniesza == 0 && wieksza == 2 && (p[5] == "n" || p[5] == "g") && polaczeniaFizyczne[0] < 2 &&
                   polaczeniaFizyczne[1] < 2) {
            changeConetion2(5, wieksza, mniesza);
        } else if (mniesza == 0 && wieksza == 3 &&
                   (p[6] == "n" || p[6] == "c2" || p[6] == "g1" || p[6] == "g2" || p[6] == "c2 g2" ||
                    p[6] == "c2 g1") && polaczeniaFizyczne[0] < 2 && polaczeniaFizyczne[3] < 2) {
            changeConetion3(6, wieksza, mniesza);
        } else if (mniesza == 1 && wieksza == 2 &&
                   (p[6] == "n" || p[6] == "c1" || p[6] == "g2" || p[6] == "g1" || p[6] == "c1 g2" ||
                    p[6] == "c1 g1") && polaczeniaFizyczne[1] < 2 && polaczeniaFizyczne[2] < 2) {

            changeConetion4(6, wieksza, mniesza);
        } else if (mniesza == 1 && wieksza == 3 && (p[7] == "n" || p[7] == "g") && polaczeniaFizyczne[1] < 2 &&
                   polaczeniaFizyczne[3] < 2) {
            changeConetion2(7, wieksza, mniesza);
        } else if (mniesza == 2 && wieksza == 3 && (p[8] == "n" || p[8] == "g") && polaczeniaFizyczne[2] < 2 &&
                   polaczeniaFizyczne[3] < 2) {
            changeConetion1(8, wieksza, mniesza);
        } else {
            MessageBox(nullptr, "Take polaczenie juz istnieje lub wykorzystano maksymalna liczbe polaczen dla routera ",
                       "Blad", MB_ICONEXCLAMATION);
            return;
        }

        renderRouter(mniesza, wieksza);
    }
}

//poziom jest pozycjią p , pole jest pozycjia obrazka
void changeConetion1(int pozition, int wieksza, int mniesza) {
    if (p[pozition] == "g") {
        cos[pozition] = L"..\\img\\summary1";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary1.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c g";
    } else {
        cos[pozition] = L"..\\img\\connect1";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\connect1.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c";
    }
    polaczeniaFizyczne[mniesza] += 1;
    polaczeniaFizyczne[wieksza] += 1;
}

void changeConetion2(int pozition, int wieksza, int mniesza) {
    if (p[pozition] == "g") {
        cos[pozition] = L"..\\img\\summary2";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary2.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c g";
    } else {
        cos[pozition] = L"..\\img\\connect2";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\connect2.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c";
    }
    polaczeniaFizyczne[mniesza] += 1;
    polaczeniaFizyczne[wieksza] += 1;
}

void changeConetion3(int pozition, int wieksza, int mniesza) {
    if (p[pozition] == "g1") {
        cos[pozition] = L"..\\img\\summary4";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary4.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c1 g1";
    } else if (p[pozition] == "c2") {
        cos[pozition] = L"..\\img\\connect5";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\connect5.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c3";
    } else if (p[pozition] == "n") {
        cos[pozition] = L"..\\img\\connect4";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\connect4.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c1";
    } else if (p[pozition] == "c2 g1") {
        cos[pozition] = L"..\\img\\summary6";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary6.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c3 g1";
    } else if (p[pozition] == "g2") {
        cos[pozition] = L"..\\img\\gre5";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\gre5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c1 g2";
    } else if (p[pozition] == "c2 g2") {
        cos[pozition] = L"..\\img\\summary5";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary5.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c3 g2";
    }
    polaczeniaFizyczne[mniesza] += 1;
    polaczeniaFizyczne[wieksza] += 1;
}

void changeConetion4(int pozition, int wieksza, int mniesza) {
    if (p[pozition] == "g2") {
        cos[pozition] = L"..\\img\\summary3";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary3.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c2 g2";
    } else if (p[pozition] == "c1") {
        cos[pozition] = L"..\\img\\connect5";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\connect5.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] == "c3";
    } else if (p[pozition] == "n") {
        cos[pozition] = L"..\\img\\connect3";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\connect3.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c2";
    } else if (p[pozition] == "g1") {
        cos[pozition] = L"..\\img\\gre6";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\gre6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c2 g1";
    } else if (p[pozition] == "c1 g2") {
        cos[pozition] = L"..\\img\\summary5";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary5.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c3 g2";
    } else if (p[pozition] == "c1 g1") {
        cos[pozition] = L"..\\img\\summary6";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary6.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c3 g1";
    }
    polaczeniaFizyczne[mniesza] += 1;
    polaczeniaFizyczne[wieksza] += 1;
}