#include "Pages.h"

Pages::Pages(HWND hwnd):
Main_hwnd{hwnd}
{
    Size_Of_Buffers = new int[5];
}

Pages::~Pages()
{
    delete[] Windows;
    delete[] Windows_PositionsX;
    delete[] Windows_PositionsY;
    delete[] Page_Name;
}


void Pages::Destroy_WindowW(HWND *Buttons){
     for (int i{}; i < *Number_Of_Windows; i++)
    {
         DestroyWindow(Buttons[i]);
    }
}