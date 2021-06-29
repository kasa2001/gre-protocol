#include <windows.h>
#include <string>
#include "../hpp/Other.h"
#include "../hpp/GRE.h"
#include "../hpp/routerFunction.h"

int chec(int parametrs1, int parametrs2)
{
    if(p[parametrs1]=="r" &&p[parametrs2]=="r")
    {
        return 0;
    }
    else
    {
        MessageBox( nullptr, "Nie wlaczono  routera lub podano blednie pozycjie", "Blad", MB_ICONEXCLAMATION );
        return -1;
    }
}
void addRouter()
{
    if(p[3]=="r")
    {
        MessageBox( nullptr, "Nie mozna dodac wiecej niz 4 routery", "Blad", MB_ICONEXCLAMATION );
        return;
    }
    for(int i=0;i<4;i++)
    {
        if(p[i]=="n")
        {
            router[i] = new Router(i);
            hPicture[i]=(HBITMAP) LoadImageW(nullptr,L"..\\img\\router.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
            SendMessage(hLogo[i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPicture[i]) ;
            p[i]="r";
            return;
        }
    }
}

void inicial()
{
    for (auto & i : p)
    {
        i="n";
    }
    for (int i=0;i<4;i++)
    {
        polaczeniaFizyczne[i]=0;
        polaczeniaLogiczne[i]=0;
    }
}

void clearReference() {
    for (auto route: router) {
        delete route;
    }
}