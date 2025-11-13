#include "Pages.h"

Pages::Pages(HWND hwnd):
Main_hwnd{hwnd}
{
    Size_Of_Buffers = new int[5];
    GetClientRect(hwnd,&Main_Rect);
    Main_Rect.top = Main_Rect.top + 30;
}

Pages::~Pages()
{
    
    delete[] Buttons_PositionsX;
    delete[] Buttons_PositionsY;
    delete[] Edit_Postion_X;
    delete[] Edit_Postion_Y;
    delete[] Page_Name;
}


void Pages::Destroy_WindowW(HWND *Window,int Size){
     for (int i{}; i < Size; i++)
    {
         DestroyWindow(Window[i]);
    }
}