#include "Page_Main.h"

Main_Page::Main_Page()
{
    Windows_Names = new wchar_t *[5]{{L"Data_Structures"}};
    Windows_CLASS = new wchar_t *[5]{{L"BUTTON"}};
    Number_Of_Windows = new int{1};
    Windows_PositionsX = new int[1]{10};
    Windows_PositionsY = new int[1]{10};
    Windows = new HWND[10];
}
Main_Page::~Main_Page(){
    
}

void Main_Page::Buttons_Function(LPARAM lparam,WPARAM wparam,int &page_num,HWND *Buttons,HWND Main_hwnd){
     enum Butoons_ID{Data_Structures = 10000};
     switch(LOWORD(wparam)){
        case (Data_Structures):
             page_num = 2;
             Destroy_WindowW(Buttons);
             break;
     }
}