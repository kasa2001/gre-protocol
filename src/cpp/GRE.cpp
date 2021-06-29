#include <windows.h>
#include <string>
#include "../hpp/GRE.h"
#include "../hpp/Other.h"
#include "../hpp/routerFunction.h"

void GRE() {
    int wieksza, mniesza;
    wchar_t text1[1];
    wchar_t text2[1];
    int GreEndpoint1, GreEndpoint2;

    GetWindowTextW(parametr1, text1, 2);
    GetWindowTextW(parametr2, text2, 2);
    wchar_t greEndpoint1[1];
    wchar_t greEndpoint2[1];
    GetWindowTextW(parametr4, greEndpoint1, 2);
    GetWindowTextW(parametr5, greEndpoint2, 2);
    if (!((greEndpoint1[0] != '/0' || greEndpoint2[0] != '/0') && (greEndpoint1[0] >= 48 && greEndpoint1[0] <= 49) &&
          (greEndpoint2[0] >= 48 && greEndpoint2[0] <= 49))) {
        MessageBox(nullptr,
                   "Nie podano wartosci w GRE endpoint interfejsu 0 i/lub 1 albo nie podano cyfry z zakresu od 0 do 1",
                   "Blad", MB_ICONEXCLAMATION);
        return;
    } else {
        GreEndpoint1 = *greEndpoint1 - 48;
        GreEndpoint2 = *greEndpoint2 - 48;
    }
    if (!((text1[0] != '/0' || text2[0] != '/0') && (text1[0] >= 48 && text1[0] <= 51) &&
          (text2[0] >= 48 && text2[0] <= 51))) {
        MessageBox(nullptr, "Nie podano wartosci w R1 i/lub R2 albo nie podano cyfry z zakresu od 0 do 3", "Blad",
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
        if (polaczeniaFizyczne[mniesza] < (GreEndpoint1 + 1) || polaczeniaFizyczne[wieksza] < (GreEndpoint2 + 1)) {
            MessageBox(nullptr, "Brak polaczenia sieciowego. Dodaj polaczenie sieciowe!", "Blad", MB_ICONEXCLAMATION);
            return;
        }

        if (mniesza == 0 && wieksza == 1 && (p[4] == "n" || p[4] == "c") && polaczeniaLogiczne[0] < 1 &&
            polaczeniaLogiczne[1] < 1) {
            changeGRE1(4, wieksza, mniesza);
        } else if (mniesza == 0 && wieksza == 2 && (p[5] == "n" || p[5] == "c") && polaczeniaLogiczne[0] < 1 &&
                   polaczeniaLogiczne[1] < 1) {
            changeGRE2(5, wieksza, mniesza);
        } else if (mniesza == 0 && wieksza == 3 && (p[6] == "n" || p[6] == "c1" || p[6] == "c2" || p[6] == "c3") &&
                   polaczeniaLogiczne[0] < 1 && polaczeniaLogiczne[3] < 1) {
            changeGRE3(6, wieksza, mniesza);
        } else if (mniesza == 1 && wieksza == 2 && (p[6] == "n" || p[6] == "c1" || p[6] == "c2" || p[6] == "c3") &&
                   polaczeniaLogiczne[1] < 1 && polaczeniaLogiczne[2] < 1) {
            changeGRE4(6, wieksza, mniesza);
        } else if (mniesza == 1 && wieksza == 3 && (p[7] == "n" || p[7] == "c") && polaczeniaLogiczne[1] < 1 &&
                   polaczeniaLogiczne[3] < 1) {
            changeGRE2(7, wieksza, mniesza);
        } else if (mniesza == 2 && wieksza == 3 && (p[8] == "n" || p[8] == "g") && polaczeniaLogiczne[2] < 1 &&
                   polaczeniaLogiczne[3] < 1) {
            changeGRE1(8, wieksza, mniesza);
        } else {
            MessageBox(nullptr,
                       "Takie polaczenie juz istnieje lub wykorzystano maksymalna liczbe polaczen gre ",
                       "Blad", MB_ICONEXCLAMATION);
            return;
        }

        renderGre(mniesza, wieksza, GreEndpoint1, GreEndpoint2);
    }
}

void changeGRE1(int pozition, int wieksza, int mniesza) {
    if (p[pozition] == "c") {
        cos[pozition] = L"..\\img\\summary1";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary1.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c g";
    } else {
        cos[pozition] = L"..\\img\\gre1";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\gre1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "g";
    }
    polaczeniaLogiczne[wieksza] += 1;
    polaczeniaLogiczne[mniesza] += 1;
}

void changeGRE2(int pozition, int wieksza, int mniesza) {
    if (p[pozition] == "c") {
        cos[pozition] = L"..\\img\\summary2";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary2.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c g";
    } else {
        cos[pozition] = L"..\\img\\gre2";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\gre2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "g";
    }
    polaczeniaLogiczne[wieksza] += 1;
    polaczeniaLogiczne[mniesza] += 1;
}

void changeGRE3(int pozition, int wieksza, int mniesza) {
    if (p[pozition] == "c1") {
        p[pozition] = "c1 g1";
        cos[pozition] = L"..\\img\\summary4";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary4.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
    } else if (p[pozition] == "n") {
        cos[pozition] = L"..\\img\\gre4";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\gre4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "g1";
    } else if (p[pozition] == "c3") {
        cos[pozition] = L"..\\img\\summary6";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary6.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c3 g1";
    } else if (p[pozition] == "c2") {
        cos[pozition] = L"..\\img\\gre6";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\gre6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c2 g1";
    } else {
        MessageBox(nullptr, "Mozna wlaczyc tylko jedno GRE na srodku", "Blad", MB_ICONEXCLAMATION);
    }
    polaczeniaLogiczne[wieksza] += 1;
    polaczeniaLogiczne[mniesza] += 1;
}

void changeGRE4(int pozition, int wieksza, int mniesza) {
    if (p[pozition] == "c2") {
        p[pozition] = "c2 g2";
        cos[pozition] = L"..\\img\\summary3";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summarysummary3.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
    } else if (p[pozition] == "n") {
        cos[pozition] = L"..\\img\\gre3";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\gre3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "g2";
    } else if (p[pozition] == "c3") {
        cos[pozition] = L"..\\img\\summary5";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\summary5.bmp", IMAGE_BITMAP, 0, 0,
                                                  LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c3 g2";
    } else if (p[pozition] == "c1") {
        cos[pozition] = L"..\\img\\gre5";
        hPicture[pozition] = (HBITMAP) LoadImageW(nullptr, L"..\\img\\gre5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        SendMessage(hLogo[pozition], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[pozition]);
        p[pozition] = "c1 g2";
    } else {
        MessageBox(nullptr, "Mozna wlaczyc tylko jedno GRE na srodku", "Blad", MB_ICONEXCLAMATION);
    }
    polaczeniaLogiczne[wieksza] += 1;
    polaczeniaLogiczne[mniesza] += 1;
}