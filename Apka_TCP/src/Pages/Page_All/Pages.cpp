#include "Pages.h"

Pages::Pages(HWND hwnd):
Main_hwnd{hwnd}
{
    Windows_CLASS = new wchar_t *[6] { {L"BUTTON"},
                                       {L"EDIT"},
                                       {L"STATIC"},
                                       {L"LISTBOX"},
                                       {L"COMBOBOX"},
                                       {L"SCROLLBAR"}};
    Size_Of_Buffers = new int[5];
}

Pages::~Pages()
{
    delete[] Windows;
    delete[] Windows_Names;
    delete[] Windows_PositionsX;
    delete[] Windows_PositionsY;
    delete[] Page_Name;
    delete[] Windows_CLASS;
}


void Pages::Destroy_WindowW(HWND *Buttons){
     for (int i{}; i < *Number_Of_Windows; i++)
    {
         DestroyWindow(Buttons[i]);
    }
}