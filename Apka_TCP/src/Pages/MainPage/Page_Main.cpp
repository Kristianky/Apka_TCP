#include "Page_Main.h"
const wchar_t *Main_Page::Windows_Names[5] = {L"Data_Structures", L"TCP Page"};
const wchar_t *Main_Page::Windows_CLASS[5] = {L"BUTTON"};
Main_Page::Main_Page(HWND hwnd) : Pages(hwnd)
{

    Number_Of_Buttons = 2;
    Buttons_PositionsX = new int[2]{10, 10};
    Buttons_PositionsY = new int[2]{Main_Rect.top, Main_Rect.top + 100};
    Data_Struct = new Data_Struct_Page(Main_hwnd);
}
Main_Page::~Main_Page()
{
}

void Main_Page::Create_ButtonsW(HWND *Buttons)
{

    for (int i{}; i < Number_Of_Buttons; i++)
    {
        Buttons[i] = CreateWindowW(L"BUTTON", Windows_Names[i], WS_CHILD | WS_VISIBLE, Buttons_PositionsX[i], Buttons_PositionsY[i], 200, 100, Main_hwnd, (HMENU)(ID_BUTTONS + i), NULL, NULL);
    }
}

void Main_Page::Buttons_Function(int &page_num, HWND *Buttons, HWND *Edit_Boxes, bool *Buttons_state, WPARAM wparam, LPARAM lparam)
{
    enum Butoons_ID
    {
        Data_Structures = ID_BUTTONS,
        TcpPage
    };
    switch (LOWORD(wparam))
    {
    case (Data_Structures):
    {
        Destroy_WindowW(Buttons, Number_Of_Buttons);
        Data_Struct->Create_ButtonsW(Buttons);
        Data_Struct->Create_EditW(Edit_Boxes);
        page_num = 2;
        break;
    }
    case TcpPage:
    {
     
    }
        
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

void Main_Page::Create_EditW(HWND *Edit_Boxes)
{
}

void Main_Page::Edit_Box_Paint(HDC hdc)
{
}