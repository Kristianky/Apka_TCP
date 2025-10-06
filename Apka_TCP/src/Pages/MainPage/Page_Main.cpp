#include "Page_Main.h"

Main_Page::Main_Page(HWND hwnd):Pages(hwnd)
{
    Windows_Names = new wchar_t *[5]{{L"Data_Structures"}};
    Windows_CLASS = new wchar_t *[5]{{L"BUTTON"}};
    Number_Of_Windows = new int{1};
    Windows_PositionsX = new int[1]{10};
    Windows_PositionsY = new int[1]{10};
    Windows = new HWND[10];
    Data_Struct = new Data_Struct_Page(Main_hwnd);

}
Main_Page::~Main_Page(){
    
}

void Main_Page::Create_WindowW(HWND *Buttons,HWND Main_Hwnd,int BUTTON)
{
    
    for (int i{}; i < *Number_Of_Windows; i++)
    {
         Buttons[i] = CreateWindowW(Windows_CLASS[i], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 200, 100, Main_Hwnd, (HMENU)(BUTTON + i), NULL, NULL);
    }
   
    
}

void Main_Page::Buttons_Function(int &page_num,HWND *Buttons,bool *Buttons_state,WPARAM wparam,LPARAM lparam){
     enum Butoons_ID{Data_Structures = 10000};
     switch(LOWORD(wparam)){
        case (Data_Structures):
             Destroy_WindowW(Buttons);
             Data_Struct->Create_WindowW(Buttons,Main_hwnd,Data_Structures);
             page_num = 2;
             break;
}
}


void Main_Page::Cout_Button_1(HDC hdc){
     
}

void Main_Page::Cout_Create(HDC hdc){
     SetTextColor(hdc, RGB(255, 255, 255)); // biely text
     SetBkMode(hdc, TRANSPARENT);
     TextOutW(hdc,200,200,L"Lenght of X",11);
     TextOutW(hdc,200,215,L"Lenght of Y",11);
     TextOutW(hdc,200,230,L"Data",4);
}

void Main_Page::Key_Board_Func(WPARAM wparam,LPARAM lparam,int ID_Button,HWND *Window){}