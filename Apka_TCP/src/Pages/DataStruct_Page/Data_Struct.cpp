#include "Data_Struct.h"

Data_Struct_Page::Data_Struct_Page()
{
     Windows_Names = new wchar_t *[5]{{L"Paint"}, {L"ShowStauts"}};
     Windows_CLASS = new wchar_t *[5]{{L"BUTTON"}};
     Number_Of_Windows = new int{2};
     Windows_PositionsX = new int[2]{10, 210};
     Windows_PositionsY = new int[2]{10, 10};
     Windows = new HWND[10];
}

Data_Struct_Page::~Data_Struct_Page()
{
}

void Data_Struct_Page::Create_WindowW(HWND *Buttons, HWND Main_Hwnd, int BUTTON)
{

     for (int i{}; i < *Number_Of_Windows; i++)
     {
          Buttons[i] = CreateWindowW(Windows_CLASS[0], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 200, 100, Main_Hwnd, (HMENU)(BUTTON + i), NULL, NULL);
     }
}

void Data_Struct_Page::Cout(HDC hdc)
{
     SetTextColor(hdc, RGB(255, 255, 255)); // biely text
     SetBkMode(hdc, TRANSPARENT);
     TextOutW(hdc, 200, 200, L"Ahoj", 4);
}

void Data_Struct_Page::Buttons_Function(LPARAM lparam, WPARAM wparam, HWND hwnd, int &page_num, HWND *Buttons, HWND Main_hwnd, bool *Buttons_state)
{
     enum BUTTONS_ID
     {
          Paint = 10000,
          ShowWindow
     };
     switch (LOWORD(wparam))
     {
     case Paint:
          Buttons_state[0] = !Buttons_state[0];
          InvalidateRect(Main_hwnd, NULL, true);
          UpdateWindow(Main_hwnd);
          
          break;
     case ShowWindow:
          if (Buttons_state[0])
          {
               MessageBoxW(Main_hwnd, L"True", MB_OK, MB_OK);
          }
          else if (!Buttons_state[0])
          {
               MessageBoxW(Main_hwnd, L"False", MB_OK, MB_OK);
          }
     }
}