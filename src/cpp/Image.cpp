//
// Created by Dawid on 27.06.2021.
//
#include <windows.h>
#include <string>
#include "../hpp/Image.h"
void loadImages()
{
    for(int i=0;i<9;i++)
    {
        hPicture[i]=(HBITMAP) LoadImageW(nullptr,L"..\\img\\nic.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
        cos[i]=L"..\\img\\nic";
    }
}

void resteRouter()
{
    for(int i=0;i<9;i++)
    {
        SendMessage(hLogo[i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPicture[i]) ;
    }
}

//umieszczanie obrazka
void CreateImage(HWND hwnd) {
    hLogo[0] = CreateWindowW(L"Static", nullptr, WS_VISIBLE | WS_CHILD | SS_BITMAP, 350, 60, 100, 100, hwnd, nullptr, nullptr,
                             nullptr);
    SendMessage(hLogo[0], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[0]);
    hLogo[1] = CreateWindowW(L"Static", nullptr, WS_VISIBLE | WS_CHILD | SS_BITMAP, 350, 260, 100, 100, hwnd, nullptr, nullptr,
                             nullptr);
    SendMessage(hLogo[1], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[1]);
    hLogo[2] = CreateWindowW(L"Static", nullptr, WS_VISIBLE | WS_CHILD | SS_BITMAP, 550, 60, 100, 100, hwnd, nullptr, nullptr,
                             nullptr);
    SendMessage(hLogo[2], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[2]);
    hLogo[3] = CreateWindowW(L"Static", nullptr, WS_VISIBLE | WS_CHILD | SS_BITMAP, 550, 260, 100, 100, hwnd, nullptr, nullptr,
                             nullptr);
    SendMessage(hLogo[3], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[3]);
    hLogo[4] = CreateWindowW(L"Static", nullptr, WS_VISIBLE | WS_CHILD | SS_BITMAP, 350, 160, 100, 100, hwnd, nullptr, nullptr,
                             nullptr);
    SendMessage(hLogo[4], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[4]);
    hLogo[5] = CreateWindowW(L"Static", nullptr, WS_VISIBLE | WS_CHILD | SS_BITMAP, 450, 60, 100, 100, hwnd, nullptr, nullptr,
                             nullptr);
    SendMessage(hLogo[5], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[5]);
    hLogo[6] = CreateWindowW(L"Static", nullptr, WS_VISIBLE | WS_CHILD | SS_BITMAP, 450, 160, 100, 100, hwnd, nullptr, nullptr,
                             nullptr);
    SendMessage(hLogo[6], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[6]);
    hLogo[7] = CreateWindowW(L"Static", nullptr, WS_VISIBLE | WS_CHILD | SS_BITMAP, 450, 260, 100, 100, hwnd, nullptr, nullptr,
                             nullptr);
    SendMessage(hLogo[7], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[7]);
    hLogo[8] = CreateWindowW(L"Static", nullptr, WS_VISIBLE | WS_CHILD | SS_BITMAP, 550, 160, 100, 100, hwnd, nullptr, nullptr,
                             nullptr);
    SendMessage(hLogo[8], STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hPicture[8]);
}