#include "Data_Struct.h"

Data_Struct_Page::Data_Struct_Page(HWND hwnd):Pages(hwnd)

{
     Windows_Names = new wchar_t *[6]{{L"Paint"}, {L"ShowStauts"},{L"0"},{L"0"},{L"0"},{L"0"}};
     Windows_CLASS = new wchar_t *[5]{{L"BUTTON"},{L"EDIT"}};
     Number_Of_Windows = new int{6};
     Windows_PositionsX = new int[6]{10, 210,10,10,10,10};
     Windows_PositionsY = new int[6]{10, 10,200,215,230,245};
     Windows = new HWND[10];
     Buffer = new wchar_t *[2];
}

Data_Struct_Page::~Data_Struct_Page()
{
}

void Data_Struct_Page::Create_WindowW(HWND *Buttons, HWND Main_Hwnd, int BUTTON)
{

     for (int i{}; i < *Number_Of_Windows; i++)
     {    
          if (i<2||i>6){
          Buttons[i] = CreateWindowW(Windows_CLASS[0], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 200, 100, Main_Hwnd, (HMENU)(BUTTON + i), NULL, NULL);
          }
          else {
          Buttons[i] = CreateWindowW(Windows_CLASS[1], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 190, 15, Main_Hwnd, (HMENU)(BUTTON + i), NULL, NULL);
          }
     }
}

void Data_Struct_Page::Cout_Button_1(HDC hdc)
{
     SetTextColor(hdc, RGB(255, 255, 255)); // biely text
     SetBkMode(hdc, TRANSPARENT);
     TextOutW(hdc, 350, 200, Buffer[3], 1);
}

void Data_Struct_Page::Cout_Create (HDC hdc){
     SetTextColor(hdc, RGB(255, 255, 255)); // biely text
     SetBkMode(hdc, TRANSPARENT);
     TextOutW(hdc,200,200,L"Lenght of X",11);
     TextOutW(hdc,200,215,L"Lenght of Y",11);
     TextOutW(hdc,200,245,L"Lenght of data",14);
     TextOutW(hdc,200,230,L"Data",4);
     
}

void Data_Struct_Page::Buttons_Function(int &page_num,HWND *Buttons,bool *Buttons_state,WPARAM wparam,LPARAM lparam)
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

void Data_Struct_Page::Key_Board_Func(WPARAM wparam,LPARAM lparam,int ID_Button,HWND *Window){
           switch(wparam){
            case VK_RETURN:
                 {
                    GetWindowTextW(Window[2],Buffer[0],ID_Button + 2);
                    GetWindowTextW(Window[2],Buffer[1],ID_Button + 3);
                    GetWindowTextW(Window[2],Buffer[2],ID_Button + 4);
                    GetWindowTextW(Window[2],Buffer[3],ID_Button + 5);
                    Sparse_Matrix.set_Lenght_X_Y(Buffer[0][0],Buffer[1][0]);
                    Sparse_Matrix.add_data(Buffer[3],Buffer[2][0]);
                 }
          }
}