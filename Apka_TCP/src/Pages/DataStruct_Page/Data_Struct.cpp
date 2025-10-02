#include "Data_Struct.h"

Data_Struct_Page::Data_Struct_Page(HWND hwnd,HDC hdc):Pages(hwnd,hdc)

{
     Windows_Names = new wchar_t *[5]{{L"Paint"}, {L"ShowStauts"},{L"0"},{L"0"},{L"0"}};
     Windows_CLASS = new wchar_t *[5]{{L"BUTTON"},{L"EDIT"}};
     Number_Of_Windows = new int{5};
     Windows_PositionsX = new int[5]{10, 210,10,10,10};
     Windows_PositionsY = new int[5]{10, 10,200,215,230};
     Windows = new HWND[10];

}

Data_Struct_Page::~Data_Struct_Page()
{
}

void Data_Struct_Page::Create_WindowW(HWND *Buttons, HWND Main_Hwnd, int BUTTON)
{

     for (int i{}; i < *Number_Of_Windows; i++)
     {    
          if (i<2||i>5){
          Buttons[i] = CreateWindowW(Windows_CLASS[0], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 200, 100, Main_Hwnd, (HMENU)(BUTTON + i), NULL, NULL);
          }
          else {
          Buttons[i] = CreateWindowW(Windows_CLASS[1], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 190, 15, Main_Hwnd, (HMENU)(BUTTON + i), NULL, NULL);
          }
     }
}

void Data_Struct_Page::Cout_Button_1()
{
     SetTextColor(Main_hdc, RGB(255, 255, 255)); // biely text
     SetBkMode(Main_hdc, TRANSPARENT);
     TextOutW(Main_hdc, 350, 200, L"Ahoj", 4);
}

void Data_Struct_Page::Cout_Create(){
     SetTextColor(Main_hdc, RGB(255, 255, 255)); // biely text
     SetBkMode(Main_hdc, TRANSPARENT);
     TextOutW(Main_hdc,200,200,L"Lenght of X",11);
     TextOutW(Main_hdc,200,215,L"Lenght of Y",11);
     TextOutW(Main_hdc,200,230,L"Data",4);
}

void Data_Struct_Page::Buttons_Function(LPARAM lparam, WPARAM wparam, int &page_num, HWND *Buttons, bool *Buttons_state)
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