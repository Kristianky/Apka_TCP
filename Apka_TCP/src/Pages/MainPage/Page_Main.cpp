#include "Page_Main.h"
const wchar_t *Main_Page::Windows_Names[5] = {L"Data_Structures"};
const wchar_t *Main_Page::Windows_CLASS[5] = {L"BUTTON"};
Main_Page::Main_Page(HWND hwnd) : Pages(hwnd)
{

    Number_Of_Windows = new int{1};
    Windows_PositionsX = new int[1]{10};
    Windows_PositionsY = new int[1]{10};
    Windows = new HWND[10];
    Data_Struct = new Data_Struct_Page(Main_hwnd);
}
Main_Page::~Main_Page()
{
}

void Main_Page::Create_WindowW(HWND *Buttons, int BUTTON)
{

    for (int i{}; i < *Number_Of_Windows; i++)
    {
        Buttons[i] = CreateWindowW(Windows_CLASS[i], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 200, 100, Main_hwnd, (HMENU)(BUTTON + i), NULL, NULL);
    }
}

void Main_Page::Buttons_Function(int &page_num, HWND *Buttons, bool *Buttons_state, WPARAM wparam, LPARAM lparam)
{
    enum Butoons_ID
    {
        Data_Structures = 10000
    };
    switch (LOWORD(wparam))
    {
    case (Data_Structures):
        Destroy_WindowW(Buttons);
        Data_Struct->Create_WindowW(Buttons, Data_Structures);
        page_num = 2;
        break;
    }
}

void Main_Page::Cout_Button_1(HDC hdc)
{
}

void Main_Page::Cout_Create(HDC hdc)
{
}

void Main_Page::Key_Board_Func(WPARAM wparam, LPARAM lparam, int ID_Button, HWND *Window) {}

void Main_Page::Cout_Button_2(HDC hdc) {}