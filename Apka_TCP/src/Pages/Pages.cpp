#include "Pages.h"

Pages::Pages()
{
    Windows_CLASS = new wchar_t *[6] { {L"BUTTON"},
                                       {L"EDIT"},
                                       {L"STATIC"},
                                       {L"LISTBOX"},
                                       {L"COMBOBOX"},
                                       {L"SCROLLBAR"}};
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

void Pages::Create_Window(HWND hwnd)
{
    for (int i{}; i < Number_Of_Windows; i++)
    {
        CreateWindow(Windows_CLASS[i], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 200, 100, hwnd, (HMENU)(ID_BUTTONS + i), NULL, NULL);
    }
}