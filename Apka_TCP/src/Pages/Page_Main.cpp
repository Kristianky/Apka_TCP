#include "Page_Main.h"

Main_Page::Main_Page()
{
    Windows_Names = new wchar_t *[5]{{L"Data_Structures"}};
    Number_Of_Windows = new int{1};
    Windows_PositionsX = new int[1]{10};
    Windows_PositionsY = new int[1]{10};
    Windows = new HWND[10];
}

void Main_Page::Create_Window(HWND hwnd)
{
    for (int i{}; i < *Number_Of_Windows; i++)
    {
        CreateWindow(Windows_CLASS[i], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 200, 100, hwnd, (HMENU)(ID_BUTTONS + i + 1), NULL, NULL);
    }
}